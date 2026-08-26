(taunt
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You taunt yourself.")
      (rest "$mcname$ taunts $mposs$self... how odd.")
    )
  )
  (targeted
    (no-arguments
      (self   "You taunt $hcname$.")
      (target "$mcname$ taunts you.")
      (rest  "$mcname$ taunts $hcname$.")
    )
  )
)

