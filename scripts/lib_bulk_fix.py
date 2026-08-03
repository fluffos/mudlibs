"""Apply known, exact-literal-match-only bug fixes (see AGENTS.md's
catalog) across every converted-but-not-yet-individually-fixed lib:
the §8.1 GBK is_chinese() bug, the §4.3 nosave/protected shim
collision, the §7.3 master.lpc SIMUL_EFUN_OB destruct-on-create
segfault, excluding actively-preloaded dns_master/ftpd, the §6.6
convertd.lpc Greek-table stray-backslash typo, absolute-path
`#include </...>` (never resolves under this driver's include-directories
search -- rewritten to a quoted include, which always resolves), and the
§7.12 two-arg tell_room() wrapper's bare-int-0 exclude default crashing
message(). Every fix is an EXACT string/structural (or, for the
convertd/include fixes, a narrowly-scoped regex) match, so it silently
no-ops (never mis-fires) on any file that differs even slightly -- those
need individual attention via the fuller AGENTS.md catalog instead.

Note: exclude_network_preload's dns_master/ftpd comment-out is a
conservative FIRST pass for libs not yet individually triaged. If a
later WASM pass gives dns_master.lpc the full §7.52 socket-gut treatment
(making its own preload-time init safe), re-enable its preload line by
hand -- this script does not know to undo its own earlier edit (see
xyj2000's WASM-pass commit for the bug this causes if left disabled).

Usage: python3 scripts/lib_bulk_fix.py
Output: scripts/lib_bulk_fix_results.json (per-lib counts of what
was touched).
"""
import os, re, json

MUDLIB_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
STATUS_FILE = os.path.join(MUDLIB_ROOT, "scripts", "lib_bulk_fix_results.json")

SLUGS = sorted(
    s for s in os.listdir(LIBS_DIR)
    if os.path.isdir(os.path.join(LIBS_DIR, s, 'work'))
)

def read(path):
    with open(path, encoding='utf-8', errors='surrogateescape') as f:
        return f.read()

def write(path, content):
    with open(path, 'w', encoding='utf-8', errors='surrogateescape') as f:
        f.write(content)

def find_files(work, basenames):
    found = []
    for dirpath, dirnames, filenames in os.walk(work):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            if fn.lower() in basenames:
                found.append(os.path.join(dirpath, fn))
    return found

def strip_cr(work):
    n = 0
    for dirpath, dirnames, filenames in os.walk(work):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            if not (fn.endswith('.lpc') or fn.endswith('.h')):
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                content = read(fpath)
            except Exception:
                continue
            if '\r' in content:
                write(fpath, content.replace('\r', ''))
                n += 1
    return n

# Confirmed byte-identical across every instance fixed by hand this session
# (yinhexiongxiongchuanshuo, ludingtianxia, hongchen) -- exact literal
# replacement only, so this silently no-ops (not mis-fires) on any file
# that differs even slightly; those need individual attention instead.
ISCHINESE_VARIANTS = [
    ("if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;\n\treturn 0;\n}",
     "if( strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff ) return 1;\n\treturn 0;\n}"),
]

def fix_is_chinese(work):
    fixed = []
    for f in find_files(work, {'chinese.c', 'chinese.lpc'}):
        try:
            content = read(f)
        except Exception:
            continue
        new_content = content
        hit = False
        for old, new in ISCHINESE_VARIANTS:
            if old in new_content:
                new_content = new_content.replace(old, new)
                hit = True
        if hit:
            write(f, new_content)
            fixed.append(f)
    return fixed

def fix_master_destruct(work):
    """AGENTS.md §7.3: old MudOS force-reload trick segfaults this driver
    -- only touches create() bodies that both destruct() something AND
    reference SIMUL_EFUN_OB (the specific documented pattern), not any
    destruct() call anywhere (e.g. connect()'s error-path destruct is
    left alone)."""
    fixed = []
    for f in find_files(work, {'master.c', 'master.lpc'}):
        try:
            content = read(f)
        except Exception:
            continue
        m = re.search(r'void\s+create\s*\(\s*\)\s*\{[^{}]*\}', content, re.DOTALL)
        if not m:
            continue
        body = m.group(0)
        if 'destruct' in body and 'SIMUL_EFUN_OB' in body:
            new_body = "void create()\n{\n\twrite(\"master: loaded successfully.\\n\");\n}\n"
            new_content = content[:m.start()] + new_body + content[m.end():]
            write(f, new_content)
            fixed.append(f)
    return fixed

