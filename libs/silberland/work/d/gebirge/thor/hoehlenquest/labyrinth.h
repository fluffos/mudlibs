// Thor@SilberLand
// 1997-05-03
// Raumbeschreibungen des Labyrinths, die mit den dazugehoerigen Details 
// randommaessig zusammengewuerfelt werden.
// (Nach dem Prinzip von Angrox' Steinwald /d/gebirge/angrox/4elem/wald.h)


#define LANG_1\
([1:"Du kannst nicht allzuviel erkennen in der Dunkelheit. ",\
2:"Die Finsternis in diesen Hoehlengaengen ist beinahe erdrueckend. ",\
3:"Deine Fackel leuchtet nur wenige Meter weit, daher erkennst Du nur wenig "\
 +"in Deiner Umgebung. ",\
4:"Die Dunkelheit verschluckt einen Grossteil des Lichtes von Deiner Fackel, "\
 +"sodass Du nur wenig erkennen kannst. ",\
5:"Der schwarze Fels verschluckt das Licht Deiner Fackel und Du kannst daher "\
 +"nur Deine naechste Umgebung erkennen. "])

#define LANG_2\
([1:"Die Waende des Hoehlengangs sind pechschwarz gefaerbt. ",\
2:"In den Hoehlenwaenden sind einige Loecher, aus denen kleinere Felsbrocken "\
 +"herausgebrochen sind. ",\
3:"In den Waenden siehst Du einige Loecher, die etwa faustgross sind und tief "\
 +"in den Fels hineinzureichen scheinen. ",\
4:"Der Fels der Hoehlenwaende ist schwarz gefaerbt. ",\
5:"Obwohl manchmal ein wenig Gestein aus den Waenden herausgebrochen ist, "\
 +"scheint es doch sehr hart zu sein. "])

#define LANG_3\
([1:"Der Boden ist felsig und glatt. ",\
2:"Der Fels am Boden sieht aus, als sei er glatt poliert. ",\
3:"Am Boden liegen einige Felsbrocken herum. ",\
4:"Links und rechts siehst Du am Boden einige bleiche Knochen herumliegen. ",\
5:"Der Boden unter Deinen Fuessen scheint glatt poliert zu sein. "])

#define LANG_4\
([1:"Dir scheint, als koennte man sich in diesen Gaengen leicht verirren. ",\
2:"Irgendwie hast Du das Gefuehl, Dich verlaufen zu haben. ",\
3:"Dir scheint, als haettest Du Dich verirrt. ",\
4:"Du bist vielleicht doch etwas zu ueberstuerzt losgegangen, denn Du hast "\
 +"nun vollkommen die Orientierung verloren. ",\
5:"Du blickst etwas verwirrt um Dich und bist etwas unschluessig, in welche "\
 +"Richtung Du weitergehen sollst. "])
#define LANG_5\
([1:"Am Fusse der Wand siehst Du einen Totenkopf liegen, der Dich starr "\
   +"angrinst. ",\
2:"Von der Decke haengen einige Zacken herunter, die, wie es schient, "\
 +"jederzeit herunterbrechen koennen. ",\
3:"Aus einem Loch in der Wand haengt ein toter Hoehlenwurm heraus, der "\
 +"erbaermlich stinkt. ",\
4:"Links am Boden liegt das Skelett eines Zwerges mit einem etwas groesserem "\
 +"Steinbrocken am Brustkorb, der diesen zermalmt hat. ",\
5:"Du beginnst zu ueberlegen, was Du hier eigentlich zu suchen hast. "])

#define D_DUNKEL\
([1:"Die Dunkelheit ist beinahe erdrueckend. ",\
  2:"Der schwarze Fels macht die Finsternis hier noch schlimmer. ",\
  3:"Du kannst in der Dunkelheit hier nur wenig erkennen. "])

#define D_GAENGE\
([1:"Die Hoehlengaenge sind eng und niedrig. ",\
  2:"Die Hoehlengaenge bestehen aus schwarzem Fels. ",\
  3:"In den Hoehlengaengen ist es stockfinster. "])

#define D_FACKEL\
([1:"Das Licht Deiner Fackel wird von dem schwarzen Fels verschluckt. Du "\
   +"kannst daher nur wenig erkennen. ",\
  2:"Deine Fackel leuchtet in dieser totalen Finsternis nur wenige Meter "\
   +"weit. ",\
  3:"Du hoffst, dass Du genuegend Fackeln dabei hast, denn Du faendest es "\
   +"schrecklich, ohne Licht in dieser Finsternis festzusitzen. "])

