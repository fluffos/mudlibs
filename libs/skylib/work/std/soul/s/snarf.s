(snarf
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You snarf embarrassingly.")
      (rest "$mcname$ snarfs embarrassingly.")
    )
    (arguments
    (arguments  chocolate cake, milkshake, brain fluid, 
                orange juice, apple juice, milk, Coca-Cola, Tim Tams,
                Tim Tam explosions, ice water, hot chocolate, 
                rum and coke, coffee, hot tea, vodka, lemonade, 
                tequila, toothpaste)
      (self "You snarf $arg$ out your nose.")
      (rest "$mcname$ snarfs $arg$ out $mposs$ nose.")
    )
  )
  (targeted
  (no-arguments
    (self   "You snarf at $hcname$ embarrassingly.")
    (target "$mcname$ snarfs at you embarrassingly.")
    (rest   "$mcname$ snarfs at $hcname$ embarrassingly.")
  )
  (arguments
  (arguments  chocolate cake, milkshake, brain fluid, 
              orange juice, apple juice, milk, Coca-Cola, Tim Tams,
              Tim Tam explosions, ice water, hot chocolate, 
              rum and coke, coffee, hot tea, vodka, lemonade, 
              tequila, toothpaste)
    (self   "You snarf $arg$ out your nose at $hcname$." )
    (target "$mcname$ snarfs $arg$ out $mposs$ nose at you." )
    (rest   "$mcname$ snarfs $arg$ out $mposs$ nose at $hcname$." )
    )
  )
)
