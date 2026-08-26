(remind
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You remind $hcname$.")
      (target "$mcname$ reminds you.")
      (rest  "$mcname$ reminds $hcname$.")
    )
    (arguments
      (arguments  #)
      (self   "You remind $hcname$ $arg$.")
      (target "$mcname$ reminds you $arg$.")
      (rest  "$mcname$ reminds $hcname$ $arg$.")
    )
  )
)

/* Hobbes 961204 */
	