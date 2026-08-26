(lick
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You lick your lips.")
      (rest "$mcname$ licks $mposs$ lips.")
    )
    (arguments
      (arguments sensuously, seductively, expectantly, carefully, suggestively,
                 hungrily)
      (self "You lick your lips $arg$.")
      (rest "$mcname$ licks $mposs$ lips $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You lick $hcname$.")
      (target "$mcname$ licks you.")
      (rest  "$mcname$ licks $hcname$.")
    )
    (arguments
      (arguments  carefully, lustily, excitedly, slowly, quickly, happily,
                  silently, loudly, absentmindedly, hungrily, clean,
                  quietly,
                  fondly, passionately, suggestively)
      (self   "You lick $hcname$ $arg$.")
      (target "$mcname$ licks you $arg$.")
      (rest  "$mcname$ licks $hcname$ $arg$.")
    )
    (arguments
      (arguments  strawberries, cucumbers, legs, feet, nose, ear,
                  armpit, thigh, elbow, wrist,
                  lips, fingers, eye, frog, apples, knee, toes, cheek, #)
      (self   "You lick $mhcname$ $arg$.")
      (target "$mcname$ licks your $arg$.")
      (rest  "$mcname$ licks $mhcname$ $arg$.")
    )
  )
)

