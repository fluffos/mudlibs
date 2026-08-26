(nibble
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments ear, finger, lip, arm, leg, toe, nose, tongue, neck,
                 hand, wrist, leg, thigh, eyebrow, cabbage, dinner,
                 thoughts, fluffy animals, strawberries, elbow, knee,
                 thigh, calf, foot, hair, clothes, jewelery, food,
               glasses, cupcakes, strawberries, oranges, fika, #)
      (self   "You nibble on $mhcname$ $arg$.")
      (target "$mcname$ nibbles on your $arg$.")
      (rest   "$mcname$ nibbles on $mhcname$ $arg$.")
    )
  )
)

