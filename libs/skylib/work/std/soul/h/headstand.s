(headstand
  (pattern "[on] <indirect:any-living>")
  (single
    (no-arguments
      (self "You stand on your head.")
      (rest "$mcname$ stands on $mposs$ head.")
    )
  )
  (targeted
    (no-arguments
      (self   "You stand on $mhcname$ head.")
      (target "$mcname$ stands on your head.")
      (rest  "$mcname$ stands on $mhcname$ head.")
    )
  )
)

