(mowr
  (pattern "<string>" )
  (pattern "<indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> [at] <indirect:any-living>") 
  (single
    (no-arguments
      (self "You mowr.")
      (rest "$mcname$ mowrs.")
    )
    (arguments
      (arguments  like a cat, like a cute kitten, like a lion, 
                happily, mischievously, affectionately, seductively, 
                flirtatiously, angrily, hungrily, sadly, #)
      (self "You mowr $arg$.")
      (rest "$mcname$ mowrs $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You mowr at $hcname$.")
      (target "$mcname$ mowrs at you.")
      (rest "$mcname$ mowrs at $hcname$.")
    )
    (arguments
      (arguments  like a cat, like a cute kitten, like a lion, 
                  happily, mischievously, affectionately, seductively, 
                  flirtatiously, angrily, hungrily, sadly, #)
      (self "You mowr $arg$ at $hcname$.")
      (target "$mcname$ mowrs $arg$ at you.")
      (rest "$mcname$ mowrs $arg$ at $hcname$.")
    )
  )
)

