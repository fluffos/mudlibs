(sleep
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You go to sleep.")
      (rest "$mcname$ goes to sleep.")
    )
  )
  (targeted
    (no-arguments
      (self   "You go to sleep in $mhcname$ arms.")
      (target "$mcname$ goes to sleep in your arms.")
      (rest  "$mcname$ goes to sleep in $mhcname$ arms.")
    )
  )
)

