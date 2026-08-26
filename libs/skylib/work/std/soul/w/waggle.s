(waggle
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [at] <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You waggle your finger.")
      (rest "$mcname$ waggles $mposs$ finger.")
    )
    (arguments
      (arguments arm, leg, head, nose, ear, frog, pinky, eyebrows, toe, #)
      (self "You waggle your $arg$.")
      (rest "$mcname$ waggles $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "What did $hcname$ do wrong?")
      (target "$mcname$ waggles $mposs$ finger at you.")
      (rest   "$mcname$ waggles $mposs$ finger at $hcname$.")
    )
    (arguments
      (arguments arm, leg, head, nose, ear, frog, pinky, eyebrows, toe, #)
      (self   "You waggle your $arg$ at $hcname$.")
      (target "$mcname$ waggles $mposs$ $arg$ at you.")
      (rest   "$mcname$ waggles $mposs$ $arg$ at $hcname$.")
    )
  )
)

