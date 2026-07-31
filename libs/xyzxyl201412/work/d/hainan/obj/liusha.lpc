#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
        object san, sna;
        set("short", "大漠风沙");
        set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼
的风声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间
仿佛只剩下你一个人。你脚下缓缓而动的流沙给你如旅薄冰的感觉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert1",
  "north" : __DIR__"desert7",
  "south" : __DIR__"desert8",
  "east"  : __DIR__"desert3",
  "down"  : __DIR__"quicksand4",
]));
        set("outdoors", "quicksand");

        setup();
}

void init()
{       object ob;
        object jade;
        int water, food, bellicosity,level,high;
        string outexit;
        mapping rided;
        if( rided = this_player()->query_temp("rided"))
           if( rided["id"] == "luotuo")
               return;
        if( interactive( ob = this_player()))
        {
        water = ob->query("water");
        food = ob->query("food");
        bellicosity = ob->query("bellicosity");
        water -= (random(4)+ 1) * water / 10;
        food -= (random(2)+ 1) * water / 10;
        bellicosity += random(10);
        ob->set("water", water);
        ob->set("food", food);
        ob->set("bellicosity", bellicosity);    
        if( !objectp(jade = present("jade", ob)))
        {
        high=10;
        }
        else
        {
        high=15;
        }
        level=this_player()->query_skill("dodge");
        if (level <10)
        {
                level =10;
        }
        high=high*level/10;
        if (random(high)<1)
        {
                drop_him(ob);
        }
        }
        add_action("do_pull", "pull");
        add_action("do_push","push");
}
int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1;

}
int dropnow(object me)
{
        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
        message_vision("$N已陷身流沙之中！！\n"NOR, me);
        me->move(__DIR__"quicksand4");
        return 1;
}
 
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
        room = load_object(__DIR__"quicksand4");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("流沙里没有这个人。\n");
         message_vision(HIW"$N用尽全身力量，将$n从流沙中救了出来。\n"NOR, me,who);
        who->move(__FILE__);
        return 1;

}

int do_push(string arg)
{
        object room;
        object who;

        room=this_object();
        if (!stringp(arg))
        {
                return 1;
        }
        who=present(arg,room);
        if (objectp(who))
        {
                tell_object(who,this_player()->name(1)+"推了你一把\n");
                if (random(who->query_skill("dodge"))<40)
                {
                        message_vision("$N大叫一声“不好！”，可是来不及了…\n", who);
                        message_vision("$N已陷身流沙之中！！\n"NOR, who); 
                        who->move(__DIR__"quicksand4");
                } else {
                        this_player()->start_busy(5);
                        who->kill_ob(this_player());
                }
        }
        return 1;
}
