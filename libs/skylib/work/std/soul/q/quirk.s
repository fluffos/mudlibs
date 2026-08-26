(quirk
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You quirk one eyebrow.")
      (rest "$mcname$ quirks one eyebrow.")
    )
  )
  (targeted
    (no-arguments
      (self "You quirk one eyebrow at $hcname$.")
      (target "$mcname$ quirks one eyebrow at you.")
      (rest "$mcname$ quirks one eyebrow at $hcname$.")
    )
  )
)

