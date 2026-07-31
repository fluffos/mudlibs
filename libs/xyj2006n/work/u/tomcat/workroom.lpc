// workroom.c
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIB"垃圾场"NOR);
	set("long", @LONG
都是垃圾
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
 "down":"/d/wiz/wizroom",
	]));

	set("sleep_room", "1");
        set("valid_startroom","1");
	set("item_desc", ([
		"sea" : "波涛汹涌，惊淘拍岸,好一幅壮丽景观！\n",
	]));
	setup();
// call_other("/u/cheer/obj/board", "???");
}

void init()
{
	add_action("look_paper","look");
}

int look_paper(string arg)
{
	if( !arg || arg!="paper" ) return 0;

	write(HIY"                               调色板说明\n"NOR);
	write("Black esc[30m BLK       "+BLK"■■■■■"NOR+" ; Red esc[31m RED       "+RED"■■■■■\n"NOR);
	write("Green esc[32m GRN       "+GRN"■■■■■"NOR+" ; Yellow esc[33m YEL    "+YEL"■■■■■\n"NOR);
	write("Blue esc[34m BLU        "+BLU"■■■■■"NOR+" ; Magenta esc[35m MAG   "+MAG"■■■■■\n"NOR);
	write("Cyan esc[36m  CYN       "+CYN"■■■■■"NOR+" ; White esc[37m WHT     "+WHT"■■■■■\n\n"NOR);

	write("Red esc[1;31m HIR       "+HIR"■■■■■"NOR+" ; Green esc[1;32m HIG   "+HIG"■■■■■\n"NOR);
	write("Yellow esc[1;33m HIY    "+HIY"■■■■■"NOR+" ; Blue esc[1;34m HIB    "+HIB"■■■■■\n"NOR);
	write("Magenta esc[1;35m HIM   "+HIM"■■■■■"NOR+" ; Cyan esc[1;36m HIC    "+HIC"■■■■■\n"NOR);
	write("White esc[1;37m HIW     "+HIW"■■■■■\n\n"NOR);

	write("Red esc[42;1m HBRED     "+HBRED"■■■■■"NOR+" ; Green esc[42;1m HBGRN "+HBGRN"■■■■■\n"NOR);
	write("Yellow esc[43;1m HBYEL  "+HBYEL"■■■■■"NOR+" ; Blue esc[44;1m HBBLU  "+HBBLU"■■■■■\n"NOR);
	write("Magenta esc[45;1m HBMAG "+HBMAG"■■■■■"NOR+" ; Cyan esc[46;1m HBCYN  "+HBCYN"■■■■■\n"NOR);
	write("White esc[47;1m HBWHT   "+HBWHT"■■■■■\n\n"NOR);

	write("Black esc[40m BBLK      "+BBLK"■■■■■"NOR+" ; Red esc[41m BRED      "+BRED"■■■■■\n"NOR);
	write("Green esc[42m BGRN      "+BGRN"■■■■■"NOR+" ; Yellow esc[43m BYEL   "+BYEL"■■■■■\n"NOR);
	write("Blue esc[44m BBLU       "+BBLU"■■■■■"NOR+" ; Magenta esc[45m BMAG  "+BMAG"■■■■■\n"NOR);
	write("Cyan esc[46m BCYN       "+BCYN"■■■■■"NOR+" ; White esc[47m BCYN    "+BCYN"■■■■■\n\n"NOR);

	write("Normal esc[2;37;0m NOR   "+NOR"■■■■■\n"NOR);
return 1;
}
