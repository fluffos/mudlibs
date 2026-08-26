(scold
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You scold $hcname$.")
      (target "$mcname$ scolds you.")
      (rest  "$mcname$ scolds $hcname$.")
    )
    (arguments
      (arguments  playfully,mercilessly,emphatically,whilst stifling a giggle,lovingly,sneakily,pointlessly,uselessly,loudly,endlessly,irritably,conveniently)
      (self   "You scold $hcname$ $arg$.")
      (target "$mcname$ scolds you $arg$.")
      (rest  "$mcname$ scolds $hcname$ $arg$.")
    )
  )
)

