(shine
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments on like a crazy diamond, brightly, happily, mischievously,
                 cheekily, idiotically, wryly, sceptically, derisively,
                 annoyingly, absentmindedly, whilst you work, distractedly,
                 pointlessly, silently, loudly, rudely, with laughter,
                 vaguely, obviously, like a sun, like Magpie, blindingly,
                 innocently, proudly, charmingly, seductively, # )
      (self "You shine $arg$.")
      (rest "$mcname$ shines $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments on like a crazy diamond, brightly, happily, mischievously,
                 cheekily, idiotically, wryly, sceptically, derisively,
                 annoyingly, absentmindedly, whilst you work, distractedly,
                 pointlessly, silently, loudly, rudely, with laughter,
                 vaguely, obviously, like a sun, like Magpie, blindingly,
                 innocently, proudly, charmingly, seductively, # )
      (self   "You shine $arg$ at $hcname$.")
      (target "$mcname$ shines $arg$ at you.")
      (rest  "$mcname$ shines $arg$ at $hcname$.")
    )
  )
)
