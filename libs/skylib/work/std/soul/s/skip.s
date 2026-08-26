(skip
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You skip around happily.")
      (rest "$mcname$ skips around happily.")
    )
  )
  (targeted
    (no-arguments
      (self   "You skip around $hcname$.")
      (target "$mcname$ skips around you.")
      (rest  "$mcname$ skips around $hcname$.")
    )
  )
)

