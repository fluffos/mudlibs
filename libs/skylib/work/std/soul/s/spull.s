(spull
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
     (arguments over, under, away, along, around, up, down)
      (self "You pull $hcname$ $arg$.")
      (target "$mcname$ pulls you $arg$.")
      (rest "$mcname$ pulls $hcname$ $arg$.")
    )
  )
)
/* Saffra, 4-26-00 */

