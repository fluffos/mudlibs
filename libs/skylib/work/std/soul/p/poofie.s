(poofie
  (pattern "<string>")
  (pattern "[at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You poofie.")
      (rest "$mcname$ poofies.")
    )
    (arguments
      (arguments like Jeslek, playfully, with a large puff, with reckless abandon, vaguely, suddenly, affectionately, randomly)
      (self "You poofie $arg$.")
      (rest "$mcname$ poofies $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You poofie at $hcname$.")
      (target "$mcname$ poofies at you.")
      (rest  "$mcname$ poofies at $hcname$.")
    )
    (arguments
      (arguments like Jeslek, playfully, with a large puff, with reckless abandon, vaguely, suddenly, affectionately, randomly)
      (self   "You poofie $arg$ at $hcname$.")
      (target "$mcname$ poofies $arg$ at you.")
      (rest  "$mcname$ poofies $arg$ at $hcname$.")
    )
  )
)
