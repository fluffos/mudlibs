(raspberry
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You blow a raspberry.")
      (rest "$mcname$ blows a raspberry.")
    )
  )
  (targeted
    (no-arguments
      (self   "You blow a raspberry at $hcname$.")
      (target "$mcname$ blows a raspberry at you.")
      (rest  "$mcname$ blows a raspberry at $hcname$.")
    )
  )
)

