(snort
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments in contempt,in disgust,happily,backwards,sideways,cheekily)
      (self "You snort $arg$.")
      (rest "$mcname$ snorts $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments in contempt,in disgust,happily,backwards,sideways,cheekily)
      (self   "You snort $arg$ at $hcname$.")
      (target "$mcname$ snorts $arg$ at you.")
      (rest  "$mcname$ snorts $arg$ at $hcname$.")
    )
  )
)
/* HOBBES */
