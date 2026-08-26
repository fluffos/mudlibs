(squeak
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You squeak.")
      (rest "$mcname$ squeaks.")
    )
    (arguments
      (arguments manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically,happily,like a mouse,like a confused cat)
      (self "You squeak $arg$.")
      (rest "$mcname$ squeaks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You squeak at $hcname$.")
      (target "$mcname$ squeaks at you.")
      (rest  "$mcname$ squeaks at $hcname$.")
    )
    (arguments
      (arguments  manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,cheekily,idiotically,wryly,sceptically,happily,like a mouse,like a confused cat)
      (self   "You squeak $arg$ at $hcname$.")
      (target "$mcname$ squeaks $arg$ at you.")
      (rest  "$mcname$ squeaks $arg$ at $hcname$.")
    )
  )
)
/* Hobbes, 96 */