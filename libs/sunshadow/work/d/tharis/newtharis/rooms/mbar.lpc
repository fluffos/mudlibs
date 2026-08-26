#include <std.h>
#include "../tharis.h"
inherit VAULT;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);
   set_short("%^RESET%^%^C130%^The %^RESET%^%^C088%^T%^C124%^u%^C160%^r%^C196%^n%^C202%^i%^C124%^n%^RESET%^%^C088%^g S%^RESET%^%^C124%^p%^C160%^i%^RESET%^%^C088%^t %^RESET%^%^C130%^Tavern%^CRST%^");
   set_long("%^RESET%^%^C130%^This tavern is unique for the fact that the room is unique in design, tables arranged facing the center of the room, where a series of %^RESET%^%^C247%^spits%^RESET%^%^C130%^ are located. The %^RESET%^%^C094%^carcasses %^RESET%^%^C130%^of various animals turn on each spit, their glazed skins %^RESET%^%^C136%^s%^C178%^i%^C220%^z%^C226%^z%^RESET%^%^C227%^l%^C220%^i%^C178%^n%^RESET%^%^C136%^g %^RESET%^%^C130%^as they slowly cook. The drone of conversation and boisterous laughter from patrons deep in their cups competes with the %^RESET%^%^C196%^c%^C202%^r%^C208%^a%^C214%^c%^RESET%^%^C220%^k%^C214%^l%^C208%^i%^RESET%^%^C202%^n%^RESET%^%^C196%^g%^RESET%^%^C130%^ of the many %^RESET%^%^C124%^f%^C160%^i%^C196%^r%^C160%^e%^RESET%^%^C124%^s%^RESET%^%^C130%^. There is a %^RESET%^%^C058%^counter %^RESET%^%^C130%^around the outside of the circle, where waitresses mingle with the customers. The tavern itself looks as if it has seen better days, many of its surfaces %^RESET%^%^C144%^worn %^RESET%^%^C130%^and %^RESET%^%^C101%^dingy%^RESET%^%^C130%^, and those that frequent this place tend to be a bit more rough and tumble themselves.%^CRST%^");
   set_smell("default","You smell the searing meat from the spit.");
   set_listen("default","You hear the yells of the crowd currently in here mixed with the popping of fats dropping into the fire.");

   set_items(([
      "spits":"%^RESET%^%^C088%^These turning spits hold whole carcasses of medium-sized animals as well as the limbs of larger beasts; pig, cow, rothe shank, lamb, and rabbit are just a sampling of the meats that turn over the open flame contained within the stone bases the spits rest upon. Some of the larger carcasses must take days to cook.%^CRST%^",
      "tables":"%^RESET%^%^C094%^Though they're of sturdy make, these tables have seen better days, their surfaces stained and worn from decades of use.%^CRST%^",
      "counter":"%^RESET%^%^C058%^This counter is where the waitstaff picks up the orders as they're filled. Some of the regulars also lean against it, drinking and watching the spitmaster as he works.%^CRST%^",
   ]));

   set_exits(([
      "west":ROOMS"north4",
   ]));
}

void reset(){
   ::reset();
   if(!present("grubb")) find_object_or_load(MOBS"grubb")->move(TO);
   //if(!present("sacretel")) find_object_or_load(MOBS"sacretel")->move(TO);
}

void init(){
   ::init();
   add_action("read","read");
   if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("grubb");
    if(!ob) {
      write("The barkeeper isn't here right now.");
      return 1;
    }
    write("The following great foods are served here at the Turning Spit Tavern.");

    write("%^RESET%^%^C088%^--%^RESET%^%^C124%^--%^C160%^--%^C196%^--%^C202%^--%^C208%^--%^C214%^--%^RESET%^%^C220%^--%^C226%^--%^C220%^--%^C214%^--%^C208%^--%^RESET%^%^C202%^--%^C196%^--%^C160%^--%^C124%^--%^RESET%^%^C088%^--%^C124%^--%^C160%^--%^C196%^--%^RESET%^%^C202%^--%^C208%^--%^C214%^--%^C220%^--%^C226%^--%^RESET%^%^C220%^--%^C214%^--%^C208%^--%^C202%^--%^RESET%^%^C196%^--%^C160%^--%^C124%^--%^C088%^--%^RESET%^%^C124%^--%^CRST%^");
    write("%^RESET%^%^C088%^Fire Roasted Nuts\t\t\t\t"+(int)ob->get_price("fire roasted nuts")+" silver%^CRST%^");
    write("%^RESET%^%^C124%^Traveler's Meal\t\t\t\t\t"+ (int)ob->get_price("traveler's meal")+" silver%^CRST%^");
    write("%^RESET%^%^C160%^Spit Turned Meat\t\t\t\t"+ (int)ob->get_price("spit turned meat")+" silver%^CRST%^");
    write("%^RESET%^%^C196%^Tharisian Dark Lager\t\t\t\t"+(int)ob->get_price("tharisian dark lager")+" silver%^CRST%^");
    write("%^RESET%^%^C202%^Verbonese Ale\t\t\t\t\t"+ (int)ob->get_price("verbonese ale")+" silver%^CRST%^");
    write("%^RESET%^%^C208%^Cravnarian Wine\t\t\t\t\t"+ (int)ob->get_price("cravnarian wine")+" silver%^CRST%^");
    write("%^RESET%^%^C214%^Mushroom Wine\t\t\t\t\t"+ (int)ob->get_price("cravnarian wine")+" silver%^CRST%^");
    write("%^RESET%^%^C220%^Water\t\t\t\t\t\t"+ (int)ob->get_price("cravnarian wine")+" silver%^CRST%^");
    write("%^RESET%^%^C088%^--%^RESET%^%^C124%^--%^C160%^--%^C196%^--%^C202%^--%^C208%^--%^C214%^--%^RESET%^%^C220%^--%^C226%^--%^C220%^--%^C214%^--%^C208%^--%^RESET%^%^C202%^--%^C196%^--%^C160%^--%^C124%^--%^RESET%^%^C088%^--%^C124%^--%^C160%^--%^C196%^--%^RESET%^%^C202%^--%^C208%^--%^C214%^--%^C220%^--%^C226%^--%^RESET%^%^C220%^--%^C214%^--%^C208%^--%^C202%^--%^RESET%^%^C196%^--%^C160%^--%^C124%^--%^C088%^--%^RESET%^%^C124%^--%^CRST%^");
    write("<buy dish_name> gets you the food.");
    return 1;
}


