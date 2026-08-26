(melt
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You melt.")
      (rest "$mcname$ melts.")
    )
    (arguments
      (arguments quickly,slowly,into a nice puddle,carefully,
           in anticipation,in ecstasy,seductively,submissively,a little)
      (self "You melt $arg$.")
      (rest "$mcname$ melts $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments arms,mouth,room,house,candle,moth,cupcake)
      (target "$mcname$ melts in your $arg$.")
      (rest   "$mcname$ melts in $mhcname$ $arg$.")
      (self   "You melt in $mhcname$ $arg$.")
    )
    (arguments
      (arguments with flames,coldly,excitedly,happily,brightly,
                 using a coffee table,in anticipation,seductively,quickly,
                 carefully,slowly,submissively)
      (target "$mcname$ melts $arg$ in your arms.")
      (rest   "$mcname$ melts $arg$ in $mhcname$ arms.")
      (self   "You melt $arg$ in $mhcname$ arms.")
    )
    (arguments
      (arguments cover yourself in chocolate sauce)
      (self   "You $arg$ and melt in $mhcname$ arms.")
      (target "$mcname$ $arg$ and melts in your arms.")
      (rest   "$mcname$ $arg$ and melts in $mhcname$ arms.")
    )
    (arguments
      (arguments scream,faint,explode,overheat)
      (self   "You $arg$ and melt in $mhcname$ arms.")
      (target "$mcname$ $arg$s and melts in your arms.")
      (rest   "$mcname$ $arg$s and melts in $mhcname$ arms.")
    )
  )
)

