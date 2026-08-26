(woo
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
   (no-arguments
    (self   "You woo.")
    (rest  "$mcname$ woos.")
      )
    (arguments
      (arguments
          vaguely,carefully,slowly,dangerously,quietly,silently,sarcastically,
          falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,happily,backwards,sideways,#)
      (self "You woo $arg$.")
      (rest "$mcname$ woos $arg$.")
    )
   (arguments
       (arguments pleasure,amazement,#)
       (self "You woo in $arg$.")
       (rest "$mcname$ woos in $arg$.")
  )
   )
  (targeted
    (no-arguments
      (self   "You woo at $hcname$.")
      (target "$mcname$ woos at you.")
      (rest  "$mcname$ woos at $hcname$.")
    )
    (arguments
      (arguments
          vaguely,carefully,slowly,dangerously,quietly,silently,sarcastically,
          falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,happily,backwards,sideways,#)
      (self   "You woo $arg$ at $hcname$.")
      (target "$mcname$ woos $arg$ at you.")
      (rest  "$mcname$ woos $arg$ at $hcname$.")
    )
     (arguments
       (arguments pleasure,amazement,#)    
       (self "You woo in $arg$ at $hcname$.")   
       (target "$mcname$ woos in $arg$ at you.")  
       (rest "$mcname$ woos in $arg$ at $hcname$.")
 )
  )
)

