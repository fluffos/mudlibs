(boingy
  (pattern "<string>")
  (pattern "[around] <indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You boingy.")
      (rest "$mcname$ boingies.")
    )
    (arguments
      (arguments insanely, happily, lovingly, with a squeak, fluffily, 
                  sarcasticly, with bells on, with pride, #)
      (self    "You boingy $arg$.")
      (rest   "$mcname$ boingies $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You boingy around $hcname$.")
      (target "$mcname$ boingies around you.")
      (rest   "$mcname$ boingies around $hcname$.")
    )
    (arguments
      (arguments  insanely, happily, lovingly, with a squeak, fluffily, 
                  sarcasticly, with bells on, with pride, #)
      (self    "You boingy $arg$ at $hcname$.")
      (target "$mcname$ boingies $arg$ at you.")
      (rest   "$mcname$ boingies $arg$ at $hcname$.")
    )
  )
)
