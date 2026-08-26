(fidget
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You fidget.")
      (rest "$mcname$ fidgets.")
    )
    (arguments
      (arguments nervously,#)
      (self "You fidget $arg$.")
      (rest "$mcname$ fidgets $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You fidget in $mhcname$ general direction.")
      (target "$mcname$ fidgets in your general direction.")
      (rest  "$mcname$ fidgets in $mhcname$ general direction.")
    )
  )
)
