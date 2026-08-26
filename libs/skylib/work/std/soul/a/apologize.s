(apologize
  (pattern "[to] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [to] <indirect:any-living>")
  (pattern "[to] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments profusely,happily,sadly,reservedly,carefully,slowly,
                 perfunctorily,curtly,viciously,sulkily,drunkenly,unhappily,
                 professionally,pompously,wholeheartedly,partially,wearily,
                 fishily,facetiously,unnecessarily,spontaneously,twice,
                 thoroughly,humbly)
      (self "You apologize $arg$.")
      (rest "$mcname$ apologizes $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  profusely,happily,sadly,reservedly,carefully,slowly,
                  perfunctorily,curtly,viciously,sulkily,drunkenly,unhappily,
                  professionally,pompously,wholeheartedly,partially,wearily,
                  fishily,facetiously,unnecessarily,spontaneously,twice,
                  thoroughly,humbly)
      (self   "You apologize $arg$ to $hcname$.")
      (target "$mcname$ apologizes $arg$ to you.")
      (rest  "$mcname$ apologizes $arg$ to $hcname$.")
    )
  )
)

