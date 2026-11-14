/* Tamedhon MUDlib
 * Querolin
 *
 * Date: 2004/02/16 
 * Revision: 1.0 
 *
 */

#pragma strong_types

#include "/secure/master.h"
#include "properties.h"

#define RUBRIK "chronik"
#define PROVIDER "TDP"
#define ADMIN "querolin"

// #define MSG_FROM 0
// #define MSG_SENDER 1
// #define MSG_RECIPIENT 2
// #define MSG_CC 3
// #define MSG_BCC 4
// #define MSG_SUBJECT 5
// #define MSG_DATE 6
// #define MSG_ID 7
// #define MSG_BODY 8


mixed* liste;  // ({ "wer", "von", "datum" })
string* eintragung_entfernen;

void save_me() { save_object("/etc/scheidungsmaster"); }

int pl_exists(string str)
{
        string *fd;

        if(!str) return 0;
        fd=0; str=lowerstring(str);
        fd=get_dir("/save/"+str[0..0]+"/"+str+".o");

        return sizeof(fd);
}



void create()
{
    seteuid(getuid());
    if(!restore_object("/etc/scheidungsmaster"))
    {
       eintragung_entfernen=({});
       liste=({});
    }
}

void reset()
{
    int i; 
    mixed* temp_liste;
    object ob;

    if (sizeof(liste))
    {
      temp_liste=({});
      for(i=0;i<sizeof(liste);i++)
      {
         // 2592000 == 30 Tage in Sekunden
         if ( ( to_int(liste[i][2]) + 2592000 ) <  time() )
         {
            eintragung_entfernen+=({ liste[i][0] });
            eintragung_entfernen+=({ liste[i][1] });
            ob=find_player(lower_case(liste[i][0]));
            if (ob) { this_object()->_login_check(ob); }
            ob=find_player(lower_case(liste[i][1]));
            if (ob) { this_object()->_login_check(ob); }
            // Und noch Hinausposaunen... 
            this_object()->_bekanntgabe(2, liste[i][0], liste[i][1] );
         }
         else
         {
            temp_liste=({ ({ liste[i][0], liste[i][1], liste[i][2] }) });
         }
      }
    liste=temp_liste;
    }
    
    save_me();
}

int _beantragen(object wer, string von)
{
   // Wer geschieden werden will kommt zuerst hierein.
   // Nur durch diese Funktion wird man aufgenommen und geprueft!

   object ob;

   if (!find_player(lower_case(wer->name()))) return 2;

   if (wer->QueryProp(P_MARRIED) == 0) return 3;
   if (wer->QueryProp(P_MARRIED) == "geschieden") return 3;

   TO->SendMail1(TP->Name(), capitalize(von));
   liste+=({ ({ wer->Name(), capitalize(wer->QueryProp(P_MARRIED)), time() }) });
   save_me();
   return 1;
}

void SendMail(string name1, string name2)
{
   mixed* mail, mail1;
   string text;

   text =
   "Guten Tag!\n\n"+
   break_string("Mit sofortiger Wirkung erklärt das Tamedhonsche Gericht "+
   "hiermit offiziell die Scheidung von " + capitalize(name1) + " und " +
   capitalize(name2)+".", 78) + "\n"+
   "Beide Partner sind von nun an wieder unabhängig und dürfen\n"+
   "des Weiteren ab sofort neue Ehegelübde ablegen.\n\n"+
   "Hochachtungsvoll\n\ni.A. des Gerichtes\nDer Gerichtsschreiber\n"
   "Tamedhonscher Gerichtshof\n\n";

   if (pl_exists(name1))
   {
   mail = allocate(9);
   mail[MSG_FROM] = "Tamedhonscher Gerichtshof";
   mail[MSG_SENDER] = MUDNAME;
   mail[MSG_RECIPIENT] = name1;
   mail[MSG_CC]=0;
   mail[MSG_BCC]=0;
   mail[MSG_SUBJECT]="Die Scheidung von "+CAP(name1)+" und "+CAP(name2);
   mail[MSG_DATE]=dtime(time());
   mail[MSG_ID]=MUDNAME+":"+time();
   mail[MSG_BODY]=text;
   "/secure/mailer"->DeliverMail(mail,1);
   }

   if (pl_exists(name2)) 
   {
   mail1 = allocate(9);
   mail1[MSG_FROM] = "Tamedhonscher Gerichtshof";
   mail1[MSG_SENDER] = MUDNAME;
   mail1[MSG_RECIPIENT] = name2;
   mail1[MSG_CC]=0;
   mail1[MSG_BCC]=0;
   mail1[MSG_SUBJECT]="Die Scheidung von "+CAP(name1)+" und "+CAP(name2);
   mail1[MSG_DATE]=dtime(time());
   mail1[MSG_ID]=MUDNAME+":"+time();
   mail1[MSG_BODY]=text;
   "/secure/mailer"->DeliverMail(mail1,1);
   }
   return;
}

