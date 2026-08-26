(wave
  (pattern "[at|to|at] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [to|at] <indirect:any-living>")
  (pattern "[at|to] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You wave.")
      (rest "$mcname$ waves.")
    )
    (arguments
      (arguments tiredly,sleepily,lazily,sadly,happily,redundantly,
                 forlornly,excitedly,longingly,pointlessly,madly,
                insanely,with complete devotion,cheerfully,merrily)
      (self "You wave $arg$.")
      (rest "$mcname$ waves $arg$.")
    )
    (arguments
      (arguments hand,tentacles,leg,frog,handkerchief)
      (self "You wave your $arg$.")
      (rest "$mcname$ waves $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You wave to $hcname$.")
      (target "$mcname$ waves to you.")
      (rest  "$mcname$ waves to $hcname$.")
    )
    (arguments
      (arguments sleepily,tiredly,perfunctorily,lazily,sadly,happily,
                 forlornly,excitedly,longingly,redundantly,pointlessly,
                 passionately,greenly,your tentacles,madly,insanely,
                 with complete devotion,cheerfully,merrily,#)
      (self   "You wave $arg$ to $hcname$.")
      (target "$mcname$ waves $arg$ to you.")
      (rest   "$mcname$ waves $arg$ to $hcname$.")
    )
  )
)

