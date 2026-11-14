// Xorgan@SilberLand
// Aufstieg.h fuer aufstieg[1-5].c
// 2002-01-12

#include "../def.h"

#define MAX_ROOM 6

inherit "std/room";

int kreide = 0;

void create()
{
   ::create();
   
   SetProp( P_INT_SHORT, "In einer gefaehrlichen Steilwand" );
   SetProp( P_INT_LONG,
      "Du haengst in einer gefaehrlichen Felswand. Das Gestein ist rauh und "
      "hat einige Risse." );
   SetProp( P_LIGHT, 1 );
   SetProp( P_INDOORS, 0 );
   SetProp(P_ENVIRONMENT, ([ENV_TEMPERATURE: 15, ENV_TERRAIN: TT_MOUNTAIN]) );
   SetProp(P_KILL_NAME, "Eine Sturz aus einer gefaehrlichen Felswand");

   AddDetail( ({ "felswand", "wand" }),
      "Eine beinahe ueberhaengende Felswand. Unter Dir gehts abwaerts und "
      "ueber Dir steil bergauf.");

   AddDetail( ({ "gestein" }),
      "Ein rauher von Rissen, Furchen und Hohlraeumen durchzogenes Gestein.");

   AddDetail( ({ "riss", "risse", "spalten", "spalte" }),
      "Einge Risse und Spalten durchziehen den Fels. Zum Klettern sind sie unglaublich "
      "hilfreich, sofern man bei der Schwierigkeit der Wand von hilfreich "
      "sprechen kann.");
   
   AddDetail( ({ "klettern" }),
      "Das solltest sehr gut koennen. Vielleicht hast ja ein paar "
      "nuetzliche Hilfsmittel dabei.");
   
   AddDetail( ({ "schwierigkeit" }),
      "Die Wand ist unglaublich schwierig. Zwar bieten die Risse guten Halt, "
      "jedoch ist die Wand extrem steil,teilwese sogar ueberhaengend, und "
      "der Fels ist sehr bruechig, womit es jeder Zeit zu einem Felssturz "
      "kommen kann.");
   
   AddDetail( ({ "zeit" }),
      "Du hast keine Zeit zu verlieren. Du solltest schnellstens weiter "
      "klettern.");
   
   AddDetail( ({ "felssturz" }),
      "Hoffentlich erwischt Dich keiner, denn das waere auf jeden Fall Dein "
      "Ende.");
   
   AddDetail( ({ "fall" }),
      "Wenn Du von einen Felsen getroffen wirst, ist ein Absturz nicht zu "
      "verhindern.");
   
   AddDetail( ({ "absturz" }),
      "Den willst Du bestimmt nicht erleben.");
   
   AddDetail( ({ "ende" }),
      "Noch gibt es Hoffnung, dass Du dieses Abenteuer ueberlebst.");
   
   AddDetail( ({ "hoffnung" }),
      "Bald hilft auch hoffen und beten nicht mehr.");
   
   AddDetail( ({ "abenteuer", "kletterabenteuer" }),
      "Langsam aber sicher wird dieses Kletterabenteuer extrem gefaehlich.");
   
   AddDetail( ({ "hilfsmittel", "ausruestung" }),
      "Als Hilfsmittel zum Klettern eignen sich in dieser Wand: "
      "Seile, Kletterhaken, Kreidenstaub, Bergschuhe, Schutzhelm");
   
   AddDetail( ({ "seil", "kletterhaken", "kreidenstaub", "bergschuhe", 
      "schutzhelm" }), 
      "Soll das bedeuten Du hast Dir keine Ausruestung besorgt? Wie leicht"
      "sinnig von Dir!");
   
   AddDetail( ({ "furche" }),
      "Etliche Furchen sind vorhanden. Sie helfen Dir kaum beim klettern.");
   
   AddDetail( ({ "hohlraeume", "hohlraum" }),
      "Es scheint als sind sie entstanden als Steine aus dem Fels "
      "herausgebrochen sind.");

   AddDetail( ({ "gestein", "fels" }),
      "Das Gestein ist sehr poroes. Sei bloss vorsichtig, dass Du nicht von "
      "herabfallenden Steinen getroffen wirst.");

   AddDetail( ({ "stein" }),
      "Es koennten sich leicht Steine aus der Wand loesen und auf Dich "
      "herabfallen.");

   AddDetail( ({ "himmel" }),
      "Der blaue Himmel ist wie immer ueber Dir. Die Sonne scheint auf Dich herab."
      "Ueber Dir kannst Du Rauchschwaden ausmachen.");
   
   AddDetail( ({ "rauchschwaden","schwaden","rauch" }),
      "Schaden aus Rauch stroemen aus der Oeffnung ueber Dir.");
   
   AddDetail( ({ "oeffnung" }),
      "Da kann Du hinauf klettern.");
   
   AddDetail( ({ "boden" }),
      "Boden? Hier gibt es keinen Boden! Die Ritzen in denen Du grade stehst, "
      "kann man nicht als Boden bezeichnen. Wenn Du den richtigen Boden meinst: "
      "Zwischen Dir und dem eigentlichen Boden liegen einige Meter Luft."
      );
   
   AddDetail( ({ "ritzen" }),
      "In denen finden Deine Fuesse, wenn auch unsicher, halt.");
   
   AddDetail( ({ "fuesse" }),
      "Die solltest Dir spaeter ansehen.");
   
   AddDetail( ({ "luft" }),
      "Luft brauchst Du zum Atmen.");
   
   AddDetail( ({ "atem", "atmen" }),
      "Pass auf, dass der Atem Dir nicht ausgeht!");
   
   AddDetail( ({ "meter" }),
      "Zu viele Meter.");
   
   AddDetail( ({ "sonne" }),
      "Hell strahlt sie auf Dich herab. Nur ein paar Rauchschwaden verdecken "
      "sie zeitweise.");
   
   AddDetail( ({ "kraft" }),
      "Langsam geht Dir wirklich die Kraft aus. Du kannst Dich nicht mehr "
      "lange festhalten.");
   
   AddDetail( ({ "fuss", "fuesse" }),
      "Dein Fuesse haben in der Spalte genug Halt, um weiter zu klettern. Fuer "
      "eine laenger Pause ist sie nicht geeignet. Es ist extrem anstrengende "
      "in der Spalte zu stehen. Du solltest schnell weiterklettern.");
   
   AddDetail( ({ "pause" }),
      "Fuer Pausen hast Du weder die Zeit noch die Kraft.");
   
   AddDetail( ({ "halt" }),
      "In den Spalten findest Du ausreichend Halt mit Deinen Fuessen. Aber "
      "darin zu stehen ist sehr anstrengend.");
   
/*
   AddDetail( ({ "" }),
      "");
   
   AddSound( DEFAULT_SOUND,
      "");

   AddSound( ({ "" }),
      "");

   AddSmell( DEFAULT_SMELL,
      "");

   AddSmell( ({ "" }),
      "");
   
*/
   AddRoomMessage( ({
      "Langsam wirst Du muede. Du solltest schnell weiterklettern.\n",
      "Deine Kraft verlaesst Dich! Du kannst Dich kaum noch festhalten.\n",
      "Dein linker Fuss rutsch ab! Mit letzter Kraft verhinderts Du einen Absturz.\n",
      "Dein rechter Fuss rutsch ab! Mit letzter Kraft verhinderts Du einen Absturz.\n",
      "Ein Felsen fliegt neben Dir runter. Das war knapp!\n"}), 60 );

   AddCmd( ({ "schlage","schlag" }), "haken" );
   AddCmd( ({ "binde","knote" }), "seil" );
   AddCmd( ({ "greife","greif" }), "kreide" );
   AddCmd( ({ "klettere","klettere" }), "klettern" );

}


