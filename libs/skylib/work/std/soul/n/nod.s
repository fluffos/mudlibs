(nod
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
        (self "You nod.")
        (rest "$mcname$ nods.")
        )
      (arguments 
        (arguments solemnly,happily,sadly,brightly,curtly,patiently,
                 slowly,eagerly,expectantly,firmly,sagely,emphatically,
                 knowingly,vigorously,in disagreement,tentatively,angrily,
                 kindly,annoyingly,#)
      (self "You nod $arg$.")
      (rest "$mcname$ nods $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You nod at $hcname$.")
      (target "$mcname$ nods at you.")
      (rest  "$mcname$ nods at $hcname$.")
       )
      (arguments 
        (arguments solemnly,happily,sadly,brightly,curtly,patiently,
                 slowly,eagerly,expectantly,firmly,sagely,emphatically,
                 knowingly,vigorously,in disagreement,tentatively,angrily,
                 kindly,annoyingly,#)
      (self   "You nod $arg$ at $hcname$.")
      (target "$mcname$ nods $arg$ at you.")
      (rest   "$mcname$ nods $arg$ at $hcname$.")
    )
  )
)

