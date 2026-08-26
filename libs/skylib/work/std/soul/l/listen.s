(listen
  (pattern "[to] <indirect:any-living>")
  (pattern "<string> [to] <indirect:any-living>")
  (targeted
    (arguments
      (arguments  intently,carefully,boredly,patiently,silently,rudely)
      (self   "You listen $arg$ to $hcname$.")
      (target "$mcname$ listens $arg$ to you.")
      (rest  "$mcname$ listens $arg$ to $hcname$.")
    )
  )
)

