(tweak
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  bottom, ear, arm, leg, nose, bits, eyebrow, arm,
                  leg, thigh, elbow, cheeks, nose, ear, knee, #)
      (self   "You tweak $mhcname$ $arg$.")
      (target "$mcname$ tweaks your $arg$.")
      (rest  "$mcname$ tweaks $mhcname$ $arg$.")
    )
  )
)
