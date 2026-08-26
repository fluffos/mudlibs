(sue
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You feel like sueing the pants off someone.")
      (rest "$mcname$ looks mad enough to sue.")
    )
  )
  (targeted
    (no-arguments
      (self   "You attempt to sue $hcname$ for all they are worth.")
      (target "$mcname$ attempt to sue you for all you are worth.")
      (rest  "$mcname$ attempt to sue $hcname$ for all $hpronoun$ are worth.")
    )
    (arguments
      (arguments  for all your money, for having a name like that)
      (self   "You attempt to sue $hcname$ $arg$.")
      (target "$mcname$ attempt to sue you $arg$.")
      (rest  "$mcname$ attempt to sue $hcname$ $arg$.")
    )
  )
)

