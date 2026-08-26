(pinch
  (pattern "<indirect:any-living> on the <string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> [on] <string>")
  (single
    (no-arguments
      (self "You pinch yourself.")
      (rest "$mcname$ pinches $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You pinch $hcname$.")
      (target "$mcname$ pinches you.")
      (rest  "$mcname$ pinches $hcname$.")
    )
    (arguments
      (arguments  bottom,leg,arm,frog,cheek)
      (self   "You pinch $hcname$ on the $arg$.")
      (target "$mcname$ pinches you on the $arg$.")
      (rest  "$mcname$ pinches $hcname$ on the $arg$.")
    )
  )
)

