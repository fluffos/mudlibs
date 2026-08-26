(fonz
  (pattern "<indirect:any-living>")
  (single
    (no-arguments
      (self "You stick both thumbs in the air and say: Ayyyyyyyy...")
      (rest "$mcname$ sticks both thumbs in the air and says: Ayyyyyyyy...")
    )
  )
  (targeted
    (no-arguments
      (self   "You tug on your jacket, and point at $hcname$ with both hands.")
      (target "$mcname$ tugs on $mposs$ jacket, and points at you with both hands.")
      (rest  "$mcname$ tugs on $mposs$ jacket, and points at $hcname$ with both hands.")
    )
  )
)

/* Implemented by Hobbes 960920. Ideas from Grampa and Presto. */

