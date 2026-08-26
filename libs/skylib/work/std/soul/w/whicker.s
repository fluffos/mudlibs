(whicker
  (single
    (no-arguments
      (self "You whicker.")
      (rest "$mcname$ whickers.")
    )
    (arguments
      (arguments like a horse, gently, happily, slowly, stupidly,
                 like a ball of string,
                 back in black, like a stallion, with gusto, excitedly,
                 unhappily, sadly, skitishly, #)
      (self "You whicker $arg$.")
      (rest "$mcname$ whickers $arg$.")
    )
  )
)

