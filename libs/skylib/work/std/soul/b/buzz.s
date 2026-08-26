(buzz
  (pattern "<indirect:any-living> [ear]")
  (single
    (no-arguments
      (self "You buzz gently.")
      (rest "$mcname$ buzzes gently.")
    )
    (arguments
      (arguments #)
      (self "You buzz $arg$.")
      (rest "$mcname$ buzzes $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You buzz in $mhcname$ ear.")
      (target "$mcname$ buzzes in your ear.")
      (rest   "$mcname$ buzzes in $mhcname$ ear.")
    )
  )
)

