(muss
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You muss $mhcname$ hair.")
      (target "$mcname$ musses your hair.")
      (rest   "$mcname$ musses $mhcname$ hair.")
    )
    (arguments
      (arguments slowly,lovingly,with a brick,patronisingly,
                 suggestively,just like Kylie would)
      (self   "You muss $mhcname$ hair $arg$.")
      (target "$mcname$ musses your hair $arg$.")
      (rest   "$mcname$ musses $mhcname$ hair $arg$.")
    )
  )
)

