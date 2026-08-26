(hang
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments shame,sorrow,despair,happiness)
      (self "You hang your head in $arg$.")
      (rest "$mcname$ hangs $mposs$ head in $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hang onto $hcname$.")
      (target "$mcname$ hangs onto you.")
      (rest  "$mcname$ hangs onto $hcname$.")
    )
    (arguments
      (arguments  tightly,passionately,fearfully,possessively,paranoically)
      (self   "You hang onto $hcname$ $arg$.")
      (target "$mcname$ hangs onto you $arg$.")
      (rest  "$mcname$ hangs onto $hcname$ $arg$.")
    )
  )
)

