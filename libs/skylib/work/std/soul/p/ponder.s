(ponder
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You ponder.")
      (rest "$mcname$ ponders.")
    )
    (arguments
      (arguments  the meaning of it all, the situation, wombles, cars, fruit,
                  pigeons, frogs, toy trains, environmental concerns,
                  nuclear disasters, love, #)
      (self "You ponder $arg$.")
      (rest "$mcname$ ponders $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ponder $hcname$.")
      (target "$mcname$ ponders you.")
      (rest   "$mcname$ ponders $hcname$.")
    )
    (arguments
      (arguments  sanity, situation, wombles, cars, fruit, pigeons, frogs,
                  toy trains, hobbies, passions, loves, hates, hairstyle)
      (self   "You ponder $mhcname$ $arg$.")
      (target "$mcname$ ponders your $arg$.")
      (rest   "$mcname$ ponders $mhcname$ $arg$.")
    )
    (arguments
      (arguments  thoughtfully, sarcastically, hard, knowingly, interestingly,
                  worriedly, happily, sadly, cutely, #)
      (self   "You ponder $arg$ about $hcname$.")
      (target "$mcname$ ponders $arg$ about you.")
      (rest   "$mcname$ ponders $arg$ about $hcname$.")
    )
  )
)

