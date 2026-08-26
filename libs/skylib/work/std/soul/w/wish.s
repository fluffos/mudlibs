(wish
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
     (arguments christmas, easter, birthday)
      (self "You wish $hcname$ a happy $arg$.")
      (target "$mcname$ wishes you a happy $arg$.")
      (rest "$mcname$ wishes $hcname$ a happy $arg$.")
     )
     (arguments
     (arguments well)
      (self "You wish $hcname$ $arg$.")
      (target "$mcname$ wishes you $arg$.")
      (rest "$mcname$ wishes $hcname$ $arg$.")
     )
    )
  )
)
