(wobble
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wobble.")
      (rest "$mcname$ wobbles.")
    )
    (arguments
      (arguments  manically,around a bit,like jelly,constantly,annoyingly,
         around,up,down,sideways, evilly,wickedly,insanely,mischievously,
       devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,#)
      (self "You wobble $arg$.")
      (rest "$mcname$ wobbles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wobble at $hcname$.")
      (target "$mcname$ wobbles at you.")
      (rest  "$mcname$ wobbles at $hcname$.")
    )
     (arguments
      (arguments  manically,around a bit,like jelly,constantly,annoyingly,
        around,up,down,sideways,evilly,wickedly,insanely,mischievously,
        devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,#)
      (self   "You wobble $arg$ at $hcname$.")
      (target "$mcname$ wobbles $arg$ at you.")
      (rest  "$mcname$ wobbles $arg$ at $hcname$.")
    )
  )
)

