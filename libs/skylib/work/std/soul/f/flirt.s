(flirt
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (no-arguments
      (self   "You flirt with $hcname$.")
      (target "$mcname$ flirts with you.")
      (rest  "$mcname$ flirts with $hcname$.")
    )
    (arguments
      (arguments  softly, passionately, deeply, tenderly, gently,
                  brightly, after a fashion, hopefully,
                  lovingly, lengthily, fishily, carefully, demandingly,
                  sensuously, longingly, hungrily, back, boringly,
                  inattentively, absentmindedly, frogily,
                  in an igloo, on a coffee table, in a shower,
                  outragously,
                  slowly, suspiciously, calmly, like pinkfish,
                  using a coffee table)
      (self   "You flirt with $hcname$ $arg$.")
      (target "$mcname$ flirts with you $arg$.")
      (rest  "$mcname$ flirts with $hcname$ $arg$.")
    )
  )
)

