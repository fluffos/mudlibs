(faint
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You faint.")
      (rest "$mcname$ faints.")
    )
    (arguments
      (arguments tiredly,out of boredom)
      (self "You faint $arg$.")
      (rest "$mcname$ faints $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You faint on $hcname$.")
      (target "$mcname$ faints on you.")
      (rest  "$mcname$ faints on $hcname$.")
    )
  )
)

