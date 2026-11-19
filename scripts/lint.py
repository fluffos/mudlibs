#!/usr/bin/env python3
"""Repository-wide linter encoding mudlib restoration and hygiene rules.

Turns the corpus-wide defects cataloged in `docs/kb/` and `AGENTS.md` into
fast, reproducible lint checks alongside repo/metadata hygiene checks.

Modes:
  scripts/lint.py                 # --fast: repo hygiene + metadata + zero-hit targeted checks
  scripts/lint.py --changed [REF] # check files changed vs REF (or working tree) with ALL rules
  scripts/lint.py --lib SLUG ...  # check specific lib(s) thoroughly with ALL rules
  scripts/lint.py --files PATH... # check explicit files with ALL matching rules
  scripts/lint.py --all           # full corpus scan across tracked files (parallelized)
  scripts/lint.py --list-rules    # list all lint rules with scope, KB ref, and summary

Exit code: 0 if no errors, 1 if any error is found (`--strict` promotes warnings to errors).
"""

from __future__ import annotations

import argparse
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass
import glob
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRIPTS_DIR = os.path.dirname(os.path.abspath(__file__))
if SCRIPTS_DIR not in sys.path:
    sys.path.insert(0, SCRIPTS_DIR)

import check_ntfs_paths as ntfs_chk  # noqa: E402
import lpc_fix_array_type as arrayfix  # noqa: E402
import lpc_fix_byte_char as bytefix  # noqa: E402
import lpc_fix_callout_info as calloutfix  # noqa: E402
import lpc_fix_cat_unchecked as catfix  # noqa: E402
import lpc_fix_chat_empty as chatfix  # noqa: E402
import lpc_fix_cmp_chain as cmpfix  # noqa: E402
import lpc_fix_default_switch as swfix  # noqa: E402
import lpc_fix_display_pad as dispfix  # noqa: E402
import lpc_fix_dotc_path as dotcfix  # noqa: E402
import lpc_fix_dotdot_dir as dotdotfix  # noqa: E402
import lpc_fix_eaten_quote as quotefix  # noqa: E402
import lpc_fix_enable_player_guard as epfix  # noqa: E402
import lpc_fix_family_guard as famgfix  # noqa: E402
import lpc_fix_family_index as famifix  # noqa: E402
import lpc_fix_functional_locals as funclocfix  # noqa: E402
import lpc_fix_getdir_strip as gdstripfix  # noqa: E402
import lpc_fix_keep_dir as keepdirfix  # noqa: E402
import lpc_fix_literal_or as litorfix  # noqa: E402
import lpc_fix_macro_strparam as macrostrfix  # noqa: E402
import lpc_fix_member_array_char as memcharfix  # noqa: E402
import lpc_fix_money_path as moneyfix  # noqa: E402
import lpc_fix_mud_port as mudportfix  # noqa: E402
import lpc_fix_negative_ranges as negrangefix  # noqa: E402
import lpc_fix_not_literal_cmp as notlitfix  # noqa: E402
import lpc_fix_perform_weapon as perfwpnfix  # noqa: E402
import lpc_fix_pname_slice as pnamefix  # noqa: E402
import lpc_fix_predefined_macro as predmacrofix  # noqa: E402
import lpc_fix_rank_null as rankfix  # noqa: E402
import lpc_fix_start_more as morefix  # noqa: E402
import lpc_fix_strlen_gate as strlenfix  # noqa: E402
import lpc_fix_topten_guard as topguardfix  # noqa: E402
import lpc_fix_unit_cut as unitcutfix  # noqa: E402
import lpc_fix_vision_env as visenvfix  # noqa: E402
import lpc_fix_visitor_count as viscntfix  # noqa: E402
import lpc_scan_cond_assign as sc  # noqa: E402
import lpc_scan_for_scope as forscope  # noqa: E402
import lpc_scan_if_else_empty as ifelse  # noqa: E402
from lpc_fix_void_return import code_mask  # noqa: E402


@dataclass(frozen=True)
class RuleSpec:
    name: str
    scope: str          # repo | targeted | file
    kb: str
    repo_severity: str  # error | warn (in --changed/--files/--strict every rule is error)
    summary: str


