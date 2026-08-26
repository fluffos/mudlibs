(roll
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<string> at <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments  around on the floor laughing, up into a paper to be delivered, 
                  up into a ball, over and plays dead, sideways, backwards, 
                  professionally, like a spy through an imaginary door, 
                  fearfully, tightly, slowly, a joint)
      (self "You roll $arg$.")
      (rest "$mcname$ rolls $arg$.")
    )
    (arguments
      (arguments eyes,own cigarette)
      (self "You roll your $arg$.")
      (rest "$mcname$ rolls $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You roll over $hcname$.")
      (target "$mcname$ rolls over you.")
      (rest   "$mcname$ rolls over $hcname$.")
    )
    (arguments
      (arguments  quickly, slowly, painfully, excitedly, lovingly, carefully)
      (self   "You roll $arg$ over $hcname$.")
      (target "$mcname$ rolls $arg$ over you.")
      (rest   "$mcname$ rolls $arg$ over $hcname$.")
    )
    (arguments
       (arguments  eyes,own cigarette)
       (self   "You roll your $arg$ at $hcname$.")
       (target "$mcname$ rolls $mposs$ $arg$ at you.")
       (rest   "$mcname$ rolls $mposs$ $arg$ at $hcname$.")
    )
    (arguments
      (arguments  around on the floor laughing)
      (self    "You roll $arg$ at $hcname$.")
      (target  "$mcname$ rolls $arg$ at you.")
      (rest    "$mcname$ rolls $arg$ at $hcname$.")
    )
  )
)

