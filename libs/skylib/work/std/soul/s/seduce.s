(seduce
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You seduce $hcname$.")
      (target "$mcname$ seduces you.")
      (rest  "$mcname$ seduces $hcname$.")
    )
    (arguments
      (arguments  absentmindedly,with enthusiasm,casually,
         on a coffee table,with promises of chocolate,with love,
         lustfully,in a hurry,with a shovel,with your frog)
      (self   "You seduce $hcname$ $arg$.")
      (target "$mcname$ seduces you $arg$.")
      (rest  "$mcname$ seduces $hcname$ $arg$.")
    )
  )
)

