/*
 * Created By Love ~ 11th February 2002
 */

(splay
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You play with your hair.")
      (rest "$mcname$ plays with $mposs$ hair.")
    )
    (arguments
      (arguments  idly, frantically, lethargically, sleepily,
                  happily, sadly, carefully, slowly, lovingly,
                  adoringly, manically)
      (self "You $arg$ play with your hair.")
      (rest "$mcname$ $arg$ plays with $mposs$ hair.")
    )
  )
  (targeted
    (no-arguments
      (self   "You play with $mhcname$ hair.")
      (target "$mcname$ plays with your hair.")
      (rest   "$mcname$ plays with $mhcname$ hair.")
    )
    (arguments
      (arguments  idly, frantically, lethargically, sleepily,
                  happily, sadly, carefully, slowly, lovingly,
                  adoringly, manically)
      (self   "You $arg$ play with $mhcname$ hair.")
      (target "$mcname$ $arg$ plays with your hair.")
      (rest  "$mcname$ $arg$ plays with $mhcname$ hair.")
    )
  )
)
