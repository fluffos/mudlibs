#include <std.h>;
inherit ROOM;

int count = 0;

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set_property("no teleport",1);
   set_smell("default", "The air is thick with the natural smells of rebirth");
   set_listen("default", "You can't hear anything.");
   set_short("%^BOLD%^%^GREEN%^A Pulsating Cocoon");
   set_long("%^BOLD%^%^BLACK%^A l%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^ge %^BOLD%^%^BLACK%^p%^GREEN%^u%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^sa%^RESET%^%^GREEN%^t%^BOLD%^i%^BLACK%^n%^RESET%^%^GREEN%^g %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^c%^RESET%^oo%^BOLD%^%^BLACK%^n%^RESET%^");
   set_heart_beat(3);
}

int setup_cocoon(string str)
{
    switch(str)
    {
        case "plant":
        set_long("%^RESET%^%^GREEN%^A haze of v%^BOLD%^e%^RESET%^%^ORANGE%^r%^GREEN%^d%^BOLD%^an%^RESET%^%^GREEN%^t g%^BOLD%^r%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n %^RESET%^%^GREEN%^fills your vision, as a %^WHITE%^f%^BOLD%^a%^RESET%^i%^BOLD%^n%^RESET%^t %^BOLD%^l%^RESET%^ig%^BOLD%^h%^RESET%^t %^GREEN%^permeates the cocoon wrapping around you. Tendrils of animate vegetation %^ORANGE%^wr%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^th%^BOLD%^%^BLACK%^e %^RESET%^%^GREEN%^about, while e%^BOLD%^me%^WHITE%^r%^GREEN%^al%^RESET%^%^GREEN%^d c%^BOLD%^hl%^WHITE%^o%^GREEN%^r%^RESET%^%^GREEN%^o%^BOLD%^p%^WHITE%^h%^GREEN%^yl%^RESET%^%^GREEN%^l skirt the periphery of the membranes that make up the walls of your domain. It is %^RED%^warm %^GREEN%^and %^CYAN%^humid %^GREEN%^in here, and heady fragrances swirl in %^CYAN%^m%^BOLD%^i%^WHITE%^s%^CYAN%^t%^RESET%^%^CYAN%^y v%^BOLD%^a%^WHITE%^p%^CYAN%^or%^RESET%^%^CYAN%^s%^GREEN%^.%^RESET%^");
        break;
        
        case "animal":
        set_long("%^RESET%^%^RED%^A h%^BOLD%^e%^MAGENTA%^a%^RED%^r%^RESET%^%^RED%^t%^BOLD%^b%^MAGENTA%^e%^RED%^a%^RESET%^%^RED%^t %^BOLD%^e%^MAGENTA%^c%^RED%^h%^RESET%^%^RED%^o%^BOLD%^e%^RESET%^%^RED%^s all around you, %^BOLD%^%^BLACK%^loud %^RESET%^%^RED%^and %^ORANGE%^thunderous %^RED%^and %^MAGENTA%^visceral%^RED%^. The gloom is only broken by traces of light breaking through the fleshy walls of this cocoon, illuminating the flow of blood through a spider web of connecting %^BOLD%^v%^RESET%^%^MAGENTA%^e%^RED%^s%^BOLD%^s%^RESET%^%^RED%^e%^MAGENTA%^l%^BOLD%^%^RED%^s%^RESET%^%^RED%^. It is %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^st%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^c%^RESET%^tin%^BOLD%^%^BLACK%^g %^RESET%^%^RED%^and %^BOLD%^sw%^RESET%^%^RED%^e%^BOLD%^lt%^RESET%^%^RED%^e%^BOLD%^ri%^RESET%^%^RED%^n%^BOLD%^g%^RESET%^%^RED%^, inundating you with anxious anticipation.%^RESET%^");
        break;
        
        case "human":
        set_long("%^RESET%^%^ORANGE%^The %^RED%^p%^BOLD%^%^MAGENTA%^u%^RED%^l%^RESET%^%^RED%^s%^BOLD%^%^MAGENTA%^i%^RED%^n%^RESET%^%^RED%^g %^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^i%^BOLD%^s%^RESET%^%^MAGENTA%^s%^BOLD%^u%^RESET%^%^MAGENTA%^e %^ORANGE%^surrounding you radiates %^RED%^w%^BOLD%^a%^RESET%^%^RED%^rm%^BOLD%^th %^RESET%^%^ORANGE%^and %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^u%^BOLD%^cc%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^%^ORANGE%^. It is safe here, the walls of the %^BOLD%^%^BLACK%^c%^WHITE%^o%^RESET%^c%^BOLD%^%^BLACK%^o%^RESET%^o%^BOLD%^n %^RESET%^%^ORANGE%^standing guard against the world. A %^WHITE%^w%^BOLD%^%^BLACK%^h%^RESET%^is%^BOLD%^%^BLACK%^pe%^RESET%^r %^ORANGE%^of cognizant thought seems to come and go like some %^CYAN%^ce%^BOLD%^re%^WHITE%^b%^CYAN%^r%^RESET%^%^CYAN%^al %^BOLD%^%^WHITE%^t%^CYAN%^i%^RESET%^%^CYAN%^de%^GREEN%^, %^ORANGE%^wreathing about you and changing you as the binding tendrils reshape and mould you into something %^BOLD%^new%^RESET%^%^ORANGE%^.%^RESET%^");
        break;
    }
    
    return 1;
}