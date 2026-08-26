(hate
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hate the world.")
      (rest "$mcname$ hates the world.")
    )
    (arguments
      (arguments #)
      (self "You hate $arg$.")
      (rest "$mcname$ hates $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hate $hcname$.")
      (target "$mcname$ hates you.")
      (rest  "$mcname$ hates $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You hate $hcname$ $arg$.")
      (target "$mcname$ hates you $arg$.")
      (rest  "$mcname$ hates $hcname$ $arg$.")
    )
  )
)
/*Hobbes 970415, suggested by Gruper. */
