inherit ROOM;

void create ()
{
  set ("short", "灵隐寺");
  set ("long", @LONG
这是一个简朴的小寺庙，正中一座观音菩萨盘腿坐在莲花宝座之上
左右是金童玉女。佛前的供台上是善男信女带来的香烛供品及一个
小签筒，每天都有很多人来这里求签上香，供台下一个小箱，装的是
供奉的金银
LONG);
   
   set("qiantong", 1);
   set("no_fight",1);
   set("no_sleep_room",1);

   
   set("exits", ([ /* sizeof() == 1 */
 "east" : "/d/yandang/jiedao",
]));
        set("objects", ([
            "/u/legato/npc/daoshi" : 1,
            "/d/yandang/obj/gongdexiang" : 1,
]));
  setup();
}
void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
    object me,ob1;
    me=this_player();

    if ( (arg!="qiantong")&&(arg!="签筒")) return 0;
if (!query("qiantong")) return notify_fail("签筒已经给人取走了!\n");
if((me->query("family/family_name")=="雁荡派")&&(query("qiantong")))
    {message_vision(
"$N从供桌上取下一个签筒！\n", me);
                ob1=clone_object("/d/yandang/obj/qiantong.c");
                         ob1->move(me);
        set("qiantong",0);
        return 1;
}
return 0;
}

