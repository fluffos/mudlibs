//千面神兵招唤的剑神
#include <ansi.h>
inherit NPC;
void consider();
void create()
{
        set_name("剑神", ({"jian shen", "shen"}));
        set("gender", "男性");
      set("begin",0);
      set("xiaoshi",0);
        set("age", 1200);
     set("per",1000000);
        set("long", 
                "传说中的剑神，不过这只是一个幻影而已。\n");
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);
        set("max_qi", 100000);
        set("max_jing",100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 400);
        set("combat_exp", 10000000);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        set_skill("force", 500);
        set_skill("strike", 500);
        set_skill("xiake-strike", 500);
        set_skill("dodge", 500);
        set_skill("jiuyin-shengong", 500);
        set_skill("xiake-shengong", 500);
        set_skill("xiake-jianfa",500);
        set_skill("sword",500);
        set_skill("throwing",500);
        set_skill("xiake-shenfa", 500);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","jiuyin-shengong");
        map_skill("sword","xiake-jianfa");
        map_skill("parry","xiake-jianfa");
        prepare_skill("strike", "xiake-strike");
        prepare_skill("sword", "xiake-jianfa");
        setup();
   reset_action();
        carry_object("/d/xiakedao/npc/obj/xguang")->wield();
        carry_object("/d/xiakedao/npc/obj/xgjia")->wear();
}
void init()
{
if(!query("begin"))
{
set("begin",1);
//       call_out("setsign",20,this_object());
       call_out("des",20,this_object());
}
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(3) )
        {
            case 0:
                command("perform sword.feijian " + target->query("id"));
                break;
            case 1:
                command("yun yihun " + target->query("id"));
                break;
            case 2:
                command("yun recover");
                break;
             }
     if(query("xiaoshi")) call_out("des",1,this_object());
}
void setsign(object shen)
{
shen->set("xiaoshi",1);
return;
}
void des(object jane)
{
message_vision(HIC"忽然一阵风吹来,剑神竟幻化为一道青烟消失在风中....\n"NOR,jane);
destruct(jane);
return;
}
