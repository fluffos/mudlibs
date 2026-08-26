(cheer
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments enthusiastically,excitedly,quietly,calmly,carefully,politely,wildly,oddly,unconvincingly,happily,slightly,up,loudly,lamely)
      (self "You cheer $arg$.")
      (rest "$mcname$ cheers $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  enthusiastically,excitedly,quietly,calmly,wildly,unconvincingly,carefully,happily,politely,oddly,slightly,up,loudly,lamely)
      (self   "You cheer $arg$ at $hcname$.")
      (target "$mcname$ cheers $arg$ at you.")
      (rest  "$mcname$ cheers $arg$ at $hcname$.")
    )
  )
)

