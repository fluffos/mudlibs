(scoff
  (pattern "<string>")
  (single
    (no-arguments
      (self "You scoff.")
      (rest "$mcname$ scoffs.")
    )
    (arguments
      (arguments loudly,sarcastically,sweetly,sardonically)
      (self "You scoff $arg$.")
      (rest "$mcname$ scoffs $arg$.")
    )
  )
)

