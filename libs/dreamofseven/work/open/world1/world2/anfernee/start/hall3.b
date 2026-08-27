inherit ROOM;
void create()
{
	set("short", "時空走廊");
	set("long", @LONG

這裡是旅館的中央走廊。這裡一片凌亂，中間有個牌子，上面寫著:

	【 裝 璜 中 ， 非 工 作 人 員 請 勿 進 入 。 】


LONG
	);

	set("exits", ([ /* sizeof() == 1 */
 "south" : __DIR__"hall2",
	]) );
	set("item_desc", ([
//		"note": (: look_sign :),
//		"告示": (: look_sign :),
	]) );
	set("light",1);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}