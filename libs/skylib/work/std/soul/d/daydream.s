(daydream
  (pattern "<string>")
  (single
    (no-arguments
      (self "You daydream.")
      (rest "$mcname$ daydreams.")
    )
    (arguments
      (arguments #)
      (self "You daydream of $arg$.")
      (rest "$mcname$ daydreams of $arg$.")
    )
  )
)

