(mercy
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
        (self "You beg for mercy.")
        (rest "$mcname$ begs for mercy.")
        )
  )
  (targeted
    (no-arguments
      (self "You throw yourself down at $hposs$ feet and beg for mercy.")
      (target "$mcname$ throws $mobj$self down at your feet and begs for mercy.")
      (rest "$mcname$ throws $mobj$self down at $hcname$'s feet and begs for mercy.")
    )
  )
)
