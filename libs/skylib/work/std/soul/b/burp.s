(burp
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You burp.")
      (rest "$mcname$ burps.")
    )
    (arguments
      (arguments disgustingly,faintly,loudly,rudely,quickly,
      happily,annoyingly,lovingly,humbly,
      manically,absentmindedly,drunkenly,disturbingly,demonically,pleasantly,
      serenely,viciously,humbly,nastily,#)
      (self "You burp $arg$.")
      (rest "$mcname$ burps $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You burp at $hcname$.")
      (target "$mcname$ burps at you.")
      (rest  "$mcname$ burps at $hcname$.")
    )
    (arguments
      (arguments disgustingly,faintly,loudly,rudely,quickly,
      happily,annoyingly,lovingly,humbly,manically,absentmindedly,
      drunkenly,disturbingly,demonically,pleasantly,
      serenely,viciously,humbly,nastily,#)
      (self   "You burp $arg$ at $hcname$.")
      (target "$mcname$ burps $arg$ at you.")
      (rest  "$mcname$ burps $arg$ at $hcname$.")
    )
  )
)

