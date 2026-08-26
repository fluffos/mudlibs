(bing
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments happily, sadly, joyfully, sagely, knowingly, quickly,
                 loudly, carefully, balefully, excitedly, nervously,
                 brightly, uncertainly, threateningly, grumpily, fluffily,
                 evilly)
      (self "You bing $arg$.")
      (rest "$mcname$ bings $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  happily, sadly, joyfully, sagely, knowingly, quickly,
                  excitedly, nervously, brightly, uncertainly, grumpily,
                  loudly, carefully, balefully, threateningly, fluffily,
                  evilly, inquiringly)
      (self   "You bing $arg$ at $hcname$.")
      (target "$mcname$ bings $arg$ at you.")
      (rest  "$mcname$ bings $arg$ at $hcname$.")
    )
  )
)