RULES: list[RuleSpec] = [
    # Repo hygiene & metadata
    RuleSpec("ntfs-paths", "repo", "#30 / AGENTS §13.3", "error", "NTFS-incompatible paths, illegal bytes, reserved names, case collisions"),
    RuleSpec("docs-utf8", "repo", "KB 03 §4", "error", "Strict UTF-8 in AGENTS.md, TOOLKIT.md, docs/, NOTES.md, README.md, scripts/*.py"),
    RuleSpec("keep-dirs-manifest", "repo", "KB 06 §7.212, §7.384", "error", "Validates scripts/wasm_keep_dirs.txt format, slugs, relative paths, duplicates"),
    RuleSpec("meta-ports", "repo", "AGENTS §10.5", "error", "Unique valid ports across libs/*/meta.json for playable non-duplicate libs"),
    RuleSpec("meta-cfg-port", "repo", "AGENTS §10.5", "warn", "config.fluffos port number matches meta.json port"),
    # Targeted zero-hit / baseline runtime & compile checks
    RuleSpec("sefun-cat-unguarded", "targeted", "KB 06 §7.297, §7.388", "error", "Active sefun::cat() passing unguarded read_file() to write()/receive()/message()"),
    RuleSpec("sefun-read-file-arity", "targeted", "KB 06 §7.389", "error", "sefun::read_file() lacking varargs or <3 args (drops start_line/number_of_lines)"),
    RuleSpec("start-more-unguarded", "targeted", "KB 06 §7.300, §7.390", "error", "start_more()/more_string()/more() passing unguarded string arg to explode()"),
    RuleSpec("toptend-guard", "targeted", "KB 06 §7.385", "error", "JackyBoy toptend.lpc missing <=0 rank check, post-del guard, or sscanf(astr) array bug"),
    RuleSpec("visitor-count-unguarded", "targeted", "KB 06 §7.301", "error", "howmany_visitor() passing unguarded read_file() result into sscanf()"),
    RuleSpec("wabaod-gbk-index", "targeted", "KB 06 §7.307", "error", "wabaod.lpc mutating desc[b..b+1] forward with UTF-8 shortening"),
    RuleSpec("keep-dir-blockade", "targeted", "KB 06 §7.340", "error", "blockade/recover missing /data/keep mkdir or file_size guard"),
    RuleSpec("mud-port-config", "targeted", "KB 06 §7.302", "error", "get_config(__MUD_PORT__) reading string under old CFG_INT runtime_config.h"),
    RuleSpec("loopback-fail-open", "targeted", "AGENTS §1.3", "error", "is_local_site() returning 1 when !stringp(site) (fail-open)"),
    RuleSpec("iips-empty-mailbox", "targeted", "KB 06 §7.379", "error", "post.lpc save_letter indexing __BoxInfo[-1] on empty folder"),
    RuleSpec("lima-menu-protected-remove", "targeted", "KB 06 §7.383", "error", "Lima std/menu.lpc declaring protected void remove()"),
    RuleSpec("dead-souls-stat-3tuple", "targeted", "KB 06 §7.382", "error", "Dead Souls books.lpc checking sizeof(statinfo) != 3 on FluffOS 4-tuple stat()"),
    RuleSpec("missing-embed-h", "targeted", "KB 04 §6.31", "error", "#include /inherit/item/embed.h in playable lib that never shipped it"),
    RuleSpec("enable-player-guard", "targeted", "KB 05 §7.19", "warn", "feature/command.lpc enable_player() lacking reentrancy guard"),
    RuleSpec("rank-null-guard", "targeted", "KB 06 §7.273", "warn", "adm/daemons/rankd.lpc missing !objectp(ob) fallback"),
    RuleSpec("ping-strip-callout-nosave", "targeted", "KB 04 §6.10", "error", "pingd.lpc/pingtcp.lpc declaring nosave int strip_callout() instead of protected"),
    RuleSpec("warcraft-actions-noop", "targeted", "KB 06 §7.392", "error", "warcraft.h discarded ternary actions == \"follow\" ? ... : ... leaving status untranslated"),
    RuleSpec("mr-dizi-duplicate-inherit", "targeted", "KB 04 §6.31", "error", "d/mr/npc/dizi.lpc declaring inherit NPC while #included by job-dizi.lpc"),
    RuleSpec("say-delete-busy", "targeted", "KB 06 §7.394", "error", "cmds/std/say.lpc call_out(\"delete_busy\") missing arg, deleted/commented body, uninit ob, or this_player()"),
    RuleSpec("cmd-callout-this-player", "targeted", "KB 06 §7.395", "error", "Shared /cmds/ call_out callback invoking this_player() (0 in timer context)"),
    RuleSpec("skill-sanshen-del-perform", "targeted", "KB 06 §7.396", "error", "kungfu/skill/fanliangyi-dao/sanshen.lpc scheduling del_perform without defining void del_perform(object me)"),
    # Per-file corpus checks (all error in --changed/--files/--strict; configurable in --all)
    RuleSpec("no-pragma-no-warnings", "file", "AGENTS (2026-10-03)", "error", "Forbids #pragma no_warnings anywhere in libs/*/work/"),
    RuleSpec("efun-dbase-call", "file", "KB 06 §7.392", "error", "Non-existent efun::set/addn/query/delete calls failing compilation"),
    RuleSpec("quoted-efun-call", "file", "KB 06 §7.393", "error", "Object efun/sefun called with quoted \"this_object()\"/\"this_player()\"/... string instead of object"),
    RuleSpec("query-method-typo", "file", "KB 06 §7.397", "error", "Misspelled ->query()/->query_temp()/->query_skill()/->query_respect() method call"),
    RuleSpec("call-method-typo", "file", "KB 06 §7.398", "error", "Misspelled ->receive_damage()/->receive_wound()/->receive_curing()/->set_temp()/->delete_temp()/->start_busy() call"),
    RuleSpec("whole-file-duplicate", "file", "KB 04 §6.32", "warn", "Whole .lpc/.h file pasted twice (identical halves modulo whitespace)"),
    RuleSpec("throwing-combined-diamond", "file", "KB 04 §6.31", "error", "inherit THROWING + COMBINED_ITEM when THROWING already inherits COMBINED_ITEM"),
    RuleSpec("default-switch-only", "file", "KB 04 §6.30", "warn", "switch (...) { default: ... } with zero case labels"),
    RuleSpec("not-literal-cmp", "file", "KB 06 §7.280", "error", "x == !\"literal\" boolean inversion of non-empty string"),
    RuleSpec("double-slash-path", "file", "KB 06 §7.276", "error", "\"//area/...\" double-leading-slash object path failing valid_read()"),
    RuleSpec("literal-or", "file", "KB 06 §7.281", "warn", "x == \"a\" || \"b\" / != \"a\" && \"b\" bare literal chain"),
    RuleSpec("cmp-chain", "file", "KB 06 §7.282", "warn", "x != \"a\" || x != \"b\" refusal or x == \"a\" && x == \"b\" De Morgan slip"),
    RuleSpec("tp-carry-create", "file", "KB 06 §7.268", "warn", "this_player()->carry_object(...) inside create()"),
    RuleSpec("vision-env", "file", "KB 06 §7.242", "warn", "message_vision(msg, environment(me), me) passing room as actor"),
    RuleSpec("family-index", "file", "KB 05 §7.30", "warn", "->query(\"family\")[...] unguarded inline indexing"),
    RuleSpec("family-guard", "file", "KB 05 §7.30", "warn", "mapping fam = ob->query(\"family\"); indexed without mapp()"),
    RuleSpec("perform-weapon", "file", "KB 06 §7.246", "warn", "weapon = me->query_temp(\"weapon\") used without objectp() check"),
    RuleSpec("unit-cut-utf8", "file", "KB 07 §8.1", "warn", "my[x[i]] == 1 ? x[i][2..] : x[i] GBK unit cut"),
    RuleSpec("pname-slice-utf8", "file", "KB 06 §7.373", "warn", "GBK (random(...) & 0xFFFE) + [0..1] one-char pick"),
    RuleSpec("display-pad-utf8", "file", "KB 06 §7.365", "warn", "GBK * 2 / strlen(emotion)/2 display padding"),
    RuleSpec("byte-char-utf8", "file", "KB 06 §7.363", "warn", "GBK i%2 parity loops, clubpoem mixup, nitan channeld byte switch"),
    RuleSpec("strlen-gate-utf8", "file", "KB 06 §7.362", "warn", "strlen() byte bounds twice the Chinese message's character count"),
    RuleSpec("chat-empty-index", "file", "KB 06 §7.334", "warn", "chat_msg[random(sizeof(chat_msg))] without sizeof guard"),
    RuleSpec("functional-locals", "file", "KB 06 §7.284", "warn", "(: this_object(), ({ \"fn\", local }) :) illegal local in functional"),
    RuleSpec("callout-info-index", "file", "KB 06 §7.287", "warn", "call_out_info()[i][3] or sizeof==4 assuming 4-element MudOS tuples"),
    RuleSpec("getdir-strip-dotc", "file", "KB 06 §7.296", "warn", "get_dir(\"*.lpc\") suffix strip [0..<3] instead of [0..<5]"),
    RuleSpec("array-reserved-type", "file", "KB 04 §6.3", "warn", "Bare `array` keyword used as variable/param/return type"),
    RuleSpec("negative-ranges", "file", "KB 06 §7.209", "warn", "Negative constant range slice [a..-N] / [-N..] without <"),
    RuleSpec("dotc-path", "file", "KB 06 §7.356", "warn", "\"/path/x.c\" literal when only x.lpc exists"),
    RuleSpec("dotdot-dir", "file", "KB 06 §7.351", "warn", "__DIR__ \"../\" in new/load_object/find_object/clone_object/unew/move"),
    RuleSpec("macro-strparam", "file", "KB 06 §7.352", "warn", "#define M(x) with K&R parameter name inside string literal"),
    RuleSpec("member-array-char", "file", "KB 06 §7.283", "warn", "member_array('c', str) byte search on string instead of strsrch"),
    RuleSpec("eaten-quote", "file", "KB 03 §4.6", "warn", "Unterminated string literal before line-ending ; or );"),
    RuleSpec("money-path-clone", "file", "KB 06 §7.375", "warn", "\"/clone/money/...\" in libs whose money files live in /obj/money/"),
    RuleSpec("predefined-macro", "file", "KB 04 §6.11", "warn", "Bare SAVE_EXTENSION without reaching a #define"),
    RuleSpec("if-else-empty", "file", "KB 04 §6.27", "warn", "if (cond) directly followed by else (missing ;)"),
    RuleSpec("for-scope-leak", "file", "KB 04 §6.12", "warn", "for (int i = ...) loop variable read after loop"),
    RuleSpec("cond-assign", "file", "KB 06 §7.290", "warn", "if (x = 1) / while (x = \"\") constant assignment in condition"),
    RuleSpec("prev-obj-path-cmp", "file", "KB 06 §7.378", "warn", "previous_object() ==|!= \"/...\" object compared directly to path string"),
    RuleSpec("path-macro-plus-arrow", "file", "KB 06 §7.377", "warn", "#define M A + \"/b\" followed by M->fn() without parentheses"),
    RuleSpec("local-shadows-sefun", "file", "KB 06 §7.380", "warn", "Local variable shadowing sefun called again in same function"),
    RuleSpec("unguarded-read-file-nested", "file", "KB 06 §7.386", "warn", "explode/replace_string/sscanf(read_file(\"/missing\")) without || \"\""),
    RuleSpec("unguarded-get-dir", "file", "KB 06 §7.391", "warn", "foreach/map/filter/sort_array over get_dir() on missing/dynamic dir without || ({})"),
    RuleSpec("dead-u-exits", "file", "KB 06 §7.367-7.372", "warn", "Hardcoded migrated/dead wizard exits (/u/calvin, /u/beyond, /u/tianlin, /u/b/bigcat, etc.) outside wizard homes"),
]

RULE_MAP: dict[str, RuleSpec] = {r.name: r for r in RULES}

