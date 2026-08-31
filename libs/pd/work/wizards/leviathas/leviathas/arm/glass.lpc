# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("sword");
    
set_short("a glass sword");
    set_long("A sparkling, but otherwise plain and featureless glass sword. ");
    set_id(({"sword"}));
    set_wc(30);            
    set_type("blade");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
