// Room: /d/yanziwu/xiaoting.c

inherit ROOM;

void create()
{
	set("short", "晓寒厅");
	set("long", @LONG
这是一间小厅,厅虽不大,布置倒也别致。满厅的芳香，沁人心脾。
只见墙上挂着几幅条幅,笔致颇为潇洒,但掩不住几分柔弱之气。厅内四
周精巧地摆着些桌子(table)和椅子(chair)。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"qinyun",
  "north" : "/u/skyzxm/syj",
  "east" : __DIR__"cuixia",
  "south" : __DIR__"chufang",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/gao" : 2,
  __DIR__"obj/cha" : 1,
  __DIR__"npc/susu" : 1,
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！
",
  "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。
",
]));

	setup();
	replace_program(ROOM);
}
