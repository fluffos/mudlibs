(shove
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (targeted
    (arguments
      (arguments  over)
      (self   "You shove $hcname$ $arg$$position$.")
      (target "$mcname$ shoves you $arg$$position$.")
      (rest  "$mcname$ shoves $hcname$ $arg$$position$.")
      (position
        (standing "sit")
        (default  "lie")
        (lying    "ignore")
        (silent   "yes")
      )
    )
    (arguments
      (arguments  off the couch, into the pool, into a bowl of jelly,
                  off a cliff, out of the way, under the bed,
                  into the cupboard)
      (self   "You shove $hcname$ $arg$$position$.")
      (target "$mcname$ shoves you $arg$$position$.")
      (rest  "$mcname$ shoves $hcname$ $arg$$position$.")
      (position
        (standing "sit")
        (default  "lie")
        (lying    "ignore")
        (silent   "yes")
      )
    )
    (arguments
      (arguments  onto the bed, onto the coffee table)
      (self   "You shove $hcname$ $arg$$position$.")
      (target "$mcname$ shoves you $arg$$position$.")
      (rest  "$mcname$ shoves $hcname$ $arg$$position$.")
      (position
        (default "lie")
        (lying    "ignore")
        (silent   "yes")
      )
    )
  )
)

