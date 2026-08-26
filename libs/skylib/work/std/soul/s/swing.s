(swing
  (pattern "<indirect:any-living>")
  (targeted
    (no-arguments
      (self "You swing $hcname$ out onto the dance floor, just as the big band music starts up.")
      (target "$mcname$ swings you out onto the dance floor, just as the big band music starts up.")
      (rest "$mcname$ swings $hcname$ out on the dance floor, just as the big band music starts up.")

    )
    (arguments spinning, twirling, dipping, whirling, flinging, tripping,     
               hopping, dragging, pulling, pushing)
      (self "You swing $hcname$ out onto the dance floor, $arg$ $hobj$ as you go, just as the big band music starts up.")
     (target "$mcname$ swings you out onto the dance floor, $arg$ you as you go, just as the big band music starts up.")
      (rest "$mcname$ swings $hcname$ out on the dance floor, $arg$ $hcobj$ as they go, just as the big band music starts up..")
    ) 
  )
)

/* Saffra 2-25-00, idea by Archana */

