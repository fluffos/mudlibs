(sob
  (pattern "[on] <indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments quietly,loudly,despairingly,forlornly,happily,uncontrollably,completely,unexpectedly,silently,cheekily)
      (self "You sob $arg$.")
      (rest "$mcname$ sobs $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You sob on $mhcname$ shoulder.")
      (target "$mcname$ sobs on your shoulder.")
      (rest  "$mcname$ sobs on $mhcname$ shoulder.")
    )
  )
)

