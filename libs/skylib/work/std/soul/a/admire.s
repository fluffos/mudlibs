(admire
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You admire $hcname$.")
      (target "$mcname$ admires you.")
      (rest  "$mcname$ admires $hcname$.")
    )
    (arguments
      (arguments  from afar)
      (self   "You admire $hcname$ $arg$.")
      (target "$mcname$ admires you $arg$.")
      (rest  "$mcname$ admires $hcname$ $arg$.")
    )
    (arguments
      (arguments  eyes, legs, bottom, body, ears, nose, fingers, toes,
                  dress, trousers, shirt, tenacity, #)
      (self   "You admire $mhcname$ $arg$.")
      (target "$mcname$ admires your $arg$.")
      (rest  "$mcname$ admires $mhcname$ $arg$.")
    )
  )
)

