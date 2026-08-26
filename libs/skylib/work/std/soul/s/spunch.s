(spunch
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You punch yourself.")
      (rest "$mcname$ punches $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You punch $hcname$.")
      (target "$mcname$ punches you.")
      (rest  "$mcname$ punches $hcname$.")
    )
  )
)

