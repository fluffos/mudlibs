(massage
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You give $hcname$ a massage.")
      (target "$mcname$ gives you a massage.")
      (rest   "$mcname$ gives $hcname$ a massage.")
    )
    (arguments
      (arguments good,bad,ugly,long,refreshing,pink,full body,
                 seductive,sensuous,strange,painful,deep,meaningful,
                 ergonomic,economic,painless,memorable,different,
                 unwanted,unwarranted,unprovoked,unknown,sneaky,
                 unnoticed,unwieldy,back,professional,unprofessional,
                 happy,sad,trained,untrained,train,virgin mary,
                 compact,quick,foot,leg,arm,head,teeth,ear,neck,
                 shoulder,nose, sensual, #)

      (self   "You give $hcname$ a $arg$ massage.")
      (target "$mcname$ gives you a $arg$ massage.")
      (rest   "$mcname$ gives $hcname$ a $arg$ massage.")
    )
    (arguments
      (arguments oiled)
      (self   "You give $hcname$ an $arg$ massage.")
      (target "$mcname$ gives you an $arg$ massage.")
      (rest   "$mcname$ gives $hcname$ an $arg$ massage.")
    )
  )
)

