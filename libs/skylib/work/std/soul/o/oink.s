(oink
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You oink.")
      (rest "$mcname$ oinks.")
    )
    (arguments
      (arguments happily,like a pig,manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,#)
      (self "You oink $arg$.")
      (rest "$mcname$ oinks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You oink at $hcname$.")
      (target "$mcname$ oinks at you.")
      (rest  "$mcname$ oinks at $hcname$.")
    )
    (arguments
      (arguments  happily,like a pig,manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,wryly,sceptically,#)
      (self   "You oink $arg$ at $hcname$.")
      (target "$mcname$ oinks $arg$ at you.")
      (rest  "$mcname$ oinks $arg$ at $hcname$.")
    )
  )
)
/* Hobbes, 961216 */
