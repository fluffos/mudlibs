(embarrass
  (pattern "<indirect:any-living> <string>")
  (pattern "<indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You embarrass $hcname$.")
      (target "$mcname$ embarrasses you.")
      (rest   "$mcname$ embarrasses $hcname$.")        
    )
    (arguments
      (arguments about sex, with a stick, under a water tower,
                 about your personal problems, slowly, excitedly, 
                 using inappropriate soul commands, in a manger, 
                 enthusiastically, seductively, quickly, about dying,
                 backwards, under a bridge, quietly, loudly,
                 while talking to someone else, heaps, completely, totally,
                 about real life, about typos, about mischatting, #)
      (self   "You embarrass $hcname$ $arg$.")
      (target "$mcname$ embarrasses you $arg$.")
      (rest   "$mcname$ embarrasses $hcname$ $arg$.")
    )
  )
)

