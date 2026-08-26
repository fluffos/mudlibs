(sbite
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You bite yourself.")
      (rest "$mcname$ bites $mobj$self.")
    )
  )
  (targeted
    (no-arguments
      (self   "You bite $hcname$.")
      (target "$mcname$ bites you.")
      (rest  "$mcname$ bites $hcname$.")
    )
    (arguments
      (arguments  hard,nastily,carefully,politely,fishily,lovingly,
     refreshingly,happily,like a train,pointlessly,thoughtfully,
     objectively,sulkily,gently,brightly,excitedly,
     uncertainly,like a dog,wolfishly,mercilessly,ruthlessly,softly,
     sweetly,professionally,hungrily,mischievously,casually,like a vampire)
      (self   "You bite $hcname$ $arg$.")
      (target "$mcname$ bites you $arg$.")
      (rest  "$mcname$ bites $hcname$ $arg$.")
    )
  )
)

