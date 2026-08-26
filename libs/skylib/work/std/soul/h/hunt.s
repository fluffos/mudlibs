(hunt
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You hunt $hcname$.")
      (target "$mcname$ hunts you.")
      (rest   "$mcname$ hunts $hcname$.")
    )
    (arguments
      (arguments  up and down the streets)
      (self   "You hunt $arg$ for $hcname$.")
      (target "$mcname$ hunts $arg$ for you.")
      (rest   "$mcname$ hunts $arg$ for $hcname$.")
    )
    (arguments
      (arguments  affectionately, nicely, kindly, 
                  with the gleam of revenge in both eyes, relentlessly, #)
      (self   "You hunt $hcname$ $arg$.")
      (target "$mcname$ hunts you $arg$.")
      (rest   "$mcname$ hunts $hcname$ $arg$.")
    )
  )
)

