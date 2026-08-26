(bleat
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You bleat.")
      (rest "$mcname$ bleats.")
    )
    (arguments
      (arguments like a lamb,like a goat,happily,evilly,devilishly,impishly,cheekily,idiotically,like a wolf in sheep's clothing,like a sheep in wolves' clothing,#)
      (self "You bleat $arg$.")
      (rest "$mcname$ bleats $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bleat at $hcname$.")
      (target "$mcname$ bleats at you.")
      (rest  "$mcname$ bleats at $hcname$.")
    )
    (arguments
      (arguments like a lamb,like a goat,happily,evilly,devilishly,impishly,cheekily,idiotically,like a wolf in sheep's clothing,like a sheep in wolves' clothing,#)
      (self   "You bleat $arg$ at $hcname$.")
      (target "$mcname$ bleats $arg$ at you.")
      (rest  "$mcname$ bleats $arg$ at $hcname$.")
    )
  )
)

/* Hobbes 960922, suggested by Eggjon */