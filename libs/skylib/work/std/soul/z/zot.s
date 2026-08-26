(zot
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You zot anxiously.")
      (rest "$mcname$ zots anxiously.")
    )
    (arguments
        (arguments with the staff of Zot, #)
        (self "You zot $arg$.")
        (rest "$mcname$ zots $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You zot $hcname$.")
      (target "$mcname$ zots you.")
      (rest  "$mcname$ zots $hcname$.")
    )
    (arguments
        (arguments with the staff of Zot, #)
        (self "You zot $hcname$ $arg$.")
        (target "$mcname$ zots you $arg$.")
        (rest "$mcname$ zots $hcname$ $arg$.")
    )
  )
)

