(mewl
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You mewl.")
      (rest "$mcname$ mewls.")
    )
    (arguments
      (arguments cutely,happily,contentedly,quietly,loudly,softly,cheerfully,slowly,merrily,joyfully,warmly,cautiously,#)
      (self "You mewl $arg$.")
      (rest "$mcname$ mewls $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You mewl at $hcname$.")
      (target "$mcname$ mewls at you.")
      (rest  "$mcname$ mewls at $hcname$.")
    )
    (arguments
      (arguments cutely,happily,contentedly,quietly,loudly,softly,cheerfully,slowly,merrily,joyfully,warmly,cautiously,#)
      (self   "You mewl $arg$ at $hcname$.")
      (target "$mcname$ mewls $arg$ at you.")
      (rest  "$mcname$ mewls $arg$ at $hcname$.")
    )
  )
)

