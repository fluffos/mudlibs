(idle
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (single
    (arguments
      (arguments like Shaydz,like sloths do,like a gherkin,like everyone else is,nonchalantly,quickly,unbelievably well,without using your hands,upside-down,hyperactively,standing still,artfully,around,intensely)
      (self "You idle $arg$.")
      (rest "$mcname$ idles $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You idle like $hcname$.")
      (target "$mcname$ idles like you.")
      (rest  "$mcname$ idles like $hcname$.")
    )
  )
)

