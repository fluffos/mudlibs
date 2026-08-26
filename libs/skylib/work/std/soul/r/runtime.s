(runtime
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (single
    (no-arguments
      (self "You create a massive runtime due to a parse error.")
      (rest "$mcname$ creates a massive runtime error.")
    )
  )
  (targeted
    (no-arguments
      (self   "You cause a runtime in $hcname$.")
      (target "$mcname$ causes a runtime in you.")
      (rest  "$mcname$ causes a runtime in $hcname$.")
    )
    (arguments
      (arguments a fatal,a large,a small,a medium-sized,an average,
                 a strange,an original,a dangerous,a strange,a weird)
      (self   "You cause $arg$ runtime in $hcname$.")
      (target "$mcname$ causes $arg$ in you.")
      (rest  "$mcname$ causes $arg$ runtime in $hcname$.")
    )
  )
)

