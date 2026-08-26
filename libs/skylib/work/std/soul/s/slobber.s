(slobber
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You slobber all over the place.")
      (rest "$mcname$ slobbers all over the place.")
    )
  )
  (targeted
    (no-arguments
      (self   "You slobber all over $hcname$.")
      (target "$mcname$ slobbers all over you.")
      (rest  "$mcname$ slobbers all over $hcname$.")
    )
  )
)

