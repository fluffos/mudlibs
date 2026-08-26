(mourn
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments the sudden death of frogs at the hands of Shiannar,#)
      (self "You mourn $arg$.")
      (rest "$mcname$ mourns $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You mourn $hcname$.")
      (target "$mcname$ mourns you.")
      (rest   "$mcname$ mourns $hcname$.")
    )
  )
)

