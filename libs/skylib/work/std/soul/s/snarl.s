(snarl
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments  viciously, nastily, demonically, happily, sadly,
                  unexpectedly, suddenly)
      (self   "You snarl $arg$.")
      (target "$mcname$ snarls $arg$.")
      (rest  "$mcname$ snarls $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  viciously, nastily, demonically, happily, sadly,
                  unexpectedly, suddenly)
      (self   "You snarl $arg$ at $hcname$.")
      (target "$mcname$ snarls $arg$ at you.")
      (rest  "$mcname$ snarls $arg$ at $hcname$.")
    )
  )
)

