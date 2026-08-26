(feh
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You go feh!")
      (rest "$mcname$ goes feh!")
    )
    (arguments
      (arguments like Dogbolter,like Taffyd on a bad code day,like Laurana on a bad hair day,anxiously,angrily,#)
      (self "You go feh! $arg$.")
      (rest "$mcname$ goes feh! $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You go feh! at $hcname$.")
      (target "$mcname$ goes feh! at you.")
      (rest  "$mcname$ goes feh! at $hcname$.")
    )
    (arguments
      (arguments like Dogbolter,like Taffyd on a bad code day,like Laurana on a bad hair day,anxiously,angrily,#)
      (self   "You go feh! $arg$ at $hcname$.")
      (target "$mcname$ goes feh! $arg$ at you.")
      (rest  "$mcname$ goes feh! $arg$ at $hcname$.")
    )
  )
)

