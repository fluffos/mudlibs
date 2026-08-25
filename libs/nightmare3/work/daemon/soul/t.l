(tackle
 *((noargs
    *((theirmsg [$TP_NAME tackles $TP_FOO to the ground])
      (mymsg    [You tackle yourself to the ground])))
   (directed
    *((theirmsg [$TP_NAME tackles $OB_NAME to the ground])
     (mymsg    [You tackle $OB_NAME to the ground])))))
$$
(tap
 *((prepositions [on the])
   (adverbs foot,head,left leg,right leg,fingers,nose,shoulder,teeth,arm)
   (undirected
    *((theirmsg [$TP_NAME taps $TP_POSS $ADJ impatiently])
      (mymsg    [You tap your $ADJ impatiently])))
   (directed
    *((theirmsg [$TP_NAME taps $OB_NAME on the $ADJ])
      (mymsg    [You tap $OB_NAME on the $ADJ])))))
$$
(taunt
 *((noargs
    *((theirmsg [$TP_NAME taunts $TP_FOO])
      (mymsg    [You taunt yourself])))
   (directed
    *((theirmsg [$TP_NAME taunts $OB_NAME])
      (mymsg    [You taunt $OB_NAME])))))
$$
(tease
 *((noargs
    *((theirmsg [$TP_NAME teases $TP_FOO])
      (mymsg    [You tease yourself])))
   (directed
    *((adverbs  mercilessly,insistantly,annoyingly,lovingly,mischeviously,
                rudely,carefully,quickly,slowly,halfheartedly,idlely,
                obnoxiously)
      (theirmsg [$TP_NAME teases $OB_NAME $ADJ])
      (mymsg    [You tease $OB_NAME $ADJ])))))
$$
(thank
 *((adverbs profusely,gratuitously,lots,slightly,reservedly)
   (directed
    *((theirmsg [$TP_NAME thanks $OB_NAME $ADJ])
      (mymsg    [You thank $OB_NAME $ADJ])))))
$$
(think
 *((adverbs #)
   (noargs
    *((theirmsg [$TP_NAME thinks carefully])
      (mymsg    [You think carefully])))
   (undirected
    *((theirmsg [$TP_NAME thinks $ADJ])
      (mymsg    [You think $ADJ])))))
$$
(tip
 *((prepositions [at to])
   (adverbs happily,pathetically,hopefully)
   (undirected
    *((theirmsg [$TP_NAME tips $TP_POSS hat $ADJ])
      (mymsg [You tip your hat $ADJ])))
   (directed
    *((theirmsg [$TP_NAME tips $TP_POSS hat $ADJ to $OB_NAME])
     (mymsg [You tip your hat $ADJ to $OB_NAME])))))
$$
(tickle
 *((adverbs ,mercilessly,ruthlessly,fearlessly,quickly,sneakily,weakly,
            carefully,gently,harshly,inconcievablely,slowly)
   (directed
    *((theirmsg [$TP_NAME tickles $OB_NAME $ADJ])
      (mymsg    [You tickle $OB_NAME $ADJ])))))
$$
(tongue
 *((directed
    *((theirmsg [$TP_NAME sticks $TP_POSS tongue out at $OB_NAME])
      (mymsg    [You stick your tongue out at $OB_NAME])))))
$$
(tremble
 *((adverbs in fear,in nervousness,in pain,slightly,violently,insistantly,
            carefully,in a pink fit)
   (undirected
    *((theirmsg  [$TP_NAME trembles $ADJ])
      (mymsg     [You tremble $ADJ])))))
$$
(trip
 *((noargs
    *((theirmsg [$TP_NAME trips over $TP_FOO])
      (mymsg    [You trip over yourself]))
   (directed 
    *((theirmsg [$TP_NAME trips over $OB_NAME])
      (mymsg    [You trip over $OB_NAME])))))
$$
(tsk
  *((noargs
   *((theirmsg   [$TP_NAME makes tsking motions])
     (mymsg      [You make tsking motions])))
   (directed  
    *((theirmsg  [$TP_NAME makes tsking motions at $OB_NAME])
      (mymsg     [You make tsking motions at $OB_NAME])))))
$$
(tweak
 *((adverbs  bottom,ear,arm,leg,nose,bits)
   (directed
    *((theirmsg [$TP_NAME tweaks $OB_NAME $ADJ])
      (mymsg    [You tweak $OB_NAME $ADJ])))))
$$
(twiddle
 *((adverbs thumbs,fingers,hair,nose)
   (undirected
    *((theirmsg [$TP_NAME twiddles $TP_POSS $ADJ])
      (mymsg    [You twiddle your $ADJ])))))
$$
(twitch
 *((adverbs nose,arm,body,finger,igloo)
   (undirected
    *((theirmsg [$TP_NAME twitches $TP_POSS $ADJ])
      (mymsg    [You twitch your $ADJ])))))
