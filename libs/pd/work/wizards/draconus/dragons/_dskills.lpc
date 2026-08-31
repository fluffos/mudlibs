#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define GS(s) (this_player()->query_skill(s))

string gtk(string skill)
{
    int a, po, maxs, sk;
    string tmp;

    if (!skill || skill=="") return "";
    a =(int)SKILLS_D->training_formula(this_player()->query_class(),
      this_player()->query_base_skill(skill),skill);

    po = this_player()->query_skill_points(skill);
    if (a) a = percent(po, a);
    if (!a) a = 0;
    if (a < 0 ) { this_player()->clean_skill_points(skill); a = 0; }
    if (a > 99) a = 99;
    sk = this_player()->query_base_skill(skill);
    maxs =this_player()->query_max_skill(skill)*(this_player()->query_level())/2;
    if (sk>=maxs)
    {
	tmp = "(MAX)";
    } else
	tmp = "("+a+"%)";

    return tmp;
}

int cmd_dskills()
{
    string *attack, *weapons, *magic, *decep,  str;
    int i, tmp;

    attack = ({ "attack", "melee", "defense", "charging" });
    weapons = ({ "breath", "claw", "tail" });
    decep = ({ "stealth", "bargaining" });
    magic = ({ "healing", "magic defense" });

    if (this_player()->query_race()!="dragon") return 1;
    write("           %^CYAN%^Attack                                 %^BLUE%^%^BOLD%^Weapons%^RESET%^\n"
      "%^ORANGE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"); 

    for(i=0; i<4; i++)
    {
	str="";
	if ((sizeof(attack) > i))
	{
	    str +="%^CYAN%^"+arrange_string("    "+arrange_string(capitalize(attack[i]), 16)+":%^RESET%^ "+ GS(attack[i]), 27);
	    str += sprintf("%%^RESET%%^%-16s", gtk(attack[i]));
	}
	else
	{
	    str = "                                           ";                     
	}
	if ((sizeof(weapons) > i)) {
	    str += "%^BOLD%^%^BLUE%^"+arrange_string(arrange_string(capitalize(weapons[i]), 16)+":%^RESET%^ "+ GS(weapons[i]), 23);
	    str += sprintf("%%^RESET%%^%s", gtk(weapons[i]));
	}
	else {
	    str += "                                           ";
	}
	write(str);
    }

    write(
      "\n          %^GREEN%^Deception                                %^MAGENTA%^Magic\n"
      "%^ORANGE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    tmp = sizeof(decep);
    if (tmp < sizeof(magic)) tmp = sizeof(magic);
    for(i=0; i<tmp;i++)
    {
	str = "";
	if (i<sizeof(decep))
	{
	    str += "%^GREEN%^"+arrange_string("    "+arrange_string(capitalize(decep[i]), 16)+":%^RESET%^ "+ GS(decep[i]), 27);
	    str += sprintf("%%^RESET%%^%-16s", gtk(decep[i]));
	}
	if (i < sizeof(magic))
	{
	    str += "%^MAGENTA%^"+arrange_string(arrange_string(capitalize(magic[i]), 16)+":%^RESET%^ "+ GS(magic[i]), 23);
	    str += sprintf("%%^RESET%%^%s", gtk(magic[i]));
	} 

	write(str);  
    }
    return 1;
}
