(bubble
  (pattern "[at] <indirect:any-living>")
  (single
    (no-arguments
      (self "I'm forever blowing bubbles!")
      (rest "$mcname$ starts to blow bubbles.")
    )
  )
  (targeted
    (no-arguments
      (self   "You blow bubbles at $hcname$.")
      (target "$mcname$ blows bubbles at you.")
      (rest  "$mcname$ blows bubbles at $hcname$.")
    )
  )
)

