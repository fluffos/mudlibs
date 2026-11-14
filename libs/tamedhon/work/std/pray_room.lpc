//pray_room.c --std-prayroom
//17.08.2000 by Serii@Tamedhon
//
//ich lass die P_INT_LONG und die ganzen beschreibungs sachen erstmal so
//koennen ja dann im eigendlichen raum ueberschrieben werden...
//(und wemma zu faul is dann laesst mans halt alles so ;) )
//details sind raus weils mich genervt ham *g* kann ja gern jeder neu machen
//mit der function AllowPray() kann man die rassen spezifizieren die in dem
//raum dann nur beten duerfen
//mit SetNPmessage() kann man die message definieren die ausgegeben werden
//soll wenn es dem spieler nicht erlaubt ist hier zu beten
//SetPmessage() definiert was ausgegeben wird wenn man 'erfolgreich' betet
//18.07.2002 (Serii)
//SetP2Player_message() - wird nach dem beten an den spieler ausgegeben
//SetP2Others_message() - wird nach dem beten an den raum ausgegeben
//05.05.2004 Gralkor
//Hab mal die Orks dazugeschrieben...
//Serii kann halt gar nix ;) Aber davon ne ganze Menge
//24.06.2008 TamTam
//Typo in Pmessage
inherit "std/room";

#include <properties.h>

//ich lass daemonen gleich mal raus, die ham eh nen ganz eigenen ;)
//alle anderen rassen koennen standardmaessig hier beten...
string *PrayAllow = ({"Ork","Mensch","Brownie","Zwerg","Elf","Hobbit","Goblin"});

string NPmessage = "Du kannst hier nicht beten.\n";

string Pmessage = "Du hältst eine kurze Andacht.\n";

string P2pmessage= "Eine sehr starke Kraft saugt Dich auf und spuckt Dich wieder aus.\n";

string P2omessage= "%s erscheint in körperlicher Form.\n";

void create()
{
	::create();
	SetProp(P_LIGHT,1);
	SetProp(P_INT_LONG,
   "Du befindest Dich in einer kleinen Kapelle, in der Du beten kannst, um\n"+
   "wieder Deine natürliche Gestalt zu erhalten. Am südlichen Ende steht\n"+
   "ein Altar, auf dem sich ein großes Kreuz befindet. In den Wänden siehst\n"+
   "Du herrliche Fenster, durch die tagsüber das Licht bunt hereinscheint.\n"+
   "Im Norden befindet sich eine Tür, die zur Gilde führt.\n");
  SetProp(P_INT_SHORT,"Kapelle");
//  AddDetail("altar", "Er ist aus Stein und nicht besonders schoen.\n");
//  AddDetail("kreuz", "Ein schlichtes Holzkreuz.\n");
//  AddDetail("fenster", "Die Fenster sind wunderschoen.\n");
//  AddDetail(({"wand", "waende"}), "An den Waenden siehst Du nichts besonderes.\n");
  AddCmd("bete","bete");
//  AddExit("norden","/gilden/abenteurer");
}

void AllowPray(string *RaceArray)
{
  PrayAllow = RaceArray;
}

void SetNPmessage(string str)
{
  NPmessage = str;
}
//message die an den spieler ausgegeben wird
void SetP2Player_message(string str)
{
  P2pmessage=str;
}
//message die an den raum ausgegeben wird
void SetP2Others_message(string str)
{
  P2omessage=str;
}

void SetPmessage(string str)
{
  Pmessage = str;
}

int bete() {
   if(member(PrayAllow,this_player()->QueryProp(P_RACE))>=0)
   {
     write(Pmessage);
     if (this_player()->QueryProp(P_GHOST))
     {
	write(P2pmessage);
	say(sprintf(P2omessage,this_player()->name()));
	this_player()->SetProp(P_GHOST,0);
     }
     return 1;
   }
   else
   {
     write(NPmessage);
     return 1;
   }
   return 0;
}


