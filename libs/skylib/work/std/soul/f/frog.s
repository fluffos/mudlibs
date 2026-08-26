(frog
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments mindlessly,silently,happily,carefully,#)
      (self "You frog around $arg$.")
      (rest "$mcname$ frogs around $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You turn $hcname$ into a frog$position$.")
      (target "$mcname$ turns you into a frog$position$.")
      (rest  "$mcname$ turns $hcname$ into a frog$position$.")
      (force "croak")
      (position
        (default "crouch")
        (silent "yes")
      )
    )
    (arguments
      (arguments  slowly,carefully,excruciatingly,happily,gleefully,magically)
      (self   "You $arg$ turn $hcname$ into a frog$position$.")
      (target "$mcname$ $arg$ turns you into a frog$position$.")
      (rest  "$mcname$ $arg$ turns $hcname$ into a frog$position$.")
      (force "croak")
      (position
        (default "crouch")
        (silent "yes")
      )
    )
  )
)

