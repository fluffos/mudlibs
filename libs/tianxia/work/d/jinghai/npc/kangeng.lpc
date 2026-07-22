#include <ansi.h>
#define MAX_EXP         70000

inherit NPC;

int ask_food(object me);
int ask_job(object me);
void give_prise(object me);

void create()
{
        set_name("伙房值更", ({ "kan shou", "kan" }) );

        set("class","jinghai");
        create_family("靖海", 4, "弟子");

        set("gender", "男性" );
        set("age", 35);
        set("long", "这是一位壮年汉子，专门
照看这里的伙房，你要是饿
了可以找他要点吃的(food)。\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "吃的" : (: ask_food :),
        "food" : (: ask_food :),
        "job"  : (: ask_job :),
]));

        set("combat_exp", 2050);
        set("str", 67);

        setup();

        carry_object(__DIR__"obj/pijia")->wear();
}

int ask_food(object me)
{
        object *inv,food;
        int n,i;

        if(!me || me->query("class") != "jinghai")
                return 0;
        if(base_name(environment()) != query("startroom"))
                return 0;

        if((int)me->query("food") >= (int)me->max_food_capacity() )
        {
                message_vision(CYN"$N看了看$n说道：“不去好好操练，\
你怎么整天就是吃？等真饿了再来找我。”\n"NOR,this_object(),me);
                return 1;
        }

        if(me->query_temp("jinghai_ask_food"))
        {
                message_vision(CYN"$N看了看$n说道：“不是刚给你的怎么又要？\
现在没有！！”\n"NOR,this_object(),me);
                return 1;
        }

        inv = all_inventory(me);

        n = sizeof(inv);
        

for(i=0;i<n;i++)
        {
                if(inv[i]->is_food() && inv[i]->query("food_remaining"))
                        break;
        }

        if(i<n)
        {
                message_vision(CYN"$N看了看$n说道：“你那不是还有吃？\
吃完了再来找我。真浪费。”\n"NOR,this_object(),me);
                return 1;
        }

        message_vision("$N点点头，将两碗糯米饭递给了$n。”\n",this_object(),me);
        food = new(__DIR__"obj/mifan");
        food->move(me);
        food = new(__DIR__"obj/mifan");
        food->move(me);
        me->set_temp("shaolin_ask_food",1);
        call_out("finish",120,me);
        return 1;
}

void finish(object me)
{
        if(!me)
        me->delete_temp("jinghai_ask_food");            
}


