(sniff
  (pattern "<string>")
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>")
  (single
    (no-arguments
      (self "You sniff.")
      (rest "$mcname$ sniffs.")
    )
    (arguments
      (arguments dejectedly, noisily, silently, loudly, in disdain
                 lustily, with a bad cold, expressively, suddenly)
      (self "You sniff $arg$.")
      (rest "$mcname$ sniffs $arg$.")
    )
    (arguments
      (arguments hair, nose, ear, eyebrow, leg, foot, arm, back,
                 chest, thigh, clothes, cheek, fingers, toe,
                 celery, carrot)
      (self "You sniff your $arg$.")
      (rest "$mcname$ sniffs $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self "You sniff at $hcname$.")
      (target "$mcname$ sniffs at you.")
      (rest "$mcname$ sniffs at $hcname$.")
    )
    (arguments
      (arguments dejectedly, noisily, silently, loudly, in disdain,
                 lustily, with a bad cold, expressively, suddenly)
      (self "You sniff $arg$ at $hcname$.")
      (rest "$mcname$ sniffs $arg$ at you.")
      (rest "$mcname$ sniffs $arg$ at $hcname$.")
    )
    (arguments
      (arguments hair, nose, ear, eyebrow, leg, foot, arm, back,
                 chest, thigh, clothes, cheek, fingers, toe,
                 celery, carrot)
      (self "You sniff $mhcname$ $arg$.")
      (rest "$mcname$ sniffs your $arg$.")
      (rest "$mcname$ sniffs $mhcname$ $arg$.")
    )
  )
)
