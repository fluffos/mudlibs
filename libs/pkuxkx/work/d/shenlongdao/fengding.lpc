// Room: /shenlongjiao/fengding.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "峰顶");
        set("long", @LONG
上了峰顶视野一片开阔，东北方向有五座大竹屋分五行方位而建，气势雄伟。而正北面有一条长廊，通向一个大堂，
想必那就是议事厅，只见四面八方有人走向竹屋。入口处竖了一块石碣（stone）。
那石碣上刻满弯弯曲曲的篆文。那石碣颜色乌黑，石钇和石碣上生满青苔，所刻的文字斑驳残缺，
一望而知是数百年前的古物。
LONG
        );
        set("outdoors", "shenlongdao");
        set("valid_startroom", 1);
        set("item_desc", ([
                "stone" : "你对着石头研究了大半天，发现你居然一个字都不认识。\n",
        ]));

        set("exits", ([
                "southdown" : __DIR__"shanlu8",        
                "north" : __DIR__"lianwuchang",  
        ]));

   set("objects", ([
         "/kungfu/class/shenlong/pang":1,
         __DIR__"npc/xunshandizi":1,
              "/clone/npc/camel1": 0,
       ]));
        setup();
  "/clone/board/shenlong_b"->foo();
//        replace_program(ROOM);
}

