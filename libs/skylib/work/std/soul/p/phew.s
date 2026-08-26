(phew
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wipe your brow and go: PHEW!")
      (rest "$mcname$ wipes $mposs$ brow and goes: PHEW!")
    )
    (arguments
      (arguments with relief,happily,#)
      (self "You wipe your brow $arg$ and go: PHEW! $arg$.")
      (rest "$mcname$ wipes $mposs$ brow $arg$ and goes: PHEW!")
    )
  )
  (targeted
    (no-arguments
      (self   "You wipe your brow and go: PHEW! at $hcname$.")
      (target "$mcname$ wipes $mposs$ brow and goes: PHEW! at you.")
      (rest  "$mcname$ wipes $mposs$ brow and goes: PHEW! at $hcname$.")
    )
    (arguments
      (arguments  with relief,happily,#)
      (self   "You wipe your brow $arg$ and go: PHEW! at $hcname$.")
      (target "$mcname$ wipes $mposs$ brow $arg$ and goes: PHEW! at you.")
      (rest  "$mcname$ wipes $mposs$ brow $arg$ and goes: PHEW! at $hcname$.")
    )
  )
)