void SendMail1(string name1, string name2)
{
   mixed* mail, mail1;
   string text;

   if (!pl_exists(name2)) return;

   text =
   "Guten Tag!\n\n"+
   break_string("Am Tamedhonschen Gerichtshof ist ein Antrag "+
   "auf Anullierung der Ehe "+
   "von " + capitalize(name1) + " und " +
   capitalize(name2)+" eingegangen.", 78) + "\n"+
   "Sollten Sie dieser Scheidung zustimmen wollen, so suchen Sie\n"+
   "bitte den dafür zuständigen Anwalt in Bronwar auf.\n\n"+
   "Alternativ wird die Scheidung auch ohne Ihr Einverständnis in\n"+
   "etwa einem Monat anulliert.\n\n"+
   "Hochachtungsvoll\n\ni.A. des Gerichtes\nDer Gerichtsschreiber\n"+
   "Tamedhonscher Gerichtshof\n\n";

   mail = allocate(9);
   mail[MSG_FROM] = "Tamedhonscher Gerichtshof";
   mail[MSG_SENDER] = MUDNAME;
   mail[MSG_RECIPIENT] = name2;
   mail[MSG_CC]=0;
   mail[MSG_BCC]=0;
   mail[MSG_SUBJECT]="Antrag auf Scheidung von "+CAP(name1)+" und "+CAP(name2);
   mail[MSG_DATE]=dtime(time());
   mail[MSG_ID]=MUDNAME+":"+time();
   mail[MSG_BODY]=text;
   "/secure/mailer"->DeliverMail(mail,1);

   return;
}



int _scheiden(object wer)
{
   string von;
   object ob;
   mixed* templiste;
   int i;

   // Sobald die Scheidung vollstreckt wird (ablauf der Zeit oder Zustimmung)
   // wird diese Funktion aufgerufen!

   if (!find_player(lower_case(wer->name() )) ) return 0;

   if (wer->QueryProp(P_MARRIED)==0) return 0;

   if (wer->QueryProp(P_MARRIED)=="geschieden") return 0;

   von=wer->QueryProp(P_MARRIED);
   if (pl_exists(von))
   {
      // Spieler als geschieden markieren...
      wer->SetProp(P_MARRIED, "geschieden");
 
      // Partner suchen und auch markieren, oder eintragen in loeschliste!
      ob=find_player(lower_case(von));
      if (ob)
      {
         if (ob->QueryProp(P_MARRIED)==wer->Name())
         {
            ob->SetProp(P_MARRIED, "geschieden");
         }
      }
      else
      {
         // Wird der Scheidungspartner nicht sofort gefunden,
         // dann kommt er in die Liste...
         eintragung_entfernen+= ({ capitalize(von) });         
      }

      // Scheidung bekanntgeben.
      TO->_bekanntgabe(1, wer->name(), von );
      
      // Noch aus der Liste entfernen...
      templiste=({});
      for(i=0;i<sizeof(liste);i++)
      {
          if ( (von != liste[i][0] ) && (von != liste[i][1] ) )
          {
              templiste+=({ ({liste[i][0], liste[i][1], liste[i][2] }) });
          }
      }
      liste=({});
      liste=templiste;
      save_me();
   }
   return 1; 
}

