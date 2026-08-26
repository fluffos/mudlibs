(tremble
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You tremble.")
      (rest "$mcname$ trembles.")
    )
    (arguments
      (arguments in fear, nervously, in pain, slightly, violently,
                 insistently, carefully, in a pink fit, passionately,
                 sensuously, slowly, quickly, jerkily, uncontrollably,
                 in excitement, in pleasure,
                 in anticip.......pation, #)
      (self "You tremble $arg$.")
      (rest "$mcname$ trembles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You tremble at $hcname$.")
      (target "$mcname$ trembles at you.")
      (rest "$mcname$ trembles at $hcname$.")
    )
  (arguments
    (arguments in fear, nervously, in pain, slightly, violently,
               insistently, carefully, in a pink fit, passionately,
               sensuously, slowly, quickly, jerkily, uncontrollably,  
               in excitement, in pleasure,
               in anticip.......pation, #)    
      (self "You tremble at $hcname$ $arg$." )
      (target "$mcname$ trembles at you $arg$." )
      (rest "$mcname$ trembles at $hcname$ $arg$." )
     )
  )
)
