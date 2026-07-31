/* silk3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","河西走廊" );
    set( "long",@LONG
河西走廊是黄河以西一条重要的交通要道，是中原通往西域的必经之地，也
是兵家争夺的重点。一条长而走起来吃力的大道在你面前展开：空旷、干燥、白
茫茫的。大道到处和荒原畅通无阻，它把一大片昏暗的地面平分作两半，好象满
头黑法中间的一道缝，一直伸到最远的天边才消失。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"silk4",
        "southeast" : __DIR__"silk2",
    ]) );
    set( "outdoors","silk");
    setup();
}


