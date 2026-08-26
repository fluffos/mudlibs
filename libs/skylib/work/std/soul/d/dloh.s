(dloh
  (pattern "[onto] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments nose,#)
      (self "You hold your $arg$.")
      (rest "$mcname$ holds $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hold $hcname$.")
      (target "$mcname$ holds you.")
      (rest  "$mcname$ holds $hcname$.")
    )
    (arguments
      (arguments  close,tightly,warmly,gently,lovingly,back,up)
      (self   "You hold $hcname$ $arg$.")
      (target "$mcname$ holds you $arg$.")
      (rest  "$mcname$ holds $hcname$ $arg$.")
    )
  )
)

