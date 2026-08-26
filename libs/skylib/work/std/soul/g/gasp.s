(gasp
  (pattern "[at] <indirect:any-living>")
  (pattern "[in] <string>")
  (pattern "[in] <string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> [in] <string>")
  (single
    (arguments
      (arguments astonishment,excitement,terror,fear,fright,pain)
      (self "You gasp in $arg$.")
      (rest "$mcname$ gasps in $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments astonishment,excitement,terror,fear,fright,pain) 
      (self   "You gasp in $arg$ at $hcname$.")
      (target "$mcname$ gasps in $arg$ at you.")
      (rest  "$mcname$ gasps in $arg$ at $hcname$.")
    )
  )
)

