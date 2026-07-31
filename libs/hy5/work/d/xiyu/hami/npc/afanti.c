// afanti.c     阿凡提
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "阿翻提", ({ "a fanti", "fanti"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 40 );                
    set( "long", @LONG
本地人……
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

