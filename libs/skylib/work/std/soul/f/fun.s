(fun
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You hope everyone has fun.")
      (rest "$mcname$ hopes everyone has fun.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hope $hcname$ has fun.")
      (target "$mcname$ hopes you have fun.")
      (rest  "$mcname$ hopes $hcname$ has fun.")
    )
  )
)

