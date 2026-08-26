(grunt
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You grunt.")
      (rest "$mcname$ grunts.")
    )
    (arguments
      (arguments loudly,evilly,wickedly,insanely,mischievously,
        devilishly,impishly,cheekily,idiotically,tentatively,wryly,
        sceptically,softly,#)
      (self "You grunt $arg$.")
      (rest "$mcname$ grunts $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You grunt at $hcname$.")
      (target "$mcname$ grunts at you.")
      (rest  "$mcname$ grunts at $hcname$.")
    )
    (arguments
      (arguments  loudly,evilly,wickedly,insanely,mischievously,
        devilishly,impishly,cheekily,idiotically,wryly,
        sceptically,softly,#)
      (self   "You grunt $arg$ at $hcname$.")
      (target "$mcname$ grunts $arg$ at you.")
      (rest  "$mcname$ grunts $arg$ at $hcname$.")
    )
  )
)
