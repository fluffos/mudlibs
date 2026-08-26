(twang
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments calmly,with the wolves,a nice little tune,up,down,manically,rhythmically,undyingly,backwards,beautifully,upside down)
      (self "You twang $arg$.")
      (rest "$mcname$ twangs $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  calmly,with the wolves,a nice little tune,up,down,manically,rhythmically,undyingly,backwards,beautifully,upside down)
      (self   "You twang $arg$ at $hcname$.")
      (target "$mcname$ twangs $arg$ at you.")
      (rest  "$mcname$ twangs $arg$ at $hcname$.")
    )
  )
)

