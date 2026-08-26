(wuzzle
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wuzzle woozle.")
      (rest "$mcname$ wuzzle woozles.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wuzzle woozle at $hcname$.")
      (target "$mcname$ wuzzle woozles at you.")
      (rest  "$mcname$ wuzzle woozles at $hcname$.")
    )
  )
)

