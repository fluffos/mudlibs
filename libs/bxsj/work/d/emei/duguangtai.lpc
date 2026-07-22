// Room: /d/emei/duguangtai.c 峨嵋派 睹光台

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",MAG "睹光台" NOR);
	set("long", @LONG
 这里是看日出、云海、佛光、神灯之地。台下深崖万丈，陡彻无底，云遮
雾掩。极目四望，数百里外的大小雪山皆历历在目。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"woyunan",
		"west" : __DIR__"sheshenya",
		"north" : __DIR__"huazangan",
	]));
        set("objects",([
		CLASS_D("emei") + "/bei-jinyi" : 1,
          ]));
	set("outdoors", "峨嵋山");
	setup();
	
}
void init()
{
	add_action("do_look", "look");
}

int do_look()
{
	object me = this_player();
	mixed *local;
	local = localtime(time() * 60);
	if(local[2] < 3 || local[2] >= 21) {
	message("vision",BLU"初见金顶下黑黝黝一片，忽而闪现出一点、两点带蓝色的亮光，这种亮点\n"
			    "越来越多，转眼便布满山谷，有的如流萤飘飞，有的如繁星闪烁。\n"NOR, me);
	}
	if(local[2] >= 3 && local[2] < 8)  {
	message("vision",HIR"启明星刚刚升起，一道道微白的光在东方云层闪现，一轮红日托地跳出，\n"
			    "大千世界顿时在彩阳映照下呈现出无限生机。\n"NOR, me);
	}
	if(local[2] >= 8 && local[2] <= 13) {
	message("vision",HIC"金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚\n"
			    "踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，\n"
			    "令人有乘舟欲风之意。\n"NOR, me);
	}
	if(local[2] > 13 && local[2] < 14) {
	message("vision",YEL"日丽风静，云海平铺，美丽以极。阳光从你背面斜射下来，在舍身崖下形\n"
			    "成彩色光环，你见到自己的身影清晰地出现在银色世界上。『光环随人动，\n"
			    "人影在环中』，这就是奇妙的　※※※※※※※佛光※※※※※※※　。\n"NOR, me);
			    
	}
	if(local[2] >= 14 && local[2] < 21) {
	message("vision",HIC"金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚\n"
			    "踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，\n"
			    "令人有乘舟欲风之意。\n"NOR, me);
	}
	
}