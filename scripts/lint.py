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
    RuleSpec("missing-team-lord", "targeted", "KB 06 §7.412", "error", "feature/team.lpc omits set_lord()/query_lord() used by trainee/animal NPCs, or animal2.lpc pow() truncation"),
    RuleSpec("undefined-misc-dir", "targeted", "KB 06 §7.413", "error", "paiming_d.lpc/fengkou.lpc using undefined MISC_DIR macro (or void add_to_top_rich return 0;)"),
    RuleSpec("enable-player-guard", "targeted", "KB 05 §7.19", "warn", "feature/command.lpc enable_player() lacking reentrancy guard"),
    RuleSpec("rank-null-guard", "targeted", "KB 06 §7.273", "warn", "adm/daemons/rankd.lpc missing !objectp(ob) fallback"),
    RuleSpec("ping-strip-callout-nosave", "targeted", "KB 04 §6.10", "error", "pingd.lpc/pingtcp.lpc declaring nosave int strip_callout() instead of protected"),
    RuleSpec("warcraft-actions-noop", "targeted", "KB 06 §7.392", "error", "warcraft.h discarded ternary actions == \"follow\" ? ... : ... leaving status untranslated"),
    RuleSpec("mr-dizi-duplicate-inherit", "targeted", "KB 04 §6.31", "error", "d/mr/npc/dizi.lpc declaring inherit NPC while #included by job-dizi.lpc"),
    RuleSpec("say-delete-busy", "targeted", "KB 06 §7.394", "error", "cmds/std/say.lpc call_out(\"delete_busy\") missing arg, deleted/commented body, uninit ob, or this_player()"),
    RuleSpec("cmd-callout-this-player", "targeted", "KB 06 §7.395", "error", "Shared /cmds/ call_out callback invoking this_player() (0 in timer context)"),
    RuleSpec("skill-sanshen-del-perform", "targeted", "KB 06 §7.396", "error", "kungfu/skill/fanliangyi-dao/sanshen.lpc scheduling del_perform without defining void del_perform(object me)"),
    RuleSpec("skill-dead-callout", "targeted", "KB 06 §7.400", "error", "Skill/daemon call_out scheduling undefined destruct_me/remove_effect/perform2/perform_jiaoyang/perform_qiao"),
    RuleSpec("semote-local-functional", "targeted", "KB 04 §6.45", "error", "cmds/std/semote.lpc functional indexing local mapping `emotion_sort[$1]` without `$(emotion_sort)`"),
    RuleSpec("rpp-self-corrupted", "targeted", "KB 04 §6.45", "error", "cmds/adm/{rp,rpp}.lpc self-corrupted by running dbase converter over its own source"),
    RuleSpec("fingerd-db-save-decls", "targeted", "KB 04 §6.47", "error", "adm/daemons/fingerd.lpc DB_SAVE locals outside #ifdef DB_SAVE, spliced in sprintf(), or out of scope across blocks"),
    # Per-file corpus checks (all error in --changed/--files/--strict; configurable in --all)
    RuleSpec("no-pragma-no-warnings", "file", "AGENTS (2026-10-03)", "error", "Forbids #pragma no_warnings anywhere in libs/*/work/"),
    RuleSpec("efun-dbase-call", "file", "KB 06 §7.392", "error", "Non-existent efun::set/addn/query/delete calls failing compilation"),
    RuleSpec("quoted-efun-call", "file", "KB 06 §7.393", "error", "Object efun/sefun called with quoted \"this_object()\"/\"this_player()\"/... string instead of object"),
    RuleSpec("query-method-typo", "file", "KB 06 §7.397", "error", "Misspelled ->query()/->query_temp()/->query_skill()/->query_respect() method call"),
    RuleSpec("call-method-typo", "file", "KB 06 §7.398", "error", "Misspelled ->receive_damage()/->receive_wound()/->receive_curing()/->set_temp()/->delete_temp()/->start_busy() call"),
    RuleSpec("crossed-bracket-query", "file", "KB 06 §7.401", "error", "Bracket-crossed query()/query_temp() corruption (`query(\"k\", map[ob) ]`) breaking compilation"),
    RuleSpec("malformed-load-object", "file", "KB 06 §7.402", "error", "Malformed load_object() call missing closing paren or followed by stray `){`"),
    RuleSpec("delete-temp-three-args", "file", "KB 06 §7.403", "error", "Three-argument delete_temp(\"k\", 1, ob) stray `1` failing compilation against delete_temp(string, object)"),
    RuleSpec("exit-string-as-object", "file", "KB 06 §7.404", "error", "Exit room path string passed as object to find_object(object dest) or sefun query(..., exits[...])"),
    RuleSpec("missing-mapping-comma", "file", "KB 06 §7.405", "error", "Missing comma between consecutive mapping literal entries (`\"dodge\": 15\\n\"parry\": 15`) breaking compilation"),
    RuleSpec("unclosed-mapping-string", "file", "KB 06 §7.406", "error", "Unclosed multiline mapping string value (`\"hua1\": \"\\n...` without closing quote before next key or `]));`)"),
    RuleSpec("basket-missing-check-trigger", "file", "KB 06 §7.407", "error", "Room calling undefined check_trigger() or inheriting ITEM with ::reset() (d/heimuya/basket.lpc)"),
    RuleSpec("unquoted-set-string", "file", "KB 06 §7.408", "error", "Missing opening quote or stray integer trailing quote in set(\"prop\", ...\")"),
    RuleSpec("undeclared-for-i-loop", "file", "KB 06 §7.409", "error", "Non-advancing `for (i = 0; obj->query(...); i++)` loop, undeclared `for (i = sizeof(ob)...)` loop var, or dead `(: goaway :)` pointer"),
    RuleSpec("include-dir-macro", "file", "KB 06 §7.410", "error", "C preprocessor #include __DIR__ / #include __DIR_ directive fails in FluffOS"),
    RuleSpec("top-level-create-family", "file", "KB 06 §7.411", "error", "create_family() statement placed outside function braces after create()"),
    RuleSpec("one-arg-set", "file", "KB 06 §7.414", "error", "1-argument set(\"k\") / set_temp(\"k\") (data=0) or missing-value set(\"k\",) against ES2 F_DBASE"),
    RuleSpec("unclosed-define-string", "file", "KB 04 §6.33", "error", "Single-line #define macro carrying an unclosed string literal"),
    RuleSpec("fullwidth-code-punct", "file", "KB 04 §6.34", "error", "Fullwidth punctuation or ideographic space used as LPC syntax/whitespace in code position"),
    RuleSpec("big5-backslash-quote", "file", "KB 03 §4.4", "error", "BIG5 0x5C leftover backslash escaping a closing string quote (`...\\\"` before `,`/`;`/`:`/`)`)"),
    RuleSpec("seccrypt-tail-corruption", "file", "KB 04 §6.35", "error", "<SecCrypt>/trailing U+FFFD+PUA binary tail corruption at EOF (truncated call/missing closing brace/trailing garbage)"),
    RuleSpec("unclosed-set-key", "file", "KB 04 §6.36", "error", "Missing closing quote on dbase key before comma in set/add/query/delete(\"key,expr)"),
    RuleSpec("unclosed-set-alias-quote", "file", "KB 04 §6.37", "error", "Unclosed string argument in set_alias(..., \"...); breaking quote parity"),
    RuleSpec("broken-order-color-quote", "file", "KB 04 §6.38", "error", "Skill colorizer `+(order[random(...)])+\"` / mid-move `NOR\"` breaking string quotes"),
    RuleSpec("pager-text-in-code", "file", "KB 06 §7.263", "error", "Interactive `more` pager prompt (`继续下一页` / `前一页)` / `未完继续`) pasted into LPC code position"),
    RuleSpec("unclosed-cmp-quote", "file", "KB 04 §6.39", "error", "Comparison `== \"...` or `!= \"...` missing closing `\"` before `)` or `;` on same line"),
    RuleSpec("unbalanced-pp-comment", "file", "KB 04 §6.40", "error", "Commented `//` line with unbalanced `(`/` )` inside `#ifdef`/`#else`/`#endif` block"),
    RuleSpec("newline-in-key-string", "file", "KB 06 §7.415", "error", "Dbase/skill/condition/property/mapping key string literal split across raw newline (`\\n`)"),
    RuleSpec("pua-action-unclosed-quote", "file", "KB 04 §6.41", "error", "Active action/mapping string literal truncated with UTF-8 PUA bytes and missing closing `\"` before `,`"),
    RuleSpec("missing-mapping-bracket", "file", "KB 04 §6.42", "error", "Mapping literal `(`\"k\" : v, ... ])` missing opening `[` after `(`"),
    RuleSpec("tilde-dollar-color", "file", "KB 04 §6.42", "error", "Unquoted BBSMUD/MUSH `~$HIG`-style color token in LPC code position (outside heredoc/strings)"),
    RuleSpec("unclosed-color-nor-quote", "file", "KB 04 §6.43", "error", "ANSI color macro string missing closing `\"` before `NOR`/`HI*`"),
    RuleSpec("unclosed-heredoc", "file", "KB 04 §6.44", "error", "Unclosed `@MARKER` heredoc lacking a column-0 `MARKER` terminator (`End of file in text block`)"),
    RuleSpec("unbalanced-if-ctrl", "file", "KB 04 §6.46", "error", "Single-line `if (...) return/continue/break;` missing closing `)` before control statement"),
    RuleSpec("malformed-query-args", "file", "KB 06 §7.416", "error", "Nitan7 `ob->query()`-converter malformed `query()`/`query_temp()` call (3+ args, hoisted `2 && obj`, or unquoted DB_STR splice)"),
    RuleSpec("missing-call-semicolon", "file", "KB 04 §6.48", "error", "Missing `;` between adjacent LPC statement calls (`f(...) g(...)`)"),
    RuleSpec("efun-name-typo", "file", "KB 04 §6.49", "error", "Misspelled FluffOS efun/predicate/daemon call (`arryp`, `objecpt`, `funtionp`, `destrcut`, `sizof`, `nnotify_fail`, `CHANNLE_D->`)"),
    RuleSpec("bare-c-varargs", "file", "KB 04 §6.50", "error", "C-style bare `...` varargs parameter in LPC function declaration (FluffOS requires `mixed *args...`)"),
    RuleSpec("shujian-unclosed-if-logind", "targeted", "KB 04 §6.50", "error", "Shujian `d/shaolin/npc/{guo,mai}.lpc` unbalanced `if (... {` or `/logind.lpc` orphan `confirm_password()` tail"),
    RuleSpec("nitan-pharmacy-broken", "targeted", "KB 04 §6.51", "error", "Nitan7 `pharmacyd.lpc`/`herb.lpc`/`10.lpc` missing `MEDICINE_DIR`/`HERB_OB`/`PHARMACY_D`, swapped `member_array(value, name)`, `s_name` redecl, `({ eng })`, or `inherit MEDICINE`"),
    RuleSpec("pasted-shell-prompt", "file", "KB 04 §6.52", "error", "Pasted MUD wizard `> c/cat/more file.c` prompt or bare `name.c inherit` header in LPC code"),
    RuleSpec("malformed-super-call", "file", "KB 04 §6.53", "error", "Superclass hook call `::init()`/`::die()`/`::create()` missing `;` or single-colon `: init();`"),
    RuleSpec("stray-foreach-semicolon", "file", "KB 04 §6.54", "error", "Stray trailing `;` on `foreach (...)` header terminating loop body and breaking loop variable scope"),
    RuleSpec("xo-special-quest-setreboot", "targeted", "KB 04 §6.54", "error", "XO `special_quest.lpc` `if` swallowed into `//` comment or `setreboot.lpc` calling undefined `adminp()`"),
    RuleSpec("stray-quote-before-newline", "file", "KB 04 §6.55", "error", "Stray/unescaped `\"` right before `\\n\"` breaking out of string literal (`Illegal character '\\\\' (0x5c)`)"),
    RuleSpec("qujing-gunfa-weapon-name", "targeted", "KB 04 §6.56", "error", "qujing-gunfa.lpc `int wn` / mangled `query_temp(\"weapon\", wn = me)` or unguarded `query_temp(\"weapon\")->query(\"name\")`"),
    RuleSpec("xyj-eof-tail-corruption", "targeted", "KB 04 §6.57", "error", "XYJ archive-corrupted EOF tails (`d/qujing/start/24/12.lpc`, `cuiping.lpc`, `nowords.lpc` ESC, `yunlougate.lpc`)"),
    RuleSpec("demogorgon-is-killing-object", "targeted", "KB 04 §6.58", "error", "demogorgon.lpc passing `this_player()` object to `is_killing(string id)` (`Bad type for argument 1`)"),
    RuleSpec("dodgebook-party-syntax", "targeted", "KB 04 §6.59", "error", "dodgebook.lpc wrapped bare comment words (`uired`/`is`/`ill`/`rn`) or party.lpc missing `,` after `\"qingyun-shou\": 100`"),
    RuleSpec("hy-migong-skill-warnings", "targeted", "KB 04 §6.60", "error", "lin06.lpc passing string path to `set_maze_boss(object)`, zhuihun-biao.lpc no-op `weapon; weapon =`, or meskill empty `if (i > j - 2)`"),
    RuleSpec("undefined-set-max-items", "targeted", "KB 04 §6.61", "error", "Uncommented `set_max_items(...)` call in home/bag/shopbox/tai/vase/hualan when the lib's `feature/move.lpc` lacks `set_max_items`"),
    RuleSpec("xkx-include-syntax-blockers", "targeted", "KB 04 §6.62", "error", "XKX `yaolu.lpc` stale `/d/quanzhou/obj/drug_list.h`, `gaolao1.lpc` stale `zhanglao.lpc`, `yuelao2.lpc` stray `]));`, or `pixie_superskill.lpc` unbraced `if`/`else`"),
    RuleSpec("heimuya-mishi-cctx-syntax", "targeted", "KB 04 §6.63", "error", "`d/heimuya/mishi.lpc` truncated `this_player();`/`this_pl;`/`oid buqun_rob` or `cctx` `shoumu1`/`haibing`/`mjjs` syntax blockers"),
    RuleSpec("qhlist-cike-chidi-syntax", "targeted", "KB 04 §6.64", "error", "`quest/qhlist600000.lpc` stray `r`, `quest/baobiao/cike.lpc` truncated EOF, `guxing-sword.lpc` missing quote before `+NOR+`, or `yaoguai4.lpc` stray quote/`1*0000`"),
    RuleSpec("sjsh-angle-include-headers", "targeted", "KB 04 §6.65", "error", "`d/huanggong/dachen2.lpc` `#include <reporting.h>` or `d/calvin/tianpeng/npc/hufa.lpc` `#include <soldier_skill.h>` missing from `/include/`"),
    RuleSpec("dtsl-daemon-weapon-blockers", "targeted", "KB 04 §6.66", "error", "DTSL `fingerd2.lpc` `wizardp(name)`, `cleard.lpc` bare `say`, `tulong-dao.lpc` undefined `use_flag = 16;`, or `zhuyu-yan.lpc` missing `<ansi.h>`"),
    RuleSpec("mhxy-bagua-include", "targeted", "KB 04 §6.67", "error", "`d/youxia/BAGUA/bagua{0..7}.lpc` stale `#include \"/d/bagua/bagua.h\"` instead of `\"/d/youxia/BAGUA/BAGUA.H\"`"),
    RuleSpec("xkx-rstbkup-xunbu-xuanci", "targeted", "KB 04 §6.68", "error", "XKX/Shenzhou `rstbkup.lpc` collapsed `#endif #define`, `cmds/std/xunbu.lpc` relative `npc_skills_attrib_setup.h`, or `d/shaolin/npc/xuanci.lpc` missing `/d/shaolin/npc/job.h`"),
    RuleSpec("sanjieshenhua-footprint-hufa-luoyang", "targeted", "KB 04 §6.69", "error", "`d/linghai/footprint.lpc` `set_name(\"short\"/\"long\")`, `d/wizz/calvin/tianpeng/npc/hufa.lpc` `<soldier_skill.h>`, `luoyang/{npc/fushang,zhulin2}.lpc` leading `a`, or `aohan-liujue.lpc` duplicate `query_action()`"),
    RuleSpec("shujian-shaolin-chan-include", "targeted", "KB 04 §6.70", "error", "`d/shaolin/npc/{jichan,kongchan,mingchan}.lpc` relative `#include \"chan.h\"` when `chan.h` lives in `/d/shaolin/obj/chan.h`"),
    RuleSpec("nitan-present-baixing-paren", "targeted", "KB 04 §6.71", "error", "Nitan `slough_{killed,killer}`/`x{killed,killer}` misplaced paren `present(query(\"baixing\", environment(this_object())))` instead of `present(query(\"baixing\"), environment(this_object()))`"),
    RuleSpec("nitan-checkskill-mixed-array", "targeted", "KB 04 §6.72", "error", "`cmds/*/{checkskill,chpfm}.lpc` declares `mixed *value;` then passes `value` to `replace_string(temp, \"$N\", value)`"),
    RuleSpec("nitan-paimaishi-corrupt-payback", "targeted", "KB 04 §6.73", "error", "`d/city/npc/paimaishi.lpc` corrupted `finish_paimai()` with stray `if (!who->restore())` tail from `pay_back()`"),
    RuleSpec("xyj-yulan-lj-blockers", "targeted", "KB 04 §6.74", "error", "`d/kaifeng/npc/yulan.lpc` stale `#include \"quest_wr.h\"`/`<reporting.h>` when `.lpc` siblings exist, or `d/dntg/yunlou/npc/lj.lpc` leading `i  //`"),
    RuleSpec("vrm-server-undefined-schedule-d", "targeted", "KB 04 §6.75", "error", "`adm/daemons/vrm_server.lpc` calls `SCHEDULE_D->set_event(...)` in a lib without `scheduled.lpc`"),
    RuleSpec("sje-uid-mafu-shenshu-blockers", "targeted", "KB 04 §6.76", "error", "`include/uid.h` orphan `#endif`, `d/huanghe/npc/mafu.lpc` missing `mafuyz.h`/`mafulz.h`, or `quest/shenshu/npc/name.lpc` missing `<ansi.h>`"),
    RuleSpec("pkuxkx-sjsz-special-weapon", "targeted", "KB 04 §6.77", "error", "`pkuxkx` `d/bwdh/sjsz/obj/obj/{unique,weapon}/*.lpc` stale `#include \"/clone/unique/special_weapon.h\"` instead of `\"/d/bwdh/sjsz/obj/obj/unique/special_weapon.h\"`"),
    RuleSpec("task1-npc-accept-hit-type", "targeted", "KB 04 §6.78", "error", "`d/city/task1/npc.h` declares `int accept_hit(string arg)` then calls `accept_hit(who)` with `object who`, or `xkx100` `fugu`/`tuwu`/`dami` blockers"),
    RuleSpec("calvin-rjl-diamond-header", "targeted", "KB 04 §6.79", "error", "`d/calvin/armor/rjl.lpc` diamond `inherit SHIELD; inherit NECK;` or missing `offensive_target()` header"),
    RuleSpec("weapon-feature-include-dotc", "targeted", "KB 04 §6.80", "error", "`std/weapon/_*.lpc` stale `#include \"<name>.c\"` after `.c`->`.lpc` rename when `<name>.lpc` exists"),
    RuleSpec("shenzhou-syntax-include-blockers", "targeted", "KB 04 §6.81", "error", "`shenzhou` `pantao.lpc` missing `;`, `bangjob200000.lpc` stray `]),`, `hetaichong.lpc` unclosed quote, or `haishui3.lpc`/`yaoshui.h` glued `#include`"),
    RuleSpec("shujian-buliao-change-state", "targeted", "KB 04 §6.82", "error", "`d/zhiye/obj/buliao.h` missing `change_state()` called by `buliao{1..4}-2.lpc` and `zhibuji.lpc`"),
    RuleSpec("changjinpeng-tanzhu-include", "targeted", "KB 04 §6.83", "error", "`d/mingjiao/npc/changjinpeng.lpc` stale `#include \"/kungfu/class/mingjiao/tanzhu.h\"` when `/d/mingjiao/npc/tanzhu.h` exists"),
    RuleSpec("huashan-doctor-unclosed-sprintf", "targeted", "KB 04 §6.84", "error", "`d/huashan/npc/doctor.lpc` unclosed `sprintf(\"...想自宫可惜办不到...\",` followed directly by `return 0;`"),
    RuleSpec("m-bian-duplicate-create", "targeted", "KB 04 §6.85", "error", "`d/npc/m_weapon/weapon/m_bian.lpc` duplicate `void create()` or unguarded `me = this_player(); w_name = me->query(\"weapon/name\");`"),
    RuleSpec("lingshe-set-color-wmkj-blockers", "targeted", "KB 04 §6.86", "error", "`d/xingxiu/npc/lingshe.lpc` undefined `set_color(\"$HIW$\")` / dangling `me,);`, or `wmkj` `tianyi.lpc` `unique::init()` / `xixi-unarmed.lpc` leading `c  //`"),
    RuleSpec("objmaker-for-zhaoshi-dup", "targeted", "KB 04 §6.87", "error", "`clone/misc/objmaker.lpc` truncated `for (i = 0; i if (member_array(...)` or player-skill duplicated `// ZHAOSHI : 0// THIS IS PLAYER'S OWN SKILL` header"),
    RuleSpec("fqyy-robber-gaochang-shopman", "targeted", "KB 04 §6.88", "error", "`d/npc/robber.lpc` `is_killing(this_player())` vs `is_killing(string)`, `d/gaochang/zoulang_1.lpc` `) ]);`, `d/pingan/pingan/npc/shopman2.lpc` stray `});`, or `d/gaochang/npc/3.lpc` missing `;`"),
    RuleSpec("hy-danuoyi-quest-unclosed-quote", "targeted", "KB 04 §6.89", "error", "`bingxue-xinfa/qiankun-danuoyi.lpc` `&& random(2) = 0 {`, or `quest/{menpaijob/dali,menpaijob/tiezhang,songhuo}/quest.lpc` / `lagjobold.lpc` unclosed Chinese quote"),
    RuleSpec("jianjun-count-wxddym-blockers", "targeted", "KB 04 §6.90", "error", "`d/city2/npc/jianjun.lpc` undeclared `count` shadowing sefun, or `wxddym` `tianshi`/`tangmen-throwing/san`/`killer`/`feizei14` compile blockers"),
    RuleSpec("spekilled-es2-query-arg", "targeted", "KB 04 §6.91", "error", "`kungfu/class/generate/spekilled.lpc` calls Nitan7 `query(\"combat_exp\", me)` in ES2-dbase lib where `query(string, int)` takes int"),
    RuleSpec("shenghuo-quan-mojibake-quote", "targeted", "KB 04 §6.92", "error", "`kungfu/skill/shenghuo-quan.lpc` GBK-mojibake unclosed `notify_fail(\"你的内力太弱，无法练仁セ鹑...);`"),
    RuleSpec("fy-purplerose-newtask-setup", "targeted", "KB 04 §6.93", "error", "Fengyun `d/fy/npc/obj/purplerose.lpc` stray `else {d` or `newtask/{hulu,shoupa,wavehammer}.lpc` nonexistent `setup()`"),
    RuleSpec("jhfy-chai-ring-haodatong", "targeted", "KB 04 §6.94", "error", "`d/obj/quest/chai*.lpc` duplicate `query_autoload()` with `task.h`, `clone/box/item/26.lpc` `inherit FINGER` under `<weapon.h>`, or `haodatong.lpc` orphan tail"),
    RuleSpec("competed-string-type-typo", "targeted", "KB 04 §6.95", "error", "`adm/daemons/competed.lpc` `static`->`string` typo (`string object/int/string/mapping`) instead of `nosave`"),
    RuleSpec("zhonghua2-questobj-init-item", "targeted", "KB 04 §6.96", "error", "`questobj/*.lpc` calls Fengyun `::init_{item,cloth,head,boots,neck}()` when ES2 `inherit/item/item.lpc` lacks `init_item()`"),
    RuleSpec("fy2-eventd-bamboo3-cola", "targeted", "KB 04 §6.97", "error", "`adm/daemons/eventd.lpc` unclosed `\"event;`, `d/canyon/bamboo/bamboo3.lpc` nested `void init()`, or `d/canyon/npc/obj/cola.lpc` missing `inherit ITEM;`"),
    RuleSpec("tianxia-banghui-d-blockers", "targeted", "KB 04 §6.98", "error", "`adm/daemons/banghui_d.lpc` `return notify_fail(...)` in `string` fn, undeclared `tmp` in `register_banghui_name()`, or undeclared `dir_pre`"),
    RuleSpec("xyj-xiwangmu-vcd3-blockers", "targeted", "KB 04 §6.99", "error", "`d/moon/npc/xiwangmu.lpc` duplicate `ask_pantao()` or `clone/misc/vcd3.lpc` stray duplicated `users());`"),
    RuleSpec("zhaoshi-premature-action-close", "targeted", "KB 04 §6.100", "error", "Player-created skill `mapping *action = ({ });` prematurely closed before `// ZHAOSHI :0` entries"),
    RuleSpec("tang-raw-telnet-utf8-literal", "targeted", "KB 04 §6.101", "error", "`clone/misc/tang.lpc` raw Telnet IAC octal bytes (`\\377...`) in UTF-8 string literal"),
    RuleSpec("dtsl-missing-wanted-h", "targeted", "KB 04 §6.102", "error", "`#include <wanted.h>` in active rooms/NPCs (`biaotou{,2}`, `quest11/{lcj/damen,tlbb/*}`, `hdg/shanbi`) when `include/wanted.h` is missing"),
    RuleSpec("nitan-lcj-stale-lchj-include", "targeted", "KB 04 §6.103", "error", "`quest*/lcj/*.lpc` stale `#include \"/d/suzhou/npc/lchj.h\"` when local `lchj.h` exists"),
    RuleSpec("hell-zero-diag-blockers", "targeted", "KB 04 §6.105", "error", "`yangrongwan.lpc` `set_amount(1)` under `ITEM`, `bowl.lpc` string 2nd arg to `set_name()`, or duplicate `query_autoload()` in `bear`/`lbook3`/`lbook4`"),
    RuleSpec("shujian3-diemenglou-liumai", "targeted", "KB 04 §6.107", "error", "`d/city/diemenglou{1,2}.lpc` merged `CYNNOR` macro or `beiming-shengong/liumai.lpc` missing `liumai_msg.h`"),
    RuleSpec("jym-pingyuan-copyskills-examine-a", "targeted", "KB 04 §6.108", "error", "`jym` `d/final/pingyuan.lpc` unclosed `item_desc`, `cmds/arch/copyskills.lpc` `playerp()`, `cmds/adm/examine.lpc` `efun::count()`, or `d/dali/npc/a.lpc` unbalanced `if`"),
    RuleSpec("mhxy-yueru-lingfan-abc", "targeted", "KB 04 §6.109", "error", "`mhxy`/`mhxyqd` `yueru.lpc` missing `)`, `lingfan-san.lpc` undefined `umbrella_parry_msg`, or `wudidong/npc/obj/abc.lpc` undeclared `qn` / `str * 3 / 2`"),
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
CROSSED_QUERY_PAT = re.compile(
    rb'\b(?:query|query_temp|set|set_temp|addn?|delete|delete_temp)\s*\("[^"\n]+",\s*[A-Za-z_]\w*\[[^()\[\]\n;"\']*\)\s*\]'
    rb'|\b(?:query|query_temp)\s*\("[^"\n]+",\s*(?:get_ship|get_table|player_id|random|mapp|stringp|intp|objectp|arrayp|pointerp|sizeof|strlen|keys|values|to_int|atoi)\s*\('
)
BAD_LOAD_OBJECT_PAT = re.compile(rb"\bload_object\s*\([^()\n;]*;|\bload_object\s*\([^;\n]+\)\r?\n\s*\)\r?\n\s*\{")
BAD_DELETE_TEMP_PAT = re.compile(rb'\bdelete_temp\s*\(\s*"[^"\n]+"\s*,\s*(?:0|1)\s*,\s*[A-Za-z_]')
BAD_EXIT_OBJ_PAT = re.compile(
    rb'\bif\s*\(\s*!\s*find_object\s*\(\s*dest\s*\)\s*\)\s*load_object\s*\(\s*dest\s*\)\s*;\s*\r?\n\s*if\s*\(\s*query\s*\(\s*"no_fight"\s*,\s*dest\s*\)\s*\)'
    rb'|\bquery(?:_temp)?\s*\(\s*"[^"\n]+"\s*,\s*exits\s*\['
)
MISSING_MAPPING_COMMA_PAT = re.compile(
    rb'"(?:dodge|parry|damage|force|attack|lvl)"\s*:\s*-?\d+[ \t]*\r?\n[ \t]*"(?:dodge|parry|damage|force|attack|lvl|action|skill_name|damage_type)"\s*:'
)
UNCLOSED_MAPPING_STR_PAT = re.compile(
    rb'(?m)^[ \t]*"[^"\n]{1,32}"[ \t]*:[ \t]*"[ \t]*\\?[ \t]*n[ \t]*\r?\n(?:(?!(?<!\\)").){1,1500}?\r?\n[ \t]*\]\s*\)\s*;'
)
BASKET_CHECK_TRIGGER_RE = re.compile(rb'\bcheck_trigger\s*\(\s*\)\s*;')
UNQUOTED_SET_STR_PAT = re.compile(
    rb'\bset\s*\(\s*"[^"\n]+"\s*,\s*(?:(?![A-Z_][A-Z0-9_]*\b)[^"\s\d({\[/\-+.\n][^";+()\[\]\n]*"|\d+")\s*\)'
)
MOFENG_LOOP_PAT = re.compile(rb'\bfor\s*\(\s*[A-Za-z_]\w*\s*=\s*0\s*;\s*this_object\s*\(\s*\)\s*->\s*query\s*\(')
DEAD_GOAWAY_PAT = re.compile(rb'\(\s*:\s*goaway\s*:\s*\)')
ONE_ARG_SET_PAT = re.compile(rb'\bset(?:_temp)?\s*\(\s*"[^"\n]+"\s*(,?)\s*\)\s*;')
ES1_SET_CLEAR_SLUGS = frozenset({"es1", "es1_win", "esI", "tmi2"})
BLANK_SET_TEMPLATES = frozenset({
    "/d/eastland/yogor/armor/example.lpc",
    "/d/eastland/yogor/weapon/example.lpc",
    "/d/city/capital/npc/stdnpc.lpc",
})
DEFINE_LINE_RE = re.compile(rb"^[ \t]*#[ \t]*define[ \t]+")


