/* nanjie.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","南大街 " );
    set( "long",@LONG
南大街远没有西大街热闹，这里两旁居住着的都是比较贫穷的百姓，他们没
有钱买什么奢侈的东西，所以商人们都不在这条街上设摊。街上偶尔走过的也是
一些过路的客商。从这里往南是高昌的南门，那是往西行的必经之路。
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "north"  : __DIR__"center",
        "south"  : __DIR__"nanmen",
        "west"   : __DIR__"minzhai",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


