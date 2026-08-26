(shake
  (pattern "<indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (pattern "[my] <string>")
  (pattern "<string> [with|at] <indirect:any-living>")
  (single
    (no-arguments
      (self "You shake your head.")
      (rest "$mcname$ shakes $mposs$ head.")
    )
    (arguments
      (arguments sorrowfully,carefully,slowly,once,quickly,curtly,pinkly,vigorously,completely,fishily,sadly,tentatively,in agreement,in disbelief)
      (self "You shake your head $arg$.")
      (rest "$mcname$ shakes $mposs$ head $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You shake $hcname$.")
      (target "$mcname$ shakes you.")
      (rest  "$mcname$ shakes $hcname$.")
    )
    (arguments
      (arguments  hands with,fins with,fingers with,legs with,pinkies with,tentacles with,your fist at,claws with,your head at)
      (self   "You shake $arg$ $hcname$.")
      (target "$mcname$ shakes $arg$ you.")
      (rest  "$mcname$ shakes $arg$ $hcname$.")
    )
  )
)

