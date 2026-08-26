(shuffle
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
   (no-arguments 
      (self "You shuffle your feet in embarrassment.")
      (rest "$mcname$ shuffles $mposs$ feet in embarrassment.")
    )
  )
  (targeted     
    (arguments
      (arguments away from,up to,towards)
      (self   "You shuffle $arg$ $hcname$.")
      (target "$mcname$ shuffles $arg$ you.")
      (rest  "$mcname$ shuffles $arg$ $hcname$.")
     )
   )
 )
