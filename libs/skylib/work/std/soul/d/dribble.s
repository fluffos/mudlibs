(dribble
  (pattern "all over <indirect:any-living>")
  (pattern "[on] <indirect:any-living>")
  (single
    (no-arguments
      (self "You start to dribble all over the front of your shirt.")
      (rest "$mcname$ starts to dribble all over the front of $mposs$ shirt.")
    )
  )
  (targeted
    (no-arguments
      (self   "You start dribbling on $hcname$.")
      (target "$mcname$ starts dribbling all over your best shirt.")
      (rest  "$mcname$ starts dribbling all over $hcname$.")
    )
  )
)

