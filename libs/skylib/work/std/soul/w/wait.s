(wait
  (pattern "[for] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [for] <indirect:any-living>")
  (pattern "[for] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wait.")
      (rest "$mcname$ waits.")
    )
    (arguments
      (arguments impatiently,for ever,angrily,happily,idiotically,
      for something to happen,#)
      (self "You wait $arg$.")
      (rest "$mcname$ waits $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wait for $hcname$.")
      (target "$mcname$ waits for you.")
      (rest  "$mcname$ waits for $hcname$.")
    )
    (arguments
      (arguments impatiently,for ever,angrily,happily,idiotically,
       for something to happen,#)
      (self   "You wait $arg$ for $hcname$.")
      (target "$mcname$ waits $arg$ for you.")
      (rest  "$mcname$ waits $arg$ for $hcname$.")
    )
  )
)

