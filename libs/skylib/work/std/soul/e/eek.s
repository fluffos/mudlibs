(eek
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You eek.")
      (rest "$mcname$ eeks.")
    )
    (arguments
      (arguments loudly,in shock,in amazement,in the basement,happily,
               sadly,carefully,brightly,manically,evilly,wickedly,insanely,
               mischievously,devilishly,impishly,cheekily,idiotically,
               tentatively,wryly,sceptically,#)
      (self "You eek $arg$.")
      (rest "$mcname$ eeks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You eek at $hcname$.")
      (target "$mcname$ eeks at you.")
      (rest  "$mcname$ eeks at $hcname$.")
    )
    (arguments
      (arguments loudly,in shock,in amazement,in the basement,happily,
               sadly,carefully,brightly,manically,evilly,wickedly,insanely,
               mischievously,devilishly,impishly,cheekily,idiotically,
               tentatively,wryly,sceptically,#)
      (self   "You eek $arg$ at $hcname$.")
      (target "$mcname$ eeks $arg$ at you.")
      (rest  "$mcname$ eeks $arg$ at $hcname$.")
    )
  )
)

