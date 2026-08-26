(furbert
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (self   "You furbert $hcname$ $arg$.")
      (target "$mcname$ furberts you $arg$.")
      (rest  "$mcname$ furberts $hcname$ $arg$.")
      (arguments  on the tummy,on the arm,on the foot,on the forehead,on the hand,on the leg,all over the body)
    )
  )
)

