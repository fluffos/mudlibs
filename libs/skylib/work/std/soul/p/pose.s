(pose
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You strike a pose.")
      (rest "$mcname$ strikes a pose.")
    )
    (arguments
      (arguments
       keenly, hoopily, froggily, slimily, brilliantly, wetly,
       tiredly, drunkenly, smarmily, smartly, quietly, awkwardly, loudly,
       evenly, sarcastically, like a creator, hollowly, mechanically,
       in victory, weakly, icily, soggily,
       overworkedly, like a pretzel, greenly, discreetly, in self defense,
       woundedly, like a cat, fuzzily, sharply, like a parcel,
       like a desk lamp, electrically, absentmindedly, hurriedly)
      (self "You pose $arg$.")
      (rest "$mcname$ poses $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You strike a pose at $hcname$.")
      (target "$mcname$ strikes a pose at you.")
      (rest  "$mcname$ strikes a pose at $hcname$.")
    )
    (arguments
      (arguments keenly, hoopily, froggily, slimily, brilliantly, wetly,
       tiredly, drunkenly, smarmily, smartly, quietly, awkwardly, loudly,
       evenly, sarcastically, like a creator, hollowly, mechanically,
       in victory, weakly, icily, soggily,
       overworkedly, like a pretzel, greenly, discreetly, in self defense,
       woundedly, like a cat, fuzzily, sharply, like a parcel,
       like a desk lamp, electrically, absentmindedly, hurriedly)
      (self   "You pose $arg$ at $hcname$.")
      (target "$mcname$ poses $arg$ at you.")
      (rest  "$mcname$ poses $arg$ at $hcname$.")
    )
  )
)
