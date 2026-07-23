//yangzhou  caifengdian.c
inherit ROOM;

void create()
{
        set("short", "裁缝店");
        set("long", @LONG
你走进一间堆满了布匹的店铺,原来是一家裁缝店.看这里一副生意兴
隆的样子,往来者不乏高官显贵就可知道这里的手艺一定不凡,你要是有兴
趣的话可以在这里定做衣裳。在柜台上有个牌子(sign)。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"nanjie1",

]));
        set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "订做各款衣服, 价格合理(即取) 

",
]));
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/clother" : 1,
//__DIR__"npc/clother1" : 1,
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
