(faint
 *((undirected
    *((adverbs   ,tiredly,out of boredom,for the heck of it)
      (theirmsg [$TP_NAME faints $ADJ])
      (mymsg    [You faint $ADJ])))
   (directed
    *((theirmsg [$TP_NAME faints on $OB_NAME])
      (mymsg    [You faint on $OB_NAME])))))
$$
(fart
 *((noargs
    *((theirmsg [$TP_NAME farts])
      (mymsg    [You fart])))))
$$
(fiddle
 *((noargs
    *((theirmsg [$TP_NAME fiddles around])
      (mymsg    [You fiddle around])))))
$$
(flap
 *((undirected
    *((adverbs  ears,arms,wings,eyelashes)
      (theirmsg [$TP_NAME flaps $TP_POSS $ADJ])
      (mymsg    [You flap your $ADJ])))))
$$
(flex
 *((undirected
    *((adverbs  muscles,bisceps,triceps,legs,brain,nose,ears)
      (theirmsg [$TP_NAME flexs $TP_POSS $ADJ])
      (mymsg    [You flex your $ADJ])))))
$$
(flip
 *((undirected
    *((adverbs  head over heels,backwards,forwards,sideways,around,
                carefully,slowly,twice,awkwardly,disturbingly,
                digustingly,quickly,slowly,gracefully,over the moon,
                around in a really complicated double back roll flip)
      (theirmsg [$TP_NAME flips $ADJ])
      (mymsg    [You flip $ADJ])))
   (directed
    *((adverbs  head over heels,off,into the garbage bin,
                dangerously,spectacularly)
      (theirmsg [$TP_NAME flips $OB_NAME $ADJ])
      (mymsg    [You flip $OB_NAME $ADJ])))))
$$
(flop
 *((undirected
    *((adverbs  helplessly,like a fish out of water,badly,
                carefully,rudely,a bit,once,wonderfully,
                impressively,suggestively,lazily,happily,pensively)
      (theirmsg [$TP_NAME flops about $ADJ])
      (mymsg    [You flop about $ADJ])))))
$$
(flustered
 *((noargs
    *((theirmsg [$TP_NAME looks flustered])
      (mymsg    [You look flustered])))))
$$
(fondle
  *((directed
     *((theirmsg [$TP_NAME fondles $OB_NAME])
       (mymsg    [You fondle $OB_NAME])))))
$$
(foo
 *((undirected
    *((adverbs   vaguely,carefully,slowly,dangerously)
      (theirmsg  [$TP_NAME foos $ADJ])
      (mymsg     [You foo $ADJ])))))
$$
(forgive
 *((directed
    *((theirmsg  [$TP_NAME forgives $OB_NAME])
      (mymsg     [You forgive $OB_NAME])))))
$$
(french
 *((directed
    *((theirmsg  [$TP_NAME frenches $OB_NAME deeply])
      (mymsg     [You french $OB_NAME deeply])))))
$$
(froth
 *((noargs
    *((theirmsg  [$TP_NAME froths at the mouth])
      (mymsg     [You froth at the mouth])))))
$$
(frown
 *((adverbs      ,in concentration,in thought,in anger,in depression,
                 happily)
   (noargs
    *((theirmsg  [$TP_NAME frowns])
      (mymsg     [You frown])))
   (undirected
    *((theirmsg  [$TP_NAME frowns $ADJ])
      (mymsg     [You frown $ADJ])))
   (directed
    *((theirmsg  [$TP_NAME frowns $ADJ at $OB_NAME])
      (mymsg     [You frown $ADJ at $OB_NAME])))))
$$
(fume
 *((undirected
   *((adverb     quietly,insultingly,despairingly)
     (theirmsg   [$TP_NAME fumes $ADJ])
     (mymsg      [You fume $ADJ])))))
      "$mcname$ fumes $lastarg$", }) }),
$$


