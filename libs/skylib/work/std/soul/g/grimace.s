(grimace
  (pattern "<indirect:any-living>")
  (pattern "[in] <string>")
  (pattern "<string> [in] <string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
        (self "You grimace.")
        (rest "$mcname$ grimaces.")
        )
      (arguments 
        (arguments disgust,anger,thought,power,despair)
 
      (self "You grimace in $arg$.")
      (rest "$mcname$ grimaces in $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You grimace at $hcname$.")
      (target "$mcname$ grimaces at you.")
      (rest  "$mcname$ grimaces at $hcname$.")
       )
      (arguments 
        (arguments disgust,anger,thought,power,despair)
      (self   "You grimace in $arg$ at $hcname$.")
      (target "$mcname$ grimaces in $arg$ at you.")
      (rest   "$mcname$ grimaces in $arg$ at $hcname$.")
    )
  )
)
/*Hobbes 970317*/
