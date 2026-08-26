(bonk
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "B O N K !")
      (rest "$mcname$ goes B O N K !")
    )
  )
  (targeted
    (arguments
      (arguments  head,arm,elk,cabbage)
      (self   "You bonk $hcname$ on the $arg$.")
      (target "$mcname$ bonks you on the $arg$.")
      (rest  "$mcname$ bonks $hcname$ on the $arg$.")
    )
  )
)

