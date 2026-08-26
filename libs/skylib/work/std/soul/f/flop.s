(flop
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [into] <string>")
  (pattern "<indirect:any-living> [onto] <string>")
  (single
    (arguments
      (arguments helplessly, like a fish out of water, badly, like zoroaster,
                 carefully, rudely, a bit, once, like a gherkin, wonderfully,
                 impressively, suggestively, lazily, happily, pensively,
                 onto a pillow)
      (self "You flop about $arg$.")
      (rest "$mcname$ flops about $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You flop on $hcname$.")
      (target "$mcname$ flops on you.")
      (rest  "$mcname$ flops on $hcname$.")
    )
    (arguments
      (arguments arms, legs, lap, dreams)
      (self   "You flop into $mhcname$ $arg$.")
      (target "$mcname$ flops into your $arg$.")
      (rest  "$mcname$ flops into $mhcname$ $arg$.")
    )
    (arguments
      (arguments chest, bed, sofa, pillows, floor, carpet, laundry floor,
                 kitchen floor, quilt, fluffy pillow, bicycle, car,
                 dreams, inspirations, thoughts, desires,
                 soft curvaceous pillows)
      (self   "You flop onto $mhcname$ $arg$.")
      (target "$mcname$ flops onto your $arg$.")
      (rest  "$mcname$ flops onto $mhcname$ $arg$.")
    )
  )
)
