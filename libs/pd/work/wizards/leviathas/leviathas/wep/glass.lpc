# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("sword");
    
set_short("%^CYAN%^a gl%^RESET%^%^BOLD%^as%^RESET%^s s%^BOLD%^wo%^RESET%^%^CYAN%^rd%^RESET%^");
    set_long("A sparkling, but otherwise plain and featureless glass sword. ");
    set_id(({"sword"}));
    set_wc(30);            
set_hit((:this_object(), "weapon_hit":));
    set_type("blade");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
int weapon_hit(object ob) {
 if (random(100)>85) {
   write("The glass cuts your opponent.");
message("info", this_player()->query_cap_name()+"'s glass sword cuts you.", ob);
message("info", this_player()->query_cap_name()+"'s glass sword cuts "+ob->query_cap_name()+".", environment(ob), ({ ob, this_player() }) );

return random(30);
}
}
