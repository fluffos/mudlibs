#!/usr/bin/env python3
"""Organize archives/ into one file per unique archive and write its manifest.

Every distinct archive (by SHA-256) is stored once, as
    archives/NNN[-M]_<slug>_<original-name>
with NNN/slug taken from the *current* catalog (scripts/lib_numbering.json),
not from whatever prefix an older rename left on the file.  Byte-identical
copies are dropped; every name a copy was ever seen under is kept in the
manifest's `original_names` column, so nothing about provenance is lost.

Inputs:
  archives/                 the local store (gitignored)
  --bundle DIR              extra loose files to take in, e.g. the extracted
                            members of a bulk upload such as mudlib.rar
  --bundle-name NAME        provenance label for --bundle files

Outputs (with --apply):
  archives/<renamed files>
  archives/MANIFEST.tsv, archives/SHA256SUMS   (travel with the store)
  scripts/archives_manifest.tsv                (committed copy)

Dry-run by default: prints the plan and any unresolved/colliding entries.
Original bytes are never re-encoded; this is a preservation store.
"""
import argparse, collections, csv, hashlib, json, os, re, shutil, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ARCH = os.path.join(ROOT, 'archives')
OUT_FILES = {'MANIFEST.tsv', 'SHA256SUMS'}
EXT = r'\.(rar|zip|7z|gz|tgz|z|exe|bz2|tar|xz)$'

# Archives the catalog cannot place by name.  Keyed by original filename,
# or by full SHA-256 where one name covers two different files.
# status "purged": lib removed from the catalog in 289dd6de041, archive kept.
OVERRIDES = {
    '东方故事I屠龙战记WIN98版.rar': ('069', 'dfgsitlzjwin', 'purged'),
    'hell - 修改.7z': ('140', 'hellxg', 'purged'),
    '火影 (2).rar': ('078', 'hy2', 'purged'),
    'foundationI_fluffos_v1.zip': ('174-1', None, None),
    'lima_fluffos_v1.zip': ('164', None, None),
    # mudbytes.net download endpoints carry no filename in the catalog
    'dsII.zip': ('006-2', None, None),
    'ds3.0.zip': ('006-3', None, None),
    # ftp.lysator.liu.se Amylaar/minilib was a bare directory; packed 2026-10-10
    'minilib.tar.gz': ('962', None, None),
    # two different uploads both named 重出江湖.rar
    '77d74b83390bffafabf54a9f09f4a60da6e152c56c049022b5f93e478c2f03a0': ('905', None, None),
    '7e042621905f9c147d48ed31479b8196b4d56b7bd852d1f0093c3a4a11382b44': ('905-3', None, None),
    # 终极地狱.rar in mudlib.rar is 终极地狱2008完整版.rar under a shorter name
    'a588713cd9d8f561cee758e94fba7914ad159dea3acf70fde4d4485ef3293d8e': ('136', None, None),
}
COPY_MARK = re.compile(r' +\(\d+\)(?=\.[^.]+$)')  # browser re-download marker


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()


def numkey(n):
    a, _, b = n.partition('-')
    return (int(a), int(b or 0))


def load_catalog():
    libs = json.load(open(os.path.join(ROOT, 'scripts/lib_numbering.json')))['libs']
    bynum = {e['number']: e for e in libs}
    byarch = collections.defaultdict(set)
    for e in libs:
        a = e.get('archive') or ''
        names = {a} | {t for t in re.split(r'[;,]?\s+|/', a) if re.search(EXT, t, re.I)}
        # git-sourced libs are stored as `git bundle`s named <owner>-<repo>.bundle
        for m in re.finditer(r'(?:github\.com/|gh repo clone )([\w.-]+)/([\w-]+(?:\.[\w-]+)*?)(?:\.git)?(?=[\s/),;]|$)', a):
            names.add(f'{m.group(1)}-{m.group(2)}.bundle')
        for n in names:
            byarch[n].add(e['number'])
    return bynum, byarch


