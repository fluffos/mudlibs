(luck
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You wish $hcname$ luck.")
      (target "$mcname$ wishes you luck.")
      (rest  "$mcname$ wishes $hcname$ luck.")
    )
    (arguments
      (arguments  good,bad,lots of,no,an iota of,a frogfull of)
      (self   "You wish $hcname$ $arg$ luck.")
      (target "$mcname$ wishes you $arg$ luck.")
      (rest  "$mcname$ wishes $hcname$ $arg$ luck.")
    )
  )
)

