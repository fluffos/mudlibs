(praise
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You praise $hcname$.")
      (target "$mcname$ praises you.")
      (rest  "$mcname$ praises $hcname$.")
    )
    (arguments
      (arguments  to the skies,obsequiously,loudly,and asks for more money,#)
      (self   "You praise $hcname$ $arg$.")
      (target "$mcname$ praises you $arg$.")
      (rest  "$mcname$ praises $hcname$ $arg$.")
    )
  )
)
/* Hobbes */
