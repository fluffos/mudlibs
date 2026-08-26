(howl
  (pattern "at the <string>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "HOOOOOWWWWWWWWWLLLLLL!!")
      (rest "$mcname$ howls.")
    )
    (arguments
      (arguments #)
      (self "You HOOOOOWWWWWWWWWLLLLLL at the $arg$.")
      (rest " $mcname$ howls at the $arg$.")
    )
  )
)

