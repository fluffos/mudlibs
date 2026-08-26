(smack
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You smack your lips.")
      (rest "$mcname$ smacks $mposs$ lips.")
    )
  )
  (targeted
    (no-arguments
      (self   "You smack $hcname$.")
      (target "$mcname$ smacks you.")
      (rest  "$mcname$ smacks $hcname$.")
    )
    (arguments
      (arguments  furiously,with gusto,without a care,twice,lots of times,happily,nastily,excitedly,upside the head with a coffee table,with a tabby cat,unbelieveably hard,with a smallish potted plant,with a keyboard)
      (self   "You smack $hcname$ $arg$.")
      (target "$mcname$ smacks you $arg$.")
      (rest  "$mcname$ smacks $hcname$ $arg$.")
    )
  )
)

