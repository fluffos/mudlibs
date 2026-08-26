(grope
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You grope $hcname$.")
      (target "$mcname$ gropes you.")
      (rest  "$mcname$ gropes $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You grope $mhcname$ $arg$.")
      (target "$mcname$ gropes you $arg$.")
      (rest  "$mcname$ gropes $mhcname$ $arg$.")
    )
  )
)

