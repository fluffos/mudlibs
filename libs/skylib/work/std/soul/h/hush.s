(hush
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You hush $hcname$.")
      (target "$mcname$ hushes you.")
      (rest  "$mcname$ hushes $hcname$.")
    )
    (arguments
      (arguments  quickly,carefully,threateningly,nervously,
      for using such language,#)
      (self   "You hush $hcname$ $arg$.")
      (target "$mcname$ hushes you $arg$.")
      (rest  "$mcname$ hushes $hcname$ $arg$.")
    )
  )
)

