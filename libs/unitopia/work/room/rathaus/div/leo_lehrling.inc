// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/room/rathaus/div/leo_lehrling.inc
// Description:	Teil von Leo, der das Lehrling-Werden regelt
// Author:	Francis
// Modified by:	
//
// $Log: leo_lehrling.inc,v $
// Revision 1.21  2014/11/11 16:38:06  myonara
// Hinweise fuer Treppennische eingebaut
//
// Revision 1.20  2009-06-17 07:56:02  gnomi
// Parsing an PARSE_SAY angepasst.
//
// Revision 1.19  2008/01/16 09:46:04  gnomi
// INPUT_PROMPT verwenden.
//
// Revision 1.18  2005/05/26 01:05:04  gnomi
// Urlaubsgoetter ablehnen.
//
// Revision 1.17  2004/04/02 10:43:14  menaures
// Bei Gottanwaertern auch Zweities auf Banish, Moerder, etc. pruefen.
//
// Revision 1.16  2003/12/15 00:03:08  gnomi
// Einige static-Funktionen privatisiert.
//
// Revision 1.15  2003/12/14 15:40:27  menaures
// Bugfix Namensabfrage bei Zweitievertrag
//
// Revision 1.14  2003/05/13 12:58:23  menaures
// Zeilen im Log waren zu lang
//
// Revision 1.13  2003/05/13 12:06:55  menaures
// Zweities nicht auf dem Gott-Kanal ankuendigen
//
// Revision 1.12  2003/05/13 02:01:05  menaures
// Zweitiegoetter nun ueber Leo
//
// Revision 1.11  2003/01/25 04:40:45  gnomi
// Typo.
//
// Revision 1.10  2002/11/20 04:16:20  gnomi
// Hinweis, wenn der Lehrling keinen Platz mehr fuer die Enzy hat.
//
// Revision 1.9  2002/04/10 05:24:14  gnomi
// Einige Variableninitialisierungen wegen Typcheck getrennt.
//
// Revision 1.8  2001/07/12 00:01:26  gnomi
// Auf die Werft ueber export.h zugreifen.
//
// Revision 1.7  2001/04/13 13:27:05  sissi
// wizinfos bei Levelaenderungen eingebaut.
//
// Revision 1.6  2001/01/24 18:58:05  freaky
// alle message() auf send_message() umgestellt.
//

#ifdef UNItopia
#include "/z/Schiffe/sys/export.h"
#endif

#include <simul_efuns.h>

#define LEHRLINGSBUCH  "/room/rathaus/obj/genesis"
#define GOETTERBUCH  "/room/rathaus/obj/goetterbuch"
#define LEHRLINGSVERTRAG "/room/rathaus/obj/lehrlingsvertrag"

