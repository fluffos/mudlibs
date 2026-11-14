// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /room/rathaus/div/leo_vogt.inc
// Description: Diese Teil von Leo macht aus Gesellen Voegte
// Author:
// Modified by:
//
// $Log: leo_vogt.inc,v $
// Revision 1.5  2003/12/15 00:03:08  gnomi
// Einige static-Funktionen privatisiert.
//
// Revision 1.4  2001/04/13 13:27:05  sissi
// wizinfos bei Levelaenderungen eingebaut.
//
// Revision 1.3  2001/04/07 00:12:15  gnomi
// Header/CVS-Log eingebaut.
//

#define VOGTVERTRAG "/room/rathaus/obj/vogtvertrag"

//
// Teste Vogt wird aufgerufen, um festzustellen, ob der Geselle Vogt
// werden DARF.
//
private int teste_vogt(object ob)
{
   int miss_time;

   if(LVL_VOGT >= BANISHD->query_banished(ob->query_real_name()))
      REJECT("sage Der oberste Rat moechte Dich nicht ohne seine Zustimmung"
	     " zum Vogt machen.");
   if(vogtp(ob))
      REJECT("sage Du bist doch bereits ein Vogt!");
   if(!gesellep(ob))
      REJECT("sage Nur Gesellen koennen Vogt werden.\n");
   if(testplayerp(ob))
      REJECT("sage Jetzt hast Du ein Problem, "
	     "denn als Zweitcharakter kann man nicht Gott werden!");
   if(ob->query_moerder())
      REJECT("sage Moerder wie Du muessen sich erst von ihrer Schuld "
	     "befreien!");
   return 1;
}

//
// erschaffe_vogt wird aufgerufen, wenn alle Formularitaeten
// abgeschlossen sind, und der Vogt gesetzt wird.
//
private void erschaffe_vogt(object vogt, string vogt1, string vogt2, string lord)
{
    string v_name;

    // Ein ein neuer Vogt ist geboren... let's do it.

    v_name=vogt->query_real_name();

    // VOGT Logfile updaten
    sys_log("VOGT",sprintf("%s:  %-10s  (Vogt: %-10s %-10s  Lord: %s)\n",
	ctime(),capitalize(v_name), capitalize(vogt1), capitalize(vogt2),
		capitalize(lord)));

    // Level setzen
    vogt->set_level(LVL_VOGT);

    // Vogt-Kommandos erlauben.
    vogt->define_wiz_commands();

    // Ins Goetter-Register eintragen
    GOETTER_REGISTER->add_lehrmeister(v_name,lord);

    // Master informieren (Schiffe...)
    // MASTER_OB->master_create_vogt(vogt);

    // Player abspeichern.
    vogt->do_save();

    // Begruessung...
    do_command("sage Viel Vergnuegen und Ausdauer als Vogt, "+
	capitalize(vogt->query_real_name())+"!");

    // Belehrung
    do_command("sage Als Vogt kannst Du "+MUD_NAME+" erweitern. Halte Dich "
	"dabei immer an die Richtlinien und beachte das, was die Domainlords "
	"sagen.");
    call_out("do_command",1,
	"sage Und denke daran: Folge dem EINEN Weg, dem Weg aller Goetter!");
    wizinfo (vogt->query_real_cap_name()
        +" ist jetzt ein Vogt, herzlichen Glueckwunsch!");
}


// 
// vogtvertrag wird aufgerufen wenn, ein Geselle Leo den
// Vogtvertrag gibt
//
protected int vogtvertrag(object ob, object woher, object to, object ti) 
{
    if (!present(ob))
	return 1;
    if(!strstr(object_name(ob), VOGTVERTRAG))
    {
	if (!ti || ti != this_player())
	    do_command("sage Du hast mir den Vogtvertrag nicht aus "
		       "eigenem Willen gegeben. Deswegen ist er ungueltig.");
	else if (!ob->query_signed()) 
	    do_command("sage Mhh. Der Vertrag ist nicht unterzeichnet. "
		       "Dann halt nicht.");
	else if (ob->query_signed()!=15)
	{
	    do_command("sage Mhh. Es haben nicht alle unterzeichnet. "
		       "Dann halt nicht.");
	    return 0;
	}
	else if (this_player()->query_real_name()!=ob->query_vogt())
	{
	    do_command("sage Mhh. Den Vertrag muss mir schon vom Lehrling "
		       "gegeben werden.");
	    return 0;
	}
	else if (teste_vogt(this_player()))
	    erschaffe_vogt(this_player(), ob->query_vogt1(),
				     ob->query_vogt2(), ob->query_lord());
	ob->remove();
	return 1;
    }
}


//
// vogt wird aufgerufen, wenn der Geselle darum bittet, vogt zu werden.
//
void vogt(string str)
{
   object ob;

   if(!teste_vogt(this_player()))
      return;

   do_command("sage Aha, Du willst also Vogt werden.");
   do_command("sage Dazu musst Du Dir einen Domainlord suchen. "
   	"Ich gebe Dir hier ein Zeugnis, das Du von Deinen beiden Lehrmeistern "
	"unterzeichnen lassen musst. Anschliessend musst Du noch unter"
	"schreiben und damit zu einem Domainlord gehen und unterschreiben "
	"lassen. Danach bringe mir das unterschriebene Zeugnis zurueck.");
   ob=clone_object(VOGTVERTRAG);
   ob->set_vogt(this_player()->query_real_name());
   ob->move(this_object());
   give_object(ob,this_player());
}
