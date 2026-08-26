/*
  Dark Courtyard
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  Tree Description updated by Kismet, written by Maenoh.
  
  -- Tlaloc --
*/

#include <std.h>
#include <move.h>

inherit "/std/templemisc";

int fruit;

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",0);
    set_temple("ashra");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(1);
    set_name("Dark Courtyard"); 
    set_short("%^RESET%^%^C240%^D%^C241%^a%^C242%^r%^C240%^k C%^RESET%^%^C241%^o%^C242%^u%^C241%^r%^C240%^t%^C241%^y%^C242%^a%^C241%^r%^C240%^d%^CRST%^");
    set_long("%^RESET%^%^C244%^Emerging from the suffocating confines of the %^RESET%^%^C022%^f%^C028%^o%^C034%^r%^C040%^e%^C028%^s%^C022%^t %^RESET%^%^C244%^you find yourself standing before the awing majesty of a %^C240%^massive temple%^RESET%^%^C244%^. The great courtyard is walled only by the forest itself, which gives way abruptly to the thick %^C028%^g%^C034%^r%^C040%^a%^C034%^s%^C028%^s %^RESET%^%^C244%^and winding %^C240%^obsidian paths%^RESET%^%^C244%^. Several %^RESET%^%^C024%^d%^C025%^a%^C026%^r%^C027%^k %^RESET%^%^C026%^s%^C025%^t%^C024%^r%^C025%^e%^C026%^a%^C027%^m%^C026%^s %^RESET%^%^C244%^wind their way through this %^RESET%^%^C029%^garden %^RESET%^%^C244%^courtyard, intersecting at a central ring that loops around a small grove. At the center of this grove encircled by dozens of %^RESET%^%^C093%^e%^C099%^x%^C105%^o%^C111%^t%^C117%^i%^C153%^c %^C147%^f%^C141%^l%^C135%^o%^C129%^w%^C092%^e%^C093%^r%^C099%^s %^RESET%^%^C244%^is a gnarled, %^RESET%^%^C247%^l%^RESET%^%^C058%^e%^C059%^a%^C247%^fl%^C249%^e%^RESET%^%^C247%^ss tr%^C102%^e%^C059%^e %^RESET%^%^C244%^with %^C240%^solid black bark %^RESET%^%^C244%^that bears an %^C248%^o%^C246%^i%^C243%^l%^C241%^y black %^RESET%^%^C244%^and %^C088%^r%^C160%^e%^C088%^d %^RESET%^%^C240%^f%^C241%^r%^C052%^u%^C088%^i%^C124%^t%^RESET%^%^C244%^. %^RESET%^%^C247%^Benches %^RESET%^%^C244%^are scattered alongside the %^C240%^twisting paths %^RESET%^%^C244%^and %^RESET%^%^C241%^bridges %^C244%^that cross over the streams, the %^RESET%^%^C046%^l%^C047%^u%^C048%^m%^C049%^i%^C050%^n%^C051%^o%^C087%^u%^C086%^s %^RESET%^%^C085%^p%^C084%^l%^C083%^a%^C082%^n%^C119%^t%^C120%^s %^RESET%^%^C244%^lending a splash of %^RESET%^%^C057%^c%^C056%^o%^C055%^l%^C054%^o%^C053%^r %^RESET%^%^C244%^and %^RESET%^%^C050%^l%^C051%^i%^C123%^g%^C122%^h%^C122%^t %^RESET%^%^C244%^to the otherwise %^RESET%^%^C240%^black surroundings%^RESET%^%^C244%^. %^RESET%^%^C240%^Statuary %^RESET%^%^C244%^of all sorts occupy the grounds, from feline to humanoid and %^C240%^m%^C241%^e%^C242%^n%^C243%^a%^C244%^c%^C242%^i%^C241%^n%^C240%^g %^RESET%^%^C244%^to %^RESET%^%^C052%^a%^C088%^g%^C124%^o%^C160%^n%^C196%^i%^C124%^z%^C088%^e%^C052%^d %^RESET%^%^C244%^watching over all that transpires here. Dwarfing all of it though is the colossal structure that towers over the yard, barely clinging to the plateau before the %^C240%^precipice%^RESET%^%^C244%^. Steep steps ascend to tremendous marble pillars that flank the entryway, a cavernous opening in the shape of a %^RESET%^%^C240%^s%^C241%^e%^C242%^r%^C243%^p%^C244%^e%^C242%^n%^C241%^t%^RESET%^%^C240%^'s %^RESET%^%^C244%^yawning maw. Adorned with windows of %^RESET%^%^C093%^g%^C092%^l%^C091%^o%^C090%^w%^C091%^i%^C092%^n%^C093%^g %^RESET%^%^C240%^s%^C089%^t%^C090%^a%^C091%^i%^C090%^n%^C089%^e%^RESET%^%^C240%^d g%^RESET%^%^C089%^l%^C090%^a%^C089%^s%^RESET%^%^C240%^s %^RESET%^%^C244%^and elegantly spired buttresses, this foreboding construct is truly a masterwork of the craft. Far overhead you can see the whirling %^RESET%^%^C240%^v%^C126%^o%^C127%^r%^C128%^t%^C126%^e%^C240%^x %^RESET%^%^C244%^of %^C240%^darkness %^RESET%^%^C244%^that crowns the %^RESET%^%^C240%^temple%^RESET%^%^C244%^, filling the air with %^RESET%^%^C124%^m%^C125%^a%^C126%^l%^C127%^e%^C128%^v%^C129%^o%^C128%^l%^C127%^e%^C126%^n%^C125%^t %^RESET%^%^C124%^e%^C125%^n%^C126%^e%^C127%^r%^C128%^g%^C129%^y%^RESET%^%^C244%^.%^CRST%^");
    set_smell("default","%^RESET%^%^C093%^You are surrounded by the thick scent floral scent of the many gardens.%^CRST%^");
    set_listen("default","%^RESET%^%^C092%^You hear the rustling of the trees and the gentle gurgling of the streams.%^RESET%^");
    set_items(([
        ({"temple"}) : "%^RESET%^%^C244%^Looming over the courtyard, this awing structure radiates a %^RESET%^%^C124%^m%^C125%^a%^C126%^l%^C127%^i%^C125%^g%^C124%^n a%^C125%^u%^C126%^r%^C124%^a %^RESET%^%^C244%^of %^RESET%^%^C088%^terrible power%^RESET%^%^C244%^. Its tall spires and flawless %^C240%^onyx walls %^RESET%^%^C244%^have been shaped with elegantly curving ridges and balconies with elaborately engraved balustrades. The %^RESET%^%^C093%^w%^C092%^i%^C091%^n%^C090%^d%^C091%^o%^C092%^w%^C093%^s %^RESET%^%^C244%^which adorn near every flat expanse of the structure are works of art, the %^RESET%^%^C240%^s%^C089%^t%^C090%^a%^C091%^i%^C090%^n%^C089%^e%^RESET%^%^C240%^d p%^RESET%^%^C089%^a%^C090%^n%^C091%^e%^C089%^l%^RESET%^%^C240%^s %^RESET%^%^C244%^depicting various scenes of a %^RESET%^%^C093%^b%^C092%^e%^C091%^a%^C129%^u%^C128%^t%^C129%^i%^C091%^f%^C092%^u%^C093%^l %^RESET%^%^C241%^black-skinned %^RESET%^%^C244%^woman dancing among encircling %^C241%^ravens%^RESET%^%^C244%^. The enormous likeness of a striking %^RESET%^%^C240%^s%^C241%^e%^C242%^r%^C243%^p%^C244%^e%^C241%^n%^C240%^t %^RESET%^%^C244%^provides the cavernous entry to the temple's %^RESET%^%^C240%^dark interior%^RESET%^%^C244%^.%^CRST%^",
        ({"gardens","garden"}) : "%^RESET%^%^C028%^The gardens are spread about the network of %^RESET%^%^C240%^paths%^RESET%^%^C028%^ and %^RESET%^%^C026%^s%^C025%^t%^C024%^r%^C025%^e%^C026%^a%^C027%^m%^C026%^s %^RESET%^%^C028%^offering an %^RESET%^%^C093%^e%^C099%^x%^C105%^o%^C111%^t%^C117%^i%^C153%^c %^RESET%^%^C028%^blend of %^RESET%^%^C046%^l%^C047%^u%^C048%^m%^C049%^i%^C050%^n%^C051%^o%^C087%^u%^C086%^s %^RESET%^%^C085%^p%^C084%^l%^C083%^a%^C082%^n%^C119%^t%^C120%^s%^RESET%^%^C028%^. The softly %^RESET%^%^C093%^g%^C092%^l%^C091%^o%^C129%^w%^C128%^i%^C129%^n%^C091%^g %^RESET%^%^C092%^b%^C093%^u%^C092%^l%^C091%^b%^C129%^s %^RESET%^%^C028%^of these exquisite %^RESET%^%^C147%^f%^C141%^l%^C135%^o%^C129%^w%^C092%^e%^C093%^r%^C099%^s %^RESET%^%^C028%^serves to cast the entire courtyard into a %^C129%^s%^C135%^u%^C141%^r%^C147%^r%^C141%^e%^C135%^a%^C129%^l l%^C135%^i%^C141%^g%^C135%^h%^C129%^t%^RESET%^%^C028%^.%^CRST%^",
        ({"grove","tree"}) : "%^RESET%^%^C244%^This small grove contains a %^RESET%^%^C022%^g%^C028%^a%^C029%^r%^C030%^d%^C028%^e%^C022%^n %^RESET%^%^C244%^of %^C093%^d%^C092%^a%^C091%^r%^C090%^k%^C089%^l%^C090%^y %^C053%^c%^C054%^o%^C055%^l%^C056%^o%^C057%^r%^C093%^e%^C092%^d %^RESET%^%^C091%^f%^C090%^l%^C089%^o%^C053%^r%^C054%^a%^RESET%^%^C244%^. These however serve only as a momentary distraction from the gnarled, %^RESET%^%^C247%^l%^RESET%^%^C058%^e%^C059%^a%^C247%^fl%^C249%^e%^RESET%^%^C247%^ss tr%^C102%^e%^C059%^e %^RESET%^%^C244%^which sprouts from the center, its twisted limbs bearing an %^RESET%^%^C062%^o%^C063%^i%^C069%^l%^C062%^y %^RESET%^%^C240%^black%^RESET%^%^C244%^ and %^RESET%^%^C088%^r%^C160%^e%^C088%^d %^RESET%^%^C240%^f%^C241%^r%^C052%^u%^C088%^i%^C124%^t%^RESET%^%^C244%^. The same %^C241%^ichor %^C244%^seems to %^RESET%^%^C088%^b%^C124%^l%^C196%^e%^C124%^e%^C088%^d %^RESET%^%^C244%^from the %^C247%^bark %^C244%^of the tree itself. Swaying from the naked limbs are several %^RESET%^%^C088%^severed %^RESET%^%^C244%^heads in various states of %^RESET%^%^C100%^decomposition%^RESET%^%^C244%^, %^C241%^flies %^C244%^buzzing about and %^RESET%^%^C231%^m%^C255%^a%^C230%^g%^C255%^g%^C231%^o%^C255%^t%^C230%^s %^RESET%^%^C244%^feasting on their %^C102%^d%^C101%^e%^C151%^c%^C152%^a%^C101%^y%^C102%^i%^C151%^n%^C152%^g %^RESET%^%^C244%^eyes.%^CRST%^",
        ({"statues",""}) : "%^RESET%^%^C023%^The %^RESET%^%^C022%^g%^C028%^a%^C034%^r%^C040%^d%^C034%^e%^C028%^n%^C022%^s %^RESET%^%^C023%^are filled with %^RESET%^%^C240%^demonic effigies%^RESET%^%^C023%^, %^C241%^feline representations%^RESET%^%^C023%^, and %^RESET%^%^C242%^cowled humanoids %^RESET%^%^C023%^with %^RESET%^%^C240%^s%^C241%^o%^C242%^r%^C243%^r%^C244%^o%^C243%^w%^C242%^f%^C241%^u%^C240%^l %^RESET%^%^C023%^expressions reaching towards the %^RESET%^%^C240%^tree %^RESET%^%^C023%^in the center of the %^RESET%^%^C028%^g%^C029%^r%^C038%^o%^C029%^v%^C028%^e%^RESET%^%^C023%^.%^CRST%^",
        ({"forest",""}) : "%^RESET%^%^C028%^The %^RESET%^%^C022%^dense vegetation %^RESET%^%^C028%^cuts off abruptly at the edge of the courtyard, held back by no wall yet seemingly unwilling to grow any closer to the temple grounds.%^CRST%^",
        ({"vortex","darkness"}) : "%^RESET%^%^C244%^Spinning slowly above this looming structure that dominates the end of the plateau is a halo of %^RESET%^%^C240%^g%^C241%^l%^C242%^o%^C241%^o%^C240%^m%^RESET%^%^C244%^. The %^RESET%^%^C240%^darkness r%^C055%^o%^C056%^i%^C055%^l%^RESET%^%^C240%^s %^RESET%^%^C244%^and seethes with otherworldly %^RESET%^%^C124%^e%^C125%^n%^C126%^e%^C127%^r%^C125%^g%^C124%^y %^RESET%^%^C244%^and %^RESET%^%^C129%^v%^C135%^i%^C141%^o%^C147%^l%^C141%^e%^C135%^t %^RESET%^%^C129%^l%^C135%^i%^C141%^g%^C147%^h%^C141%^t%^C135%^n%^C129%^i%^C135%^n%^C141%^g %^RESET%^%^C129%^f%^C135%^l%^C141%^a%^C153%^s%^C248%^h%^C247%^e%^C245%^s %^RESET%^%^C244%^and %^RESET%^%^C129%^s%^C135%^t%^C141%^r%^C153%^e%^C248%^a%^C247%^k%^C246%^s %^RESET%^%^C244%^through its %^RESET%^%^C240%^depths%^RESET%^%^C244%^.%^CRST%^",
    ]));
    set_exits(([
        "northeast" : "/d/magic/temples/shar_path5",
        "temple" : "/d/magic/temples/ashra/hall",
    ]));
    
    fruit = 5;
}

