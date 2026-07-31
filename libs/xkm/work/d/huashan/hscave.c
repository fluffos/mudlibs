// 2002-8-27

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是一个黑黝黝的山洞，里边石椅、石桌却摆放的非常整齐，外边
不时传来一阵阵瀑布冲击岩石的声音。蒲团上端坐着一位白发老人
看年龄也要八十左右，看到有人来，老人缓缓睁开双眼，一动不动
的盯着你看。出口被他挡在身后。
LONG
        );
        set("exits", ([
  "out" : __DIR__"shanhong",
]));

        set("objects", ([
                "/d/huashan/npc/laoren" : 1,
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "huashan");

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
      object *inv;
        int i;
        inv = all_inventory(me);
      if ( dir == "out" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开这里。\n");
                }
        }
           me->set_temp("mark/猴子", 0);
        return ::valid_leave(me, dir);
}
