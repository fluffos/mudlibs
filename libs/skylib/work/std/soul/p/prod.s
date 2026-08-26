(prod
  (pattern "[at] <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (targeted
      (no-arguments
          (self "You prod $hcname$.")
          (target "$mcname$ prods you.")
          (rest "$mcname$ prods $hcname$.")
      )
      (arguments
          (arguments with a stick, cautiously, happily, mischievously,
                     cheekily, idiotically, wryly, sceptically,
                     derisively, annoyingly, absentmindedly,
                     whilst you work, distractedly, pointlessly,
                     silently, loudly, rudely, with laughter,
                     vaguely, obviously, #)
          (self   "You prod $hcname$ $arg$.")
          (target "$mcname$ prods you $arg$.")
          (rest  "$mcname$ prods $hcname$ $arg$.")
    )
  )
)

