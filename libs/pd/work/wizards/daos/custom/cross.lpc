#include <std.h>

inherit WEAPON;

#define TP this_player()

void create() {
    ::create();
    set_properties( (["no steal" : 1, "no auction" : 1]) );
    set_name("weapon");
    set("id", ({"cross"}) );
    set_short("%^BOLD%^BLACK%^Tsuke's%^RESET%^ %^BOLD%^YELLOW%^B%^RESET%^"
      "%^BOLD%^RED%^u%^RESET%^RED%^r%^RESET%^ORANGE%^n%^RESET%^RED%^i%^RESET%^"
      "%^BOLD%^RED%^n%^RESET%^BOLD%^YELLOW%^g%^RESET%^ C%^BOLD%^r%^RESET%^"
      "os%^BOLD%^s%^RESET%^ %^BOLD%^BLACK%^of%^RESET%^ %^BOLD%^BLACK%^R"
      "%^RESET%^BOLD%^e%^RESET%^BOLD%^BLACK%^d%^RESET%^BOLD%^e%^RESET%^"
      "%^BOLD%^BLACK%^mp%^RESET%^BOLD%^t%^RESET%^BOLD%^BLACK%^i%^RESET%^"
      "%^BOLD%^on%^RESET%^");
    set_long("%^BOLD%^BLACK%^This cross was crafted from%^RESET%^ %^BOLD%^"
      "%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r%^RESET%^ %^BOLD%^"
      "%^BLACK%^of the highest purity and%^RESET%^ %^BOLD%^bl%^RESET%^"
      "%^BOLD%^YELLOW%^e%^RESET%^BOLD%^s%^RESET%^BOLD%^YELLOW%^s%^RESET%^"
      "%^BOLD%^ed%^RESET%^ %^BOLD%^BLACK%^by the%^RESET%^ %^BOLD%^h%^RESET%^"
      "%^BOLD%^YELLOW%^ol%^RESET%^BOLD%^y%^RESET%^ %^BOLD%^g%^RESET%^BOLD%^"
      "%^YELLOW%^od%^RESET%^BOLD%^s%^RESET%^ %^BOLD%^BLACK%^during its "
      "creation.  The cross was then presented to Tsuke as a gift to aid him "
      "in his quest to hunt down%^RESET%^ %^BOLD%^RED%^sinners%^RESET%^%^BOLD%^"
      "%^BLACK%^.  As Tsuke holds the cross, it is consumed by %^BOLD%^h%^RESET%^"
      "%^BOLD%^YELLOW%^ol%^RESET%^BOLD%^y%^RESET%^ %^BOLD%^YELLOW%^f%^RESET%^"
      "%^BOLD%^RED%^l%^RESET%^RED%^am%^RESET%^BOLD%^RED%^e%^RESET%^BOLD%^"
      "%^YELLOW%^s%^RESET%^ %^BOLD%^BLACK%^that do not harm the%^RESET%^ %^BOLD%^"
      "h%^RESET%^BOLD%^YELLOW%^ol%^RESET%^BOLD%^y%^RESET%^BOLD%^BLACK%^, and"
      "%^RESET%^ %^RED%^s%^RESET%^BOLD%^RED%^c%^RESET%^BOLD%^YELLOW%^or%^RESET%^"
      "%^BOLD%^RED%^c%^RESET%^RED%^h%^RESET%^ %^BOLD%^BLACK%^the%^RESET%^ "
      "%^BOLD%^RED%^sinners%^RESET%^BOLD%^BLACK%^.%^RESET%^");
    set_type("blunt");
    set_hit( (: this_object(), "weapon_hit" :) );
    set_wield( (: call_other, this_object(), "wield" :) );
    set_unwield( (: call_other, this_object(), "unwield" :) );
    set_wc(0);
}

void init() {
    ::init();
    add_action("smash", "smash");
}

int wield() {
    message("info", "%^BOLD%^BLACK%^Your cross lights up with%^RESET%^ "
      "%^BOLD%^righteous%^RESET%^ %^BOLD%^YELLOW%^f%^RESET%^BOLD%^RED%^l"
      "%^RESET%^RED%^am%^RESET%^BOLD%^RED%^e%^RESET%^BOLD%^YELLOW%^s%^RESET%^ "
      "%^BOLD%^BLACK%^as you wield it%^RESET%^.", this_player());
    message("info", "%^BOLD%^BLACK%^Tsuke's cross lights up with%^RESET%^ "
      "%^BOLD%^righteous%^RESET%^ %^BOLD%^YELLOW%^f%^RESET%^BOLD%^RED%^l"
      "%^RESET%^RED%^am%^RESET%^BOLD%^RED%^e%^RESET%^BOLD%^YELLOW%^s%^RESET%^ "
      "%^BOLD%^BLACK%^as he "
      "wields it%^RESET%^.", environment(this_player()), this_player());
    return 1;
}

