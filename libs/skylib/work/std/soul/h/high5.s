(high5
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You high five.")
      (rest "$mcname$ high fives.")
    )
  )
  (targeted
    (no-arguments
      (self   "You high five $hcname$.")
      (target "$mcname$ high fives you.")
      (rest  "$mcname$ high fives $hcname$.")
    )
  (arguments
    (arguments happily,annoyingly,courteously,hysterically,absentmindedly)
      (self "You high five $hcname$.")
      (target "$mcname$ high fives you $arg$.")
      (rest "$mcname$ high fives $hcname$ $arg$.")	
	
	
       )
    )
 )

/* Changed by Hobbes, 961201 */