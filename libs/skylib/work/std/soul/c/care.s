(care
  (pattern "[for] <indirect:any-living>")
  (pattern "[about] <string>")
  (pattern "[about] <string> [for] <indirect:any-living>")
  (single
    (arguments
      (arguments frogs, string, free radicals, sheep, old people,
        new people, fluff, pocket watches, world politics, everything,
        fluridation, pool cleaners, stuff in a Rywfol like manner, #)
      (self "You care about $arg$.")
      (rest "$mcname$ cares about $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You care for $hcname$.")
      (target "$mcname$ cares for you.")
      (rest  "$mcname$ cares for $hcname$.")
    )
    (arguments
      (arguments frogs, string, free radicals, sheep, old people,
          new people, fluff, pocket watches, world politics, everything,
          fluridation, pool cleaners, stuff in a Rywfol like manner, #)
      (self   "You care about $arg$ for $hcname$.")
      (target "$mcname$ cares about $arg$ for you.")
      (rest  "$mcname$ cares about $arg$ for $hcname$.")
    )
  )
)
/* Recoded by Hobbes, 970931 */
