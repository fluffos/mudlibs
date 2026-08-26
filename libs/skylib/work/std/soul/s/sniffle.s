(sniffle
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You sniffle.")
      (rest "$mcname$ sniffles.")
    )
    (arguments
      (arguments dejectedly, noisily, silently, loudly, in disdain, 
                 happily, sadly, dramatically, #)
      (self "You sniffle $arg$.")
      (rest "$mcname$ sniffles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You sniffle at $hcname$.")
      (target "$mcname$ sniffles at $hcname$.")
      (rest   "$mcname$ sniffles at $hcname$.")
    )
    (arguments
      (arguments dejectedly, noisily, silently, loudly, in disdain, 
                 happily, sadly, dramatically, #)
      (self   "You sniffle $arg$ at $hcname$.")
      (target "$mcname$ sniffles $arg$ at $hcname$.")
      (rest   "$mcname$ sniffles $arg$ at $hcname$.")
    )
  )
)

