(blame
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> [for] <string>")
  (targeted
    (no-arguments
      (self   "You blame $hcname$.")
      (target "$mcname$ blames you.")
      (rest  "$mcname$ blames $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You blame $hcname$ for $arg$.")
      (target "$mcname$ blames you for $arg$.")
      (rest  "$mcname$ blames $hcname$ for $arg$.")
    )
  )
)