#define D_FELS\
([1:"Der Fels ist pechschwarz gefaerbt. ",\
  2:"Das Gestein hat eine tiefschwarze Farbe. ",\
  3:"Der schwarze Fels um Dich herum verschluckt das meiste Licht Deiner "\
   +"Fackel. "])

#define D_UMGEBUNG\
([1:"Du kannst nur sehr wenig von Deiner Umgebung erkennen. ",\
  2:"Die Finsternis laesst Dich nur einige Meter weit sehen. ",\
  3:"Du kannst wegen des schwachen Lichtes deiner Fackel nur Deine naechste "\
   +"Umgebung erkennen. "])

#define D_WAENDE\
([1:"Die Waende bestehen aus schwarzem Fels. ",\
  2:"Das Gestein an den Waenden ist schwarz gefaerbt. ",\
  3:"In den Waenden sind einige tiefere Loecher. "])

#define D_LOECHER\
([1:"In den Waenden sind einige tiefe Loecher zu erkennen. ",\
  2:"Die Loecher in den Waenden scheinen tief in den Fels hineinzufuehren. ",\
  3:"In den Loechern scheinen sich die Hoehlenwuermer zu verkriechen. "])

#define D_BROCKEN\
([1:"Einige kleinere Felsbrocken sind aus den Waenden herausgebrochen. ",\
  2:"Am Boden liegen einige Felsbrocken herum, die aus den Waenden "\
   +"herausgebrochen sind. ",\
  3:"Am Boden siehst Du einige Felsbrocken liegen. "])

#define D_BODEN\
([1:"Am Boden siehst Du einige Felsbrocken herumliegen. ",\
  2:"Einige bleiche Knochen liegen am Boden. ",\
  3:"Der Boden besteht aus schwarzem, glatten Fels. "])

#define D_KNOCHEN\
([1:"Links und rechts von Dir liegen einige bleiche Knochen. ",\
  2:"Hier scheinen schon einige Abenteurer zu Grunde gegangen zu sein. ",\
  3:"Du erkennst die kleinen, dicken Knochen von Zwergen und die etwas "\
   +"laengeren von Menschen. "])

#define D_FUESSE\
([1:"Der Boden unter Deinen Fuessen ist ganz glatt. ",\
  2:"Der Boden unter Deinen Fuessen scheint glatt poliert zu sein. ",\
  3:"Deine Fuessen stehen auf ganz glattem Boden. "])

#define D_GEFUEHL\
([1:"Du hast ein sonderbares Gefuehl im Bauch, dass Du Dich verlaufen hast. ",\
  2:"Dich ueberkommt ein Gefuehl der Orientierungslosigkeit. ",\
  3:"Dir scheint, als haettest Du Dich verlaufen. "])

#define D_TOTENKOPF\
([1:"Ein Totenkopf liegt am Boden, der Dich starr angrinst. ",\
  2:"Es scheint der Totenkopf eines Zwerges zu sein. ",\
  3:"Hier scheinen schon einige Wesen ihren Tod gefunden zu haben. "])

#define D_ZACKEN\
([1:"Die Zacken an der Decke sehen nicht sehr stabil aus. ",\
  2:"Es scheint, als koennten die Zacken an der Decke jeden Moment "\
    +"herunterbrechen. ",\
  3:"Die Zacken an der Decke sehen nicht sehr vertrauenswuerdig aus. "])

#define D_SKELETT\
([1:"Das muss weh getan haben. ",\
  2:"Der arme Zwerg. ",\
  3:"Ob Du auch ein Opfer der Hoehle wirst? "])

#define D_ZWERG\
([1:"Es scheinen hier schon einige Zwerge ihren Tod gefunden zu haben. ",\
  2:"Der arme Zwerg. ",\
  3:"Hoffentlich ergeht es Dir nicht genauso. "])

#define D_BRUSTKORB\
([1:"Der Brustkorb des Zwerges sieht reichlich zermalmt aus. ",\
  2:"Das hat warscheinlich ziemlich weh getan. ",\
  3:"Du bekommst etwas weiche Beine, wenn Du den zerquetschen Zwerg so "\
   +"betrachtest. "])

#define D_WURM\
([1:"Ein toter Hoehlenwurm haengt aus einem Loch heraus. ",\
  2:"Der Hoehlenwurm an der Wand stinkt ganz fuerchterlich. ",\
  3:"Du fasst ihn besser nicht an. "])





