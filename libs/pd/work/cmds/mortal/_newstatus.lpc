//      _status.c
//     created by Descartes for the Nightmare mudlib 141192
// modified by seeker
// a dungeonware.net modification 07-Jan-01
// Showed bug if done at setter due to no race.  Fix by Whit 1/5/02

#include <daemons.h> 
#include <std.h>

inherit DAEMON;

string do_bar(int begin, int end)
{
    int i, a;
    string st;

    st = "%^BOLD%^%^WHITE%^[%^RESET%^";
    i = percent(begin, end);
    i += i;
    while(a<i)
    {
	if (a < 50)
	    st += "%^GREEN%^%^BOLD%^";
	if (a > 50)
	    st += "%^YELLOW%^";
	if (a > 120)
	    st += "%^RED%^%^BOLD%^";
	st += "|";
	a += 10;
    } 

    if (strlen(TERMINAL_D->no_colours(st)) < 21)
	while(strlen(TERMINAL_D->no_colours(st)) < 21)
	    st += "%^BLACK%^%^BOLD%^.%^RESET%^";

    st += "%^BOLD%^%^WHITE%^]%^RESET%^";
    return st;
}

int cmd_newstatus() {

    string msg_level, sb, tmp;
    int exp, lev_exp, lev_perc;
    if(this_player()->query_race() == "" || !this_player()->query_race())
	return notify_fail("You must first choose a race!\n");


    exp = (int)this_player()->query_exp();
    lev_exp = (int)ADVANCE_D->get_exp((int)this_player()->query_level()+1);

    lev_perc = percent(exp,lev_exp);
    if (lev_perc >= 100)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||||||||||||%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 99)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||||||||||%^BLACK%^.%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 95)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||||||||||%^BLACK%^.%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 90)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||||||||||%^BLACK%^..%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 85)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||||||||%^BLACK%^...%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 80)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||||||||%^BLACK%^....%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 75)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||||||%^BLACK%^.....%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 70)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||||||%^BLACK%^......%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 65)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||||%^BLACK%^.......%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 60)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||||%^BLACK%^........%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 55)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||||%^BLACK%^.........%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 50)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||||%^BLACK%^..........%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 45)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||||%^BLACK%^............%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 40)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||||%^BLACK%^.............%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 35)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||||%^BLACK%^..............%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 30)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||||%^BLACK%^...............%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 25)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||||%^BLACK%^................%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 20)
	msg_level = "0%%^BOLD%^[%^BLUE%^||||%^BLACK%^.................%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 15)
	msg_level = "0%%^BOLD%^[%^BLUE%^|||%^BLACK%^..................%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 10)
	msg_level = "0%%^BOLD%^[%^BLUE%^||%^BLACK%^..................%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 5)
	msg_level = "0%%^BOLD%^[%^BLUE%^|%^BLACK%^...................%^WHITE%^]%^RESET%^100%";
    if (lev_perc <= 1)
	msg_level = "0%%^BOLD%^[%^BLACK%^....................%^WHITE%^]%^RESET%^100%";

    write("%^BLUE%^=+=+=%^BOLD%^(%^WHITE%^ Status %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
    tmp="%^RED%^%^BOLD%^hp%^RESET%^: "+this_player()->query_hp()+"/"+this_player()->query_max_hp()+"  "
      "%^CYAN%^%^BOLD%^sp%^RESET%^: "+this_player()->query_sp()+"/"+this_player()->query_max_sp()+"  "
      "%^MAGENTA%^%^BOLD%^mp%^RESET%^: "+this_player()->query_mp()+"/"+this_player()->query_max_mp()+"  ";
      tmp += "%^BLUE%^%^BOLD%^level%^RESET%^: "+this_player()->query_level();
    write(tmp);
    if (this_player()->query_max_stuffed()) {
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^");
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Intoxicated : %^RESET%^", 14);
    sb += arrange_string(do_bar(this_player()->query_intox(), this_player()->query_max_intox()), 23);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Stuffed     : %^RESET%^", 14);
    sb +=  do_bar(this_player()->query_stuffed(), this_player()->query_max_stuffed());
    write(sb);
    sb = arrange_string("%^BOLD%^%^MAGENTA%^Quenched    : %^RESET%^", 14);
    sb += arrange_string(do_bar(this_player()->query_quenched(), this_player()->query_max_quenched()), 23);
    sb += arrange_string("%^BOLD%^%^MAGENTA%^Poisoned    : %^WHITE%^%^BOLD%^[", 17);
    if (this_player()->query_poisoning())
	sb +="%^RED%^%^BOLD%^%^FLASH%^Yes!%^RESET%^%^BOLD%^]%^RESET%^";
    else sb += "%^RESET%^No  %^BOLD%^]%^RESET%^";
    write(sb);
    }
    write("%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^");
    write("%^BOLD%^%^MAGENTA%^Experience to next level:%^RESET%^ "+ msg_level +"%^RESET%^");
    write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    return 1;
}

void help() {
    write("Syntax: <status>\n\n"+
      "Gives you your current physical status.\n"
      "See also: score\n"
    );
}
