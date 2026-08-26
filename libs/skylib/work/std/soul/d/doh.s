(doh
  (pattern "[at] <indirect:any-living>")
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You slap your forehead and exclaim: D'oh!")
      (rest "$mcname$ slaps $mposs$ forehead and exclaims: D'oh!")
    )
  )
  (targeted
    (no-arguments
      (self   "You slap your forehead and exclaim: D'oh! at $hcname$.")
      (target "$mcname$ slaps $mposs$ forehead and exclaims: D'oh! at you.")
      (rest   "$mcname$ slaps $mposs$ forehead and exclaims: D'oh! at $hcname$.")
    )
  )
)
