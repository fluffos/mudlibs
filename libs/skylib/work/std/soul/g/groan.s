(groan
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You groan.")
      (rest "$mcname$ groans.")
    )
    (arguments
      (arguments loudly, resignedly, tiredly, in disappointment, #)
      (self "You groan $arg$.")
      (rest "$mcname$ groans $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You groan at $hcname$.")
      (target "$mcname$ groans at you.")
      (rest  "$mcname$ groans at $hcname$.")
    )
    (arguments
      (arguments  loudly, resignedly, tiredly, in disappointment, #)
      (self   "You groan $arg$ at $hcname$.")
      (target "$mcname$ groans $arg$ at you.")
      (rest  "$mcname$ groans $arg$ at $hcname$.")
    )
  )
)

