(pine
   (pattern "<string>")
   (pattern "[at] <indirect:any-living>")
   (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You pine away.")
      (rest "$mcname$ pines away.")
    )
    (arguments
      (arguments for the fjords, dramatically, melodramatically, 
                romantically, swooningly, sarcastically,
                 longingly, lovingly, not at all)
      (self "You pine $arg$.")
      (rest "$mcname$ pines $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You pine at $hcname$.")
      (target "$mcname$ pines at you.")
      (rest  "$mcname$ pines at $hcname$.")
    )
    (arguments
      (arguments for the fjords, dramatically, melodramatically,
                 romantically, swooningly, sarcastically,
                 longingly, lovingly, not at all)
      (self   "You pine $arg$ at $hcname$.")
      (target "$mcname$ pines $arg$ at you.")
      (rest  "$mcname$ pines $arg$ at $hcname$.")
    )
  )
)
