(zonk
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You go 'Zonke zonke zonke'.")
      (rest "$mcname$ goes 'Zonke zonke zonke'.")
    )
  )
  (targeted
    (no-arguments
      (self "You zonk $hcname$ on the nose.")
      (target "$mcname$ zonks you on the nose.")
      (rest "$mcname$ zonks $hcname$ on the nose.")
    )
  )
)