DOUBLE_SLASH_PAT = re.compile(rb'"//([A-Za-z_][A-Za-z0-9_\-]*/[A-Za-z0-9_./\-]*)"')
PRAGMA_NOWARN_RE = re.compile(rb"(?m)^[ \t]*#pragma\s+.*\bno_warnings\b")
READ_FILE_SEFUN_RE = re.compile(rb"(?m)^[ \t]*(?:(varargs)\s+)?string\s+read_file\s*\(([^)]*)\)\s*\{")
EFUN_DBASE_RE = re.compile(rb"\befun::(?:set|addn|query|delete)[ \t]*\(")
QUOTED_EFUN_RE = re.compile(
    rb'\b(?:base_name|file_name|environment|geteuid|getuid|living|userp|wizardp|clonep|destruct|tell_object|present|move|move_object)\s*\(\s*"(?:this_object|this_player|previous_object|environment)\(\)"\s*\)'
)
PREV_OBJ_CMP_RE = re.compile(rb'previous_object\s*\(\s*\)\s*(?:==|!=)\s*"/|"[^"\n]*"\s*(?:==|!=)\s*previous_object\s*\(\s*\)')
SHADOW_SEFUN_RE = re.compile(rb"\b(?:string|mixed|object)\s+(home_path)\s*=\s*\1\s*\(")
UNGUARDED_RF_NEST = re.compile(rb'\b(?:explode|replace_string|sscanf)\s*\(\s*(?:efun::)?read_file\s*\(\s*"(/[^"\n]+)"\s*\)')
UNGUARDED_GD_HOF = re.compile(rb"\b(?:map_array|map|filter_array|filter|sort_array)\s*\(\s*(?:efun::)?get_dir\s*\(")
UNGUARDED_GD_FOREACH = re.compile(rb"\bforeach\s*\([^;\n()]*?\bin\s+(?:efun::)?get_dir\s*\(")
GD_GUARD_CTX = re.compile(rb"\b(?:file_size|pointerp|arrayp|directory_exists|is_directory|catch)\b|\|\|\s*\(\s*\{\s*\}\s*\)")
DEAD_U_EXITS_RE = re.compile(
    r'"(/u/(?:calvin/兰陵|fly/doublesword/houdian|beyond/|tianlin/阿修罗界|g/gold/dock|xinyue/sunrise_room|mei/(?:workroom|tianying/elou)|b/bigcat/|f/faceoff/|r/rence/|onskyer/niulang/|skinys/yihua/))'
)


def _load_metas() -> dict[str, dict]:
    out = {}
    for mp in sorted(glob.glob(f"{REPO}/libs/*/meta.json")):
        try:
            m = json.load(open(mp, encoding="utf-8"))
            out[m["slug"]] = m
        except Exception:
            pass
    return out


def _git_ls_files() -> tuple[set[str], list[str]]:
    raw = subprocess.run(
        ["git", "-c", "core.quotepath=false", "ls-files", "-s", "-z", "--", "libs"],
        cwd=REPO, capture_output=True,
    ).stdout.split(b"\0")
    gitlinks: set[str] = set()
    files: list[str] = []
    for ent in raw:
        if not ent:
            continue
        meta, _, path = ent.partition(b"\t")
        try:
            p = path.decode("utf-8")
        except UnicodeDecodeError:
            continue
        parts = p.split("/")
        if meta.split()[0] == b"160000" and len(parts) >= 2 and parts[0] == "libs":
            gitlinks.add(parts[1])
            continue
        files.append(p)
    return gitlinks, files


def _is_active_vendored(slug: str, metas: dict[str, dict], gitlinks: set[str]) -> bool:
    if slug in gitlinks or slug in sc.GENERATED or slug in sc.LDMUD:
        return False
    m = metas.get(slug, {})
    return (
        m.get("wasm_status") == "playable"
        and m.get("hosting", "vendored") == "vendored"
        and not m.get("duplicate_of")
    )


def _active_simul_paths(slug: str) -> list[str]:
    cfg = f"{REPO}/libs/{slug}/config.fluffos"
    if not os.path.isfile(cfg):
        return []
    txt = open(cfg, encoding="utf-8", errors="replace").read()
    m = re.search(r"(?m)^simulated efun file\s*:\s*(\S+)", txt)
    if not m:
        return []
    sf = m.group(1).lstrip("/")
    cand = f"{REPO}/libs/{slug}/work/{sf}"
    if not os.path.isfile(cand) and not sf.endswith((".lpc", ".c")):
        for ext in (".lpc", ".c"):
            if os.path.isfile(f"{REPO}/libs/{slug}/work/{sf}{ext}"):
                cand = f"{REPO}/libs/{slug}/work/{sf}{ext}"
                break
    res: list[str] = []
    if os.path.isfile(cand):
        res.append(os.path.relpath(cand, REPO))
        try:
            raw = open(cand, "rb").read()
        except OSError:
            return res
        for im in re.finditer(rb'(?m)^[ \t]*#[ \t]*include[ \t]*[<"]([^>"]+)[>"]', raw):
            inc = im.group(1).decode("utf-8", "replace").lstrip("/")
            for ic in (f"{REPO}/libs/{slug}/work/{inc}", os.path.join(os.path.dirname(cand), inc)):
                if os.path.isfile(ic):
                    rp = os.path.relpath(ic, REPO)
                    if rp not in res:
                        res.append(rp)
                    break
    return res


def _sefun_wraps_read_file(slug: str) -> bool:
    for rp in _active_simul_paths(slug):
        try:
            b = open(f"{REPO}/{rp}", "rb").read()
        except OSError:
            continue
        if b"read_file" in b and re.search(rb'\bstring\s+read_file\b', b):
            if re.search(rb'return\s+""', b):
                return True
    return False


def _throwing_inherits_combined(slug: str) -> bool:
    inc = ""
    for gp in glob.glob(f"{REPO}/libs/{slug}/work/**/globals.h", recursive=True):
        t = open(gp, encoding="utf-8", errors="replace").read()
        mm = re.search(r'#define\s+THROWING\s+"([^"]+)"', t)
        if mm:
            inc = mm.group(1).lstrip("/")
            break
    if not inc:
        return False
    for ext in (".lpc", ".c", ""):
        cand = f"{REPO}/libs/{slug}/work/{inc}{ext}"
        if os.path.isfile(cand):
            tt = open(cand, encoding="utf-8", errors="replace").read()
            return bool(re.search(r"(?m)^\s*inherit\s+COMBINED_ITEM\b", tt))
    return False


class LintCollector:
    def __init__(self, selected_rules: set[str] | None, strict: bool, changed_paths: set[str] | None):
        self.selected = selected_rules
        self.strict = strict
        self.changed_paths = changed_paths
        self.findings: list[tuple[str, str, str, str]] = []  # (sev, rule, path, msg)

    def wants(self, rule: str) -> bool:
        return self.selected is None or rule in self.selected

    def add(self, rule: str, path: str, msg: str, as_error: bool | None = None) -> None:
        if not self.wants(rule):
            return
        spec = RULE_MAP[rule]
        raw_path = path.split(":", 1)[0]
        if as_error is not None:
            sev = "error" if as_error else "warn"
        elif self.strict or (self.changed_paths is not None and raw_path in self.changed_paths):
            sev = "error"
        else:
            sev = spec.repo_severity
        self.findings.append((sev, rule, path, msg))


def run_repo_checks(col: LintCollector, metas: dict[str, dict], skip_ntfs: bool,
                    changed_files: list[str] | None = None) -> None:
    if not skip_ntfs and col.wants("ntfs-paths"):
        cmd = ["git", "ls-files", "-z"]
        out = subprocess.check_output(cmd, cwd=REPO)
        res = ntfs_chk.check_paths(out.split(b"\x00"))
        for kind, items in res.items():
            for it in items:
                col.add("ntfs-paths", str(it), f"{kind}: {it}")

    if col.wants("docs-utf8"):
        pats = ["AGENTS.md", "TOOLKIT.md", "README.md", "docs/**/*.md",
                "libs/*/NOTES.md", "libs/*/README.md", "scratchpad/*.txt", "scripts/*.py"]
        for pat in pats:
            for p in sorted(glob.glob(f"{REPO}/{pat}", recursive=True)):
                try:
                    open(p, encoding="utf-8", errors="strict").read()
                except UnicodeDecodeError as e:
                    col.add("docs-utf8", os.path.relpath(p, REPO), f"non-UTF-8: {e}")

    if col.wants("keep-dirs-manifest"):
        seen: set[str] = set()
        kp = f"{REPO}/scripts/wasm_keep_dirs.txt"
        for lno, ln in enumerate(open(kp, encoding="utf-8"), 1):
            s = ln.rstrip("\n")
            if not s or s.startswith("#"):
                continue
            parts = s.split("\t")
            if len(parts) != 2:
                col.add("keep-dirs-manifest", f"scripts/wasm_keep_dirs.txt:{lno}", f"expected 2 tab fields: {s!r}")
                continue
            slug, rel = parts
            if not os.path.isdir(f"{REPO}/libs/{slug}"):
                col.add("keep-dirs-manifest", f"scripts/wasm_keep_dirs.txt:{lno}", f"unknown slug {slug!r}")
            if not rel or rel.startswith("/") or ".." in rel.split("/") or "//" in rel:
                col.add("keep-dirs-manifest", f"scripts/wasm_keep_dirs.txt:{lno}", f"bad relative dir {rel!r}")
            if s in seen:
                col.add("keep-dirs-manifest", f"scripts/wasm_keep_dirs.txt:{lno}", f"duplicate entry {s!r}")
            seen.add(s)

    if col.wants("meta-ports") or col.wants("meta-cfg-port"):
        ports: dict[str, str] = {}
        changed_set = set(changed_files or [])
        for slug, m in sorted(metas.items()):
            ws = m.get("wasm_status")
            p = str(m.get("port") or "").strip()
            dup = m.get("duplicate_of")
            if p:
                if not p.isdigit():
                    col.add("meta-ports", f"libs/{slug}/meta.json", f"non-numeric port {p!r}")
                elif p in ports:
                    col.add("meta-ports", f"libs/{slug}/meta.json", f"duplicate port {p} (already {ports[p]})")
                ports[p] = slug
            elif ws == "playable" and not dup:
                col.add("meta-ports", f"libs/{slug}/meta.json", "playable non-duplicate lib missing port")

            cfg = f"{REPO}/libs/{slug}/config.fluffos"
            if p and os.path.isfile(cfg):
                cm = re.search(r"(?m)^port number\s*:\s*(\d+)", open(cfg, encoding="utf-8", errors="replace").read())
                if cm and cm.group(1) != p:
                    touched = (f"libs/{slug}/meta.json" in changed_set or f"libs/{slug}/config.fluffos" in changed_set)
                    col.add(
                        "meta-cfg-port",
                        f"libs/{slug}/config.fluffos",
                        f"port number {cm.group(1)} != meta.json port {p}",
                        as_error=(True if (col.strict or touched) else None),
                    )


