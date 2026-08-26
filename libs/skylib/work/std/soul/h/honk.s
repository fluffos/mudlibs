(honk
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[at] <indirect:any-living> <string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You honk.")
      (rest "$mcname$ honks.")
    )
    (arguments
      (arguments like a goose,like a confused frog,happily,sadly,joyfully,sagely,knowingly,quickly,loudly,carefully,balefully,excitedly,nervously,brightly,uncertainly,threateningly,grumpily,fluffily,sarcastically)
      (self "You honk $arg$.")
      (rest "$mcname$ honks $arg$.")
    )
    (arguments
      (arguments horn)
       (self "You honk your $arg$.")
       (rest "$mcname$ honks $mposs$ $arg$.")
	  )
          )
  (targeted
    (no-arguments
      (self   "You honk at $hcname$.")
      (target "$mcname$ honks at you.")
      (rest  "$mcname$ honks at $hcname$.")
    )
    (arguments
      (arguments like a goose,like a confused frog,happily,sadly,joyfully,sagely,knowingly,quickly,loudly,carefully,balefully,excitedly,nervously,brightly,uncertainly,threateningly,grumpily,fluffily,sarcastically)
      (self   "You honk $arg$ at $hcname$.")
      (target "$mcname$ honks $arg$ at you.")
      (rest  "$mcname$ honks $arg$ at $hcname$.")
    )
     (arguments
     (arguments horn)
      (self   "You honk your $arg$ at $hcname$.")
      (target "$mcname$ honks $mposs$ $arg$ at you.")
      (rest  "$mcname$ honks $mposs$ $arg$ at $hcname$.")
      )
    )
  )
	
/* Hobbes, 970524 */


