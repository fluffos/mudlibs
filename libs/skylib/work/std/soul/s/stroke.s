(stroke
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You stroke your chin thoughtfully.")
      (rest "$mcname$ strokes $mposs$ chin thoughtfully.")
    )
  )
  (targeted
    (no-arguments
      (self   "You stroke $hcname$.")
      (target "$mcname$ strokes you.")
      (rest  "$mcname$ strokes $hcname$.")
         )
    (arguments
      (arguments  gently,warmly,softly,lovingly)
      (self   "You stroke $hcname$ $arg$.")
      (target "$mcname$ strokes you $arg$.")
      (rest  "$mcname$ strokes $hcname$ $arg$.")
    )
    (arguments
      (arguments  ear, nose, cheek, hand, forehead, eyebrow,
                  finger, foot, toe, fingernail, arm, thigh,
                  upper thigh, calf, elbow, knee, fingers, neck,
          shoulder, palm, toes, hair, chicken)
      (self   "You stroke $mhcname$ $arg$.")
      (target "$mcname$ strokes your $arg$.")
      (rest   "$mcname$ strokes $mhcname$ $arg$.")
    )
  )
)

/* Hobbes 970513*/
