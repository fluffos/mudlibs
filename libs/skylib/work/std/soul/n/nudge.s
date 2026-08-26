(nudge
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You nudge $hcname$.")
      (target "$mcname$ nudges you.")
      (rest   "$mcname$ nudges $hcname$.")
    )
    (arguments
      (arguments  knowingly, experimentally, nicely, hopefully, meanly, cutely
                  accidentally, on purpose, accidentally-on-purpose, recklessly, 
                  enticingly, provocatively, happily, suggestively, 
                  convincingly, suggestively, half-heartedly, twice, 
                  for a second time, with abandon, with a ten-foot pole, #)
      (self   "You nudge $hcname$ $arg$.")
      (target "$mcname$ nudges you $arg$.")
      (rest   "$mcname$ nudges $hcname$ $arg$.")
    )
  )
)

