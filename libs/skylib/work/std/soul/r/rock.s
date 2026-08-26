(rock
  (pattern "<string>")
  (pattern "<indirect:any-living> <string>")
  (pattern <string> "<indirect:any-living>")
  (pattern "<indirect:any-living>")
  (single
    (arguments
      (arguments  heels, nose, feet, elbows, #)
      (self "You rock on your $arg$.")
      (rest "$mcname$ rocks on $mposs$ $arg$.")
    )
    (arguments
      (arguments  around the clock, in consternation, uncertainly to and fro, #)
      (self "You rock $arg$.")
      (rest "$mcname$ rocks $arg$.")
    )
    (arguments
      (arguments  around the clock, #)
      (self "You rock $arg$.")
      (rest "$mcname$ rocks $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  gently in their arms, #)
      (self   "You rock $hcname$ gently in your arms.")
      (target "$mcname$ rocks you gently in $mposs$ arms.")
      (rest   "$mcname$ rocks $hcname$ gently in $mposs$ arms.")
    )
  )
)
