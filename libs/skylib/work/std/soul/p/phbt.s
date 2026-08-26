(phbt
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You go: \"Phbttptblptt!\"")
      (rest "$mcname$ goes: \"Phbttptblptt!\"")
       )
  )
  (targeted
    (no-arguments
      (self   "You go: \"Phbttptblptt!\" at $hcname$.")
      (target "$mcname$ goes: \"Phbttptblptt!\" at you.")
      (rest  "$mcname$ goes: \"Phbttptblptt!\" at $hcname$.")
    )
  )
)

