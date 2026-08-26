(moo
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> at <indirect:any-living>")
  (single
    (no-arguments
      (self "You moo.")
      (rest "$mcname$ moos.")
    )
    (arguments
      (arguments like a cow,like a bottle of milk,like a tree,happily,
                 annoyingly,like Hobbes,from halfway up a tree,#)
      (self "You moo $arg$.")
      (rest "$mcname$ moos $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You moo at $hcname$.")
      (target "$mcname$ moos at you.")
      (rest  "$mcname$ moos at $hcname$.")
    )
    (arguments
      (arguments like a cow,like a bottle of milk,like a tree,
                 happily,annoyingly,like Hobbes,from halfway up a tree,#)
      (self   "You moo $arg$ at $hcname$.")
      (target "$mcname$ moos $arg$ at you.")
      (rest  "$mcname$ moos $arg$ at $hcname$.")
    )
  )
)

/* Hobbes, 961204 */
