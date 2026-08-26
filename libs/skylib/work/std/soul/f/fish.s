(fish
  (pattern "[in] <indirect:any-living>")
  (pattern "<string>")
  (pattern "[for|for] <string> [in|in|in] <indirect:any-living> [pockets]")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You fish around in your pockets.")
      (rest "$mcname$ fishes around in $mposs$ pockets.")
    )
    (arguments
      (arguments #)
      (self "You fish around in your pockets for a $arg$.")
      (rest "$mcname$ fishes around in $mposs$ pockets for a $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You fish around in $mhcname$ pockets.")
      (target "$mcname$ fishes around in your pockets.")
      (rest  "$mcname$ fishes around in $mhcname$ pockets.")
    )
    (arguments
      (arguments  #)
      (self   "You fish around in $mhcname$ pockets for a $arg$.")
      (target "$mcname$ fishes around in your pockets for a $arg$.")
      (rest  "$mcname$ fishes around in $mhcname$ pockets for a $arg$.")
    )
  )
)

