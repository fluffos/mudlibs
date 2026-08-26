(dance
 *((noargs
    *((mymsg    [You sweep yourself across the dance floor])
      (theirmsg [$TP_NAME sweeps $TP_FOO across the dance floor])))
   (directed
    *((theirmsg [$TP_NAME sweeps $OB_NAME across the dance floor])
      (mymsg    [You sweep $OB_NAME across the dance floor])))))
$$
(daydream
 *((noargs
    *((theirmsg [$TP_NAME daydreams])
      (mymsg    [You daydream])))
   (undirected
    *((adverbs  #)
      (theirmsg [$TP_NAME daydreams $ADJ])
      (mymsg    [You daydream $ADJ])))))
$$
(drool
 *((noargs
    *((theirmsg [$TP_NAME messily drools all over the place])
      (mymsg    [You start to drool])))
  (directed
    *((theirmsg [$TP_NAME drools all over $OB_NAME])
      (mymsg    [You drool all over $OB_NAME])))))
$$
(duh
 *((noargs
    *((theirmsg [$TP_NAME duhs])
      (mymsg    [You duh])))))
$$





