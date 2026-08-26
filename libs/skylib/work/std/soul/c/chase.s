(chase
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You chase $hcname$.")
      (target "$mcname$ chases you.")
      (rest   "$mcname$ chases $hcname$.")
    )
    (arguments
      (arguments  around the room, around the Disc, 
                  to the Counter Weight Continent and back)
      (self   "You chase $hcname$ $arg$.")
      (target "$mcname$ chases you $arg$.")
      (rest   "$mcname$ chases $hcname$ $arg$.")
    )
  )
)

