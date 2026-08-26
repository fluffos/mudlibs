$$
(waltz
 *((prepositions [with])
   (directed
    *((theirmsg [$TP_NAME waltzs around the room with $OB_NAME])
      (mymsg    [You waltz around the room with $OB_NAME])))))
$$
(wave
 *((prepositions [at])
   (adverbs ,tiredly,sleepily,lazily,sadly,happily,redundantly,
            forlornly,excitedly,longingly,pointlessly,passionately)
   (noargs
    *((theirmsg [$TP_NAME waves])
      (mymsg    [You wave])))
   (undirected
    *((theirmsg [$TP_NAME waves $ADJ])
      (mymsg    [You wave $ADJ])))
   (directed
    *((theirmsg [$TP_NAME waves $ADJ to $OB_NAME])
      (mymsg    [You wave $ADJ to $OB_NAME])))))
$$
(whimper
 *((adverbs painfully,feafully,carefully,dimuatively,happily,winningly)
   (undirected
    *((theirmsg [$TP_NAME whimpers $ADJ])
      (mymsg    [You whimper $ADJ])))))
$$
(whistle
 *((prepositions [at])
   (adverbs innocently,appreciatively,loudly,musically,pleasantly,
            discordantly)
   (undirected
    *((theirmsg [$TP_NAME whistles $ADJ])
      (mymsg    [You whistle $ADJ])))
   (directed
    *((theirmsg [$TP_NAME whistles $ADJ with $OB_NAME])
      (mymsg    [You whistle $ADJ with $OB_NAME])))))
$$
(wince
 *((noargs
    *((theirmsg [$TP_NAME winces])
      (mymsg    [You wince])))))
$$
(wiggle
 *((prepositions [at])
   (adverbs ,enticingly,suggestively,vigourously,arrogantly,nonchalantly,
            quickly)
   (undirected
    *((theirmsg  [$TP_NAME wiggles $TP_POSS bottom $ADJ])
      (mymsg     [You wiggle your bottom $ADJ])))
   (directed
    *((theirmsg  [$TP_NAME wiggles $TP_POSS bottom at $OB_NAME $ADJ])
      (mymsg     [You wiggle your bottom at $OB_NAME $ADJ])))))
$$
(wink
 *((prepositions [at])
   (adverbs ,suggestively,slowly,loudly,grumpily,despairingly,coyly,
            desperately,insolently,curtly,lovingly,patiently,sadisticly,
            warily,seductively,lazily)
   (undirected 
    *((theirmsg [$TP_NAME winks $ADJ])
      (mymsg    [You wink $ADJ]))
   (directed 
    *((theirmsg [$TP_NAME winks $ADJ at $OB_NAME])
      (mymsg    [You wink $ADJ at $OB_NAME])))))
$$
(wipe
 *((prepositions [on])
   (noargs
    *((theirmsg [$TP_NAME wipes the sweat from $TP_POSS brow])
      (mysmg    [You wipe the sweat from your brow])))
   (directed
    *((adverbs hands,leg,arm,nose)
      (theirmsg [$TP_NAME wipes $TP_POSS $ADJ on $OB_NAME])
      (mymsg    [You wipe your $ADJ on $OB_NAME]))))
$$
(wobble
 *((adverbs around a bit,like jelly,unsteadily,happily,carefully,
            sideways,steadily)
   (undirected
    *((theirmsg [$TP_NAME wobbles $ADJ])
      (mymsg    [You wobble $ADJ])))))
$$
(womble
 *((adverbs #)
   (undirected
    *((theirmsg [$TP_NAME wombles around $ADJ])
      (mymsg    [You womble around $ADJ])))))
$$
(wonder
 *((adverbs #,about reality and how boring it can be)
   (undirected
    *((theirmsg [$TP_NAME wonders $ADJ])
      (mymsg    [You wonder $ADJ])))))
$$
(worship
 *((noargs
   *((theirmsg [$TP_NAME worships $TP_FOO])
      (mymsg    [You worship yourself])))
   (directed
    *((theirmsg [$TP_NAME worships $OB_NAME])
      (mymsg    [You worship $OB_NAME])))))




