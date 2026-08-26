(blush
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You blush.")
      (rest "$mcname$ blushes.")
    )
    (arguments
      (arguments  in embarrassment,redly,comfortably,slightly,worriedly,#)
      (self "You blush $arg$.")
      (rest "$mcname$ blushes $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You blush at $hcname$.")
      (target "$mcname$ blushes at you.")
      (rest  "$mcname$ blushes at $hcname$.")
    )
    (arguments
      (arguments  in embarrassment,redly,comfortably,slightly,worriedly,#)  
      (self   "You blush $arg$ at $hcname$.")
      (target "$mcname$ blushes $arg$ at you.")
      (rest  "$mcname$ blushes $arg$ at $hcname$.")
    )
  )
)

