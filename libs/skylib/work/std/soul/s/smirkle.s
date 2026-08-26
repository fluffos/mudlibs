(smirkle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You smirkle.")
      (rest "$mcname$ smirkles.")
    )
    (arguments
      (arguments happily,sadly,like truilkan,sardonically)
      (self "You smirkle $arg$.")
      (rest "$mcname$ smirkles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You smirkle.")
      (target "$mcname$ smirkles at you.")
      (rest  "$mcname$ smirkles at $hcname$.")
    )
    (arguments
      (arguments  happily,sadly,like truilkan,sardonically)
      (self   "You smirkle $arg$.")
      (target "$mcname$ smirkles $arg$ at you.")
      (rest  "$mcname$ smirkles $arg$ at $hcname$.")
    )
  )
)

