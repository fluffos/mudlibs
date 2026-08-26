(puke
  (pattern "[on|at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You brighten up the place.")
      (rest "$mcname$ does a technicolour yawn.")
    )
  )
  (targeted
    (no-arguments
      (self   "You puke on $hcname$.")
      (target "$mcname$ pukes on you.")
      (rest  "$mcname$ pukes on $hcname$.")
    )
  )
)

