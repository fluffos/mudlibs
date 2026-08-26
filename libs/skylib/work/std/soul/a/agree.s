(agree
  (pattern "[with] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [with] <indirect:any-living>")
  (pattern "[with] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments wholeheartedly,partially,wearily,sadly,reluctantly,with reluctance)
      (self "You agree $arg$.")
      (rest "$mcname$ agrees $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments wholeheartedly,partially,wearily,sadly,reluctantly,with reluctance)
      (self   "You agree $arg$ with $hcname$.")
      (target "$mcname$ agrees $arg$ with you.")
      (rest  "$mcname$ agrees $arg$ with $hcname$.")
    )
  )
)
