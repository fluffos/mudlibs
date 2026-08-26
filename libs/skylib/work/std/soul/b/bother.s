(bother
  (pattern "<indirect:any-living>")
  (pattern "<string> <indirect:any-living>")
  (pattern "<indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You mutter 'Oh bother!'")
      (rest "$mcname$ mutters 'Oh bother!'.")
     )
  )
  (targeted
    (no-arguments
      (self   "You bother $hcname$.")
      (target "$mcname$ bothers you.")
      (rest  "$mcname$ bothers $hcname$.")
    )
    (arguments
     (arguments about work,about the time,about not doing any qc work,
                about life,about being bored, about finishing a project,
                about what to do,with a pointed stick,by singing badly,
                with sadistic glee,with paperwork)
      (self "You bother $hcname$ $arg$.")
      (target "$mcname$ bothers you $arg$.")
      (rest "$mcname$ bothers $hcname$ $arg$.")
    )
  )
)
