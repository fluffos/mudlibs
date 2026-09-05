#include <room.h>
inherit ROOM;

void create()
{
        set("short", "武庙");
        set("long", @LONG
        这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭毕敬
地上香礼拜。旁边似乎有一道侧门。
LONG
        );

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

//        set("objects", ([
  //              __DIR__"obj/box" : 1,
    //    ]));

        set("exits", ([
               // "east" : __DIR__"beidajie2",
//             // "up" : __DIR__"wumiao2",
                "out": __DIR__"shichang",
        ]));
//        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
        setup();
}
void init()
{
        add_action("do_chanhui","chanhui");
}

int do_chanhui()
{
        object me = this_player();
//        if ( me->is_busy() )
  //          return notify_fail("你现在正忙着！\n");
        
        if ( me->query("shaqi") <= 0 )
                return notify_fail("你心中已没有丝毫杀气，如果真的一心向善，不如皈依我佛。\n");

        if ( me->query("jing") > 50 )   
        {
                message_vision("$N双膝跪地，两眼紧闭，口中念念有词，脸上充满悔恨之意。\n", me);
     //           me->start_busy(100);
                me->add("shaqi", -30);
                me->add("jing", -50);
                call_out("end_chanhui",50, me);
        }
        else return notify_fail("你的精不够！\n");
        
        return 1;
}       
                
                
                

void end_chanhui( object me )
{
        if ( me->query("shaqi") < 0 )
        {
    me->set("attitude","peaceful");
                tell_object( me, "你心中一片平和，已经没有丝毫杀气。\n");
                me->delete("attitude");
                me->set("shaqi" ,0 );
        }
        else {
                tell_object( me, "你感觉心中的杀气渐渐消失......\n");
        }
      //  me->start_busy(1);
        return;
}

