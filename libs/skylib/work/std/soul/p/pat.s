(pat
  (pattern "<indirect:any-living> on the <string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> [on] <string>")
  (targeted
    (arguments
      (arguments  head,back,leg,arm,nose,bottom)
      (self   "You pat $hcname$ on the $arg$.")
      (target "$mcname$ pats you on the $arg$.")
      (rest  "$mcname$ pats $hcname$ on the $arg$.")
    )
  )
)

