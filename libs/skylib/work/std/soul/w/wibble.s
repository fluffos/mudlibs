(wibble
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments  like bil,loudly,constantly,annoyingly,around,up,down,sideways)
      (self "You wibble $arg$.")
      (rest "$mcname$ wibbles $arg$.")
    )
  )
  (targeted
    (arguments 
      (arguments  like bil,loudly,constantly,annoyingly,around,up,down,sideways) 
      (self   "You wibble $arg$ at $hcname$.")
      (target "$mcname$ wibbles $arg$ at you.")
      (rest  "$mcname$ wibbles $arg$ at $hcname$.")
    )
  )
)

