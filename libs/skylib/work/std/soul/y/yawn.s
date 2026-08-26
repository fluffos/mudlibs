(yawn
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You yawn.")
      (rest "$mcname$ yawns.")
    )
    (arguments
      (arguments tiredly,boredly,sleepily,happily,brightly,in sympathy,
                 hugely,loudly,dramatically)
      (self "You yawn $arg$.")
      (rest "$mcname$ yawns $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You yawn at $hcname$.")
      (target "$mcname$ yawns at you.")
      (rest  "$mcname$ yawns at $hcname$.")
    )
    (arguments
      (arguments tiredly,boredly,sleepily,happily,brightly,in sympathy,
                 hugely,loudly,dramatically)
      (self   "You yawn $arg$ at $hcname$.")
      (target "$mcname$ yawns $arg$ at you.")
      (rest  "$mcname$ yawns $arg$ at $hcname$.")
    )
  )
)