def _find_unclosed_define_string(b: bytes) -> int | None:
    """Return 1-based line number of first single-line #define with an unclosed string, else None."""
    mk = code_mask(b, heredoc=True)
    off = 0
    for lno, raw_line in enumerate(b.split(b"\n"), 1):
        line_len = len(raw_line)
        line = raw_line[:-1] if raw_line.endswith(b"\r") else raw_line
        if mk[off:off + 1] == b"\x01" and b'"' in line and DEFINE_LINE_RE.match(line):
            if not line.endswith(b"\\"):
                i = 0
                n = len(line)
                in_str = False
                in_chr = False
                while i < n:
                    ch = line[i]
                    if not in_str and not in_chr:
                        if ch == 47 and i + 1 < n and line[i + 1] == 47:  # //
                            break
                        if ch == 47 and i + 1 < n and line[i + 1] == 42:  # /*
                            j = line.find(b"*/", i + 2)
                            if j < 0:
                                break
                            i = j + 2
                            continue
                        if ch == 39:  # '
                            in_chr = True
                            i += 1
                            continue
                        if ch == 34:  # "
                            in_str = True
                            i += 1
                            continue
                    elif in_chr:
                        if ch == 92 and i + 1 < n:
                            i += 2
                            continue
                        if ch == 39:
                            in_chr = False
                    elif in_str:
                        if ch == 92 and i + 1 < n:
                            i += 2
                            continue
                        if ch == 34:
                            in_str = False
                    i += 1
                if in_str:
                    return lno
        off += line_len + 1
    return None


FW_CODE_RE = re.compile(rb'\xe3\x80\x80|\xef\xbc\x8c|\xef\xbc\x9b|\xef\xbc\x88|\xef\xbc\x89|\xef\xbc\x9a')
FW_CODE_LPC_RE = re.compile(
    rb'(?m)^[ \t]*(?:#[ \t]*(?:include|define|ifdef|ifndef|pragma)\b|inherit\b|(?:(?:private|public|protected|nosave|static|nomask|varargs)\s+)*(?:void|int|string|object|mapping|mixed|float|buffer)\s+[A-Za-z_*])'
)


def _find_fullwidth_code_punct(b: bytes) -> tuple[int, str] | None:
    """Return (1-based line, char) for first fullwidth punctuation/space in LPC code, else None."""
    if not FW_CODE_LPC_RE.search(b):
        return None
    mk = code_mask(b, heredoc=True)
    off = 0
    for lno, raw in enumerate(b.split(b"\n"), 1):
        line = raw[:-1] if raw.endswith(b"\r") else raw
        if FW_CODE_RE.search(line):
            code_seg = bytes(line[k] if mk[off + k] == 1 else 32 for k in range(len(line)))
            m = FW_CODE_RE.search(code_seg)
            if m:
                rem_code = bytes(line[k] for k in range(len(line)) if mk[off + k] == 1)
                if not any(ch >= 0x80 for ch in FW_CODE_RE.sub(b"", rem_code)):
                    if len(re.findall(rb'(?<!\\)"', line[:m.start()])) % 2 == 0:
                        return (lno, m.group(0).decode("utf-8"))
        off += len(raw) + 1
    return None


BIG5_BS_QUOTE_RE = re.compile(rb'[\x80-\xff]\\"[ \t]*[,;:\)\]\}]')
_BIG5_TMPL_LHS_RE = re.compile(rb'^\s*(?:file_global|item_buff|room|roomtext|str|mobu|list|msg|bstr|code|line|txt|arg|out)\s*\+?=')


def _find_big5_backslash_quote(b: bytes) -> int | None:
    """Return 1-based line number of first BIG5 0x5C stray backslash escaping a closing quote, else None."""
    mk = None
    for m in BIG5_BS_QUOTE_RE.finditer(b):
        ls = b.rfind(b"\n", 0, m.start()) + 1
        le = b.find(b"\n", m.end())
        if le < 0:
            le = len(b)
        line = b[ls:le].rstrip(b"\r")
        if b[ls:m.start()].lstrip().startswith(b"//"):
            continue
        if mk is None:
            mk = code_mask(b, heredoc=True)
        line_first_nonws = ls + len(line) - len(line.lstrip())
        if line_first_nonws < le and mk[m.start()] == 0 and mk[m.start() + 2] == 0:
            before = b[ls:m.start()]
            if b'\\"' not in before and len(re.findall(rb'"', before)) % 2 == 1:
                if _BIG5_TMPL_LHS_RE.search(line):
                    continue
                if (b"sprintf" in line or b"fprintf" in line or b"replace_string" in line or b"write_file" in line or b"query(" in line):
                    if re.search(rb'(?<!\\)"\s*(?:\)\s*)?;\s*$', line) and line.count(b'\\"') >= 2:
                        continue
                return b.count(b"\n", 0, m.start()) + 1
    return None


