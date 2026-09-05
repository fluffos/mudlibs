inherit ROOM;
#include <ansi.h>
int is_song_extra_room()
{
	return 1;
}

int Show_Local_Map()
{
	string file;
	if (this_object()->query("at_hangzhouplace")||this_object()->query("at_hangzhoupalace"))
	file="/doc/help/map-palace";
	else if (this_object()->query("at_hangzhou"))
	file="/d/song/maps/hangzhou";
	else if (this_object()->query("at_yw")||"/cmds/usr/localmaps"->get_area(base_name(this_object()))=="wuchang")
	file="/d/song/maps/yanwu";
	else if (this_object()->query("at_none"))
	return 0;
	else
	file="/d/song/maps/zhongshu";
	file = read_file(file); //调用map文件
	file = replace_string(file, COLOR_D->uncolor(this_object()->query("short")), BBLU+HIY+this_object()->query("short")+NOR);
	this_player()->start_more(file);
	write(" ___________________________________________________________\n");
	return 1;
}