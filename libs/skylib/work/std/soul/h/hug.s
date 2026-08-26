(hug
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You hug $hcname$.")
      (target "$mcname$ hugs you.")
      (rest  "$mcname$ hugs $hcname$.")
    )
    (arguments
      (arguments  tightly,warmly,gently,close,#,like a huge bear)
      (self   "You hug $hcname$ $arg$.")
      (target "$mcname$ hugs you $arg$.")
      (rest  "$mcname$ hugs $hcname$ $arg$.")
    )
  )
)

