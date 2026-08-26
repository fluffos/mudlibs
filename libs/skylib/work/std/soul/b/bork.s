(bork
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You bork.")
      (rest "$mcname$ borks.")
    )
    (arguments
    (arguments  like a Swedish chef, with meatballs, #)
      (self "You borks $arg$.")
      (rest "$mcname$ borks $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You bork at $hcname$.")
    (target "$mcname$ borks at you.")
    (rest "$mcname$ borks at $hcname$.")
  )
  (arguments
    (arguments  like a Swedish chef, with meatballs, #)
    (self "You bork at $hcname$ $arg$." )
    (target "$mcname$ borks at you $arg$." )
    (rest "$mcname$ borks $hcname$ $arg$." )
    )
  )
)
