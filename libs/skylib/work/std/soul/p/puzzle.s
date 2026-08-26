(puzzle
  (pattern "<string>")
  (single
    (no-arguments
      (self "You look puzzled.")
      (rest "$mcname$ looks puzzled.")
    )
    (arguments
      (arguments #)
      (self "You puzzle over $arg$.")
      (rest "$mcname$ puzzles over $arg$.")
    )
  )
)

