(fall
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You fall over.")
      (rest "$mcname$ falls over.")
    )
    (arguments
      (arguments backwards,painfully,awkwardly,accidentally,purposefully,happily,sadly,quickly,rapidly)
      (self "You fall over $arg$.")
      (rest "$mcname$ falls over $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You fall for $hcname$.")
      (target "$mcname$ falls for you.")
      (rest  "$mcname$ falls for $hcname$.")
    )
    (arguments
      (arguments  heavily,slowly,happily,quickly,twice)
      (self   "You fall $arg$ on $hcname$.")
      (target "$mcname$ falls $arg$ on you.")
      (rest  "$mcname$ falls $arg$ on $hcname$.")
    )
  )
)