def fix_shim_collision(work):
    fixed = []
    for dirpath, dirnames, filenames in os.walk(work):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            if not (fn.endswith('.lpc') or fn.endswith('.h')):
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                content = read(fpath)
            except Exception:
                continue
            if '#define nosave nosave' not in content and '#define protected nosave' not in content:
                continue
            lines = content.split('\n')
            new_lines = [l for l in lines if l.strip() not in ('#define nosave nosave', '#define protected nosave')]
            if len(new_lines) != len(lines):
                write(fpath, '\n'.join(new_lines))
                fixed.append(fpath)
    return fixed

def fix_convertd_backslash(work):
    """AGENTS.md §6.6: convertd.lpc's Greek-conversion table has a stray
    backslash before the closing quote on ~43-45 lines (`"a\",` for
    `"a\",` -- i.e. `"α\",` should read `"α",`), recurring across the whole
    西游记/ES II family, often fatal (inside simul_efun's compile).
    Exact-shape regex: a double-quoted string ending in `\"` immediately
    followed by an optional comma and line end (CRLF or LF) -- matches
    only the corrupt shape, never a legitimately escaped-quote-at-end
    string (which would need something after it on the same line)."""
    fixed = []
    pat = re.compile(r'\\"(,)?\r?\n')
    for f in find_files(work, {'convertd.c', 'convertd.lpc'}):
        try:
            content = read(f)
        except Exception:
            continue
        new_content, n = pat.subn(lambda m: '"' + (m.group(1) or '') + '\n', content)
        if n:
            write(f, new_content)
            fixed.append((f, n))
    return fixed


def fix_absolute_angle_include(work):
    """This driver's `#include <...>` only searches config.fluffos's
    'include directories' (normally just /include) -- an absolute-path
    `#include </d/foo/bar.h>` never resolves there ("Cannot #include"),
    even though the target file exists. Quoted includes always resolve
    as a literal path from the mudlib root, so rewriting the delimiters
    is a safe, purely mechanical fix (AGENTS.md's xkx100/xkx2017/xyj2006n
    combatd.lpc/jitan.h cases) -- never touches `<net/foo.h>`-style
    relative includes, only ones starting with a literal '/'."""
    fixed = []
    pat = re.compile(r'#include\s*<(/[^>]+)>')
    for dirpath, dirnames, filenames in os.walk(work):
        parts = dirpath.split(os.sep)
        if any(p in ('log', 'save', 'data', 'binaries', '.git') for p in parts):
            continue
        for fn in filenames:
            if not (fn.endswith('.lpc') or fn.endswith('.h')):
                continue
            fpath = os.path.join(dirpath, fn)
            try:
                content = read(fpath)
            except Exception:
                continue
            new_content, n = pat.subn(r'#include "\1"', content)
            if n:
                write(fpath, new_content)
                fixed.append((fpath, n))
    return fixed


def fix_tell_room_exclude(work):
    """AGENTS.md §7.12: a 2-arg tell_room() wrapper forwards its varargs
    `exclude` param straight into message()'s 4th arg; when the caller
    omits it, that's a raw int 0 instead of an array/object, crashing
    with 'Bad argument 4 to EFUN message()' the first time anything
    calls tell_room() with 2 args (very common). Exact-literal shapes
    only, matching every instance fixed by hand this session -- silently
    no-ops on any wrapper whose body differs even slightly (parameter
    name, extra whitespace), which needs individual attention instead."""
    fixed = []
    variants = [
        ('message("tell_room", str, ob, exclude);',
         'message("tell_room", str, ob, exclude || ({}));'),
        ('message("tell_room",str,ob,exclude);',
         'message("tell_room",str,ob,exclude || ({}));'),
    ]
    for f in find_files(work, {'message.c', 'message.lpc'}):
        try:
            content = read(f)
        except Exception:
            continue
        new_content = content
        hit = 0
        for old, new in variants:
            if old in new_content:
                new_content = new_content.replace(old, new)
                hit += 1
        if hit:
            write(f, new_content)
            fixed.append((f, hit))
    return fixed