int _zustimmung(object wer)
{
  object von, ob;
  int i;

  // Der zweite Ehepartner kann der Scheidung zustimmen - 
  // oder das Zeitlimit loest die Zustimmung aus

  if (!sizeof(liste)) return 6;

  if (!find_player(lower_case(wer->name() )) ) return 4;

  if (wer->QueryProp(P_MARRIED)==0) return 5;

  for(i=0;i<sizeof(liste);i++) 
  {
    //tell_object(find_player("querolin"),
    //   break_string("Liste: "+liste[i][0]+" : "+liste[i][1]+".\n"));
    if ( liste[i][1] == wer->Name() )
    {
       // Sind denn die beiden auch verheiratet???
       if ( wer->QueryProp(P_MARRIED) != liste[i][0] )
       {
          return 3;
       }

       // Okay - nun die Scheidung durchfuehren!
       // tell_object(find_player("querolin"),break_string("Okay - Scheidung.\n"));
       call_out("_scheiden", 1 ,wer);
       return 1;
    }
  }

  // Nicht in der Liste - hat der falsche Partner zugestimmt ;) ?
  return 2;
}

int _login_check(object wen)
{
   int i;
   string* neue_eintragungsliste;
   if (!find_player(lower_case(wen->name()))) return 1;

   if ( sizeof(eintragung_entfernen) == 0 ) return 1;
   neue_eintragungsliste=({});

   for(i=0;i<sizeof(eintragung_entfernen);i++)
   {
       if (eintragung_entfernen[i] == wen->Name() )
       {
           wen->SetProp(P_MARRIED, "geschieden");
       }
       else
       {
          // Erneut reihen...
          if (pl_exists(eintragung_entfernen[i]))
          {
             // Gibts den Player nicht mehr, dann braucht er auch 
             // nicht mehr geschieden werden...
             neue_eintragungsliste+=({ eintragung_entfernen[i] });
          }
       }
   }
   eintragung_entfernen=({});
   eintragung_entfernen=neue_eintragungsliste;
   save_me();
   return 1;
}

int _finger_check(string wer)
{
   int i;

   // Wurde die Ehe geschieden, aber noch nicht am Spieler vollzogen?
   if (sizeof(eintragung_entfernen)==0) return 0;
   if (!wer) return 0;

   for (i=0;i<sizeof(eintragung_entfernen);i++)
   {
       if (lower_case(wer) == lower_case(eintragung_entfernen[i]))
       {
          return 1;
       }
   }
   return 0;
} 


int _bekanntgabe(int wie, string wer, string von)
{
  // wie: 1=durch zustimmung - 2=durch zeitablauf.

  mixed *art;
  string text;
  int i;

//  tell_object(find_player("bort"),break_string("Aufruf bekanntgabe Scheidungsmaster: "+wer+" : "+von+".\n"));
//  return 1;

  if (wie == 0) return 0;

  if (wie == 1 || wie == 2)
  {
  TO->SendMail(wer, von);
  text ="Der Tamedhonsche Gerichtshof gibt mit sofortiger Wirkung\n"
        "die Scheidung von "+capitalize(wer)+" und "+capitalize(von)+
        " bekannt.\n\nGegen diesen Bescheid gibt es kein Rechtsmittel.\n"
        "Beide Parteien wurden durch postalische Zustellung von diesem\n"
        "Beschluss informiert.\n\nIm Auftrag des Tamedhonschen Gerichtshofes\n\n"
        "Der Gerichtsschreiber";

  art = ({ RUBRIK, "Tamedhonscher Gerichtshof", 0, 0,
      sprintf("%s und %s gehen ab heute getrennte Wege...",capitalize(wer),
       capitalize(von)), text });

//    NEWSSERVER->WriteNote(art,1);

    if ( (NEWSSERVER->WriteNote(art,1) > 0) ||
         ( (NEWSSERVER->RemoveNote(RUBRIK,0) > 0) &&
           (NEWSSERVER->WriteNote(art,1) > 0) ) )
    { }
    else if (find_player(ADMIN))
      tell_object(find_player(ADMIN),
          "[Scheidung:] Fehler bei Posten eines Artikels, bitte prüfen!\n");

  }

  call_other("/obj/infomaster", "InfoMsg",
      wer+" und "+von+" gehen ab heute getrennte Wege.");

  log_file("SCHEIDUNG",sprintf("%s: %s und %s\n",
    ctime(time()),
    capitalize(wer), capitalize(von)));
  return 1;
} 
