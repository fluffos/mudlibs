(gaze
  (pattern "[at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You gaze into the wild blue yonder.")
      (rest "$mcname$ gazes into the wild blue yonder.")
    )
  )
  (targeted
    (arguments
      (arguments lovingly,evilly,forlornly,intently,frogilly,#)
      (self "You gaze $arg$ at $hcname$.")
      (target "$mcname$ gazes $arg$ at you.")
      (rest "$mcname$ gazes $arg$ at $hcname$.")
    )
  )
)
