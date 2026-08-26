(flip
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments head over heels,backwards,forwards,sideways,around,carefully,slowly,twice,doggily,awkwardly,disturbingly,disgustingly,quickly,slowly,gracefully,over the moon,around in a really complicated double back roll flip,half way around and land on your head)
      (self "You flip $arg$.")
      (rest "$mcname$ flips $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  head over heels,off,into the garbage bin,viciously,dangerously,spectacularly)
      (self   "You flip $hcname$ $arg$.")
      (target "$mcname$ flips you $arg$.")
      (rest  "$mcname$ flips $hcname$ $arg$.")
    )
  )
)

