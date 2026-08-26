(tilt
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self   "You tilt your head.")
      (target "$mcname$ tilts $mposs$ head.")
      (rest  "$mcname$ tilts $mposs$ head.")
    )
    (arguments
      (arguments to one side, to the left, to the right,
                 sideways, to one side and the other, # )
      (self "You tilt your head $arg$.")
      (rest "$mcname$ tilts $mposs$ head $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You tilt your head at $hcname$.")
      (target "$mcname$ tilts $mposs$ head at you.")
      (rest  "$mcname$ tilts $mposs$ head at $hcname$.")
    )
    (arguments
      (arguments quietly, curiously, # )
      (self   "You tilt your head at $hcname$ $arg$.")
      (target "$mcname$ tilts $mposs$ head at you $arg$.")
      (rest  "$mcname$ tilts $mposs$ head at $hcname$ $arg$.")
    )
  )
)
