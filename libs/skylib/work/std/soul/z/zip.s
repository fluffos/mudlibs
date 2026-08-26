(zip
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You zip around the room.")
      (rest "$mcname$ zips around the room.")
    )
  )
  (targeted
    (no-arguments
      (self   "You zip around $hcname$.")
      (target "$mcname$ zips around you.")
      (rest  "$mcname$ zips around $hcname$.")
    )
  )
)

