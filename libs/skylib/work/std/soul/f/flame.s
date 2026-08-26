(flame
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments like Signe,like a dragon,with napalm,with propane,fishily,with a high explosive womble,with glee,without remorse,froggily,forcefully,to 5000 degrees)
      (self "You flame $arg$.")
      (rest "$mcname$ flames $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  like Signe,like a dragon,with napalm,with propane,fishily,with a high explosive womble,with glee,without remorse,froggily,forcefully,to 5000 degrees,into small charred frog bits)
      (self   "You flame $hcname$ $arg$.")
      (target "$mcname$ flames you $arg$.")
      (rest  "$mcname$ flames $hcname$ $arg$.")
    )
  )
)

