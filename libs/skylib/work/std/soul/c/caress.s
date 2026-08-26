(caress
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You caress $hcname$.")
      (target "$mcname$ caresses you.")
      (rest  "$mcname$ caresses $hcname$.")
    )
    (arguments
      (arguments  gently, strangely, violently, firmly, seductively,
                  suggestively, slightly, sensually, reluctantly, politely,
                  lovingly, vigorously, eagerly, vivaciously)
      (self   "You caress $hcname$ $arg$.")
      (target "$mcname$ caresses you $arg$.")
      (rest  "$mcname$ caresses $hcname$ $arg$.")
    )
    (arguments
      (arguments  ear, nose, cheek, hand, forehead, eyebrow,
                  finger, foot, toe, fingernail, arm, thigh,
                  upper thigh, calf, elbow, knee, fingers, neck,
                  shoulder, palm, toes, hair)
      (self   "You caress $mhcname$ $arg$.")
      (target "$mcname$ caresses your $arg$.")
      (rest  "$mcname$ caresses $mhcname$ $arg$.")
    )
  )
)

