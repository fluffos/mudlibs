(laugh
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "[with] <indirect:any-living>")
  (single
    (no-arguments
      (self "You laugh.")
      (rest "$mcname$ laughs.")
    )
    (arguments
      (arguments  nastily, nicely, quietly, uncontrollably, politely, happily,
                  manically, ecstatically, demonically, out loud, maniacally,
                  hysterically, evilly, mischievously, #)
      (self "You laugh $arg$.")
      (rest "$mcname$ laughs $arg$.")
    )
    (arguments
     (arguments fall)
     (self "You fall down laughing.")
     (rest "$mcname$ falls down laughing.")
    )
   )
  (targeted
    (no-arguments
      (self   "You laugh at $hcname$.")
      (target "$mcname$ laughs at you.")
      (rest   "$mcname$ laughs at $hcname$.")
    )
    (arguments
      (arguments  nastily, nicely, quietly, uncontrollably, politely, happily,
                  manically, ecstatically, demonically, out loud, maniacally,
                  hysterically, evilly, mischievously, #)
      (self   "You laugh $arg$ at $hcname$.")
      (target "$mcname$ laughs $arg$ at you.")
      (rest   "$mcname$ laughs $arg$ at $hcname$.")
    )
      (arguments
        (arguments with,#)
        (self  "You laugh $arg$ $hcname$.")
        (target "$mcname$ laughs $arg$ you.")
        (rest   "$mcname$ laughs $arg$ $hcname$.")
        )
      )
    )


