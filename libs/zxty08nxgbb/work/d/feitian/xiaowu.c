// /d/feitian/xiaowu
// diabio(青云)2001.2.6
inherit ROOM;

void create()
{
	set("short", "林间小屋");
	set("long",@LONG
简陋的屋子四周的墙壁全放着一些陶陶罐罐，整个屋子凌乱不堪在地上还
散落着不少未完成品。一个身穿白色大蓬的人正背对着你观赏陶器。屋角
很散乱地放了一些日常生活用具。中央放着一张桌子，上面摆一茶壶和几
个杯子。
LONG);
	set("exits", ([
	"south" : __DIR__"xiaodao",

]));
	set("objects", ([
        	__DIR__"npc/biguqing" : 1,
]) );
        set("no_fight",1);
	set("sleep_room",1) ;
	setup();
	replace_program(ROOM);
}
