(accuse
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [of] <string>")
  (single
    (no-arguments
      (self "The butler did it!")
      (rest "$mcname$ accuses the butler.")
    )
    (arguments
      (arguments #)
      (self "You accuse $arg$.")
      (rest "$mcname$ accuses $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You accuse $hcname$.")
      (target "$mcname$ accuses you.")
      (rest  "$mcname$ accuses $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You accuse $hcname$ of $arg$.")
      (target "$mcname$ accuses you of $arg$.")
      (rest  "$mcname$ accuses $hcname$ of $arg$.")
    )
  )
)

