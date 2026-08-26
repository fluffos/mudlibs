(lambada
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You lambada by yourself.")
      (rest "$mcname$ lambadas by $mobj$self.")
    )
    (arguments  
    (arguments  sensuously, happily, hard and heavy, fast and furious,
                in high heels, across the dance floor, in a smoky dance 
                club, slowly, seductively, closely, tightly, clumsily,
                carelessly, like a Latin lover, #)
      (self "You lambada $arg$.")
      (rest "$mcname$ lambadas $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You lambada with $hcname$.")
    (target "$mcname$ lambadas with you.")
			 (rest "$mcname$ lambadas with $hcname$.")
  )
  (arguments
    (arguments  sensuously, happily, hard and heavy, fast and furious,
                in high heels, across the dance floor, in a smoky dance 
                club, slowly, seductively, closely, tightly, clumsily,
                carelessly, like a Latin lover, #)
    (self "You lambada $arg$ with $hcname$." )
    (target "$mcname$ lambadas $arg$ with you." )
    (rest "$mcname$ lambadas $arg$ with $hcname$.")
   )
  )
)
