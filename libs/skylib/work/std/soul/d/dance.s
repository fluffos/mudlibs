(dance
  (pattern "[with] <indirect:any-living>")
  (single
    (no-arguments
      (self "You dance.")
      (rest "$mcname$ dances.")
    )
  )
  (targeted
    (no-arguments
      (self   "You sweep $hcname$ across the dance floor.")
      (target "$mcname$ sweeps you across the dance floor.")
      (rest  "$mcname$ sweeps $hcname$ across the dance floor.")
    )
  )
)