SECCRYPT_TAIL_PATTERNS = (
    # shuijingqiu.lpc truncated mid-call: locate_quest(this_player(), arg <U+FFFD/PUA>...
    re.compile(rb"locate_quest\s*\(\s*this_player\s*\(\s*\)\s*,\s*arg[^\)\r\n]*[\xef\xee]"),
    # beast1.lpc trailing U+FFFD/PUA garbage line at EOF after closing function brace
    re.compile(rb"(?:^|\n)[ \t]*\}\r?\n(?:\r?\n)*(?:[ \t]*(?:\xef\xbf\xbd|\xee[\x80-\xbf]{2}|\xef[\x80-\xa3][\x80-\xbf])[ \t]*)+\r?\n?\Z"),
    # sunguanshi.lpc <SecCrypt> control byte 0x16 + PUA bytes at EOF replacing closing ); return 1; }
    re.compile(rb'"[ \t]*\x16[^\r\n]*(?:\xee[\x80-\xbf]{2}|\xef[\x80-\xa3][\x80-\xbf])[^\r\n]*(?:\r?\n)*\Z'),
)
LPC_FUNC_SIG_RE = re.compile(rb"\b(?:void|int|mixed|string|object|mapping)\s+[A-Za-z_]\w*\s*\(")


def _find_seccrypt_tail(b: bytes) -> int | None:
    """Return 1-based line number of <SecCrypt> / trailing U+FFFD+PUA tail corruption, if any."""
    for idx, pat in enumerate(SECCRYPT_TAIL_PATTERNS):
        m = pat.search(b)
        if m is not None:
            if idx == 2 and LPC_FUNC_SIG_RE.search(b[: m.start()]) is None:
                continue
            pos = m.start()
            if idx == 1:
                # Anchor line number on the trailing U+FFFD/PUA line rather than `}`
                m_bad = re.search(rb"\xef\xbf\xbd|\xee[\x80-\xbf]{2}|\xef[\x80-\xa3][\x80-\xbf]", b[pos:])
                if m_bad is not None:
                    pos += m_bad.start()
            return b.count(b"\n", 0, pos) + 1
    return None


UNCLOSED_SET_KEY_RE = re.compile(
    rb'\b(?:set|set_temp|add|add_temp|query|query_temp|delete|delete_temp)\s*\(\s*"[A-Za-z0-9_/\-]+,[^"\r\n]+\)'
)


def _find_unclosed_set_key(b: bytes) -> int | None:
    """Return 1-based line number of set/add/query/delete(\"key,expr) missing its closing quote."""
    mask = None
    for m in UNCLOSED_SET_KEY_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


UNCLOSED_SET_ALIAS_RE = re.compile(
    rb'\bset_alias\s*\([^,\r\n]+,\s*"(?:[^"\r\n\\]|\\.)*\)\s*;'
)


def _find_unclosed_set_alias_quote(b: bytes) -> int | None:
    """Return 1-based line number of set_alias(cmd, \"...); missing closing string quote."""
    mask = None
    for m in UNCLOSED_SET_ALIAS_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


BROKEN_ORDER_STR_RE = re.compile(
    rb'[^\s"]\+\(order\[random\(\d+\)\]\)\+"[^"\r\n]*,(?=[ \t]*\r?$)', re.MULTILINE
)
BROKEN_MID_NOR_RE = re.compile(
    rb'(?:' + "「".encode("utf-8") + rb'|:\s*")[^\x00-\x7f]{1,9}NOR"[ \t]*[^\x00-\x7f]'
)


def _find_broken_order_color_quote(b: bytes) -> int | None:
    """Return 1-based line number of colorizer-broken +(order[...])+" or mid-move NOR" syntax."""
    mask = None
    for pat in (BROKEN_ORDER_STR_RE, BROKEN_MID_NOR_RE):
        for m in pat.finditer(b):
            if mask is None:
                mask = code_mask(b, heredoc=True)
            pos = m.end() - 1
            if pos < len(mask) and mask[pos]:
                return b.count(b"\n", 0, m.start()) + 1
    return None


PAGER_CODE_RE = re.compile(
    rb"\xe7\xbb\xa7\s*\xe7\xbb\xad\s*\xe4\xb8\x8b\s*\xe4\xb8\x80\s*\xe9\xa1\xb5"
    rb"|\xe5\x89\x8d\s*\xe4\xb8\x80\s*\xe9\xa1\xb5\s*\)"
    rb"|\xe6\x9c\xaa\s*\xe5\xae\x8c\s*\xe7\xbb\xa7\s*\xe7\xbb\xad"
)


def _find_pager_text_in_code(b: bytes) -> int | None:
    """Return 1-based line number of `more` pager status text pasted into LPC code."""
    mask = None
    for m in PAGER_CODE_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


UNCLOSED_CMP_QUOTE_RE = re.compile(
    rb'(?:==|!=)[ \t]*"[^"\r\n\\;)]+[);][ \t]*\r?$',
    re.MULTILINE,
)


def _find_unclosed_cmp_quote(b: bytes) -> int | None:
    """Return 1-based line number of `== \"...` / `!= \"...` missing closing quote."""
    mask = None
    for m in UNCLOSED_CMP_QUOTE_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


UNBALANCED_PP_CMT_RE = re.compile(
    rb"#(?:if|ifdef|ifndef|elif|else)[^\r\n]*\r?\n(?:[ \t]*//[^\r\n]*\r?\n)+[ \t]*#(?:else|elif|endif)"
)


def _find_unbalanced_pp_comment(b: bytes) -> int | None:
    """Return 1-based line number of unbalanced `(`/` )` commented line inside `#ifdef`/`#else`."""
    mask = None
    for m in UNBALANCED_PP_CMT_RE.finditer(b):
        seg = m.group(0)
        if seg.count(b"(") == seg.count(b")"):
            continue
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


NL_FN_KEY_RE = re.compile(
    rb"(?:query(?:_skill|_temp|_skill_mapped|_skill_prepared|_entire_dbase|_condition|_property)?|"
    rb"set(?:_temp|_skill|_property)?|"
    rb"add(?:n|_temp)?|"
    rb"delete(?:_temp|_skill)?|"
    rb"apply_condition|clear_condition|"
    rb"map_skill|prepare_skill|skill_mapped|exert_function|perform_action|"
    rb"present|load_object|find_object|new|inherit)"
    rb"\s*\(\s*\"[A-Za-z0-9_ /-]*\r?\n[A-Za-z0-9_/-]+\""
)
NL_MAP_KEY_RE = re.compile(
    rb"(?:^|[,({\[ \t])(?:\"[a-z_][a-z0-9_ /-]*\r?\n[a-z0-9_/-]+\"|\"\r?\n[a-z_][a-z0-9_/-]*\")\s*:",
    re.MULTILINE,
)


def _find_newline_in_key_string(b: bytes) -> tuple[int, str] | None:
    """Return (1-based line, snippet) of a key/mapping-key string split across a raw newline."""
    mask = None
    for pat, use_end in ((NL_FN_KEY_RE, False), (NL_MAP_KEY_RE, True)):
        if not pat.search(b):
            continue
        if mask is None:
            mask = code_mask(b, heredoc=True)
        for m in pat.finditer(b):
            idx = (m.end() - 1) if use_end else m.start()
            if idx < len(mask) and mask[idx]:
                ln = b.count(b"\n", 0, m.start()) + 1
                snip = m.group(0).replace(b"\r", b"").replace(b"\n", b"\\n").decode("utf-8", "replace")
                return ln, snip.strip()
    return None


PUA_ACTION_COMMA_RE = re.compile(
    rb'^[ \t]*"[^"\r\n]*\xee[\x80-\xbf]{2}[^"\r\n]*,[ \t]*\r?$',
    re.MULTILINE,
)


def _find_pua_action_unclosed_quote(b: bytes) -> int | None:
    """Return 1-based line number of an active PUA-truncated `\"...,` string missing closing quote."""
    mask = None
    for m in PUA_ACTION_COMMA_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() > 0 and m.start() - 1 < len(mask) and mask[m.start() - 1]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


MAP_OPEN_KEY_RE = re.compile(rb'\(\s*(?:"[^"\r\n()]+"|\d+)\s*:')
MAP_CLOSE_RE = re.compile(rb'\]\s*\)')
TILDE_DOLLAR_COLOR_RE = re.compile(
    rb'~\$(?:HI[RGBYMCW]|NOR|BLINK|B[A-Z]{2,3}|RED|GRN|YEL|BLU|MAG|CYN|WHT)'
)


def _find_missing_mapping_bracket(b: bytes) -> int | None:
    """Return 1-based line number of `( "k" : v, ... ])` missing `[` after `(`."""
    mask = None
    for m in MAP_OPEN_KEY_RE.finditer(b):
        win = b[m.end():m.end() + 2500]
        jm = MAP_CLOSE_RE.search(win)
        if not jm:
            continue
        seg = win[:jm.start()]
        if b";" in seg or b"{" in seg or b"}" in seg or b"([" in seg or b"({" in seg or b"[" in seg:
            continue
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()] and (m.end() + jm.end() - 1) < len(mask) and mask[m.end() + jm.end() - 1]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


def _find_tilde_dollar_color(b: bytes) -> int | None:
    """Return 1-based line number of unquoted `~$COLOR` markup in LPC code position."""
    mask = None
    for m in TILDE_DOLLAR_COLOR_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


COLOR_NOR_OPEN_RE = re.compile(
    rb'\b(?:HI[RGBYMCW]|RED|GRN|YEL|BLU|MAG|CYN|WHT|B(?:LACK|RED|GRN|YEL|BLU|MAG|CYN|WHT|LINK|OLD))\b[ \t]*"[^"\r\n\\]{1,120}(?:NOR|HI[RGBYMCW])\b[ \t]*(?:[;,)+:\]\r\n]|$)'
)


def _find_unclosed_color_nor_quote(b: bytes) -> int | None:
    """Return 1-based line number of `HI*\"...NOR` missing its closing quote."""
    mask = None
    for m in COLOR_NOR_OPEN_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() < len(mask) and mask[m.start()]:
            return b.count(b"\n", 0, m.start()) + 1
    return None


UNCLOSED_HEREDOC_RE = re.compile(rb"@@?([A-Za-z_][A-Za-z0-9_]*)[ \t]*(?://[^\r\n]*)?(?:\r?\n|$)")


def _find_unclosed_heredoc(b: bytes) -> tuple[int, str] | None:
    """Return `(1-based line, tag)` of `@MARKER` lacking a column-0 terminator line."""
    mask = None
    for m in UNCLOSED_HEREDOC_RE.finditer(b):
        if m.start() > 0 and b[m.start() - 1:m.start()] not in b" \t(=+,;:{\n\r":
            continue
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if m.start() >= len(mask) or not mask[m.start()]:
            continue
        tag = m.group(1)
        if not re.compile(rb"(?m)^" + re.escape(tag) + rb"(?![A-Za-z0-9_])").search(b, m.end()):
            return (b.count(b"\n", 0, m.start()) + 1, tag.decode("ascii", "replace"))
    return None


UNBAL_IF_CTRL_RE = re.compile(rb"^[ \t]*(?:else[ \t]+)?if\s*\([^\n]*?\b(?:return|continue|break)\b", re.M)
_IF_CTRL_KW_RE = re.compile(rb"\b(?:return|continue|break)\b")


def _find_unbalanced_if_ctrl(b: bytes) -> int | None:
    """Return 1-based line number of single-line `if (...) return/continue/break;` missing `)`."""
    mask = None
    for m in UNBAL_IF_CTRL_RE.finditer(b):
        if mask is None:
            mask = code_mask(b, heredoc=True)
        lstart = m.start()
        if lstart >= len(mask) or not mask[lstart]:
            continue
        lend = b.find(b"\n", lstart)
        if lend == -1:
            lend = len(b)
        line = b[lstart:lend]
        lp = line.find(b"(")
        km = _IF_CTRL_KW_RE.search(line[lp:])
        if not km:
            continue
        kpos = lp + km.start()
        if lstart + kpos >= len(mask) or not mask[lstart + kpos]:
            continue
        depth = 0
        ok = True
        for i in range(lp, kpos):
            if not mask[lstart + i]:
                continue
            if line[i] == 40:
                depth += 1
            elif line[i] == 41:
                depth -= 1
                if depth < 0:
                    ok = False
                    break
        if ok and depth > 0 and b"{" not in line[kpos:] and b";" in line[kpos:]:
            return b.count(b"\n", 0, lstart) + 1
    return None


_BARE_QUERY_CALL_RE = re.compile(rb"(?<![A-Za-z0-9_>])(query(?:_temp)?)\s*\(")
_QUERY_DECL_PREFIX_RE = re.compile(rb"\b(?:mixed|int|string|void|mapping|object|varargs|private|protected|public|nomask)\s+$")
_QUERY_BOOL_HOIST_RE = re.compile(rb"\b[0-9]+\s*(?:&&|\|\|)\s*[A-Za-z_]")


def _split_call_args(b: bytes, start: int) -> list[bytes] | None:
    depth = 1
    i = start
    args: list[bytes] = []
    cur = start
    n = min(len(b), start + 1000)
    in_str = False
    while i < n and depth > 0:
        ch = b[i]
        if in_str:
            if ch == 92:  # \
                i += 2
                continue
            if ch == 34:  # "
                in_str = False
        else:
            if ch == 34:
                in_str = True
            elif ch in (40, 91, 123):  # ([{
                depth += 1
            elif ch in (41, 93, 125):  # )]}
                depth -= 1
                if depth == 0:
                    args.append(b[cur:i].strip())
                    return args
            elif ch == 59 and depth == 1:  # ;
                return None
            elif ch == 44 and depth == 1:  # ,
                args.append(b[cur:i].strip())
                cur = i + 1
        i += 1
    return None


def _find_malformed_query_args(b: bytes) -> tuple[int, str] | None:
    """Return `(1-based line, reason)` for Nitan7 converter-corrupted `query`/`query_temp` calls."""
    idx = b.find(b'username=query(" id "')
    if idx != -1:
        return (b.count(b"\n", 0, idx) + 1, "unquoted `query(\" id \"` DB_STR splice inside SQL literal")
    mask = None
    for m in _BARE_QUERY_CALL_RE.finditer(b):
        pos = m.start()
        if pos >= 2 and b[pos - 2:pos] in (b"->", b"::"):
            continue
        if _QUERY_DECL_PREFIX_RE.search(b[max(0, pos - 40):pos]):
            continue
        args = _split_call_args(b, m.end())
        if not args:
            continue
        reason = None
        if len(args) >= 3:
            reason = f"3+-arg `{m.group(1).decode()}()` call drops trailing target object or fails compilation"
        elif len(args) == 2 and _QUERY_BOOL_HOIST_RE.search(args[1]):
            reason = f"boolean `&&`/`||` inside `{m.group(1).decode()}()` 2nd arg drops target object"
        if reason is None:
            continue
        if mask is None:
            mask = code_mask(b, heredoc=True)
        if pos < len(mask) and mask[pos]:
            return (b.count(b"\n", 0, pos) + 1, reason)
    return None


_CALL_SEMI_RHS = (
    rb"(?:add_money|add_action|apply_condition|carry_object|command|create_family|delete_temp|"
    rb"destruct|init_(?:axe|blade|dagger|fork|hammer|spear|staff|stick|sword|whip)|"
    rb"map_skill|message_vision|move|prepare_skill|reset_action|set|set_amount|"
    rb"set_heart_beat|set_name|set_skill|set_temp|set_weight|seteuid|setup|"
    rb"start_busy|tell_object|tell_room|unwield|wear|wield|write)"
)
MISSING_CALL_SEMI_RE = re.compile(rb"\)[ \t]+" + _CALL_SEMI_RHS + rb"\s*\(")
_CALL_SEMI_CTL = frozenset({
    b"if", b"while", b"for", b"switch", b"catch", b"return", b"foreach",
    b"sizeof", b"typeof", b"defined", b"stringp", b"intp", b"objectp",
    b"mapp", b"arrayp", b"undefinedp", b"floatp", b"functionp", b"bufferp", b"nullp",
})
_CALL_SEMI_IDENT_RE = re.compile(rb"\b([A-Za-z_][A-Za-z0-9_]*)$")


