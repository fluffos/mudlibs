(toast
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments  happines,two wombles,the future,#)
      (self "You propose a toast to $arg$.")
      (rest "$mcname$ proposes a toast to $arg$")
	)
	)
  (targeted
    (no-arguments 
      (self   "You raise your glass and toast $hcname$.")
      (target "$mcname$ raises $mposs$ glass and toasts you.")
      (rest  "$mcname$ raises $mposs$ glass and toasts $hcname$.")
    )
  )
)
/* HOBBES, Suggested by Gototh 970823 */
