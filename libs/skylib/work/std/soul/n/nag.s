(nag
  (pattern "[at] <indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")

  (targeted
    (no-arguments
      (self   "You nag at $hcname$.")
      (target "$mcname$ nags at you.")
      (rest  "$mcname$ nags at $hcname$.")
    )
    (arguments
      (arguments  creators,add_command,everything,nothing,unfinished code,players,#)
      (self   "You nag at $hcname$ about $arg$.")
      (target "$mcname$ nags at $hcname$ about $arg$.")
      (rest  "$mcname$ nags at $hcname$ about $arg$.")
    )
  )
)