def _find_missing_call_semicolon(b: bytes) -> int | None:
    """Return 1-based line number of adjacent LPC statement calls missing `;`."""
    mask = code_mask(b, heredoc=True)
    cb = bytes(b[i] if (mask[i] or b[i] == 10) else 32 for i in range(len(b)))
    if not MISSING_CALL_SEMI_RE.search(cb):
        return None
    lines = cb.split(b"\n")
    for lno, raw in enumerate(lines, 1):
        if b")" not in raw:
            continue
        st = raw.lstrip()
        if st.startswith((b"#", b"if", b"else", b"while", b"for", b"switch", b"catch", b"return", b"foreach")):
            continue
        for m in MISSING_CALL_SEMI_RE.finditer(raw):
            seg_start = max(raw.rfind(b";", 0, m.start()) + 1, 0)
            seg = raw[seg_start:m.start() + 1]
            depth = 0
            open_idx = -1
            for k in range(len(seg) - 1, -1, -1):
                c = seg[k]
                if c == 41:  # ')'
                    depth += 1
                elif c == 40:  # '('
                    depth -= 1
                    if depth == 0:
                        open_idx = k
                        break
            if open_idx <= 0:
                if depth == 1 and seg.strip() == b")":
                    # Walk backward over preceding lines to ensure this ')' does not close an `if/while/for (...)`
                    d = 1
                    prev_ln = lno - 2
                    found_ctl = None
                    steps = 0
                    while prev_ln >= 0 and steps < 40 and d > 0:
                        pl = lines[prev_ln]
                        for k in range(len(pl) - 1, -1, -1):
                            if pl[k] == 41:
                                d += 1
                            elif pl[k] == 40:
                                d -= 1
                                if d == 0:
                                    cm = _CALL_SEMI_IDENT_RE.search(pl[:k].rstrip())
                                    found_ctl = cm.group(1) if cm else b""
                                    break
                        prev_ln -= 1
                        steps += 1
                    if found_ctl is not None and found_ctl not in _CALL_SEMI_CTL:
                        return lno
                continue
            prefix = seg[:open_idx].rstrip()
            cm = _CALL_SEMI_IDENT_RE.search(prefix)
            if not cm:
                continue
            if cm.group(1) in _CALL_SEMI_CTL:
                continue
            before = prefix[:cm.start()].rstrip()
            if before and before[-1] in b"(,=?:&|+*/!~[":
                continue
            return lno
    return None


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
EFUN_NAME_TYPO_RE = re.compile(
    rb"\b(?:arryp|objecpt|funtionp|strinp|destrcut|destuct|sizof|sizoef|enviroment|nnotify_fail|prevous_object|this_palyer|this_obect|call_othre|load_obejct|find_obejct|clone_obejct)\s*\("
    rb"|\bCHANNLE_D\s*->"
)


def _find_efun_name_typo(b: bytes) -> tuple[int, str] | None:
    mask = code_mask(b, heredoc=True)
    for m in EFUN_NAME_TYPO_RE.finditer(b):
        pos = m.start()
        if not mask[pos]:
            continue
        tok = m.group(0)
        if not tok.startswith(b"CHANNLE_D") and b[:pos].rstrip().endswith(b"->"):
            continue
        return b[:pos].count(b"\n") + 1, tok.decode("ascii", "replace").strip()
    return None


BARE_C_VARARGS_RE = re.compile(
    rb"(?m)^[ \t]*(?:(?:public|private|protected|nomask|varargs)[ \t]+)*"
    rb"(?:void|int|string|mixed|object|mapping|float|buffer)[ \t]+\*?[A-Za-z_][A-Za-z0-9_]*[ \t]*\([^;\r\n]*,[ \t]*\.\.\.[ \t]*\)"
)


def _find_bare_c_varargs(b: bytes) -> int | None:
    mask = code_mask(b, heredoc=True)
    for m in BARE_C_VARARGS_RE.finditer(b):
        if mask[m.start()]:
            return b[:m.start()].count(b"\n") + 1
    return None


PASTED_SHELL_PROMPT_RE = re.compile(
    rb"(?m)^[ \t]*(?:>[ \t]+(?:c|cat|more|head|tail|ed)[ \t]+[A-Za-z0-9_./-]+\.(?:c|lpc|h)\b|[A-Za-z0-9_-]+\.(?:c|lpc)[ \t]+inherit\b)"
)


def _find_pasted_shell_prompt(b: bytes) -> tuple[int, str] | None:
    mask = code_mask(b, heredoc=True)
    for m in PASTED_SHELL_PROMPT_RE.finditer(b):
        if mask[m.start()]:
            return b[:m.start()].count(b"\n") + 1, m.group(0).decode("ascii", "replace").strip()
    return None


MALFORMED_SUPER_CALL_RE = re.compile(
    rb"(?m)^[ \t]*(?:::(?:init|create|setup|reset|die|unconcious|heart_beat|remove|clean_up)[ \t]*\([ \t]*\)[ \t]*\r?$|:[ \t]*(?:init|create|setup|reset|die|unconcious)[ \t]*\([ \t]*\)[ \t]*;)"
)


def _find_malformed_super_call(b: bytes) -> tuple[int, str] | None:
    mask = code_mask(b, heredoc=True)
    for m in MALFORMED_SUPER_CALL_RE.finditer(b):
        if mask[m.start()]:
            return b[:m.start()].count(b"\n") + 1, m.group(0).decode("ascii", "replace").strip()
    return None


STRAY_FOREACH_SEMI_RE = re.compile(
    rb"(?m)^[ \t]*foreach[ \t]*\((?:[^()\r\n]|\([^()\r\n]*\))*\)[ \t]*;[ \t]*\r?$"
)


def _find_stray_foreach_semicolon(b: bytes) -> int | None:
    mask = code_mask(b, heredoc=True)
    for m in STRAY_FOREACH_SEMI_RE.finditer(b):
        if mask[m.start()]:
            return b[:m.start()].count(b"\n") + 1
    return None


STRAY_QUOTE_NL_RE = re.compile(rb'[^\x00-\x7f]"\\n"')


