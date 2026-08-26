#include <std.h>

//at 41,44 on sea
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

string seas;

void create() {
    ::create();
    set_terrain(VILLAGE);
    set_travel(RUTTED_TRACK);
    set_property("indoors",0);
    set_name("abandoned docks");
    set_property("light",2);
    set_short("%^RESET%^%^ORANGE%^abandoned docks%^RESET%^");
    seas = season(time());
    set_long("blah");
    switch(seas){
    case "summer": 
        set_long("%^RESET%^%^ORANGE%^The docks stretch out for miles both "+
		"north and south along the crescent of the cove. %^RED%^Massive wooden "+
		"constructs%^RESET%^%^ORANGE%^ form docks fit for the largest of "+
		"%^GREEN%^galleons%^RESET%^%^ORANGE%^ and is spectacular as a deep water "+
		"port. But what is odd is that there isn.t a single ship, nor signs there "+
		"have been ships in some time. The %^BLACK%^%^BOLD%^brackish "+
		"water%^RESET%^%^ORANGE%^ is stifling hot and having not been broken "+
		"by moving ships it reflects the %^RED%^%^BOLD%^burning sun%^RESET%^%^ORANGE%^. "+
		"Bundles of %^GREEN%^ropes%^RESET%^%^ORANGE%^ lay in coils almost decayed "+
		"into solid heaps. And crates sit in neat stacks covered in cargo netting. "+
		"To the east a road passes shuttered buildings and into the remains of a "+
                "city.\n%^RESET%^");
    break;
    
    case "spring": 
        set_long("%^RESET%^%^GREEN%^The docks stretch out for miles both north and "+
		"south along the crescent of the cove. %^RESET%^%^ORANGE%^Massive wooden "+
		"constructs%^RESET%^%^GREEN%^ form docks fit for the largest of "+
		"%^ORANGE%^galleons%^RESET%^%^GREEN%^ and is spectacular as a deep water "+
		"port. But what is odd is that there isn.t a single ship, nor signs there "+
		"have been ships in some time. Newly created %^RESET%^birds. "+
		"nests%^RESET%^%^GREEN%^ dot every available surface and you can hear "+
		"the %^YELLOW%^chirping%^RESET%^%^GREEN%^ across the harbor of the newly "+
		"hatched birds. %^RESET%^%^ORANGE%^Bundles of ropes%^RESET%^%^GREEN%^ "+
		"lay in coils almost decayed into solid heaps. And %^ORANGE%^crates"+
		"%^RESET%^%^GREEN%^ sit in neat stacks covered in cargo netting. The "+
		"smell of %^RED%^%^BOLD%^flowers%^RESET%^%^GREEN%^ wafts in from the east "+
		"and the %^CYAN%^water%^RESET%^%^GREEN%^, while no longer frozen, still "+
		"holds a chill that rises. To the east a road passes shuttered buildings "+
                "and into the remains of a city.\n%^RESET%^");
    break;

    case "winter":
        set_long("%^RESET%^%^BOLD%^The docks stretch out for miles both north and "+
		"south along the crescent of the cove. Massive snow covered "+
		"%^RESET%^%^ORANGE%^wooden constructs%^RESET%^%^BOLD%^ form docks fit for "+
		"the largest of %^BLACK%^%^BOLD%^galleons%^RESET%^%^BOLD%^ and is spectacular "+
		"as a deep water port. But what is odd is that there isn.t a single ship, nor "+
		"signs there have been ships in some time. Even the water is a mostly "+
		"unbroken %^CYAN%^cover of ice%^RESET%^%^BOLD%^. Bundles of frost covered "+
		"ropes lay in coils almost %^BLACK%^%^BOLD%^decayed into solid heaps. "+
		"%^RESET%^%^ORANGE%^Crates%^RESET%^%^BOLD%^ sit in neat stacks covered in "+
		"cargo netting. To the east a road passes shuttered buildings and into the "+
		"remains of a city yet the path is covered by mounds of snow that have "+
                "collected against the buildings.\n%^RESET%^");
    break;

    case "autumn":
        set_long("%^RESET%^%^ORANGE%^The docks stretch out for miles both north and "+
		"south along the crescent of the cove. %^RESET%^%^RED%^Massive wooden "+
		"constructs%^RESET%^%^ORANGE%^ form docks fit for the largest of "+
		"%^RESET%^galleons%^RESET%^%^ORANGE%^ and is spectacular as a deep water "+
		"port. But what is odd is that there isn.t a single ship, nor signs there "+
		"have been ships in some time. The water is covered in a carpet of "+
		"%^RED%^fallen leaves%^RESET%^%^ORANGE%^ that must have collected from all "+
		"across the island and dropped here by the prevailing winds. Bundles of "+
		"ropes lay in coils almost %^BLACK%^%^BOLD%^decayed%^RESET%^%^ORANGE%^ "+
		"into solid heaps. And crates sit in neat stacks covered in cargo netting. "+
		"To the east a road passes shuttered buildings and a westerly wind drives "+
		"through it back to the harbor with a hint of cold on its way. The path is "+
		"likewise covered in %^RED%^leaves%^RESET%^%^ORANGE%^  and leads into the "+
                "remains of a city.\n%^RESET%^");
    break;
	
    }   
    set_items(([
        ({"docks"}) : "%^RESET%^%^ORANGE%^The massive docks spread out to the "+
		"north and south along the cove%^RESET%^.",
		({"rope"}) : "%^RESET%^%^ORANGE%^There is enough coiled rope here to bind a "+
		"wing of dragons, but it is coiled up and hasn't been used in long enough "+
		"time that it has rotted%^RESET%^.",
		({"water"}) : "%^RESET%^%^BLUE%^The water is brackish, salty and deep as "+
		"the ocean%^RESET%^.",
        ({"buildings"}) : "%^RESET%^%^ORANGE%^The buildings along the dock have been "+
		"shuttered but you can easily imagine that once this was a hive of "+
		"activity%^RESET%^.",
    ]));

set_smell("default","%^RESET%^You smell the sea.");
set_listen("default","%^RESET%^You hear waves.");

      set_exits(([
            "east" : "/d/islands/serakii/rooms/dock/1",
    ] ));
}




