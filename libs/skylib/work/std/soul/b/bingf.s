(bingf
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments sarcastically,sadly,joyfully,sagely,knowingly,quickly,loudly,carefully,balefully,excitedly,nervously,brightly,uncertainly)
      (self "You bing in a $arg$ but formatted way.")
      (rest "$mcname$ bings in a $arg$ but formatted way.")
    )
  )
  (targeted
    (arguments
      (arguments  sarcastically,sadly,joyfully,sagely,knowingly,quickly,loudly,carefully,balefully,excitedly,nervously,brightly,uncertainly)
      (self   "You bing in a $arg$ but formatted way with $hcname$.")
      (target "$mcname$ bings in a $arg$ but formatted way with you.")
      (rest  "$mcname$ bings in a $arg$ but formatted way with $hcname$.")
    )
  )
)

