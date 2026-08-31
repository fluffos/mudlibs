# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("dagger");
    
set_short("%^RESET%^%^CYAN%^R%^GREEN%^%^BOLD%^i%^RESET%^%^CYAN%^sk"
          "%^BOLD%^%^GREEN%^y %^RESET%^%^CYAN%^D%^BOLD%^%^GREEN%^a"
          "%^RESET%^%^CYAN%^gg%^BOLD%^%^GREEN%^e%^RESET%^%^CYAN%^r%^RESET%^");
    set_long("A creepy-looking dagger with a tinted-green blade and cyan hilt. ");
    set_id(({"dagger", "knife", "risky dagger"}));
    set_wc(10);            
    set_type("knife");
    set_mass(100);   

}
int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

