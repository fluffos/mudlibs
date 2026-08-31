# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("scepter");
    
set_short("%^YELLOW%^A %^CYAN%^Q%^YELLOW%^uee%^CYAN%^n%^YELLOW%^'%^CYAN%^s Sc%^YELLOW%^e%^CYAN%^pt%^YELLOW%^e%^CYAN%^r");
    set_long("This scepter must have been looted by a vampire from the corpse of a VERY wealthy queen.  It is solid gold, quite heavy, adorned with cyan-coloured jewels. ");
    set_id(({"scepter", "staff"}));
    set_wc(15);            
    set_type("blunt");
    set_mass(50);   

}
int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

