(whimper
  (pattern "<string>")
  (pattern "<string> [at] <indirect:object>")
  (pattern "<indirect:object>")
  (single
    (no-arguments
      (self "You whimper.")
      (rest "$mcname$ whimpers.")
    )
    (arguments
      (arguments painfully, fearfully, carefully, diminutively, happily,
                 winningly, in triumph, with the wombles, #)
      (self "You whimper $arg$.")
      (rest "$mcname$ whimpers $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You whimper at $hcname$.")
      (target "$mcname$ whimpers at you.")
      (rest "$mcname$ whimpers at $hcname$.")
    )
    (arguments
      (arguments painfully, fearfully, carefully, diminutively, happily,
                 winningly, in triumph, with the wombles, #)
      (self "You whimper $arg$ at $hcname$.")
      (target "$mcname$ whimpers $arg$ at you.")
      (rest "$mcname$ whimpers $arg$ at $hcname$.")
    )
  )
)

