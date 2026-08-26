(quack
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> at <indirect:any-living>")
  (single
    (no-arguments
      (self "You quack.")
      (rest "$mcname$ quacks.")
    )
    (arguments
      (arguments like a duck,like a confused dog,happily,#)
      (self "You quack $arg$.")
      (rest "$mcname$ quacks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You quack at $hcname$.")
      (target "$mcname$ quacks at you.")
      (rest  "$mcname$ quacks at $hcname$.")
    )
    (arguments
      (arguments like a duck,like a confused dog,happily,#)
      (self   "You quack $arg$ at $hcname$.")
      (target "$mcname$ quacks $arg$ at you.")
      (rest  "$mcname$ quacks $arg$ at $hcname$.")
    )
  )
)

/* Hobbes, 970524 */
