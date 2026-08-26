(tm
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You masquerade as a giant TM and run around the room.")
      (rest "$mcname$ masquerades as a giant TM and runs around the room.")
    )
  )
  (targeted
    (arguments
      (arguments  chases,wombles happily around,stares jealously at,envies,bings happily at,throws coffee tables at)
      (self   "You turn $hcname$ into a giant TM, and watch as everyone $arg$ $hobj$.")
      (target "$mcname$ turns you into a giant TM.  Everyone $arg$ you.")
      (rest  "$mcname$ turns $hcname$ into a giant TM.  Everyone $arg$ $hobj$.")
    )
  )
)


