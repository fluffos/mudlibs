// Room: yudong.c

inherit ROOM;
void create()
{
        set("short","玉洞");
        set("long",@LONG 
如果说外面的冰洞象梦幻的世界一样，那么，这里就是真正
的天堂。整个洞内，无论洞壁洞顶，全是墨绿的玉石。玉质温润
细滑，竟是和田之玉。就算在权贵之家，和田玉也是了不起的财
富。一块手掌般大的和田玉，就够一户中等人家过上一辈子。但
是，这里最吸引人的，还是中间的玉台上天然所生的一块珠子，
它散发出幽幽光泽，照的满室皆绿。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "out"  : __DIR__"wave", 
        ])); 
        set("objects", ([
                __DIR__"obj/yujing" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

