(serenade
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You serenade everyone.")
      (rest "$mcname$ serenades everyone.")
    )
    (arguments
      (arguments  softly, musically, melodically, harmoniously,
                  romantically, seductively, lovingly, insistently, 
                  with a guitar, with love songs, under the moon, 
                  under the stars, in the rain, on a balcony,
                  in the warm still night, on a warm spring day,
                  like Casanunda)
      (self "You serenade everyone $arg$.")
      (rest "$mcname$ serenades everyone $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You serenade $hcname$.")
    (target "$mcname$ serenades you.")
    (rest "$mcname$ serenades $hcname$.")
  )
  (arguments
    (arguments  softly, musically, melodically, harmoniously,
                romantically, seductively, lovingly, insistently, 
                with a guitar, with love songs, under the moon, 
                under the stars, in the rain, on a balcony,
                in the warm still night, on a warm spring day,
                like Casanunda)
    (self "You serenade $hcname$ $arg$." )
    (target "$mcname$ serenades you $arg$." )
    (rest "$mcname$ serenades $hcname$ $arg$." )
    )
  )
)
