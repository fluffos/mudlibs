// chair.c
//
// Created by pretty (09/17/98)

inherit ITEM;

void create()
{
	set_name( "椅子", ({ "chair", "椅子" }) );
	set( "long", @LONG
这是一张很舒适的藤椅，上面却堆了很多玩具。
LONG
	);

	set( "no_show", 1 );
	set( "no_get", 1 );
	set( "prep", "on" );
	set( "unit", "张");
        set_max_encumbrance(50000);

	setup();
}

int is_container()
{
	return 1;
}
