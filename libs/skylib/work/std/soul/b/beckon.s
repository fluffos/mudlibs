(beckon
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You beckon to $hcname$ to come closer.")
      (target "$mcname$ beckons to you to come closer.")
      (rest  "$mcname$ beckons to $hcname$ to come closer.")
    )
    (arguments
      (arguments quickly,subtly,calmly,patiently,hastily)
      (self   "You $arg$ beckon to $hcname$ to come closer.")
      (target "$mcname$ $arg$ beckons you to come closer.")
      (rest  "$mcname$ $arg$ beckons $hcname$ to come closer.")
    )
  )
)

