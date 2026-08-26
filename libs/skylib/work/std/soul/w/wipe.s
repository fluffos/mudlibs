(wipe
  (pattern "[on] <indirect:any-living>")
  (pattern "[the] <string>")
  (pattern "<string> [on] <indirect:any-living>")
  (single
    (arguments
      (arguments sweat from your brow,smile off your face)
      (self "You wipe the $arg$.")
      (rest "$mcname$ wipes the $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments hands,leg,arm,nose)
      (self   "You wipe your $arg$ on $hcname$.")
      (target "$mcname$ wipes $mposs$ $arg$ on you.")
      (rest   "$mcname$ wipes $mposs$ $arg$ on $hcname$.")
    )
  )
)

