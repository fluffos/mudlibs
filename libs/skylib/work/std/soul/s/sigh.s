(sigh
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You sigh.")
      (rest "$mcname$ sighs.")
    )
   (arguments 
     (arguments deeply, silently, desperately, tiredly, sadly, slowly, dreamily,
                happily, melodramatically, wistfully, dramatically, heavily,
                suggestively, sarcastically, in relief, with relief,
                contentedly, seductively, softly, quietly, disconsolately,
                desolately, #)
      (self "You sigh $arg$.")
      (rest "$mcname$ sighs $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You sigh at $hcname$.")
      (target "$mcname$ sighs at you.")
      (rest  "$mcname$ sighs at $hcname$.")
    )
    (arguments
     (arguments deeply, silently, desperately, tiredly, sadly, slowly, dreamily,
                happily, melodramatically, wistfully, dramatically, heavily,
                suggestively, sarcastically, in relief, with relief,
                contentedly, seductively, softly, quietly, disconsolately,
                desolately, #)
      (self   "You sigh $arg$ at $hcname$.")
      (target "$mcname$ sighs $arg$ at you.")
      (rest  "$mcname$ sighs $arg$ at $hcname$.")
     )
   )
 )
