(ack
 *((undirected
    *((theirmsg [$TP_NAME acks])
      (mymsg    [You ack])))))
$$
(accuse
 *((prepositions [of])
   (adverbs #)
   (noargs
    *((theirmsg [$TP_NAME looks around the room accusingly])
      (mymsg    [You look around the room accusingly])))
   (undirected
    *((theirmsg [$TP_NAME accuses $ADJ])
      (mymsg    [You accuse $ADJ])))
   (directed
    *((theirmsg [$TP_NAME accuses $OB_NAME of $ADJ])
      (mymsg    [You accuse $OB_NAME of $ADJ])))))
$$
(apologize
 *((prepositions [to])
   (adverbs profusely,happily,sadly,reservedly,carefully,slowly,perfunctorily,
	    curtly,visciously,sulkily,drunkenly,unhappily,professionally,
	    pompously,wholeheartedly,partially,wearily,fishily,facetiously,
	    unnecessarily,spontaneously,twice,thoroughly,humbly)
   (undirected
    *((theirmsg [$TP_NAME apologizes $ADJ])
      (mymsg    [You apologize $ADJ])))
   (directed
    *((theirmsg [$TP_NAME apologizes $ADJ to $OB_NAME])
      (mymsg    [You apologize $ADJ to $OB_NAME])))))
$$
(applaud
 *((adverbs wholeheartedly,loudly,softly,vaguely,briefly)
   (undirected
    *((theirmsg [$TP_NAME applauds $ADJ])
      (mymsg    [You applaud $ADJ])))
   (directed
    *((theirmsg [$TP_NAME applauds $OB_NAME $ADJ])
      (mymsg    [You applaud $OB_NAME $ADJ])))))
$$
(agree
 *((noargs
    *((theirmsg [$TP_NAME agrees wholeheartedly])
      (mymsg    [You agree wholeheartedly])))
   (directed
    *((theirmsg [$TP_NAME agrees with $OB_NAME wholeheartedly])
      (mymsg    [You agree with $OB_NAME wholeheartedly])))))
$$
(assimilate
 *((adverbs cheerfully,reluctantly)
   (undirected
    *((theirmsg [$TP_NAME assimilates species $ADJ like a Borg])
      (mymsg    [You assimilate species $ADJ like a Borg])))
   (directed           
    *((theirmsg [$TP_NAME assimilates $OB_NAME $ADJ])
      (mymsg    [You assimilate $OB_NAME $ADJ])))))

