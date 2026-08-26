(be
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You appear to be about to type 'help essentials'.")
      (rest "$mcname$ appears to be about to type 'help essentials'.")
    )
    (arguments
      (arguments #)
      (self "You appear to be $arg$.")
      (rest "$mcname$ appears to be $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You appear to be $hcname$.")
      (target "$mcname$ appears to be you.")
      (rest  "$mcname$ appears to be $hcname$.")
    )
  )
)
