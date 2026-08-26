/*
 * Created By Love ~ 8th February 2002
 */

(curl
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You curl up into a ball.")
      (rest "$mcname$ curls up into a ball.")
    )
    (arguments
      (arguments  tiny, shiny, spherical, two-dimensional, dainty, cat-like,
                  drunken, #)
      (self "You curl up into a $arg$ ball.")
      (rest "$mcname$ curls up into a $arg$ ball.")
    )
  )
  (targeted
    (no-arguments
      (self   "You curl up on $mhcname$ lap.")
      (target "$mcname$ curls up on your lap.")
      (rest   "$mcname$ curls up on $mhcname$ lap.")
    )
    (arguments
      (arguments  sleepily, happily, sadly, reservedly, carefully, slowly,
                  lovingly, adoringly, #)
      (self   "You $arg$ curl up on $mhcname$ lap.")
      (target "$mcname$ $arg$ curls up on your lap.")
      (rest  "$mcname$ $arg$ curls up on $mhcname$ lap.")
    )
  )
)
