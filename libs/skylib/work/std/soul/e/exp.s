(exp
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You raise yourself to a random power.")
      (rest "$mcname$ raises $mobj$self to a random power.")
    )
    (arguments
      (arguments #)
      (self "You raise yourself to the power of $arg$.")
      (rest "$mcname$ raises $mobj$self to the power of $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You raise $hcname$ to a random power.")
      (target "$mcname$ raises you to a random power.")
      (rest  "$mcname$ raises $hcname$ to a random power.")
    )
    (arguments
      (arguments  #)
      (self   "You raise $hcname$ to the power of $arg$.")
      (target "$mcname$ raises you to the power of $arg$.")
      (rest  "$mcname$ raises $hcname$ to the power of $arg$.")
    )
  )
)

