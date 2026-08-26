(expect
  (pattern "[at] <indirect:any-living>")
  (targeted
    (no-arguments
      (self   "You look expectantly at $hcname$.")
      (target "$mcname$ looks expectantly at you.")
      (rest  "$mcname$ looks expectantly at $hcname$.")
    )
  )
)

