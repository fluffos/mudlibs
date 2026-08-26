(hassle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> [about] <string>")
  (targeted
    (no-arguments
      (self   "You hassle $hcname$.")
      (target "$mcname$ hassles you.")
      (rest  "$mcname$ hassles $hcname$.")
    )
    (arguments
      (arguments  frogs,chickens,wombles,#)
      (self   "You hassle $hcname$ about $arg$.")
      (target "$mcname$ hassles you about $arg$.")
      (rest  "$mcname$ hassles $hcname$ about $arg$.")
    )
  )
)