def _find_stray_quote_before_newline(b: bytes) -> int | None:
    mask = code_mask(b, heredoc=True)
    for m in STRAY_QUOTE_NL_RE.finditer(b):
        # Single stray `"` leaves `\` at m.start()+2 outside the string (mask==1);
        # paired unescaped inner quotes leave the CJK char at m.start() outside the string (mask==1);
        # comments (e.g. `// 被"\n"取代`) have mask==0 at both positions.
        if mask[m.start()] or mask[m.start() + 2]:
            return b[:m.start()].count(b"\n") + 1
    return None


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
        and m.get("hosting", "vendored") in ("vendored", "submodule-patch")
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
    rb'query_skil|quert_skill|queyr_skill|query_skill_perpare|query_conditon)\s*\('
)
CALL_TYPO_PAT = re.compile(
    rb'->\s*(recieve_damage|recieve_wound|recieve_curing|delte_temp|delet_temp|settemp|se_temp|stat_busy|'
    rb'delete_tem|strat_busy|start_bus|receive_damgae|recive_damage|receive_woud|start_perfrom|'
    rb'apply_conditon|clear_conditon|is_figting)\s*\('
)
INCLUDE_DIR_PAT = re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]+__DIR_+\s*"([^"\n]+)"')


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

    if want("crossed-bracket-query") and (b") ]" in b or b")]" in b or b"query" in b) and CROSSED_QUERY_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in CROSSED_QUERY_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("crossed-bracket-query", f"{path}:{ln}", "bracket-crossed query/set subscript corruption"))
                break

    if want("malformed-load-object") and b"load_object" in b and BAD_LOAD_OBJECT_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in BAD_LOAD_OBJECT_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("malformed-load-object", f"{path}:{ln}", "malformed load_object() missing ')' or stray '){'"))
                break

    if want("delete-temp-three-args") and b"delete_temp" in b and BAD_DELETE_TEMP_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in BAD_DELETE_TEMP_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("delete-temp-three-args", f"{path}:{ln}", "3-argument delete_temp(\"k\", 1, ob) call failing compilation"))
                break

    if want("exit-string-as-object") and (b"exits" in b or b"find_object" in b) and BAD_EXIT_OBJ_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in BAD_EXIT_OBJ_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("exit-string-as-object", f"{path}:{ln}", "exit room path string passed as object to find_object/sefun query"))
                break

    if want("missing-mapping-comma") and b'"dodge"' in b and MISSING_MAPPING_COMMA_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in MISSING_MAPPING_COMMA_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("missing-mapping-comma", f"{path}:{ln}", "missing comma between mapping entries"))
                break

    if want("unclosed-mapping-string") and b"]));" in b and UNCLOSED_MAPPING_STR_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in UNCLOSED_MAPPING_STR_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("unclosed-mapping-string", f"{path}:{ln}", "unclosed multiline mapping string literal before ]));"))
                break

    if want("basket-missing-check-trigger") and (b"check_trigger" in b or b"::reset" in b):
        mk = code_mask(b, heredoc=True)
        cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
        if (BASKET_CHECK_TRIGGER_RE.search(cb) and not re.search(rb'\b(?:void|int|mixed)\s+check_trigger\s*\(', cb)) or (
            re.search(rb'(?m)^[ \t]*inherit\s+ITEM\s*;', cb) and re.search(rb'::reset\s*\(', cb)
        ):
            hits.append(("basket-missing-check-trigger", path, "undefined check_trigger() or inherit ITEM with ::reset()"))

    if want("unquoted-set-string") and b"set(" in b and UNQUOTED_SET_STR_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in UNQUOTED_SET_STR_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("unquoted-set-string", f"{path}:{ln}", "set() value missing opening quote before closing quote"))
                break

    if want("undeclared-for-i-loop") and (b"goaway" in b or b"npc_number" in b or b"sizeof(ob)" in b):
        mk = code_mask(b, heredoc=True)
        cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
        if MOFENG_LOOP_PAT.search(cb):
            hits.append(("undeclared-for-i-loop", path, "non-advancing `for (i = 0; this_object()->query(...); i++)` infinite loop / undeclared locals"))
        elif DEAD_GOAWAY_PAT.search(cb) and not re.search(rb'\b(?:void|int|mixed|varargs)\s+goaway\s*\(', cb):
            hits.append(("undeclared-for-i-loop", path, "undefined `(: goaway :)` lfun pointer"))
        elif re.search(rb'\bfor\s*\(\s*i\s*=\s*sizeof\s*\(\s*ob\s*\)\s*-\s*1\s*;', cb) and not re.search(rb'\bint\b[^;(){}\n]*\bi\b', cb):
            hits.append(("undeclared-for-i-loop", path, "undeclared loop counter `i` in `for (i = sizeof(ob) - 1; ...)`"))

    if want("include-dir-macro") and b"__DIR_" in b and INCLUDE_DIR_PAT.search(b):
        mk = code_mask(b, heredoc=True)
        for m in INCLUDE_DIR_PAT.finditer(b):
            if mk[m.start()]:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("include-dir-macro", f"{path}:{ln}", f"`#include __DIR_` fails FluffOS preprocessor (`Cannot read #include file`) for `{m.group(1).decode('latin-1')}`"))
                break

    if want("top-level-create-family") and b"create_family" in b:
        mk = code_mask(b, heredoc=True)
        cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
        for m in re.finditer(rb'\bcreate_family\s*\([^;{}]*\)\s*;', cb):
            ls = cb.rfind(b"\n", 0, m.start()) + 1
            if re.match(rb'^[ \t]*(?:void|int|mixed|string|varargs|nomask|protected|public|private|nosave)\b', cb[ls:m.start()]):
                continue
            if cb[:m.start()].count(b"{") - cb[:m.start()].count(b"}") <= 0:
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("top-level-create-family", f"{path}:{ln}", "create_family() statement outside any function body"))
                break

    if want("one-arg-set") and (b"set(" in b or b"set_temp(" in b) and ONE_ARG_SET_PAT.search(b):
        if rel not in BLANK_SET_TEMPLATES:
            mk = code_mask(b, heredoc=True)
            for m in ONE_ARG_SET_PAT.finditer(b):
                if not mk[m.start()]:
                    continue
                has_comma = bool(m.group(1))
                if not has_comma and (slug in ES1_SET_CLEAR_SLUGS or not ctx["has_es2_dbase"]):
                    continue
                ln = b.count(b"\n", 0, m.start()) + 1
                hits.append(("one-arg-set", f"{path}:{ln}", f"`{m.group(0).decode('latin-1', 'replace').strip()}` omits value arg (sets 0 / compile error)"))
                break

    if want("unclosed-define-string") and b"#define" in b and b'"' in b:
        uln = _find_unclosed_define_string(b)
        if uln is not None:
            hits.append(("unclosed-define-string", f"{path}:{uln}", "#define macro carries an unclosed string literal"))

    if want("fullwidth-code-punct") and FW_CODE_RE.search(b):
        fw_hit = _find_fullwidth_code_punct(b)
        if fw_hit is not None:
            fln, fch = fw_hit
            hits.append(("fullwidth-code-punct", f"{path}:{fln}", f"fullwidth `{fch}` used in LPC code position"))

    if want("big5-backslash-quote") and b'\\"' in b and BIG5_BS_QUOTE_RE.search(b):
        bln = _find_big5_backslash_quote(b)
        if bln is not None:
            hits.append(("big5-backslash-quote", f"{path}:{bln}", "BIG5 0x5C leftover `\\\"` escapes closing string quote"))
    if want("seccrypt-tail-corruption") and (b"\xef" in b or b"\xee" in b or b"\x16" in b):
        sln = _find_seccrypt_tail(b)
        if sln is not None:
            hits.append(("seccrypt-tail-corruption", f"{path}:{sln}", "<SecCrypt>/trailing U+FFFD+PUA binary tail corruption breaks EOF syntax"))
    if want("unclosed-set-key") and UNCLOSED_SET_KEY_RE.search(b):
        kln = _find_unclosed_set_key(b)
        if kln is not None:
            hits.append(("unclosed-set-key", f"{path}:{kln}", "dbase key missing closing quote before comma"))
    if want("unclosed-set-alias-quote") and UNCLOSED_SET_ALIAS_RE.search(b):
        aln = _find_unclosed_set_alias_quote(b)
        if aln is not None:
            hits.append(("unclosed-set-alias-quote", f"{path}:{aln}", "set_alias() string argument missing closing quote"))
    if want("broken-order-color-quote") and (b"+(order[random(" in b or b'NOR"' in b):
        if BROKEN_ORDER_STR_RE.search(b) or BROKEN_MID_NOR_RE.search(b):
            oln = _find_broken_order_color_quote(b)
            if oln is not None:
                hits.append(("broken-order-color-quote", f"{path}:{oln}", "skill colorizer broke string quotes around `+(order[...])` or `NOR\"`"))
    if want("pager-text-in-code") and (b"\xe9\xa1\xb5" in b or b"\xe7\xbb\xad" in b) and PAGER_CODE_RE.search(b):
        pln = _find_pager_text_in_code(b)
        if pln is not None:
            hits.append(("pager-text-in-code", f"{path}:{pln}", "`more` pager prompt text pasted into LPC code position"))
    if want("unclosed-cmp-quote") and (b"==" in b or b"!=" in b) and UNCLOSED_CMP_QUOTE_RE.search(b):
        cln = _find_unclosed_cmp_quote(b)
        if cln is not None:
            hits.append(("unclosed-cmp-quote", f"{path}:{cln}", "Comparison string literal missing closing `\"` before `)` or `;`"))
    if want("unbalanced-pp-comment") and b"#endif" in b and UNBALANCED_PP_CMT_RE.search(b):
        upl = _find_unbalanced_pp_comment(b)
        if upl is not None:
            hits.append(("unbalanced-pp-comment", f"{path}:{upl}", "Commented `//` line leaves unbalanced `(`/` )` inside preprocessor branch"))
    if want("newline-in-key-string") and not is_wiz and b"\n" in b and (NL_FN_KEY_RE.search(b) or NL_MAP_KEY_RE.search(b)):
        nk = _find_newline_in_key_string(b)
        if nk is not None:
            hits.append(("newline-in-key-string", f"{path}:{nk[0]}", f"Key literal split across newline: `{nk[1]}`"))
    if want("pua-action-unclosed-quote") and b"\xee" in b and PUA_ACTION_COMMA_RE.search(b):
        pal = _find_pua_action_unclosed_quote(b)
        if pal is not None:
            hits.append(("pua-action-unclosed-quote", f"{path}:{pal}", "PUA-corrupted action string missing closing `\"` before `,`"))
    if want("missing-mapping-bracket") and not is_wiz and b"]" in b and MAP_OPEN_KEY_RE.search(b):
        mbl = _find_missing_mapping_bracket(b)
        if mbl is not None:
            hits.append(("missing-mapping-bracket", f"{path}:{mbl}", "Mapping literal `(\"k\": v ... ])` missing opening `[` after `(`"))
    if want("tilde-dollar-color") and b"~$" in b and TILDE_DOLLAR_COLOR_RE.search(b):
        tdl = _find_tilde_dollar_color(b)
        if tdl is not None:
            hits.append(("tilde-dollar-color", f"{path}:{tdl}", "Unquoted `~$COLOR` color markup in LPC code position"))
    if want("unclosed-color-nor-quote") and not is_wiz and (b"NOR" in b or b"HI" in b) and COLOR_NOR_OPEN_RE.search(b):
        cnl = _find_unclosed_color_nor_quote(b)
        if cnl is not None:
            hits.append(("unclosed-color-nor-quote", f"{path}:{cnl}", "ANSI color string missing closing `\"` before `NOR`/`HI*`"))
    if (
        want("unclosed-heredoc")
        and not is_wiz
        and "/doc/" not in f"/{path}/"
        and not path.endswith("/cmds/usr/whotest.lpc")
        and b"@" in b
        and UNCLOSED_HEREDOC_RE.search(b)
    ):
        uh = _find_unclosed_heredoc(b)
        if uh is not None:
            hits.append(("unclosed-heredoc", f"{path}:{uh[0]}", f"Unclosed heredoc `@{uh[1]}` missing column-0 terminator (`End of file in text block`)"))
    if want("unbalanced-if-ctrl") and not is_wiz and b"if" in b and UNBAL_IF_CTRL_RE.search(b):
        ifln = _find_unbalanced_if_ctrl(b)
        if ifln is not None:
            hits.append(("unbalanced-if-ctrl", f"{path}:{ifln}", "Single-line `if (...) return/continue/break;` missing closing `)` before statement"))
    if want("malformed-query-args") and not is_wiz and slug not in ("unitopia", "silberland", "tamedhon") and (b"query(" in b or b"query (" in b or b"query_temp(" in b or b"query_temp (" in b):
        qhit = _find_malformed_query_args(b)
        if qhit is not None:
            hits.append(("malformed-query-args", f"{path}:{qhit[0]}", qhit[1]))
    if (
        want("missing-call-semicolon")
        and not rel.startswith("/sjsh/u/")
        and b")" in b
        and b"(" in b
        and not (slug == "mohuanshiji" and rel in ("/d/moon/obj/dan_xueshan.lpc", "/obj/prize/xueshan.lpc"))
        and MISSING_CALL_SEMI_RE.search(b)
    ):
        mcs_ln = _find_missing_call_semicolon(b)
        if mcs_ln is not None:
            hits.append(("missing-call-semicolon", f"{path}:{mcs_ln}", "Adjacent LPC statement calls missing `;` between `)` and next call"))
    if (
        want("efun-name-typo")
        and not is_wiz
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and EFUN_NAME_TYPO_RE.search(b)
    ):
        et = _find_efun_name_typo(b)
        if et is not None:
            hits.append(("efun-name-typo", f"{path}:{et[0]}", f"Misspelled FluffOS efun/daemon identifier `{et[1]}`"))
    if (
        want("bare-c-varargs")
        and not is_wiz
        and "/bin/" not in rel
        and "/doc/" not in rel
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and b"..." in b
        and BARE_C_VARARGS_RE.search(b)
    ):
        bcv = _find_bare_c_varargs(b)
        if bcv is not None:
            hits.append(("bare-c-varargs", f"{path}:{bcv}", "C-style bare `...` varargs parameter (FluffOS requires `mixed *args...`)"))
    if (
        want("pasted-shell-prompt")
        and not is_wiz
        and "/doc/" not in rel
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and (b">" in b or b"inherit" in b)
        and PASTED_SHELL_PROMPT_RE.search(b)
    ):
        psp = _find_pasted_shell_prompt(b)
        if psp is not None:
            hits.append(("pasted-shell-prompt", f"{path}:{psp[0]}", f"Pasted wizard shell prompt or bare filename prefix `{psp[1]}`"))
    if (
        want("malformed-super-call")
        and not is_wiz
        and "/doc/" not in rel
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and b":" in b
        and MALFORMED_SUPER_CALL_RE.search(b)
    ):
        msc = _find_malformed_super_call(b)
        if msc is not None:
            hits.append(("malformed-super-call", f"{path}:{msc[0]}", f"Malformed superclass hook call `{msc[1]}`"))
    if (
        want("stray-foreach-semicolon")
        and not is_wiz
        and "/doc/" not in rel
        and not rel.endswith("/bad_foreach.lpc")
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and b"foreach" in b
        and STRAY_FOREACH_SEMI_RE.search(b)
    ):
        sfs = _find_stray_foreach_semicolon(b)
        if sfs is not None:
            hits.append(("stray-foreach-semicolon", f"{path}:{sfs}", "Stray `;` after `foreach (...)` terminates the loop header and breaks loop-variable scope"))
    if (
        want("stray-quote-before-newline")
        and not is_wiz
        and "/doc/" not in rel
        and slug not in sc.LDMUD
        and slug not in ("unitopia", "silberland", "tamedhon")
        and slug not in sc.GENERATED
        and b'"\\n"' in b
        and STRAY_QUOTE_NL_RE.search(b)
    ):
        sqn = _find_stray_quote_before_newline(b)
        if sqn is not None:
            hits.append(("stray-quote-before-newline", f"{path}:{sqn}", "Stray/unescaped `\"` before `\\n\"` closes string early (`Illegal character '\\\\' (0x5c)`)"))

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
        k: [] for k in ("more", "toptend", "logind", "wabaod", "post", "menu", "books", "blockade", "command", "rankd", "ping", "warcraft", "mrdizi", "say", "cmdco", "sanshen", "skill_co", "rtcfg", "ver_cfg", "band", "embed_cand", "team", "animal2", "btsnake", "miscdir_cand", "semote", "rpadm", "fingerd", "guomai", "pharmacy", "xo_qboot", "qujing", "xyj_eof", "demogorgon", "dodge_party", "hy_migong_skill", "set_max_items", "xkx_blockers", "mishi_cctx", "qhlist_chidi", "sjsh_inc", "dtsl_blk", "mhxy_bagua", "xkx_rx", "sjsh_fhl", "sj_chan", "nt_baixing", "nt_chkskill", "nt_paimai", "xyj_yulan", "vrm_sched", "sje_blk", "pku_sw", "task1_hit", "rjl_blk", "weapon_feat", "sz_blk", "buliao_h", "cjp_tanzhu", "hs_doc", "m_bian", "ls_wmkj", "objmaker_zh", "fqyy_blk", "hy_dq", "jj_wx", "spekilled", "shquan", "fy_nt", "jhfy_crh", "competed", "qobj_ii", "fy2_ebc", "tx_bh", "xyj_xv", "zhao_cls", "tang_iac", "biaotou_w", "lcj_inc", "hell_zd", "sj3_dl", "jym_blk", "mhxy_yla")
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
        if rel in (
            "/kungfu/skill/beidou-zhenfa.lpc",
            "/kungfu/skill/shigu-bifa/kuangcao.lpc",
            "/daemon/class/lingjie/lingfan-san/lieshi.lpc",
            "/kungfu/skill/songyang-shou/junji.lpc",
            "/kungfu/skill/banruo-zhang/yipai.lpc",
            "/kungfu/skill/guang-jian/guangmang.lpc",
        ):
            targeted_bins["skill_co"].append(item)
        if bn == "runtime_config.h":
            targeted_bins["rtcfg"].append(item)
        if any(k in bn for k in ("versiond", "getconfig", "server", "config")):
            targeted_bins["ver_cfg"].append(item)
        if "band" in bn or "security" in bn or "logind" in bn:
            targeted_bins["band"].append(item)
        if not has_embed[slug] and "/weapon/" in rel:
            targeted_bins["embed_cand"].append(item)
        if rel == "/feature/team.lpc":
            targeted_bins["team"].append(item)
        if rel == "/d/wanshou/npc/animal2.lpc":
            targeted_bins["animal2"].append(item)
        if rel == "/d/baituo/npc/bt_snake.lpc":
            targeted_bins["btsnake"].append(item)
        if rel in ("/adm/daemons/paiming_d.lpc", "/d/kongdong/fengkou.lpc"):
            targeted_bins["miscdir_cand"].append(item)
        if rel == "/cmds/std/semote.lpc":
            targeted_bins["semote"].append(item)
        if rel in ("/cmds/adm/rp.lpc", "/cmds/adm/rpp.lpc"):
            targeted_bins["rpadm"].append(item)
        if rel == "/adm/daemons/fingerd.lpc":
            targeted_bins["fingerd"].append(item)
        if rel in ("/d/shaolin/npc/guo.lpc", "/d/shaolin/npc/mai.lpc"):
            targeted_bins["guomai"].append(item)
        if rel in ("/adm/daemons/pharmacyd.lpc", "/clone/pharmacy/herb/herb.lpc", "/clone/pharmacy/medicine/10.lpc"):
            targeted_bins["pharmacy"].append(item)
        if rel in ("/system/std/char/special_quest.lpc", "/cmds/admin/setreboot.lpc"):
            targeted_bins["xo_qboot"].append(item)
        if rel == "/kungfu/skill/qujing-gunfa.lpc":
            targeted_bins["qujing"].append(item)
        if rel in ("/d/qujing/start/24/12.lpc", "/d/meishan/cuiping.lpc", "/d/ourhome/obj/nowords.lpc", "/d/sky/yunlougate.lpc"):
            targeted_bins["xyj_eof"].append(item)
        if rel in ("/clone/demogorgon.lpc", "/clone/npc/demogorgon.lpc"):
            targeted_bins["demogorgon"].append(item)
        if rel in ("/d/yanziwu/obj/dodgebook.lpc", "/quest/shenshu/npc/party.lpc"):
            targeted_bins["dodge_party"].append(item)
        if rel in (
            "/p/migong/lin06.lpc",
            "/kungfu/skill/zhuihun-biao.lpc",
            "/daemon/skill/zhuihun-biao.lpc",
            "/kfedit/skill/meskill/dan.lpc",
            "/kfedit/skill/meskill/hun.lpc",
            "/kfedit/skill/meskill/lian.lpc",
            "/kungfu/skill/meskill/dan.lpc",
            "/kungfu/skill/meskill/hun.lpc",
            "/kungfu/skill/meskill/lian.lpc",
        ):
            targeted_bins["hy_migong_skill"].append(item)
        if rel in (
            "/obj/home.lpc",
            "/clone/guan/home.lpc",
            "/d/taohuacun/obj/home.lpc",
            "/clone/home/home.lpc",
            "/d/city/obj/bag.lpc",
            "/d/city/obj/shopbox.lpc",
            "/d/city/obj/misc/hualan.lpc",
            "/d/city/obj/misc/vase.lpc",
            "/inherit/room/shopbox.lpc",
            "/clone/newitem/baoshi/tai.lpc",
            "/clone/newitem/dazao/tai.lpc",
        ):
            targeted_bins["set_max_items"].append(item)
        if rel in (
            "/d/quanzhou/yaopu/obj/yaolu.lpc",
            "/d/xiakedao/npc/gaolao1.lpc",
            "/d/city/yuelao2.lpc",
            "/d/qilian/npc/pixie_superskill.lpc",
        ):
            targeted_bins["xkx_blockers"].append(item)
        if rel in (
            "/d/heimuya/mishi.lpc",
            "/d/taohua/npc/shoumu1.lpc",
            "/d/shenlong/npc/haibing.lpc",
            "/d/mj/obj/mjjs.lpc",
        ):
            targeted_bins["mishi_cctx"].append(item)
        if rel in (
            "/quest/qhlist600000.lpc",
            "/quest/baobiao/cike.lpc",
            "/kungfu/skill/guxing-sword.lpc",
            "/d/shushan/zhenyaota/npc/yaoguai4.lpc",
        ):
            targeted_bins["qhlist_chidi"].append(item)
        if rel in ("/d/huanggong/dachen2.lpc", "/d/calvin/tianpeng/npc/hufa.lpc"):
            targeted_bins["sjsh_inc"].append(item)
        if rel in (
            "/adm/daemons/fingerd2.lpc",
            "/adm/daemons/cleard.lpc",
            "/clone/weapon/tulong-dao.lpc",
            "/d/clone/room/lingwu/yingui/zhuyu-yan.lpc",
        ):
            targeted_bins["dtsl_blk"].append(item)
        if rel.startswith("/d/youxia/BAGUA/bagua") and rel.endswith(".lpc"):
            targeted_bins["mhxy_bagua"].append(item)
        if rel in (
            "/cmds/wiz/rstbkup.lpc",
            "/cmds/adm/rstbkup.lpc",
            "/cmds/std/xunbu.lpc",
            "/d/shaolin/npc/xuanci.lpc",
        ):
            targeted_bins["xkx_rx"].append(item)
        if rel in (
            "/d/linghai/footprint.lpc",
            "/d/wizz/calvin/tianpeng/npc/hufa.lpc",
            "/d/luoyang/npc/fushang.lpc",
            "/d/luoyang/zhulin2.lpc",
            "/daemon/skill/aohan-liujue.lpc",
        ):
            targeted_bins["sjsh_fhl"].append(item)
        if rel in (
            "/d/shaolin/npc/jichan.lpc",
            "/d/shaolin/npc/kongchan.lpc",
            "/d/shaolin/npc/mingchan.lpc",
        ):
            targeted_bins["sj_chan"].append(item)
        if rel.endswith(("/slough_killed.lpc", "/slough_killer.lpc", "/xkilled.lpc", "/xkiller.lpc")):
            targeted_bins["nt_baixing"].append(item)
        if rel.startswith("/cmds/") and bn in ("checkskill.lpc", "chpfm.lpc"):
            targeted_bins["nt_chkskill"].append(item)
        if rel == "/adm/daemons/competed.lpc":
            targeted_bins["competed"].append(item)
        if rel.startswith("/questobj/") and rel.endswith(".lpc"):
            targeted_bins["qobj_ii"].append(item)
        if rel in ("/adm/daemons/eventd.lpc", "/d/canyon/bamboo/bamboo3.lpc", "/d/canyon/npc/obj/cola.lpc"):
            targeted_bins["fy2_ebc"].append(item)
        if rel == "/adm/daemons/banghui_d.lpc":
            targeted_bins["tx_bh"].append(item)
        if rel in ("/d/moon/npc/xiwangmu.lpc", "/clone/misc/vcd3.lpc"):
            targeted_bins["xyj_xv"].append(item)
        if rel == "/kungfu/skill/dragonfly-sword.lpc":
            targeted_bins["zhao_cls"].append(item)
        if rel == "/clone/misc/tang.lpc":
            targeted_bins["tang_iac"].append(item)
        if rel in ("/d/zhiye/npc/biaotou.lpc", "/d/zhiye/npc/biaotou2.lpc", "/quest11/lcj/damen.lpc", "/quest11/tlbb/guangchang.lpc", "/quest11/tlbb/silk3.lpc", "/d/mingjiao/hdg/shanbi.lpc"):
            targeted_bins["biaotou_w"].append(item)
        if ("/lcj/" in rel) and rel.endswith(".lpc"):
            targeted_bins["lcj_inc"].append(item)
        if rel in ("/clone/gift/yangrongwan.lpc", "/d/baituo/npc/obj/bowl.lpc", "/clone/special/bear.lpc", "/d/city/npc/obj/lbook3.lpc", "/d/xiaoyao/npc/obj/lbook4.lpc", "/d/xiaoyao/obj/lbook4.lpc"):
            targeted_bins["hell_zd"].append(item)
        if rel in ("/d/city/diemenglou1.lpc", "/d/city/diemenglou2.lpc", "/kungfu/skill/beiming-shengong/liumai.lpc"):
            targeted_bins["sj3_dl"].append(item)
        if rel in ("/d/final/pingyuan.lpc", "/cmds/arch/copyskills.lpc", "/cmds/adm/examine.lpc", "/d/dali/npc/a.lpc"):
            targeted_bins["jym_blk"].append(item)
        if rel in ("/d/shushan/npc/yueru.lpc", "/daemon/skill_wiz/umbrella/lingfan-san.lpc", "/d/qujing/wudidong/npc/obj/abc.lpc"):
            targeted_bins["mhxy_yla"].append(item)
        if rel == "/d/city/npc/paimaishi.lpc":
            targeted_bins["nt_paimai"].append(item)
        if rel in ("/d/kaifeng/npc/yulan.lpc", "/d/dntg/yunlou/npc/lj.lpc"):
            targeted_bins["xyj_yulan"].append(item)
        if rel == "/adm/daemons/vrm_server.lpc":
            targeted_bins["vrm_sched"].append(item)
        if rel in ("/include/uid.h", "/d/huanghe/npc/mafu.lpc", "/quest/shenshu/npc/name.lpc"):
            targeted_bins["sje_blk"].append(item)
        if rel.startswith(("/d/bwdh/sjsz/obj/obj/unique/", "/d/bwdh/sjsz/obj/obj/weapon/")) and rel.endswith(".lpc") and not rel.endswith("/yuxiao.lpc"):
            targeted_bins["pku_sw"].append(item)
        if rel in (
            "/d/city/task1/npc.h",
            "/kungfu/skill/jinshe-zhang/fugu.lpc",
            "/kungfu/skill/jinshe-zhui/tuwu.lpc",
            "/clone/food/dami.lpc",
        ):
            targeted_bins["task1_hit"].append(item)
        if rel == "/d/calvin/armor/rjl.lpc":
            targeted_bins["rjl_blk"].append(item)
        if rel.startswith("/std/weapon/_") and rel.endswith(".lpc"):
            targeted_bins["weapon_feat"].append(item)
        if rel == "/d/zhiye/obj/buliao.h":
            targeted_bins["buliao_h"].append(item)
        if rel == "/d/mingjiao/npc/changjinpeng.lpc":
            targeted_bins["cjp_tanzhu"].append(item)
        if rel == "/d/huashan/npc/doctor.lpc":
            targeted_bins["hs_doc"].append(item)
        if rel == "/d/npc/m_weapon/weapon/m_bian.lpc":
            targeted_bins["m_bian"].append(item)
        if rel in ("/d/xingxiu/npc/lingshe.lpc", "/d/objj/cloth/tianyi.lpc", "/kungfu/skill/xixi-unarmed.lpc"):
            targeted_bins["ls_wmkj"].append(item)
        if rel in (
            "/clone/misc/objmaker.lpc",
            "/kungfu/skill/club-sword.lpc",
            "/kungfu/skill/dabei-unarmed.lpc",
            "/kungfu/skill/wulainizou-unarmed.lpc",
            "/kungfu/skill/wuming-sword.lpc",
            "/kungfu/skill/wushuang-sword.lpc",
        ):
            targeted_bins["objmaker_zh"].append(item)
        if rel in (
            "/d/npc/robber.lpc",
            "/d/gaochang/zoulang_1.lpc",
            "/d/pingan/pingan/npc/shopman2.lpc",
            "/d/gaochang/npc/3.lpc",
        ):
            targeted_bins["fqyy_blk"].append(item)
        if rel in (
            "/kungfu/skill/bingxue-xinfa/qiankun-danuoyi.lpc",
            "/daemon/skill/bingxue-xinfa/qiankun-danuoyi.lpc",
            "/quest/menpaijob/dali/quest.lpc",
            "/quest/menpaijob/tiezhang/quest.lpc",
            "/quest/songhuo/quest.lpc",
            "/quest/newbie/qiandao/lagjobold.lpc",
        ):
            targeted_bins["hy_dq"].append(item)
        if rel in (
            "/d/city2/npc/jianjun.lpc",
            "/d/city/npc/tianshi.lpc",
            "/kungfu/skill/tangmen-throwing/san.lpc",
            "/clone/npc/killer.lpc",
            "/npc/feizei14.lpc",
        ):
            targeted_bins["jj_wx"].append(item)
        if rel == "/kungfu/class/generate/spekilled.lpc":
            targeted_bins["spekilled"].append(item)
        if rel == "/kungfu/skill/shenghuo-quan.lpc":
            targeted_bins["shquan"].append(item)
        if rel in ("/d/fy/npc/obj/purplerose.lpc", "/newtask/hulu.lpc", "/newtask/shoupa.lpc", "/newtask/wavehammer.lpc"):
            targeted_bins["fy_nt"].append(item)
        if rel in (
            "/d/obj/quest/chai.lpc",
            "/d/obj/quest/chai1.lpc",
            "/d/obj/quest/chai3.lpc",
            "/clone/box/item/26.lpc",
            "/d/quanzhen_old/npc/haodatong.lpc",
        ):
            targeted_bins["jhfy_crh"].append(item)
        if rel in (
            "/clone/gift/pantao.lpc",
            "/d/huanghe/bangjob/bangjob200000.lpc",
            "/kungfu/class/kunlun/hetaichong.lpc",
            "/d/shaolin/haishui3.lpc",
            "/d/shaolin/shaolin/haishui3.lpc",
            "/d/shaolin/npc/yaoshui.h",
        ):
            targeted_bins["sz_blk"].append(item)

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

    if col.wants("missing-team-lord"):
        lord_callers = (
            "inherit/char/trainee.lpc",
            "d/wanshou/npc/animal2.lpc",
            "d/wanshou/shulin.lpc",
            "clone/animal/lion.lpc",
            "clone/animal/laohu.lpc",
            "clone/animal/tuying.lpc",
            "d/baituo/npc/tuying.lpc",
            "d/baituo/npc/bt_snake.lpc",
            "d/baituo/obj/zhulou.lpc",
            "d/xueshan/npc/tuying.lpc",
            "cmds/std/train.lpc",
            "adm/daemons/fairyland_quest/temp/get.lpc",
            "adm/daemons/huanjing2003/temp/get.lpc",
        )
        for slug, p, _ in targeted_bins["team"]:
            if slug == "wllz3":
                continue
            b = open(f"{REPO}/{p}", "rb").read()
            has_set = bool(re.search(rb'\b(?:void|int|object|mixed)\s+set_lord\s*\(', b))
            has_qry = bool(re.search(rb'\b(?:void|int|object|mixed)\s+query_lord\s*\(', b))
            if not (has_set and has_qry):
                w = f"{REPO}/libs/{slug}/work"
                if any(
                    os.path.isfile(f"{w}/{c}") and (b"query_lord" in open(f"{w}/{c}", "rb").read() or b"set_lord" in open(f"{w}/{c}", "rb").read())
                    for c in lord_callers
                ):
                    col.add("missing-team-lord", p, "feature/team.lpc omits set_lord()/query_lord() while trainee/animal callers use it")
        for _, p, _ in targeted_bins["animal2"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"pow(" in b and re.search(rb'\bmax\s*=\s*pow\s*\(', b):
                col.add("missing-team-lord", p, "animal2.lpc assigns float pow() result to int `max` without to_int()")
        for _, p, _ in targeted_bins["btsnake"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'(?m)^void query_lord\s*\(\s*\)\s*;', b):
                col.add("missing-team-lord", p, "bt_snake.lpc has bogus void query_lord() forward declaration shadowing F_TEAM")

    if col.wants("undefined-misc-dir"):
        has_misc = {
            s: (
                os.path.isfile(f"{REPO}/libs/{s}/work/include/globals.h")
                and b"MISC_DIR" in open(f"{REPO}/libs/{s}/work/include/globals.h", "rb").read()
            )
            for s in slugs
        }
        for slug, p, rel in targeted_bins["miscdir_cand"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"MISC_DIR" in b and not has_misc[slug] and not re.search(rb'(?m)^[ \t]*#[ \t]*define[ \t]+MISC_DIR\b', b):
                col.add("undefined-misc-dir", p, f"{rel} uses undefined MISC_DIR macro (missing #define MISC_DIR)")
            elif rel == "/adm/daemons/paiming_d.lpc":
                sefun_p = f"{REPO}/libs/{slug}/work/adm/kernel/simul_efun.lpc"
                if b"clr_ansi(" in b and os.path.isfile(sefun_p) and b"clr_ansi" not in open(sefun_p, "rb").read():
                    col.add("undefined-misc-dir", p, "paiming_d.lpc calls undefined clr_ansi() instead of remove_ansi()")
                else:
                    idx = b.find(b"protected void add_to_top_rich(object ply)")
                    end_idx = b.find(b"protected int sort_top_force(", idx) if idx != -1 else -1
                    if idx != -1 and end_idx != -1 and b"return 0;" in b[idx:end_idx]:
                        col.add("undefined-misc-dir", p, "paiming_d.lpc void add_to_top_rich() returns 0")

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
            if os.path.isfile(job_p):
                dizi_b = open(f"{REPO}/{p}", "rb").read()
                job_b = open(job_p, "rb").read()
                if re.search(rb'(?m)^[ \t]*inherit\s+NPC\s*;', job_b):
                    if re.search(rb'(?m)^[ \t]*inherit\s+NPC\s*;', dizi_b):
                        col.add("mr-dizi-duplicate-inherit", p, "inherit NPC; in dizi.lpc duplicates job-dizi.lpc inherit and breaks compilation")
                    elif re.search(rb'(?m)^[ \t]*mapping\s+(?:skills|learned)\s*;', dizi_b):
                        col.add("mr-dizi-duplicate-inherit", p, "mapping skills/learned in dizi.lpc redeclares globals inherited from F_SKILL via job-dizi.lpc")

    if col.wants("semote-local-functional"):
        for _, p, _ in targeted_bins["semote"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"emotion_sort[$1]" in b:
                mk = code_mask(b, heredoc=True)
                for m in re.finditer(rb'\bemotion_sort\[\$1\]', b):
                    if mk[m.start()]:
                        ln = b.count(b"\n", 0, m.start()) + 1
                        col.add("semote-local-functional", f"{p}:{ln}", "local mapping `emotion_sort` indexed in functional without `$(emotion_sort)`")
                        break

    if col.wants("rpp-self-corrupted"):
        for _, p, _ in targeted_bins["rpadm"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'strsrch(str,query(", ")' in b or b'set(%s, %s, if(' in b:
                col.add("rpp-self-corrupted", p, "rp/rpp.lpc source self-corrupted by dbase rewrite (`query(\", \"` / `set(%s, %s, if(`)")

    if col.wants("fingerd-db-save-decls"):
        fd_splice_re = re.compile(rb'sprintf\([^;)]*\n[ \t]*(?:string|int)\s+[A-Za-z_*]')
        fd_inner_where_re = re.compile(rb'#ifdef DB_SAVE[^\n]*\n(?:[ \t]*string\s+\*ret;[^\n]*\n)?[ \t]*string\s+where\b[^\n]*\n[ \t]*ip_number\s*=')
        fd_hdr_re = re.compile(rb'finger_user\s*\([^)]*\)\s*\{(.*?)\bif\s*\(\s*!\s*me\s*\)', re.S)
        fd_ifdef_re = re.compile(rb'#ifdef\s+DB_SAVE\b.*?#endif\b', re.S)
        fd_var_re = re.compile(rb'\b(?:ret|sql|ip_number|addr|res|flag)\b')
        for _, p, _ in targeted_bins["fingerd"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"#ifdef DB_SAVE" not in b or b"DATABASE_D->do_sql" not in b:
                continue
            if fd_splice_re.search(b):
                col.add("fingerd-db-save-decls", p, "DB_SAVE local declarations spliced inside sprintf(...) call")
                continue
            if fd_inner_where_re.search(b) and b"where = res[1];" in b:
                col.add("fingerd-db-save-decls", p, "`where` declared inside inner #ifdef DB_SAVE block is out of scope at `where = res[1]`")
                continue
            hm = fd_hdr_re.search(b)
            if hm and fd_var_re.search(fd_ifdef_re.sub(b"", hm.group(1))):
                col.add("fingerd-db-save-decls", p, "DB_SAVE locals declared outside #ifdef DB_SAVE emit unused-local warnings")

    if col.wants("shujian-unclosed-if-logind"):
        for _, p, _ in targeted_bins["guomai"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"if (objectp(present(ob, this_object()) {" in b or b'if (query_temp("last_damage_from") == me {' in b:
                col.add("shujian-unclosed-if-logind", p, "unbalanced `if (... {` missing closing `)` before `{`")
        lg_orphan_re = re.compile(rb'input_to\("get_name",\s*ob\);\r?\n\}\r?\n"\\n"')
        for _, p, rel in targeted_bins["logind"]:
            if rel != "/logind.lpc":
                continue
            b = open(f"{REPO}/{p}", "rb").read()
            if lg_orphan_re.search(b):
                col.add("shujian-unclosed-if-logind", p, "orphan duplicated `confirm_password()` tail outside closing `}`")

    if col.wants("nitan-pharmacy-broken"):
        for _, p, rel in targeted_bins["pharmacy"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/adm/daemons/pharmacyd.lpc":
                if (
                    b"#define MEDICINE_DIR(" not in b
                    or b"#define HERB_OB" not in b
                    or b"member_array(value, name)" in b
                ):
                    col.add("nitan-pharmacy-broken", p, "pharmacyd.lpc missing MEDICINE_DIR/HERB_OB defines or swapped member_array(value, name)")
            elif rel == "/clone/pharmacy/herb/herb.lpc":
                if (
                    b"#define PHARMACY_D" not in b
                    or b"string s_name," in b
                    or b"set_name(name, ({ eng }))" in b
                ):
                    col.add("nitan-pharmacy-broken", p, "herb.lpc missing PHARMACY_D define, redeclares s_name, or wraps eng in ({ eng })")
            elif rel == "/clone/pharmacy/medicine/10.lpc":
                if b"inherit MEDICINE;" in b:
                    col.add("nitan-pharmacy-broken", p, "10.lpc inherits undefined macro MEDICINE instead of ITEM")

    if col.wants("xo-special-quest-setreboot"):
        for _, p, rel in targeted_bins["xo_qboot"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/system/std/char/special_quest.lpc":
                if re.search(rb"//[^\r\n]*\bif[ \t]*\([ \t]*random[ \t]*\([ \t]*class_score", b):
                    col.add("xo-special-quest-setreboot", p, "special_quest.lpc `if (random(class_score) < 50)` swallowed into `//` comment line")
            elif rel == "/cmds/admin/setreboot.lpc":
                mk = code_mask(b, heredoc=True)
                cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
                if re.search(rb"\badminp[ \t]*\(", cb):
                    col.add("xo-special-quest-setreboot", p, "setreboot.lpc calls undefined `adminp()` instead of `wiz_level()` check")

    if col.wants("qujing-gunfa-weapon-name"):
        for _, p, _ in targeted_bins["qujing"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if (
                b"int wn, i, level;" in b
                or b'query_temp("weapon", wn = me)' in b
                or b'me->query_temp("weapon")->query("name")' in b
            ):
                col.add("qujing-gunfa-weapon-name", p, "qujing-gunfa.lpc declares `int wn` or reads weapon name without objectp() guard / mangled `wn = me`")

    if col.wants("xyj-eof-tail-corruption"):
        for _, p, rel in targeted_bins["xyj_eof"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/qujing/start/24/12.lpc" and (b"\x06" in b or b"piyi@" in b):
                col.add("xyj-eof-tail-corruption", p, "corrupted binary EOF tail on carry_object(\".../piyi\")")
            elif rel == "/d/meishan/cuiping.lpc" and b"return ZN" in b:
                col.add("xyj-eof-tail-corruption", p, "corrupted EOF `return ZN ...` instead of `return 1; }`")
            elif rel == "/d/ourhome/obj/nowords.lpc" and b"\x1b" in b:
                col.add("xyj-eof-tail-corruption", p, "stray trailing ESC (0x1b) byte at EOF")
            elif rel == "/d/sky/yunlougate.lpc" and re.search(rb"(?m)^  a [^\x00-\x7f]", b):
                col.add("xyj-eof-tail-corruption", p, "corrupted EOF garbage bytes replacing closing `}`")

    if col.wants("demogorgon-is-killing-object"):
        str_iskill_cache: dict[str, bool] = {}
        for slug, p, _ in targeted_bins["demogorgon"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"is_killing(this_player())" not in b:
                continue
            if slug not in str_iskill_cache:
                atk = f"{REPO}/libs/{slug}/work/feature/attack.lpc"
                str_iskill_cache[slug] = (
                    os.path.isfile(atk)
                    and bool(re.search(rb"\bis_killing\s*\(\s*string\b", open(atk, "rb").read()))
                )
            if str_iskill_cache[slug]:
                col.add("demogorgon-is-killing-object", p, "calls `is_killing(this_player())` against `feature/attack.lpc` `is_killing(string id)`")

    if col.wants("dodgebook-party-syntax"):
        for _, p, rel in targeted_bins["dodge_party"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/yanziwu/obj/dodgebook.lpc":
                if re.search(rb"//[^\r\n]*experience req\r?\n[ \t]*uired\b", b):
                    col.add("dodgebook-party-syntax", p, "wrapped comment continuation words (`uired`/`is`/`ill`/`rn`) in code position")
            elif rel == "/quest/shenshu/npc/party.lpc":
                if (
                    re.search(rb'"qingyun-shou": 100[ \t]*\r?\n', b)
                    or re.search(rb'"strike"[ \t]*:[ \t]*"chousui-zhang",[ \t]*q\r?\n', b)
                    or re.search(rb'\]\),\r?\n[ \t]*"party"[ \t]*:[ \t]*"shaolin",', b)
                ):
                    col.add("dodgebook-party-syntax", p, "party.lpc missing `,` after `\"qingyun-shou\": 100`, stray `q` after `\"chousui-zhang\",`, or missing `([` before `\"party\": \"shaolin\"`")

    if col.wants("hy-migong-skill-warnings"):
        for _, p, rel in targeted_bins["hy_migong_skill"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/p/migong/lin06.lpc":
                if re.search(rb'\bset_maze_boss\s*\(\s*"', b):
                    col.add("hy-migong-skill-warnings", p, "lin06.lpc passes string path to `vrm_server::set_maze_boss(object ob)`")
            elif rel in ("/kungfu/skill/zhuihun-biao.lpc", "/daemon/skill/zhuihun-biao.lpc"):
                if re.search(rb'(?m)^[ \t]*weapon\s*;\s*weapon\s*=\s*me->query_temp\("weapon"\)\s*;', b):
                    col.add("hy-migong-skill-warnings", p, "zhuihun-biao.lpc stray no-op `weapon; weapon = me->query_temp(\"weapon\");`")
            else:
                if re.search(rb'\bif\s*\(\s*i\s*>\s*j\s*-\s*2\s*\)\s*\{\r?\n[ \t]*\{\r?\n(?:[ \t]*//case [012]:[^\r\n]*\r?\n){3}[ \t]*\}\r?\n[ \t]*\}', b):
                    col.add("hy-migong-skill-warnings", p, "meskill empty `if (i > j - 2)` block triggers unused conditional warning")

    if col.wants("undefined-set-max-items"):
        move_lacks_max_items: dict[str, bool] = {}
        for slug, p, _ in targeted_bins["set_max_items"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"set_max_items" not in b:
                continue
            if slug not in move_lacks_max_items:
                mv = f"{REPO}/libs/{slug}/work/feature/move.lpc"
                move_lacks_max_items[slug] = (
                    os.path.isfile(mv) and b"set_max_items" not in open(mv, "rb").read()
                )
            if not move_lacks_max_items[slug]:
                continue
            mk = code_mask(b, heredoc=True)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if re.search(rb'(?<!->)\bset_max_items\s*\(', cb):
                col.add("undefined-set-max-items", p, "calls `set_max_items(...)` but `feature/move.lpc` does not define it")

    if col.wants("xkx-include-syntax-blockers"):
        for slug, p, rel in targeted_bins["xkx_blockers"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/quanzhou/yaopu/obj/yaolu.lpc":
                if b'"/d/quanzhou/obj/drug_list.h"' in b and os.path.isfile(f"{REPO}/libs/{slug}/work/d/quanzhou/yaopu/obj/drug_list.h"):
                    col.add("xkx-include-syntax-blockers", p, "yaolu.lpc includes missing `/d/quanzhou/obj/drug_list.h` instead of `/d/quanzhou/yaopu/obj/drug_list.h`")
            elif rel == "/d/xiakedao/npc/gaolao1.lpc":
                if b'"/d/xiakedao/npc/zhanglao.lpc"' in b:
                    col.add("xkx-include-syntax-blockers", p, "gaolao1.lpc includes missing `/d/xiakedao/npc/zhanglao.lpc` instead of `zhanglao.h`")
            elif rel == "/d/city/yuelao2.lpc":
                if re.search(rb'\r?\n\]\r?\n\)\r?\n\);', b):
                    col.add("xkx-include-syntax-blockers", p, "yuelao2.lpc stray duplicate `]));` after `set(\"exits\", ...)`")
            elif rel == "/d/qilian/npc/pixie_superskill.lpc":
                if re.search(rb'target->unconcious\(\);\r?\n[ \t]*else\s*\{', b):
                    col.add("xkx-include-syntax-blockers", p, "pixie_superskill.lpc two-statement `if` missing `{ ... }` before `else`")

    if col.wants("heimuya-mishi-cctx-syntax"):
        for _, p, rel in targeted_bins["mishi_cctx"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/heimuya/mishi.lpc":
                if (
                    re.search(rb'\\n",\s*this_player\(\);', b)
                    or b"this_pl;" in b
                    or re.search(rb'\boid buqun_rob\(', b)
                ):
                    col.add("heimuya-mishi-cctx-syntax", p, "mishi.lpc truncated `this_player();`/`this_pl;` or duplicated `oid buqun_rob(`")
            elif rel == "/d/taohua/npc/shoumu1.lpc":
                if re.search(rb'\(:\s*exert_function,\s*"recover"\s*:\),\s*\r?\n[ \t]*setup\(\);', b):
                    col.add("heimuya-mishi-cctx-syntax", p, "shoumu1.lpc unclosed `set(\"chat_msg_combat\", ({ ...` before `setup();`")
            elif rel == "/d/shenlong/npc/haibing.lpc":
                if b"inherit " not in b and b"set_name(" in b:
                    col.add("heimuya-mishi-cctx-syntax", p, "haibing.lpc missing `inherit NPC;`")
            elif rel == "/d/mj/obj/mjjs.lpc":
                if re.search(rb'set\("long",\r?\n"', b):
                    col.add("heimuya-mishi-cctx-syntax", p, "mjjs.lpc unclosed multiline string literal in `set(\"long\", ...)`")

    if col.wants("qhlist-cike-chidi-syntax"):
        for _, p, rel in targeted_bins["qhlist_chidi"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/quest/qhlist600000.lpc":
                if re.search(rb'"pot_bonus"\s*:\s*44,\s*r\r?\n', b):
                    col.add("qhlist-cike-chidi-syntax", p, "qhlist600000.lpc stray `r` after `\"pot_bonus\": 44,`")
            elif rel == "/quest/baobiao/cike.lpc":
                if b.rstrip().endswith(b'set_skill("hunyuan-yiqi", l'):
                    col.add("qhlist-cike-chidi-syntax", p, "cike.lpc truncated EOF at `set_skill(\"hunyuan-yiqi\", l`")
            elif rel == "/kungfu/skill/guxing-sword.lpc":
                if re.search(rb'\+YEL\+"[^"\r\n]+\+NOR\+"', b):
                    col.add("qhlist-cike-chidi-syntax", p, "guxing-sword.lpc missing closing `\"` before `+NOR+`")
            elif rel == "/d/shushan/zhenyaota/npc/yaoguai4.lpc":
                if b'"+chinese_number(1*0000)+"' in b:
                    col.add("qhlist-cike-chidi-syntax", p, "yaoguai4.lpc stray `\"` and `1*0000` in `tell_object()`")

    if col.wants("sjsh-angle-include-headers"):
        for slug, p, rel in targeted_bins["sjsh_inc"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/huanggong/dachen2.lpc":
                if b"#include <reporting.h>" in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/include/reporting.h") and os.path.isfile(f"{REPO}/libs/{slug}/work/d/huanggong/npc/reporting.h"):
                    col.add("sjsh-angle-include-headers", p, "dachen2.lpc uses `#include <reporting.h>` instead of `\"/d/huanggong/npc/reporting.h\"`")
            elif rel == "/d/calvin/tianpeng/npc/hufa.lpc":
                if b"#include <soldier_skill.h>" in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/include/soldier_skill.h") and os.path.isfile(f"{REPO}/libs/{slug}/work/obj/npc/soldier_skill.h"):
                    col.add("sjsh-angle-include-headers", p, "hufa.lpc uses `#include <soldier_skill.h>` instead of `\"/obj/npc/soldier_skill.h\"`")

    if col.wants("dtsl-daemon-weapon-blockers"):
        for slug, p, rel in targeted_bins["dtsl_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/adm/daemons/fingerd2.lpc":
                if b"(wizardp(name) > 0)" in b:
                    col.add("dtsl-daemon-weapon-blockers", p, "fingerd2.lpc passes string `name` to efun `wizardp()` instead of `wiz_level(name)`")
            elif rel == "/adm/daemons/cleard.lpc":
                if re.search(rb'(?m)^say\r?$', b):
                    col.add("dtsl-daemon-weapon-blockers", p, "cleard.lpc stray bare `say` statement")
            elif rel == "/clone/weapon/tulong-dao.lpc":
                if slug in ("dtsl", "dtsl2", "dtslmud") and re.search(rb'(?m)^[ \t]*use_flag\s*=\s*16;', b):
                    col.add("dtsl-daemon-weapon-blockers", p, "tulong-dao.lpc assigns undefined `use_flag = 16;` in DTSL")
            elif rel == "/d/clone/room/lingwu/yingui/zhuyu-yan.lpc":
                if slug == "dtsl" and b"ansi.h" not in b and b"HIR" in b:
                    col.add("dtsl-daemon-weapon-blockers", p, "zhuyu-yan.lpc uses `HIR`/`NOR` without `#include <ansi.h>`")

    if col.wants("mhxy-bagua-include"):
        for slug, p, _ in targeted_bins["mhxy_bagua"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'#include "/d/bagua/bagua.h"' in b and os.path.isfile(f"{REPO}/libs/{slug}/work/d/youxia/BAGUA/BAGUA.H"):
                col.add("mhxy-bagua-include", p, "uses stale `#include \"/d/bagua/bagua.h\"` instead of `\"/d/youxia/BAGUA/BAGUA.H\"`")

    if col.wants("xkx-rstbkup-xunbu-xuanci"):
        for slug, p, rel in targeted_bins["xkx_rx"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel.endswith("/rstbkup.lpc"):
                if b"#endif #define" in b:
                    col.add("xkx-rstbkup-xunbu-xuanci", p, "collapsed `#endif #define` on one line causes `Missing #endif`")
            elif rel == "/cmds/std/xunbu.lpc":
                if b'#include "npc_skills_attrib_setup.h"' in b and os.path.isfile(f"{REPO}/libs/{slug}/work/d/city/npc/npc_skills_attrib_setup.h"):
                    col.add("xkx-rstbkup-xunbu-xuanci", p, "relative `#include \"npc_skills_attrib_setup.h\"` fails outside `/d/city/npc/`")
            elif rel == "/d/shaolin/npc/xuanci.lpc":
                if b'#include "/d/shaolin/npc/job.h"' in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/d/shaolin/npc/job.h"):
                    col.add("xkx-rstbkup-xunbu-xuanci", p, "includes missing `/d/shaolin/npc/job.h` (adopt from sibling `jym`)")

    if col.wants("sanjieshenhua-footprint-hufa-luoyang"):
        for slug, p, rel in targeted_bins["sjsh_fhl"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/linghai/footprint.lpc":
                if b'set_name("short"' in b or b'set_name("long"' in b:
                    col.add("sanjieshenhua-footprint-hufa-luoyang", p, "`set_name(\"short\"/\"long\", ...)` should be `set(...)`")
            elif rel == "/d/wizz/calvin/tianpeng/npc/hufa.lpc":
                if b"#include <soldier_skill.h>" in b and os.path.isfile(f"{REPO}/libs/{slug}/work/obj/npc/soldier_skill.h"):
                    col.add("sanjieshenhua-footprint-hufa-luoyang", p, "uses `#include <soldier_skill.h>` instead of `\"/obj/npc/soldier_skill.h\"`")
            elif rel in ("/d/luoyang/npc/fushang.lpc", "/d/luoyang/zhulin2.lpc"):
                if b.startswith(b"a\n") or b.startswith(b"a\r\n"):
                    col.add("sanjieshenhua-footprint-hufa-luoyang", p, "stray leading `a` before `inherit`")
            elif rel == "/daemon/skill/aohan-liujue.lpc":
                if b.count(b"mapping query_action(") > 1:
                    col.add("sanjieshenhua-footprint-hufa-luoyang", p, "duplicate `query_action()` definition")

    if col.wants("shujian-shaolin-chan-include"):
        for slug, p, _ in targeted_bins["sj_chan"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'(?m)^[ \t]*#include[ \t]+"chan\.h"', b) and not os.path.isfile(f"{REPO}/libs/{slug}/work/d/shaolin/npc/chan.h") and os.path.isfile(f"{REPO}/libs/{slug}/work/d/shaolin/obj/chan.h"):
                col.add("shujian-shaolin-chan-include", p, "relative `#include \"chan.h\"` fails outside `/d/shaolin/obj/`")

    if col.wants("nitan-present-baixing-paren"):
        for _, p, _ in targeted_bins["nt_baixing"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'present(query("baixing", environment(this_object())))' in b:
                col.add("nitan-present-baixing-paren", p, "misplaced paren in `present(query(\"baixing\", environment(this_object())))`")

    if col.wants("nitan-checkskill-mixed-array"):
        for _, p, _ in targeted_bins["nt_chkskill"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'\bmixed\s+\*\s*value\s*;', b) and b'replace_string(temp, "$N", value)' in b:
                col.add("nitan-checkskill-mixed-array", p, "declares `mixed *value;` then passes `value` to `replace_string()`")

    if col.wants("nitan-paimaishi-corrupt-payback"):
        for _, p, _ in targeted_bins["nt_paimai"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'pay_back\(owner_id,[^\n]+\);\s*\n\s*if \(!who->restore\(\)\)', b):
                col.add("nitan-paimaishi-corrupt-payback", p, "corrupted `finish_paimai()` with stray `pay_back()` tail")

    if col.wants("xyj-yulan-lj-blockers"):
        for slug, p, rel in targeted_bins["xyj_yulan"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/kaifeng/npc/yulan.lpc":
                if b'#include <reporting.h>' in b and os.path.isfile(f"{REPO}/libs/{slug}/work/d/kaifeng/npc/reporting.lpc") and not os.path.isfile(f"{REPO}/libs/{slug}/work/include/reporting.h"):
                    col.add("xyj-yulan-lj-blockers", p, "stale `#include <reporting.h>` instead of `\"reporting.lpc\"`")
            elif rel == "/d/dntg/yunlou/npc/lj.lpc":
                if b.startswith(b"i  //"):
                    col.add("xyj-yulan-lj-blockers", p, "stray leading `i  //` before `inherit NPC;`")

    if col.wants("vrm-server-undefined-schedule-d"):
        for slug, p, _ in targeted_bins["vrm_sched"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"SCHEDULE_D->" in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/adm/daemons/scheduled.lpc"):
                col.add("vrm-server-undefined-schedule-d", p, "calls `SCHEDULE_D->` without `/adm/daemons/scheduled.lpc` (use `call_out`)")

    if col.wants("sje-uid-mafu-shenshu-blockers"):
        for slug, p, rel in targeted_bins["sje_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/include/uid.h":
                if b"#endif" in b and b"#if" not in b:
                    col.add("sje-uid-mafu-shenshu-blockers", p, "orphan `#endif` without matching `#if`")
            elif rel == "/d/huanghe/npc/mafu.lpc":
                for hdr in ("mafuyz.h", "mafulz.h"):
                    if re.search(rb'(?m)^[ \t]*#include[ \t]+"' + hdr.encode() + rb'"', b) and not os.path.isfile(f"{REPO}/libs/{slug}/work/d/huanghe/npc/{hdr}"):
                        col.add("sje-uid-mafu-shenshu-blockers", p, f"includes missing `{hdr}`")
            elif rel == "/quest/shenshu/npc/name.lpc":
                if b"HIY" in b and b"ansi.h" not in b:
                    col.add("sje-uid-mafu-shenshu-blockers", p, "uses ANSI color macros (`HIY`) without `#include <ansi.h>`")

    if col.wants("pkuxkx-sjsz-special-weapon"):
        for slug, p, _ in targeted_bins["pku_sw"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'#include "/clone/unique/special_weapon.h"' in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/clone/unique/special_weapon.h") and os.path.isfile(f"{REPO}/libs/{slug}/work/d/bwdh/sjsz/obj/obj/unique/special_weapon.h"):
                col.add("pkuxkx-sjsz-special-weapon", p, "uses stale `#include \"/clone/unique/special_weapon.h\"` instead of `\"/d/bwdh/sjsz/obj/obj/unique/special_weapon.h\"`")

    if col.wants("task1-npc-accept-hit-type"):
        for _, p, rel in targeted_bins["task1_hit"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/city/task1/npc.h":
                if b"int accept_hit(string " in b and b"accept_hit(who)" in b:
                    col.add("task1-npc-accept-hit-type", p, "`int accept_hit(string arg)` called with `object who`")
            elif rel in ("/kungfu/skill/jinshe-zhang/fugu.lpc", "/kungfu/skill/jinshe-zhui/tuwu.lpc"):
                if b.startswith(b"s  //"):
                    col.add("task1-npc-accept-hit-type", p, "stray leading `s  //` before comment")
            elif rel == "/clone/food/dami.lpc":
                if b"init_unarmed(" in b and b"inherit ITEM;" in b:
                    col.add("task1-npc-accept-hit-type", p, "food `inherit ITEM` calls nonexistent `init_unarmed()`")

    if col.wants("calvin-rjl-diamond-header"):
        for _, p, _ in targeted_bins["rjl_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"inherit SHIELD;" in b and b"inherit NECK;" in b:
                col.add("calvin-rjl-diamond-header", p, "diamond `inherit SHIELD;` + `inherit NECK;`")
            if b"offensive_target(" in b and b"object offensive_target(" not in b:
                col.add("calvin-rjl-diamond-header", p, "missing `object offensive_target(object me)` header")

    if col.wants("weapon-feature-include-dotc"):
        for _, p, _ in targeted_bins["weapon_feat"]:
            b = open(f"{REPO}/{p}", "rb").read()
            mo = re.search(rb'^\s*#\s*include\s*"([^"]+\.c)"', b, re.M)
            if mo:
                inc = mo.group(1).decode("ascii", "replace")
                parent = os.path.dirname(f"{REPO}/{p}")
                if not os.path.exists(os.path.join(parent, inc)) and os.path.exists(os.path.join(parent, inc[:-2] + ".lpc")):
                    col.add("weapon-feature-include-dotc", p, f'stale `#include "{inc}"` when `{inc[:-2]}.lpc` exists')

    if col.wants("shenzhou-syntax-include-blockers"):
        for _, p, rel in targeted_bins["sz_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/clone/gift/pantao.lpc" and b") remove_action(" in b:
                col.add("shenzhou-syntax-include-blockers", p, "missing `;` before `remove_action()`")
            elif rel == "/d/huanghe/bangjob/bangjob200000.lpc" and re.search(rb"\]\),\s*\n\s*\]\),", b):
                col.add("shenzhou-syntax-include-blockers", p, "stray duplicate `]),` closing mapping array")
            elif rel == "/kungfu/class/kunlun/hetaichong.lpc" and "你去找班夫人吧.);".encode("utf-8") in b:
                col.add("shenzhou-syntax-include-blockers", p, "unclosed quote before `);`")
            elif rel in ("/d/shaolin/haishui3.lpc", "/d/shaolin/shaolin/haishui3.lpc") and b'#include "d/shaolin/npc/yaoshui.h";' in b:
                col.add("shenzhou-syntax-include-blockers", p, "relative `#include \"d/shaolin/npc/yaoshui.h\";inherit ROOM;`")
            elif rel == "/d/shaolin/npc/yaoshui.h" and (b"#include <ansi.h>int " in b or b'if (ob->query("full")\n' in b):
                col.add("shenzhou-syntax-include-blockers", p, "glued `#include <ansi.h>int` or unclosed `if (ob->query(\"full\")`")

    if col.wants("shujian-buliao-change-state"):
        for _, p, _ in targeted_bins["buliao_h"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"void change_name(" in b and b"void change_state(" not in b:
                col.add("shujian-buliao-change-state", p, "`buliao.h` defines `change_name()` without `change_state()` needed by `buliao*-2.lpc` and `zhibuji.lpc`")

    if col.wants("changjinpeng-tanzhu-include"):
        for slug, p, _ in targeted_bins["cjp_tanzhu"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'#include "/kungfu/class/mingjiao/tanzhu.h"' in b:
                if (not os.path.exists(f"{REPO}/libs/{slug}/work/kungfu/class/mingjiao/tanzhu.h")
                        and os.path.exists(f"{REPO}/libs/{slug}/work/d/mingjiao/npc/tanzhu.h")):
                    col.add("changjinpeng-tanzhu-include", p, 'stale `#include "/kungfu/class/mingjiao/tanzhu.h"` when `/d/mingjiao/npc/tanzhu.h` exists')

    if col.wants("huashan-doctor-unclosed-sprintf"):
        for _, p, _ in targeted_bins["hs_doc"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'sprintf\("%s [^\r\n"]+",\s*\r?\n\s*return 0;', b):
                col.add("huashan-doctor-unclosed-sprintf", p, "unclosed `sprintf(...,` followed directly by `return 0;`")

    if col.wants("m-bian-duplicate-create"):
        for _, p, _ in targeted_bins["m_bian"]:
            b = open(f"{REPO}/{p}", "rb").read()
            mk = code_mask(b)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if len(re.findall(rb'\bvoid\s+create\s*\(\s*\)\s*\{', cb)) >= 2:
                col.add("m-bian-duplicate-create", p, "duplicate `void create()` definition")
            elif b'w_name = me->query("weapon/name");' in cb and b'if (!me' not in cb:
                col.add("m-bian-duplicate-create", p, "unguarded `me->query(\"weapon/name\")` when `this_player()` may be 0")

    if col.wants("lingshe-set-color-wmkj-blockers"):
        for slug, p, rel in targeted_bins["ls_wmkj"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/xingxiu/npc/lingshe.lpc" and b'set_color("$HIW$");' in b:
                fn = f"{REPO}/libs/{slug}/work/feature/name.lpc"
                if not (os.path.exists(fn) and b"set_color(" in open(fn, "rb").read()):
                    col.add("lingshe-set-color-wmkj-blockers", p, 'undefined `set_color("$HIW$")`')
            elif rel == "/d/objj/cloth/tianyi.lpc" and b"unique::init();" in b:
                fu = f"{REPO}/libs/{slug}/work/feature/unique.lpc"
                if not (os.path.exists(fu) and b"void init(" in open(fu, "rb").read()):
                    col.add("lingshe-set-color-wmkj-blockers", p, "`unique::init()` when `feature/unique.lpc` defines no `init()`")
            elif rel == "/kungfu/skill/xixi-unarmed.lpc" and b.startswith(b"c  //"):
                col.add("lingshe-set-color-wmkj-blockers", p, "stray leading `c  //` before comment")

    if col.wants("objmaker-for-zhaoshi-dup"):
        for _, p, rel in targeted_bins["objmaker_zh"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/clone/misc/objmaker.lpc" and b"for (i = 0; i if (member_array(" in b:
                col.add("objmaker-for-zhaoshi-dup", p, "truncated `for (i = 0; i if (member_array(...)`")
            elif rel.startswith("/kungfu/skill/") and b"// ZHAOSHI : 0// THIS IS PLAYER'S OWN SKILL" in b:
                col.add("objmaker-for-zhaoshi-dup", p, "duplicated `// ZHAOSHI : 0// THIS IS PLAYER'S OWN SKILL` header")

    if col.wants("fqyy-robber-gaochang-shopman"):
        for slug, p, rel in targeted_bins["fqyy_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/npc/robber.lpc" and b"is_killing(this_player())" in b:
                fa = f"{REPO}/libs/{slug}/work/feature/attack.lpc"
                if os.path.isfile(fa) and re.search(rb"\bint\s+is_killing\s*\(\s*string\b", open(fa, "rb").read()):
                    col.add("fqyy-robber-gaochang-shopman", p, "passes `this_player()` object to `is_killing(string)`")
            elif rel == "/d/gaochang/zoulang_1.lpc" and b") ]);" in b:
                col.add("fqyy-robber-gaochang-shopman", p, "malformed mapping closer `) ]);` instead of `]));`")
            elif rel == "/d/pingan/pingan/npc/shopman2.lpc" and re.search(rb"//[^\r\n]*book4[^\r\n]*\r?\n[ \t]*\}\r?\n[ \t]*\)\r?\n[ \t]*\);", b):
                col.add("fqyy-robber-gaochang-shopman", p, "uncommented `}\n)\n);` tail left after commented `vendor_goods`")
            elif rel == "/d/gaochang/npc/3.lpc" and b"this_player() if (" in b:
                col.add("fqyy-robber-gaochang-shopman", p, "missing `;` between `me = this_player()` and `if (...)`")

    if col.wants("hy-danuoyi-quest-unclosed-quote"):
        q_tm = '"天门道人,'.encode("utf-8")
        q_jk = '"绞髁,'.encode("utf-8")
        for _, p, rel in targeted_bins["hy_dq"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel.endswith("/bingxue-xinfa/qiankun-danuoyi.lpc") and b"&& random(2) = 0 {" in b:
                col.add("hy-danuoyi-quest-unclosed-quote", p, "premature `)` and `random(2) = 0` assignment in `if` condition")
            elif rel.endswith("/quest.lpc") and q_tm in b:
                col.add("hy-danuoyi-quest-unclosed-quote", p, 'unclosed `"天门道人,` string literal in quest table')
            elif rel == "/quest/newbie/qiandao/lagjobold.lpc" and q_jk in b:
                col.add("hy-danuoyi-quest-unclosed-quote", p, 'unclosed `"绞髁,` string literal in quest table')

    if col.wants("jianjun-count-wxddym-blockers"):
        for _, p, rel in targeted_bins["jj_wx"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/city2/npc/jianjun.lpc" and b"count = 600000;" in b and not re.search(rb"\bint\b[^;]*\bcount\b", b):
                col.add("jianjun-count-wxddym-blockers", p, "assigns `count = 600000;` without declaring `int count;` (collides with `count` sefun)")
            elif rel == "/d/city/npc/tianshi.lpc" and re.search(rb"int\s+accept_object\s*\(\s*object\s+who\s*,\s*object\s+ob\s*\)\s*\{\r?\n[ \t]*object\s+ob\s*;", b):
                col.add("jianjun-count-wxddym-blockers", p, "redeclares parameter `object ob;` inside `accept_object()`")
            elif rel == "/kungfu/skill/tangmen-throwing/san.lpc" and b'query_skill("force")++ me->query_skill' in b:
                col.add("jianjun-count-wxddym-blockers", p, "stray `++` instead of `+` in `ap` expression")
            elif rel == "/clone/npc/killer.lpc" and re.search(rb'set\("qi",\s*100\)[ \t]+//', b):
                col.add("jianjun-count-wxddym-blockers", p, 'missing `;` after `set("qi", 100)`')
            elif rel == "/npc/feizei14.lpc" and re.search(rb'map_skill\("sword",\s*"huashan-jianfa"\);\r?\n[ \t]*\}\r?\n[ \t]*\)\r?\n[ \t]*\);', b):
                col.add("jianjun-count-wxddym-blockers", p, "stray `}\n)\n);` closing tokens after `map_skill()`")

    if col.wants("spekilled-es2-query-arg"):
        for slug, p, _ in targeted_bins["spekilled"]:
            fdb = f"{REPO}/libs/{slug}/work/feature/dbase.lpc"
            if not (os.path.isfile(fdb) and re.search(rb"mixed\s+query\s*\(\s*string\s+\w+\s*,\s*int\b", open(fdb, "rb").read())):
                continue
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'(?m)^[ \t]*exp\s*=\s*query\(\s*"combat_exp",\s*me\s*\)', b):
                col.add("spekilled-es2-query-arg", p, 'calls Nitan7 `query("combat_exp", me)` under ES2 `query(string, int)`')

    if col.wants("shenghuo-quan-mojibake-quote"):
        bad_q = "仁セ鹑\ue11a);".encode("utf-8")
        for _, p, _ in targeted_bins["shquan"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if bad_q in b:
                col.add("shenghuo-quan-mojibake-quote", p, 'GBK-mojibake unclosed `notify_fail("你的内力太弱，无法练仁セ鹑...);`')

    if col.wants("fy-purplerose-newtask-setup"):
        for slug, p, rel in targeted_bins["fy_nt"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/fy/npc/obj/purplerose.lpc" and b"else {d" in b:
                col.add("fy-purplerose-newtask-setup", p, "stray `d` after `else {`")
            elif rel.startswith("/newtask/") and re.search(rb"(?m)^[ \t]*setup\(\);", b):
                fi = f"{REPO}/libs/{slug}/work/std/item.lpc"
                if os.path.isfile(fi) and b"void setup(" not in open(fi, "rb").read():
                    col.add("fy-purplerose-newtask-setup", p, "calls undefined `setup()` under Fengyun `std/item.lpc` (use `::init_item()`)")

    if col.wants("jhfy-chai-ring-haodatong"):
        for slug, p, rel in targeted_bins["jhfy_crh"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel.startswith("/d/obj/quest/chai") and b'#include "task.h"' in b and b"int query_autoload()" in b:
                th = f"{REPO}/libs/{slug}/work/d/obj/quest/task.h"
                if os.path.isfile(th) and b"query_autoload" in open(th, "rb").read():
                    col.add("jhfy-chai-ring-haodatong", p, 'redeclares `query_autoload()` already defined in `"task.h"`')
            elif rel == "/clone/box/item/26.lpc" and b"#include <weapon.h>" in b and b"inherit FINGER;" in b:
                col.add("jhfy-chai-ring-haodatong", p, "`inherit FINGER;` under `<weapon.h>` instead of `inherit RING;`")
            elif rel == "/d/quanzhen_old/npc/haodatong.lpc" and re.search(rb'return 1;\r?\n\}\r?\n\r?\nme->set\("neili"', b):
                col.add("jhfy-chai-ring-haodatong", p, "orphan duplicated `me->set(\"neili\", ...)` tail after closing `}`")

    if col.wants("competed-string-type-typo"):
        for _, p, _ in targeted_bins["competed"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb"(?m)^string (?:object|int|string|mapping) ", b):
                col.add("competed-string-type-typo", p, "`static`->`string` typo (`string object/int/string/mapping`) instead of `nosave`")

    if col.wants("zhonghua2-questobj-init-item"):
        qobj_re = re.compile(rb"(?m)^[ \t]*::init_(?:item|cloth|head|boots|neck)\(\);")
        has_ii_cache: dict[str, bool] = {}
        for slug, p, _ in targeted_bins["qobj_ii"]:
            if slug not in has_ii_cache:
                has_ii_cache[slug] = any(
                    os.path.isfile(ip) and b"void init_item" in open(ip, "rb").read()
                    for ip in (f"{REPO}/libs/{slug}/work/std/item.lpc", f"{REPO}/libs/{slug}/work/inherit/item/item.lpc")
                )
            if has_ii_cache[slug]:
                continue
            b = open(f"{REPO}/{p}", "rb").read()
            if qobj_re.search(b):
                col.add("zhonghua2-questobj-init-item", p, "calls Fengyun `::init_{item,cloth,head,boots,neck}()` under ES2 `ITEM` (use `setup()`)")

    if col.wants("fy2-eventd-bamboo3-cola"):
        for _, p, rel in targeted_bins["fy2_ebc"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/adm/daemons/eventd.lpc" and b'DATA_DIR + "event;' in b:
                col.add("fy2-eventd-bamboo3-cola", p, 'unclosed `DATA_DIR + "event;` string literal')
            elif rel == "/d/canyon/bamboo/bamboo3.lpc" and b"])); void init()" in b:
                col.add("fy2-eventd-bamboo3-cola", p, "`void init()` nested inside `void create()` before `setup(); }`")
            elif rel == "/d/canyon/npc/obj/cola.lpc" and b"inherit " not in b:
                col.add("fy2-eventd-bamboo3-cola", p, "missing `inherit ITEM;`")

    if col.wants("tianxia-banghui-d-blockers"):
        for _, p, _ in targeted_bins["tx_bh"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"member_array(tmp, bh_cnames)" in b or b'sprintf("%s%s/", dir_pre, id)' in b:
                col.add("tianxia-banghui-d-blockers", p, "undeclared `tmp` or `dir_pre` in `banghui_d.lpc`")

    if col.wants("xyj-xiwangmu-vcd3-blockers"):
        for _, p, rel in targeted_bins["xyj_xv"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/moon/npc/xiwangmu.lpc" and len(re.findall(rb'(?m)^\s*(?:string|int|void|mixed)\s+ask_pantao\s*\(', b)) > 1:
                col.add("xyj-xiwangmu-vcd3-blockers", p, "duplicate `ask_pantao()` definition")
            elif rel == "/clone/misc/vcd3.lpc" and re.search(rb'users\(\)\s*\);\s*users\(\)\s*\);', re.sub(rb'\s+', b' ', b)):
                col.add("xyj-xiwangmu-vcd3-blockers", p, "stray duplicated `users());` line")

    if col.wants("zhaoshi-premature-action-close"):
        for _, p, _ in targeted_bins["zhao_cls"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if re.search(rb'mapping\s*\*action\s*=\s*\(\{\s*\r?\n\s*\}\);\s*\r?\n\s*//\s*ZHAOSHI\s*:0\s*\r?\n\s*\(\[', b):
                col.add("zhaoshi-premature-action-close", p, "premature `});` closing `mapping *action = ({` before `// ZHAOSHI :0` mapping entry")

    if col.wants("tang-raw-telnet-utf8-literal"):
        for _, p, _ in targeted_bins["tang_iac"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"\\377" in b:
                col.add("tang-raw-telnet-utf8-literal", p, "raw Telnet IAC octal bytes (`\\377`) in UTF-8 string literal")

    if col.wants("dtsl-missing-wanted-h"):
        for slug, p, _ in targeted_bins["biaotou_w"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b"#include <wanted.h>" in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/include/wanted.h"):
                col.add("dtsl-missing-wanted-h", p, "`#include <wanted.h>` but `include/wanted.h` is missing")

    if col.wants("nitan-lcj-stale-lchj-include"):
        for slug, p, _ in targeted_bins["lcj_inc"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if b'/d/suzhou/npc/lchj.h' in b and not os.path.isfile(f"{REPO}/libs/{slug}/work/d/suzhou/npc/lchj.h"):
                if os.path.isfile(os.path.join(os.path.dirname(f"{REPO}/{p}"), "lchj.h")):
                    col.add("nitan-lcj-stale-lchj-include", p, 'stale `#include "/d/suzhou/npc/lchj.h"` — use local `"lchj.h"`')

    if col.wants("hell-zero-diag-blockers"):
        for _, p, rel in targeted_bins["hell_zd"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/clone/gift/yangrongwan.lpc" and b"inherit ITEM;" in b and b"set_amount(" in b:
                col.add("hell-zero-diag-blockers", p, "`set_amount()` called under `inherit ITEM;`")
            elif rel == "/d/baituo/npc/obj/bowl.lpc" and re.search(rb'set_name\s*\(\s*"[^"]*"\s*,\s*"[^"]*"\s*\)', b):
                col.add("hell-zero-diag-blockers", p, "string 2nd argument to `set_name()` instead of `({ ... })`")
            elif rel in ("/clone/special/bear.lpc", "/d/city/npc/obj/lbook3.lpc", "/d/xiaoyao/npc/obj/lbook4.lpc", "/d/xiaoyao/obj/lbook4.lpc"):
                if len(re.findall(rb'(?m)^\s*int\s+query_autoload\s*\(', b)) > 1:
                    col.add("hell-zero-diag-blockers", p, "duplicate `int query_autoload()` definition")

    if col.wants("shujian3-diemenglou-liumai"):
        for slug, p, rel in targeted_bins["sj3_dl"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel in ("/d/city/diemenglou1.lpc", "/d/city/diemenglou2.lpc") and b"CYNNOR" in b:
                col.add("shujian3-diemenglou-liumai", p, "merged `CYNNOR` macro typo (should be `CYN \"\\n\" NOR`)")
            elif rel == "/kungfu/skill/beiming-shengong/liumai.lpc" and b"/kungfu/skill/beiming-shengong/liumai_msg.h" in b:
                if not os.path.isfile(f"{REPO}/libs/{slug}/work/kungfu/skill/beiming-shengong/liumai_msg.h"):
                    col.add("shujian3-diemenglou-liumai", p, "missing `/kungfu/skill/beiming-shengong/liumai_msg.h`")

    if col.wants("jym-pingyuan-copyskills-examine-a"):
        for slug, p, rel in targeted_bins["jym_blk"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/final/pingyuan.lpc" and re.search(rb'set\("item_desc",\s*\(\[\s*\r?\n\s*\r?\n\s*set\("exits"', b):
                col.add("jym-pingyuan-copyskills-examine-a", p, 'unclosed `set("item_desc", ([` before `set("exits"`')
            elif rel == "/cmds/adm/examine.lpc" and b'efun::count(n1, "/", n2)' in b:
                col.add("jym-pingyuan-copyskills-examine-a", p, "removed `efun::count()` call in `count_div()`")
            elif rel == "/d/dali/npc/a.lpc" and b'if (random(a + b + c + d) > 40 && (random(a + b + c + d) < 70)\n' in b:
                col.add("jym-pingyuan-copyskills-examine-a", p, "unbalanced `(` in `if` condition")

    if col.wants("mhxy-yueru-lingfan-abc"):
        for _, p, rel in targeted_bins["mhxy_yla"]:
            b = open(f"{REPO}/{p}", "rb").read()
            if rel == "/d/shushan/npc/yueru.lpc" and re.search(rb'command\("heng "\s*\+\s*me->query\("id"\)\s*;', b):
                col.add("mhxy-yueru-lingfan-abc", p, 'missing `)` in `command("heng " + me->query("id");`')
            elif rel == "/daemon/skill_wiz/umbrella/lingfan-san.lpc" and b"umbrella_parry_msg" in b:
                col.add("mhxy-yueru-lingfan-abc", p, "undefined `umbrella_parry_msg` (should be `unarmed_parry_msg`)")
            elif rel == "/d/qujing/wudidong/npc/obj/abc.lpc" and re.search(rb'\bstr\s*\*\s*3\s*/\s*2\b', b):
                col.add("mhxy-yueru-lingfan-abc", p, "string multiplication `str * 3 / 2` / undeclared `qn`")

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

    if col.wants("skill-dead-callout"):
        sym_map = {
            "/kungfu/skill/beidou-zhenfa.lpc": b"destruct_me",
            "/kungfu/skill/shigu-bifa/kuangcao.lpc": b"remove_effect",
            "/daemon/class/lingjie/lingfan-san/lieshi.lpc": b"perform_jiaoyang",
            "/kungfu/skill/songyang-shou/junji.lpc": b"remove_effect",
            "/kungfu/skill/banruo-zhang/yipai.lpc": b"perform2",
            "/kungfu/skill/guang-jian/guangmang.lpc": b"perform_qiao",
        }
        for _, p, rel in targeted_bins["skill_co"]:
            sym = sym_map[rel]
            b = open(f"{REPO}/{p}", "rb").read()
            if b'"' + sym + b'"' not in b:
                continue
            mk = code_mask(b, heredoc=True)
            cb = bytes(ch if mk[i] else 32 for i, ch in enumerate(b))
            if (re.search(rb'\b(?:call_out|start_call_out)\s*\(', cb)
                    and not re.search(rb'\b' + sym + rb'\s*\(', cb)):
                col.add("skill-dead-callout", p, f"{rel} calls undefined call_out(\"{sym.decode()}\")")


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
                "has_es2_dbase": (
                    os.path.isfile(f"{REPO}/libs/{slug}/work/feature/dbase.lpc")
                    or os.path.isfile(f"{REPO}/libs/{slug}/work/inherit/dbase.lpc")
                    or os.path.isfile(f"{REPO}/libs/{slug}/work/include/dbase.h")
                ),
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