//
// Teste Lehrling wird aufgerufen, um festzustellen, ob der Engel Lehrling
// werden DARF.
//
private int teste_lehrling(object ob)
{
   int miss_time, miss_time_stunden;
   string * chars;

   if(LVL_LEARNER >= BANISHD->query_banished(ob->query_real_name()))
       REJECT("sage Der oberste Rat des Pantheons moechte Dich nicht ohne"
              " seine Zustimmung in den Kreis der Goetter aufnehmen!");

   if(wizp(ob))
      REJECT("sage Du bist doch bereits ein Gott!");
   if(!hlpp(ob))
      REJECT("sage Nur Engel werden von mir in den Kreis der Goetter "
	     "aufgenommen.");
   if(testplayerp(ob))
      REJECT("sage Jetzt hast Du ein Problem, "
	     "denn als Zweitcharakter kann man nicht Gott werden!");
   if(GOETTER_REGISTER->is_wiz_on_vacation(ob->query_real_name()))
      REJECT("sage Wende Dich dazu bitte direkt an den Obersten Rat "
    	     "des Pantheons.");
   if(ob->query_moerder())
      REJECT("sage Moerder wie Du muessen sich erst von ihrer Schuld "
	     "befreien!");
   if(( miss_time = 
	 ANGEL_TIME_TO_WIZ -
         (ob->query_age()-
	  ob->query_level_ages(LVL_HLP)) ) >= 0) {
      miss_time_stunden = (miss_time/3600)+1;
      REJECT("sage Du solltest Dich erst einmal mit den Moeglichkeiten "
             "der Engel vertraut machen, um dann eine wohl ueberlegte "
             "Entscheidung treffen zu koennen. 'Gott Werden' ist nicht "
             "rueckgaengig zu machen. Goetter muessen sich an einen "
             "strengen Kodex halten, an den sich Engel und Spieler "
             "nicht halten muessen. Fuer Spieler bricht die Illusion "
             "einer wohlfunktionierenden, bluehenden Fantasiewelt "
             "zusammen, wenn sie zum Gott werden. Goetter muessen "
             "(duerfen/sollen) schwer arbeiten und sind dauernd auf der "
             "Hatz nach Fehlern. Allerdings koennen sie, anders wie die "
	     "Engel, "+MUD_NAME+" um neue Dinge erweitern. Komm doch "
	     "fruehestens zurueck, wenn Du " + miss_time_stunden +
             (miss_time_stunden==1?" Stunde":" Stunden")+
	     " aelter bist und Du Dir diese wichtige Entscheidung "
	     "gut ueberlegt hast!");
   }

   chars = PLAYER_SECOND->query_second_chars(ob->query_real_name());
   chars ||= ({});
   chars -= ({ob->query_real_name()});

   foreach(string char : chars)
   {
       if(LVL_LEARNER >= BANISHD->query_banished(char))
           REJECT("sage Der oberste Rat des Pantheons moechte Dich nicht ohne"
              " seine Zustimmung in den Kreis der Goetter aufnehmen!");

       if(GOETTER_REGISTER->is_wiz(char))
       {
           exec_command("fluestere",ob,"Du hast doch bereits "
              "einen Gottcharakter.");
           return 0;
       }

       if(sizeof(PLAYER_READER->query(char, "opfer")))
       {
           exec_command("fluestere",ob,"Mindestens einer "
              "deiner Charaktere ist ein Moerder, der sich zunaechst von "
              "seiner Schuld befreien muss.");
           return 0;
       }
   }

   return 1;
}

