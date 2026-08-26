(pity
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You pity $hcname$.")
      (target "$mcname$ pities you.")
      (rest  "$mcname$ pities $hcname$.")
    )
    (arguments
      (arguments #)
      (self   "You pity $hcname$ $arg$.")
      (target "$mcname$ pities you $arg$.")
      (rest  "$mcname$ pities $hcname$ $arg$.")
    )
  )
)

