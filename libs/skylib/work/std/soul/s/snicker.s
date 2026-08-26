(snicker
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You snicker.")
      (rest "$mcname$ snickers.")
    )
    (arguments
      (arguments  mischievously,nastily,a bit,annoyingly)
      (self "You snicker $arg$.")
      (rest "$mcname$ snickers $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You snicker at $hcname$.")
      (target "$mcname$ snickers at you.")
      (rest  "$mcname$ snickers at $hcname$.")
    )
    (arguments
      (arguments mischievously,nastily,a bit,annoyingly) 
      (self   "You snicker $arg$ at $hcname$.")
      (target "$mcname$ snickers $arg$ at you.")
      (rest  "$mcname$ snickers $arg$ at $hcname$.")
    )
  )
)

