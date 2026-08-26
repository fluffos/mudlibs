(cackle
  (pattern "<indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [at] <indirect:any-living>")
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments     
      (self "You cackle with glee.")
      (rest "$mcname$ throws back $mposs$ head and cackles with glee.")
    )
  )
  (targeted
    (no-arguments
      (self   "You cackle at $hcname$.")
      (target "$mcname$ cackles at $hcname$.")
      (rest   "$mcname$ cackles at $hcname$.")
	)
     (arguments
      (arguments with glee,happily,sadly,brightly,curtly,patiently,slowly,eagerly,expectantly,firmly,sagely,emphatically,knowingly,vigorously,in disagreement,tentatively,angrily,manically,mischievously,nastily,despairingly,womblely,backwards,#)
      (self   "You cackle $arg$ at $hcname$.")
      (target "$mcname$ cackles $arg$ at you.")
      (rest   "$mcname$ cackles $arg$ at $hcname$.")
    )
  )
)

