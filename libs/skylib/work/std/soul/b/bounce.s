(bounce
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [around] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "B O U N C E ! !")
      (rest "$mcname$ bounces around.")
    )
    (arguments
      (arguments excitedly,fearfully,happily,wildly)
      (self "You bounce around $arg$.")
      (rest "$mcname$ bounces around $arg$.")
    )
    (arguments
      (arguments off walls)
      (self "You bounce $arg$")
      (rest "$mcname$ bounces $arg$")
    )
  )
  (targeted
    (no-arguments
      (self   "You bounce around $hcname$.")
      (target "$mcname$ bounces around you.")
      (rest  "$mcname$ bounces around $hcname$.")
    )
    (arguments
      (arguments  happily,carefully,wildly,excitedly,pinkly,joyfully,once,slowly,suggestively,viciously,sarcastically,happily,womblely,#)
      (self   "You bounce around $hcname$ $arg$.")
      (target "$mcname$ bounces around you $arg$.")
      (rest  "$mcname$ bounces around $hcname$ $arg$.")
    )
  )
)

