(dare
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You dare $hcname$.")
      (target "$mcname$ dares you.")
      (rest   "$mcname$ dares $hcname$.")
    )
    (arguments
      (arguments to go creator,to read Shaydz's code,#)
      (self   "You dare $hcname$ $arg$.")
      (target "$mcname$ dares you $arg$.")
      (rest   "$mcname$ dares $hcname$ $arg$.")
    )
  )
)

