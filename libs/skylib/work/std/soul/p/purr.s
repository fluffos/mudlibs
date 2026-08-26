(purr
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
   (arguments 
     (arguments  contentedly,demonically,loudly,happily,sensuously,
      like a cute kitten)
      (self "You purr $arg$.")
      (rest "$mcname$ purrs $arg$.")
    )
  )
  (targeted     
    (arguments
      (arguments contentedly,demonically,loudly,happily,sensuously,
       like a cute kitten)
      (self   "You purr $arg$ at $hcname$.")
      (target "$mcname$ purrs $arg$ at you.")
      (rest  "$mcname$ purrs $arg$ at $hcname$.")
     )
   )
 )

