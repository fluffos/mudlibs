#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("slab");
   set_short("%^RESET%^%^RED%^A %^ORANGE%^m%^RED%^o%^ORANGE%^l"
   "%^RED%^t%^ORANGE%^e%^RED%^n %^ORANGE%^s%^RED%^l%^ORANGE%^a%^RED%^b");
   set_long("%^RESET%^%^RED%^This slab has seemed to be recently formed and has "
            "steam coming out of the cracks.");
   set_weight(10);
   set_id( ({ "slab", "molten slab" }) );
}

int get()
{
 write("%^RESET%^%^ORANGE%^You pick up the slab and your hand burns from the heat "
       "and you quickly drop it and it cracks open. %^RED%^Lava %^ORANGE%^flows "
       "out of the slab dissolving it and it forms into a molten "
       "being.");
 say("%^RED%^"+ this_player()->query_cap_name()+ " picks up the slab and drops "
     "it instantly. Lava flows from the slab dissolving it and it forms "
     "into a molten being.");
 new( "/wizards/detach/being" )->move(environment(this_object()));
 this_object()->remove();
 return 0;
}


