(suck
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments thumb,pen)
      (self "You suck your $arg$.")
      (rest "$mcname$ sucks $mposs$ $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  ear, nose, leg, arm, finger, apples, strawberries,
                  frog, straw, cow, coffee table, car, tent,
                  house, lawnmower, thumb, toe, knee, thigh)
      (self   "You suck on $mhcname$ $arg$.")
      (target "$mcname$ sucks on your $arg$.")
      (rest  "$mcname$ sucks on $mhcname$ $arg$.")
    )
  )
)

