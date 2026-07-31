// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (! arg)
		return notify_fail("дЦр╙лФвт╪╨х║й╡ц╢╢б╨её©\n");

	if (arg == "none")
	{
		me->delete("nickname");
		write("дЦ╣д╢б╨ех║оШак║ё\n");
		return 1;
	}

	if (strlen(arg) > 80)
		return notify_fail("дЦ╣д╢б╨еу╪сц╣двйт╢╧Щ╤Юё╛гКжьпбиХжц║ё\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	if (strlen(filter_color(arg)) > 30)
		return notify_fail("дЦ╣д╢б╨ел╚Ё╓акё╛оКр╩╦Ж╤лр╩╣Ц╣д║╒оЛаар╩╣Ц╣д║ё\n");

	me->set("nickname", arg + NOR);
	write("дЦх║╨цак╢б╨е║ё\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : nick <мБ╨е, ╢б╨е> | none
 
уБ╦Жж╦аН©иртхцдЦн╙вт╪╨х║р╩╦ЖоЛаа╣дцШ╨е╩Рм╥
онё╛дЦхГ╧ШоёмШтз╢б╨ежпй╧сц ANSI ╣д©ьжфвжт╙
╦д╠Дяуи╚ё╛©иртсцртоб╣д©ьжфвж╢╝ё╨

 $BLK$ - ╨з║║и╚            $NOR$ - уЩЁёи╚
 $RED$ - [31m╨Л║║и╚[2;37;0m            $HIR$ - [1;31mаа╨Ли╚[2;37;0m
 $GRN$ - бл║║и╚            $HIG$ - [1;32mаабли╚[2;37;0m
 $YEL$ - [33mма╩фи╚[2;37;0m            $HIY$ - [1;33m╩ф║║и╚[2;37;0m
 $BLU$ - [34mиНю╤и╚[2;37;0m            $HIB$ - [1;34mю╤║║и╚[2;37;0m
 $MAG$ - [35mгЁвои╚[2;37;0m            $HIM$ - [1;35m╥ш╨Ли╚[2;37;0m
 $CYN$ - [36mю╤бли╚[2;37;0m            $HIC$ - [1;36mлЛгЮи╚[2;37;0m
 $WHT$ - [37mгЁ╩ри╚[2;37;0m            $HIW$ - [1;37m╟в║║и╚[2;37;0m
 
╫Шж╧тз nick жпй╧сц $BLINK$ - [5m[1;37mвж[2;37;0m[5m[1;36m╥Ш[2;37;0m[5m[35mиа[2;37;0m[5m[1;33mк╦[2;37;0m
фДжпо╣мЁвт╤╞╩Атзвж╢╝н╡╤к╪ср╩╦Ж $NOR$║ё

HELP );
        return 1;
}
