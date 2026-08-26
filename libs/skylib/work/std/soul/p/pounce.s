(pounce
  (pattern "[on] <indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "[on] <indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You pounce on $hcname$.")
      (target "$mcname$ pounces on you.")
      (rest  "$mcname$ pounces on $hcname$.")
    )
    (arguments
      (arguments  excitedly, seductively, madly, carefully, appreciatively,
                  selectively, with a wooden spoon, at near light speed,
                  while showing some cleavage, # )
      (self   "You pounce on $hcname$ $arg$.")
      (target "$mcname$ pounces on you $arg$.")
      (rest  "$mcname$ pounces on $hcname$ $arg$.")
    )
  )
)

