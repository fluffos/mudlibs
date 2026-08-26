(strut
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You strut your stuff.")
      (rest "$mcname$ struts proudly around the room.")
    )
  )
  (targeted
    (no-arguments
      (self "You strut your stuff at $hcname$.")
      (target "$mcname$ struts proudly around the room at you.")
      (rest "$mcname$ struts proudly around the room at $hcname$.")
    )
  )
)

