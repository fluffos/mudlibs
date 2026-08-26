(hrmph
  (pattern "<string>")
  (pattern "[at] <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hrmph.")
      (rest "$mcname$ hrmphs.")
    )
    (arguments
      (arguments  carefully, silently, lengthily, fishily, boringly, snobbishly, 
                  happily, courageously, with wild abandon, snortingly, cutely, 
                  absentmindedly, in disgust, in contempt, in perturbation, 
                  with an evil glint in your eye, #)
      (self "You hrmph $arg$.")
      (rest "$mcname$ hrmphs $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hrmph in $mhcname$ general direction.")
      (target "$mcname$ hrmphs in your general direction.")
      (rest   "$mcname$ hrmphs in $mhcname$ general direction.")
    )
    (arguments
      (arguments  carefully, silently, lengthily, fishily, boringly, snobbishly, 
                  happily, courageously, with wild abandon, snortingly, cutely, 
                  absentmindedly, in disgust, in contempt, in perturbation, 
                  with an evil glint in your eye, #)
      (self   "You hrmph $arg$ at $hcname$.")
      (target "$mcname$ hrmphs $arg$ at you.")
      (rest   "$mcname$ hrmphs $arg at $hcname$.")
    )
  )
)

