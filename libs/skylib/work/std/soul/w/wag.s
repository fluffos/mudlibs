(wag
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<indirect:any-living> [at] <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You wag your tail.")
      (rest "$mcname$ wags $mposs$ tail.")
    )
    (arguments
      (arguments eyebrows, nose, ear, toe, foot, arm, leg, coffee table,
                  shower hose, green shoes)
      (self "You wag your $arg$.")
      (rest "$mcname$ wags $mposs$ $arg$.")
    )
    (arguments
      (arguments happily,enticingly,suggestively,vigorously,arrogantly,
                 nonchalantly,quickly,tunelessly)
      (self "You wag your tail $arg$.")
      (rest "$mcname$ wags $mposs$ tail $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wag your tail at $hcname$.")
      (target "$mcname$ wags $mposs$ tail at you.")
      (rest   "$mcname$ wags $mposs$ tail at $hcname$.")
    )
    (arguments
      (arguments eyebrows, nose, ear, toe, foot, arm, leg, coffee table,
                  shower hose, green shoes)
      (self "You wag your $arg$ at $hcname$.")
      (target "$mcname$ wags $mposs$ $arg$ at you.")
      (rest "$mcname$ wags $mposs$ $arg$ at $hcname$.")
    )
    (arguments
      (arguments happily,enticingly,suggestively,vigorously,arrogantly,
                 tunelessly,nonchalantly,quickly)
      (self   "You wag your tail $arg$ at $hcname$.")
      (target "$mcname$ wags $mposs$ tail $arg$ at you.")
      (rest   "$mcname$ wags $mposs$ tail $arg$ at $hcname$.")
    )
  )
)

