(titter
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You titter.")
      (rest "$mcname$ titters.")
    )
    (arguments
      (arguments
         quietly,silently,sarcastically,falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,#)
      (self "You titter $arg$.")
      (rest "$mcname$ titters $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You titter at $hcname$.")
      (target "$mcname$ titters at you.")
      (rest  "$mcname$ titters at $hcname$.")
    )
    (arguments
      (arguments
         quietly,silently,sarcastically,falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,#)
      (self   "You titter $arg$ at $hcname$.")
      (target "$mcname$ titters $arg$ at you.")
      (rest  "$mcname$ titters $arg$ at $hcname$.")
    )
  )
)

