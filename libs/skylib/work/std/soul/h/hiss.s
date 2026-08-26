(hiss
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hiss.")
      (rest "$mcname$ hisses.")
    )
    (arguments
      (arguments angrily,cynically,sarcastically,happily,nastily,like a snake,
                 like a cat,like a woman scorned,menacingly,#)
      (self "You hiss $arg$.")
      (rest "$mcname$ hisses $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hiss at $hcname$.")
      (target "$mcname$ hisses at you.")
      (rest  "$mcname$ hisses at $hcname$.")
    )
    (arguments
      (arguments  angrily,cynically,sarcastically,happily,nastily,like a snake,
                  like a cat,like a woman scorned,menacingly,#)
      (self   "You hiss $arg$ at $hcname$.")
      (target "$mcname$ hisses $arg$ at you.")
      (rest  "$mcname$ hisses $arg$ at $hcname$.")
    )
  )
)

