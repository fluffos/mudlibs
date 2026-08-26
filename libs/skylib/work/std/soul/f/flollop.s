(flollop
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You flollop.")
      (rest "$mcname$ flollops.")
    )
    (arguments
    (arguments  around, like Zem, in a mattress-like manner, in a swamp, 
                on Sqornshellous Zeta, globberingly, #)
      (self "You flollop $arg$.")
      (rest "$mcname$ flollops $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You flollop at $hcname$.")
    (target "$mcname$ flollops at you.")
    (rest "$mcname$ flollops at $hcname$.")
  )
  (arguments
   (arguments like Zem, in a mattress-like manner, in a swamp,
                on Sqornshellous Zeta, globberingly, #)
    (self "You flollop at $hcname$ $arg$.")
    (target "$mcname$ flollops at you $arg$." )
    (rest "$mcname$ flollops at $hcname$ $arg$." )
    )
  )
)
