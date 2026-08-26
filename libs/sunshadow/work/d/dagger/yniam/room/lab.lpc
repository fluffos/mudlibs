// Chernobog (4/14/22)
// Yniam Waystation - Lab

#include <std.h>
#include "../defs.h"
inherit VAULT;

int occupied, temperment;

void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_name("A laboratory within the waystation");
    set_short("%^RESET%^%^CRST%^%^C046%^A %^C109%^laboratory %^C046%^within the %^C144%^waystation%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C136%^This room is full of various %^C130%^worktables%^C136%^, each presenting a different array of equipment from fantastically shaped %^C231%^gla%^C189%^s%^C231%^sw%^C189%^ar%^C231%^e %^RESET%^%^C136%^to intricate %^C059%^m%^C244%^e%^C246%^t%^C244%^a%^C059%^l b%^C244%^o%^C246%^w%^C244%^l%^C059%^s %^RESET%^%^C136%^to %^C144%^ceramic mortars %^C136%^and %^C144%^pestles%^RESET%^%^C136%^. A pair of %^C059%^stoves %^C136%^are featured opposite the entrance, their metal bellies kept full and alive for any work requiring heat, while other walls are lined with %^C130%^cabinets %^C136%^and %^C130%^shelves%^RESET%^%^C136%^, each stocked with an array of mundane and exotic ingredients. Windows are absent of the room but vents can be seen around the periphery of the high ceiling to allow any disastrous accidents to disperse. A set of %^C059%^small cages %^C136%^lurk against the wall away from any of the furnishings, seeming out of place.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A strange %^C156%^acrid scent %^C144%^seems to emanate from the equipment here.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C244%^The soft scratch of %^C250%^qu%^C253%^i%^C250%^l%^C253%^l %^RESET%^%^C244%^against %^C144%^paper %^C244%^sound from those working here.%^CRST%^");
    set_items(([
        ({"tables", "worktables"}) : "%^RESET%^%^CRST%^%^C101%^Made from %^C136%^solid oak%^C101%^, these tables are sturdy and expansive to allow plenty of room to work.%^CRST%^",
        "glassware" : "%^RESET%^%^CRST%^%^C231%^Vi%^C189%^al%^C231%^s %^C101%^and %^C231%^bot%^C189%^tle%^C231%^s %^RESET%^%^C101%^of %^C032%^st%^C038%^ra%^C044%^ng%^C050%^e l%^C044%^iq%^C038%^ui%^C032%^ds %^RESET%^%^C101%^are suspended in a thin metal framework, some connected by glass tubing. Small portable %^C202%^b%^C196%^u%^C202%^rn%^C208%^e%^C202%^rs %^RESET%^%^C101%^lurk beneath some of the glassware, while others have been set aside.%^CRST%^",
        ({"bowls", "mortars", "pestles"}) : "%^RESET%^%^CRST%^%^C101%^Some of these are solid %^C059%^cast ir%^C244%^o%^C059%^n%^RESET%^%^C101%^, while others are a %^C144%^glazed ceramic %^C101%^make.%^CRST%^",
        "stoves" : "%^RESET%^%^CRST%^%^C101%^The pair of stoves are huge %^C059%^ir%^C244%^o%^C059%^n %^C101%^beasts, each with a door that can be opened when feeding more fuel to their %^C202%^f%^C196%^i%^C202%^r%^C208%^e%^C202%^s%^C101%^.%^CRST%^",
        ({"cabinets", "shelves"}) : "%^RESET%^%^CRST%^%^C101%^The %^C136%^cabinets %^C101%^and %^C136%^shelves %^C101%^are tall and heavy, fashioned from oak with solid locks at the juncture of their doors. %^C231%^Gl%^C189%^as%^C231%^s pan%^C189%^el%^C231%^s %^RESET%^%^C101%^have been set in the doors to view the assortment of strange materials and chemicals stored within.%^CRST%^",
        ({"ingredients", "chemicals", "materials"}) : "%^RESET%^%^CRST%^%^C065%^Strange %^C064%^herbs %^C101%^and %^C211%^p%^C205%^o%^C199%^wde%^C205%^r%^C211%^s %^RESET%^%^C101%^fill various containers, some %^C244%^dusky %^C101%^or muted in color while others are a %^C033%^v%^C039%^i%^C045%^bra%^C039%^n%^C033%^t %^C111%^as%^C105%^so%^C099%^rt%^C105%^me%^C111%^nt %^C101%^of %^C214%^pi%^C220%^g%^C226%^me%^C220%^n%^C214%^ts%^RESET%^%^C101%^, each with exotic scents wafting about.%^CRST%^",
        ({"cage", "cages"}) : (:this_object(), "look_cages":),
        "goblin" : (:this_object(), "look_goblin":),
        ]));
    set_exits(([
        "west" : ROOMS"outpost_hub",
        ]));
    set_door("wooden door", ROOMS"outpost_hub", "west", 0);
	set_door_description("wooden door","%^RESET%^%^CRST%^%^C058%^This is a simple wooden door with a %^C214%^b%^C220%^ras%^C214%^s d%^C220%^oo%^C214%^r h%^C220%^andl%^C214%^e%^RESET%^%^C058%^. Thick planks give it some heft, making it quite solid.%^CRST%^");
    occupied = random(3);
    temperment = random(3) + 1;
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance")->move(this_object());
}

void look_cages(){
    object player;
    player = this_player();
    
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^These are solid %^C153%^steel%^C101%^, about half the height of a human. Some %^C222%^st%^C228%^ra%^C222%^w %^RESET%^%^C101%^has been strewn about the floor within, and are otherwise kept clean.%^CRST%^");
    if(occupied) tell_object(player, "\n%^RESET%^%^CRST%^%^C108%^A %^C064%^goblin %^C108%^lurks in one of the cages: %^RESET%^%^CRST%^%^C065%^small, green, and foul.%^CRST%^");
        
    return;
}

void look_goblin(){
    object player;
    player = this_player();
    
    if(!occupied) tell_object(player, "%^RESET%^%^CRST%^You do not notice that here.%^CRST%^");
    else{ 
        tell_object(player, "%^RESET%^%^CRST%^%^C108%^This nasty little %^C064%^goblin %^C108%^is trapped in one of the cages. It is typical of the breed: %^RESET%^%^CRST%^%^C065%^small, green, and foul. %^RESET%^%^C108%^It appears someone has made an attempt to clean this one by dousing it with water.%^CRST%^");
    }
    return;
}

int is_lab(){ return 1;}
int get_occupied() { return occupied;}
int get_temperment(){ return temperment;}

