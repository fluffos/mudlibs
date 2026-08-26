(fika
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>")
  (pattern "<string> <indirect:any-living>")
  (single
    (no-arguments
      (self "You fika.")
      (rest "$mcname$ fikas.")
    )
    (arguments
      (arguments  on a coffee table, like Wix, madly, passionately, wildly, 
                  without precautions, with cream, without cream, with two sugars, 
                  in a cafe, with milk, with non-dairy creamer, with foam, 
                  with a bowl of cream and a plate of strawberry shortbread, #)
      (self "You fika $arg$.")
      (rest "$mcname$ fikas $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You fika $hcname$.")
      (target "$mcname$ fikas you.")
      (rest   "$mcname$ fikas $hcname$.")
    )
    (arguments
      (arguments  on a coffee table, like Wix, madly, passionately, wildly, 
                  without precautions, with cream, without cream, with two sugars, 
                  in a cafe, with milk, with non-dairy creamer, with foam, 
                  with a bowl of cream and a plate of strawberry shortbread, #)
      (self   "You fika $hcname$ $arg$." )
      (target "$mcname$ fikas you $arg$." )
      (rest   "$mcname$ fikas $hcname$ $arg$." )
    )
  )
)
