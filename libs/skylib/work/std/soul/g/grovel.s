(grovel
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You grovel.")
      (rest "$mcname$ grovels.")
    )
    (arguments
      (arguments shamelessly,violently,unashamedly)
      (self "You grovel $arg$.")
      (rest "$mcname$ grovels $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You grovel at $mhcname$ feet.")
      (target "$mcname$ grovels at your feet.")
      (rest  "$mcname$ grovels at $mhcname$ feet.")
    )
    (arguments
      (arguments  shamelessly,violently,unashamedly)
      (self   "You grovel $arg$ at $mhcname$ feet.")
      (target "$mcname$ grovels $arg$ at your feet.")
      (rest  "$mcname$ grovels $arg$ at $mhcname$ feet.")
    )
  )
)

