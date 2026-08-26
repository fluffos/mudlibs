(swear
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You swear.")
      (rest "$mcname$ swears.")
    )
    (arguments
      (arguments violently,on your life,on the bible,on your mother's grave,loudly)
      (self "You swear $arg$.")
      (rest "$mcname$ swears $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You swear at $hcname$.")
      (target "$mcname$ swears at you.")
      (rest  "$mcname$ swears at $hcname$.")
    )
    (arguments
      (arguments  violently,on your life,on the bible,on your mother's grave,loudly)
      (self   "You swear $arg$ at $hcname$.")
      (target "$mcname$ swears $arg$ at you.")
      (rest  "$mcname$ swears $arg$ at $hcname$.")
    )
  )
)

