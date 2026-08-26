(rub
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments hands together,eyes,tummy,nose,leg,arm,eyebrows,head)
      (self "You rub your $arg$.")
      (rest "$mcname$ rubs $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You rub $hcname$ up the wrong way.")
      (target "$mcname$ rubs you up the wrong way.")
      (rest  "$mcname$ rubs $hcname$ up the wrong way.")
    )
  )
)

