/*                                                                  *
 *  Langbeschreibungen und Details der gewoehnlichen Walrdraeume.   *
 *                                                                  *
 *   Feyaria, April 2001                                            *
 *                                                                  */


// Short-Descriptions

#define DET_SHORT \
([ 1:"Mitten im Wald.",\
   2:"Im Wald.",\
   3:"Der Wald.",\
   4:"Zwischen Baeumen, Baeumen, Baeumen.",\
   5:"Ein Raum im Wald.",\
   6:"In einem riesigen Wald."])


// Long-Descriptions

#define DET_LANG1 \
([ 1:"Du befindest Dich in einem scheinbar endlos grossem Wald. ";\
     ({"wald"}),\
   2:"Vorsichtig schleichst Du weiter durch den Wald. ";\
     ({"wald"}),\
   3:"Der Wald ist hier ein wenig dichter als sonst. ";\
     ({"wald"}),\
   4:"Du stehst mitten im riesigen Wald. ";\
     ({"wald"}),\
   5:"Du tastest Dich vorsichtig weiter durchs Unterholz. ";\
     ({"unterholz","wald"})])

#define DET_LANG2 \
([ 1:"Ringsherum wachsen viele Baeume, Straeucher und sonstige Pflanzen. ";\
     ({"baeume","straeucher","pflanzen"}),\
   2:"Alles um Dich herum ist gruen und die Flora waechst und gedeiht. ";\
     ({"flora"}),\
   3:"In diesem Bereich des Waldes wachsen hauptsaechlich Nadelbaeume, aber nicht ausschliesslich. ";\
     ({"nadelbaeume","bereich"}),\
   4:"Zwischen den Laubbaeumen wachsen auch einige Nadelbaeume. ";\
     ({"laubbaeume","nadelbaeume"}),\
   5:"Hier ist der Baumbestand nicht mehr so dicht, sodass auch mehr Licht auf die hier wachsenden Buesche einfaellt. ";\
     ({"baumbestand","licht","buesche"})])

#define DET_LANG3 \
([ 1:"Am Boden wuseln lauter kleine Ameisen und andere Insekten herum. ";\
     ({"boden","ameisen","insekten"}),\
   2:"Irgendein Tier hat hier Spuren im Boden hinterlassen. ";\
     ({"tier","boden","spuren"}),\
   3:"Du watest in knoecheltiefem Laub und abgestorbenen Nadeln. ";\
     ({"laub","boden","nadeln"}),\
   4:"Pass auf, dass Du nicht ueber eine der vielen Wurzeln am Boden stolperst! ";\
     ({"boden","wurzeln"}),\
   5:"Der Boden unter Dir besteht aus typischer Walderde. ";\
     ({"boden","erde","walderde"})])

#define DET_LANG4 \
([ 1:"Vereinzelt sieht man hier auch wunderschoene Blumen. ";\
     ({"blumen"}),\
   2:"Wenn Du ein Pilzesammler waerest, wuerdest Du Dich hier wie im Paradies fuehlen, so viele Pilze gibt es hier. ";\
     ({"pilze","paradies","pilzesammler"}),\
   3:"Huch? Ein Vogel fliegt ploetzlich haarscharf an Dir vorbei und landet auf einem Ast. ";\
     ({"vogel","ast"}),\
   4:"An einem der Baeume vor Dir haengen lauter dicke Lianen herab. ";\
     ({"baeume","lianen"}),\
   5:"Auf einigen der Straeucher um Dich herum waechst etwas. ";\
     ({"strauch","straeucher"})])