int unwield() {
    message("info", "%^BOLD%^BLACK%^The%^RESET%^ %^BOLD%^YELLOW%^f%^RESET%^"
      "%^BOLD%^RED%^l%^RESET%^RED%^am%^RESET%^BOLD%^RED%^e%^RESET%^BOLD%^"
      "%^YELLOW%^s%^RESET%^ %^BOLD%^BLACK%^on your cross%^RESET%^ %^BOLD%^"
      "ext%^RESET%^BOLD%^BLACK%^in%^RESET%^BOLD%^gui%^RESET%^BOLD%^"
      "%^BLACK%^s%^RESET%^BOLD%^h%^RESET%^ %^BOLD%^BLACK%^themselves as you "
      "unwield it%^RESET%^.", this_player());
    message("info", "%^BOLD%^BLACK%^The%^RESET%^ %^BOLD%^YELLOW%^f%^RESET%^"
      "%^BOLD%^RED%^l%^RESET%^RED%^am%^RESET%^BOLD%^RED%^e%^RESET%^BOLD%^"
      "%^YELLOW%^s%^RESET%^ %^BOLD%^BLACK%^on Tsuke's cross%^RESET%^ %^BOLD%^"
      "ext%^RESET%^BOLD%^BLACK%^in%^RESET%^BOLD%^gui%^RESET%^BOLD%^BLACK%^"
      "s%^RESET%^BOLD%^h%^RESET%^ %^BOLD%^BLACK%^themselves as "
      ""+this_player()->query_subjective()+" unwields "
      "it%^RESET%^.", environment(this_player()), this_player());
    return 1;
}

int smash(string str) {

    object ob;
    int i;

    if (!str || !(ob=find_player(str)))
    {
	return notify_fail("That player is not here.\n");
    }
    if (!sizeof(TP->query_wielded()))
    {
	return notify_fail("You have to wield the weapon first.\n");
    }
    message("info", "%^BOLD%^BLACK%^You smash "+capitalize(str)+" with your "
      "cross,%^RESET%^ %^RED%^sc%^RESET%^BOLD%^RED%^o%^RESET%^BOLD%^YELLOW%^rch"
      "%^RESET%^BOLD%^RED%^i%^RESET%^RED%^ng%^RESET%^ %^BOLD%^BLACK%^them"
      "%^RESET%^.", TP);
    message("info", "%^BOLD%^BLACK%^"+TP->query_cap_name()+" smashes "
      "you with "+TP->query_possessive()+" cross,%^RESET%^ %^RED%^sc%^RESET%^"
      "%^BOLD%^RED%^o%^RESET%^BOLD%^YELLOW%^rch%^RESET%^BOLD%^RED%^i%^RESET%^"
      "%^RED%^ng%^RESET%^ %^BOLD%^BLACK%^you.%^RESET%^", ob, this_player());
    message("info", "%^BOLD%^BLACK%^"+TP->query_cap_name()+" smashes "
      ""+capitalize(str)+" with his cross,%^RESET%^ %^RED%^sc%^RESET%^"
      "%^BOLD%^RED%^o%^RESET%^BOLD%^YELLOW%^rch%^RESET%^BOLD%^RED%^i%^RESET%^"
      "%^RED%^ng%^RESET%^ %^BOLD%^BLACK%^them.%^RESET%^",
      environment(TP), ({TP, ob}) );
    return 1;
}

int weapon_hit(object ob) 
{
    ob = this_player()->query_current_attacker();

    if (!random(20)) {
	message("info", "%^BOLD%^BLACK%^You smash "+ob->query_cap_name()+" with your cross,%^RESET%^ %^RED%^sc%^RESET%^BOLD%^RED%^o%^RESET%^BOLD%^YELLOW%^rch%^RESET%^BOLD%^RED%^i%^RESET%^RED%^ng%^RESET%^ %^BOLD%^BLACK%^them%^RESET%^.", this_player());
	message("info", "%^BOLD%^BLACK%^"+this_player()->query_cap_name()+" smashes "+ob->query_cap_name()+" with his cross, %^RESET%^RED%^sc%^RESET%^%^BOLD%^RED%^o%^RESET%^BOLD%^YELLOW%^rch%^RESET%^BOLD%^RED%^i%^RESET%^RED%^ng%^RESET%^ %^BOLD%^BLACK%^them.%^RESET%^",
	  environment(this_player()), ({this_player(), ob}) );
	return 1;
    }
}

void heart_beat()
{
    if (environment(this_object()) != find_player("tsuke"))
    {
	message("info", "%^BOLD%^BLACK%^Your cross finds its way back to "
	  "your inventory.%^RESET%^", find_player("tsuke"));
	this_object()->move(find_player("tsuke"));
    }
}

int query_auto_load() {
    if (this_player()->query_name() == "tsuke")
    {
	return 1;
    }
}

int drop() { return 1; }
int sell() { return 1; }
int bury() { return 1; }




