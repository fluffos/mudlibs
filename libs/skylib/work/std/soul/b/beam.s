(beam
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
(arguments brightly, admiringly, strangely, happily, ecstatically, fishily,
           like a train, #)
      (self "You beam $arg$.")
      (rest "$mcname$ beams $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You beam at $hcname$.")
      (target "$mcname$ beams at you.")
      (rest  "$mcname$ beams at $hcname$.")
    )
    (arguments
(arguments brightly, admiringly, strangely, happily, ecstatically, fishily,
           like a train, #)
      (self   "You beam at $hcname$ $arg$.")
      (target "$mcname$ beams at you $arg$.")
      (rest  "$mcname$ beams at $hcname$ $arg$.")
    )
  )
)

