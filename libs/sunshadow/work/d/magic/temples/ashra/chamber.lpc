/*
  Chamber of Whispers
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>
#include <player_housing.h>

inherit "/std/templemisc";

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",0);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_temple("ashra");
    set_name("Chamber of Whispers"); 
    set_short("%^RESET%^%^C244%^Chamber of W%^RESET%^%^C243%^h%^C242%^i%^C241%^s%^C240%^p%^C241%^e%^C242%^r%^C243%^s%^RESET%^");
    set_long("%^RESET%^%^C244%^The billowing %^RESET%^%^C240%^w%^C241%^i%^C242%^s%^C241%^p%^RESET%^%^C240%^s %^RESET%^%^C244%^of %^RESET%^%^C240%^black cloth %^RESET%^%^C244%^hanging shroud-like across the entrance give way to a %^RESET%^%^C240%^s%^C241%^e%^C242%^a %^RESET%^%^C243%^o%^C244%^f %^RESET%^%^C243%^d%^C242%^a%^C241%^r%^C240%^k%^C241%^n%^C242%^e%^C243%^s%^C242%^s %^RESET%^%^C244%^that hovers %^RESET%^%^C240%^thick %^RESET%^%^C244%^in the air. Underfoot the floor is lost in a %^RESET%^%^C247%^m%^C245%^i%^C243%^a%^C242%^s%^C241%^m%^C240%^a %^RESET%^%^C244%^of %^RESET%^%^C240%^shadow %^RESET%^%^C244%^that creeps along at ankle height like a %^RESET%^%^C247%^rolling fog%^RESET%^%^C244%^. Thick %^RESET%^%^C241%^black spines %^RESET%^%^C244%^curve upward from the balcony's edge like %^RESET%^%^C240%^t%^C242%^w%^C240%^i%^C243%^s%^C240%^t%^C245%^e%^C240%^d %^RESET%^%^C244%^taloned fingers. Hanging from each of these spines are small %^RESET%^%^C231%^c%^C015%^a%^C230%^g%^RESET%^%^C231%^e l%^RESET%^%^C015%^a%^C230%^n%^C231%^t%^C230%^e%^RESET%^%^C015%^r%^C230%^n%^C231%^s %^RESET%^%^C244%^that cast the surroundings in a %^RESET%^%^C240%^f%^C055%^l%^C056%^i%^C241%^c%^C056%^k%^C057%^e%^C240%^r%^C054%^i%^C055%^n%^C240%^g %^RESET%^%^C056%^v%^C055%^i%^C054%^o%^C055%^l%^C056%^e%^C055%^t %^RESET%^%^C054%^l%^C055%^i%^C056%^g%^C055%^h%^C054%^t%^RESET%^%^C244%^. Dominating the center of the room is an enormous %^RESET%^%^C054%^r%^C241%^ound tabl%^C054%^e %^RESET%^%^C244%^surrounded by smaller comfortable-looking %^RESET%^%^C241%^c%^C243%^h%^C244%^a%^C243%^i%^C241%^rs%^RESET%^%^C244%^. Rising from the rear of the balcony facing toward the large table is a jagged %^RESET%^%^C240%^throne %^RESET%^%^C244%^of %^RESET%^%^C240%^g%^C243%^l%^C245%^i%^C247%^t%^C240%^t%^C242%^e%^C245%^r%^C247%^i%^C241%^n%^C240%^g jet %^RESET%^%^C244%^that is flanked by two %^RESET%^%^C247%^w%^C248%^r%^C249%^a%^C250%^i%^C248%^t%^C247%^h%^RESET%^%^C244%^-like %^RESET%^%^C247%^figures%^RESET%^%^C244%^. Beyond the balcony itself floats an enormous %^RESET%^%^C240%^orb %^RESET%^%^C244%^of %^RESET%^%^C240%^solid darkness %^RESET%^%^C244%^encased in a corona of %^RESET%^%^C056%^v%^C055%^i%^C054%^o%^C055%^l%^C056%^e%^C055%^t %^RESET%^%^C054%^f%^C055%^l%^C056%^a%^C055%^m%^C054%^e%^RESET%^%^C244%^. Below the balcony, you can barely make out the light of the chapel %^RESET%^%^C240%^w%^C053%^i%^C054%^n%^C055%^d%^C056%^o%^C055%^w%^RESET%^%^C240%^s %^RESET%^%^C244%^far below. All around you, %^RESET%^%^C087%^w%^C123%^h%^C159%^i%^C195%^s%^C159%^p%^C123%^e%^C087%^r%^C123%^s %^RESET%^%^C244%^echo through the dark and you cannot help but wonder what secrets these %^RESET%^%^C033%^e%^C039%^p%^C045%^h%^C051%^e%^C087%^m%^C081%^e%^C075%^r%^C069%^a%^C075%^l %^RESET%^%^C033%^v%^C081%^o%^C087%^i%^C051%^c%^C045%^e%^C039%^s %^RESET%^%^C244%^hold.%^CRST%^");
    set_smell("default","%^RESET%^%^C093%^The heady, sweet aroma of an exotic incense is in the air.%^RESET%^");
    set_listen("default","%^RESET%^%^C092%^You hear the soft rustle of cloth, clinking of swaying chains and the whispers that fill the air around you.%^RESET%^");
    set_items(([
        ({"shadow","shade","darkness"}) : "%^RESET%^%^C244%^All around you, the air is filled with a pervasive %^RESET%^%^C241%^gloom %^RESET%^%^C244%^that whirls and flows like a sea of %^RESET%^%^C240%^darkness%^RESET%^%^C244%^. %^RESET%^%^C241%^Dark shapes %^RESET%^%^C244%^swim through this sea just beyond your vision revealed only barely by the %^RESET%^%^C240%^f%^C054%^l%^C055%^i%^C241%^c%^C055%^k%^C056%^e%^C240%^r%^C054%^i%^C055%^n%^C240%^g %^RESET%^%^C015%^l%^C231%^a%^C255%^n%^C230%^t%^C255%^e%^C231%^r%^C015%^n %^RESET%^%^C054%^l%^C055%^i%^C056%^g%^C055%^h%^C054%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"lanterns","spines","lantern","spine"}) : "%^RESET%^%^C244%^Like the taloned fingers of some %^RESET%^%^C088%^d%^C124%^e%^C160%^m%^C196%^o%^C160%^n%^C124%^i%^C088%^c %^RESET%^%^C244%^giant, curving %^RESET%^%^C240%^s%^C241%^p%^C088%^i%^C124%^n%^C241%^e%^C240%^s %^RESET%^%^C244%^curl inward from the balcony rail. Hanging from swaying %^RESET%^%^C251%^c%^C250%^h%^C249%^a%^C248%^i%^C250%^n%^C251%^s %^RESET%^%^C244%^at the tip of each of these spines are %^RESET%^%^C015%^i%^C231%^v%^C230%^o%^C255%^r%^C231%^y %^RESET%^%^C015%^c%^C231%^a%^C230%^g%^C255%^e %^RESET%^%^C231%^l%^C015%^a%^C231%^n%^C230%^t%^C255%^e%^C230%^r%^C231%^n%^C015%^s %^RESET%^%^C244%^that hold %^RESET%^%^C240%^f%^C054%^l%^C055%^i%^C241%^c%^C055%^k%^C056%^e%^C240%^r%^C054%^i%^C055%^n%^C240%^g %^RESET%^%^C055%^orbs %^RESET%^%^C244%^of %^RESET%^%^C054%^v%^C055%^i%^C056%^o%^C054%^l%^C055%^e%^C056%^t %^RESET%^%^C054%^l%^C055%^i%^C056%^g%^C054%^h%^C055%^t%^RESET%^%^C244%^.%^CRST%^",
        ({"throne"}) : "%^RESET%^%^C244%^Rising out of the murk that shrouds the floor, this glittering piece of %^RESET%^%^C240%^jet %^RESET%^%^C244%^has been fashioned into an %^RESET%^%^C240%^intimidating throne%^RESET%^%^C244%^. Wicked %^RESET%^%^C240%^s%^C241%^p%^C088%^i%^C124%^n%^C241%^e%^C240%^s %^RESET%^%^C244%^and %^RESET%^%^C240%^b%^C241%^a%^C088%^r%^C241%^b%^C240%^s %^RESET%^%^C244%^adorn its back and arms and %^RESET%^%^C129%^glittering %^RESET%^%^C129%^a%^C128%^m%^C127%^e%^C126%^t%^C125%^h%^C089%^y%^C090%^s%^C091%^t %^RESET%^%^C092%^g%^C093%^e%^C091%^m%^C091%^s %^RESET%^%^C135%^glow softly %^RESET%^%^C244%^at the ends of each armrest. Soft %^RESET%^%^C054%^v%^C055%^i%^C056%^o%^C054%^l%^C055%^e%^C056%^t %^RESET%^%^C054%^c%^C055%^u%^C056%^s%^C054%^h%^C055%^i%^C056%^o%^C054%^n%^C055%^s %^RESET%^%^C244%^provide a %^RESET%^%^C240%^s%^C241%^i%^C242%^n%^C240%^f%^C241%^u%^C242%^l%^C240%^l%^C241%^y %^RESET%^%^C244%^comfortable seat worthy of %^RESET%^%^C020%^royalty%^RESET%^%^C244%^.%^CRST%^",
        ({"orb","eye"}) : "%^RESET%^%^C244%^Floating high above the balcony is the central %^RESET%^%^C240%^e%^C241%^y%^C242%^e %^RESET%^%^C244%^of the %^RESET%^%^C240%^darkness %^RESET%^%^C244%^that flows throughout the temple. %^RESET%^%^C240%^A%^C241%^m%^C242%^o%^C243%^r%^C240%^p%^C241%^h%^C242%^o%^C243%^u%^C240%^s %^RESET%^%^C241%^t%^C242%^e%^C243%^n%^C240%^d%^C241%^r%^C242%^i%^C243%^l%^C240%^s %^RESET%^%^C241%^w%^C242%^r%^C243%^i%^C240%^g%^C241%^g%^C242%^l%^C243%^e %^RESET%^%^C244%^and %^RESET%^%^C240%^w%^C241%^r%^C242%^i%^C243%^t%^C240%^h%^C241%^e %^RESET%^%^C244%^outward from the orb all surrounded by the %^RESET%^%^C054%^p%^C055%^u%^C056%^r%^C054%^p%^C055%^l%^C056%^e %^RESET%^%^C054%^a%^C055%^u%^C056%^r%^C054%^a %^RESET%^%^C244%^of %^RESET%^%^C055%^flame %^RESET%^%^C244%^that envelopes the %^RESET%^%^C240%^orb %^RESET%^%^C244%^itself. As you look upon the orb you cannot help but feel a sense of %^RESET%^%^C241%^awareness %^RESET%^%^C244%^from within it...almost as though it is looking right back at you...%^CRST%^",
        ({"floor"}) : "%^RESET%^%^C244%^The %^RESET%^%^C241%^shadows %^RESET%^%^C244%^s%^C241%^w%^C242%^i%^C241%^r%^C240%^l %^RESET%^%^C244%^around your feet, concealing the floor like a %^RESET%^%^C247%^thick fog%^RESET%^%^C244%^.%^CRST%^",
        ({"ceiling"}) : "%^RESET%^%^C244%^You cannot see the ceiling through the %^RESET%^%^C240%^impenetrable darkness %^RESET%^%^C244%^overhead and it leaves you wondering just how high this tower rises.%^CRST%^",
        ({"cloth","shroud"}) : "%^RESET%^%^C244%^These wisps of %^RESET%^%^C240%^g%^C241%^a%^C242%^u%^C241%^z%^C240%^y black cloth %^RESET%^%^C244%^billow softly across the archway, partially concealing the landing that lies beyond.%^CRST%^",
    ]));
    set_exits(([
       "south" : "/d/magic/temples/ashra/balcony",
    ]));
    set_property("scry proof", SCRYWARD_LEGENDARY);
}

void reset()
{
    object ob;
    ::reset();
    
    if(!present("mirror"))
    {
        ob = new("/d/magic/obj/mirror");
        
        if(ob)
        {
            ob->set_short("%^RESET%^%^C241%^A %^RESET%^%^C240%^glossy %^RESET%^%^C240%^black table %^RESET%^%^C241%^with a %^C247%^m%^C245%^i%^C250%^r%^C247%^r%^C245%^o%^C247%^r %^RESET%^%^C250%^f%^C247%^i%^C245%^n%^C247%^i%^C250%^s%^C247%^h%^CRST%^");
            ob->set_long("%^RESET%^%^C244%^This luxurious round table rises from a central pillar that is anchored to the floor somewhere beneath the %^RESET%^%^C240%^murky darkness %^RESET%^%^C244%^underfoot. A %^RESET%^%^C054%^ring %^RESET%^%^C244%^of %^RESET%^%^C054%^deep purple %^RESET%^%^C244%^pine surrounds the %^RESET%^%^C240%^glossy obsidian disk %^RESET%^%^C244%^set in its center. The surface of the obsidian is absolutely flawless and reflective like a pitch black %^C247%^m%^C245%^i%^C250%^r%^C247%^r%^C245%^o%^C247%^r%^RESET%^%^C244%^. Surrounding the table are a collection of %^RESET%^%^C054%^matching chairs%^RESET%^%^C244%^, %^RESET%^%^C054%^dark purple pine %^RESET%^%^C244%^with %^RESET%^%^C241%^black v%^C243%^e%^C247%^l%^C241%^v%^C243%^e%^C247%^t %^RESET%^%^C241%^cushions%^RESET%^%^C244%^.%^CRST%^");
            ob->set_id( ({ "mirror", "fine mirror", "table", "black table", "mirror table" }) );
            ob->move(this_object());
        }
    }
}

/*
Items: Obsidian round table    Descrip: %^BOLD%^%^BLACK%^This luxurious round table rises from a central pillar that is anchored to the floor somewhere beneath the murky darkness underfoot. A %^RESET%^%^MAGENTA%^ring %^BOLD%^%^BLACK%^of %^RESET%^%^MAGENTA%^deep purple %^BOLD%^%^BLACK%^pine surrounds the glossy obs%^WHITE%^i%^BLACK%^d%^RESET%^i%^BOLD%^a%^BLACK%^n disk set in its center. The surface of the obsidian is absolutely flawless and refl%^RESET%^e%^BOLD%^%^BLACK%^ct%^WHITE%^i%^BLACK%^ve like a pitch black %^RESET%^mirror%^BOLD%^%^BLACK%^. Surrounding the table are a collection of %^RESET%^%^MAGENTA%^matching chairs%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^dark purple pine %^BOLD%^%^BLACK%^with glossy black cushions.%^RESET%^
                                             *Acts as mirror for scrying*

Echoes : %^BOLD%^%^BLACK%^A serpentine tendril snakes out of the darkness overhead, reaching toward you before diving back into the murky sea.%^RESET%^
       
             %^BOLD%^%^BLACK%^A %^BLUE%^c%^CYAN%^o%^BLUE%^ld %^CYAN%^shiver %^BLACK%^runs up your spine as you suddenly become aware of some terrible presence watching over you...%^RESET%^
           
            %^BOLD%^%^BLACK%^The shade overhead ripples as something large passes just above its surface.%^RESET%^

      
            %^BOLD%^%^BLACK%^The %^WHITE%^wr%^CYAN%^a%^WHITE%^ith%^CYAN%^l%^WHITE%^y g%^CYAN%^u%^WHITE%^ar%^CYAN%^d%^WHITE%^s %^BLACK%^fl%^WHITE%^i%^BLACK%^ck%^WHITE%^e%^BLACK%^r and their burning %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t e%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s seem to bore into you.%^RESET%^

Guards: %^BOLD%^C%^CYAN%^e%^WHITE%^l%^CYAN%^e%^BLACK%^s%^WHITE%^ti%^BLACK%^a%^WHITE%^l wr%^CYAN%^a%^BLACK%^i%^WHITE%^th%^RESET%^		

Descrip: %^BOLD%^%^BLACK%^Tattered black robes hang loosely on the %^WHITE%^tr%^CYAN%^a%^WHITE%^nsl%^CYAN%^u%^WHITE%^cent eth%^CYAN%^e%^WHITE%^re%^CYAN%^a%^WHITE%^l fl%^CYAN%^e%^WHITE%^sh %^BLACK%^of this otherwordly being. Long dark hair spills down across its shoulders framing a %^WHITE%^androgynously beautiful face%^BLACK%^. Its %^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s are empty black pools with glowing %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rpl%^BOLD%^e %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^p%^BOLD%^i%^RESET%^%^MAGENTA%^ls %^BOLD%^%^BLACK%^that look at the living with a cold hunger. Terrible black taloned hands curl at its sides eagerly and folded on its back are a pair of raven black wings.%^RESET%^
*/