// This is a room made by wsl.

inherit ROOM;
void create()
{
    set("short", "土地庙");
    set("long",@LONG
这里香火鼎盛，正中央摆放了一个不大的泥菩萨，前排放着一个
香炉，左右放了一些供果。旁边还有一张破旧的桌子，桌上挂了一块
木匾（bian）。
LONG
);
    set("no_sleep_room", "1");
    set("no_steal", "1");
    //set("no_fight", "1");
    set("objects", ([
       __DIR__"obj/table" : 1,
       __DIR__"npc/shensuan" : 1,
]));
    set("exits", ([
         "east" :__DIR__"ca9",
]));
        set("item_desc", ([
    "bian" : "人有旦夕祸福，天有不测风云。
",
]));
    setup();
}

void init()
{
        add_action("do_knock","knock");
        remove_call_out("stat");
        call_out("stat", 10, this_player());
        remove_call_out("do_sleep");
        call_out("do_sleep",110+random(10));
}
int do_knock(string arg)
{
        object me,ob;
        me = this_player();
        ob = present("shensuan zi",this_object());
        if (ob){
         if(!arg || arg != "table")   return notify_fail("你要敲什么？\n");
         if(! ob->query_temp("sleeped") )
            return notify_fail("赛神仙已经醒了，不必再敲桌子了。\n");
         ob->delete_temp("sleeped");
         ob->delete("no_get");
         ob->delete("no_get_from");
         ob->enable_player();
//         ob->set("long","他就是远近闻名的神算子“赛半仙”，很多人都慕名而来找他算命。\n" HIY "他看起来似乎隐藏了一些天大的秘密。\n" NOR);
         message_vision("$N用力敲了敲桌子。\n",me);
         message_vision("赛半仙睁开睡意朦胧的眼睛，伸了个懒腰，不怀好意的看了看$N。\n",me);
          me->set_temp("knock", 1);
         remove_call_out("do_sleep");
         call_out("do_sleep",60);
         return 1;
        }else  return notify_fail("你得等赛神仙回来再说，\n");
}
void do_sleep()
{
      object ob;

      remove_call_out("do_sleep");
      ob=present("shensuan zi",this_object());
      if (ob && living(ob)){
      message_vision("$N打了个哈欠，又睡着了。\n",ob);
      ob->set_temp("sleeped",1);
      ob->set("no_get",1);
      ob->set("no_get_from",1);
      ob->disable_player("<睡梦中>");
      ob->set("long","神算子正坐在板凳头趴在桌子上睡觉，唾液一直流到了桌子底下。\n");
      }
      
}
int stat(object me)
{
   object ob;
   
   if (!me || environment(me)!=this_object() ) return 1;   
   
   ob=present("shensuan zi",this_object());
   if (ob && ob->query_temp("sleeped")){
      message_vision("呼噜.....呼.........噜...............\n",ob);
   }
   remove_call_out("stat");
   call_out("stat",60,me);
}
void reset()
{
   ::reset();
   call_out("do_sleep",0);
}

