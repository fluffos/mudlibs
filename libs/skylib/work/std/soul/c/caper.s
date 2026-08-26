(caper
  (pattern "[around] <indirect:any-living>")
  (pattern "<string>")
  (pattern "<string> [around] <indirect:any-living>")
  (pattern "[around] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You caper around madly.")
      (rest "$mcname$ capers around madly.")
    )
    (arguments
      (arguments womble with its pants on fire,chicken,jester,bimbo,
        blonde,sulam,seductress, eager person,vivacious person,madman,
        madwoman,madperson,
        frog on the run,happy chap,polite gentle person,woman,
        no we aren't sexist,merrily,fool,#)
      (self "You capers around like a $arg$.")
      (rest "$mcname$ capers around like a $arg$.")
    )
  )
  (targeted
    (no-arguments
      (self   "You caper around $hcname$ madly.")
      (target "$mcname$ capers around you madly.")
      (rest  "$mcname$ capers around $hcname$ madly.")
    )
    (arguments
      (arguments womble with its pants on fire,chicken,jester,bimbo,
        blonde,sulam,seductress, eager person,vivacious person,madman,
        madwoman,madperson,
        frog on the run,happy chap,polite gentle person,woman,
        no we aren't sexist,merrily,fool,#)
      (self   "You caper around $hcname$ like a $arg$.")
      (target "$mcname$ capers around you like a $arg$.")
      (rest  "$mcname$ capers around $hcname$ like a $arg$.")
    )
  )
)
/* Recoded by Hobbes, 970931 */
