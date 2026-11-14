// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /room/rathaus/div/leo_geselle.inc
// Description: Leos Funktionen, um einen Lehrling zum Gesellen zu befoerdern
// Author:
// Modified by:
//
// $Log: leo_geselle.inc,v $
// Revision 1.7  2003/12/15 00:03:08  gnomi
// Einige static-Funktionen privatisiert.
//
// Revision 1.6  2001/09/16 19:50:43  sissi
// Leo gibt einem Gesellen nun auch eine Ausbildungsschriftrolle.
//
// Revision 1.5  2001/04/13 13:27:05  sissi
// wizinfos bei Levelaenderungen eingebaut.
//
// Revision 1.4  2001/04/07 00:12:15  gnomi
// Header/CVS-Log eingebaut.
//

#define GESELLENBUCH  "/room/rathaus/obj/exodus"
#define GESELLENVERTRAG "/room/rathaus/obj/gesellenvertrag"
#define AUSBILDUNGSSCHRIFTROLLE "/room/rathaus/obj/ausbildung"

//
// Teste Geselle wird aufgerufen, um festzustellen, ob der Lehrling Geselle
// werden DARF.
//
private int teste_geselle(object ob)
{
   int miss_time, miss_time_stunden;

   if(LVL_GESELLE >= BANISHD->query_banished(ob->query_real_name()))
      REJECT("sage Der oberste Rat der Goetter moechte Dich nicht"
	     " ohne seine Zustimmung zum Gesellen machen!");
   if(gesellep(ob))
      REJECT("sage Du bist doch bereits ein Geselle!");
   if(!learnerp(ob))
      REJECT("sage Nur Lehrlinge koennen Geselle werden.\n");
   if(testplayerp(ob))
      REJECT("sage Jetzt hast Du ein Problem, "
	     "denn als Zweitcharakter kann man nicht Gott werden!");
   if(ob->query_moerder())
      REJECT("sage Moerder wie Du muessen sich erst von ihrer Schuld "
	     "befreien!");
   if(( miss_time = 
	 LEARNER_TIME -
         (ob->query_age()-
	  ob->query_level_ages(LVL_LEARNER)) ) >= 0) {
      miss_time_stunden = (miss_time/3600)+1;
      REJECT("sage Du solltest noch etwas mehr Doku lesen und "
	     "Dir alle Richtlinien und Funktionsweisen genau einpraegen. "
	     "Komm doch fruehestens zurueck, wenn Du "+
	     miss_time_stunden+" "+
             (miss_time_stunden==1?"Stunde":"Stunden")+
             " aelter bist, und Dich besser auskennst.");
   }
   return 1;
}

//
// erschaffe_geselle wird aufgerufen, wenn alle Formularitaeten
// abgeschlossen sind, und der Geselle gesetzt wird.
//
private void erschaffe_geselle(object geselle, string vogt1, string vogt2)
{
    object book;
    string g_name;

    // Ein ein neuer Geselle ist geboren... let's do it.

    g_name=geselle->query_real_name();

    // GESELLE Logfile updaten
    sys_log("GESELLE",sprintf("%s:  %-10s  (Vogt: %-10s %s)\n",
	ctime(),capitalize(g_name), capitalize(vogt1), capitalize(vogt2)));

    // Level setzen
    geselle->set_level(LVL_GESELLE);

    // Gesellen-Kommandos erlauben.
    geselle->define_wiz_commands();

    // Ins Goetter-Register eintragen
    GOETTER_REGISTER->add_lehrmeister(g_name,vogt2);

    // Master informieren (Schiffe...)
    MASTER_OB->master_create_geselle(g_name);

    // Player abspeichern.
    geselle->do_save();

    // Begruessung...
    do_command("sage Viel Vergnuegen und Ausdauer als Geselle, "+
	capitalize(geselle->query_real_name())+"!");

    // Belehrung
    do_command("sage Als Geselle musst Du jetzt viel ueben. Dabei werden Dir "
	"Deine beiden Lehrmeister helfen. Wenn Du dann genug geuebt hast, "
	"und Deine beiden Lehrmeister auch dieser Ansicht sind, so kannst "
        "Du Dir einen Lord suchen, der Dich dann zusammen mit Deinen beiden "
        "Lehrmeistern zum Vogt ernennt.");

    // Einfuehrungsbuch in die Hand druecken
    book = clone_object(GESELLENBUCH);
    book->move(this_object());
    give_object(book,geselle);

    book = clone_object(AUSBILDUNGSSCHRIFTROLLE);
    book->move(this_object());
    give_object(book,geselle);
    

    call_out("do_command",1,
	"sage Und denke daran: Folge dem EINEN Weg, dem Weg aller Goetter!");
    wizinfo (geselle->query_real_cap_name()
        +" ist jetzt ein Geselle, herzlichen Glueckwunsch!");
}


// 
// gesellenvertrag wird aufgerufen wenn, ein Lehrling Leo den
// Gesellenvertrag gibt
//
protected int gesellenvertrag(object ob, object woher, object to, object ti) 
{
    if (!present(ob))
	return 1;
    if(!strstr(object_name(ob), GESELLENVERTRAG))
    {
	if (!ti || ti != this_player())
	    do_command("sage Du hast mir den Gesellenvertrag nicht aus "
		       "eigenem Willen gegeben. Deswegen ist er ungueltig.");
	else if (!ob->query_signed()) 
	    do_command("sage Mhh. Der Vertrag ist nicht unterzeichnet. "
		       "Dann halt nicht.");
	else if (ob->query_signed()!=7)
	{
	    do_command("sage Mhh. Es haben nicht alle unterzeichnet. "
		       "Dann halt nicht.");
	    return 0;
	}
	else if (this_player()->query_real_name()!=ob->query_geselle())
	{
	    do_command("sage Mhh. Den Vertrag muss mir schon vom Lehrling "
		       "gegeben werden.");
	    return 0;
	}
	else if (teste_geselle(this_player()))
	    erschaffe_geselle(this_player(), ob->query_vogt1(),
					     ob->query_vogt2());
	ob->remove();
	return 1;
    }
}


//
// geselle wird aufgerufen, wenn der Lehrling darum bittet, Goetter-
// geselle zu werden.
//
void geselle(string str)
{
   object ob;

   if(!teste_geselle(this_player()))
      return;

   do_command("sage Aha, Du willst also Geselle werden.");
   do_command("sage Dazu musst Du Dir einen weiteren Vogt als 2. Lehrmeister "
	"suchen. Ich gebe Dir hier einen Vertrag, den Du, Dein Lehrmeister "
	"und Dein 2. Lehrmeister unterschreiben muessen. Danach bringe "
	"mir den unterschriebenen Vertrag zurueck.");
   ob=clone_object(GESELLENVERTRAG);
   ob->set_geselle(this_player()->query_real_name());
   ob->move(this_object());
   give_object(ob,this_player());
}
