(hmm
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You hmm.")
      (rest "$mcname$ goes hmm.")
    )
    (arguments
      (arguments manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,chee
        kily,idiotically,tentatively,wryly,sceptically,#)
      (self "You hmm $arg$.")
      (rest "$mcname$ hmms $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You hmm at $hcname$.")
      (target "$mcname$ goes hmm at you.")
      (rest  "$mcname$ goes hmm at $hcname$.")
    )

    (arguments
      (arguments  manically,evilly,wickedly,insanely,mischievously,devilishly,impishly,che
        ekily,idiotically,wryly,sceptically,#)
      (self   "You hmm $arg$ at $hcname$.")
      (target "$mcname$ goes hmm $arg$ at you.")
      (rest  "$mcname$ goes hmm $arg$ at $hcname$.")
    )
  )
)
