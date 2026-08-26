(educate
  (pattern "<indirect:any-living> [about] <string>")
  (pattern "<string> <indirect:any-living>")
  (targeted
    (arguments
      (arguments #)
      (self   "You educate $hcname$ about $arg$.")
      (target "$mcname$ educates you about $arg$.")
      (rest  "$mcname$ educates $hcname$ about $arg$.")
    )
  )
)

