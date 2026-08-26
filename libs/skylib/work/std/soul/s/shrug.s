(shrug
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You shrug.")
      (rest "$mcname$ shrugs.")
    )
    (arguments
      (arguments resignedly,tiredly,happily,confusedly,uncaringly,
                 uncertainly)
      (self "You shrug $arg$.")
      (rest "$mcname$ shrugs $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You shrug at $hcname$.")
      (target "$mcname$ shrugs at you.")
      (rest "$mcname$ shrugs at $hcname$.")
    )
    (arguments
      (arguments resignedly,tiredly,happily,confusedly,uncaringly,
                 uncertainly,back)
      (self "You shrug $arg$ at $hcname$.")
      (target "$mcname$ shrugs $arg$ at you.")
      (rest "$mcname$ shrugs $arg$ at $hcname$.")
    )
  )
)

