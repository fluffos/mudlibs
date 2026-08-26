(cheep
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern " <string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string> ")
  (single
    (no-arguments
      (self "You cheep like a cute fluffy chick.")
      (rest "$mcname$ cheeps like a cute fluffy chick.")
    )
    (arguments
      (arguments cutely, adorably, fluffily, brightly, quietly,
                 like a wet hen, like a ruffled chicken, like a 
                 marshmallow peep,  # )
      (self "You cheep $arg$.")
      (rest "$mcname$ cheeps $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You cheep at $hcname$ like a cute fluffy chick.")
      (target "$mcname$ cheeps at you like a cute fluffy chick.")
      (rest "$mcname$ cheeps at $hcname$ like a cute fluffy chick.")
    )
    (arguments
      (arguments cutely, adorably, fluffily, brightly, quietly,
                 like a wet hen, like a ruffled chicken, like a 
                 marshmallow peep,  # )
      (self   "You cheep $arg$ at $hcname$.")
      (target "$mcname$ cheeps $arg$ at you.")
      (rest  "$mcname$ cheeps $arg$ at $hcname$.")
    )
  )
)
/* Saffra 6-14-00 */
