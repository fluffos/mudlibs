(pout
  (pattern "<string>")
  (pattern "[at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments quietly in the corner, childishly, silently, resignedly, # )
      (self "You pout $arg$.")
      (rest "$mcname$ pouts $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You pout at $hcname$.")
      (target "$mcname$ pouts at you.")
      (rest  "$mcname$ pouts at $hcname$.")
    )
    (arguments
      (arguments childishly, silently, resignedly, quietly, # )
      (self   "You pout $arg$ at $hcname$.")
      (target "$mcname$ pouts $arg$ at you.")
      (rest  "$mcname$ pouts $arg$ at $hcname$.")
    )
  )
)
