(wuffle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  affectionately,warmly,gently,absentmindedly,carefully,warmly,
                  absolutely,triumphantly,capriciously,suspiciously,
                  drunkenly,astheticaly,insolently,faintly,delicately,fluffily,#)
      (self   "You wuffle $hcname$ $arg$.")
      (target "$mcname$ wuffles you $arg$.")
      (rest  "$mcname$ wuffles $hcname$ $arg$.")
    )
  )
)
