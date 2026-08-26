(roar
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You roar.")
      (rest "$mcname$ roars.")
    )
    (arguments
      (arguments loudly,happily,manically,evilly,wickedly,insanely,impishly,
                 cheekily,idiotically,repeatedly,like a drop bear,#)
      (self "You roar $arg$.")
      (rest "$mcname$ roars $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You roar at $hcname$.")
      (target "$mcname$ roars at you.")
      (rest  "$mcname$ roars at $hcname$.")
    )
    (arguments
       (arguments loudly,happily,manically,evilly,wickedly,insanely,impishly,
                 cheekily,idiotically,repeatedly,like a drop bear,#)
      (self   "You roar $arg$ at $hcname$.")
      (target "$mcname$ roars $arg$ at you.")
      (rest  "$mcname$ roars $arg$ at $hcname$.")
    )
  )	
)
