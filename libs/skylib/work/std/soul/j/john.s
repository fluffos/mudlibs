(john
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You say, 'Well, pilgrim, this town ain't big enough fer the both o' us.'")
      (rest "$mcname$ says, 'Well, pilgrim, this town ain't big enough fer the both o' us.'")
    )
  )
  (targeted
    (no-arguments
      (self   "You tell $hcname$, 'Well, pilgrim, this town ain't big enough fer the both o' us.'")
      (target "$mcname$ tells you, 'Well, pilgrim, this town ain't big enough fer the both o' us.'")
      (rest  "$mcname$ tells $hcname$, 'Well, pilgrim, this town ain't big enough fer the both o' us.'")
    )
  )
)
