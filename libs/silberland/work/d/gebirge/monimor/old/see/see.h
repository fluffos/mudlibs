//  Standard-Details:   STAND1&2
//  Standard-Befehle:   COMMS
//  Im See:             SWIM_DETAILS

#define STAND1	\
AddDetail("boden",bs("Der Boden ist aus Fels. Du kannst keine "	\
           "Steine am Boden erkennen."));	\
AddDetail("himmel",bs("Der Himmel ist in strahlendem Blau zu erkennen."));	\
AddDetail("blau",bs("Der Himmel erstrahlt im schoensten Blau. Nur "	\
           "manchmal truebt eine Wolke den Glanz."));	\
AddDetail(({"wolke","wolken"}),bs("Die Wolken wandern langsam ueber "	\
           "das Himmelszelt. Eine schiebt sich langsam vor die Sonne."));	\
AddDetail("sonne",bs("Die Sonne ist teilweise von einer Wolke verdeckt. "	\
           "Trotzdem blendet Dich ihr Licht."));	\
AddDetail("licht",bs("Das Licht der Sonne blendet Dich. Du hast erst "	\
           "selten ein derart helles Licht gesehen, das, obwohl Du "	\
           "in diesem Gebirgskessel bist."));	\
AddDetail(({"kessel","gebirgskessel"}),bs("Der Gebirgskessel fasst den "	\
           "See in sich. Obwohl die Waende ziemlich steil empor ragen, "	\
           "ist der Kessel total hell erleuchtet."));	\
AddDetail(({"wand","waende","felswand","felswaende"}),bs("Die Waende "	\
           "sind aus dem selben Fels wie auch der Rest der Klamm der "	\
           "der Seelen. Du kannst keine Unebenheiten an den Waenden "	\
           "erkennen."));	\
AddDetail("fels",bs("Der Fels ist total glatt. Er erscheint nur dunkel.")); \
AddDetail("klamm",bs("Der See befindet sich in der Klamm der Seelen."));	\
AddDetail("see",bs("Das ist der See des Ruesselwurms. Er befindet sich "	\
           "in der Klamm der Seelen. Du kannst die Wellen ans Ufer "	\
           "schlagen hoeren. Wenn Du im See etwas finden solltest, lass es liegen. Im See hortet der Drache seine Beute!"));	\
AddDetail(({"welle","wellen"}),bs("Das sanfte Rauschen der Wellen wird "	\
           "dadurch unterbrochen, wenn sie ans Ufer schlagen. Sie "	\
           "sind nicht besonders hoch. Nicht einmal ein Zwerg wuerde "	\
           "auf ihnen reiten koennen."));	\
AddDetail("ufer",bs("Das Ufer ist felsig. Manchmal schlagen Wellen gegen "	\
           "das Ufer und hinterlassen einen feuchten Schatten auf "	\
           "dem Fels."));	\
AddDetail("schatten",bs("Die Schatten verdunsten sofort wieder und ziehen " \
           "sich gegen das Ufer zu zurueck, fast als ob sie wieder in "	\
           "den See zurueck schlichen."));	\
AddDetail("glanz",bs("Der Himmel glaenzt wie kostbare Edelsteine."));	\
AddDetail(({"edelstein","edelsteine"}),bs("Der Glanz des Himmels erinnert " \
           "Dich an den von tuerkis-blauen schimmernden Edelsteinen."));	\
AddDetail(({"unebenheit","unebenheiten"}),bs("Der Fels ist spiegelglatt. "  \
           "Du kannst keine Unebenheiten erkennen."));	\
AddDetail(({"wurm","ruesselwurm"}),bs("Der Wurm ist nicht hier. "	\
           "Nun faellt Dir auch auf, dass hier wirklich keine Unebenheiten "\
           "an den Waenden sind. Offenbar ist bisher noch niemand "	\
           "so weit in den Gebirgskessel vorgedrungen, denn sonst waeren "	\
           "hier vermutlich Spuren eines Kampfes vorzufinden. Vielleicht "	\
           "gibt es aber auch einen Weg, wo man dem Wurm nicht begegnet "	\
           "und so unbemerkt an ihm vorbeikommt."));
           
