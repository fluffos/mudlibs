(twirl
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You twirl $hcname$ round in circles.")
      (target "$mcname$ twirls you round in circles.")
      (rest  "$mcname$ twirls $hcname$ round in circles.")
    )
  )
)

