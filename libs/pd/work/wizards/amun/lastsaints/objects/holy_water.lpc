#include <std.h>
#include <amun.h>
inherit OBJECT;
string limb;
int uses, i, use;
string * limbs;
void create(){
    set_name("Holy Water");
    set_short("%^BOLD%^%^CYAN%^Holy %^WHITE%^Water%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This bottle of Holy Water was blessed for The Last Saints. If applied to a <limb> or to <all>, it will improve your stamina.%^RESET%^");
    set_id( ({ "holy water", "water" }) );
    set_mass(2);
    set_value(10);
    uses = 20;
}
string query_short()
{
    string str;
    str = ::query_short();
    str += " (";
    switch(uses) {
    case 1: str += "one"; break;
    case 2: str += "two"; break;
    case 3: str += "three"; break;
    case 4: str += "four"; break;
    case 5: str += "five"; break;
    case 6: str += "six"; break;
    case 7: str += "seven"; break;
    case 8: str += "eight"; break;
    case 9: str += "nine"; break;
    case 10: str += "ten"; break;
    case 11: str += "eleven"; break;
    case 12: str += "twelve"; break;
    case 13: str += "thirteen"; break;
    case 14: str += "fourteen"; break;
    case 15: str += "fifteen"; break;
    case 16: str += "sixteen"; break;
    case 17: str += "seventeen"; break;
    case 18: str += "eighteen"; break;
    case 19: str += "nineteen"; break;
    case 20: str += "twenty"; break;
    }
    if(uses > 1)
	str += " uses left)";
    else
	str += " use left)";
    return str;
}
void init(){
    ::init();
    add_action("fApply", "apply");
}
int fApply(string str){
    if (!str){
	notify_fail("Apply what?\n");
	return 0;
    }
    if(sscanf(str, "%s %s", str, limb) != 2) {
	notify_fail("Correct syntax: <apply water [(limb)]\n");
	return 0;
    }
    if (str!="water") {
	notify_fail("Apply what?\n");
	return 0;
    }
    if (this_player()->query_disable()){
	write("You are too busy doing something else.");
	return 1;
    }

    if (this_player()->query_paralyzed() || this_player()->query_magic_round()
      || this_player()->query_casting()) {
	return notify_fail(this_player()->query_paralyze_message());
    }
    if(limb == "all") {
	limbs = (string *)this_player()->query_limbs();
	for(i=0; i<sizeof(limbs); i++) {
	    this_player()->set_disable();
	    this_player()->heal_limb(limbs[i], 25+random(25));
	    this_player()->add_sp(50+random(45)+random(45));
	    write("%^BOLD%^%^WHITE%^You apply the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over your wounds.%^RESET%^");
	    say( this_player()->query_cap_name() +" applies the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over
"+this_player()->query_possessive()+" wounds.%^RESET%^");
            uses--;
            if(uses <= 0) this_object()->remove();
            return 1;
        }
    }
    if(member_array(limb, (string *)this_player()->query_limbs()) == -1) {
        notify_fail("That limb is missing!\n");
        return 0;
    }

    this_player()->set_disable();
    write("%^BOLD%^%^WHITE%^You apply the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over your "+limb+".%^RESET%^");
    say( this_player()->query_cap_name()+" applies the %^BOLD%^%^CYAN%^Holy %^WHITE%^Water over
"+this_player()->query_title_gender()+" "+limb+".%^RESET%^");
    this_player()->heal_limb(limb, 50+random(50));
    this_player()->add_sp(35+random(20)+random(20));
    uses--;
    if(uses <= 0) this_object()->remove();
    return 1;
}
