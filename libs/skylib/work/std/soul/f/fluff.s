(fluff
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You fluff $hcname$.")
      (target "$mcname$ fluffs you.")
      (rest  "$mcname$ fluffs $hcname$.")
    )
    (arguments
      (arguments happily,affectionately,warmly,gently,absentmindedly,
         carefully,warmly,absolutely,triumphantly,capriciously,
         suspiciously,drunkenly,aesthetically,insolently,faintly,
         delicately,hysterically,slightly,ecstatically,with a hair dryer,
         with a frog,in the nose,is this something dirty?,
         under a coffee table,#)
      (self   "You fluff $hcname$ $arg$.")
      (target "$mcname$ fluffs you $arg$.")
      (rest  "$mcname$ fluffs $hcname$ $arg$.")
    )
  )
)
/* Hobbes */

