inherit "/std/room";
#include <properties.h>
#include <rooms.h>
 
create() {
   ::create();
   SetIntShort("You are on the captain's bridge");
   SetIntLong(
"You are on the bridge of the Constitution class Starship 'Enterprise',\ "
"NCC-1701. The bridge if full of technology you cannot begin to understand. "
"You wonder why one of the higher ranking officers is not here.\n");
    SetIndoors(1);
    AddDetail("NCC-1701", "No bloody -A, -B, -C or -D!\n");
    AddExplorable("look:NCC-1701");
    AddExplorable("look:ncc-1701");
    AddExit("down","./r_t3");
    AddNoise("signal", "A constant tweeping and beeping.\n");
    AddItem("/std/npc",REFRESH_HOME,
      ([P_NAME:"Sulu",
	P_SHORT:"Mr. Hikaru Sulu",
	P_LONG:"Mr. Sulu is the ship's helmsman.\n",
	P_IDS:({"hikaru","sulu"}),
	P_ADS:({"mr.","hikaru"}),
	P_RACE:"human",
	P_AGGRESSIVE:0,
	P_LEVEL:3,
	P_HANDS:({({"his left hand",0,6}),({"his right hand",0,6})}),
	P_AC:1,
	P_GENDER:1,
	P_ALIGN:1000,
	P_CHATS:({
  "Sulu says: Kirk needs his communicator so we can lock onto his signal.\n",
  "Mr. Sulu says: Where is Scotty? He needs to fix the transporter!\n",
  "Sulu asks: Do you think Scotty was drugged by the intruder?\n"}),
	P_CHAT_CHANCE:5]));
    AddItem("/std/npc",REFRESH_HOME,
      ([P_NAME:"Uhura",
	P_SHORT:"Uhura",
	P_LONG:"Uhura is the ship's communications officer.\n",
	P_RACE:"human",
	P_AGGRESSIVE:0,
	P_LEVEL:3,
	P_HANDS:({({"her left hand",0,6}),({"her right hand",0,6})}),
	P_AC:1,
	P_GENDER:2,
        P_ALIGN:1000,
	P_CHATS:({
  "Uhura says: Still no response from Scotty, Sir!\n",
  "Uhura says: I am getting a signal from the engine room Sir!\n",
  "Uhura says: Still no response from Kirk!\n",
  "Uhura says: Transporter room reports they still cannot locate the captain.\n"
	}),
        P_CHAT_CHANCE:5]));
}
