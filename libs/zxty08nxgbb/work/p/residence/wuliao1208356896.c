#include <ansi.h> 
inherit ROOM;
//int get_object(object ob);
void create()
{
set("short", "圣剑魔宫大门");
set("long", @LONG
这就是闻名天下的『圣剑魔宫』的宫门。宫门由一块巨大的汉白玉雕
刻而成，不知凝聚着多少能工巧匠的智慧与心血。宫门前左右各蹲着一只
威武庄严的碧玉狮子。更显出圣剑魔宫的气势与威严。

LONG
);
set("exits", ([
"north" : "/p/residence/wuliao1208357262",
"down" : "/u/zjb/room/yingxiong1.c",
]));
set("objects", ([
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "$HIC$圣剑$HIR$魔宫");
        setup();
}
int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}
void init()
{
     object *obj;
     object ob=this_player();
     object *inv = deep_inventory(ob);    

     obj = filter_array(inv,(:get_object:));
     if(sizeof(obj)) {
         write (HIB"你刚想偷偷背个人进去，结果还是被发现了。\n"NOR);
         ob->unconcious();
         ob->move("/u/zjb/room/yingxiong");
         return;
     }

     if ( (int)ob->query_condition("killer")) {
         write (HIM"杀人犯也敢来总坛，找死!\n"NOR);
         ob->unconcious();
         ob->move("/u/zjb/room/yingxiong");
         return;
     }

     if((string)ob->query("banghui")!=environment(ob)->query("banghui")&&userp(ob))  {
            message("vision",HIR"〖帮派总坛〗"NOR+":"+HIB" " + ob->query("name") + "于今日" + NATURE_D->game_time() + 
                    "企图闯入" + environment(ob)->query("banghui") + HIB"总坛,被赶了出来!\n"NOR,users());
            message_vision(HIR"门卫突然从里面冲了出来给$N一脚,$N惨叫一声,被踢了出来。"NOR,this_player());
            ob->move("/u/zjb/room/yingxiong");
            ob->unconcious();
     }
     else return;
}
