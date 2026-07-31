// Room: linzi.c
// Date: diabio

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "森林中部");
	set("long", @LONG
森林中央生了一堆篝火，几个地藏菩萨围在四周。一个面色阴冷的
和尚正做在火边打坐念经。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"senlin",
	]));

	set("objects",([
		__DIR__"npc/luo": 1,
	]));
	setup();
}

void init()
{	
	mapping mine;
        object ob = this_player();

	mine = this_player()->query("family");

    if(!userp(ob)) return;
    if (ob->query("family/family_name") == "少林派" && (ob->query("passdu") || ob->query("pass_xin"))) 
return;
	message_vision("
树林中间坐着的僧人似乎不知道你的到来，依然低声念着经
"CYN"苦饿焚我身.....
神佛共世界........
....明王......世.......
"HIC"突然僧人眼中精光大盛,抽出背后的明王剑双手合十插入地下"NOR"
"CYN"僧人念经声渐渐变大
......救苦救难...观..
明王救世.... 苦饿焚我身.....哈
"HIR"只听一声巨响，四周的地藏菩萨轰的一声全部爆裂炸开了"NOR"
"RED"$N只觉地面一股强力的波动传来，胸犹如遭到巨锤，突的一口就喷出了一大口"HIR"鲜血\n\n" NOR, this_player());
}

