(ooze
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [at] <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You ooze.")
      (rest "$mcname$ oozes.")
    )
    (arguments
      (arguments all over, coffee, cappacino, soda, tea, sweat, 
                 testosterone, estrogen, blood, saliva, guts, slime,
                 bodily fluids, charm, alcohol, code, #)
      (self "You ooze $arg$.")
      (rest "$mcname$ oozes $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ooze all over $hcname$.")
      (target "$mcname$ oozes all over you.")
      (rest   "$mcname$ oozes all over $hcname$.")
    )
    (arguments
      (arguments coffee, cappacino, soda, tea, sweat, testosterone, 
                 estrogen, blood, saliva, guts, slime, bodily fluids, 
                 charm, alcohol, code, #)
      (self   "You ooze $arg$ all over $hcname$.")
      (target "$mcname$ oozes $arg$ all over you.")
      (rest   "$mcname$ oozes $arg$ all over $hcname$.")
    )
  )
)
