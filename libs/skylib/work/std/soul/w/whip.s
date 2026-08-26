(whip
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You crack a whip at $hcname$.")
      (target "$mcname$ cracks a whip at you.")
      (rest  "$mcname$ cracks a whip at $hcname$.")
    )
    (arguments
      (arguments angrily,hastily,viciously,happily,idly,cautiously,
                 quickly,in a bored fashion)
      (self   "You crack a whip at $hcname$ $arg$.")
      (target "$mcname$ cracks a whip at you $arg$.")
      (rest  "$mcname$ cracks a whip at $hcname$ $arg$.")
    )
  )
)

