(bow
  (pattern "[to] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (single
     (no-arguments
        (self  "You bow.")
        (rest  "$mcname$ bows.")
     )
     (arguments
        (arguments solemnly,deeply,formally,hastily,slightly,
                   disgustedly,floridly,flamboyantly,
                   insolently,clumsily,dextrously,wildly,
                   colourfully,with a flourish)
        (self  "You bow $arg$.")
        (rest  "$mcname$ bows $arg$.")
      )
  )
  (targeted
     (no-arguments
        (self "You bow to $hcname$.")
        (rest "$mcname$ bows to $hcname$.")
        (target "$mcname$ bows to you.")
     )
     (arguments
        (arguments solemnly,deeply,formally,hastily,slightly,
                   disgustedly,floridly,flamboyantly,
                   insolently,clumsily,dextrously,wildly,
                   colourfully,with a flourish)
        (self "You bow $arg$ to $hcname$.")
        (rest "$mcname$ bows $arg$ to $hcname$.")
        (target "$mcname$ bows $arg$ to you.")
     )
  )
)

