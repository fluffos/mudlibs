(hop
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hop around a bit.")
      (rest "$mcname$ hops around a bit.")
    )
  )
  (targeted
    (arguments
      (arguments  arms,pool,house,car,bed,frog,television,pocket,#)
      (self   "You hop into $mhcname$ $arg$.")
      (target "$mcname$ hops into your $arg$.")
      (rest  "$mcname$ hops into $mhcname$ $arg$.")
    )
  )
)

