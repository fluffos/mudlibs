(explode
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [over] <indirect:any-living>")
  (pattern "[over] <indirect:any-living> <string>")
  (single
    (no-arguments
        (self "You explode into thousands of tiny pieces.") 
        (rest "$mcname$ explodes into thousands of tiny pieces.")
        )
      (arguments 
        (arguments messily,into thousands of tiny thetans,over your frog,#)
      (self "You explode $arg$.")
      (rest "$mcname$ explodes $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You explode into thousands of tiny pieces over $hcname$.")
      (target "$mcname$ explodes into thousands of tiny pieces over you.")
      (rest  "$mcname$ explodes into thousands of tiny pieces over $hcname$.")
       )
      (arguments 
        (arguments messily,into thousands of tiny thetans,your frog,#)
      (self   "You explode $arg$ over $hcname$.")
      (target "$mcname$ explodes $arg$ over you.")
      (rest   "$mcname$ explodes $arg$ over $hcname$.")
    )
  )
)
