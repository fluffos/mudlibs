(pet
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You pet Goldie.")
      (rest "$mcname$ pets Goldie.")
    )
  )
  (targeted
    (no-arguments
      (self   "You pet $hcname$.")
      (target "$mcname$ pets you.")
      (rest  "$mcname$ pets $hcname$.")
    )
  )
)

