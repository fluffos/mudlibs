(smooch
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You give $hcname$ a big wet smooch on the lips.")
      (target "$mcname$ gives you a big wet smooch on the lips.")
      (rest   "$mcname$ gives $hcname$ a big wet smooch on the lips.")
    )
    (arguments
      (arguments wet,nice,passionate,soft,careful,fishy,friendly,)
      (self   "You give $hcname$ a $arg$ smooch on the lips.")
      (target "$mcname$ gives you a $arg$ smooch on the lips.")
      (rest   "$mcname$ gives $hcname$ a $arg$ smooch on the lips.")
    )
  )
)
