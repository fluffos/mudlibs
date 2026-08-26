(stretch
  (pattern "<string>")
  (single
    (no-arguments
      (self "You stretch.")
      (rest "$mcname$ stretches.")
    )
    (arguments
      (arguments lazily,slowly,seductively,carefully,excitedly,sleepily,
                 sadly,happily,your legs,your arms,your eyebrows,languidly,#)
      (self "You stretch $arg$.")
      (rest "$mcname$ stretches $arg$.")
    )
  )
)
