(prescribe
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  dried frog pills, narcotics, #)
      (self   "You prescribe a dose of $arg$ for $hcname$.")
      (target "$mcname$ prescribes a dose of $arg$ $hcname$.")
      (rest  "$mcname$ prescribes a dose of $arg$ $hcname$.")
    )
  )
)

