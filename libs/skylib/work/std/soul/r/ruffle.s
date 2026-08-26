(ruffle
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You ruffle $mhcname$ hair.")
      (target "$mcname$ ruffles your hair.")
      (rest  "$mcname$ ruffles $mhcname$ hair.")
    )
    (arguments
      (arguments  playfully,affectionately)
      (self   "You ruffle $mhcname$ hair $arg$.")
      (target "$mcname$ ruffles your hair $arg$.")
      (rest  "$mcname$ ruffles $mhcname$ hair $arg$.")
    )
  )
)

