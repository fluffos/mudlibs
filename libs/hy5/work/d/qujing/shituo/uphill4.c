// Room: some place in 西牛贺洲
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "狮驼洞");
  set ("long", @LONG
狮驼洞，骷髅若岭，骸骨如林。人头发躧成毡片，人皮
肉烂作泥尘。人筋缠在树上，干焦晃亮如银。真个是尸山
血海，果然腥臭难闻。东边小妖，将活人拿了剐肉；西下
泼魔，把人肉鲜煮鲜烹。
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "northeast" : __DIR__"uphill5",
                "southwest": __DIR__"uphill3",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/qingshi-laomo" : 1,
                __DIR__"npc/yao" : 2]));

        set("no_clean_up", 0);
        set("outdoors", "xy28");
        setup();
        replace_program(ROOM);
}

