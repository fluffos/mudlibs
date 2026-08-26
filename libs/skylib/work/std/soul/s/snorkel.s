(snorkel
  (pattern "[at] <indirect:any-living>")
  (pattern "<string>")
  (single
    (no-arguments
      (self "You look really cool in your snorkeling gear.")
      (rest "$mcname$ looks really cool in $mposs$ snorkeling gear.")
    )
  )
  (targeted
    (no-arguments
      (self "You put on a mask, fins, and a snorkel and swim around $hcname$ looking for fish.")
      (target "$mcname$ puts on a mask, fins, and a snorkel and swims around you looking for fish.")
      (rest "$hcname$ puts on a mask, fins, and a snorkel and swims around $hcname$ looking for fish.")
    )
  )
)
