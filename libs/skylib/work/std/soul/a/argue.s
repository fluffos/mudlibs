(argue
  (pattern "<string>")
  (pattern "[with] <indirect:any-living>")
  (pattern "<string> [with] <indirect:any-living>")
  (pattern "[with] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You argue the point.")
      (rest "$mcname$ argues the point.")
    )
    (arguments
      (arguments  happily, using big words, teasingly, flirtatiously,
                  nonchalantly, cunningly, illogically, mercilessly,
                  that the world's about to end, #)
      (self "You argue $arg$.")
      (rest "$mcname$ argues $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You argue with $hcname$.")
      (target "$mcname$ argues with you.")
      (rest   "$mcname$ argues with $hcname$.")
    )
    (arguments
      (arguments  the point, happily, using big words, teasingly, flirtatiously,
                  nonchalantly, cunningly, illogically, mercilessly,
                  that the world's about to end)
      (self   "You argue $arg$ with $hcname$.")
      (target "$mcname$ argues $arg$ with you.")
      (rest   "$mcname$ argues $arg$ with $hcname$.")
    )
    (arguments
      (arguments  the unfairness of it all, what happened,
                  whose fault it is,  trivial things,
                  whose turn it is to do the washing up, 
                  what colour the psychedelic frogs were, #)
      (self   "You argue with $hcname$ about $arg$.")
      (target "$mcname$ argues with you about $arg$.")
      (rest   "$mcname$ argues with $hcname$ about $arg$.")
    )
    (arguments
      (arguments  frog, womble)
      (self   "You argue that $hcname$ isn't a $arg$.")
      (target "$mcname$ argues that you aren't a $arg$.")
      (rest   "$mcname$ argues that $hcname$ isn't a $arg$.")
    )
  )
)

