(grin
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You grin.")
      (rest "$mcname$ grins.")
    )
    (arguments
      (arguments manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,#)
      (self "You grin $arg$.")
      (rest "$mcname$ grins $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You grin at $hcname$.")
      (target "$mcname$ grins at you.")
      (rest  "$mcname$ grins at $hcname$.")
    )
    (arguments
      (arguments  manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,wryly,sceptically,#)
      (self   "You grin $arg$ at $hcname$.")
      (target "$mcname$ grins $arg$ at you.")
      (rest  "$mcname$ grins $arg$ at $hcname$.")
    )
  )
)