#define DET_LANG5 \
([ 1:"Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach. ";\
     ({"lichtstrahlen","blaetterdach","dach","licht", "strahlen"}),\
   2:"Das Blaetterdach ist hier so dicht, dass es ziemlich duester ist. ";\
     ({"dach","blaetterdach"}),\
   3:"Nur wenig Licht dringt durch das Blaetterdach auf den Boden. ";\
     ({"licht","blaetterdach","boden"}),\
   4:"Die wenigen Lichtstrahlen, die das Blaetterdach durchdringen, zaubern ein lustiges Muster auf dem Boden. ";\
     ({"lichtstrahlen","blaetterdach","dach","licht","strahlen","muster","boden"}),\
   5:"Es ist sehr duester hier, nur wenig Licht dringt durch das Blaetterdach bis zum Boden durch. ";\
     ({"licht","blaetterdach","dach","boden"})])

#define DET_LANG6 \
([ 1:"Ein grosser, stark mit Gestruepp ueberwucherter Felsblock liegt zwischen den Baeumen. ";\
     ({"gestruepp","felsblock","baeume"}),\
   2:"Ein kleines Baechlein fliesst hier durch den Wald. ";\
     ({"baechlein","wald","bach"}),\
   3:"Zwischen den Baeumen wachsen einige kleine Buesche. ";\
     ({"buesche","baeume"}),\
   4:"Am Boden entdeckst Du ein kleines Erdloch. ";\
     ({"erdloch","loch"}),\
   5:"Auf einem der Baeume bemerkst Du ein kleines Vogelnest. ";\
     ({"vogelnest","nest"}),\
   6:"Eine grosse Eiche faellt Dir auf. ";\
     ({"eiche"}),\
   7:"Der Wald macht hier einen ganz besonders friedlichen Eindruck. ";\
     ({"eindruck", "wald"}),\
   8:"Dieser Wald ist wirklich so gross, dass man sich total verirren kann. ";\
     ({"wald"}),\
   9:"Ein Augenpaar beobachete Dich aus einem Busch. ";\
     ({"augenpaar", "busch"}),\
  10:"Nun hast Du total die Orientierung verloren und und hast Dich im Wald verirrt. ";\
     ({"orientierung", "wald"}),\
  11:"Hinter Dir knackt es im Unterholz. ";\
     ({"unterholz"}),\
  12:"Du hoerst ein Rascheln im Gebuesch. ";\
     ({"gebuesch"}),\
  13:"Dies ist wirklich der schoenste Wald in dem Du je warst. ";\
     ({"wald"}),\
  14:"Ein kleines Tier springt vor Dir aus den Bueschen und verschwindet sofort wieder im Unterholz. ";\
     ({"tier", "buesche", "unterholz"}),\
     ])

#define DET_ALL1 ([ \
  "wald":3;\
    ({"Du befindest Dich mitten im Wald.",({"wald"}),\
    "Du siehst den Wald vor lauter Baeumen nicht.",({"baeume"}),\
    "Rund um Dich ist nur Wald.",({"wald"}),}),\
  "unterholz":3;\
    ({"Das Unterholz ist sehr dicht hier.",({"holz"}),\
    "Du bahnst Dir einen Weg durch das Unterholz.",({"weg","holz"}),\
    "Auf einem Baum ist 'Unterholz acht' eingraviert.",({"baum", "unterholz 8", "unterholz acht"}),}),\
  "baeume":3;\
    ({"Es wachsen viele Baeume in diesem Wald.",({"wald"}),\
    "Viele Baeume wachsen in diesem Wald.",({"wald"}),\
    "Der Wald ist voller Baeume.",({"wald"}),}),\
  "straeucher":3;\
    ({"Zwischen den Baeumen wachsen viele Straeucher:",({"baeume"}),\
    "Einige Straeucher wachsen zwischen den Baeumen.",({"baeume"}),\
    "Es wachsen hier nicht nur Baeume, sondern auch Straeucher.",({"baeume"}),}),\
  "pflanzen":3;\
    ({"Viele verschiedene Pflanzen wachsen im Wald: Baeume, Straeucher, ...",({"wald", "baeume", "straeucher"}),\
    "Baueme und Straeucher zum Beispiel.",({"baeume", "straeucher"}),\
    "Der Wald besteht aud Pflanzen und Tieren",({"wald", "tiere"}),}),\
  "flora":3;\
    ({"Die Flora des Waldes besteht hauptsaechlich aus Baeumen und Straeuchern.",({"wald", "baeume", "straeucher"}),\
    "Flora ist ein anderer Begriff fuer Pflanzen",({"begriff", "pflanzen"}),\
    "Mit Flora sind wohl die Baeume und Straeucher gemeint.",({"baeume", "straeucher"}),}),\
  "bereich":3;\
    ({"Mit Bereich ist die naehere Umgebung gemeint.",({"umgebung"}),\
    "Dieser Bereich des Waldes eben.",({"wald"}),\
    "Damit ist der Teil des Waldes gemeint, den Du jetzt sehen kannst.",({"teil", "wald"}),}),\
  "umgebung":1;\
    ({"Die Umgebung besteht aus Wald.", ({"wald"}),}),\
   ])