//
// erschaffe_lehrling wird aufgerufen, wenn alle Formularitaeten
// abgeschlossen sind, und der Lehrling gesetzt wird.
//
private void erschaffe_lehrling(object learner, string v_name,
                string erstie, string admin)
{
    object book;
    string l_name;

    // Ein ein neuer Lehrling ist geboren... let's do it.

    l_name=learner->query_real_name();

    // LEHRLING Logfile updaten
    sys_log("LEHRLING",sprintf("%s:  %-10s  (Vogt: %s)\n",
	ctime(),capitalize(l_name),capitalize(v_name)));

    if(erstie && admin)
    {
        // Mitloggen, wessen Zweities da so goettern...
        write_file("/var/intern/ZWEITIEGOETTER",
            trim(sprintf("%10s  %10-s  %10-s  %10-s  %10-s",
                shorttimestr(time(), 1, TIMESTR_ONLY_DATE),
                capitalize(erstie), capitalize(l_name),
                capitalize(v_name), capitalize(admin)
                ))+"\n");
    }

    // Player abspeichern, sodass die Daten so, wie sie waren, als
    // er Gott geworden ist, jederzeit im Falle von "will kein Gott mehr
    // sein" oder im Fall von Rauswurf wiederhergestellt werden koennen.
    learner->do_save_before_wiz();

    // Level setzen
    learner->set_level(LVL_LEARNER);

    // Lehrling-Kommandos erlauben.
    learner->define_wiz_commands();

    // Dem Goetterregister bescheid geben
    GOETTER_REGISTER->add_lehrmeister(l_name,v_name);

    // Master informieren (UID umsetzen...)
    MASTER_OB->master_create_learner(l_name);

    // Updaten der Spieler-Top-Liste
    LEVEL_LISTER->new_enter(learner);

    // Meldung an alle ausgeben. Aber nicht bei Zweities.
    if(!admin || !erstie)
        EVENT_MASTER->event("Gott", learner);

    // Titel aendern.
    switch (learner->query_gender())
    {
	case "maennlich" : 
	    learner->set_title(", der Neue im Kreis der Goetter");
	    break;
	case "weiblich"  : 
	    learner->set_title(", die Neue im Kreis der Goetter");
	    break;
	case "saechlich" : 
	    learner->set_title(", das Neue im Kreis der Goetter");
    }

    // Den Startraum des neuen Gotts auf seinen workroom setzen.
    learner->set_start_room("/w/"+l_name+"/workroom");

    // Den neuen Gott erst mal aus der Wer-Liste nehmen:
    learner->set_no_wer(1);

    // Player abspeichern.
    learner->do_save();

    // Begruessung...
    do_command("sage Willkommen im Kreis der Goetter, "+
	capitalize(l_name)+"!");

    // Belehrung
    do_command("sage Als Lehrling musst Du jetzt viel lesen und Dich "
	"umschauen. Wenn du deine Lehrzeit von ungefaehr 5 Tagen hinter Dir "
	"hast kannst Du wiederkommen, um das Programmieren zu erlernen.");

    // Einfuehrungsbuch in die Hand druecken
    book = clone_object(LEHRLINGSBUCH);
    book->move(this_object());
    give_object(book,learner);

    book=clone_object("/obj/enzyclopedia");
    if(book->move(learner,MOVE_ERR_REMOVE)==MOVE_OK)
	this_object()->send_message(MT_LOOK,MA_PUT,
	    Der()+" gibt "+dem(learner)+" "+einen(book)+".\n",
	    Der()+" gibt Dir "+einen(book)+".\n",learner);
    else
	exec_command("sage Du kannst die Enzyclopedia " MUD_NAME 
	    " nicht tragen. Hol sie Dir nachher einfach beim Kurs ab.");

    call_out("do_command",1,
	"sage Und denke daran: Folge dem EINEN Weg, dem Weg aller Goetter!");
#ifdef UNItopia
    catch(
    WERFT_BUERO->wird_gott(learner->query_real_name())
	 );
#endif
    wizinfo ("Willkommen im Pantheon, "+learner->query_real_cap_name()+"!");
}


// 
// Lehrlingsvertrag wird aufgerufen wenn, der Lehrlingsvertrag 
// bei Leo abgegeben wurde.
//
protected int lehrlingsvertrag(object ob, object woher, object to, object ti) 
{
    if (!present(ob))
	return 1;
    if(!strstr(object_name(ob), LEHRLINGSVERTRAG))
    {
	if (!ti || ti != this_player())
	    do_command("sage Du hast mir den Goettervertrag nicht aus "
		       "eigenem Willen gegeben. Deswegen ist er ungueltig.");
	else if (!ob->query_signed()) 
	    do_command("sage Mhh. Der Vertrag ist nicht unterzeichnet. "
		       "Dann halt nicht.");
	else if (ob->query_signed()!=3)
	{
	    do_command("sage Mhh. Es haben nicht beide unterzeichnet. "
		       "Dann halt nicht.");
	    return 0;
	}
	else if (this_player()->query_real_name()!=ob->query_lehrling())
	{
	    do_command("sage Mhh. Den Vertrag muss mir schon von seinem "
		       "Besitzer persoenlich uebergegeben werden.");
	    return 0;
	}
	else if (ob->query_admin() ||
                 teste_lehrling(this_player()))
	    erschaffe_lehrling(this_player(), ob->query_vogt(),
                ob->query_erstie(), ob->query_admin());
	ob->remove();
	return 1;
    }
}