object checkKletter()
{
   object ob;
   
   ob = deep_present( "\nKletterPruef" );
   if( !ob )
   {
      ob = clone_object( OBJ + "kletter.lpc" );
      ob ->move( TP, M_NOCHECK );
   }
   
   return ob;
}

int haken( string str )
{
   object kl;
   object ob;
   
   notify_fail( "Was willst Du einschlagen?\n" );
   if( str == "kletterhaken ein" )
   {
      kl = checkKletter();
      
      if( !kl->CheckHaken( ROOM_NUM ))
      {
         ob = deep_present( "kletterhaken" );
         if( ob )
         {
            kl->SetHaken( ROOM_NUM );
            ob->remove();
            
            write("Du suchst einen geeingeten Riss und schlaegst einen Kletterhaken ein.\n");
            say( TPN+" schlaegt in einen Riss einen Kletterhaken ein.\n");
         }
         else
            write("Du hast ja gar keine Kletterhaken!\n");
      }
      else
      {
         write("Du hast schon einen Kletterhaken eingeschlagen.\n");
      }
      return 1;
   }
   return 0;
}


int seil( string str )
{
   object kl;
   object ob;
   
   notify_fail( "Was willst Du wo festbinden?\n" );
   if( str == "seil an kletterhaken fest" )
   {
      kl = checkKletter();
      
      if( !kl->CheckHaken( ROOM_NUM ))
      {
         ob = deep_present( "seil" );
         if( ob )
         {
            kl->SetSeil( ROOM_NUM );
//            ob->remove();
            
            write("Du ein Seil am Kletterhaken fest.\n");
            say( TPN+" ein Seil am Kletterhaken fest.\n");
         }
         else
            write("Du hast ja gar keine Seil!\n");
      }
      return 1;
   }
   return 0;
}


