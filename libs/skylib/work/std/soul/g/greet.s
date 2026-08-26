(greet
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  happily,sadly,with open arms,annoyingly,impatiently,ecstatically,carefully,courteously,hysterically,reservedly,warmly,coldly,insolently,curtly,absentmindedly,slightly)
      (self   "You greet $hcname$ $arg$.")
      (target "$mcname$ greets you $arg$.")
      (rest  "$mcname$ greets $hcname$ $arg$.")
    )
  )
)

