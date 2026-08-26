(signal
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You signal wildly.")
      (rest "$mcname$ signals wildly.")
    )
    (arguments
      (arguments happily,madly,like someone desperate of attention,manically,
       evilly,wickedly,insanely,mischievously,with your ears,with your nose,
       with your arms,with every free limb available,with your toes,
       devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically)
      (self "You signal $arg$.")
      (rest "$mcname$ signals $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You signal wildly at $hcname$.")
      (target "$mcname$ signals wildly at you.")
      (rest  "$mcname$ signals wildly at $hcname$.")
    )
    (arguments
      (arguments  happily,madly,like someone desperate of attention,manically,
         evilly,wickedly,insanely,mischievously,with your ears,with your nose,
         with your arms,with every free limb available,with your toes,
         devilishly,impishly,cheekily,idiotically,tentatively,wryly,sceptically)
      (self   "You signal $arg$ at $hcname$.")
      (target "$mcname$ signals $arg$ at you.")
      (rest  "$mcname$ signals $arg$ at $hcname$.")
    )
  )
)

