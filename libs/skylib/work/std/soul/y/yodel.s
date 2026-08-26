(yodel
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments loudly,sadly,annoyingly,feverishly,quickly,tunelessly,incessantly,constantly,to the tune of william tell's overture)
      (self "You yodel $arg$.")
      (rest "$mcname$ yodels $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  happily,sadly,annoyingly,romantically,dreamily,incessantly,constantly,to the tune of william tell's overture,carefully,loudly,sternly,pinkly,like a blackboard,with the frogs)
      (self   "You yodel $arg$ to $hcname$.")
      (target "$mcname$ yodels $arg$ to you.")
      (rest  "$mcname$ yodels $arg$ to $hcname$.")
    )
  )
)

