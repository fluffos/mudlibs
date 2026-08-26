/*
 * Created By Love ~ 8th February 2002
 */

(irating
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You show off your instrument rating.")
      (rest "$mcname$ shows off $mposs$ instrument rating.")
    )
    (arguments
      (arguments  huge, average, tiny, puny, brand new, impressive,
                  astronomical, mindboggling, bright blue, #)
      (self "You show off your $arg$ instrument rating.")
      (rest "$mcname$ shows off $mposs$ $arg$ instrument rating.")
    )
  )
  (targeted
    (no-arguments
      (self   "You show $hcname$ your instrument rating.")
      (target "$mcname$ shows you $mposs$ instrument rating.")
      (rest   "$mcname$ shows $hcname$ $mposs$ instrument rating.")
    )
    (arguments
      (arguments  huge, average, tiny, puny, brand new, impressive,
                  astronomical, mind boggling, bright blue, #)
      (self   "You show $hcname$ your $arg$ instrument rating.")
      (target "$mcname$ shows you $mposs$ $arg$ instrument rating.")
      (rest  "$mcname$ shows $hcname$ $mposs$ $arg$ instrument rating.")
    )
  )
)