//
// response_lehrling wird aufgerufen, wenn der Lehrling etwas geantwortet
// hat.
//
protected void response_lehrling(string answer)
{
   object vo, ob;
   mixed *pars;

   if(this_player()->query_real_name() == lehrling)
      switch(lehrmeister)
      {
	 case 1:
	      if(!sizeof(regexp(({lower_case(answer)}),"\\<ja\\>")))
	      {
		 do_command("sage Nun gut. Dann suche weiter, "
			"oder gib mir das Buch zurueck.");
		 lehrmeister = 0;
		 lehrling = 0;
	      }
	      else
	      {
		 do_command("sage Wer soll Dein Lehrmeister sein?");
		 lehrmeister=2;
	      }
	      return;
	case 2:
	     pars=parse_com(answer,environment());
	     if (!pars[PARSE_NUM_OBS])
	     {
		do_command("sage "+capitalize(answer)+
			" ist aber gar nicht hier.");
		break;
	     }
	     vo=pars[PARSE_OBS][0];
	     if (!vogtp(vo))
	     {
		do_command("sage "+Der(vo)+" ist aber kein Vogt.");
		break;
	     }
	     do_command("sage Aha. "+vo->query_cap_name()+" also.");
	     do_command("sage Ich hoffe Du wirst gut auf "+
		this_player()->query_cap_name()+" aufpassen, und "+
		ihm(this_player())+" helfen.");
	     ob=clone_object(LEHRLINGSVERTRAG);
	     ob->set_vogt(vo->query_real_name());
	     ob->set_lehrling(lehrling);
	     do_command("sage Wenn Du dazu bereit bist, dann unterschreibe "
		+den(ob)+".");
	     ob->move(this_object());
	     give_object(ob,vo);
	 default:
	    lehrmeister = 0;
	    lehrling = 0;
      }
}

//
// lehrling wird aufgerufen, wenn der Engel darum bittet, Goetter-
// lehrling zu werden.
//
void lehrling(string str)
{
   object ob;

   if(strstr(str," kein ")>=0 || strstr(str," nicht ")>=0)
   {
     if(wizp(this_player()))
       exec_command("sage Hmm. Das haetten wir uns wohl vorher ueberlegen sollen.");
     else
       exec_command("sage Schoen. Dann bleib einfach wie du bist.");
     return;
   }

   do_command("sage Hinweise zur Gottwerdung sind in der betretbaren Nische "
              "dort unter der Treppe zu finden.");
   
   if(!teste_lehrling(this_player()))
      return;

   if(present("goetterbuch",this_player()))
   {
      do_command("sage Ahh. Da bist Du ja wieder.");
      do_command("frage Und? Hast Du einen Lehrmeister gefunden ");
      lehrmeister = 1;
      lehrling = this_player()->query_real_name();
      return;
   }

   do_command("sage Dieser Schritt muss wohl ueberlegt sein.");
   do_command("sage Damit Du Dich besser entscheiden kannst, gebe ich "
	"Dir ein Buch mit, in dem alles ueber das Goetterdasein steht. "
	"Lese es mit Sorgfalt durch und praege Dir alles genau ein.");
   do_command("sage Wenn Du Dich dann entschieden hast, suche eine Voegtin "
	"oder einen Vogt mit Lizenz zum Ausbilden, damit Du einen "
        "Ansprechpartner fuer alle Deine Fragen hast, die Du auf Deinem "
        "Weg zum Programmieren haben wirst.");
   do_command("sage Dein Lehrmeister muss dann mit Dir wieder hierherkommen, "
	"und den Goettervertrag unterschreiben.");
   ob = clone_object(GOETTERBUCH);
   ob->move(this_object());
   ob->set_owner(this_player()->query_real_name());
   give_object(ob,this_player());
   do_command("sage Also bis dann, und bringe mir das Buch zurueck.\n");
}

//
// --- Zusaetzliche Funktionen fuer Zweitiegott: ---
//

//
// Prueft die Anwesenheit des Admins
//
private int admin_anwesend(object who)
{
    return objectp(who) && adminp(who) && environment(who) == environment()
           && who == this_player();
    // Check auf TI wegen call_out() nicht moeglich
}

