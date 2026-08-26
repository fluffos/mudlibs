(huggle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You huggle $hcname$.")
      (target "$mcname$ huggles you.")
      (rest   "$mcname$ huggles $hcname$.")
    )
    (arguments
      (arguments  tightly, warmly, gently, close, under your jumper, #)
      (self   "You huggle $hcname$ $arg$.")
      (target "$mcname$ huggles you $arg$.")
      (rest   "$mcname$ huggles $hcname$ $arg$.")
    )
  )
)

