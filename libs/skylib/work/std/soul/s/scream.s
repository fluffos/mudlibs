(scream
  (pattern "[at|in] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at|in] <indirect:any-living>")
  (pattern "[at|in] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You scream.")
      (rest "$mcname$ screams.")
    )
    (arguments
      (arguments loudly,happily,manically,evilly,wickedly,insanely,impishly,
               cheekily,idiotically,repeatedly,#)
      (self "You scream $arg$.")
      (rest "$mcname$ screams $arg$.")
    )
   (arguments
     (arguments horror,fright,fear,pain,surprise,frustration,despair,anger)
      (self "You scream in $arg$.")
      (rest "$mcname$ screams in $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You scream at $hcname$.")
      (target "$mcname$ screams at you.")
      (rest  "$mcname$ screams at $hcname$.")
    )
    (arguments
       (arguments loudly,happily,manically,evilly,wickedly,insanely,impishly,
                 cheekily,idiotically,repeatedly,#)
      (self   "You scream $arg$ at $hcname$.")
      (target "$mcname$ screams $arg$ at you.")
      (rest  "$mcname$ screams $arg$ at $hcname$.")
    )
     (arguments
       (arguments horror,fright,fear,pain,surprise,frustration,despair,anger)
         (self   "You scream in $arg$ at $hcname$.")
         (target "$mcname$ screams in $arg$ at you.")
         (rest  "$mcname$ screams in $arg$ at $hcname$.")
       )
      (arguments
       (arguments ear,face)
         (self   "You scream in $mhcname$ $arg$.")
         (target "$mcname$ screams in your $arg$.")
         (rest  "$mcname$ screams in $mhcname$ $arg$.")
       )
   )
)
/*Hobbes 970730 */
