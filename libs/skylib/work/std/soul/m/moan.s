(moan
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<string> at <indirect:any-living>")
  (single
    (no-arguments
      (self "You moan.")
      (rest "$mcname$ moans.")
    )
    (arguments
      (arguments gently,deeply,softly,sensually,agonisingly,in terror)
      (self "You moan $arg$.")
      (rest "$mcname$ moans $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You moan at $hcname$.")
      (target "$mcname$ moans at you.")
      (rest "$mcname$ moans at $hcname$.")
    )
    (arguments
      (arguments gently,deeply,softly,sensually,agonisingly,in terror)
      (self "You moan $arg$ at $hcname$.")
      (target "$mcname$ moans $arg$ at you.")
      (rest "$mcname$ moans $arg$ at $hcname$.")
    )
  )
)
