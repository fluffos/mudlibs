// /guanwai/songhuajiang.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "松花江面");
	set("long", @LONG
这里是松花江的江面，冰面早已解冻，清澈的江水涛涛北去，两岸是如
烟如雾松支，柳条。船夫悠闲地在船尾把着舵。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
}

void transfer(object *obs, string dest)
{
	obs->move(this_object());
	message("vision", BLU "你在江上一路漂流......."NOR"\n", obs);
	call_out("arrive", 10, obs, dest);
}

void arrive(object *obs, string dest)
{
	obs = filter_array(obs, (: objectp($1) &&
				   environment($1) == this_object() :));
	if (! sizeof(obs))
		return;
	message("vision", "\n船很快停靠彼岸。你抬脚跨出船来。\n\n", obs);
	obs->move(dest);
}

