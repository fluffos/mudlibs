(gnash
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You gnash your teeth.")
      (rest "$mcname$ gnashes $mposs$ teeth.")
    )
  )
  (targeted
    (no-arguments
      (self   "You gnash your teeth at $hcname$.")
      (target "$mcname$ gnashes $mposs$ teeth at you.")
      (rest  "$mcname$ gnashes $mposs$ teeth at $hcname$.")
    )
  )
)

