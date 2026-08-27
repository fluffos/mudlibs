#!/usr/bin/env bash
# Merge-queue guard for the parallel WASM-enablement/verification/bring-up
# batches. All batch agents share ONE working tree (no per-agent worktrees),
# so several of them can have unstaged edits sitting in libs/<slug>/ at the
# same time. Before committing any one batch's work, this script stages
# ONLY that batch's own lib paths and refuses to proceed if anything else
# ends up staged -- e.g. because a batch's assigned lib list was wrong, or
# because `git add` was given a glob that reached outside it.
#
# Usage:
#   scripts/safe_commit_batch.sh [--dry-run] <slug1> [slug2 ...] -- <commit message file>
#
# --dry-run: stage and validate as normal, print what WOULD be committed,
# then unstage and exit 0 without committing or pushing. Use this to check
# a batch's isolation before it's actually ready to land.
#
# Behavior:
#   1. `git reset` (unstage everything -- start from a clean index so a
#      leftover stage from a previous run/batch can't ride along).
#   2. `git add libs/<slug>/` for each slug given (only these paths, plus
#      any extra paths listed after a literal `+` argument, e.g. shared
#      README.md/AGENTS.md edits belonging to this same batch).
#   3. Verify every staged path falls under one of the allowed prefixes.
#      Any violation aborts: unstages everything and exits 1 WITHOUT
#      committing, printing the offending paths so the orchestrator can
#      investigate (most likely cause: another batch's in-flight edit to
#      a lib that should have been exclusive to it).
#   4. Commit with the message file, then `git push origin main`.
#
# This is a safety guard, not a lock -- it does not stop a second batch
# from writing to disk concurrently. It only stops the ORCHESTRATOR from
# accidentally sweeping a concurrent batch's unfinished edits into a
# commit meant for a different batch. Only the orchestrator (not batch
# agents themselves) runs this script; batch agents are read-only w.r.t.
# git by standing policy.

set -euo pipefail

slugs=()
extra_paths=()
msg_file=""
dry_run=0

mode=slugs
for arg in "$@"; do
  case "$arg" in
    --dry-run)
      dry_run=1
      continue
      ;;
    --)
      mode=msgfile
      continue
      ;;
    +)
      mode=extra
      continue
      ;;
  esac
  case "$mode" in
    slugs) slugs+=("$arg") ;;
    extra) extra_paths+=("$arg") ;;
    msgfile)
      if [ -z "$msg_file" ]; then
        msg_file="$arg"
      else
        echo "error: multiple commit-message-file arguments given after --" >&2
        exit 1
      fi
      ;;
  esac
done

if [ "${#slugs[@]}" -eq 0 ] || { [ -z "$msg_file" ] && [ "$dry_run" -eq 0 ]; }; then
  echo "usage: $0 [--dry-run] <slug1> [slug2 ...] [+ extra_path1 [extra_path2 ...]] -- <commit-message-file>" >&2
  exit 1
fi

if [ "$dry_run" -eq 0 ] && [ ! -f "$msg_file" ]; then
  echo "error: commit message file '$msg_file' not found" >&2
  exit 1
fi

repo_root=$(git rev-parse --show-toplevel)
cd "$repo_root"

echo "== resetting index (unstage everything) =="
git reset >/dev/null

allowed_prefixes=()
for slug in "${slugs[@]}"; do
  if [ ! -d "libs/$slug" ]; then
    echo "error: libs/$slug does not exist -- refusing to guess" >&2
    exit 1
  fi
  allowed_prefixes+=("libs/$slug/")
  git add "libs/$slug/"
done

for p in "${extra_paths[@]}"; do
  allowed_prefixes+=("$p")
  git add "$p"
done

staged=$(git -c core.quotePath=false diff --cached --name-only)
if [ -z "$staged" ]; then
  echo "error: nothing staged for slugs: ${slugs[*]} (already committed, or no changes present?)" >&2
  git reset >/dev/null
  exit 1
fi

violations=()
while IFS= read -r f; do
  [ -z "$f" ] && continue
  ok=0
  for prefix in "${allowed_prefixes[@]}"; do
    case "$f" in
      "$prefix"*|"$prefix") ok=1; break ;;
    esac
  done
  if [ "$ok" -eq 0 ]; then
    violations+=("$f")
  fi
done <<< "$staged"

if [ "${#violations[@]}" -gt 0 ]; then
  echo "!! REFUSING TO COMMIT -- staged content outside this batch's owned paths:" >&2
  printf '   %s\n' "${violations[@]}" >&2
  echo "!! unstaging everything. Investigate before retrying (likely another" >&2
  echo "!! batch's in-flight edit under one of: ${allowed_prefixes[*]})" >&2
  git reset >/dev/null
  exit 1
fi

echo "== staged files (all within owned paths) =="
echo "$staged"

if [ "$dry_run" -eq 1 ]; then
  echo "== --dry-run: unstaging, no commit/push made =="
  git reset >/dev/null
  exit 0
fi

echo "== committing =="
git commit -F "$msg_file"
echo "== pushing =="
git push origin main
