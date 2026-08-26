(pressgang
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self "You pressgang $hcname$ into an incredibly crazy plan.")
      (target "$mcname$ pressgangs you into an incredibly crazy plan.")
      (rest "$mcname$ pressgangs $hcname$ into an incredibly crazy plan.")
     )
    (arguments
      (arguments the navy,idling,coding,swimming the channel, being a hero,the army,taking medication,sleeping,joining a crazy scheme, reading a book,#)
      (self "You pressgang $hcname$ into $arg$.")
      (target "$mcname$ pressgangs you into $arg$.")
      (rest "$mcname$ pressgangs $hcname$ into $arg$.")
    )
  )
)
