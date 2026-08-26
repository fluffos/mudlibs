(applaud
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments wholeheartedly,loudly,softly,vaguely,briefly)
      (self "You applaud $arg$.")
      (rest "$mcname$ applauds $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  wholeheartedly,loudly,softly,vaguely,briefly)
      (self   "You applaud $hcname$ $arg$.")
      (target "$mcname$ applauds you $arg$.")
      (rest  "$mcname$ applauds $hcname$ $arg$.")
    )
  )
)

