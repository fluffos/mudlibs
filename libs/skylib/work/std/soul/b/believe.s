(believe
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You believe.")
      (rest "$mcname$ believes.")
    )
    (arguments
    (arguments  everything, nothing, some of it, most of it, all of it, 
                none of it, willingly, unwillingly, reluctantly, 
                completely, #)
      (self "You believe $arg$.")
      (rest "$mcname$ believes $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You believe $hcname$.")
    (target "$mcname$ believes you.")
    (rest "$mcname$ believes $hcname$.")
  )
  (arguments
    (arguments  willingly, unwillingly, reluctantly, completely, 
                not at all, devotedly, till the ends of the earth, #)
    (self "You believe $hcname$ $arg$." )
    (target "$mcname$ believes you $arg$." )
    (rest "$mcname$ believes $hcname$ $arg$." )
    )
  )
)

/* Saffra 2-20-00 */

