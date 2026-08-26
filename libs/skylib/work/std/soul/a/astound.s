(astound
  (pattern "<indirect:any-living>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You are astounded!")
      (rest "$mcname$ is astounded!")
    )
  )
  (targeted
    (no-arguments
      (self   "You astound $hcname$!")
      (target "$mcname$ astounds you!")
      (rest  "$mcname$ astounds $hcname$.")
    )
    (arguments
      (arguments  stupidity,cleverness,thoughtfulness,dumbness,idiocy,clever use of soul commands,deviousness,VW Beetle,annoyingness,paranoia,wideness of grin,coffee table,womble,grinning frog,stupid pet tricks)
      (self   "You astound $hcname$ with your $arg$!")
      (target "$mcname$ astounds you with $mposs$ $arg$!")
      (rest  "$mcname$ astounds $hcname$ with $mposs$ $arg$.")
    )
  )
)
