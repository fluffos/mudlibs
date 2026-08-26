(bop
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You bop to the beat.")
      (rest "$mcname$ bops to the beat.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bop $hcname$ on the head.")
      (target "$mcname$ bops you on the head.")
      (rest  "$mcname$ bops $hcname$ on the head.")
    )
  )
)

