(twitch
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You twitch." )
      (rest "$mcname$ twitches." )
    )
    (arguments
      (arguments violently, spasmodically, suddenly, frantically, 
                 pointedly, from too much caffeine, from too much crack, #)
      (self "You twitch $arg$.")
      (rest "$mcname$ twitch $arg$.")
    )
   )
  (targeted
    (no-arguments
      (self   "You twitch at $hcname$." )
      (target "$mcname$ twitches at you." )
      (rest   "$mcname$ twitches at $hcname$." )
    )   
    (arguments
      (arguments violently, spasmodically, suddenly, frantically, 
                 pointedly, from too much caffeine, from too much crack, #)
      (self   "You twitch $arg$ at $hcname$.")
      (target "$mcname$ twitches $arg$ at you.")
      (rest  "$mcname$ twitches $arg$ at $hcname$.")
    )
  )
)

/* Saffra 2-21-00 */

