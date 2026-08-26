(slook
  (pattern "<string>" )
(pattern "<string> <indirect:any-living>")
(pattern "<indirect:any-living> <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
    (arguments  happy, sad, around, silly, foolish)
      (self "You look $arg$.")
      (rest "$mcname$ looks $arg$.")
    )
  )
  (targeted
    (arguments
    (arguments  happy, sad, around, silly, foolish)
    (self   "You look $arg$ at $hcname$.")
    (target "$mcname$ looks $arg$ at you.")
    (rest   "$mcname$ looks $arg$ at $hcname$.")
    )
  )
)

/* Saffra 3-30-00 */

