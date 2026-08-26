(bombard
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> with <string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
     (arguments for that pathetic joke,for making that comment,for that lousy pun,for the fun of it)
      (self "You bombard $hcname$ with rotten eggs and tomatoes $arg$.")
      (target "$mcname$ bombards you with rotten eggs and tomatoes $arg$.")
      (rest "$mcname$ bombards $hcname$ with rotten eggs and tomatoes $arg$.")
    )
   (arguments
    (arguments #)
    (self "You bombard $hcname$ with $arg$.")
    (target "$mcname$ bombards you with $arg$.")
    (rest "$mcname$ bombards $hcname$ with $arg$.")
    )
  )
)
