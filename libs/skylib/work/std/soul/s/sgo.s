(sgo
  (pattern "<string>" )
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
    (arguments  away, hmmm, Bing!, # )
      (self "You go $arg$.")
      (rest "$mcname$ goes $arg$.")
    )
  )
  (targeted
    (arguments
    (arguments  away, hmmm, Bing!, # )
    (self   "You go $arg$ at $hcname$.")
    (target "$mcname$ goes $arg$ at you.")
    (rest   "$mcname$ goes $arg$ at $hcname$.")
    )
  )
)