void init()
{
    ::init();
    add_action("pick_fruit", "pick");
}

int pick_fruit(string str)
{
    object obj;
    if (!str) {
        tell_object(TP, "Pick what?");
        return 1;
    }
    if (str != "fruit" && str != "dark fruit") {
        return 0;
    }
    if (fruit > 0) {
        tell_object(TP, "%^RESET%^%^C244%^You pick one of the %^RESET%^%^C240%^f%^C241%^r%^C052%^u%^C088%^i%^C124%^t%^C160%^s %^RESET%^%^C244%^from the %^RESET%^%^C241%^tree%^RESET%^%^C244%^.%^CRST%^");
        tell_room(TO, "%^RESET%^%^C244%^" + TPQCN + " %^RESET%^%^C244%^picks one of from the %^RESET%^%^C240%^f%^C241%^r%^C052%^u%^C088%^i%^C124%^t%^C160%^s %^RESET%^%^C244%^from the %^RESET%^%^C241%^tree.%^CRST%^", TP);
        obj = new("/d/magic/temples/misc/shar_fruit");
        if (obj->move(TP) != MOVE_OK) {
            tell_object(TP, "You drop it as fast as you pick it!");
            tell_room(TO, "" + TPQCN + " drops it!", TP);
            obj->move(ETP);
        }
        fruit--;
        return 1;
    }else {
        tell_object(TP,"%^RESET%^%^C240%^A nearby garden keeper waves you away muttering about that being enough for today%^RESET%^.");
           tell_room(TO,"%^RESET%^%^C240%^As "+TPQCN+" %^RESET%^%^C240%^tries to pick a fruit from the tree, a nearby gardener waves "+TP->QO+" away, muttering about that being enough for today.",TP);
        return 1;
    }
}
   
