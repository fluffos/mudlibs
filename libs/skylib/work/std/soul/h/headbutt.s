(headbutt
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You headbutt $hcname$.")
      (target "$mcname$ headbutts you.")
      (rest  "$mcname$ headbutts $hcname$.")
    )
    (arguments
      (arguments hard, in the nose, on the ear, slowly, unexpectedly,
                 quickly, explosively, pointedly, #)
      (self   "You headbutt $hcname$ $arg$.")
      (target "$mcname$ headbutts you $arg$.")
      (rest  "$mcname$ headbutts $hcname$ $arg$.")
    )
  )
)

