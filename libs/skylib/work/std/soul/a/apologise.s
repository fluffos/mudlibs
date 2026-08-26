(apologise
  (pattern "[to] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You apologise.")
      (rest "$mcname$ apologises.")
    )
    (arguments
      (arguments  profusely, happily, sadly, reservedly, carefully, slowly, 
                  perfunctorily, curtly, viciously, sulkily, drunkenly, 
                  unhappily, professionally, pompously, wholeheartedly, 
                  partially, wearily, fishily, facetiously, unnecessarily, 
                  spontaneously, twice, thoroughly, humbly, #)
      (self "You apologise $arg$.")
      (rest "$mcname$ apologises $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You apologise to $hcname$.")
      (target "$mcname$ apologises to you.")
      (rest   "$mcname$ apologises to $hcname$.")
    )
    (arguments
      (arguments  profusely, happily, sadly, reservedly, carefully, slowly, 
                  perfunctorily, curtly, viciously, sulkily, drunkenly, 
                  unhappily, professionally, pompously, wholeheartedly, 
                  partially, wearily, fishily, facetiously, unnecessarily, 
                  spontaneously, twice, thoroughly, humbly, #)
      (self   "You apologise $arg$ to $hcname$.")
      (target "$mcname$ apologises $arg$ to you.")
      (rest   "$mcname$ apologises $arg$ to $hcname$.")
    )
  )
)