#define STAND2	\
AddDetail("weg",bs("Der Weg fuehrt zwischen den Waenden des Kessels und "	\
           "dem Ufer des Sees entlang."));	\
AddDetail(({"spur","spuren","kampf"}),bs("Ein Kampf haette vermutlich "	\
           "Spuren hinterlassen, die sich in zerkratzten Waenden aeussern "	\
           "wuerden."));	\
AddDetail(({"luft","luftfeuchtigkeit","feuchtigkeit"}),bs("Die Luft ist "	\
           "sehr feucht. "	\
           "Die drueckende Luftfeuchtigkeit bringt Dich fast zum "	\
           "Schwitzen."));	\
AddDetail(({"schweiss","schwitzen"}),"Du transpirierst.\n");	\
AddSmell(DEFAULT_SMELL,"Du bemerkst, dass die Luft sehr feucht ist.\n");	\
AddSmell("luft","Die Luft ist sehr feucht.\n");	\
AddSmell(({"schweiss","schwitzen"}),"Dein Schweiss riecht salzig.\n");	\
AddDetail("wasser","Im See leben ausser dem Ruesselwurm keine " \
  +"Lebewesen. Das Wasser kann nicht gesund sein.\n"); \
AddSound(({DEFAULT_SOUND,"welle","wellen"}),"Du hoerst Wellen ans Ufer "	\
           "schlagen.\n");

#define SWIM_DETAILS	\
AddDetail("wasser",bs("Das Wasser ist nass. Es ist kalt, sodass Dir beinahe "	\
           "friert."));	\
AddDetail(({"see","klamm"}),bs("Du bist in einem See der Klamm der Seelen."));\
AddDetail(({"welle","wellen"}),bs("Die Wellen sind nicht sehr hoch."));	\
AddDetail(({"entfernung","ufer"}),bs("Das Ufer ist weit von hier entfernt. "	\
           "Es dauert vermutlich eine Zeit, dass Du wieder zurueckkommst."));	\
AddDetail("gesicht","Dein Gesicht kennst Du sehr gut.\n");	\
AddDetail("zeit",bs("Du wirst laenger schwimmen muessen, um ans Ufer "	\
           "zurueckzukommen."));	\
AddSmell(DEFAULT_SMELL,"Es riecht feucht.\n");	\
AddSound(DEFAULT_SOUND,"Du hoerst, wie Wellen neben Dir plaetschern.\n");	\
AddSound(({"wellen","welle"}),"Die Wellen brechen in sich zusammen.\n");\
AddDetail(({"wasser"}),"Das Wasser kann nicht geniessbar sein. " \
  +"Ausser dem Ruesselwurm kann hier vermutlich kein Lebewesen " \
  +"leben.\n");

#define COMMS	\
AddCmd(({"schwimm","schwimme"}),"schwimm");	\
AddCmd(({"tauch","tauche"}),"tauch");

//  In see11 und see12 ist tauchen anders, da kann man das Amulett finden.

#define SWIM	\
int schwimm()	\
{	\
  object o;	\
  write("Du springst ins Wasser und schwimmst vom Ufer weg.\n");	\
  say(TPN+" springt ins Wasser und schwimmt weg.\n");	\
  o=clone_object("/d/gebirge/monimor/obj/schwimm_tool.lpc");	\
  o->move(TP,M_NOCHECK);	\
  o->SetFrom(file_name(environment(TP)));	\
  TP->move(SEE("schwimm"),M_GO);	\
  return 1;	\
}

#define DIVE	\
int tauch()	\
{	\
  write("Du tauchst unter.\n");	\
  say(TPN+" taucht unter.\n");	\
  TP->move(SEE("tauch"),M_GO);	\
  return 1;	\
}
