(spank
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You spank $hcname$.")
      (target "$mcname$ spanks you.")
      (rest   "$mcname$ spanks $hcname$.")
    )
    (arguments
      (arguments  seductively, carefully, gently, uncontrollably, politely, 
                  sensuously, selectively, unexpectedly, with an evil smirk, 
                  painfully, sneakily, unprovoked, professionally, vigorously, 
                  reflexively, with a cat, like a train, like a virgin mary, 
                  with a virgin mary, with a wooden spoon)
      (self   "You spank $hcname$ $arg$.")
      (target "$mcname$ spanks you $arg$.")
      (rest   "$mcname$ spanks $hcname$ $arg$.")
    )
  )
)

