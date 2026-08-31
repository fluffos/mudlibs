# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("dagger");
    
set_short("%^RED%^D%^BOLD%^a%^RESET%^%^RESET%^gg%^BOLD%^%^RED%^e%^RESET%^%^RED%^r %^BOLD%^o%^RESET%^%^RED%^f t%^RESET%^h%^RED%^e %^D%^BOLD%^ea%^RESET%^%^RED%^d%^RESET%^");
    set_long("A dagger crafted to look like a cricified corpse. ");
    set_id(({"dagger", "dagger of the dead"}));
    set_wc(15);            
    set_type("knife");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