QUERY_TYPO_PAT = re.compile(
    rb'->\s*(queyr|queryr|qury|qurey|quey|quer|qeury|qeuery|quert|quary|'
    rb'qury_temp|queyr_temp|queryr_temp|qurey_temp|qeury_temp|qeuery_temp|quety_temp|'
    rb'query_tmp|query_tme|query_tepm|query_tmep|querk_skill|quert_respect|'
    rb'query_skil|quert_skill|queyr_skill)\s*\('
)
CALL_TYPO_PAT = re.compile(
    rb'->\s*(recieve_damage|recieve_wound|recieve_curing|delte_temp|delet_temp|settemp|se_temp|stat_busy)\s*\('
)


def check_file_worker(task: tuple[str, dict]) -> list[tuple[str, str, str]]:
    """Run all stateless per-file lint rules on a single tracked file.

    Returns list of (rule, path, message). Designed for ProcessPoolExecutor.
    """
    path, ctx = task
    slug = ctx["slug"]
    rel = ctx["rel"]
    is_wiz = ctx["is_wiz"]
    active = ctx["active"]
    selected = ctx["selected"]

    def want(r: str) -> bool:
        return selected is None or r in selected

    full = f"{REPO}/{path}"
    try:
        b = open(full, "rb").read()
    except OSError:
        return []

    hits: list[tuple[str, str, str]] = []

    if want("no-pragma-no-warnings") and b"no_warnings" in b and PRAGMA_NOWARN_RE.search(b):
        hits.append(("no-pragma-no-warnings", path, "#pragma no_warnings is forbidden (AGENTS.md)"))

    if is_wiz or not active or "海洋2002/hy3/" in rel:
        return hits

    if want("whole-file-duplicate") and len(b) >= 80:
        lines = b.splitlines(keepends=True)
        n = len(lines)
        for k in range(max(2, n // 2 - 3), min(n, n // 2 + 4)):
            a, c = b"".join(lines[:k]), b"".join(lines[k:])
            if len(a) >= 40 and re.sub(rb"\s+", b"", a) == re.sub(rb"\s+", b"", c):
                hits.append(("whole-file-duplicate", path, f"file body duplicated across lines 1..{k} / {k+1}..{n}"))
                break

    if want("missing-embed-h") and not ctx["has_embed_h"] and b"embed.h" in b:
        if re.search(rb'#include\s+"/?inherit/item/embed\.h"', b):
            hits.append(("missing-embed-h", path, "includes /inherit/item/embed.h which is absent from lib"))

    if want("double-slash-path") and b'"//' in b:
        for m in DOUBLE_SLASH_PAT.finditer(b):
            ls = b.rfind(b"\n", 0, m.start()) + 1
            if not b[ls:m.start()].lstrip().startswith(b"//"):
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("double-slash-path", f"{path}:{ln}", f"double leading slash path {m.group(0).decode('latin-1')}"))
                break

    if want("not-literal-cmp") and b'!"' in b:
        if notlitfix.fix(b)[1]:
            hits.append(("not-literal-cmp", path, "comparison against negated string literal (`== !\"...\"`)"))

    if want("query-method-typo") and b"->" in b and QUERY_TYPO_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in QUERY_TYPO_PAT.finditer(b):
            if mk[m.start(1)]:
                ln = b.count(b"\n", 0, m.start(1)) + 1
                hits.append(("query-method-typo", f"{path}:{ln}", f"misspelled query method `->{m.group(1).decode('latin-1')}()`"))
                break

    if want("call-method-typo") and b"->" in b and CALL_TYPO_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in CALL_TYPO_PAT.finditer(b):
            if mk[m.start(1)]:
                ln = b.count(b"\n", 0, m.start(1)) + 1
                hits.append(("call-method-typo", f"{path}:{ln}", f"misspelled call_other method `->{m.group(1).decode('latin-1')}()`"))
                break

    if want("literal-or") and (b"||" in b or b"&&" in b):
        if litorfix.fix(b)[1]:
            hits.append(("literal-or", path, "bare string literal operand in boolean chain (`x == \"a\" || \"b\"`)"))

    if want("cmp-chain") and (b"!=" in b or b"==" in b):
        if cmpfix.fix(b)[1]:
            hits.append(("cmp-chain", path, "always-true/always-false repeated comparison chain"))

    if want("vision-env") and b"environment(" in b and b"message_vision" in b:
        if visenvfix.fix(b)[1]:
            hits.append(("vision-env", path, "message_vision(..., environment(me), me) passes room instead of actor"))

    if want("family-index") and b"family" in b:
        if famifix.fix(b)[1]:
            hits.append(("family-index", path, "unguarded inline query(\"family\")[...] indexing"))

    if want("family-guard") and b"family" in b:
        if famgfix.fix(b)[1]:
            hits.append(("family-guard", path, "mapping fam = query(\"family\") indexed without mapp() check"))

    if want("perform-weapon") and b"query_temp" in b and ("/kungfu/skill/" in rel or "/daemon/" in rel):
        if perfwpnfix.fix(b)[1]:
            hits.append(("perform-weapon", path, "query_temp(\"weapon\") used without objectp() check"))

    if want("unit-cut-utf8") and b"[2..]" in b:
        if unitcutfix.fix(b)[1]:
            hits.append(("unit-cut-utf8", path, "GBK-era [2..] unit cut on single Chinese character unit"))

    if want("pname-slice-utf8") and b"0xFFFE" in b:
        txt = b.decode("utf-8", "replace")
        if pnamefix.edits_for(txt):
            hits.append(("pname-slice-utf8", path, "GBK 0xFFFE + [0..1] one-character pick"))

    if want("display-pad-utf8") and (b"emotion" in b or b"bar_string" in b or b"blank_string" in b or b"full_string" in b or b"bmin_string" in b):
        txt = b.decode("utf-8", "replace")
        if dispfix.edits_edemote(txt) or dispfix.edits_scorebar(txt):
            hits.append(("display-pad-utf8", path, "GBK-era *2 / /2 display padding index"))

    if want("byte-char-utf8") and (b"is_chinese" in b or b"mixup" in b or b"channeld" in path.encode()):
        txt = b.decode("utf-8", "replace")
        if bytefix.edits_parity(txt) or bytefix.edits_clubpoem(txt) or bytefix.edits_channeld(txt) or bytefix.edits_strlen2(txt):
            hits.append(("byte-char-utf8", path, "GBK-era parity/clubpoem/channeld byte indexing"))

    if want("strlen-gate-utf8") and b"strlen" in b:
        txt = b.decode("utf-8", "replace")
        if strlenfix.edits(txt):
            hits.append(("strlen-gate-utf8", path, "strlen() byte bound twice the message's Chinese character count"))

    if want("chat-empty-index") and b"chat_msg" in b:
        txt = b.decode("utf-8", "replace")
        if chatfix.fix(txt)[1]:
            hits.append(("chat-empty-index", path, "chat_msg[random(sizeof(chat_msg))] without sizeof guard"))

    if want("functional-locals") and b"this_object()" in b and b"(:" in b:
        if funclocfix.fix(b)[1]:
            hits.append(("functional-locals", path, "local variable used inside (: this_object(), ({ ... }) :) functional"))

    if want("callout-info-index") and b"call_out_info" in b and os.path.basename(rel) not in calloutfix.LEFT:
        if not calloutfix.TOP.search(rel) and not calloutfix.ANY.search(rel) and calloutfix.fix(b)[1]:
            hits.append(("callout-info-index", path, "call_out_info()[i][3] or sizeof==4 assuming MudOS 4-tuple"))

    if want("getdir-strip-dotc") and b".lpc" in b and b"..<3" in b:
        if gdstripfix.scan(b):
            hits.append(("getdir-strip-dotc", path, "get_dir(\"*.lpc\") stripped with [0..<3] instead of [0..<5]"))

    if want("array-reserved-type") and b"array" in b:
        if arrayfix.fix(b)[1]:
            hits.append(("array-reserved-type", path, "bare `array` used as type (ARRAY_RESERVED_WORD is off)"))

    if want("negative-ranges") and b".." in b:
        txt = b.decode("latin-1")
        _, edits, _ = negrangefix.process(txt)
        if edits:
            hits.append(("negative-ranges", path, "negative constant range index without `<`"))

    if want("dotc-path") and b'.c"' in b:
        root = f"{REPO}/libs/{slug}/work"
        if dotcfix.fix(b, root, full)[1]:
            hits.append(("dotc-path", path, "\".c\" object literal path where only .lpc exists"))

    if want("dotdot-dir") and b".." in b and b"__DIR__" in b:
        if dotdotfix.fix(b, rel, direct=True)[1]:
            hits.append(("dotdot-dir", path, "__DIR__ \"../\" passed directly to driver path efun"))

    if want("macro-strparam") and b"#define" in b:
        if macrostrfix.fix(b)[1]:
            hits.append(("macro-strparam", path, "#define parameter name inside string literal (K&R preprocessor habit)"))

    if want("member-array-char") and b"member_array" in b:
        if memcharfix.fix(b)[1]:
            hits.append(("member-array-char", path, "member_array('c', str) byte search on string"))

    if want("eaten-quote") and not ctx["comma_quote_skip"]:
        txt = b.decode("utf-8", "replace")
        if quotefix.fix_text(txt)[1]:
            hits.append(("eaten-quote", path, "unterminated string literal before statement terminator"))

    if want("money-path-clone") and ctx["uses_obj_money"] and b'"/clone/money/' in b:
        hits.append(("money-path-clone", path, "\"/clone/money/\" literal in /obj/money/ lib"))

    if want("default-switch-only") and b"switch" in b and b"default" in b and not swfix.SKIP.search(rel):
        if swfix.find_all(b.decode("utf-8", "replace")):
            hits.append(("default-switch-only", path, "switch without any case statements (default only)"))

    if want("if-else-empty") and b"else" in b:
        prev = None
        for i, ln in enumerate(b.split(b"\n")):
            if not ln.strip():
                continue
            if prev is not None and ifelse.ELSE.match(ln) and ifelse.bare_if(prev[1].rstrip(b"\r")):
                hits.append(("if-else-empty", f"{path}:{prev[0]+1}", "if/while/for directly followed by else (missing `;`)"))
                break
            prev = (i, ln)

    if want("predefined-macro") and b"SAVE_EXTENSION" in b:
        lib = predmacrofix.Lib(slug)
        ginc = predmacrofix.global_include(slug)
        gpath = lib.resolve("/", ginc, b"<") if ginc else None
        glob_def = {m: bool(gpath and lib.reach(m, gpath)) for m in predmacrofix.RENAMES}
        if predmacrofix.fix(b, lib, rel, glob_def)[1]:
            hits.append(("predefined-macro", path, "bare `SAVE_EXTENSION` without #define (use `__SAVE_EXTENSION__`)"))

    if want("dead-u-exits") and b"/u/" in b:
        txt = b.decode("utf-8", "replace")
        for ln_no, line in enumerate(txt.splitlines(), 1):
            code_part = line.split("//", 1)[0]
            dm = DEAD_U_EXITS_RE.search(code_part)
            if dm:
                hits.append(("dead-u-exits", f"{path}:{ln_no}", f"migrated/dead wizard path `{dm.group(1)}`"))
                break

    if want("cond-assign") and (b"if" in b or b"while" in b):
        mk = code_mask(b, heredoc=True)
        for m in sc.COND.finditer(b):
            if not mk[m.start()]:
                continue
            end = sc.cond_span(b, mk, m.end() - 1)
            if end < 0:
                continue
            for _, term in sc.split_terms(b[m.end():end - 1]):
                tm = sc.TERM.match(term.strip())
                if tm:
                    ln = b.count(b"\n", 0, m.start()) + 1
                    hits.append(("cond-assign", f"{path}:{ln}", f"constant assignment `{tm.group(1).decode('latin-1')} = {tm.group(2).decode('latin-1')}` in condition"))
                    break

    # New mask-aware checks for KB 04 §6.31/6.32 and KB 06 §7.377..7.391
    need_mask = (
        (want("throwing-combined-diamond") and b"THROWING" in b and b"COMBINED_ITEM" in b and ctx["throwing_has_combined"])
        or (want("prev-obj-path-cmp") and b"previous_object" in b)
        or (want("local-shadows-sefun") and b"home_path" in b)
        or (want("tp-carry-create") and b"carry_object" in b and b"this_player" in b)
        or (want("unguarded-read-file-nested") and b"read_file" in b and not ctx["sefun_wraps_rf"])
        or (want("unguarded-get-dir") and b"get_dir" in b)
        or (want("for-scope-leak") and b"for" in b)
        or (want("path-macro-plus-arrow") and b"#define" in b and b"->" in b)
        or (want("efun-dbase-call") and b"efun::" in b)
        or (want("quoted-efun-call") and b'()"' in b)
    )
    if need_mask:
        mk = code_mask(b, heredoc=True)
        cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))

        if want("efun-dbase-call") and b"efun::" in cb:
            em = EFUN_DBASE_RE.search(cb)
            if em:
                ln = b.count(b"\n", 0, em.start()) + 1
                hits.append(("efun-dbase-call", f"{path}:{ln}", f"`{em.group(0).decode('latin-1').rstrip('(').strip()}` is not a FluffOS efun (use `::set` / `::add` or inherited F_DBASE)"))

        if want("quoted-efun-call") and b'()"' in cb:
            qm = QUOTED_EFUN_RE.search(cb)
            if qm:
                ln = b.count(b"\n", 0, qm.start()) + 1
                hits.append(("quoted-efun-call", f"{path}:{ln}", f"quoted zero-arg efun string `{qm.group(0).decode('latin-1')}` passed where an object expression was intended"))

        if want("throwing-combined-diamond") and ctx["throwing_has_combined"]:
            if re.search(rb"(?m)^[ \t]*inherit[ \t]+THROWING\s*;", cb) and re.search(rb"(?m)^[ \t]*inherit[ \t]+COMBINED_ITEM\s*;", cb):
                hits.append(("throwing-combined-diamond", path, "inherit COMBINED_ITEM duplicates THROWING ancestor (redefines nomask functions)"))

        if want("prev-obj-path-cmp") and b"previous_object" in cb:
            if PREV_OBJ_CMP_RE.search(b):
                hits.append(("prev-obj-path-cmp", path, "previous_object() compared directly to string path literal"))

        if want("local-shadows-sefun") and b"home_path" in cb:
            if SHADOW_SEFUN_RE.search(cb):
                hits.append(("local-shadows-sefun", path, "local variable `home_path` shadows sefun called in same function"))

        if want("tp-carry-create") and b"carry_object" in cb:
            cm = re.search(rb"(?m)^[ \t]*(?:void|int|mixed)?[ \t]*create\s*\([^)]*\)\s*\{", cb)
            if cm:
                end = morefix.brace_span(b, mk, cm.end() - 1)
                if end > 0 and re.search(rb"this_player\s*\(\s*\)\s*->\s*carry_object\s*\(", cb[cm.end():end]):
                    hits.append(("tp-carry-create", path, "this_player()->carry_object() inside create()"))

        if want("path-macro-plus-arrow") and b"#define" in b and b"->" in cb:
            for dm in re.finditer(rb'(?m)^[ \t]*#[ \t]*define[ \t]+([A-Z][A-Z0-9_]{2,})[ \t]+([A-Z][A-Z0-9_]*\s*\+\s*"[^"\n]+")\s*$', b):
                macro = dm.group(1)
                if re.search(rb"\b" + macro + rb"\s*->", cb):
                    hits.append(("path-macro-plus-arrow", path, f"concatenated path macro `{macro.decode()}` used before `->` (`->` binds tighter than `+`)"))
                    break

        if want("unguarded-read-file-nested") and b"read_file" in cb and not ctx["sefun_wraps_rf"]:
            lines_raw = b.split(b"\n")
            for rm in UNGUARDED_RF_NEST.finditer(b):
                if not mk[rm.start()]:
                    continue
                target_rel = rm.group(1).decode("utf-8", "replace").lstrip("/")
                if os.path.exists(f"{REPO}/libs/{slug}/work/{target_rel}"):
                    continue
                ln = b.count(b"\n", 0, rm.start())
                line_bytes = lines_raw[ln]
                if re.search(rb"\|\||file_size\s*\(", line_bytes):
                    continue
                ctx_prev = b"\n".join(lines_raw[max(0, ln - 6):ln + 1])
                if re.search(rb"file_size\s*\(", ctx_prev):
                    continue
                hits.append(("unguarded-read-file-nested", f"{path}:{ln+1}", f"missing-file read_file(\"/{target_rel}\") passed unguarded"))
                break

        if want("unguarded-get-dir") and b"get_dir" in cb:
            lines_cb = cb.split(b"\n")
            for gm in list(UNGUARDED_GD_HOF.finditer(cb)) + list(UNGUARDED_GD_FOREACH.finditer(cb)):
                ln = cb.count(b"\n", 0, gm.start())
                line_s = lines_cb[ln]
                # Skip if static literal directory already exists in repo work tree
                lm = re.search(rb'get_dir\s*\(\s*"(/[^"*?\n]+)', b.split(b"\n")[ln])
                if lm:
                    drel = lm.group(1).decode("utf-8", "replace").lstrip("/").rstrip("/")
                    if os.path.isdir(f"{REPO}/libs/{slug}/work/{drel}"):
                        continue
                ctx_next = b"\n".join(lines_cb[ln:min(len(lines_cb), ln + 3)])
                if GD_GUARD_CTX.search(ctx_next):
                    continue
                ctx_prev = b"\n".join(lines_cb[max(0, ln - 8):ln + 1])
                if GD_GUARD_CTX.search(ctx_prev):
                    continue
                hits.append(("unguarded-get-dir", f"{path}:{ln+1}", "get_dir() on missing/dynamic dir consumed without `|| ({})` guard"))
                break

        if want("for-scope-leak") and b"for" in cb:
            blocks = forscope.top_blocks(cb)
            starts = [x[0] for x in blocks]
            decl_re = forscope.TYPES + rb"[ \t*]+(?:[^;(){}]*,\s*)?\*?"
            for fm in forscope.FOR.finditer(cb):
                vname = fm.group(1)
                fs, fe = forscope.func_bounds(blocks, starts, fm.start())
                if fe < 0:
                    continue
                close_paren = forscope.match_close(cb, cb.find(b"(", fm.start()), 0x28, 0x29)
                if close_paren < 0:
                    continue
                after_loop = forscope.stmt_end(cb, close_paren + 1)
                rest_ba = bytearray(cb[after_loop:fe])
                for m2 in forscope.FOR.finditer(cb, after_loop, fe):
                    if m2.group(1) != vname:
                        continue
                    hc2 = forscope.match_close(cb, cb.find(b"(", m2.start()), 0x28, 0x29)
                    if hc2 < 0:
                        continue
                    e2 = forscope.stmt_end(cb, hc2 + 1)
                    for q in range(m2.start() - after_loop, min(e2, fe) - after_loop):
                        rest_ba[q] = 32
                rest = bytes(rest_ba)
                first = re.search(rb"(?<![A-Za-z0-9_'])" + vname + rb"\b", rest)
                if not first:
                    continue
                if re.search(rb"(?m)^[ \t]*#[ \t]*(else|elif)\b", rest[:first.start()]):
                    continue
                vdecl = decl_re + vname + rb"\b"
                if re.search(vdecl, cb[fs:fm.start()]):
                    continue
                d = re.search(vdecl, rest)
                if d and d.start() <= first.start():
                    continue
                ln = b.count(b"\n", 0, fm.start()) + 1
                hits.append(("for-scope-leak", f"{path}:{ln}", f"`for`-scoped variable `{vname.decode()}` read after loop"))
                break

    return hits


