// Xorgan@SilberLand
// Im Inneren des mahnenden Finger
// 2002-02-22

#include "../def.h"

inherit "std/room";

void create()
{
   ::create();

   SetProp( P_INT_SHORT, "Im Inneren des mahnenden Finger" );
   SetProp( P_INT_LONG,
      "Du befindest Dich in einem schmalen niedrigen Gang im mahnenden Finger. "
      "Je weiter Du vordringst, desto heisser wird es. Abgesehen von dem "
      "schwarzen Fels gibt es nicht viel zu sehen.");
   SetProp( P_LIGHT, 0 );
   SetProp( P_INDOORS, 1 );
   SetProp(P_ENVIRONMENT, ([ENV_TEMPERATURE: ROOM_TEMP, ENV_TERRAIN: TT_CAVE]) );
   
   AddDetail( ({ "gang" }),
      "Ein schmaler niedriger Gang fuehrt tiefer in der Berg. Wie Du erahnen "
      "kannst faellt der Gang leicht nach unten ab.");
   
   AddDetail( ({ "finger" }),
      "Deine Finger sind nicht interessant.");
   
   AddDetail( ({ "mahnenden finger" }),
      "So heisst er Berg in dem Du dich befindest.");
   
   AddDetail( ({ "berg" }),
      "Wie wuerderst Du es denn sonst bezeichen?");
   
   AddDetail( ({ "boden" }),
      "Der Boden besteht wie erwartet aus voellig Fels und ist teilweise mit "
      "keinen Steinen bedeckt.");
   
   AddDetail( ({ "felsen", "fels", "stein", "steine", "material" }),
      "Es handelt sich um schwarzes, rauhes Material, wie es bei "
      "einem Vulkanausbruch entstehen kann.");
   
   AddDetail( ({ "ausbruch", "vulkanausbruch" }),
      "Vulkane bestehen oft aus diesem schwarzen Gestein.");
   
   AddDetail( ({ "vulkane", "vulkan" }),
      "Es deutet vieles darauf hin, dass es sich hierbei um einen Vulkan "
      "handel. Hoffentlich bricht er nicht aus.");
   
   AddDetail( ({ "gestein" }),
      "Das Gestein ist schwarz und poroes.");
   
   AddDetail( ({ "decke" }),
      "Die Decke kannst Du vor lauter Rauch kaum erkennen, aber auch sie "
      "besteht aus Fels.");
   
   AddDetail( ({ "waende", "wand" }),
      "Die Waende bestehen aus dem selben Material wie auch der Boden. Sie "
      "bieten keine besonderen Auffaelligkeiten.");
   
   AddDetail( ({ "auffaelligkeiten", "besonderes" }),
      "Es ist wirklich nichts Besonderes an den Waenden zu finden.");
   
   AddDetail( ({ "rauch" }),
      "Richtige Rauchschwaden nehmen Dir die Sicht.");
   
   AddDetail( ({ "sicht" }),
      "Du kannst kaum weiter als ein paar Schritte sehen.");
   
   AddDetail( ({ "schritte", "meter" }),
      "Ein nicht unuebliches Laengenmass.");
   
   AddDetail( ({ "mass", "laengenmass" }),
      "Damit bestimmt man die Laenge.");
   
   AddDetail( ({ "laenge" }),
      "Alles hat eine Laenge.");
   
   AddDetail( ({ "alles" }),
      "Ja, wirklich alles.");
   
   AddDetail( ({ "paar" }),
      "Du schaetzt die Sicht betraegt nicht mehr als 10 Schritte.");
   
   AddDetail( ({ "rauchschwaden", "schwaden" }),
      "Schwaden von Rauch fliessen an der Decke entlang. ");
   
/*   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddDetail( ({ "" }),
      "");
   
   AddReadDetail( ({ "" }),
      "");
   
   AddRoomMessage( 
      ({""}),30,"func");
   
*/
   AddSound( DEFAULT_SOUND,
      "Du hoerst ein entferntes Donnern und grollen");
   
   AddSound( ({ "donnern", "donner", "grollen" }),
      "Je weiter Du in den Gang hinein gehst, desto lauter wird es.");
   
   AddSound( ({ "gang" }),
      "Irgendwie scheint Dich das Grollen und Donnern zu beunruhigen.");
   
   AddSmell( DEFAULT_SMELL,
      "Ein scharfer beissender Geruch liegt in der Luft.");
   
   AddSmell( ({ "geruch", "luft" }),
      "Es riecht nach faulen Eiern. Wiederlich!");
   
   AddSmell( ({ "eier", "eiern" }),
      "Schwefel, das muss es sein. ");
   
   AddSmell( ({ "schwefel", "schwefelgeruch" }),
      "Auch der Schwefelgeruch scheint Dich nicht gerade zu beruhigen.");

/*   
   AddCmd( ({ "tue" }), "command" );

   AddItem( "item" , REFRESH_DESTRUCT);
*/
   AddExit( R_REIN, "nach " + CAP( R_REIN ) + "#" + "./gang" + ROOM_REIN );
   AddExit( R_RAUS, "nach " + CAP( R_RAUS ) + "#" + "./gang" + ROOM_RAUS );
}
