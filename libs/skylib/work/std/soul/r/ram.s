(ram
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You ram the nearest turtle.")
      (rest "$mcname$ rams the nearest turtle.")
    )
    (arguments
      (arguments #)
      (self "You ram the $arg$.")
      (rest "$mcname$ rams the $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ram $hcname$.")
      (target "$mcname$ rams you.")
      (rest  "$mcname$ rams $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You ram $mhcname$ $arg$.")
      (target "$mcname$ rams your $arg$.")
      (rest  "$mcname$ rams $mhcname$ $arg$.")
    )
  )
)

