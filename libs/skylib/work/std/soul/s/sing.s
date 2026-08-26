(sing
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments in appreciation of life, happy birthday, #)
      (self "You sing $arg$.")
      (rest "$mcname$ sings $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You sing to $hcname$.")
      (target "$mcname$ sings to you.")
      (rest  "$mcname$ sings to $hcname$.")
    )
   (arguments
      (arguments in appreciation of life,happy birthday, #)
      (self   "You sing $arg$ to $hcname$.")
      (target "$mcname$ sings $arg$ to you.")
      (rest   "$mcname$ sings $arg$ to $hcname$.")
    )
   )
  )
