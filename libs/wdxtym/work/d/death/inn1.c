// Room: /d/death/inn1.c
 
inherit ROOM;
 
int do_stuff(object ob);
 
void create()
{
	set("short", "小店");
	set("long", @LONG
你一进来就发现屋里异常的温暖, 墙角壁炉里微弱的火光将你
的影子投射在对面的墙上. 几个人影(shadows)围在炉旁不知在讨
论些什麽. 屋内有几张木桌, 椅, 墙上挂了几幅字画, 一切看来非
常的详和宁静, 你几乎忘了自己身在何处.
 
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "east" : "/d/death/road1",
	]));
 
	set("item_desc", ([
	"shadows" : @SHADOWS
从你站的位置很难辨别出那几个人的容貌, 四个披著黑斗蓬的人斜靠在壁
炉边的角落, 偶尔传来其中几人说话的声音, 不过从这个距离你无法听到
他们讨论的内容. 当你还在考虑要不要靠过去一点时, 其中一人回头看了
你一眼, 你愣住了... 那人... 那人......... 居然长得跟你一模一样!
SHADOWS
	]) );

	set("no_fight", 1);
	set("no_sleep_room", 1);

	setup();
}

