(wake
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments up,up and smell the cat food,the dead,
                 the wombles of the world up)
      (self "You wake $arg$.")
      (rest "$mcname$ wakes up.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wake up $hcname$.")
      (target "$mcname$ wakes you up.")
      (rest   "$mcname$ wakes up $hcname$.")
    )
  )
)

