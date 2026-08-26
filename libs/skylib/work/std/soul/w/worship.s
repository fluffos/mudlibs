(worship
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")

  (targeted
    (no-arguments
      (self   "You worship $hcname$.")
      (target "$mcname$ worships you.")
      (rest   "$mcname$ worships $hcname$.")
    )
    (arguments
      (arguments slightly,sarcastically,uncertainly,fawningly,sickeningly,embarrasingly,#)
      (self "You worship $hcname$ $arg$.")
      (target "$mcname$ worships you $arg$.")
      (rest   "$mcname$ worships $hcname$ $arg$.")
    )
  )
  (single
    (arguments
      (arguments fresh air,#)
      (self "You worship $arg$.")
      (rest "$mcname$ worships $arg$.")
    )
  )
)
