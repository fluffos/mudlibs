(mutter
   (pattern "<indirect:any-living>")
   (pattern "<string>")
   (pattern "<string> [at] <indirect:any-living>")
   (pattern "[at] <indirect:any-living> <string>")
   (single
      (no-arguments
      (self "You mutter under your breath.")
      (rest "$mcname$ mutters under $mposs$ breath.")
      )
    (arguments
      (arguments lag,creators,TM's,#)
         (self "You mutter something about $arg$ under your breath.")
         (rest "$mcname$ mutters something about $arg$ under $mposs$ breath.")
      )
   )
   (targeted
      (no-arguments
      (self   "You mutter under your breath at $hcname$.")
      (target "$mcname$ mutters under $mposs$ breath at you.")
      (rest   "$mcname$ mutters under $mposs$ breath at $hcname$.")
    )
      (arguments
      (arguments lag,creators,TM's,#)
      (self   "You mutter under your breath about $arg$ at $hcname$.")
      (target "$mcname$ mutters under $mposs$ breath about $arg$ at you.")
      (rest   "$mcname$ mutters under $mposs$ breath about $arg$ at $hcname$.")
      )
   )
)
/*Hobbes 970311*/