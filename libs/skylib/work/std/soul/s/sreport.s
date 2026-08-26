(sreport
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You report $hcname$ to the coding police.")
      (target "$mcname$ reports you to the coding police.")
      (rest  "$mcname$ reports $hcname$ to the coding police.")
    )
    (arguments
      (arguments to the coding police,to the fashion police,to The Admin,for being mean,for grievous runtimes,for causing errors)
      (self   "You report $hcname$ $arg$.")
      (target "$mcname$ reports you $arg$.")
      (rest  "$mcname$ reports $hcname$ $arg$.")
    )
  )
)

