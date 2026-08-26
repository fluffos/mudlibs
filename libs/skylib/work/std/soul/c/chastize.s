(chastize
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You chastize $hcname$.")
      (target "$mcname$ chastizes you.")
      (rest  "$mcname$ chastizes $hcname$.")
    )
    (arguments
      (arguments  loudly,insistently,argumentatively,unmercifully,unexpectedly,enthusiastically,calmly,rationally,insanely,madly,lovingly,politely,suggestively,eagerly,reluctantly,firmly,excitedly,understandably,irrationally,imaginatively,destructively,cunningly,thoughtlessly,carefully,offhandedly,absolutely)
      (self   "You chastize $hcname$ $arg$.")
      (target "$mcname$ chastizes you $arg$.")
      (rest  "$mcname$ chastizes $hcname$ $arg$.")
    )
  )
)

