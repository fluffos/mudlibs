(wrap
  (pattern "<indirect:any-living> [up]")
  (pattern "<string> [around] <indirect:any-living>")
  (pattern "<indirect:any-living> [up] <string>")
  (targeted
    (no-arguments
      (self   "You wrap $hcname$ up.")
      (target "$mcname$ wraps you up.")
      (rest   "$mcname$ wraps $hcname$ up.")
    )
    (arguments
      (arguments in string, carefully, in wrapping paper, slowly,
                 in a blanket, in newspaper, #)
      (self   "You wrap $hcname$ up $arg$.")
      (target "$mcname$ wraps you up $arg$.")
      (rest   "$mcname$ wraps $hcname$ up $arg$.")
    )
    (arguments
      (arguments arms, legs, wings, flippers)
      (self   "You wrap your $arg$ around $hcname$.")
      (target "$mcname$ wraps $mposs$ $arg$ around you.")
      (rest   "$mcname$ wraps $mposs$ $arg$ around $hcname$.")
    )
  )
)
