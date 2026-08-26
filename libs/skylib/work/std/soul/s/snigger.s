(snigger
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You snigger.")
      (rest "$mcname$ sniggers.")
    )
    (arguments
      (arguments mischievously,nastily,a bit,annoyingly)
      (self "You snigger $arg$.")
      (rest "$mcname$ sniggers $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You snigger at $hcname$.")
      (target "$mcname$ sniggers at you.")
      (rest  "$mcname$ sniggers at $hcname$.")
    )
    (arguments
      (arguments mischievously,nastily,a bit,annoyingly) 
      (self   "You snigger $arg$ at $hcname$.")
      (target "$mcname$ sniggers $arg$ at you.")
      (rest  "$mcname$ sniggers $arg$ at $hcname$.")
    )
  )
)

