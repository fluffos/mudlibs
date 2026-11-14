#define DRITTER  \
SetProp(P_NO_TPORT, NO_TPORT);\
  \
AddDetail( ({"ebene","etage","labyrinthebene","umgebung"}),               \
  "Du befindest Dich auf Etage III im Turm der tausend Tode. Sie wird von Steingolems bewohnt."); \
  \
AddDetail( ({"labyrinthwaende","wand","waende"}),               \
  "Die Waende sind aus Steinbloecken erbaut. Obwohl sie eigentlich sehr fest und unbeweglich "+\
  "aussehen, veraendern sie sich auf dieser Etage von Zeit zu Zeit."); \
  \
AddDetail(({"tod","tode"}),                           \
  "Den Tod untersuchen? Dazu muesstest Du zuerst sterben...");\
  \
AddDetail("zeit",                           \
  "Es ist Zeit fuer Dich zu sterben, oder?");\
  \
AddDetail("granit",                           \
  "Nicht nur deine Umgebung ist aus diesem harten Gestein, sondern auch manche Golems die hier rumlungern.");\
  \
AddDetail("boden",							 \
  "Auch der Boden in dieser Etage ist so wie fast alles in diesem Turm aus Stein.");\
  \
AddDetail( ({"stein","gestein"}),               \
  "Es handelt sich um knallhartes Granit. Unglaublich das es sich in dieser Labyrinthebene "+\
  "teilweise veraendert."); \
  \
AddDetail("labyrinth",                           \
  "Du stehst inmitten dieses Labyrinths, hoffentlich findest Du bald wieder heraus.");\
  \
AddDetail("decke",\
  "Die Decke ist in ca. 2m ueber Dir angebracht. Du findest nichts besonderes an ihr.");\
  \
AddDetail("turm",\
  "Du stehst mitten in ihm.");\
  \
AddDetail("himmel",\
  "Du starrst an die Decke. Himmel ist da keiner zu sehen.");\
  \
AddDetail( ({"steingolem","golem","golems","steingolems"}),               \
  "Es handelt sich um aus verschiedenen Gesteinen geschaffenen Golems, welche diese Labyrinthebene "+\
  "bewohnen und ab und die Labyrinthwaende verschieben. Manche von ihnen sind freundlich andere aber sehr kampflustig."); \
  \
AddDetail(({"gesteine","gesteinen"}),\
  "Golems gibts aus folgenden Gesteinen: Lehm, Sandstein, Granit, Marmor, Basalt, Quarz, Porphyr, "+\
  "Kalkstein, Gneis und Schiefer.");\
  \
AddDetail( ({"stein","block","steinblock","bloecke","steinbloecke","steinbloecken"}),               \
  "Sie sind riesig. Du kannst froh sein, dass Du sie nicht selbst "+ \
  "abbauen hast muessen. Das Material aus dem sie sind, ist anscheinend Granit."); \
  \
AddDetail( ({"material","granit"}),               \
  "Es handelt sich um Granit."); \
  \
AddDetail("nase",\
  "Du greifst Dir auf die Nase. Sie ist leicht erroetet.");\
  \
AddSmell( ({DEFAULT_SMELL}),                        \
  "Du schnupperst mit Deiner Nase, riechst aber nur Deinen eigenen Schweiss.");    \
                                    \
AddSmell("schweiss", \
  "Oh, wie ekelhaft!"); \
  									\
AddSound( ({DEFAULT_SOUND}),                        \
  "Du hoerst ein leises Knirschen, muss wohl von den Steingolems kommen.");   \
                                    \
AddSound( ({"knirsch","knirschen"}),                        \
  "Es hoer sich an als ob man zwei Steine aneinander reibt.");
#define ZWEITER  \
SetProp(P_NO_TPORT, NO_TPORT);\
  \
AddDetail( ({"wand","waende"}),               \
  "Die Waende sind auch hier aus fetten Steinbloecken erbaut. Jedoch so feucht wie in "+\
  "der ersten Ebene dieses Turms sind sie nicht. Sie scheinen dich beinahe zu erdruecken."); \
  \
AddDetail( ({"stein","block","steinblock","bloecke","steinbloecke","steinbloecken"}),               \
  "Sie sind riesig. Du kannst froh sein, dass Du sie nicht selbst im Steinbruch "+ \
  "abbauen hast muessen. Das Material aus dem sie sind, ist anscheinend Granit."); \
  \
AddDetail( ({"steinbruch"}),               \
  "Du hast keine Ahnung wo der sein soll."); \
  \
AddDetail( ({"material","granit","gestein"}),               \
  "Du klopfst mit Deiner Hand hart auf das Gestein. Tatsaechlich, harter, ja, "+ \
  "steinharter Granit."); \
  \
AddDetail( ({"ebene","etage","unteren"}),               \
  "Du befindest Dich auf Etage II im Turm der tausend Tode. "); \
  \
