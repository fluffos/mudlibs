(signore
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You ignore the world.")
      (rest "$mcname$ ignores the world.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ignore $hcname$.")
      (target "$mcname$ ignores you.")
      (rest  "$mcname$ ignores $hcname$.")
    )
  )
)

