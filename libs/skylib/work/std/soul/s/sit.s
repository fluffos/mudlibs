(sit
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments thoughtfully,quickly,slowly,clumsily,carefully,
                 with one hand tied behind your back,in shock,gracefully,
                 gratefully,inconsiderately,quietly, #)
      (self "You sit $arg$.")
      (rest "$mcname$ sits $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  lap,face,leg,chest,arm,cat,sofa,computer,keyboard,dinner,#)
      (self   "You sit on $mhcname$ $arg$.")
      (target "$mcname$ sits on your $arg$.")
      (rest  "$mcname$ sits on $mhcname$ $arg$.")
    )
  )
)
