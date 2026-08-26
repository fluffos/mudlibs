(twinkle
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You twinkle like a star.")
      (rest "$mcname$ twinkles like a star.")
    )
    (arguments
      (arguments brightly,lovely,happily,mischievously,
                 cheekily,idiotically,wryly,sceptically,
                 derisively,annoyingly,absentmindedly,whilst you work,
                 distractedly,pointlessly,like Josie,
                 silently,loudly,rudely,with laughter,vaguely,obviously,#)
      (self "You twinkle $arg$.")
      (rest "$mcname$ twinkles $arg$.")
    )
  )
  (targeted
      (arguments
      (arguments like a star,brightly,lovely,happily,mischievously,
                 cheekily,idiotically,wryly,sceptically,
                 derisively,annoyingly,absentmindedly,whilst you work,
                 distractedly,pointlessly,like Josie,
                 silently,loudly,rudely,with laughter,vaguely,obviously,#)
      (self   "You twinkle $arg$ at $hcname$.")
      (target "$mcname$ twinkles $arg$ at you.")
      (rest  "$mcname$ twinkles $arg$ at $hcname$.")
    )
  )
)

