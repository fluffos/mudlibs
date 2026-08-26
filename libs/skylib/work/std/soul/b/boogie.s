(boogie
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
      (no-arguments
      (self "You boogie around the room.")
      (rest "$mcname$ boogies around the room.")
      )
   )
  (targeted
    (no-arguments
      (self   "You boogie around $hcname$.")
      (target "$mcname$ boogies around you.")
      (rest  "$mcname$ boogies around $hcname$.")
    )
    (arguments
      (arguments quickly,happily,slowly,curiously,sadly)
      (self   "You boogie around $hcname$ $arg$.")
      (target "$mcname$ boogies around you $arg$.")
      (rest  "$mcname$ boogies around $hcname$ $arg$.")
    )
  )
)

