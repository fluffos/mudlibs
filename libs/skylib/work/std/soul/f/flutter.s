(flutter
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You flutter your eyelashes.")
      (rest "$mcname$ flutters $mposs$ eyelashes.")
    )
  )
  (targeted
    (no-arguments
      (self   "You flutter your eyelashes at $hcname$.")
      (target "$mcname$ flutters $mposs$ eyelashes at you.")
      (rest  "$mcname$ flutters $mposs$ eyelashes at $hcname$.")
    )
  )
)

