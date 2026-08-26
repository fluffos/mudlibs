(bleed
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [at] <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You bleed.")
      (rest "$mcname$ bleeds.")
    )
    (arguments
      (arguments heart, leg, arm, head, ear, nose, #)
      (self "Your $arg$ bleeds.")
      (rest "$mcname$'s $arg$ bleeds.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bleed on $mcname$.")
      (target "$mcname$ bleeds on you.")
      (rest   "$mcname$ bleeds on $hcname$.")
    )
    (arguments
      (arguments heart, leg, arm, head, ear, nose, #)
      (self   "Your $arg$ bleeds on $hcname$.")
      (target "$mcname$'s $arg$ bleeds on you.")
      (rest   "$mcname$'s $arg$ bleeds on $hcname$.")
    )
  )
)

