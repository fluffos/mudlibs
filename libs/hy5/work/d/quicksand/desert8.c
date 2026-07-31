#include <ansi.h>
#include <room.h> 
inherit ROOM;
int drop_him(object me);
void create()
{
        set("short", "大漠风沙");
        set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼
的风声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间
仿佛只剩下你一个人。你脚下缓缓而动的流沙给你如旅薄冰的感觉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"greenland",
  "north" : __DIR__"desert4",
  "south" : __DIR__"desert7",
  "east"  : __DIR__"desert6",
  "down"  : __DIR__"quicksand8",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"npc/snake" : 2,
        ]) ); 
        set("outdoors", "quicksand"); 
        set("coor/x",-1070);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 
void init()
{       object ob;
        object jade;
        int water, food, bellicosity;
        string outexit;
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
                if( random(200)< 2)               drop_him(ob);
        }
        else
        {
                if( random(1000)< 2)    drop_him(ob);
        }
        }
        add_action("do_pull", "pull");
}
int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1; 
}
int dropnow(object me){
        if(environment(me) == this_object()){
        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
        message_vision("$N已陷身流沙之中！！\n"NOR, me);
        me->move(__DIR__"quicksand8");
    }
        return 1;
}
 
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
        room = load_object(__DIR__"quicksand8");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("流沙里没有这个人。\n");
         message_vision(HIW"$N用尽全身力量，将$n从流沙中救了出来。\n"NOR, me,who);
        who->move(__FILE__);
        who->delete_temp("no_quit");
        return 1; 
}    
