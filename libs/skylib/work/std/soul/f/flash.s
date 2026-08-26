(flash
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You flash your naughty bits!")
      (rest "$mcname$ flashes $mposs$ naughty bits!")
    )
    (arguments
      (arguments frogs,clocks,goods,stock,#)
      (self "You flash your $arg$.")
      (rest "$mcname$ flashes $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You flash your naughty bits at $hcname$!")
      (target "$mcname$ flashes $mposs$ naughty bits at you!")
      (rest  "$mcname$ flashes $mposs$ naughty bits at $hcname$!")
    )
    (arguments
      (arguments frogs,clocks,goods,stock,#)
      (self   "You flash your $arg$ at $hcname$.")
      (target "$mcname$ flashes $mposs$ $arg$ at you.")
      (rest  "$mcname$ flashes $mposs$ $arg$ at $hcname$.")
    )
  )
)
/* Hobbes, 970520 */
	