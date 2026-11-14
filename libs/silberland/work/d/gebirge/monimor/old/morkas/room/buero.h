
//  Buerokomplex von Morkas
//  BUERO -> Details fuer Bueroraeume
//  GANG -> Gang-Details
//  POST -> Das Rohrpostsystem und seine Befehle
//  COMMS -> Die Befehle fuer die Rohrpost


#define POST \
AddDetail(({"loch","rohrpost","rohrpostsystem"}),"Das Loch in " \
  +"der Wand ist der Zugang zum Rohrpostsystem Morkas'. Du kannst " \
  +"eine Rohrpost schreiben, aber hierfuer solltest Du zuerst " \
  +"die Tafel neben dem Loch lesen. Dort steht auch, wie Du " \
  +"Deine Post dann abschicken kannst.\n"); \
AddDetail("tafel","Du kannst sie lesen.\n"); \
AddReadDetail("tafel","Das Rohrpostsystem von Morkas:\n" \
  +"  --------------------------------------------------------------------------\n" \
  +"\n" \
  +"Mit <schreibe rohrpost <kuerzel> <absender>> kannst Du ein Rohrpost schreiben.\n" \
  +"Mit <schicke rohrpost an <empfaenger>> kannst Du diese dann " \
  +"abschicken.\n" \
  +"Mit <lies rohrpost> kannst Du eine Rohrpost lesen.\n"+"\n" \
  +"Folgende Empfaenger stehen zur Verfuegung: \n" \
  +"  Nidgor\n"+"  Sekretaer\n"+"\n" \
  +"Du kannst folgende Kuerzel beim Schreiben einer Rohrpost " \
  +"verwenden:\n" \
  +"  1: zum Diktat\n" \
  +"  2: Zigarettenpause\n" \
  +"  3: bin Ausserhalb, rekrutiere gerade\n" \
  +"  4: bin kurz weg -> uriniere gerade\n" \
  +"  5: bin beim Chef\n");

#define BUERO \
AddDetail(({"tisch","schreibtisch"}),"Dieser Schreibtisch ist " \
  +"schon ziemlich alt. Er ist zerfurcht und hat an manchen " \
  +"Stellen Tintenflecke. Die Schreibauflage ist aus gruenem " \
  +"Filz, ein kleiner Vorbau erhebt sich vor dieser und er " \
  +"hat eine Schublade.\n"); \
AddCmd(({"schreib","schreibe"}),"schreib"); \
AddCmd(({"schick","schicke"}),"schick"); 

#define COMMS \
schreib(str) \
{ \
  int kuerzel; \
  string absender; \
  object post; \
  if(!stringp(str) || str=="") \
	return (notify_fail("Syntax: <schreibe rohrpost <kuerzel> <absender>>\n"),0); \
  if(sscanf( str, "rohrpost %d %s", kuerzel, absender)>0) \
  { \
    post=clone_object(MOOB("rohrpost")); \
	post->set_vars(kuerzel,absender); \
    post->move(TP,M_NOCHECK); \
	write("Du schreibst eine Rohrpost und steckst sie ein.\n"); \
	say(TPN+" schreibt eine Rohrpost und steckt sie ein.\n",TP); \
	return 1; \
  } \
 else \
   return (notify_fail("Das kannst Du nicht schreiben.\n"),0); \
}