def run_targeted_checks(col: LintCollector, metas: dict[str, dict], gitlinks: set[str],
                        files: list[str], only_slugs: set[str] | None = None) -> None:
    slugs = sorted(
        s for s in metas
        if _is_active_vendored(s, metas, gitlinks) and (only_slugs is None or s in only_slugs)
    )
    active_simuls: list[tuple[str, str]] = []
    seen_simuls: set[str] = set()
    for slug in slugs:
        for rp in _active_simul_paths(slug):
            if rp not in seen_simuls:
                seen_simuls.add(rp)
                active_simuls.append((slug, rp))

    if col.wants("sefun-cat-unguarded") or col.wants("sefun-read-file-arity"):
        for _, rp in active_simuls:
            b = open(f"{REPO}/{rp}", "rb").read()
            if col.wants("sefun-cat-unguarded") and b"cat" in b and catfix.patch_bytes(b) is not None:
                col.add("sefun-cat-unguarded", rp, "sefun::cat() passes unguarded read_file() output")
            if col.wants("sefun-read-file-arity") and b"read_file" in b:
                mk = code_mask(b, heredoc=True)
                cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
                for rm in READ_FILE_SEFUN_RE.finditer(cb):
                    args = [x.strip() for x in rm.group(2).split(b",") if x.strip()]
                    if not rm.group(1) or len(args) < 3:
                        col.add("sefun-read-file-arity", rp, "sefun::read_file() drops start_line/number_of_lines or lacks varargs")

    targeted_bins: dict[str, list[tuple[str, str, str]]] = {
        k: [] for k in ("more", "toptend", "logind", "wabaod", "post", "menu", "books", "blockade", "command", "rankd", "ping", "warcraft", "mrdizi", "say", "cmdco", "sanshen", "rtcfg", "ver_cfg", "band", "embed_cand")
    }
    slug_set = set(slugs)
    has_embed = {s: os.path.isfile(f"{REPO}/libs/{s}/work/inherit/item/embed.h") for s in slugs}
    for p in files:
        if "/work/" not in p or not p.endswith((".lpc", ".h")):
            continue
        prefix, rel_raw = p.split("/work/", 1)
        slug = prefix.split("/", 1)[1]
        if slug not in slug_set:
            continue
        rel = "/" + rel_raw
        if sc.TOP.search(rel) or sc.ANY.search(rel) or "海洋2002/hy3/" in rel:
            continue
        bn = os.path.basename(rel)
        item = (slug, p, rel)
        if "more" in bn:
            targeted_bins["more"].append(item)
        if rel == "/adm/daemons/toptend.lpc":
            targeted_bins["toptend"].append(item)
        if "login" in bn:
            targeted_bins["logind"].append(item)
        if rel == "/adm/daemons/wabaod.lpc":
            targeted_bins["wabaod"].append(item)
        if bn == "post.lpc":
            targeted_bins["post"].append(item)
        if rel == "/std/menu.lpc":
            targeted_bins["menu"].append(item)
        if bn in ("books.lpc", "book.lpc"):
            targeted_bins["books"].append(item)
        if "blockade" in bn or "recover" in bn:
            targeted_bins["blockade"].append(item)
        if rel == "/feature/command.lpc":
            targeted_bins["command"].append(item)
        if rel == "/adm/daemons/rankd.lpc":
            targeted_bins["rankd"].append(item)
        if bn in ("pingd.lpc", "pingtcp.lpc"):
            targeted_bins["ping"].append(item)
        if bn == "warcraft.h":
            targeted_bins["warcraft"].append(item)
        if rel in ("/d/mr/npc/dizi.lpc", "/d/mr1/npc/dizi.lpc"):
            targeted_bins["mrdizi"].append(item)
        if rel == "/cmds/std/say.lpc":
            targeted_bins["say"].append(item)
        if rel in ("/cmds/std/block.lpc", "/cmds/skill/defense.lpc", "/cmds/std/perform.lpc", "/cmds/std/exercise.lpc", "/cmds/std/meditate.lpc", "/cmds/usr/wash.lpc", "/cmds/usr/bbg.lpc") or (rel.startswith("/cmds/") and bn == "jbless.lpc"):
            targeted_bins["cmdco"].append(item)
        if rel == "/kungfu/skill/fanliangyi-dao/sanshen.lpc":
            targeted_bins["sanshen"].append(item)
        if bn == "runtime_config.h":
            targeted_bins["rtcfg"].append(item)
        if any(k in bn for k in ("versiond", "getconfig", "server", "config")):
            targeted_bins["ver_cfg"].append(item)
        if "band" in bn or "security" in bn or "logind" in bn:
            targeted_bins["band"].append(item)
        if not has_embed[slug] and "/weapon/" in rel:
            targeted_bins["embed_cand"].append(item)

    if col.wants("start-more-unguarded"):
        for _, p, _ in targeted_bins["more"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"start_more" in b and morefix.plan(b) is not None:
                col.add("start-more-unguarded", p, "start_more() explodes string param without stringp() guard")

    if col.wants("toptend-guard"):
        for slug, p, _ in targeted_bins["toptend"]:
            if slug in topguardfix.SKIP_NON_JACKYBOY:
                continue
            _, ch = topguardfix.fix_text(open(f"{REPO}/{p}", "rb").read().decode("utf-8", "replace"))
            if ch:
                col.add("toptend-guard", p, f"toptend guard gaps: {', '.join(ch)}")

    if col.wants("visitor-count-unguarded"):
        for _, p, _ in targeted_bins["logind"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"howmany_visitor" in b and viscntfix.plan(b):
                col.add("visitor-count-unguarded", p, "howmany_visitor() passes unguarded read_file() to sscanf()")

    if col.wants("wabaod-gbk-index"):
        for _, p, _ in targeted_bins["wabaod"]:
            if re.search(rb"desc\s*\[\s*b\s*\.\.\s*b\s*\+\s*1\s*\]\s*=", open(f"{REPO}/{p}", "rb").read()):
                col.add("wabaod-gbk-index", p, "forward desc[b..b+1] byte mutation breaks under UTF-8")

    if col.wants("iips-empty-mailbox"):
        for _, p, _ in targeted_bins["post"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"__BoxInfo" in b and re.search(rb"if\s*\(\s*!\s*letter\s*\)\s*letter\s*=\s*__Current\s*;", b) and not re.search(rb"letter\s*<\s*0", b):
                col.add("iips-empty-mailbox", p, "save_letter() indexes __BoxInfo[letter] without letter < 0 check")

    if col.wants("lima-menu-protected-remove"):
        for _, p, _ in targeted_bins["menu"]:
            if re.search(rb"(?m)^[ \t]*protected\s+void\s+remove\s*\(", open(f"{REPO}/{p}", "rb").read()):
                col.add("lima-menu-protected-remove", p, "protected void remove() blocks external destruct() call_other")

    if col.wants("dead-souls-stat-3tuple"):
        for _, p, _ in targeted_bins["books"]:
            if re.search(rb"sizeof\s*\(\s*statinfo\s*\)\s*!=\s*3", open(f"{REPO}/{p}", "rb").read()):
                col.add("dead-souls-stat-3tuple", p, "checks sizeof(statinfo) != 3 on FluffOS 4-tuple stat()")

    if col.wants("keep-dir-blockade"):
        for _, p, rel in targeted_bins["blockade"]:
            r = keepdirfix.plan(os.path.basename(rel), open(f"{REPO}/{p}", "rb").read())
            if r and r[1]:
                col.add("keep-dir-blockade", p, "blockade/recover missing /data/keep mkdir or file_size check")

    if col.wants("mud-port-config"):
        stale_slugs = {slug for slug, p, _ in targeted_bins["rtcfg"] if mudportfix.stale_header([f"{REPO}/{p}"])}
        for slug, p, _ in targeted_bins["ver_cfg"]:
            if slug in stale_slugs:
                b = open(f"{REPO}/{p}", "rb").read()
                if b"__MUD_PORT__" in b and mudportfix.fix(b)[1]:
                    col.add("mud-port-config", p, "get_config(__MUD_PORT__) returns string under old runtime_config.h")

    if col.wants("loopback-fail-open"):
        for _, p, _ in targeted_bins["band"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"is_local_site" in b and re.search(rb"if\s*\(\s*!\s*stringp\s*\(\s*site\s*\)\s*\)\s*return\s+1\s*;", b):
                col.add("loopback-fail-open", p, "is_local_site() fails open on non-string IP")

    if col.wants("missing-embed-h"):
        for _, p, _ in targeted_bins["embed_cand"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"embed.h" in b and re.search(rb'#include\s+"/?inherit/item/embed\.h"', b):
                col.add("missing-embed-h", p, "includes /inherit/item/embed.h which is missing from lib")

    if col.wants("enable-player-guard"):
        for _, p, _ in targeted_bins["command"]:
            nb, _ = epfix.fix(open(f"{REPO}/{p}", "rb").read())
            if nb is not None:
                col.add("enable-player-guard", p, "enable_player() lacks reentrancy guard")

    if col.wants("rank-null-guard"):
        for slug, p, _ in targeted_bins["rankd"]:
            _, msgs = rankfix.fix(open(f"{REPO}/{p}", "rb").read(), slug)
            if any(m.startswith("FIX") for m in msgs):
                col.add("rank-null-guard", p, "adm/daemons/rankd.lpc lacks !objectp(ob) guard")

    if col.wants("ping-strip-callout-nosave"):
        for _, p, _ in targeted_bins["ping"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"strip_callout" in b:
                mk = code_mask(b)
                for m in re.finditer(rb"\bnosave\s+int\s+strip_callout\s*\(", b):
                    if mk[m.start()]:
                        col.add("ping-strip-callout-nosave", p, "nosave int strip_callout() emits Illegal to declare nosave function (use protected)")
                        break

    if col.wants("warcraft-actions-noop"):
        noop_re = re.compile(rb'^[ \t]*actions\s*==\s*"follow"\s*\?\s*[^;]+;', re.M)
        for _, p, _ in targeted_bins["warcraft"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"actions" in b:
                mk = code_mask(b)
                for m in noop_re.finditer(b):
                    if mk[m.start()]:
                        col.add("warcraft-actions-noop", p, "discarded `actions == \"follow\" ? ... : ...;` comparison leaves warcraft status untranslated")
                        break

    if col.wants("mr-dizi-duplicate-inherit"):
        for slug, p, rel in targeted_bins["mrdizi"]:
            job_p = f"{REPO}/libs/{slug}/work{os.path.dirname(rel)}/job-dizi.lpc"
            if os.path.isfile(job_p) and re.search(rb'(?m)^[ \t]*inherit\s+NPC\s*;', open(f"{REPO}/{p}", "rb").read()):
                if re.search(rb'(?m)^[ \t]*inherit\s+NPC\s*;', open(job_p, "rb").read()):
                    col.add("mr-dizi-duplicate-inherit", p, "inherit NPC; in dizi.lpc duplicates job-dizi.lpc inherit and breaks compilation")

    if col.wants("say-delete-busy"):
        for _, p, _ in targeted_bins["say"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"delete_busy" not in b:
                continue
            mk = code_mask(b, heredoc=True)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if (re.search(rb'\bcall_out\s*\(\s*"delete_busy"\s*,\s*[^,)]+\s*\)', cb)
                    or not re.search(rb'\bvoid\s+delete_busy\s*\(\s*\w+\s+\w+\s*\)', cb)
                    or re.search(rb'\bvoid\s+delete_busy\s*\([^{]*\)\s*\{[^}]*\bthis_player\s*\(', cb)
                    or re.search(rb'\bvoid\s+delete_busy\s*\([^{]*\)\s*\{[^}]*\bobject\s+\w+\s*;[^}]*if\s*\(\s*!\s*\w+\s*\)\s*return', cb)):
                col.add("say-delete-busy", p, "say.lpc delete_busy() missing target/arg, commented out, uninitialized ob, or calling this_player() in call_out")

    if col.wants("cmd-callout-this-player"):
        cmdco_re = re.compile(
            rb'\b(?:void|int|varargs\s+void|varargs\s+int)\s+(?:cost|show_bless|del_busy|dazuo|minsi|out|gogogo_start|gogogo_running)\s*\([^)]*\)\s*\{[^}]{0,600}?\bthis_player\s*\('
        )
        for _, p, _ in targeted_bins["cmdco"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"this_player" not in b:
                continue
            mk = code_mask(b, heredoc=True)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if cmdco_re.search(cb):
                col.add("cmd-callout-this-player", p, "command call_out callback uses this_player() (0 under call_out)")

    if col.wants("skill-sanshen-del-perform"):
        for _, p, _ in targeted_bins["sanshen"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'"del_perform"' not in b:
                continue
            mk = code_mask(b, heredoc=True)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if (re.search(rb'\b(?:call_out|start_call_out)\s*\(', cb)
                    and not re.search(rb'\bdel_perform\s*\(', cb)):
                col.add("skill-sanshen-del-perform", p, "sanshen.lpc schedules del_perform without defining void del_perform(object me)")


def _changed_files(base: str | None) -> list[str]:
    paths: set[str] = set()
    if base:
        out = subprocess.run(
            ["git", "-c", "core.quotepath=false", "diff", "--name-only", "--diff-filter=ACMRT", base, "HEAD"],
            cwd=REPO, capture_output=True, text=True,
        )
        if out.returncode == 0:
            paths.update(ln for ln in out.stdout.splitlines() if ln.strip())
    # Always include local uncommitted modifications & untracked files when no explicit commit range or base==HEAD
    if not base or base == "HEAD":
        for cmd in (
            ["git", "-c", "core.quotepath=false", "diff", "--name-only", "--diff-filter=ACMRT"],
            ["git", "-c", "core.quotepath=false", "diff", "--cached", "--name-only", "--diff-filter=ACMRT"],
            ["git", "-c", "core.quotepath=false", "ls-files", "--others", "--exclude-standard"],
        ):
            r = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
            paths.update(ln for ln in r.stdout.splitlines() if ln.strip())
    return sorted(paths)


def _run_file_batch(col: LintCollector, paths: list[str], metas: dict[str, dict], gitlinks: set[str],
                    selected: set[str] | None, workers: int) -> None:
    slug_ctx: dict[str, dict] = {}
    tasks: list[tuple[str, dict]] = []
    for p in paths:
        if not p.startswith("libs/") or "/work/" not in p or not p.endswith((".lpc", ".h")):
            continue
        prefix, rel_raw = p.split("/work/", 1)
        slug = prefix.split("/", 1)[1]
        if slug in gitlinks:
            continue
        rel = "/" + rel_raw
        if slug not in slug_ctx:
            slug_ctx[slug] = {
                "active": _is_active_vendored(slug, metas, gitlinks),
                "has_embed_h": os.path.isfile(f"{REPO}/libs/{slug}/work/inherit/item/embed.h"),
                "sefun_wraps_rf": _sefun_wraps_read_file(slug),
                "uses_obj_money": moneyfix.taken(slug),
                "throwing_has_combined": _throwing_inherits_combined(slug),
                "comma_quote_skip": False,
            }
        is_wiz = bool(sc.TOP.search(rel) or sc.ANY.search(rel))
        ctx = {
            **slug_ctx[slug],
            "slug": slug,
            "rel": rel,
            "is_wiz": is_wiz,
            "selected": selected,
        }
        tasks.append((p, ctx))

    if not tasks:
        return
    if len(tasks) < 200 or workers <= 1:
        results = [check_file_worker(t) for t in tasks]
    else:
        with ProcessPoolExecutor(max_workers=workers) as ex:
            results = list(ex.map(check_file_worker, tasks, chunksize=500))
    for flist in results:
        for rule, p, msg in flist:
            col.add(rule, p, msg)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list-rules", action="store_true", help="List all lint rules and exit")
    ap.add_argument("--fast", action="store_true", help="Run repo hygiene + targeted zero-hit rules (default)")
    ap.add_argument("--all", action="store_true", help="Run full corpus scan across all tracked .lpc/.h files")
    ap.add_argument("--changed", nargs="?", const="HEAD", default=None, metavar="REF",
                    help="Run all rules on files changed vs REF (plus working tree if REF omitted or HEAD)")
    ap.add_argument("--lib", nargs="+", default=[], metavar="SLUG", help="Lint specific mudlib(s) with all rules")
    ap.add_argument("--files", nargs="+", default=[], metavar="PATH", help="Lint explicit file paths with all rules")
    ap.add_argument("--rule", action="append", default=[], help="Run only the named rule(s)")
    ap.add_argument("--strict", action="store_true", help="Treat baseline warnings as errors")
    ap.add_argument("--skip-ntfs", action="store_true", help="Skip full-tree NTFS path check")
    ap.add_argument("--with-configs", action="store_true", help="Also run scripts/lint_configs.py (requires lpcc)")
    ap.add_argument("--jobs", type=int, default=min(8, os.cpu_count() or 4), help="Parallel workers for --all")
    args = ap.parse_args()

    if args.list_rules:
        for r in RULES:
            print(f"{r.name:30s} {r.scope:9s} {r.repo_severity:5s}  [{r.kb}] {r.summary}")
        print(f"Total: {len(RULES)} rules")
        return 0

    selected = set(args.rule) if args.rule else None
    if selected:
        unknown = selected - RULE_MAP.keys()
        if unknown:
            print(f"Unknown rule(s): {', '.join(sorted(unknown))}", file=sys.stderr)
            return 2

    metas = _load_metas()
    gitlinks, tracked_lib_files = _git_ls_files()
    changed_list = _changed_files(args.changed) if args.changed is not None else []
    if args.files:
        changed_list = list(args.files)
    changed_paths = set(changed_list) if (args.changed is not None or args.files) else None
    col = LintCollector(selected, strict=args.strict, changed_paths=changed_paths)

    if args.files:
        # Check targeted + file rules on the explicit files only
        _run_file_batch(col, changed_list, metas, gitlinks, selected, workers=1)
        # Also run targeted rules on matching files
        sub_slugs = {p.split("/")[1] for p in changed_list if p.startswith("libs/") and len(p.split("/")) > 2}
        if sub_slugs:
            run_targeted_checks(col, metas, gitlinks, changed_list, only_slugs=sub_slugs)
        run_repo_checks(col, metas, skip_ntfs=True, changed_files=changed_list)
    elif args.lib:
        only = set(args.lib)
        unknown_libs = only - metas.keys()
        if unknown_libs:
            print(f"Unknown lib(s): {', '.join(sorted(unknown_libs))}", file=sys.stderr)
            return 2
        run_repo_checks(col, {k: v for k, v in metas.items() if k in only}, skip_ntfs=args.skip_ntfs, changed_files=None)
        run_targeted_checks(col, metas, gitlinks, tracked_lib_files, only_slugs=only)
        lib_files = [p for p in tracked_lib_files if p.startswith("libs/") and p.split("/")[1] in only]
        _run_file_batch(col, lib_files, metas, gitlinks, selected, workers=args.jobs)
    elif args.all:
        run_repo_checks(col, metas, skip_ntfs=args.skip_ntfs)
        run_targeted_checks(col, metas, gitlinks, tracked_lib_files)
        _run_file_batch(col, tracked_lib_files, metas, gitlinks, selected, workers=args.jobs)
    else:
        # --fast or --changed
        run_repo_checks(col, metas, skip_ntfs=args.skip_ntfs, changed_files=changed_list if args.changed is not None else None)
        run_targeted_checks(col, metas, gitlinks, tracked_lib_files)
        if args.changed is not None and changed_list:
            _run_file_batch(col, changed_list, metas, gitlinks, selected, workers=args.jobs)

    if args.with_configs:
        cfg_targets = args.lib or []
        r = subprocess.run(["python3", f"{SCRIPTS_DIR}/lint_configs.py", *cfg_targets], capture_output=True, text=True)
        if r.returncode != 0:
            for ln in (r.stdout + "\n" + r.stderr).splitlines():
                if ln.strip():
                    col.findings.append(("error", "lint-configs", "config.fluffos", ln.strip()))

    errs = [f for f in col.findings if f[0] == "error"]
    warns = [f for f in col.findings if f[0] == "warn"]
    for sev, rule, path, msg in col.findings:
        print(f"{sev.upper():5s} [{rule}] {path}: {msg}")
    print(f"lint: {len(errs)} error(s), {len(warns)} warning(s) across {len(RULES)} rules")
    return 1 if errs else 0


if __name__ == "__main__":
    raise SystemExit(main())
