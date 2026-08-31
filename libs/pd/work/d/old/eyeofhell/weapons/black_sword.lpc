#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Black Sword");
    set("id", ({ "sword", "blade" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Sword%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This sword was made by the She raknid, It is well crafted having been done by a spider.%^RESET%^" );
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(14);
    set_type("blade");
    set_decay_rate(200);
    set("skill level", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 60)
	return 1;
}
int can_wield() {
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("sword") >= 200)
    {
	write("%^BOLD%^%^BLACK%^The sword forms to your hand as if it were made for you.");
    }
    return 1;
}

int weapon_hit() 
{
    int result;
    object atk;
    int num;
    if (this_player()->query_class() != "fighter"  ||
      this_player()->query_skill("blade") < 200)
    {
	write("The sword cuts your hand as you attempt to wield it.");
	say((string)this_player()->query_cap_name() + " screams and drops the 
sword clutching thier bloody hand!");
            this_player()->force_me("drop sword");
        }
        num = random(200);
        atk = (object)this_player()->query_current_attacker();
        if(num < 100)
        {
                write("Your sword slashes deep into"+ atk->query_cap_name() +"'s 
face!");
                say((string)this_player()->query_cap_name() + " slashes " + 
atk->query_cap_name() + "'s face open makeing blood splurt everywhere!");
                result = 10 +random(30);
                this_player()->add_sp(result);
                return result;
        }
          return 0; 
        num = random(200);
        atk = (object)this_player()->query_current_attacker();
        if(num >200)
        {
                write("Your sword guts"+ atk->query_cap_name() +"'s 
stomach!");
                say((string)this_player()->query_cap_name() + " guts " + atk->query_cap_name() + "'s stomach, ripping out its insides!");
                result = 10 +random(30);
                this_player()->add_sp(result);
                return result;
       }
        return 0; 
} 
