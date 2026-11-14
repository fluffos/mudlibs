/*
   Dhrkion, die Dunkelelfenstadt - Zordan@SL
*/

// Long-Descriptions

/*
#define DET_LANG \
([ 1:". ";\
     "";"";"",\
   2:". ";\
     "";"";"",\
   3:". ";\
     "";"";""])
*/

#define DET_LANG1 \
([ 1:"Nahezu lautlos bewegst Du Dich um den Schutzwall weiter. ";\
     "wand";"waende";"",\
   2:"Rings um Dhrkion herum ist ein ziemlich hoher Schutzwall aufgebaut. ";\
     "wand";"waende";"",\
   3:"Der gewaltige Schutzwall um Dhrkion haelt bestimmt jedem Angriff stand. ";\
     "angriff";"wand";"waende"])

#define DET_LANG2 \
([ 1:"Ein kleiner Pfad ist mit der Zeit rings um die Stadt entstanden. ";\
     "pfad";"zeit";"boden",\
   2:"Auf dem Boden sind nicht viele Spuren zu erkennen. ";\
     "boden";"spuren";"spur",\
   3:"Der kleine Pfad auf dem Du stehst muss wohl von den Wachen angelegt "\
     "worden sein. ";\
     "pfad";"wachen";"boden"])

#define DET_LANG3 \
([ 1:"Selbst mit Deiner Lichtquelle kannst Du kaum die Decke erkennen. ";\
     "lichtquelle";"decke";"",\
   2:"Deine Lichtquelle reicht nicht dafuer aus, die Decke der riesigen "\
     "Hoehle zu erkennen. ";\
     "lichtquelle";"decke";"hoehle",\
   3:"Kleine Tiere scheinen an der Decke der Hoehle zu haengen. ";\
     "tiere";"decke";"hoehle"])

#define DET_LANG4 \
([ 1:"Dir ist ein wenig mulmig und Du moechtest eigentlich sofort weitergehen. "\
     "Entweder in die Stadt oder wieder ans Sonnenlicht zurueck. Hier zu lange "\
     "einfach so stehenbleiben kann wirklich gefaehrlich sein. ";\
     "sonnenlicht";"";"",\
   2:"Zu lange solltest Du Dich hier nicht aufhalten. Wer weiss schon welche "\
     "Gefahren Dich ausserhalb der Stadt erwarten. Nicht ohne Grund wird "\
     "Dhrkion so gut bewacht. ";\
     "gefahren";"grund";"",\
   3:"Leise Stimmen dringen aus der Stadt an Dich heran. Vielleicht solltest "\
     "Du Dich auch besser in die Stadt begeben, als Dich hier ausserhalb "\
     "in Gefahr zu bringen. ";\
     "stimmen";"gefahr";""])

/* Details 

  angriff,pfad,zeit,boden,spuren,spur,wachen,lichtquelle,decke,hoehle,tiere
  sonnenlicht,gefahren,grund,stimmen,gefahr

  licht,aerger,besonderes,ende

  "":\
   ".";\
   ".";\
   ".";\
   "";"";"",\

*/

#define DET_ALL2 ([ \
  "wand":\
   "Die Waende sind hier vollkommen uninteressant.";\
   "Die Waende wurden hier reingeschlagen.";\
   "Die findest nichts an den Waenden.";\
   "";"";"",\
  "waende":\
   "Die Waende sind hier vollkommen uninteressant.";\
   "Die Waende wurden hier reingeschlagen.";\
   "Die findest nichts an den Waenden.";\
   "";"";"",\
  "ende":\
   "Jemand fluestert Dir zu: Dein Ende ist nah.";\
   "Dein Ende kann schneller kommen als Du denkst.";\
   "Alles hat ein Ende, nur das SL nicht :)";\
   "";"";"",\
  "besonderes":\
   "NICHTS !!!";\
   "SEI FROH, DASS ICH SCRIPTFALLEN HASSE.";\
   "Sagte Ich Nicht, Dass Es Hier NICHTS Besonderes Gibt?";\
   "";"";"",\
  "aerger":\
   "Mach welchen und Du wirst sehen...";\
   "Hier Aerger zu machen waere sicher Dein Ende.";\
   "Musst Du denn ueberall Aerger machen? tststst";\
   "ende";"";"",\
  "licht":\
   "Kaum ein Licht ist hier zu sehen. Eigentlich nur Deines.";\
   "Die Wachen werden Dich sicher angreifen, wenn sie Dein Licht sehen!";\
   "Mach sofort das Licht aus! Oder bist Du selbstmoerderisch?";\
   "wachen";"";"",\
  "gefahr":\
   "Je laenger Du darueber nachdenkst, umso groesser wird sie wahrscheinlich.";\
   "Du solltest nicht zu lange darueber nachdenken. Sonst erwischt sie Dich "\
   "glatt noch.";\
   "Hinterhaeltig ist sie meist und kommt wenn man sie ueberhaupt nicht erwartet.";\
   "";"";"",\
  "stimmen":\
   "Kannst Du die sonst sehen?";\
   "Kann man Stimmen sehen?";\
   "Du siehst zwei Stimmen. Die sehen aber lustig aus...";\
   "";"";"",\
  "grund":\
   "Es muss einen Grund geben.";\
   "Fuer alles gibt es einen Grund.";\
   "Muss es fuer alles einen geben?";\
   "";"";"",\
  "gefahren":\
   "Vielfaeltige Gefahren lauern hier auf Dich. Besser Du gehst schnell weiter.";\
   "Viele Gefahren hast Du schon erlebt. Aber hier ist irgendwie alles anders.";\
   "Du denkst kurz an die Gefahren hier unten und laechelst kurz.";\
   "";"";"",\
  "sonnenlicht":\
   "Das Sonnenlicht wird hier unten niemals erscheinen.";\
   "Zurueck ans Sonnenlicht moechtest Du?";\
   "Du erinnerst Dich an das Sonnenlicht. Hm, Dir schaudert.";\
   "";"";"" ])

