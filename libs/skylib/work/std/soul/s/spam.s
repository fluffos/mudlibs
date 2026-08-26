(spam
  (pattern "<string>")
  (pattern "<indirect:any-living>" )
  (pattern "<indirect:any-living> <string>" )
  (pattern "[at] <indirect:any-living> <string>")
  (single
    (no-arguments
      (self "You spam away.")
      (rest "$mcname$ spams away.")
    )
    (arguments
    (arguments  the room, like Chugabolt, the boards, the talker,
                everyone, the creators, mercilessly, annoyingly,
                endlessly, forever, forever and a day, relentlessly,
                proudly, unknowingly, torturously, like a newbie, 
                like a creator)
      (self "You spam $arg$.")
      (rest "$mcname$ spams $arg$.")
    )
  )
  (targeted
  (no-arguments
    (self "You spam at $hcname$.")
    (target "$mcname$ spams at you.")
    (rest "$mcname$ spams at $hcname$.")
  )
  (arguments
    (arguments  the room, like Chugabolt, the boards, the talker,
                everyone, the creators, mercilessly, annoyingly,
                endlessly, forever, forever and a day, relentlessly,
                proudly, unknowingly, torturously, like a newbie, 
                like a creator, specifically, personally)
   (self "You spam $arg$ at $hcname$.")
   (target "$mcname$ spams $arg$ at you.")
   (rest "$mcname$ spams $arg$ at $hcname$.")
    )
  )
)
