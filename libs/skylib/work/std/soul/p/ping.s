(ping
  (pattern "<indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You ping $hcname$.")
      (target "$mcname$ pings you.")
      (rest  "$mcname$ pings $hcname$.")
      (force "ack $mcname$")
    )
  )
)

