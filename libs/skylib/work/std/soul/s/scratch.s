(scratch
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (arguments
      (arguments head,leg,arm,nose,ear,finger,bum,cat behind the ears)
      (self "You scratch your $arg$.")
      (rest "$mcname$ scratches $mposs$ $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You scratch $hcname$.")
      (target "$mcname$ scratches you.")
      (rest  "$mcname$ scratches $hcname$.")
    )
    (arguments
      (arguments  back,head,leg,arm,nose,ear,finger,bum)
      (self   "You scratch $mhcname$ $arg$.")
      (target "$mcname$ scratches your $arg$.")
      (rest  "$mcname$ scratches $mhcname$ $arg$.")
    )
  )
)

