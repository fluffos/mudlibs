(swagger
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You swagger about.")
      (rest "$mcname$ swaggers about.")
    )
    (arguments
      (arguments suavely, impressively, lustily, bravely, arrogantly, 
                 far too arrogantly, seductively, drunkenly, from side 
                 to side, like a drunken sailor, like a drunken creator, 
                 like Captain Bligh, like John Wayne, like an eighth level 
                 wizard, like an admin)
      (self "You swagger about $arg$.")
      (rest "$mcname$ swaggers about $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You swagger at $hcname$.")
      (target "$mcname$ swaggers at you.")
      (rest  "$mcname$ swaggers at $hcname$.")
    )
    (arguments
      (arguments suavely, impressively, bravely, arrogantly, far too 
                 arrogantly, seductively, drunkenly, from side to side, 
                 like a drunken sailor, like a drunken creator, like 
                 Captain Bligh, like John Wayne, like an eighth level 
                 wizard, like an admin)
      (self   "You swagger $arg$ at $hcname$.")
       (target "$mcname$ swaggers $arg$ at you.")
      (rest  "$mcname$ swaggers $arg$ at $hcname$.")
    )
   )
)

/* Saffra June 4, 2000 */
