(mother
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>") 
  (targeted
    (no-arguments
      (self   "You mother $hcname$.")
      (target "$mcname$ mothers you.")
      (rest   "$mcname$ mothers $hcname$.")
    )
    (arguments
      (arguments  fussily, happily, lovingly, caringly, 
                  carefully, worriedly, dotingly, 
                  like your mother would, like your father would, #)
      (self   "You mother $hcname$ $arg$.")
      (target "$mcname$ mothers you $arg$.")
      (rest   "$mcname$ mothers $hcname$ $arg$.")
    )
    (arguments
      (arguments  with a wooden spoon)
      (self   "You mother $hcname$ $arg$.")
      (target "$mcname$ mothers you $arg$.  Whap!  Whap!  Whap!")
      (rest   "$mcname$ mothers $hcname$ $arg$.")
    )
  )
)