#define DET_ALL2 ([ \
  "nadelbaeume":3;\
    ({"Es wachsen viele verschiedene Nadelbaeume im Wald.",({"wald"}),\
    "Nadelbaeume sind Baeume mit Nadeln.",({"baeume", "nadeln"}),\
    "Der Wald besteht hier zu einem grossen Teil aus Nadelbaeumen.",({"wald", "teil"}),}),\
  "laubbaeume":3;\
    ({"Es wachsen viele verschiedene Laubbaeume im Wald.",({"wald"}),\
    "Laubbaeume sind Baeume mit Laub, auch Blaetter genannt.",({"laub", "blaetter"}),\
    "Der Wald besteht hier zu einem grossen Teil aus Laubbaeumen.",({"wald","teil"}),}),\
  "baumbestand":3;\
    ({"Der Baumbestand hier ist nicht mehr so dicht, sodass auch mehr Licht auf die hier wachsenden Buesche faellt.",({"licht", "buesche"}),\
    "Der Wald besteht hier aus Laubbaeumen und Nadelbaeumen.", ({"wald", "laubbaueme", "nadelbaeume"}),\
    "Der Baumbestand ist hier nicht mehr ganz so dicht wie an anderen Stellen im Wald.", ({"stellen", "wald"}),}),\
  "buesche":3;\
    ({"Zwischen den Baeumen befinden sich hier einige Buesche.", ({"baeume"}),\
    "Zwischen den Baeumen befinden sich hier einige Buesche.", ({"baeume"}),\
    "Zwischen den Baeumen befinden sich hier einige Buesche.", ({"baeume"}),}),\
  ])

