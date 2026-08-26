(sorry
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You apologise to $hcname$.")
      (target "$mcname$ apologises to you.")
      (rest  "$mcname$ apologises to $hcname$.")
    )
    (arguments
      (arguments  profusely,reservedly,perfunctorily,carefully,insultingly,insolently)
      (self   "You apologise $arg$ to $hcname$.")
      (target "$mcname$ apologises $arg$ to you.")
      (rest  "$mcname$ apologises $arg$ to $hcname$.")
    )
  )
)

