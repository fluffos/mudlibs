(weep
  (pattern "[for] <indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments unashamedly,sadly,uncontrollably)
      (self "You weep $arg$.")
      (rest "$mcname$ weeps $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You weep with $hcname$.")
      (target "$mcname$ weeps with you.")
      (rest   "$mcname$ weeps with $hcname$.")
    )
  )
)

