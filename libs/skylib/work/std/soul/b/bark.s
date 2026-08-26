(bark
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> at <indirect:any-living>")
  (single
    (no-arguments
      (self "You bark.")
      (rest "$mcname$ barks.")
    )
    (arguments
      (arguments dog, cat, tree, wolf,
                 labrador, german shepherd, bull terrier)
      (self "You bark like a $arg$.")
      (rest "$mcname$ barks like a $arg$.")
    )
    (arguments
      (arguments something else that barks,
                 one of those darned obnoxious little dogs)
      (self "You bark like $arg$.")
      (rest "$mcname$ barks like $arg$.")
    )
    (arguments
      (arguments happily, annoyingly, without a care in the world,
                 warily, watchfully, bashfully, snidely,
                 enthusiastically, excitedly, obnoxiously, #)
      (self "You bark $arg$.")
      (rest "$mcname$ barks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bark at $hcname$.")
      (target "$mcname$ barks at you.")
      (rest  "$mcname$ barks at $hcname$.")
    )
    (arguments
      (arguments dog, cat, tree, wolf,
                 labrador, german shepherd, bull terrier)
      (self "You bark like a $arg$ at $hcname$.")
      (rest "$mcname$ barks like a $arg$ at you.")
      (rest "$mcname$ barks like a $arg$ at $hcname$.")
    )
    (arguments
      (arguments something else that barks,
                 one of those darned obnoxious little dogs)
      (self "You bark like $arg$ at $hcname$.")
      (rest "$mcname$ barks like $arg$ at you.")
      (rest "$mcname$ barks like $arg$ at $hcname$.")
    )
    (arguments
      (arguments happily, annoyingly, without a care in the world,
                 warily, watchfully, bashfully, snidely,
                 enthusiastically, excitedly, obnoxiously, #)
      (self "You bark $arg$ at $hcname$.")
      (rest "$mcname$ barks $arg$ at you.")
      (rest "$mcname$ barks $arg$ at $hcname$.")
    )
  )
)

/* changed by Hobbes, 960911 */
