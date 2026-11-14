/* Der Last-Seen-Master - wer hat wen zuletzt gesehen.
 * Querolin@Tamedhon 29.07.2008
 *
 * Verwendung ausserhalb des Tamedhons nur mit schriftlicher Erlaubnis
 * des Autors und auf eigene Gefahr.
 */

/*
    Eingetragen in:
*/


#pragma strong_types

#include <properties.h>

#define SAVEFILE	"/etc/lastseen.db"
#define DB(x)          if(find_player("querolin")) \
                            tell_object(find_player("querolin"), \
                            break_string("LSM:"+x+".\n", 78));

mixed	*database;

/* --- Hilfsfunktionen ------------------------------------------------- */
void save_me() { save_object(SAVEFILE); }

int lsm_seen(object wer, object wen)
{
    int i,r;
    int wann;

    // Wer darf denn ueberhaupt gefragt werden...
    // Wir wollen ja keine auskunftgebenden Hasen...
    r=0;
    switch( wer->QueryProp(P_RACE) ) {
      case "Mensch": r=1; break;
      case "Ork": r=1; break;
      case "Zwerg": r=1; break;
      case "Dämon": r=1; break;
      case "Troll": r=1; break;
      case "Elf": r=1; break;
      case "Hobbit": r=1; break;
      case "Fee": r=1; break;
      case "Brownie": r=1; break;
    }
    if (r==0) 
    { 
       return -2;
    }

    if (!find_player(lower_case(wen->Name()))) return -1;
//    DB(wen->Name()+" gesehen von "+to_string(wer));
    wann=time();
    if (sizeof(database)) 
    {
        //Aktualisieren...
        for(i=0;i<sizeof(database);i++) {
          if (database[i][0]==to_string(wer) &&
              database[i][1]==wen->Name()) {
                database[i][2]=wann;
                return 2;
          }
        }
    }
    
    //Neu eintragen...
    database+=({ ({to_string(wer),wen->Name(),wann}) });
    return 1;
    
}

int __aufraeumen()
{
   mixed dbneu;
   int i;
 
   if (!sizeof(database)) return -1;
   dbneu=({});
   for(i=0;i<sizeof(database);i++) {
    
      if ((time() - database[i][2]) < 14390)
      {
         dbneu+=({ ({ database[i][0], database[i][1], database[i][2]}) });
      }
   }
   database=dbneu;
   this_object()->save_me();
 return 1;
}

string lsm_last(object wer, string wen)
{
   int i,r;
   string str,wann,jetzt, plyr;
   wen=capitalize(lower_case(wen));
   plyr=this_player()->Name();
//   DB(wer->Name()+";"+wen+";"+plyr+".\n");

   this_object()->__aufraeumen();

    r=0;
    switch( wer->QueryProp(P_RACE) ) {
      case "Mensch": r=1; break;
      case "Ork": r=1; break;
      case "Zwerg": r=1; break;
      case "Dämon": r=1; break;
      case "Troll": r=1; break;
      case "Elf": r=1; break;
      case "Hobbit": r=1; break;
      case "Goblin": r=1; break;
      case "Brownie": r=1; break;
    }
    if (r==0)
    {
       return 0;
    }


   if (wen == capitalize(lower_case(plyr)))
   {
       return "meint: Aber Du stehst doch grade vor mir??? ";
   }

   if (wer->Name() == capitalize(lower_case(wen))) { return 0; }

   if (present(lower_case(wen), environment(wer)))
   {
      return "antwortet: Ähm - schau doch mal neben Dir??? ";
   }

   if (!sizeof(database)) return "sagt: "+wen+
                                 " habe ich lange nicht mehr gesehen...";

   for(i=0;i<sizeof(database);i++) {
      str=capitalize(wen)+" habe ich leider nicht gesehen.";
      if (database[i][0]==to_string(wer) &&
          database[i][1]==wen) 
      {
         switch(time() - database[i][2]) {
          case 0 .. 30:
            str=wen+" lief doch grade eben erst hier vorbei. ";
            break;
          case 31 .. 60:
            str="Ich habe "+wen+" erst vor kurzem hier gesehen. ";
            break;
          case 61 .. 180:
            str=wen+" war vor einigen Minuten hier bei mir. ";
            break;
          case 181 .. 300:
            str=wen+" habe ich vor einiger Zeit hier gesehen. ";
            break;
          case 301 .. 600:
            str="Vor etwas längerer Zeit hat "+wen+" hier vorbeigeschaut. ";
            break;
          case 601 .. 1800:
            str="Es ist schon länger her, dass ich "+wen+" gesehen habe. ";
            break;
          case 1801 .. 3600:
            str=wen+" war vor ganz langer Zeit hier bei mir. ";
            break;
          case 3601 .. 14400:
            str=wen+" war vor einigen Stunden mal hier. ";
            break;
          default: 
            str="Ich kann mich momentan nicht erinnern "+wen+" überhaupt "
                "gesehen zu haben. ";
         }
         return "antwortet: "+str;
      }
   }
return "";
}

int __show_count()
{
   return sizeof(database);
}

/* --- Standardfunktionen ---------------------------------------------- */
void reset()
{
    this_object()->__aufraeumen();

    save_me();
}

void create()
{
    seteuid(getuid());
    if(!restore_object(SAVEFILE))
    {
	database=({});
    }
}
