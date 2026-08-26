(whine
  (pattern "[at|to] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at|to] <indirect:any-living>")
  (pattern "[at|to] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You whine.")
      (rest "$mcname$ whines.")
    )
    (arguments
      (arguments pathetically,unconvincingly,like Klahn,like a lost puppy)
      (self "You whine $arg$.")
      (rest "$mcname$ whines $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You whine at $hcname$.")
      (target "$mcname$ whines at you.")
      (rest   "$mcname$ whines at $hcname$.")
    )
    (arguments
      (arguments pathetically,unconvincingly,like klahn,like a lost puppy)
      (self   "You whine $arg$ at $hcname$.")
      (target "$mcname$ whines $arg$ at you.")
      (rest  "$mcname$ whines $arg$ at $hcname$.")
    )
  )
)

