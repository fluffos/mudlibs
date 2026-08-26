(vader
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "<string>")  
  (single
    (no-arguments
      (self   "You squeeze your fingers together and say: \"I find your lack of faith disturbing.\"")    
      (rest   "$mcname$ squeezes $mposs$ fingers together and says: \"I find your lack of faith disturbing.\"")
    )
    (arguments
      (arguments I find your lack of faith disturbing, You have failed me for the last time Admiral, #)
      (self   "You squeeze your fingers together and say: \"$arg$\"")    
      (rest   "$mcname$ squeezes $mposs$ fingers together and says: \"$arg$\"")
    )    
  )
  (targeted
    (no-arguments
      (self   "You squeeze your fingers together and say to $hcname$: \"I find your lack of faith disturbing.\"")    
      (rest   "$mcname$ squeezes $mposs$ fingers together and says to $hcname$: \"I find your lack of faith disturbing.\"")    
      (target   "$mcname$ squeezes $mposs$ fingers together and says to $hcname$: \"I find your lack of faith disturbing.\"")          
    )
    (arguments
      (arguments I find your lack of faith disturbing, You have failed me for the last time Admiral, #)
      (self   "You squeeze your fingers together and say to $hcname$: \"$arg$\"")    
      (rest   "$mcname$ squeezes $mposs$ fingers together and says to $hcname$: \"$arg$\"")    
      (target   "$mcname$ squeezes $mposs$ fingers together and says to $hcname$: \"$arg$\"")          
    )
  )
)
