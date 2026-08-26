(bid
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You bid $hcname$ farewell.")
      (target "$mcname$ bids you farewell.")
      (rest   "$mcname$ bids $hcname$ farewell.")
    )
    (arguments
      (arguments farewell, to stay, God Speed, to gather shells, #)
      (self   "You bid $hcname$ $arg$.")
      (target "$mcname$ bids you $arg$.")
      (rest   "$mcname$ bids $hcname$ $arg$.")
    )
  )
)
