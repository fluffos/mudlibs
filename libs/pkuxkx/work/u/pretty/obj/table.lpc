// table.c
//
// Created by pretty (09/17/98)

inherit ITEM;

void create()
{
	set_name( "桌子", ({ "table", "桌子" }) );
	set( "long", @LONG
这是一张普普通通的桌子，上面放着不少玩具。
LONG
	);

	set( "no_show", 1 );
	set( "no_get", 1 );
	set( "prep", "under" );
	set( "unit", "张");
	set_max_encumbrance(50000);

	setup();
}

int is_container()
{
	return 1;
}
