(abuse
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You abuse $hcname$.")
      (target "$mcname$ abuses you.")
      (rest  "$mcname$ abuses $hcname$.")
    )
    (arguments
      (arguments  teasingly, happily, incessantly, like a yobbo at a
        cricket match, for being a silly person, for being smelly,
        for not being wombly, for not being a frog, with naughty words,
        for not hugging enough, #)
      (self   "You abuse $hcname$ $arg$.")
      (target "$mcname$ abuses you $arg$.")
      (rest  "$mcname$ abuses $hcname$ $arg$.")
    )
  )
)
