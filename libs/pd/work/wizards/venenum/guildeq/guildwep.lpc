#include <venguilds.h>
#include <std.h>
inherit WEAPON;
inherit GUILDEQ;

string use;
string targ;
string room;
string wield;
string unwield;
string denied;

int weapon_hit();

void create() {
    :: create();
    set_wc(13);
    set_ac(0);
    set_curr_value("gold", 250);
    set_hit((:this_object(),"weapon_hit":));
    set_wield((:this_object(),"wield_func":));
    set_unwield((:this_object(),"unwield_func":));
}

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 22) {
	message("use", use, this_player());
	message("targ", targ, atk);
	message("room", targ, environment(atk));
	result=(random(55))+((this_player()->query_level()));
    }
}
int query_auto_load()
{
    if (this_player()->query_guild() == guild) return 1;
    return 0;
}
int wield_func()
{
    if (this_player()->query_guild() != guild)
    {
	write(denied);
	return 0;
    }
    else
    {
	write(wield);
	return 1;
    }
}
int unwield_func()
{
    write(unwield);
    return 1;
}

int set_player_message(string str)
{
    use = str;
}
int set_target_message(string str)
{
    targ = str;
}
int set_room_message(string str)
{
    room = str;
}
int set_wield_message(string str)
{
    wield = str;
}
int set_unwield_message(string str)
{
    unwield = str;
}
int set_denied_message(string str)
{
    denied = str;
}

