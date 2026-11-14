//  Gang in Morkas
//  DETAILS
//  COMMS
//  LOOK
//  LOOK1 nur fuer room_03.c -> Eingang zu einer Kneipe


#define LOOK1 \
SSH("Ein Gang in Morkas"); \
SetProp(P_INT_LONG,"Du befindest Dich in einem Gang durch die Hallen von Morkas. Trotz des" \
+" etwas duesteren Lichtes kannst Du noch genug sehen, da Fackeln den Gang " \
+"ausleuchten. Es ist kuehl hier drinnen, Du duerftest also irgendwo " \
+"innerhalb des Gebirges sein. Genau kannst Du es nicht wissen, da es " \
+"keinen begehbaren Weg hierher gibt. Die Waende und der Boden des Ganges " \
+"sind dunkel. Insgesamt herrscht eine duestere Atmosphaere. Im Norden ist " \
+"der Eingang zu einer Kneipe."); \
SetProp (P_ENVIRONMENT, ([ENV_TEMPERATURE:15+random(5)])); \
SetProp(P_INDOORS,1); \
SetProp(P_LIGHT,1);


#define LOOK \
SSH("Ein Gang in Morkas"); \
SetProp(P_INT_LONG,"Du befindest Dich in einem Gang durch die Hallen von Morkas. Trotz des" \
+" etwas duesteren Lichtes kannst Du noch genug sehen, da Fackeln den Gang " \
+"ausleuchten. Es ist kuehl hier drinnen, Du duerftest also irgendwo " \
+"innerhalb des Gebirges sein. Genau kannst Du es nicht wissen, da es " \
+"keinen begehbaren Weg hierher gibt. Die Waende und der Boden des Ganges " \
+"sind dunkel. Insgesamt herrscht eine duestere Atmosphaere."); \
SetProp (P_ENVIRONMENT, ([ENV_TEMPERATURE:5])); \
SetProp(P_INDOORS,1); \
SetProp(P_LIGHT,1);

#define DETAILS \
  AddDetail("decke","Die Decke ist nicht sehr hoch.\n"); \
  AddDetail( ({ "licht" }), \
                break_string( "Das Licht der Fackeln ist ziemlich duester.", 78 ) ); \
  AddDetail("gang",bs("Der Gang fuehrt durch die Hallen von Morkas. Es ist " \
"ziemlich duester hier.")); \
  AddDetail(({"halle","hallen"}),"Die Hallen von Morkas.\n"); \
  AddDetail(({"fackel","fackeln"}),"Die Fackeln stecken in Halterungen. Sie " \
"erhellen den Gang.\n"); \
  AddDetail("morkas",bs("Morkas ist eine Art Stadt mitten im Gestein der " \
"Klamm der Seelen.")); \
  AddDetail("klamm",bs("Die kannst Du von hier aus nicht sehen, weil Du im " \
"Gestein der Klamm bist.")); \
  AddDetail(({"gestein","fels"}),"Der typische Fels der Klamm, keine Ritzen " \
"und Fugen.\n"); \
  AddDetail(({"weg","boden"}),bs("Auf dem Boden ist etwas Staub.")); \
  AddDetail("staub",bs("Du kannst Spuren im Staub erkennen.")); \
  AddDetail(({"spur","spuren"}),bs("Ausser Deinen eigenen Spuren, siehst Du " \
"Spuren schwerer Metallstiefel.")); \
  AddDetail("gebirge",bs("Du befindest Dich im Gesteinsmassiv der Klamm " \
"der Seelen in den Hallen von Morkas.")); \
  AddDetail("atmosphaere","Eine ziemlich duestere Atmosphaere herrscht " \
"hier.\n"); \
  AddDetail("stadt","Du bist in Morkas.\n"); \
  AddDetail("wand",bs("Die Wand besteht aus Felsgestein.")); \
  AddDetail(({"halterung","halterungen"}),bs("Die Fackeln stecken in ihnen. " \
"Sie sind an der Wand befestigt.")); \
  AddDetail("fels",bs("Der Fels ist aalglatt, keine Spalten und keine Fugen. "\
"Er ist nicht wirklich schwarz, sondern dunkel. Seltsam, aber trotzdem " \
"scheint diese Felsart das Licht staerker zu absorbieren, als wenn sie " \
"schwarz waere."));
