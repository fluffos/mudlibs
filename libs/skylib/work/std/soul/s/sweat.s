(sweat
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [on] <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments profusely,vigorously,wetly,rudely,petrol,bricks,buckets,
       buckets of igloos,artichokes,loudly,igloos,silently,anxiously,patiently,hotly,blood)
      (self "You sweat $arg$.")
      (rest "$mcname$ sweats $arg$.")
    )
  )
  (targeted
    (arguments
      (arguments  profusely,vigorously,wetly,rudely,petrol,bricks,buckets,buckets of igloos,
       artichokes,loudly,igloos,silently,anxiously,patiently,hotly,blood)
      (self   "You sweat $arg$ on $hcname$.")
      (target "$mcname$ sweats $arg$ on you.")
      (rest  "$mcname$ sweats $arg$ at $hcname$.")
    )
  )
)

