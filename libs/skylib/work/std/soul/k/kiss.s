(kiss
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You kiss $hcname$.")
      (target "$mcname$ kisses you.")
      (rest  "$mcname$ kisses $hcname$.")
    )
    (arguments
      (arguments  softly, passionately, deeply, tenderly, gently,
                  lovingly, lengthily, fishily, carefully, demandingly,
                  sensuously, longingly, hungrily, back, boringly,
                  inattentively, absentmindedly, frogily,
                  in an igloo, on a coffee table, in a shower,
                  slowly, suspiciously, calmly,#)
      (self   "You kiss $hcname$ $arg$.")
      (target "$mcname$ kisses you $arg$.")
      (rest  "$mcname$ kisses $hcname$ $arg$.")
    )
    (arguments
      (arguments  ear, nose, cheek, hand, forehead, eyebrow,
                  finger, foot, toe, fingernail, arm, thigh,
                  upper thigh, calf, elbow, knee, fingers, neck,
                  shoulder, palm, toes)
      (self   "You kiss $mhcname$ $arg$.")
      (target "$mcname$ kisses your $arg$.")
      (rest  "$mcname$ kisses $mhcname$ $arg$.")
    )
    (arguments
      (arguments  girly air, rabbity, scruffy, cabbagey)
      (self   "You give $hcname$ a $arg$ kiss on the cheek.")
      (target "$mcname$ gives you a $arg$ kiss on the cheek.")
      (rest  "$mcname$ gives $hcname$ a $arg$ kiss on the cheek.")
    )
    (arguments
      (arguments  exciting)
      (self   "You give $hcname$ an $arg$ kiss on the cheek.")
      (target "$mcname$ gives you an $arg$ kiss on the cheek.")
      (rest  "$mcname$ gives $hcname$ an $arg$ kiss on the cheek.")
    )
  )
)

