(whinny
  (single
    (no-arguments
      (self "You whinny.")
      (rest "$mcname$ whinnies.")
    )
    (arguments
      (arguments like a horse, gently, happily, slowly, stupidly,
                 like a ball of string, in growing pains,
                 back in black, like a stallion, with gusto, excitedly,
                 unhappily, sadly, skitishly, #)
      (self "You whinny $arg$.")
      (rest "$mcname$ whinnies $arg$.")
    )
  )
)

