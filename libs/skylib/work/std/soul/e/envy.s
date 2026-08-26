(envy
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You envy $hcname$.")
      (target "$mcname$ envies you.")
      (rest  "$mcname$ envies $hcname$.")
    )
    (arguments
      (arguments  frog,#)
      (self   "You envy $mhcname$ $arg$.")
      (target "$mcname$ envies your $arg$.")
      (rest  "$mcname$ envies $mhcname$ $arg$.")
    )
  )
)

