(whistle
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")

  (single
    (arguments
      (arguments innocently,appreciatively,loudly,musically,mischievously,
                 pleasantly,discordantly,tunelessly,covertly,#)
      (self "You whistle $arg$.")
      (rest "$mcname$ whistles $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments appreciatively,innocently,loudly,musically,mischievously,
                 pleasantly,discordantly,tunelessly,covertly,#)
      (self   "You whistle $arg$ at $hcname$.")
      (target "$mcname$ whistles $arg$ at you.")
      (rest   "$mcname$ whistles $arg$ at $hcname$.")
    )
  )
)
