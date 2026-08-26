(meow
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You meow.")
      (rest "$mcname$ meows.")
    )
    (arguments
      (arguments like a cat,like a cute kitten,like a cabbage,happily,insanely,mischievously,affectionately,faintly,like Hobbes,#)
      (self "You meow $arg$.")
      (rest "$mcname$ meows $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You meow at $hcname$.")
      (target "$mcname$ meows at you.")
      (rest  "$mcname$ meows at $hcname$.")
    )
    (arguments
      (arguments like a cat,like a cute kitten,like a cabbage,happily,insanely,mischievously,affectionately,faintly,like Hobbes,#)
      (self   "You meow $arg$ at $hcname$.")
      (target "$mcname$ meows $arg$ at you.")
      (rest  "$mcname$ meows $arg$ at $hcname$.")
    )
  )
)

