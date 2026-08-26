(bap
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You bap to the beat.")
      (rest "$mcname$ baps to the beat.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bap $hcname$ on the head.")
      (target "$mcname$ baps you on the head.")
      (rest  "$mcname$ baps $hcname$ on the head.")
    )
  )
)

