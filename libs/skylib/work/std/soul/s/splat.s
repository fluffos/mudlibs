(splat
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You go 'Boing! Boing! Splat!'")
      (rest "$mcname$ goes 'Boing! Boing! Splat!'")
    )
    (arguments
      (arguments manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,chee
        kily,idiotically,tentatively,wryly,sceptically)
      (self "You boing $arg$.")
      (rest "$mcname$ boings $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You fly through the air and land upon $hcname$. Oh my, $hpronoun$ is splatted!")
      (target "$mcname$ flies through the air and lands upon you. Oh my, you are splatted!")
      (rest "$mcname$ flies through the air and lands upon $hcname$. Oh my, $hpronoun$ is splatted!")
    )

    (arguments
      (arguments  manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,che
        ekily,idiotically,wryly,sceptically)
      (self   "You boing $arg$ at $hcname$.")
      (target "$mcname$ boings $arg$ at you.")
      (rest  "$mcname$ boings $arg$ at $hcname$.")
    )
  )
)
