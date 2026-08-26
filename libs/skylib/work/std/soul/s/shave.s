(shave
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments head, face, legs, armpits, goatee, poodle)
      (self "You shave your $arg$.")
      (rest "$mcname$ shaves $mposs$ $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  head, face, legs, armpits, goatee, poodle)
      (self   "You shave $hcname$'s $arg$.") 
      (target "$mcname$ shaves your $arg$.")
      (rest  "$mcname$ shaves $hcname$'s $arg$.")
    )
  )
)
/* by Saffra 4-26-00 */
