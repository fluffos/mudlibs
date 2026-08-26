(eye
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You eye $hcname$ over.")
      (target "$mcname$ eyes you over.")
      (rest  "$mcname$ eyes $hcname$ over.")
    )
    (arguments
      (arguments thoughtfully, #)
      (self   "You eye $hcname$ $arg$.")
      (target "$mcname$ eyes you $arg$.")
      (rest  "$mcname$ eyes $hcname$ $arg$.")
    )
  )
)