AddDetail( ({"turm","todesturm","raum"}),               \
  "Der Turm ist immer noch sehr beaengstigend, doch mittlerweile bist Du schon "+ \
  "einigermassen an ihn gewoehnt. Es ist irgendwie saukalt hier drinnen oder nicht?"); \
  \
AddDetail( ({"mauern","mauer","wand","waende"}),               \
  "Die Waende sind aus Gestein. Hier in dieser Etage sind sie nicht mehr so feucht "+ \
  "wie in der unteren. Sie scheinen Dich nahezu zu erdruecken."); \
  \
AddDetail( ({"decke"}),               \
  "Die Decke ist ebenfalls aus purem Granit. Sie ist in etwa 3 Meter ueber Dir "+ \
  "angebracht. Sie sieht wirklich robust aus und wird Dir bestimmt nicht auf den Kopf fallen."); \
  \
AddDetail( ({"kopf","hand"}),               \
  "Ist noch dran, Du kannst es fuehlen."); \
  \
AddDetail( ({"licht"}),               \
  "Nicht gerade hell hier drinnen. Das Licht erhellt den Raum gerade soweit, dass "+ \
  "Du was sehen kannst."); \
  \
AddDetail( ({"boden"}),               \
  "Am Boden kannst Du einige Knochenreste erkennen, werden wohl die Untoten "+ \
  "verloren haben."); \
  \
AddDetail( ({"untot","untoter","untote"}),               \
  "Diese Ebene regieren die Untoten. Hoffentlich wirst Du nicht auch einer "+ \
  "von ihnen."); \
  \
AddDetail( ({"knochen","knochenreste","reste"}),               \
  "Die sehen nicht gerade gut aus. Daher kommt also dieser modrige Geruch hier "+ \
  "im Turm."); \
  \
AddDetail( ({"tod","tode"}),               \
  "Nein, daran willst Du gar nicht denken. Du bist momentan noch froh, unter "+ \
  "den Lebenden zu weilen."); \
  \
AddDetail( ({"lebende","lebenden","puls"}),               \
  "Du fuehlst Deinen Puls. Alles ok!"); \
  \
AddSmell( ({DEFAULT_SMELL}),                        \
  "Es riecht extrem modrig hier drinnen.");    \
  \
AddSound( ({DEFAULT_SOUND}),                        \
   "Du hoerst Knochen klappern, das werden doch nicht Deine sein.");   \
  \
AddDetail( ({"gang","gaenge"}),               \
  "Der Todesturm steckt voller Gaenge so wie dieser einer ist. Irgendwie ist es zu eng hier."); 
#define VORSPRUNG	\
SetProp(P_NO_TPORT, NO_TPORT);\
  \
AddDetail( ({"wand","waende"}),               \
  "Diese Steinplatte schwebt ab und an hier vorbei."); \
                                    \
AddDetail( ({"wand","waende"}),               \
  "Die Waende sind aus kalten massiven Steinbloecken welche uebereinander gestapelt " \
  "den Turm der tausend Tode bilden. Auf einem Stein ist ein kleiner Knopf den man druecken kann.");  \
                                    \
AddDetail( ({"gestein","stein","steine","block","steinblock","bloecke","steinbloecke"}),               \
  "Die Steinbloecke bestehen aus Granit. Sie sind feucht, irgendwoher " \
  "muss hier Wasser eindringen.");  \
                                    \
AddDetail( ({"turm"}),               \
  "Du stehst mitten in ihm. Ob Du je wieder herauskommst ist eine andere "\
  "Frage.");  \
                                    \
AddDetail( ({"frage"}),               \
  "Du fragst Dich welche Frage Du fragen sollst, entscheidest aber " \
  "besser nichts ueber Deine Fragen zu fragen.");  \
                                    \
AddDetail( ({"wasser"}),               \
  "Das Wasser ist leicht salzig, es wird wohl die Mineralien leicht aus den " \
  "Steinbloecken loesen.");  \
                                    \
AddDetail( ({"mineralien"}),               \
  "Du untersuchst das Wasser nach Mineralien, findest aber keine. Sie " \
  "sind wahrscheinlich zu klein.");  \
                                    \
AddDetail( ({"gewoelbe"}),               \
  "Das Gewoelbe ist aus kaltem massiven Stein gehauen. Es vermittelt " \
  "einen unheimlichen Eindruck.");  \
                                    \
AddDetail( ({"mauervorsprung","vorsprung"}),               \
  "Der Vorsprung auf dem Du stehst ist etwa 2 Meter mal 2 Meter gross. " \
  "Es sammelt sich etwas Wasser darauf.");  \
                                    \
AddDetail( ({"boden"}),               \
  "Du stehst auf einem Mauervorsprung."); \
                                    \
AddDetail( ({"decke"}),               \
  "Die Decke ist 3 Meter ueber Dir und ebenfalls wie so manches hier " \
  "aus Granit.");  \
                                    \
