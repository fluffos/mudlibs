(skick
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You kick yourself.")
      (rest "$mcname$ kicks $mobj$self.")
    )
    (arguments
      (arguments hard, softly)
      (self "You kick yourself $arg$.")
      (rest "$mcname$ kicks $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You kick $hcname$.")
      (target "$mcname$ kicks you.")
      (rest  "$mcname$ kicks $hcname$.")
    )
    (arguments
      (arguments  softly, hard)
      (self   "You kick $hcname$ $arg$.")
      (target "$mcname$ kicks you $arg$.")
      (rest  "$mcname$ kicks $hcname$ $arg$.")
    )
  )
)

