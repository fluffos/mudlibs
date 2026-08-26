(giggle
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You giggle.")
      (rest "$mcname$ giggles.")
    )
   (arguments
     (arguments  inanely,stupidly,snort,quietly,idiotically,
      fiendishly,insanely,slightly,carefully,cutely,
    sarcastically,happily,#)
      (self "You giggle $arg$.")
      (rest "$mcname$ giggles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You giggle at $hcname$.")
      (target "$mcname$ giggles at you.")
      (rest  "$mcname$ giggles at $hcname$.")
    )
    (arguments
      (arguments  inanely,stupidly,snort,quietly,idiotically,
       fiendishly,insanely,slightly,carefully,cutely,sarcastically,happily,#)
      (self   "You giggle $arg$ at $hcname$.")
      (target "$mcname$ giggles $arg$ at you.")
      (rest  "$mcname$ giggles $arg$ at $hcname$.")
     )
   )
 )




