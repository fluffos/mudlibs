(salute
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You salute smartly.")
      (rest "$mcname$ salutes smartly.")
    )
  )
  (targeted
    (no-arguments
      (self   "You salute $hcname$.")
      (target "$mcname$ salutes you.")
      (rest  "$mcname$ salutes $hcname$.")
    )
  )
)

