(flatter
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>")
  (single
    (no-arguments
      (self "You flatter yourself.")
      (rest "$mcname$ flatters $mobj$self.")
    )
    (arguments
      (arguments   #)
      (self "You flatter $arg$.")
      (rest "$mcname$ flatters $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You flatter $hcname$.")
      (target "$mcname$ flatters you.")
      (rest   "$mcname$ flatters $hcname$.")
    )
    (arguments
      (arguments  sincerely, insincerely, excessively, slickly, cleverly, lots,          
                  like a professional, like a sycophant, wooingly, #)
      (self   "You flatter $hcname$ $arg$." )
      (target "$mcname$ flatters you $arg$." )
      (rest   "$mcname$ flatters $hcname$ $arg$." )
    )
  )
)

/* Saffra 2-29-00, idea by Gruper. */
