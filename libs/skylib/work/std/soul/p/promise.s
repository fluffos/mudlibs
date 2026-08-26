(promise
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  #)
      (self   "You promise $hcname$ $arg$.")
      (target "$mcname$ promises you $arg$.")
      (rest  "$mcname$ promises $hcname$ something.")
    )
  )
)


