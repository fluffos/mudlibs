(leap
  (pattern "<string>")
  (single
    (no-arguments
      (self "You leap into the air.")
      (rest "$mcname$ leaps into the air.")
    )
    (arguments
      (arguments longingly,excitedly,quickly,slowly,awkwardly,politely,quietly,noisily)
      (self "You leap $arg$ into the air.")
      (rest "$mcname$ leaps $arg$ into the air.")
    )
  )
)

