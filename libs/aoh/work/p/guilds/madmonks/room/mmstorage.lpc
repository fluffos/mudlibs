// storage for the Madmonks
// made by MagicTCS 24/9/96

inherit "std/shop";

#include <rooms.h>
#include <properties.h>
//#include "/d/woodland/sys/woodland.h"

void create(){
 ::create();
 SetIntShort("dojo storage-room");
 SetIntLong(
"You entered a huge chamber behind the main-hall of the guildhouse.\n\
Here you can ask for new weapons or buy some useful stuff like bandages.\n\
Shelves filled with weapons decorate two of the walls. Another shelf is\n\
filled with armours and bandages. There is a price-list hanging above one\n\
of them. An old smiling half-elf is sitting here to welcome new guild-\n\
members. As you enter he looks up and laughs. 'Another fool has joined\n\
this guild for losers!' He sees that you are getting angry and laughs\n\
even more. 'Lesson number one: Don't let anyone provoke you! In the\n\
case of cases just don't listen.' He smiles at you. The exit lies to the\n\
south.\n");
 SetIndoors(1);
 AddDetail("shelves", "They are filled with weapons.\n");
 AddDetail(({"weapons", "armour", "bandages"}),
 "Do you think you will get one?\n");
 AddDetail("price-list", "The shopkeeper can show it to you.\n");
 AddDetail("half-elf", "He is old and wise.\n");
 SetBuyFactor(200);
 SetMinCash(30000);
 SetIdentify(0);
 SetAppraise(0);
 SetSell(0);
 ForbidShopkeeper();
 RemoveDustbin();
 AddExit("south", GUILDS("paladins"));
 AddArticle(GUILDS("bandages"), REFRESH_REMOVE, 5);
 AddArticle("/obj/torch", REFRESH_REMOVE);
 AddArticle(OBJ("quiver"), REFRESH_REMOVE, 5);
 AddArticle(OBJ("ppack"), REFRESH_REMOVE, 5);
 AddArticle(OBJ("bow"), REFRESH_REMOVE, 3);
 AddArticle(OBJ("shortsword"), REFRESH_REMOVE, 3);
}

void init() {
 ::init();
 add_action("ask", "ask");
}

int has_sword() {
 object pl,ob;
 int has;
 has = 0;
 pl = this_player();
 ob = first_inventory(pl);
 while(ob) {
    if (ob->id("guildsword")) has = 1;
    ob = next_inventory(ob);
 }
 return has;
}

int ask(string str) {
 write("The guildmaster says: 'I don't give swords to players any more.'\n");
 say("The guildmaster says: 'I don't give swords to players any more.'\n");
 return 1;
}

int ModifyPrice(object obj, int price, string verb) {
   if (this_player()->QueryGuild() == "Fighters") return price/2;
   return price;
}
