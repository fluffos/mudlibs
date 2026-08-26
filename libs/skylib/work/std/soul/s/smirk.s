(smirk
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You smirk.")
      (rest "$mcname$ smirks.")
    )
  )
  (targeted
    (no-arguments
      (self   "You smirk at $hcname$.")
      (target "$mcname$ smirks at you.")
      (rest  "$mcname$ smirks at $hcname$.")
    )
  )
)

