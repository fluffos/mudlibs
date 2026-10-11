#!/bin/bash
# scripts/corpus_pass2.sh SLUG...  (curator tool; outside users want scripts/toolkit_fix.sh)
# Was pass2.sh: -- second-round warning fixers on one lib at a time: scan, apply the diagnostic-driven fixers,
# HEAD-vs-tree load diff of the changed files; commit+push when no regression, else leave the edits for review.
S=${PASS2_DIR:-/tmp/pass2}; mkdir -p "$S"
cd /home/sunyc/src/mudlib || exit 1
for s in "$@"; do
  echo "--- $s $(date +%H:%M)"
  g=$(git ls-files -s libs/$s/work | head -1 | cut -c1-6); [ "$g" = 160000 ] && { echo "  gitlink, skipped"; continue; }
  [ -n "$(git -c core.quotepath=false diff --name-only -- libs/$s/work | grep -E '\.(lpc|h)$')" ] && { echo "  uncommitted source edits, skipped"; continue; }
  ( ulimit -v 16000000; LPCW_CHUNK=1500 python3 -u scripts/lpc_warnings.py $s > $S/p2-$s.txt 2>&1 )
  D=/tmp/lpcw-$s/diagnostics.tsv; [ -f $D ] || { echo "  no diagnostics"; continue; }
  # compiler tests and error-message demos are broken on purpose (lil /single/tests/compiler/fail, Discworld
  # help_topics/error_messages): no fixer may touch them
  grep -avE '/tests?/|/help_topics/error_messages/' $D > $D.f; mv $D.f $D
  cp $D $S/diag-$s.tsv
  n1=$(python3 scripts/lpc_fix_bitwise_bool.py --apply $s $D | tail -1 | awk '{print $1}')
  n2=$(python3 scripts/lpc_fix_return_types.py --apply $s $D | tail -1 | awk '{print $1}')
  n3=$(python3 scripts/lpc_fix_unique_init.py --apply $s $D | tail -1 | awk '{print $1}')
  n4=$(python3 scripts/lpc_fix_unused_init.py $s --apply 2>/dev/null | grep -c '^FIX')
  n5=$(python3 scripts/lpc_move_decl.py $s --apply 2>/dev/null | grep -c '^edited')
  out="按位 & 改逻辑运算 $n1 处，返回类型/原型 $n2 处，NPC+F_UNIQUE 的 init() $n3 个，带初始化的未用局部变量 $n4 个，只在 #if 分支用的声明移进分支 $n5 个文件；"
  echo "  $out"
  rm -rf /tmp/lpcw-$s
  files=$(git -c core.quotepath=false diff --name-only -- libs/$s/work | grep -E '\.lpc$')
  if [ -z "$files" ]; then
    hdrs=$(git -c core.quotepath=false diff --name-only -- libs/$s/work | grep -E '\.h$')
    if [ -n "$hdrs" ]; then
      # a header-only edit has no object of its own to load-check: record it for a hand look, leave the tree clean
      echo "$hdrs" | sed "s/^/$s /" >> $S/header-only.txt; git checkout -- $hdrs
      echo "  header-only edits reverted, listed in $S/header-only.txt"
    else
      echo "  nothing changed"
    fi
    continue
  fi
  echo "$files" | sed "s#^libs/$s/work##; s#\.lpc\$##" > $S/p2-$s.list
  scripts/lpc_listcheck.sh $s $S/p2-$s.list > /dev/null 2>&1
  res=$(python3 scripts/lpc_load_diff.py $s | tail -1); echo "  $res"
  wh=$(grep -ac 'warning:' /tmp/listchunk-$s.head.out); ww=$(grep -ac 'warning:' /tmp/listchunk-$s.work.out)
  rm -rf /tmp/listchunk-$s*
  if echo "$res" | grep -q 'regress 0;'; then
    n=$(echo "$files" | wc -l)
    printf '\n- %s：编译警告第二轮（按驱动报告逐条修）：%s改动 %s 个文件，HEAD 与工作树各载入一次无回退（%s），这些文件的警告 %s -> %s。\n' "$(date +%F)" "$out" "$n" "$(echo $res | sed 's/^[^:]*: //')" "$wh" "$ww" >> libs/$s/NOTES.md
    git commit -q -m "$s: second-round warning fixers ($n files, warnings $wh -> $ww in them)

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>" -- libs/$s/NOTES.md $(git -c core.quotepath=false diff --name-only -- libs/$s/work | grep -E '\.(lpc|h)$') && git push -q origin main 2>&1 | grep -iv 'dependabot\|vulnerab\|^remote: *$'
    echo "  committed $(git log --oneline -1 | cut -c1-12)"
  else
    echo "  NEEDS REVIEW (edits left in the tree)"
  fi
done
echo PASS2 DONE
