(fondle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You fondle $hcname$.")
      (target "$mcname$ fondles you.")
      (rest   "$mcname$ fondles $hcname$.")
    )
    (arguments
      (arguments  hand, leg, knee, foot, finger, ear, hair,
                  soft curvaceous pillows, tree trunk, strawberries,
                  eyebrows, nose, cucumber, melons, coconuts, #)
      (self   "You fondle $mhcname$ $arg$.")
      (target "$mcname$ fondles your $arg$.")
      (rest   "$mcname$ fondles $mhcname$ $arg$.")
    )
  )
)

