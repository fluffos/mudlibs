//jinling  huafang.c
inherit ROOM;

void create()
{
        set("short", "画舫");
        set("long", @LONG
这里是秦淮河上的一个画舫.整坐画舫华丽非凡,但最主要的是这里的姑
娘们都可以说是色艺双绝，上至将相王侯，下至商贾文士无不闻名而来，欲
一睹芳资。但没有点身份的人是不能轻易被姑娘们接见的。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"huaihe",


]));
set("objects", ([
              __DIR__"npc/yutt" : 1,
              __DIR__"npc/xuezi" : 1,
			]) );
    // set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}