(trip
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You trip up.")
      (rest "$mcname$ trips up.")
      (position
        (standing "sit")
      )
    )
  )
  (targeted
    (no-arguments
      (self   "You trip $hcname$.")
      (target "$mcname$ trips you.")
      (rest  "$mcname$ trips $hcname$.")
      (position
        (standing "sit")
      )
    )
  )
)

