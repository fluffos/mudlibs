(pant
  (pattern "<string>")
  (pattern "<string> at <indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (single
    (no-arguments
      (self "You pant.")
      (rest "$mcname$ pants.")
    )
    (arguments
      (arguments deeply, silently, desperately, tiredly, sadly, dreamily,
                 happily, melodramatically, wistfully, heavily, suggestively,
                 sarcastically, unconvincingly)
      (self "You pant $arg$.")
      (rest "$mcname$ pants $arg$.")
    )
  )
  (targeted
    (no-arguments
       (self "You pant at $hcname$.")
       (target "$mcname$ pants at you.")
       (rest "$mcname$ pants at $hcname$.")
    )
    (arguments
      (arguments deeply, silently, desperately, tiredly, sadly, dreamily,
                 happily, melodramatically, wistfully, heavily, suggestively,
                 sarcastically, unconvincingly)
      (self   "You pant $arg$ at $hcname$.")
      (target "$mcname$ pants $arg$ at you.")
      (rest   "$mcname$ pants $arg$ at $hcname$.")
    )
  )
)

