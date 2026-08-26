(congrat
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You congratulate everyone.")
      (rest "$mcname$ congratulates everyone.")
    )
    (arguments
      (arguments heartily,warmly)
      (self "You $arg$ congratulate everyone.")
      (rest "$mcname$ $arg$ congratulates everyone.")
    )
  )
  (targeted
    (no-arguments
      (self   "You congratulate $hcname$.")
      (target "$mcname$ congratulates you.")
      (rest  "$mcname$ congratulates $hcname$.")
    )
    (arguments
      (arguments  heartily,warmly)
      (self   "You $arg$ congratulate $hcname$.")
      (target "$mcname$ $arg$ congratulates you.")
      (rest  "$mcname$ $arg$ congratulates $hcname$.")
    )
  )
)

