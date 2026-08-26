(mumble
   (pattern "<indirect:any-living>")
   (pattern "<string>")
   (pattern "<string> [at] <indirect:any-living>")
   (pattern "[at] <indirect:any-living> <string>")
   (single
      (no-arguments
      (self "You mumble under your breath.")
      (rest "$mcname$ mumbles under $mposs$ breath.")
      )
    (arguments
      (arguments lag,creators,TM's,#)
         (self "You mumble something about $arg$ under your breath.")
         (rest "$mcname$ mumbles something about $arg$ under $mposs$ breath.")
      )
   )
   (targeted
      (no-arguments
      (self   "You mumble under your breath at $hcname$.")
      (target "$mcname$ mumbles under $mposs$ breath at you.")
      (rest   "$mcname$ mumbles under $mposs$ breath at $hcname$.")
    )
      (arguments
      (arguments lag,creators,TM's,#)
      (self   "You mumble under your breath about $arg$ at $hcname$.")
      (target "$mcname$ mumbles under $mposs$ breath about $arg$ at you.")
      (rest   "$mcname$ mumbles under $mposs$ breath about $arg$ at $hcname$.")
      )
   )
)
