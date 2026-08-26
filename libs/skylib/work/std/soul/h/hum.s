(hum
  (pattern "<string>")
    (pattern "[to] <indirect:any-living>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hum.")
      (rest "$mcname$ hums.")
    )
    (arguments
      (arguments  a merry tune, tunelessly, annoyingly, vaguely, cutely, 
                  absentmindedly, whilst you work, distractedly, pointlessly, 
                  silently, loudly, rudely, #)
      (self "You hum $arg$.")
      (rest "$mcname$ hums $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hum to $hcname$.")
      (target "$mcname$ hums to you.")
      (rest   "$mcname$ hums to $hcname$.")    
    )
    (arguments
      (arguments  a merry tune, tunelessly, annoyingly, vaguely, cutely, 
                  absentmindedly, whilst you work, distractedly, pointlessly, 
                  silently, loudly, rudely, #)
      (self   "You hum $arg$ to $hcname$.")
      (target "$mcname$ hums $arg$ to you.")
      (rest   "$mcname$ hums $arg$ to $hcname$.")    
    )
  )
)