//
// Wird zum Pruefen von Namen verwendet
//
private int teste_zweitie(object who, string name)
{
    if(admin_anwesend(who))
    {
        if(!stringp(name) || !player_exists(name))
        {
            exec_command("fluestere", who, "Diesen Spieler kenne "
                "ich ja gar nicht.");
            return 0;
        }

        else if(SECOND->is_testplayer(name))
        {
            exec_command("fluestere", who, "Testies koennen keine Zweitie"
                "goetter werden.");
            return 0;
        }

        string * chars = PLAYER_SECOND->query_second_chars(name);
        chars ||= ({name});

        foreach(string char : chars)
        {
            // Gott & Testie und Banish abfangen
            if(LVL_LEARNER >= BANISHD->query_banished(char))
            {
                exec_command("fluestere", who, "Tut mir leid, aber dieser "
                    "Spieler ist gebanished! ("+char+")");
                return 0;
            }

            else if(GOETTER_REGISTER->is_wiz(char))
            {
                exec_command("fluestere", who, "Das ist doch bereits ein "
                    "Gott. ("+char+")");
                return 0;
            }

            else if(sizeof(PLAYER_READER->query(char, "opfer")))
            {
                exec_command("fluestere", who, "Das ist ein Moerder. ("
                    +char+")");
                return 0;
            }
        }

        exec_command("nicke", who);
        return 1;
    }
}

//
// Leo fragt den Admin nach dem Namen des Lehrmeisters
//
private void name_lehrmeister(string str, object who,
                             string erstie, string zweitie)
{
    str = str && lower_case(str);

    if(admin_anwesend(who))
    {
        // Auf Existenz und Gott pruefen
        if(!stringp(str) || !player_exists(str) ||
           !GOETTER_REGISTER->is_wiz(str))
        {
            exec_command("fluestere", who, "Diesen Gott kenne ich ja "
                "gar nicht.");
            return;
        }

        // Auf Lehrmeister pruefen
        if(!GOETTER_REGISTER->query_lehrerlaubnis(str))
        {
            exec_command("fluestere", who, "Dieser Vogt hat noch keine "
                "Lehrerlaubnis.");
            return;
        }

        // Vertrag klonen:
        object ob;

        ob = clone_object(LEHRLINGSVERTRAG);
        ob->set_admin(who->query_real_name());
        ob->set_erstie(erstie);
        ob->set_lehrling(zweitie);
        ob->set_vogt(str);

        if(ob->move(who) == MOVE_OK)
        {
            exec_command("fluestere", who, "Okay, ich habe dir einen "
                "Vertrag zugesteckt, der jetzt nur noch von "+
                capitalize(zweitie)+" und "+capitalize(str)+
                " mit einer Unterschrift versehen werden muss. "
                "Wenn mir "+capitalize(zweitie)+" dann den unterzeichneten "
                "Vertrag gibt, kuemmere ich mich um den Rest.");
        }

        else
        {
            ob->remove();
            destruct(ob);

            exec_command("wuete");
            exec_command("fluestere", who, "Du hast keinen Platz frei. "
                "Sorry, aber ich musste den Vertrag wieder zerstoeren.");
        }
    }
}

//
// Leo fragt den Admin nach dem Namen des Zweities
//
private void name_zweitie(string str, object who, string erstie)
{
    str = str && lower_case(str);

    if(teste_zweitie(who, str))
    {
        input_to(#'name_lehrmeister, INPUT_PROMPT, "Name des Lehrmeisters: ",
                 who, erstie, str);
    }
}

//
// Leo fragt den Admin nach dem Namen des Ersties
//
private void name_erstie(string str, object who)
{
    str = str && lower_case(str);

    if(teste_zweitie(who, str))
    {
        input_to(#'name_zweitie, INPUT_PROMPT, "Name des Zweities: ",
                 who, str);
    }
}

//
// zweitie wird aufgerufen, wenn ein Admin Leo das Wort Zweitie
// zufluestert. Der Admin kann so einen Zweitievertrag verlangen.
//
static void zweitie(string str)
{
    exec_command("emote schaut sich vorsichtig um.");

    if(admin_anwesend(this_player()))
    {
        exec_command("fluestere", this_player(), "Du moechtest einem "
            "Spieler erlauben, mit seinem Zweitie Gott zu werden? "
            "Dann brauche ich von Dir die Namen des Ersties und des "
            "Zweities, sowie den des Lehrmeisters.");

        input_to(#'name_erstie, INPUT_PROMPT,
    	    "Name des Ersties: ", this_player());

        return;
    }

    exec_command("fluestere", this_player(), "Solltest du planen, "
        "mit einem Zweitie hier Gott zu werden, wende dich an einen "
        "Admin. Du solltest dazu allerdings bereits ein erfahrener "
        "Engel sein...");
}
