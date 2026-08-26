(drool
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You start to drool.")
      (rest "$mcname$ starts to drool.")
    )
  )
  (targeted
    (no-arguments
      (self   "You drool all over $hcname$.")
      (target "$mcname$ drools all over you.")
      (rest  "$mcname$ drools all over $hcname$.")
    )
  )
)

