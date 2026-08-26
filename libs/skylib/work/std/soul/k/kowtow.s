(kowtow
  (pattern "[to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You kowtow.")
      (rest "$mcname$ kowtows.")
    )
    (arguments
      (arguments awkwardly, grudgingly, slavishly, like someone with something to hide)
      (self "You kowtow $arg$.")
      (rest "$mcname$ kowtows $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You kowtow to $hcname$.")
      (target "$mcname$ kowtows to you.")
      (rest  "$mcname$ kowtows to $hcname$.")
    )
    (arguments
      (arguments awkwardly, grudgingly, slavishly, like someone with something to hide)    
      (self   "You kowtow $arg$ to $hcname$.")
      (target "$mcname$ kowtows $arg$ to you.")
      (rest  "$mcname$ kowtows $arg$ to $hcname$.")
    )
  )
)
