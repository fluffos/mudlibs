#include <ansi.h>
inherit NPC;

void create()
{
        set_name("紫蘭", ({ "zi lan","lan" }));
        set("title",HIG"俏丫头"NOR);
        set("gender", "女性");
        set("age", 18);
        set("long", "他是陆先生家的小丫头，灵巧可爱，心地善良。\n她正在忙上忙下的张罗饭菜，你也许可以问她要(yao)点吃的。\n");
        
        set("combat_exp", 10000);
        set("shen_type", -1);
  set("count",3);
  set("per",36);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);

        setup();
        carry_object("/clone/cloth/female6-cloth")->wear();
  carry_object("/clone/cloth/female-shoe")->wear(); 
}

void init()
{

    add_action("do_serve", "serve");
    add_action("do_serve", "yao");
}


int do_serve()
{
    object ob,me;
    me=this_player();
   if(me->is_busy()) return notify_fail("你正忙着呢，等一下再要吧。\n");
    message_vision("$N涨红了脸，很不要意思的问小丫头要些吃的。\n", me);
   if (this_object()->query("count") < 1)
            return notify_fail("小丫头说道：都被别人吃光了，先生和夫人就没得吃了。\n小丫头冲你吐了吐舌头！");
                switch(random(3)) {
        case 0:
                              ob=new("/d/murong/obj/tianbing");
            break;
        case 1:
            ob=new("/d/murong/obj/gao");
            break;
        case 2:
            ob=new("/d/murong/obj/oufen");
            break;
        }    
        ob->move(environment(me));
        message_vision("小丫头端出"+ob->name()+"给$N，关切的说：“慢慢吃哦，不够还有。”\n", me);
        this_object()->add("count",-1);
    return 1;
}
