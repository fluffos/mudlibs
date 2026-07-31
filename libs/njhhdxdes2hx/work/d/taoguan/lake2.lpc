#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清湖");
	set("long", @LONG
湖水清澈透明，不时可以看到几尾鱼跳上水面。湖水尽头
是一个大瀑布。在这里可以听到瀑布从山上直冲而下，发出的
轰轰雷声。湖边稀稀落落地站着几个道人。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"grassland2",
  		"south" : __DIR__"lake1",
]));
        set("objects", ([ /* sizeof() == 2 */
  		__DIR__"npc/reg_taoist" : 3,
]));
        set("resource/water",1);
	set("outdoors", "taoguan");
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_swim", "swim");
}

int do_swim()
{
 object me;
 me = this_player();
 message_vision(HIY"$N大着胆子跳入池中，游了起来...\n"NOR,me);
 if(random(me->query("kar"))<10) {
    tell_object(me,HIR"...你忽然觉得手脚一阵抽筋，一口水已经呛了进去，急忙爬上了岸。\n"NOR);
    me->receive_damage("kee",100);
    }else{
          tell_object(me,HIC"你在水中尽情的畅游，忘记了一切烦恼。\n"NOR);
          me->add("gin",50);
         }
 return 1;
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 30,
                                "drunk_apply": 6,
                        ]) );
                        write("你从井里装满了清水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}
