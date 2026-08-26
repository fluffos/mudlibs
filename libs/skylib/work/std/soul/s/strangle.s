(strangle
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> [about] <string>")
  (single
    (no-arguments
      (self "You strangle yourself.")
      (rest "$mcname$ strangles $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You strangle $hcname$.")
      (target "$mcname$ strangles you.")
    (rest  "$mcname$ strangles $hcname$.")
    )
  )
)

