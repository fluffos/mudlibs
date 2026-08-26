(juggle
 *((adverbs     balls,sticks,battons,cats,dogs,frogs,chickens,swords,knives,
                arms,legs,balls,trees,chain saws,bottles,torches,bings,
                tree stumps,logs,wine glasses,water,people,fire)
   (undirected
    *((mymsg    [You juggle ineptly])
      (theirmsg [$TP_NAME juggles $ADJ ineptly])))))
$$
(jump
 *((adverbs     excitedly,happily,carefully,slowly,joyfully,unsteadily,
                sideways,absentmindedly)
   (directed
    *((adverbs  ,)
      (mymsg    [You jump $ADJ up and down on $OB_NAME])
      (theirmsg [$TP_NAME jumps up and down $ADJ on $OB_NAME])))
   (undirected
    *((mymsg    [You jump up and down $ADJ])
      (theirmsg [$TP_NAME jumps up and down $ADJ])))))
$$



