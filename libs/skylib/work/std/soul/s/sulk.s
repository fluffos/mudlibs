(sulk
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You sulk in the corner.")
      (rest "$mcname$ sulks in the corner.")
    )
  )
  (targeted
    (no-arguments
      (self "You sulk in the corner near $hcname$.")
      (target "$mcname$ sulks in the corner near you.")
      (rest "$mcname$ sulks in the corner near $hcname$.")
    )
  )
)

