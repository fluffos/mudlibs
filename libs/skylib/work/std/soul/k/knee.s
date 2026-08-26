(knee
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You knee $hcname$.")
      (target "$mcname$ knees you.")
      (rest  "$mcname$ knees $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You knee $hcname$ $arg$.")
      (target "$mcname$ knees you $arg$.")
      (rest  "$mcname$ knees $hcname$ $arg$.")
    )
  )
)

