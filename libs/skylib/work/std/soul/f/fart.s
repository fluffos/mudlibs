(fart
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You fart.")
      (rest "$mcname$ farts.")
    )
    (arguments
      (arguments loudly,discreetly,violently,discretely but violently,and leaves a large hole in your underwear,quietly,with a big stink,and leaves behind a tasty morsel in your Y-fronts,without shame,and lifts several inches off the ground,backwards,and it isn't funny,stinkily,downwind,mischievously,devilishly,impishly,cheekily,idiotically,nervously,like a small nuclear detonation,wryly,sceptically)
      (self "You fart $arg$.")
      (rest "$mcname$ farts $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You fart in $mhcname$ general direction.")
      (target "$mcname$ farts in your general direction.")
      (rest  "$mcname$ farts in $mhcname$ general direction.")
      (force "wrinkle nose in revulsion")
    )
    (arguments
      (arguments loudly,discreetly,violently,discretely but violently,and leaves a large hole in your underwear,quietly,with a big stink,and leaves behind a tasty morsel in your Y-fronts,without shame,and lifts several inches off the ground,backwards,and it isn't funny,stinkily,downwind,mischievously,devilishly,impishly,cheekily,idiotically,nervously,like a small nuclear detonation,wryly,sceptically)
      (self   "You fart $arg$ in $mhcname$ general direction.")
      (target "$mcname$ farts $arg$ in your general direction.")
      (rest  "$mcname$ farts $arg$ in $mhcname$ general direction.")
      (force "wrinkle nose in revulsion")
    )
  )
)

/* Rewritten by Hobbes, 970531 */