SOCKET_CALL_RE = re.compile(
    r'\bsocket_(create|bind|listen|accept|connect|write)\s*\(')


def _daemon_still_has_sockets(work, preload_path):
    """preload_path is a mudlib-absolute path with no extension (e.g.
    '/adm/daemons/network/dns_master'). Resolve it to a .lpc/.c file
    under work and check whether it still makes raw socket_*() calls.
    Returns True (assume unsafe -> keep excluding) if the file can't be
    found or read, so this only ever gets MORE conservative on unknowns,
    never less."""
    rel = preload_path.lstrip('/')
    for ext in ('.lpc', '.c'):
        fpath = os.path.join(work, *rel.split('/')) + ext
        if os.path.isfile(fpath):
            content = read(fpath)
            if content is None:
                return True
            return bool(SOCKET_CALL_RE.search(content))
    return True


def exclude_network_preload(work):
    """Comments out dns_master/ftpd preload lines -- but ONLY if that
    daemon still makes raw socket_*() calls. A lib whose dns_master.lpc
    was already individually gutted (AGENTS.md §7.52) needs ITS preload
    line re-ENABLED, not disabled -- disabling a properly-gutted
    dns_master.lpc breaks find_object(DNS_MASTER) checks elsewhere (see
    xyj2000's WASM-pass commit for the exact bug this causes). This
    function must never undo that kind of individual fix."""
    fixed = []
    fpath = os.path.join(work, 'adm', 'etc', 'preload')
    if not os.path.exists(fpath):
        return fixed
    try:
        content = read(fpath)
    except Exception:
        return fixed
    lines = content.split('\n')
    changed = False
    new_lines = []
    for l in lines:
        stripped = l.strip()
        if stripped.startswith('#') or not stripped:
            new_lines.append(l)
            continue
        is_dns_master = 'dns_master' in stripped
        is_ftpd = bool(re.search(r'/ftpd(\.c|\.lpc)?$', stripped))
        if (is_dns_master or is_ftpd) and _daemon_still_has_sockets(work, stripped):
            new_lines.append('#' + l)
            changed = True
        else:
            new_lines.append(l)
    if changed:
        write(fpath, '\n'.join(new_lines))
        fixed.append(fpath)
    return fixed

def main():
    results = {}
    for i, slug in enumerate(SLUGS):
        work = os.path.join(LIBS_DIR, slug, 'work')
        if not os.path.isdir(work):
            continue
        entry = {}
        entry['cr_stripped'] = strip_cr(work)
        entry['is_chinese_fixed'] = [f.replace(work, '') for f in fix_is_chinese(work)]
        entry['master_destruct_fixed'] = [f.replace(work, '') for f in fix_master_destruct(work)]
        entry['shim_fixed'] = [f.replace(work, '') for f in fix_shim_collision(work)]
        entry['preload_fixed'] = [f.replace(work, '') for f in exclude_network_preload(work)]
        entry['convertd_backslash_fixed'] = [
            (f.replace(work, ''), n) for f, n in fix_convertd_backslash(work)]
        entry['absolute_include_fixed'] = [
            (f.replace(work, ''), n) for f, n in fix_absolute_angle_include(work)]
        entry['tell_room_exclude_fixed'] = [
            (f.replace(work, ''), n) for f, n in fix_tell_room_exclude(work)]
        results[slug] = entry
        print(f"[{i+1}/{len(SLUGS)}] {slug}: cr={entry['cr_stripped']} chinese={len(entry['is_chinese_fixed'])} destruct={len(entry['master_destruct_fixed'])} shim={len(entry['shim_fixed'])} preload={len(entry['preload_fixed'])} "
              f"convertd_bs={sum(n for _, n in entry['convertd_backslash_fixed'])} abs_include={sum(n for _, n in entry['absolute_include_fixed'])} tell_room={sum(n for _, n in entry['tell_room_exclude_fixed'])}", flush=True)

    with open(STATUS_FILE, 'w') as f:
        json.dump(results, f, ensure_ascii=False, indent=2)

if __name__ == '__main__':
    main()