AddDetail( ({"granit"}),               \
  "Es ist sehr hart, kalt und glitzert ein wenig. Ein echtes Gestein " \
  "aus den Bergen.");  \
                                    \
AddDetail( ({"fackel","fackeln"}),               \
  "Die Fackeln sind fest verankert in den Waenden. Sie geben ein wenig " \
  "Licht hier drinnen.");  \
                                    \
AddDetail( ({"licht"}),               \
  "Das Licht der Fackeln ist nicht besonders hell aber es reicht um " \
  "etwas zu sehen.");  \
                                    \
AddDetail( ({"loch"}),               \
  "Das Loch ist tief, viel zu tief um zu ueberleben wenn man runterfallen wuerde."); \
                                    \
AddDetail( ({"leben"}),               \
  "Irgendwie haengst Du daran."); \
                                    \
AddDetail( ({"knopf"}),               \
  "Ein kleiner Knopf steht aus einem der Steine heraus. Man kann ihn " \
  "druecken."); \
									\
AddSmell( ({DEFAULT_SMELL}),                        \
  "Es riecht modrig hier drinnen.");    \
AddCmd("brich","fackel"); \
                                    \
AddSound( ({DEFAULT_SOUND}),                        \
  "Du hoerst die Wassertropfen von den Waenden auf den Vorsprung tropfen.");   \
                                    \
AddSound( ({"tropfen","wassertropfen"}),                        \
  "TROPPPPPFFFFFFFFFFFF - TROOOOOPPPPPPPPFFFFFFFFFF - TROOOOOOOPPFFFFFFFFFFF.");
#define ERSTER	\
SetProp(P_NO_TPORT, NO_TPORT);\
  \
AddDetail( ({"wand","waende","gewoelbe","decke","gang"}),				\
  "Das Gewoelbe ist aus kaltem massiven Stein gehauen. Es vermittelt " \
  "einen unheimlichen Eindruck.");  \
									\
AddDetail( ({"stein","gestein","steinklotz","steinkloetze","klotz"}), \
  "Purer Granit. Das Licht der Fackeln an den Waenden bricht sich " \
  "darin. Du wunderst Dich wo im Silberland so viel Granit abgebaut " \
  "worden ist.");  \
                                    \
AddDetail( ({"silberland"}),           \
  "Du schaust Dich um. Das hier soll wirklich noch das Silberland sein?"); \
									\
AddDetail( ({"wasser", "feuchte", "feucht"}),			\
  "Es ist eindeutig Salzwasser, es wird an einigen Stellen der Waende " \
  "hereingedrueckt und sammelt sich am Boden."); \
  									\
AddDetail( ({"salzwasser"}),           \
  "Keine Ahnung warum aber das Wasser ist salzig."); \
                                    \
AddDetail( ({"boden","granitboden"}),				\
  "Du stehst auf einem nassen Granitboden. Ueberall steht Dir hier das Wasser " \
  "bis an die Fussknoechel.");	\
                                    \
AddDetail( ({"knochen","knoechel", "fussknoechel"}),           \
  "Ganz schoen morsch Deine alten Knochen."); \
                                    \
AddDetail( ({"turm","tod","todesturm"}),				\
  "Man munkelt ueber mehr als tausend Helden die ihr Leben hier beendeten. "  \
  "Darum auch der Name, Turm der tausend Tode. Alles sieht so kalt aus hier.");			\
  									\
AddDetail( ({"granit"}),                \
  "Er ist hart und kalt. Nahezu alles hier herinnen duerfte daraus gemacht sein. ");  \
  									\
AddSmell( ({DEFAULT_SMELL}),						\
  "Es riecht modrig hier drinnen.");	\
AddCmd("brich","fackel"); \
                                    \
AddSound( ({DEFAULT_SOUND}),                        \
  "Du hoerst die Wassertropfen von den Waenden auf den Boden tropfen.");   \
  									\
AddSound( ({"tropfen","wassertropfen"}),                        \
  "TROPPPPPFFFFFFFFFFFF - TROOOOOPPPPPPPPFFFFFFFFFF - TROOOOOOOPPFFFFFFFFFFF.");
#define FACKEL                      \
int fackel(string str)                          \
{                                   \
  notify_fail("Was willst Du wo rausbrechen?\n");                   \
  if(!str) return 0;                            \
  if( member( ({"fackel", "fackel heraus","fackel aus halterung", "fackel herunter",    \
                "rackel runter","fackel aus wand"}), str)!=-1 )             \
  {                                 \
   if(!deep_present("\nfackel",this_player()))    \
   {    \
   clone_object("/d/ebene/lamuerte/turm/obj/fackel.lpc")->move(this_player(),M_NOCHECK);    \
    write("Du brichst eine Fackel aus ihrer Halterung.\n");     \
    return 1;       \
   }        \
   else     \
   {        \
    write ("Mehr von diesen Fackeln brauchst Du nicht.\n"); \
    return 1; \
   }        \
  }                                 \
  return 0;                             \
} 