#define DET_ALL3 ([ \
  "boden":1;\
    ({"Unter Dir ist der Boden, so wie du es in einem Wald erwartest.", ({"wald"}),\
    "Unter Dir ist der Boden, so wie du es in einem Wald erwartest.", ({"wald"}),\
    "Unter Dir ist der Boden, so wie du es in einem Wald erwartest.", ({"wald"}),}),\
  "ameisen":1;\
    ({"Am Boden wuseln lauter kleine Ameisen herum.", ({"boden"}),\
    "Am Boden wuseln lauter kleine Ameisen herum.", ({"boden"}),\
    "Am Boden wuseln lauter kleine Ameisen herum.", ({"boden"}),}),\
  "insekten":1;\
    ({"Am Boden wuseln lauter kleine Insekten herum.", ({"boden"}),\
    "Am Boden wuseln lauter kleine Insekten herum.", ({"boden"}),\
    "Am Boden wuseln lauter kleine Insekten herum.", ({"boden"}),}),\
  "tier":1;\
    ({"Irgend ein Tier hat hier Spuren im Boden hinterlassen.", ({"boden", "spuren"}),\
    "Irgend ein Tier hat hier Spuren im Boden hinterlassen.", ({"boden", "spuren"}),\
    "Irgend ein Tier hat hier Spuren im Boden hinterlassen.", ({"boden", "spuren"}),}),\
  "nadeln":1;\
    ({"Die Nadeln befinden sich nicht nur auf den Nadelbaeumen sondern auch am Boden.", ({"boden", "nadelbaeume"}),\
    "Die Nadeln befinden sich nicht nur auf den Nadelbaeumen sondern auch am Boden.", ({"boden", "nadelbaeume"}),\
    "Die Nadeln befinden sich nicht nur auf den Nadelbaeumen sondern auch am Boden.", ({"boden", "nadelbaeume"}),}),\
  "laub":1;\
    ({"Die Laubbaeume hier haben zum Teil ihr Laub abgeworfen, sodass einiges davon am Boden herumliegt.", ({"boden", "laubbaeume"}),\
    "Die Laubbaeume hier haben zum Teil ihr Laub abgeworfen, sodass einiges davon am Boden herumliegt.", ({"boden", "laubbaeume"}),\
    "Die Laubbaeume hier haben zum Teil ihr Laub abgeworfen, sodass einiges davon am Boden herumliegt.", ({"boden", "laubbaeume"}),}),\
  "wurzeln":1;\
    ({"Die Wurzeln einiger Baeume schauen hier aus dem Boden heraus.",({"baeume", "boden"}),\
    "Die Wurzeln einiger Baeume schauen hier aus dem Boden heraus.",({"baeume", "boden"}),}),\
  "erde":1;\
    ({"Bei der Erde hier handelt es sich um dunkle Walderde, die besonders fruchtbar ist.", ({"walderde"}),\
    "Bei der Erde hier handelt es sich um dunkle Walderde, die besonders fruchtbar ist.", ({"walderde"}),}),\
  "walderde":1;\
    ({"Die Walderde ist dunkel und sehr fruchtbar.",({"erde"}),\
    "Die Walderde ist dunkel und sehr fruchtbar.",({"erde"}),}),\
  ])

#define DET_ALL4 ([ \
  "spuren":1;\
    ({"Du betrachtest die Spuren hier naeher, kannst aber nicht erkennen, zu welchem Tier sie gehoeren.", ({"tier"}),\
    "Du betrachtest die Spuren hier naeher, kannst aber nicht erkennen, zu welchem Tier sie gehoeren.", ({"tier"}),}),\
  ])

#define DET_ALL5 ([ \
  "licht":1;\
    ({"Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"lichtstrahlen", "strahlen", "blaetterdach"}),\
    "Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"lichtstrahlen", "strahlen", "blaetterdach"}),}),\
  "lichtstrahlen":1;\
    ({"Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"licht", "strahlen", "blaetterdach"}),\
    "Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"licht", "strahlen", "blaetterdach"}),}),\
  "strahlen":1;\
    ({"Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"licht", "lichtstrahlen", "blaetterdach"}),\
    "Vereinzelt dringen Lichtstrahlen durch das dichte Blaetterdach.", ({"licht", "lichtstrahlen", "blaetterdach"}),}),\
  "blaetterdach":2;\
    ({"Das Blaetterdach ist hier sehr dicht, nur vereinzelte Lichtstrahlen dringen bis zum Boden durch.", ({"boden", "licht", "lichtstrahlen", "strahlen", "dach"}),\
    "Das Blaetterdach ist hier sehr dicht, nur vereinzelte Lichtstrahlen dringen bis zum Boden durch.", ({"boden", "licht", "lichtstrahlen", "strahlen", "dach"}),}),\
  "dach":2;\
    ({"Du meinst wohl das Blaetterdach?", ({"blaetterdach"}),\
    "Du meinst wohl das Blaetterdach?", ({"blaetterdach"}),}),\
  "muster":2;\
    ({"Die Lichtstrahlen zaubern lustige Muster auf den Waldboden.", ({"waldboden", "lichstrahlen", "strahlen", "licht"}),\
    "Die Lichtstrahlen zaubern lustige Muster auf den Waldboden.", ({"waldboden", "lichstrahlen", "strahlen", "licht"}),}),\
  ])

#define DET_ALL6 ([ \
  ])

#define DET_ALL7 ([ \
  ])
