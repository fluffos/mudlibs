(womble
  (pattern "[around] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [around] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You womble around.")
      (rest "$mcname$ wombles around.")
    )
    (arguments
      (arguments #)
      (self "You womble around $arg$.")
      (rest "$mcname$ wombles around $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments happily, peacefully, brightly, sadly, greenly, backwards,
                 orinocoly, wellingtonly, bungoly, tomskly, with your frog,
                 commonly, twice, once, with a hey nonny nonny,
                 doing a dance to the great frog in the sky)
      (self   "You womble around $hcname$ $arg$.")
      (target "$mcname$ wombles around you $arg$.")
      (rest   "$mcname$ wombles around $hcname$ $arg$.")
    )
  )
)

