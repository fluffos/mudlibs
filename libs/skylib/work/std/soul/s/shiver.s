(shiver
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You shiver.")
      (rest "$mcname$ shivers.")
    )
    (arguments
       (arguments horror, fear, revulsion, disappointment, ecstasy,
                 pleasure, orgasmic release)
      (self "You shiver in $arg$.")
      (rest "$mcname$ shivers in $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You shiver at $hcname$.")
      (target "$mcname$ shivers at you.")
      (rest  "$mcname$ shivers at $hcname$.")
    )
    (arguments
      (arguments horror, fear, revulsion, disappointment, ecstasy,
                 pleasure, orgasmic release)
      (self   "You shiver in $arg$ at $hcname$.")
      (target "$mcname$ shivers in $arg$ at you.")
      (rest  "$mcname$ shivers in $arg$ at $hcname$.")
    )
  )
)

