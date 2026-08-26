(snore
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You snore.")
      (rest "$mcname$ snores.")
    )
    (arguments
     (arguments loudly,sadly,joyfully,sagely,knowingly,quickly,happily,carefully,
     balefully,excitedly,nervously,brightly,uncertainly,threateningly,grumpily,
     fluffily,absentmindedly,quickly)
      (self "You snore $arg$.")
      (rest "$mcname$ snores $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You snore at $hcname$.")
      (target "$mcname$ snores at you.")
      (rest  "$mcname$ snores at $hcname$.")
    )
    (arguments
      (arguments loudly,sadly,joyfully,sagely,knowingly,quickly,happily,carefully,
            balefully,excitedly,nervously,brightly,uncertainly,threateningly,
            grumpily, fluffily,absentmindedly,quickly)
      (self   "You snore $arg$ at $hcname$.")
      (target "$mcname$ snores $arg$ at you.")
      (rest  "$mcname$ snores $arg$ at $hcname$.")
    )
  )
)

