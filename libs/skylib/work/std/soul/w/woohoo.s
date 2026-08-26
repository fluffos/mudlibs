(woohoo
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You go WOOOOO-HOOOOO!")
      (rest "$mcname$ goes WOOOOO-HOOOOO!")
    )
    (arguments
    (arguments  #)
      (self "You go WOOOOO-HOOOOO! $arg$.")
      (rest "$mcname$ goes WOOOOO-HOOOOO! $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You go WOOOOO-HOOOOO! at $hcname$.")
    (target "$mcname$ goes WOOOOO-HOOOOO! at you.")
    (rest "$mcname$ goes WOOOOO-HOOOOO! at $hcname$.")
  )
  (arguments
  (arguments  #)
    (self "You go WOOOOO-HOOOOO! at $hcname$ $arg$." )
    (target "$mcname$ goes WOOOOO-HOOOOO! at you $arg$." )
    (rest "$mcname$ goes WOOOOO-HOOOOO! at $hcname$ $arg$." )
    )
  )
)
