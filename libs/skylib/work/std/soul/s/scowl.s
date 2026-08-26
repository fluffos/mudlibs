(scowl
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You scowl.")
      (rest "$mcname$ scowls.")
    )
  )
  (targeted
    (no-arguments
      (self   "You scowl at $hcname$.")
      (target "$mcname$ scowls at you.")
      (rest  "$mcname$ scowls at $hcname$.")
    )
  )
)

