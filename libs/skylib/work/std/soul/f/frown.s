(frown
  (pattern "[at] <indirect:any-living>")
  (pattern "[in] <string>")
  (single
    (no-arguments
      (self "What's the problem?")
      (rest "$mcname$ frowns.")
    )
    (arguments
      (arguments concentration,thought,anger,depression,like a cat,happily,#)
      (self "You frown in $arg$.")
      (rest "$mcname$ frowns in $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You frown at $hcname$.")
      (target "$mcname$ frowns at you.")
      (rest  "$mcname$ frowns at $hcname$.")
    )
  )
)

