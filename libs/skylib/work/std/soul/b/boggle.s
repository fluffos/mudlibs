(boggle
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments the concept,#)
      (self "You boggle at $arg$.")
      (rest "$mcname$ boggles at $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You boggle at $hcname$.")
      (target "$mcname$ boggles at you.")
      (rest  "$mcname$ boggles at $hcname$.")
    )
  )
)

