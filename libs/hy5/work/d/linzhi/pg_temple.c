// Room: /d/linzhi/pg_temple.c

inherit ROOM;

void create()
{
	set("short", "帕嘎寺");
	set("long", @LONG
帕嘎寺位于工布江达县之娘蒲乡，原属甘丹寺管辖，传说
寺内有两灵塔，其一放置甘丹寺第一任赤巴宗客巴大师的衣帽
鞋等。帕嘎寺建于五世达赖时期，属黄教。寺中共供大小佛像
1000多尊，僧人近百。　　寺后的帕嘎神山在工布地区非常有
名，整座山形似多吉帕姆女神，特别是山腰处的多吉帕姆女神
肚洞处更是灵验，有神洞之称。该洞洞口有两处玛尼堆，洞比
较深，大洞和小洞相套，向上延伸，洞顶端有天窗，洞内四壁
刻有图案和不知名的文字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lin63",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/monk2" : 2,
  __DIR__"npc/lama2" : 1,
__DIR__"npc/xintu2" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
