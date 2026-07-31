//yangzhou  nanmen.c
inherit ROOM;

void create()
{
        set("short", "南门");
        set("long", @LONG
这里是金陵的南门，高高的城墙上面插着几个旗帜，城门口站着几个值
勤的官兵，你朝他们瞧了一眼，其中一个官兵冷冷地盯了你一眼，你不禁打
了个哆嗦，还是快点走吧。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
          "north" : __DIR__"nanjie2",
          "south" : "/d/jiangling/tulu",	//goto taohua
//          "south" : "/u/xiaoyao/...",	//goto xiaoyao


]));
 set("outdoors", "jinling"); 
        set("objects", ([
              __DIR__"npc/bing" : 3,
			]) );


        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}