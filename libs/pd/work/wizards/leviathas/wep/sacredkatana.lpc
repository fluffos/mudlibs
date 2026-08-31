# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("katana");
    
set_short("a sacred katana");
    set_long("This katana is the weapon of Balra'Zin.  It is rather plain looking. ");
    set_id(({"katana"}));
    set_wc(25);            
set_hit((:this_object(), "weapon_hit":));
    set_type("blade");   

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
int weapon_hit(object ob) {
 if (random(100)>1000) {
   write("Your katana burts into purple flames as you attack relentlessly.");
message("info", this_player()->query_cap_name()+"'s katana burts into purple flames as it attacks you relentlessly .",
ob);
message("info", this_player()->query_cap_name()+"'s katana burts into purple flames as it attacks
"+ob->query_cap_name()+" relentlessly.", environment(ob), ({ ob, this_player() }) );

return random(1);
}
}

