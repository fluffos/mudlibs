(shoot
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You shoot yourself.")
      (rest "$mcname$ shoots $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You shoot $hcname$ with an arrow.")
      (target "$mcname$ shoots you with an arrow.")
      (rest  "$mcname$ shoots $hcname$ with an arrow.")
    )
    (arguments
      (arguments  butt,head,eye,ear,leg,arm,toe,foot,hand,mouth,neck)
      (self   "You shoot $hcname$ in the $arg$ with an arrow.")
      (target "$mcname$ shoots you in the $arg$ with an arrow.")
      (rest  "$mcname$ shoots $hcname$ in the $arg$ with an arrow.")
    )
  )
)

