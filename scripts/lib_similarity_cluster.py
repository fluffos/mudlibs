"""Group converted mudlibs into framework families and content-similarity
groups, ranked by size. Run lib_fingerprint.py, lib_fingerprint_core.py,
and lib_fingerprint_content.py first to produce their input files.

Two DELIBERATELY separate signals -- they answer different questions
and must not be blended (see AGENTS.md §2.1, which this automates the
manual version of):

- Framework families: anchored on byte-identical `master` files (the
  single strongest, most specific engine-identity signal). Members
  share engine plumbing (master/securityd/dbase/etc) but can have
  almost entirely different game content -- porting a core-file fix
  across a family is safe, porting a content fix is not. Whole-repo
  similarity is USELESS for this: it gets diluted to near-zero by each
  game's thousands of unique room/NPC/item files, badly undercounting
  real engine-sharing (a confirmed-identical pair scored 0.99% by
  whole-repo Jaccard, because both are ~99% unique game content sitting
  on top of the same handful of shared engine files).
- Content-similarity groups: overlap coefficient scoped to ONLY
  kungfu/ (skills/classes) and d/ (rooms/zones/NPCs) -- the actual game
  a player experiences, independent of what engine wrapper it's bolted
  to. High scores here mean two archives are substantially the SAME
  GAME (a re-upload, a site rebrand, a snapshot a version apart), even
  if their master.c files differ (e.g. one was hand-patched). This is
  the signal that answers "is this archive worth processing on its
  own, or is it a repack of one I already have."

Usage: python3 scripts/lib_similarity_cluster.py
Output: scripts/lib_similarity_report.json + a printed summary.
"""
import json, os, itertools
from collections import defaultdict, Counter

FP_FILE = os.path.join(os.path.dirname(__file__), 'lib_fingerprints.json')
CORE_FILE = os.path.join(os.path.dirname(__file__), 'lib_core_fingerprints.json')
CONTENT_FILE = os.path.join(os.path.dirname(__file__), 'lib_content_fingerprints.json')
OUT_JSON = os.path.join(os.path.dirname(__file__), 'lib_similarity_report.json')

CONTENT_OVERLAP_THRESHOLD = 0.50
CONTENT_MIN_FILES = 20  # below this, overlap coefficient is noise (a 2-file
                         # archive matching 2 files elsewhere is a meaningless
                         # 100% "overlap") -- usually a partial patch/diff
                         # repack rather than a real standalone game

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
    with open(CONTENT_FILE) as f:
        content = json.load(f)

    slugs = list(fp.keys())
    sizes = {s: len(fp[s]['hashes']) for s in slugs}
    content_slugs = list(content.keys())
    content_sizes = {s: len(content[s]['hashes']) for s in content_slugs}

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

    # ---- Signal 2: content similarity, scoped to kungfu/ + d/ only ----
    hash_to_slugs = defaultdict(list)
    for s in content_slugs:
        for h in content[s]['hashes']:
            hash_to_slugs[h].append(s)

    pair_intersection = Counter()
    for h, owners in hash_to_slugs.items():
        if len(owners) < 2 or len(owners) > 60:
            continue
        for a, b in itertools.combinations(sorted(owners), 2):
            pair_intersection[(a, b)] += 1

    content_edges = []
    content_pair_info = {}
    for (a, b), inter in pair_intersection.items():
        if min(content_sizes[a], content_sizes[b]) < CONTENT_MIN_FILES:
            continue
        overlap = inter / min(content_sizes[a], content_sizes[b])
        if overlap >= CONTENT_OVERLAP_THRESHOLD:
            content_edges.append((a, b))
            content_pair_info[(a, b)] = round(overlap, 3)

    content_clusters_raw = union_find_cluster(content_slugs, content_edges)
    content_clusters = []
    for root, members in content_clusters_raw.items():
        if len(members) < 2:
            continue
        members_ranked = sorted(members, key=lambda s: -content[s]['file_count'])
        member_set = set(members)
        edges = [
            {'a': a, 'b': b, 'overlap': content_pair_info[(a, b)]}
            for (a, b) in content_pair_info if a in member_set and b in member_set
        ]
        content_clusters.append({
            'size': len(members),
            'canonical': members_ranked[0],
            'members_ranked': [{'slug': s, 'file_count': content[s]['file_count']} for s in members_ranked],
            'evidence_edges': sorted(edges, key=lambda e: -e['overlap']),
        })
    content_clusters.sort(key=lambda c: -c['size'])

    out = {
        'total_libs': len(slugs),
        'framework_families': lineage_clusters,
        'content_similarity_groups': content_clusters,
    }
    with open(OUT_JSON, 'w') as f:
        json.dump(out, f, ensure_ascii=False, indent=2)

    print(f"total libs: {len(slugs)}")
    print(f"\n=== FRAMEWORK FAMILIES (byte-identical master file, {len(lineage_clusters)} families) ===")
    for c in lineage_clusters:
        print(f"\n--- family size {c['size']}, canonical={c['canonical']} ---")
        for m in c['members_ranked']:
            print(f"    {m['slug']:35s} {m['file_count']:6d} files")

    print(f"\n\n=== CONTENT-SIMILARITY GROUPS (kungfu/+d/ only, {len(content_clusters)} groups, overlap>={CONTENT_OVERLAP_THRESHOLD}) ===")
    for c in content_clusters:
        print(f"\n--- group size {c['size']}, canonical={c['canonical']} ---")
        for m in c['members_ranked']:
            print(f"    {m['slug']:35s} {m['file_count']:6d} files")

if __name__ == '__main__':
    main()
