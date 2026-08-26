(burst
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments into laughter,into tears,messily,spectacularly,at the seams,
                 like a water pipe,like the water tanks atop of a skyscraper)
      (self   "You burst $arg$.")
      (target "$mcname$ bursts $arg$.")
      (rest  "$mcname$ bursts $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You burst into laughter with $hcname$.")
      (target "$mcname$ bursts into laughter with you.")
      (rest  "$mcname$ bursts into laughter with $hcname$.")
    )
    (arguments
      (arguments quietly,loudly,wildly)
      (self   "You burst $arg$ into laughter with $hcname$.")
      (target "$mcname$ bursts $arg$ into laughter with you.")
      (rest  "$mcname$ bursts $arg$ into laughter with $hcname$.")
    )
  )
)
