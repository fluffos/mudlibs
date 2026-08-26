(duck
  (pattern "[from] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [from] <indirect:any-living>")
  (pattern "[from] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You duck.")
      (rest "$mcname$ ducks.")
    )
    (arguments
     (arguments for cover, the snowball, quickly, slowly, badly,
                     inappropriately, pointlessly, sadly, carefully, #)
      (self "You duck $arg$.")
      (rest "$mcname$ ducks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You duck away from $hcname$.")
      (target "$mcname$ ducks away from you.")
      (rest  "$mcname$ ducks away from $hcname$.")
    )
    (arguments
     (arguments quickly, slowly, badly,
       inappropriately, pointlessly, sadly, carefully, #)
      (self   "You duck away from $hcname$ $arg$.")
      (target "$mcname$ ducks away from $hcname$ $arg$.")
      (rest  "$mcname$ ducks away from $hcname$ $arg$.")
    )
  )
)

