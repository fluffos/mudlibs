(beg
  (pattern "at <indirect:any-living> like a <string>")
  (pattern "like a <string> at <indirect:any-living>")
  (pattern "like a <string>")
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments dog,cat,frog,chicken,frisbee,cow,large bear,poodle,chihuahua,train,beggar,noble man,lassie,labrador,german shepherd,cannibal,chimpanzee,orang-utang,librarian,fish,dolphin,tokzic,banshee,bloodhound,st bernard,virgin mary,husky,wolf,dingo,alsatian)
      (self "You beg like a $arg$.")
      (rest "$mcname$ begs like a $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  dog,cat,frog,chicken,frisbee,cow,large bear,poodle,chihuahua,train,beggar,noble man,lassie,labrador,german shepherd,cannibal,chimpanzee,orang-u-tang,librarian,fish,dolphin,tokzic,banshee,bloodhound,st bernard,virgin mary,husky,wolf,dingo,alsatian,train)
      (self   "You beg like a $arg$ at $hcname$.")
      (target "$mcname$ begs like a $arg$ at you.")
      (rest  "$mcname$ begs like a $arg$ at $hcname$.")
    )
  )
)

