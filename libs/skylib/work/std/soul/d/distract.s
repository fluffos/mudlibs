(distract
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You distract yourself.")
      (rest "$mcname$ distracts $mposs$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You distract $hcname$.")
      (target "$mcname$ distracts you.")
      (rest  "$mcname$ distracts $hcname$.")
    )
    (arguments
      (arguments  carefully, shamelessly, excitedly, with a pitchfork,
                   after the dream has died, flirtatiously, graciously,
                   completely, selfishly, pointlessly, for dinner,
                   from something else more fun, to play catch,
                   with a wonderful lack of panties, with oranges,
                   with strawberries, slowly, keenly, with a shower,
                   with a bath, under a table,
                   with a cucumber, with a perky wobbler, #)
      (self   "You distract $hcname$ $arg$.")
      (target "$mcname$ distracts you $arg$.")
      (rest  "$mcname$ distracts $hcname$ $arg$.")
    )
  )
)

