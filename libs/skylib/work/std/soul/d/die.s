(die
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments  suddenly, dramatically, of boredom, of hunger, 
                  of anticipation, pathetically, gracefully, senselessly, 
                  stupidly, tragically, slowly, painfully, quickly
                  an excruciating death, in no specific direction, #)
      (self "You die $arg$.")
      (rest "$mcname$ dies $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You die in $mhcname$ general direction.")
      (target "$mcname$ dies in your general direction.")
      (rest   "$mcname$ dies in $mhcname$ general direction.")
    )
    (arguments
      (arguments  arms)
      (self   "You die in $mhcname$ arms.")
      (target "$mcname$ dies in your arms.")
      (rest   "$mcname$ dies in $mhcname$ arms.")
    )
    (arguments
      (arguments  suddenly, dramatically, of boredom, of hunger, 
                  of anticipation, pathetically, gracefully, senselessly, 
                  stupidly, tragically, slowly, painfully, quickly
                  an excruciating death, #)
      (self   "You die $arg$ in $mhcname$ general direction.")
      (target "$mcname$ dies $arg$ in your general direction.")
      (rest   "$mcname$ dies $arg$ in $mhcname$ general direction.")
    )
  )
)

