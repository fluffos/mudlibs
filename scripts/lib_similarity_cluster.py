"""Group converted mudlibs into lineage families and near-duplicate
content groups, ranked by size. Run lib_fingerprint.py and
lib_fingerprint_core.py first to produce their input files.

Two signals, reported separately (see AGENTS.md's own manual lineage-
recognition convention in §2.1, which this automates):

- Lineage families: anchored on byte-identical `master` files (the
  single strongest, most specific signal). Members share an engine
  core but can have almost entirely different game content -- porting
  a core-file fix is safe, porting a content fix is not.
- Near-duplicate groups: overlap coefficient (shared files / smaller
  lib's file count) across ALL .c/.lpc files, not just core files.
  High scores mean the two archives are substantially the same
  snapshot (a re-upload, a site-branded repack, a one-file diff).

Usage: python3 scripts/lib_similarity_cluster.py
Output: scripts/lib_similarity_report.json + a printed summary.
"""
import json, os, itertools
from collections import defaultdict, Counter

FP_FILE = os.path.join(os.path.dirname(__file__), 'lib_fingerprints.json')
CORE_FILE = os.path.join(os.path.dirname(__file__), 'lib_core_fingerprints.json')
OUT_JSON = os.path.join(os.path.dirname(__file__), 'lib_similarity_report.json')

DUP_OVERLAP_THRESHOLD = 0.60

def union_find_cluster(slugs, edge_pairs):
    parent = {s: s for s in slugs}
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[rx] = ry
    for a, b in edge_pairs:
        union(a, b)
    clusters = defaultdict(list)
    for s in slugs:
        clusters[find(s)].append(s)
    return clusters

def main():
    with open(FP_FILE) as f:
        fp = json.load(f)
    with open(CORE_FILE) as f:
        core = json.load(f)

    slugs = list(fp.keys())
    sizes = {s: len(fp[s]['hashes']) for s in slugs}

    # ---- Signal 1 (tightened): lineage anchored strictly on master-file hash equality ----
    master_hash = {s: core[s]['master'] for s in slugs if s in core and 'master' in core[s]}
    by_master_hash = defaultdict(list)
    for s, h in master_hash.items():
        by_master_hash[h].append(s)

    master_edges = []
    for h, owners in by_master_hash.items():
        if len(owners) < 2:
            continue
        for a, b in itertools.combinations(sorted(owners), 2):
            master_edges.append((a, b))

    lineage_clusters_raw = union_find_cluster(list(master_hash.keys()), master_edges)
    lineage_clusters = []
    for root, members in lineage_clusters_raw.items():
        if len(members) < 2:
            continue
        members_ranked = sorted(members, key=lambda s: -fp[s]['file_count'])
        lineage_clusters.append({
            'size': len(members),
            'canonical': members_ranked[0],
            'members_ranked': [{'slug': s, 'file_count': fp[s]['file_count']} for s in members_ranked],
            'evidence': 'byte-identical master file (adm/obj/master.c or equivalent)',
        })
    lineage_clusters.sort(key=lambda c: -c['size'])

    # ---- Signal 2: near-duplicate content (overlap coefficient) ----
    hash_to_slugs = defaultdict(list)
    for s in slugs:
        for h in fp[s]['hashes']:
            hash_to_slugs[h].append(s)

    pair_intersection = Counter()
    for h, owners in hash_to_slugs.items():
        if len(owners) < 2 or len(owners) > 60:
            continue
        for a, b in itertools.combinations(sorted(owners), 2):
            pair_intersection[(a, b)] += 1

    dup_edges = []
    dup_pair_info = {}
    for (a, b), inter in pair_intersection.items():
        overlap = inter / min(sizes[a], sizes[b])
        if overlap >= DUP_OVERLAP_THRESHOLD:
            dup_edges.append((a, b))
            dup_pair_info[(a, b)] = round(overlap, 3)

    dup_clusters_raw = union_find_cluster(slugs, dup_edges)
    dup_clusters = []
    for root, members in dup_clusters_raw.items():
        if len(members) < 2:
            continue
        members_ranked = sorted(members, key=lambda s: -fp[s]['file_count'])
        member_set = set(members)
        edges = [
            {'a': a, 'b': b, 'overlap': dup_pair_info[(a, b)]}
            for (a, b) in dup_pair_info if a in member_set and b in member_set
        ]
        dup_clusters.append({
            'size': len(members),
            'canonical': members_ranked[0],
            'members_ranked': [{'slug': s, 'file_count': fp[s]['file_count']} for s in members_ranked],
            'evidence_edges': sorted(edges, key=lambda e: -e['overlap']),
        })
    dup_clusters.sort(key=lambda c: -c['size'])

    out = {
        'total_libs': len(slugs),
        'lineage_families_by_master_hash': lineage_clusters,
        'near_duplicate_groups': dup_clusters,
    }
    with open(OUT_JSON, 'w') as f:
        json.dump(out, f, ensure_ascii=False, indent=2)

    print(f"total libs: {len(slugs)}")
    print(f"\n=== LINEAGE FAMILIES (byte-identical master file, {len(lineage_clusters)} families) ===")
    for c in lineage_clusters:
        print(f"\n--- family size {c['size']}, canonical={c['canonical']} ---")
        for m in c['members_ranked']:
            print(f"    {m['slug']:35s} {m['file_count']:6d} files")

    print(f"\n\n=== NEAR-DUPLICATE CONTENT GROUPS ({len(dup_clusters)} groups, overlap>={DUP_OVERLAP_THRESHOLD}) ===")
    for c in dup_clusters:
        print(f"\n--- group size {c['size']}, canonical={c['canonical']} ---")
        for m in c['members_ranked']:
            print(f"    {m['slug']:35s} {m['file_count']:6d} files")

if __name__ == '__main__':
    main()