int kreide( string str )
{
   object ob;
   
   notify_fail( "Wo willst Du hinein greifen?\n" );
   if( str == "in kreidebeutel" )
   {
      ob = TP->QueryArmours( AT_GLOVE );
      if( !ob )
      {
         ob = deep_present( "kreidebeutel" );
         if( ob )
         {
            write("Du greifst in den Kreidebeutel.\n");
            say( TPN+" greift in einen Kreidebeutel.\n");
            
            kreide = 1;
            
         }
         else
            write("Du hast ja gar keinen Kreidebeutel!\n");
               
      }
      else
      {
         write("Du willst Dir Kreide auf Deinen Handschuhe streuen?!.\n");
      }
      return 1;
   }
   return 0;
}


absturz( int schaden, int weg )
{
   object kl;
   int room;
   int weiter;
   int stop;
   
   // Der Fall ist zu ende
   stop = 0;
   
   // Wahrscheinlichkeit mit der der Spieler weiter abstuerzt
   weiter = ( TP->QueryProp( P_TOTAL_WEIGHT ) - TP->QueryProp( P_WEIGHT ) )
          * 100 / TP->QueryProp( P_MAX_WEIGHT ) - 80;
   if( weiter < 0 )
      weiter = 5;
   else
      weiter += 5;
   
   kl = checkKletter();
   
   schaden += ( 40 * weg ) + random( 40 * weg );
   weg++;
   
   if( kl->CheckHaken( ROOM_NUM ) && kl->CheckSeil( ROOM_NUM ) &&
       kl->CheckAngebunden() )
   {
      if( random( 100 ) < weiter || TP->QueryProp( P_HP ) < schaden )
      {
         stop = 0;
      }
      else 
      {
         stop = 1;
      }
   }
   else
   {
      stop = 0;
   }
   
   if( stop )
   {
      say( BS( TPN+" stuerzt schreind auf Dich herab. Ploetzlich scheint "
         + " die Sicherung zu wirken und " + TPN + "schlaegt extrem hart "
         + "gegen die Felswand!\n"));
      write( BS( "Nach einer Ewigkeit des Fallens spuerst Du einen "
         + "stechenden Schmerz, der durch Dich faehrt und Dir die Sinne "
         + "raubt, als das Seil Deinen Sturz abrupt beendet!\n" ));
      TP->do_damage( schaden );
   }
   else
   {
      if( ROOM_NUM == 0 )
      {
         TP->move( ROOM + "finger1" , M_GO + M_SILENT );
      }
      else
      {
         TP->move( ROOM + "aufstieg" + ROOM_NUM , M_GO + M_SILENT );
      }
      say( TPN+" stuerzt schreiend an Dir vorbei in die Tiefe!\n");
      ENV( TP )->absturz( schaden, weg );
   }
}


