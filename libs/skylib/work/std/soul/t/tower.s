(tower
  (pattern "[over] <indirect:any-living>")
  (pattern "[over] <indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You tower over $hcname$.")
      (target "$mcname$ towers over you.")
      (rest  "$mcname$ towers over $hcname$.")
    )
    (arguments
      (arguments  ominously,threateningly)
      (self   "You tower over $hcname$ $arg$.")
      (target "$mcname$ towers over you $arg$.")
      (rest  "$mcname$ towers over $hcname$ $arg$.")
    )
  )
)

