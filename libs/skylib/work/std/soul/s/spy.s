(spy
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You spy on people with rays.")
      (rest "$mcname$ spies on people with rays.")
    )
    (arguments
    (arguments  with rays, with closed circuit cameras, with 
                telephone bugs, despite the tinfoil hat, with
                crystal balls, through a painting, cunningly,
                cleverly, obviously, incessantly, surreptitiously,
                covertly, like an admin)
      (self "You spy on people $arg$.")
      (rest "$mcname$ spies on people $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You spy on $hcname$.")
    (target "$mcname$ spies on you.")
    (rest "$mcname$ spies on $hcname$.")
  )
  (arguments
  (arguments  with rays, with closed circuit cameras, with 
              telephone bugs, despite the tinfoil hat, with
              crystal balls, through a painting, cunningly,
              cleverly, obviously, incessantly, surreptitiously,
              covertly, like an admin)
    (self "You spy on $hcname$ $arg$." )
    (target "$mcname$ spies on you $arg$." )
    (rest "$mcname$ spies on $hcname$ $arg$." )
    )
  )
)
