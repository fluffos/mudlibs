(skitter
  (pattern "[around] <indirect:any-living>")
  (pattern "[around] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You skitter along the ground quickly.")
      (rest "$mcname$ skitters along the ground quickly.")
    )
  )
  (targeted
    (no-arguments
      (self   "You skitter quickly along the ground around $hcname$.")
      (target "$mcname$ skitters quickly along the ground around you.")
      (rest  "$mcname$ skitter quickly along the ground around $hcname$.")
    )
    (arguments
     (arguments quickly,like an insect,happily,slowly,gracefully,busily,
                mindlessly,joyfully,boredly,merrily)
      (self "You skitter $arg$ along the ground around $hcname$.")
      (target "$mcname$ skitters $arg$ along the ground around you.")
      (rest "$mcname$ skitters $arg$ along the ground around $hcname$.")
    )
  )
)
