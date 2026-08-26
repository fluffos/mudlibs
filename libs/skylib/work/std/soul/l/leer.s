(leer
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You leer at yourself.")
      (rest "$mcname$ leers at $mobj$self... hmmm, interesting....")
    )
  )
  (targeted
    (no-arguments
      (self   "You leer at $hcname$.")
      (target "$mcname$ leers at you.")
      (rest  "$mcname$ leers at $hcname$.")
    )
  )
)

