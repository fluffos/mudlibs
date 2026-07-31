"""Apply known, exact-literal-match-only bug fixes (see AGENTS.md's
catalog) across every converted-but-not-yet-individually-fixed lib:
the §8.1 GBK is_chinese() bug, the §4.3 nosave/protected shim
collision, the §7.3 master.lpc SIMUL_EFUN_OB destruct-on-create
segfault, and excluding actively-preloaded dns_master/ftpd. Every
fix is an EXACT string/structural match, so it silently no-ops
(never mis-fires) on any file that differs even slightly -- those
need individual attention via the fuller AGENTS.md catalog instead.

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

def exclude_network_preload(work):
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
        if 'dns_master' in stripped or re.search(r'/ftpd(\.c|\.lpc)?$', stripped):
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
        results[slug] = entry
        print(f"[{i+1}/{len(SLUGS)}] {slug}: cr={entry['cr_stripped']} chinese={len(entry['is_chinese_fixed'])} destruct={len(entry['master_destruct_fixed'])} shim={len(entry['shim_fixed'])} preload={len(entry['preload_fixed'])}", flush=True)

    with open(STATUS_FILE, 'w') as f:
        json.dump(results, f, ensure_ascii=False, indent=2)

if __name__ == '__main__':
    main()
