(ack
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You ack.")
      (rest "$mcname$ acks.")
    )
    (arguments
      (arguments seductively,happily,carefully)
      (self "You ack $arg$.")
      (rest "$mcname$ acks $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You ack at $hcname$.")
      (target "$mcname$ acks at you.")
      (rest  "$mcname$ acks at $hcname$.")
    )
    (arguments
      (arguments  seductively,happily,carefully)
      (self   "You ack $arg$ at $hcname$.")
      (target "$mcname$ acks $arg$ at you.")
      (rest  "$mcname$ acks $arg$ at $hcname$.")
    )
  )
)