def old_renames():
    """original name <- prefixed name, from the retired rename_archives.sh."""
    ren = {}
    p = os.path.join(ROOT, 'scripts/rename_archives.sh')
    if os.path.exists(p):
        for line in open(p, encoding='utf-8'):
            m = re.match(r"^rename_one '(.*)' '(.*)'$", line.strip())
            if m:
                ren[m.group(2)] = m.group(1)
    return ren


def strip_prefix(name, bynum):
    """'NNN_slug_orig' -> candidate original names (slug may contain '_')."""
    out = set()
    if re.match(r'^\d{3}(?:-\d+)?_', name):
        parts = name.split('_')
        for k in range(2, len(parts)):
            out.add('_'.join(parts[k:]))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--bundle', action='append', default=[])
    ap.add_argument('--bundle-name', action='append', default=[])
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    bynum, byarch = load_catalog()
    ren = old_renames()
    old_manifest = {}
    mp = os.path.join(ARCH, 'MANIFEST.tsv')
    if os.path.exists(mp):
        for r in csv.DictReader(open(mp, encoding='utf-8'), delimiter='\t'):
            old_manifest[r['sha256']] = r
    # bulk uploads already broken up into the store stay out of it
    containers = {src for r in old_manifest.values() for src in r['sources'].split(' | ')} - {'archives/'}

    # sha -> {paths, names, sources}
    blobs = collections.defaultdict(lambda: {'paths': [], 'names': set(), 'sources': set()})
    for f in sorted(os.listdir(ARCH)):
        p = os.path.join(ARCH, f)
        if f in OUT_FILES or f in a.bundle_name or f in containers or not os.path.isfile(p):
            if os.path.isdir(p):
                print(f'WARNING: loose directory archives/{f}/ is not stored; pack it first', file=sys.stderr)
            continue
        h = sha256(p)
        b = blobs[h]
        b['paths'].append(p)
        prev = old_manifest.get(h)
        if prev:
            b['names'] |= set(filter(None, prev['original_names'].split(' | ')))
            b['sources'] |= set(filter(None, prev['sources'].split(' | ')))
        else:
            b['names'] |= {ren.get(f, f)} if f in ren else ({f} if not strip_prefix(f, bynum) else set())
            b['sources'].add('archives/')
        b.setdefault('cands', set()).update({f, ren.get(f, f)} | strip_prefix(f, bynum))
    for i, d in enumerate(a.bundle):
        label = a.bundle_name[i] if i < len(a.bundle_name) else os.path.basename(d.rstrip('/'))
        for f in sorted(os.listdir(d)):
            p = os.path.join(d, f)
            if not os.path.isfile(p):
                continue
            h = sha256(p)
            b = blobs[h]
            b['paths'].append(p)
            b['names'].add(f)
            b['sources'].add(label)
            b.setdefault('cands', set()).add(f)

    plan, problems = [], []
    for h, b in blobs.items():
        cands = b['cands'] | b['names']
        ov = OVERRIDES.get(h) or next((OVERRIDES[n] for n in cands if n in OVERRIDES), None)
        status = None
        if ov:
            num, slug, status = ov
            slug = slug or bynum[num]['slug']
            nums = [num]
        else:
            nums = set()
            # a file already carrying a current NNN_slug_ prefix was placed on purpose
            for p in b['paths']:
                f = os.path.basename(p)
                m = re.match(r'^(\d{3}(?:-\d+)?)_(.+)$', f)
                if m and m.group(1) in bynum and m.group(2).startswith(bynum[m.group(1)]['slug'] + '_'):
                    nums.add(m.group(1))
            if not nums:
                for n in cands:
                    nums |= byarch.get(n, set())
            nums = sorted(nums, key=lambda n: (bynum[n].get('duplicate_of') is not None, numkey(n)))
            if not nums:
                problems.append(f'UNPLACED {sorted(cands)}')
                continue
            num, slug = nums[0], bynum[nums[0]]['slug']
        status = status or bynum[num].get('wasm_status') or ''
        # other catalog entries built from the very same upload
        alias = set()
        for n in ([] if ov else b['names']):  # overrides exist because the name misleads
            alias |= byarch.get(n, set())
        nums = sorted(set(nums) | alias, key=numkey)
        if not b['names']:
            b['names'] = {n for n in b['cands'] if n in byarch or n in OVERRIDES}
        if not b['names']:
            problems.append(f'UNPLACED (no original name) {sorted(b["cands"])}')
            continue
        catname = (bynum.get(num) or {}).get('archive') or ''
        names = sorted(b['names'], key=lambda n: (n != catname, bool(COPY_MARK.search(n)), len(n), n))
        orig = COPY_MARK.sub('', names[0])
        plan.append(dict(file=f'{num}_{slug}_{orig}', raw=f'{num}_{slug}_{names[0]}', sha256=h, size=os.path.getsize(b['paths'][0]),
                         number=num, slug=slug, also=' '.join(n for n in nums if n != num),
                         status=status, original_names=' | '.join(sorted(b['names'])),
                         sources=' | '.join(sorted(b['sources'])), paths=b['paths']))

    # distinct files must not land on one name
    byfile = collections.defaultdict(list)
    for r in plan:
        byfile[r['file']].append(r)
    for f, rs in byfile.items():
        if len(rs) > 1 and len({r['raw'] for r in rs}) == len(rs):
            for r in rs:
                r['file'] = r['raw']
        elif len(rs) > 1:
            for k, r in enumerate(sorted(rs, key=lambda r: r['size']), 1):
                stem, ext = re.match(r'^(.*?)((?:\.tar)?\.[^.]+)$', f).groups()
                r['file'] = f'{stem}.v{k}{ext}'
            problems.append(f'NAME COLLISION {f}: kept all {len(rs)} as .vN')
    plan.sort(key=lambda r: (numkey(r['number']), r['file']))

    moves = dups = 0
    for r in plan:
        dst = os.path.join(ARCH, r['file'])
        keep = dst if dst in r['paths'] else next((p for p in r['paths'] if os.path.dirname(p) == ARCH), r['paths'][0])
        if keep != dst:
            moves += 1
            print(f"{'mv' if os.path.dirname(keep) == ARCH else 'cp'}  {os.path.relpath(keep, ROOT)} -> {r['file']}")
        for p in r['paths']:
            if p not in (keep, dst) and os.path.dirname(p) == ARCH:
                dups += 1
                print(f'dup {os.path.relpath(p, ROOT)} (same bytes as {r["file"]})')
        r['_keep'] = keep
    for line in problems:
        print(line, file=sys.stderr)
    print(f'{len(plan)} unique archives, {sum(r["size"] for r in plan)/1e9:.2f} GB; '
          f'{moves} to place, {dups} duplicate copies to drop', file=sys.stderr)
    if not a.apply:
        print('dry run; pass --apply', file=sys.stderr)
        return
    if any(p.startswith('UNPLACED') for p in problems):
        sys.exit('refusing to apply with unplaced archives; add OVERRIDES')

    for r in plan:
        dst = os.path.join(ARCH, r['file'])
        if r['_keep'] != dst:
            if os.path.exists(dst):
                sys.exit(f'target exists: {dst}')
            if os.path.dirname(r['_keep']) == ARCH:
                os.rename(r['_keep'], dst)
            else:
                shutil.copy2(r['_keep'], dst)
        if sha256(dst) != r['sha256']:
            sys.exit(f'hash mismatch after placing {dst}')
        for p in r['paths']:
            if p != dst and os.path.dirname(p) == ARCH and os.path.exists(p):
                assert sha256(p) == r['sha256']
                os.remove(p)
    cols = ['file', 'sha256', 'size', 'number', 'slug', 'also', 'status', 'original_names', 'sources']
    for out in (os.path.join(ARCH, 'MANIFEST.tsv'), os.path.join(ROOT, 'scripts/archives_manifest.tsv')):
        with open(out, 'w', encoding='utf-8', newline='') as f:
            w = csv.DictWriter(f, cols, delimiter='\t', extrasaction='ignore', lineterminator='\n')
            w.writeheader()
            w.writerows(plan)
    with open(os.path.join(ARCH, 'SHA256SUMS'), 'w', encoding='utf-8') as f:
        for r in plan:
            f.write(f"{r['sha256']}  {r['file']}\n")
    print('applied', file=sys.stderr)


if __name__ == '__main__':
    main()
