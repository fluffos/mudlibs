(point
  (pattern "[at] <string>")
  (pattern "[at] <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You point.")
      (rest "$mcname$ points.")
    )
    (arguments
      (arguments head,#)
      (self "You point at your $arg$.")
      (rest "$mcname$ points at $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You point at $hcname$.")
      (target "$mcname$ points at you.")
      (rest  "$mcname$ points at $hcname$.")
    )
    (arguments
      (arguments accusingly,straight)
      (self   "You point $arg$ at $hcname$.")
      (target "$mcname$ points $arg$ at you.")
      (rest  "$mcname$ points $arg$ at $hcname$.")
    )
  )
)