#define DET_ALL1 ([ \
  "tiere":\
   "Die Tiere haengen an der Decke und sind deshalb fuer Dich nicht zu erreichen.";\
   "Die Tiere sind zu weit entfernt. Du kannst sie nicht genauer beschreiben.";\
   "Unglaeubig scheinen Dich die Tiere anzusehen. Wie kann man hier unten "\
   "in Dhrkion nur Licht machen?";\
   "licht";"";"",\
  "hoehle":\
   "Dhrkion wurde in eine riesige Hoehle gebaut. Du kannst nicht sehen, "\
   "wie weit sie sich insgesamt ausdehnt.";\
   "Die Hoehle ist einfach nur gigantisch gross. Vorstellen kannst Du Dir "\
   "nicht, wie man eine komplette Stadt hier unten darin bauen kann.";\
   "Unbeschreibbares muss diese gewaltige Hoehle erschaffen haben.";\
   "";"";"",\
  "decke":\
   "Die Decke ist sehr weit ueber Dir.";\
   "Da ist nichts an der Decke, oder doch?";\
   "Seltsam, die Decke ist nicht zu erkennen von hier aus.";\
   "";"";"",\
  "lichtquelle":\
   "Es ist jedenfalls hell genug.";\
   "Hell genug um was zu sehen, mehr nicht.";\
   "Mehr als diesen Raum kannst Du nicht ausleuchten.";\
   "";"";"",\
  "wachen":\
   "Etliche Wachen patroullieren staendig um die Stadt und bewachen sie.";\
   "Man hat um die Stadt viele Wachen positioniert. Mach hier bloss keinen "\
   "Aerger oder Licht, sie wuerde Dich sofort angreifen!";\
   "Die Wachen werden kein Licht dulden. Pass bloss auf, dass sie Dich nicht "\
   "damit erwischen!";\
   "aerger";"licht";"",\
  "spur":\
   "Hihi, das ist Deine eigene Spur. Mehr nicht.";\
   "Hm, wem mag diese Spur nur gehoeren?";\
   "Upsi, die Spur ist auf einmal verschwunden!?!";\
   "";"";"",\
  "spuren":\
   "Nicht viele heisst es sind einfach nur wenige. Die meisten wohl von Dir.";\
   "Vereinzelt siehst Du ein paar Spuren. Gerade viele sind es halt nicht.";\
   "Die Spuren koennen nur von den Wachen und Dir stammen.";\
   "wachen";"";"",\
  "boden":\
   "Auf dem Boden windet sich ein kleiner Pfad um den Schutzwall.";\
   "Ein kleiner Pfad ist auf dem Boden zu erkennen.";\
   "Bis auf einen kleinen Pfad kannst Du nichts auf dem Boden erkennen.";\
   "pfad";"";"",\
  "zeit":\
   "Mit der Zeit lernst auch Du, sowas nicht zu untersuchen.";\
   "Zeit Zei Ze Z, wie sie doch manchmal voellig sinnlos verstreicht.";\
   "Es kommt die Zeit, da bemerkst auch Du, dass ich nicht jedes Detail "\
   "hier beschreiben werde. gez. Zordan.";\
   "";"";"",\
  "pfad":\
   "Der Pfad um den Schutzwall zeigt hier nichts Besonderes.";\
   "Auf dem Pfad findest Du eine kleine Spur.";\
   "Der Pfad schlaengelt sich lautlos und unbedeutend um die Stadt herum.";\
   "besonderes";"spur";"",\
  "angriff":\
   "Um einen Angriff auf Dhrkion zu ueberleben, sollte man gut planen und "\
   "sehr gut taktieren. Schnell koennte man sonst sein Ende finden.";\
   "Du hast doch nicht ernsthaft vor, Dhrkion anzugreifen, oder?";\
   "Einen Angriff nach dem anderen hat man hier wohl schon abgewehrt. Sonst "\
   "wuerde es Dhrkion ja wohl nicht mehr geben...";\
   "ende";"";"" ])

