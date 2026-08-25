(massage
 *((adverbs     good,bad,ugly,long,refreshing,pink,full body,seductive,
                sensuous,strange,painful,deep,meaningful,ergonomic,economic,
                painless,memorable,different,unwanted,unwarranted,
                unprovoked,unknown,sneaky,unnoticed,unwieldly,back,
                professional,unprofessional,happy,sad,trained,untrained,
                train,compact,quick,foot,leg,arm,head,
                ear,neck,shoulder,nose)
   (directed
    *((mymsg    [You give $OB_NAME a $ADJ massage])
      (theirmsg [$TP_NAME gives $OB_NAME a $ADJ massage])))))
$$
(meow
 *((noargs
  *((theirmsg   [$TP_NAME meows])
     (mymsg     [You meow])))))
$$
(moan
 *((adverbs     ,gently,deeply,sensually,agonisingly,in terror,seductively)
   (undirected
    *((mymsg    [You moan $ADJ])
      (theirmsg [$TP_NAME moans $ADJ])))))
$$
(moon
 *((directed
    *((mymsg    [You drop your pants and moon $OB_NAME])
      (theirmsg [$TP_NAME drops $TP_POSS pants and moons $OB_NAME])))))
$$
(mosh
 *((undirected
    *((adverbs  violently,angrily,carefully,thoughtfully,wonderingly,
                vigously,insanely,loudly)
      (theirmsg [$TP_NAME moshes $ADJ around the room])
      (mymsg    [You mosh $ADJ around the room])))))
$$
(mutter
 *((adverbs     #)
   (undirected
    *((theirmsg [$TP_NAME muuters $ADJ under $TP_POSS breath])
      (mymsg    [You mutter $ADJ under your breath]))))
