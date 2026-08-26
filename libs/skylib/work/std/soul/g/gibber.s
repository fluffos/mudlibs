(gibber
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You gibber madly.")
      (rest "$mcname$ gibbers madly.")
    )
    (arguments
      (arguments anxiously,madly,unhappily,#)
      (self "You gibber $arg$.")
      (rest "$mcname$ gibbers $arg$.")
    )
  )
  (targeted
     (no-arguments
	   (self "You gibber madly at $hcname$.")
	   (target "$mcname$ gesticulates wildly at you.")
	   (rest "$mcname$ gesticulates wildly at $hcname$.")
	 )
	 (arguments
	   (arguments anxiously,madly,unhappily,#)
	   (self "You gibber $arg$ at $hcname$")
	   (target "$mcname$ gibbers $arg$ at you.")
	   (rest "$mcname$ gibbers madly at $mcname$.")
	 )
  )	 	
)

