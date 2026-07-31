// /clone/board/wiz_b.c

inherit ITEM;

void create()
{
	set_name("巫师留言簿", ({ "board" }) );
	set("location", "/d/wizard/wizard_room");
	set("board_id", "wiz_b");
	set("long", "这是一个专供巫师使用的留言板。\n" );
	setup();
	set("capacity", 1000);
	replace_program(ITEM);
}

