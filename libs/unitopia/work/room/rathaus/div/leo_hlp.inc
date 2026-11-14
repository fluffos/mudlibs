// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/room/rathaus/div/leo_hlp.inc
// Description:	Teil von Leo, der das Engelwerden regelt.
// Author:	Garthan
// Modified by: Nethar (16.09.01) Wahlraetsel eingefuegt
//	
//
// $Log: leo_hlp.inc,v $
// Revision 1.13  2008/01/16 09:46:04  gnomi
// INPUT_PROMPT verwenden.
//
// Revision 1.12  2005/02/02 23:50:30  gnomi
// Testet die Pflichtraetsel nun auf min_skill_solved.
//
// Revision 1.11  2003/12/15 00:03:08  gnomi
// Einige static-Funktionen privatisiert.
//
// Revision 1.10  2003/02/02 03:17:30  gnomi
// Basilika -> Kathedrale.
//
// Revision 1.9  2002/09/08 10:21:51  sissi
// Mitglieder der Orkgilde koennen keine Engel werden.
//
// Revision 1.8  2002/03/18 03:46:36  gnomi
// Falsche Meldung bei Ablehnung der Engelswerdung.
//
// Revision 1.7  2001/12/10 21:49:19  gnomi
// Stueck -> Abenteuer. (Ist zwar eine Wiederholung, aber besser als 'Stueck'.)
//
// Revision 1.6  2001/11/21 20:07:38  sissi
// Anforderungen fuers Engelwerden auf 75er Stats reduziert.
//
// Revision 1.5  2001/09/16 19:33:54  sissi
// Wahl-Pflicht-Raetsel eingefuehrt (Nethar)
//
// Revision 1.5  2001/09/13 14:00:00  nethar
// Wahlraetsel eingefuegt
//
// Revision 1.4  2001/03/31 22:52:08  sissi & gnomi
// Keine Engelswerdung mehr.
//
// Revision 1.3  2001/01/24 18:58:05  freaky
// alle message() auf send_message() umgestellt.
//

//
// teste_engel wird aufgerufen, um zu pruefen ob eine Spieler Engel werden 
// darf.
//
private int teste_engel(object ob)
{
   int a, sum_stat, sum_real_stat, count;
   object *quests, *choice_quests, shad;

#ifdef PLAYER_DAY
   if(ob->player_day())
      REJECT("sage Nicht in diesem Monat!");
#endif
   if(LVL_HLP >= BANISHD->query_banished(ob->query_real_name()))
      REJECT("sage DU nicht!");
   if(guestp(ob))
      REJECT("sage Ein Gast kann das nicht!");
#ifdef UNItopia
   if(ob->query_gilde()=="Orkgilde") {
     do_command("wundere");
     do_command("schuettle Kopf");
     do_command("sage Du glaubst doch nicht im Ernst, dass Orks in den Himmel "
        "kommen und ihnen Fluegel wachsen? Nene.");
     exec_command("taetschle",this_player());
     return 0;
   }
#endif
   if(hlpp(ob))
      REJECT("sage Du bist doch bereits ein Engel!");
   if(wizp(ob))
      REJECT("sage Du bist doch bereits ein Gott!");
   if (ob->query_moerder())
      REJECT("sage Moerder wie Du muessen sich "
	     "erst von ihrer Schuld befreien!");
   if(ob->query_sum_skill() < TOTAL_EXPERIENCE)
      REJECT("sage Du hast noch nicht genuegend Erfahrung "
	     "fuer diesen Schritt!");
   if(sizeof(quests = QUEST_ROOM->query_quests(Q_NECESSARY)) <= 0)
      REJECT("sage Sorry, ohne installierte Raetsel kann niemand "
		 "in die Engelsschar aufgenommen werden!");
   
   if(sizeof(choice_quests = QUEST_ROOM->query_quests(Q_WAHL)) <= 0)
      REJECT("sage Sorry, ohne installierte Wahlraetsel kann niemand "
         "in die Engelsschar aufgenommen werden!");
   
   // Pflichties
   for(count = 0, a = sizeof(quests); a--;)
      if(!QUEST_ROOM->quest_min_solved(quests[a], ob))
         count++;
   if(count)
      REJECT("sage Du musst erst alle Abenteuer der rechten Tafel "
             "loesen!");  
   
   // Wahlraetsel
   for(count = 0, a = sizeof(choice_quests); a--;)
      if(QUEST_ROOM->quest_min_solved(choice_quests[a], ob))
         count++;
   if(count < NEEDED_CHOICE_QUESTS)
      REJECT("sage Du musst mindestens "+NEEDED_CHOICE_QUESTS+
             " Abenteuer der linken Tafel bestehen! "+
             (NEEDED_CHOICE_QUESTS-count)+" Abenteuer "+
             ((NEEDED_CHOICE_QUESTS-count)==1 ? "fehlt " : "fehlen ")+
             "Dir also noch.");

   for(a=0; a<STAT_NUMBER; a++)
      sum_stat += ob->query_stat(a);
   for(a=0; a<STAT_NUMBER; a++)
      sum_real_stat += ob->query_real_stat(a);
   if(sum_real_stat/STAT_NUMBER < 75)
   {
      do_command("sage Deine Faehigkeiten sind fuer diesen Schritt "
	         "noch nicht hoch genug!");
      if(sum_stat/STAT_NUMBER >= 75)
         do_command("sage Auch wenn das so scheinen mag!");
      else
      if(sum_stat != sum_real_stat)
         do_command("sage Da helfen auch Magie und andere Tricks nichts!");
      return 0;
   }
   return 1;
}

