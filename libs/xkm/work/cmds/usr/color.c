// Change by Server
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

	if( me->query("combat_exp") < 500000)
		return notify_fail("дЦ╣дцШиЫ╩╧╡╩╧╩оЛааё╛ц╩спвй╦Яиои╚║ё\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("дЦ╣дцШвжря╬╜спяуи╚ак║ё\n");

	if( !arg ) return notify_fail("дЦр╙╦Ьвт╪╨╣дцШвжиой╡ц╢и╚ё©\n");

	if( arg == "RED") me->set_color("$RED$");
	if( arg == "GRN") me->set_color("$GRN$");
	if( arg == "YEL") me->set_color("$YEL$");
	if( arg == "BLU") me->set_color("$BLU$");
	if( arg == "MAG") me->set_color("$MAG$");
	if( arg == "CYN") me->set_color("$CYN$");
	if( arg == "WHT") me->set_color("$WHT$");
	if( arg == "HIR") me->set_color("$HIR$");
	if( arg == "HIG") me->set_color("$HIG$");
	if( arg == "HIY") me->set_color("$HIY$");
	if( arg == "HIB") me->set_color("$HIB$");
	if( arg == "HIM") me->set_color("$HIM$");
	if( arg == "HIC") me->set_color("$HIC$");
	if( arg == "HIW") me->set_color("$HIW$");

	else if(!me->query("colorname"))
	return notify_fail("дЦр╙╦Ьвт╪╨╣дцШвжиой╡ц╢и╚ё©\n");

	write("ожтздЦ╣дцШвжф╞аа╤Юак║ё\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : color <яуи╚>
 
хГ╧ШдЦспнЕй╝мР╬╜яИё╛дгц╢дЦ©ирт╦ЬдЦвт╪╨оЛаа╣дцШвж╪сиор╩╦Жяуи╚║ё
гКя║тЯртобяуи╚ё╨
ё╗в╒рБё║ё║ё║яуи╚р╩╣╘╪сио╬м╡╩дэ╦Э╦дё╛ЁЩ╥гдЦ╦Э╩╩акцШвжё║ё║ё║ё╘

[31mRED[37;0m - ╨Ли╚		[1;31mHIR[37;0m - аа╨Ли╚
[32mGRN[37;0m - бли╚		[1;32mHIG[37;0m - аабли╚
[33mYEL[37;0m - ма╩фи╚		[1;33mHIY[37;0m - ╩фи╚
[34mBLU[37;0m - иНю╤и╚		[1;34mHIB[37;0m - ю╤и╚
[35mMAG[37;0m - гЁвои╚		[1;35mHIM[37;0m - ╥ш╨Ли╚
[36mCYN[37;0m - ю╤бли╚		[1;36mHIC[37;0m - лЛгЮи╚
[37mWHT[37;0m - гЁ╩ри╚		[1;37mHIW[37;0m - ╟ви╚

HELP
        );
        return 1;
}
