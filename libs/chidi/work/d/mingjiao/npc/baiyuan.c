//baiyuan.c 
#include <ansi.h> 
inherit BHNPC;

void create()
{
        set_name(HIW"白猿"NOR, ({ "bai yuan","yuan" }) );
        set("gender", "雄性" );
        set("age", 16);
        set("str", 25);
        set("int", 16);
        set("con", 25);
        set("dex",25);  
        set("long", @LONG
一只通体白毛的大猿猴,看起来颇通人意。
LONG
);
        set("attitude", "peaceful");
        set("combat_exp", 50000);

        set_skill("unarmed", 60);
        set_skill("force",40);
        set_skill("jiuyang-force",20);  
        set_skill("dodge", 80);
        map_skill("force","jiuyang-force");
        map_skill("unarmed","jiuyang-force");
        set("env/wimpy", 50);           
        set("chat_chance", 10);
        set("chat_msg", ({
                HIR"白猿冲你眨了眨眼睛，好象在向你要食物……  \n"NOR,
        }) );
        setup();
} 
int accept_object(object me, object ob)
{
        object book;

        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, me) ) return notify_fail("白猿喜欢吃的是…… \n");
      if (  (string)ob->query("name") != "钢刀")
                    return notify_fail("白猿喜欢吃的是……  \n");
                
message_vision(HIC"白猿高兴的冲$N点点头，然后丢给$N一个破烂的羊皮书，转身蹦到一边享受食物去了！\n"NOR, me);
                           book=new(__DIR__"obj/jianlun");
// me->add("combat_exp",9999);
// me->add("potential",4999);
                           book->move(me);
                return 1;
        }


