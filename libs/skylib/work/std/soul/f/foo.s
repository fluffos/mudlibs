(foo
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (arguments
      (arguments
          vaguely,carefully,slowly,dangerously,quietly,silently,sarcastically,
          falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,happily,backwards,sideways,#)
      (self "You foo $arg$.")
      (rest "$mcname$ foos $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You foo at $hcname$.")
      (target "$mcname$ foos at you.")
      (rest  "$mcname$ foos at $hcname$.")
    )
    (arguments
      (arguments
          vaguely,carefully,slowly,dangerously,quietly,silently,sarcastically,
          falsely,manically,evilly,wickedly,insanely,
         mischievously,devilishly,impishly,cheekily,idiotically,
         tentatively,wryly,sceptically,happily,backwards,sideways,#)
      (self   "You foo $arg$ at $hcname$.")
      (target "$mcname$ foos $arg$ at you.")
      (rest  "$mcname$ foos $arg$ at $hcname$.")
    )
  )
)

