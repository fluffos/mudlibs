(ssit
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You sit down.")
      (rest "$mcname$ sits down.")
    )
    (arguments
      (arguments quickly,slowly,clumsily,carefully,thoughtfully,
                 with one hand tied behind your back,in shock,gracefully,
                 gratefully,inconsiderately)
      (self "You sit down $arg$.")
      (rest "$mcname$ sits down $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  lap,face,leg,chest,arm,cat,sofa,computer,keyboard,dinner)
      (self   "You sit on $mhcname$ $arg$.")
      (target "$mcname$ sits on your $arg$.")
      (rest  "$mcname$ sits on $mhcname$ $arg$.")
    )
  )
)

