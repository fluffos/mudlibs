(shudder
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You shudder.")
      (rest "$mcname$ shudders.")
    )
    (arguments
      (arguments horror, fear, revulsion, disappointment, ecstasy,
                 pleasure, orgasmic release)
      (self "You shudder in $arg$.")
      (rest "$mcname$ shudders in $arg$.")
    )
    (arguments
      (arguments like they were having a shower) 
      (self   "You shudder $arg$.")
      (rest  "$mcname$ shudders $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You shudder at $hcname$.")
      (target "$mcname$ shudders at you.")
      (rest   "$mcname$ shudders at $hcname$.")
    )
    (arguments
      (arguments horror, fear, revulsion, disappointment, ecstasy,
                 pleasure, orgasmic release)
      (self   "You shudder in $arg$ at $hcname$.")
      (target "$mcname$ shudders in $arg$ at you.")
      (rest  "$mcname$ shudders in $arg$ at $hcname$.")
    )
    (arguments
      (arguments like they were having a shower) 
      (self   "You shudder $arg$ at $hcname$.")
      (target "$mcname$ shudders $arg$ at you.")
      (rest  "$mcname$ shudders $arg$ at $hcname$.")
    )
  )
)

