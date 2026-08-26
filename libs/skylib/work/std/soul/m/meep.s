(meep
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You meep.")
      (rest "$mcname$ meeps.")
    )
    (arguments
      (arguments #)
      (self "You meep $arg$.")
      (rest "$mcname$ meeps $arg$.")
    )
   )
  (targeted
    (no-arguments
      (self   "You meep at $hcname$.")
      (target "$mcname$ meeps at you.")
      (rest  "$mcname$ meeps at $hcname$.")
    )
   (arguments
      (arguments #)
      (self   "You meep $arg$ at $hcname$.")
      (target "$mcname$ meeps $arg$ at you.")
      (rest   "$mcname$ meeps $arg$ at $hcname$.")
    )
  )
)
