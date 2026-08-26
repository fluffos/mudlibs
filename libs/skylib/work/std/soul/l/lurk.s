(lurk
  (pattern "[around] <indirect:any-living>")
  (pattern "[around] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You lurk.")
      (rest "$mcname$ lurks.")
    )
     (arguments
      (arguments menacingly, with good intent, gloomily, happily,
                 evilly, like a maniac, sadly, like a proffesional,
                 merrily, quickly, slowly, in the shadows, carefully,
                 calmly)
      (self "You lurk $arg$.")
      (rest "$mcname$ lurks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You lurk around $hcname$.")
      (target "$mcname$ lurks around you.")
      (rest  "$mcname$ lurks around $hcname$.")
    )
    (arguments
      (arguments  evilly, happily, quietly, with good intent, carefully,
                  crazily, sadly, slowly, while juggling, convincingly,
                  cheekily, to pass some time, #)
      (self   "You lurk around $hcname$ $arg$.")
      (target "$mcname$ lurks around you $arg$.")
      (rest   "$mcname$ lurks around $hcname$ $arg$.")
    )
  )
)

