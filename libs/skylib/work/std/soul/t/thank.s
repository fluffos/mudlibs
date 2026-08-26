(thank
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You thank $hcname$.")
      (target "$mcname$ thanks you.")
      (rest   "$mcname$ thanks $hcname$.")
    )
    (arguments
      (arguments  profusely, very much, gratuitously, lots, slightly, reservedly, 
                  muchly, verily, verily muchly, again, for all the help, 
                  for all the fish, sarcastically, a million times, lot and lots, 
                  for being so wonderful, for nothing, for being there, 
                  for the last time, heaps, #)
      (self   "You thank $hcname$ $arg$.")
      (target "$mcname$ thanks you $arg$.")
      (rest   "$mcname$ thanks $hcname$ $arg$.")
    )
  )
)

