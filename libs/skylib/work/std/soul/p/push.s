(push
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You push yourself over$position$.")
      (rest "$mcname$ pushes $mobj$self over$position$.")
      (position
        (standing "sit")
        (lying    "ignore")
        (default  "lie")
        (silent "yes")
      )
    )
  )
  (targeted
    (no-arguments
      (self   "You push $hcname$ over$position$.")
      (target "$mcname$ pushes you over$position$.")
      (rest  "$mcname$ pushes $hcname$ over$position$.")
      (position
        (standing "sit")
        (lying "ignore")
        (default "lie")
        (silent "yes")
      )
    )
  )
)

