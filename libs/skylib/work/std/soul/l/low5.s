(low5
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You low five.")
      (rest "$mcname$ low fives.")
    )
  )
  (targeted
    (no-arguments
      (self   "You low five $hcname$.")
      (target "$mcname$ low fives you.")
      (rest  "$mcname$ low fives $hcname$.")
    )
  )
)

