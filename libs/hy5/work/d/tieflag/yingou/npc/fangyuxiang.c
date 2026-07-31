 // garrison.c
#include <ansi.h> 
inherit NPC;
#define LOWER_LIMIT 2000
#define DUMP_PLACE  AREA_LAOWU"road0.c"
void create()
{
        set_name("方玉香", ({ "xiang", "fangyuxiang" }) );
        set("long",
"这位美人是银鹞子方玉飞的妹妹\n");
        set("attitude", "heroism");
        set("title", HIW "银燕子"NOR);
        set("str", 20+random(10));
        set("cor", 26);
        set("gender", "女性");
        set("cps", 25);
        set("per", 30);
        set("age",16);
        set("combat_exp", 100000); 
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100); 
        setup(); 
        carry_object(__DIR__"obj/goldcloth")->wear();
} 
int accept_object(object me, object obj)
{
        object real;
        if( (string) obj->query("name") == "罗刹牌")
        {
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，你帮了我大忙．这个给你．");
        me->set("marks/冷若霜",0);
        real = new(__DIR__"obj/realjade");
        if(!me->query("m_success/罗刹牌"))
        {
                me->set("m_success/罗刹牌",1);
                me->add("score",300); 
        }
        if( real )
        real->move(me); 
        return 1;
        }
        return 0;
}        