private void tell_him()
{
   do_command("sage Man spricht in Tadmor von Engeln, die des oefteren "
	      "um die Kirchtuerme der Kathedrale kreisen und elegant ueber "
	      "den Kartukultininurtaplatz gleiten. Vielleicht solltest Du "
	      "dort Dein Glueck suchen?");
}

//
// erschaffe_engel wird aufgerufen, wenn alle Formularitaeten
// abgeschlossen sind, und der Engel gesetzt wird.
//
private void erschaffe_engel(string str)
{
    object book;
    if(!str || lower_case(str) != "ja")
    {
        this_player()->send_message(MT_NOISE,MA_COMM,
	    wrap_say(Der(this_player())+" sagt:",str));
        do_command("sage Wie Du meinst, das sollte auch gut ueberlegt sein.");
        return;
    }
    this_player()->send_message(MT_NOISE,MA_COMM,
	    Der(this_player())+" sagt: Ja.\n");

    // Ein ein neuer Engel ... let's do it.

    // Level setzen
    this_player()->set_level(LVL_HLP);

    // GOETTER Logfile updaten
    sys_log("ENGEL",timestr(time())+": "+
	    capitalize(this_player()->query_real_name())+".\n");

    // Meldung an alle ausgeben.
    touch(EVENT_MASTER)->event("Gott", this_player(), 0, 1);

    // Titel aendern.
    switch(this_player()->query_gender()) {
	case "weiblich":
	    this_player()->set_title(", die Neue in der Engelsschar");
	    break;
	case "maennlich":
	    this_player()->set_title(", der Neue in der Engelsschar");
	    break;
	default:
	    this_player()->set_title(", das Neue in der Engelsschar");
	}

    // Player abspeichern.
    this_player()->do_save();

    this_player()->set_mmsg_out(
       "$Der() erhebt sich in die Luft und fliegt davon");
    this_player()->set_mmsg_in(
       "$Ein() fliegt heran und landet elegant neben Dir");

    // Begruessung...

    this_object()->send_message(MT_LOOK,MA_MAGIC,wrap(
       "Leo hebt die Arme und spricht einen sehr komplizierten Zauber auf "+
       den(this_player())+"."),
       wrap(
       "Leo hebt die Arme und spricht einen sehr komplizierten Zauber auf "+
       "Dich."), this_player());
    do_command("sage Engel "+this_player()->query_cap_name()+", "
       "Deine Aufgabe ist es nun, Lyrion den Schutzengel auf seiner Wolke "
       "im Himmel aufzusuchen!");
    call_out(#'tell_him, 2);
}

//
// engel wird aufgerufen, wenn der Spieler darum bittet, Engel zu werden.
//
void engel(string str)
{
   if(strstr(str," kein ")>=0 || strstr(str," nicht ")>=0)
   {
     if(wizp(this_player()))
       exec_command("sage Du brauchst auch nicht Engel werden, denn "
         "wie du vielleicht schon mitbekommen hast, bist du ein Gott.");
     else if(hlpp(this_player()))
       exec_command("sage Hmm. Das haetten wir uns wohl eher ueberlegen sollen.");
     else
       exec_command("sage Schoen. Dann bleib einfach wie du bist.");
     return;
   }
   if(!teste_engel(this_player()))
      return;

   do_command("sage Nun gut. Bist Du bereit fuer diesen bedeutungsvollen "
	       "Schritt? So antworte mit ja oder nein, Sterblich"+
	      (this_player()->query_gender()=="weiblich"?"e":"er")+"!");
   input_to(#'erschaffe_engel, INPUT_PROMPT, "[ja/nein] ? ");
}
