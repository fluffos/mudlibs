(warn
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You warn $hcname$.")
      (target "$mcname$ warns you.")
      (rest  "$mcname$ warns $hcname$.")
    )
    (arguments
      (arguments  angrily,evilly,wickedly,carefully,slightly,hysterically,patienly,sagely,vigorously,dangerously,knowingly,faintly,#)
      (self   "You warn $hcname$ $arg$.")
      (target "$mcname$ warns you $arg$.")
      (rest  "$mcname$ warns $hcname$ $arg$.")
    )
  )
)

