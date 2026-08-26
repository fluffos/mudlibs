(stare
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You stare into space.")
      (rest "$mcname$ stares into space.")
    )
    (arguments
      (arguments happily,sadly,worriedly,lazily,rudely,dazedly,hungrily,macabrely,absentmindedly,fanatically,lovingly,respectfully,womblely,froggily,desperately,sternly,tentatively,politely,listlessly,jealously,enviously,dreamily,intently,mindlessly,expectantly,longingly,nastily)
      (self "You stare $arg$ into space.")
      (rest "$mcname$ stares $arg$ into space.")
    )
  )
  (targeted
    (no-arguments
      (self   "You stare at $hcname$.")
      (target "$mcname$ stares at you.")
      (rest  "$mcname$ stares at $hcname$.")
    )
    (arguments
      (arguments  happily,sadly,worriedly,lazily,rudely,dazedly,hungrily,macabrely,absentmindedly,fanatically,lovingly,respectfully,womblely,froggily,desperately,sternly,tentatively,politely,listlessly,jealously,enviously,dreamily,intently,mindlessly,romantically,expectantly,longingly,continuously,annoyingly,nastily)
      (self   "You stare $arg$ at $hcname$.")
      (target "$mcname$ stares $arg$ at you.")
      (rest  "$mcname$ stares $arg$ at $hcname$.")
    )
  )
)

