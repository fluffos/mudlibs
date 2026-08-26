(gulp
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You gulp.")
      (rest "$mcname$ gulps.")
    )
    (arguments
      (arguments horrified,nervously,happily,sadly,in astonishment,excetedly,
                 in fright,in terror,astonishment,loudly,in shock,
                 in amazement,carefully,#) 
      (self "You gulp $arg$.")
      (rest "$mcname$ gulps $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You gulp at $hcname$.")
      (target "$mcname$ gulps at you.")
      (rest  "$mcname$ gulps at $hcname$.")
    )
    (arguments
      (arguments horrified,nervously,happily,sadly,in astonishment,excetedly,
                 in fright,in terror,astonishment,loudly,in shock,
                 in amazement,carefully,#)  
      (self   "You gulp $arg$ at $hcname$.")
      (target "$mcname$ gulps $arg$ at you.")
      (rest  "$mcname$ gulps $arg$ at $hcname$.")
    )
  )
)

