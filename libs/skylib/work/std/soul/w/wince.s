(wince
  (pattern "[at] <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wince.")
      (rest "$mcname$ winces.")
    )
  )
  (targeted
    (no-arguments
      (self "You wince at $hcname$.")
      (rest "$mcname$ winces at $hcname$.")
      (target "$mcname$ winces at you.")
    )
    (arguments
      (arguments in shock,unhappily,angrily,at the thought of coding,#)
      (self "You wince at $hcname$ $arg$.")
      (rest "$mcname$ winces $arg$ at $hcname$.")
      (target "$mcname$ winces $arg$ at you.")
    )
  )
)