int klettern( string str )
{
   object ob;
   int schuhe;
   int schaden;
   int ziel;
   int chance;
   int risiko;
   int leicht;
   
   leicht = ziel = schaden = schuhe = 0;
   
   notify_fail( "Wohin willst Du klettern?\n" );
   if( str == "rauf" || str == "hinauf" )
      ziel = 1;
   if( str == "ohne ruecksicht auf verluste rauf" || 
       str == "ohne ruecksicht auf verluste hinauf" )
   {
      ziel = 1;
      risiko = 1;
   }
   if( str == "runter" || str == "hinunter")
      ziel = -1;
   if( str == "ohne ruecksicht auf verluste runter" || 
       str == "ohne ruecksicht auf verluste hinunter" )
   {
      ziel = -1;
      risiko = 1;
   }
   
   if( ziel == 0 )
      return 0;
   
   // Was haben wir denn fuer Schuhe an?
//   ob = TP->QueryArmours( AT_BOOT );
   if( !ob )
   {
      schuhe  = 1;
      schaden = 1;
   }
   else
   {
      if( ob->QueryMaterialGroup( MATGROUP_CLOTH ) > 50 || 
          ob->QueryMaterial( MAT_SKIN ) > 50 ||
          ob->QueryMaterial( MAT_WOOL ) > 50 ||
          ob->QueryMaterial( MAT_LEATHER ) > 50 )
         schuhe = 1;
      else if( ob->QueryMaterialGroup( MATGROUP_METAL ))
         schuhe = -1;
   }
   
   // Was haben wir denn fuer Handschuhe an
//   ob = TP->QueryArmours( AT_GLOVE );
   if( !ob )
   {
      if( kreide != 1 )
      {
         schaden += 1;
      }
   }
   else
   {
      if( ob->QueryMaterialGroup( MATGROUP_CLOTH ) > 50 || 
          ob->QueryMaterial( MAT_SKIN ) > 50 ||
          ob->QueryMaterial( MAT_LEATHER ) > 50 )
         kreide = 1;
      else if( ob->QueryMaterialGroup( MATGROUP_METAL ))
         kreide = -1;
   }
   
   if( ( TP->QueryProp( P_TOTAL_WEIGHT ) - TP->QueryProp( P_WEIGHT ) )
       * 100 / TP->QueryProp( P_MAX_WEIGHT ) > 80 )
      leicht = -1;
   else if( ( TP->QueryProp( P_TOTAL_WEIGHT ) - TP->QueryProp( P_WEIGHT ) )
       * 100 / TP->QueryProp( P_MAX_WEIGHT ) < 50 )
      leicht = 1;
/*   
   chance = 100 - ( TP->QueryAttribute(A_STR)
                     + TP->QueryAttribute(A_INT)
                     + TP->QueryAttribute(A_CON) ) / 2
                   - TP->QueryAttribute(A_DEX)
                   - kreide * 10
                   - schuh * 10
                   - leicht * 10
                   ;
*/
   chance = 20 - leicht * 5 - kreide * 5 - schuhe * 5 
          - TP->QueryAttribute(A_DEX) / 5;
   
   if( chance < 0 )
      chance = 1;
   
   if( chance > 10 && !risiko)
   {
      write( BS( "Du willst gerade zu klettern beginnen, als Dir bewusst wird "
             + "wie gefaehrlich Dein Vorhaben ohne gruedliche Vorbereitung "
             "ist, und Du haeltst inne.\nWenn Du trotzdem klettern willst gib "
             "ein:\nklettere ohne ruecksicht auf verluste <richtung>.\n" ));
      return 1;
   }
   
   if( random( 100 ) < chance )
   {
      write( BS( "Als Dein rechter Fuss weg rutscht, verlierst Du das "
         + "Gleichgewicht, kannst Dich nicht laenger in der Wand festhalten.\n")
         + "Schreined und mit weit aufgerissenen Augen stuerzt Du dem Boden "
         + "entgegen!\n");
      say( BS( TPN + " verliert das Gleichgewicht und stuerzt in schreiend "
         + "in die Tiefe!\n"));
      absturz( 0, 1 );
   }
   else
   {
      str = "Mutig beginnst Du nach ";
      if( ziel == 1 )
      {
         str += "oben zuklettern.";
         say( TPN+" klettert mutig nach oben.\n");
      }
      else
      {
         str += "unten zuklettern.";
         say( TPN+" klettert mutig nach unten.\n");
      }
      
      if( schaden > 0 )
      {
         schaden = 5 * schaden + random( schaden * 10 );
         str += " Wegen Deiner mangelhaften Ausruestung verletzt Du Dich an "
             + "den scharfen Kanten.";
         
         TP->do_damage( schaden );
         
      }
      write( BS( str + "\n" ));
      
      ziel = ROOM_NUM + ( ziel + 1);
      
      switch( ziel )
      {
         case MAX_ROOM:
            write( "Raum: " + ROOM + "gang0" + "\n.");
            TP->move( ROOM + "gang0", M_GO + M_SILENT );
            break;
         case 0:
            write( "Raum: " + ROOM + "finger1" + "\n.");
            TP->move( ROOM + "finger1", M_GO + M_SILENT );
            break;
         default:
            write( "Raum: " + ROOM + "aufstieg" + ziel + "\n.");
            TP->move( ROOM + "aufstieg" + ziel, M_GO + M_SILENT );
            break;
      }
   }
   return 1;
}


