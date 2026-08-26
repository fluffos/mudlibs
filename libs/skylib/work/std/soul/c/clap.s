(clap
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern " <string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string> ")
  (single
    (no-arguments
      (self "You clap your hands.")
      (rest "$mcname$ claps $mposs$ hands.")
    )
    (arguments
      (arguments excitedly, happily, foolishly, like an otter,
                 briefly,loudly,enthusiastically,halfheartedly, # )
      (self "You clap your hands $arg$.")
      (rest "$mcname$ claps $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You clap your hands at $hcname$.")
      (target "$mcname$ claps $mposs$ hands at you.")
      (rest "$mcname$ claps $mposs$ hands at $hcname$.")
    )
    (arguments
      (arguments excitedly, happily, foolishly, like an otter,
                 briefly,loudly,enthusiastically,halfheartedly, # )
      (self   "You clap your hands $arg$ at $hcname$.")
      (target "$mcname$ claps $mposs$ hands $arg$ at you.")
      (rest  "$mcname$ claps $mposs$ hands $arg$ at $hcname$.")
    )
  )
)

