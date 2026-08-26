(spock
  (pattern "[at] <indirect:any-living>")
  (pattern "[in] <string>")
  (pattern "[in] <string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> [in] <string>")
  (single
    (no-arguments
      (self "You raise one eyebrow.")
      (rest "$mcname$ raises one eyebrow.")
    )
  )
  (targeted
    (no-arguments 
      (self   "You raise one eyebrow at $hcname$.")
      (target "$mcname$ raises one eyebrow at you.")
      (rest  "$mcname$ raises one eyebrow at $hcname$.")
    )
  )
)

