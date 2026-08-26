(spit
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You spit.")
      (rest "$mcname$ spits.")
    )
  )
  (targeted
    (no-arguments
      (self   "You spit in $mhcname$ face.")
      (target "$mcname$ spits in your face.")
      (rest  "$mcname$ spits in $mhcname$ face.")
    )
  )
)

