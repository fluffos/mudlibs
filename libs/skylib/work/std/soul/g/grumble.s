(grumble
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You grumble.")
      (rest "$mcname$ grumbles.")
    )
    (arguments
      (arguments
         quietly,bitterly,menacingly,halfheartedly,seductively,suggestively,loudly,
         annoyingly,devastatingly,carefully,wildly,more or less,         
         silently,sarcastically,falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,#)
      (self "You grumble $arg$.")
      (rest "$mcname$ grumbles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You grumble at $hcname$.")
      (target "$mcname$ grumbles at you.")
      (rest  "$mcname$ grumbles at $hcname$.")
    )
    (arguments
      (arguments
         quietly,bitterly,menacingly,halfheartedly,seductively,suggestively,loudly,
         annoyingly,devastatingly,carefully,wildly,more or less,
         silently,sarcastically,falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,#)
      (self   "You grumble $arg$ at $hcname$.")
      (target "$mcname$ grumbles $arg$ at you.")
      (rest  "$mcname$ grumbles $arg$ at $hcname$.")
    )
  )
)

