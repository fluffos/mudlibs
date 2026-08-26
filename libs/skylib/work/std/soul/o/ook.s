(ook
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You ook.")
      (rest "$mcname$ ooks.")
    )
    (arguments
      (arguments happily,like the librarian,manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,#)
      (self "You ook $arg$.")
      (rest "$mcname$ ooks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ook at $hcname$.")
      (target "$mcname$ ooks at you.")
      (rest  "$mcname$ ooks at $hcname$.")
    )
    (arguments
      (arguments  happily,like the librarian,manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,wryly,sceptically,#)
      (self   "You ook $arg$ at $hcname$.")
      (target "$mcname$ ooks $arg$ at you.")
      (rest  "$mcname$ ooks $arg$ at $hcname$.")
    )
  )
)
/* Hobbes, 961216 */
