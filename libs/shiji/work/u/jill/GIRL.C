#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("小莹", ({ "xiao yin","yin"}) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个容貌清丽的小姑娘。\n");
        set("shen_type", 1);
        set("combat_exp", 5000);
        set("str", 20);
        set("dex", 18);
        set("con", 19);
        set("int", 20);
        set("attitude", "friendly");
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("score", 1000);

        set_skill("force", 20);

        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 8);
        set_temp("apply/defense", 12);
        set_temp("apply/damage", 11);
        set_temp("apply/armor", 7);
        set("chat_chance", 1);
        set("chat_msg", ({
                "小莹站在一旁：不时地看着来客！\n",
                "小莹听到客人说的笑话，也忍不住笑了笑！\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
          }
                add_action("do_say","say");
}
void greeting(object ob)
{
        if(ob->query("id") == "jill")
          {
          say("小莹说道：主人，你好！\n");
          return;
          }
        if(ob->query("gender") == "男性")
          {     
          say("小莹说道：" + ob->query("name")+"少爷，请坐！\n");
        return;
          }
        if(ob->query("gender") == "女性")
          {
          say("小莹说道："+ob->query("name")+"小姐，请坐！\n");
        return;
           }
}
int do_say(string arg)
{
        object me=this_player();
        object ob=this_object();
        if (me->query("id") != "jill")
           return notify_fail(HIW"这是在别人家里，放规矩点!\n"NOR);
        if (arg == "退下")
           {
                 message_vision(CYN "$N说道：退下。\n"NOR,this_player());
                 message_vision(HIY "小莹答道：是，主人！\n"NOR,this_player());
                 message_vision(HIM "小莹走到门外，将门关上！\n"NOR,this_player());
                 destruct(this_object());
                 return 1;
           }
        if (arg == "设宴")
           {
                 message_vision(CYN "$N说道：退下。\n"NOR,this_player());
                 message_vision(HIY "小莹答道：是，主人！\n"NOR,this_player());
                 message_vision(HIM "小莹向厨房走去。\n"NOR,this_player());
                 remove_call_out("duanc");
                 call_out("duanc", 5, me);

                 return 1;
           }
        if (arg == "助兴")
           {
                message_vision(CYN"$N说道：助兴。\n"NOR,this_player());
                message_vision(HIY"小莹答道：知道了，主人！\n"NOR,this_player());
                message_vision(HIM"小莹走出大门。\n"NOR,this_player());
                remove_call_out("dance");
                call_out("dance",5,me);
                return 1;
           }
        if (arg == "打赏")
           {
                message_vision(CYN"$N说道：打赏。\n"NOR,this_player());
                message_vision(HIW"小莹立刻道：是，主人。\n"NOR,this_player());
                message_vision(HIC"小莹对少女们说道：跟我来。\n"NOR,this_player());
                message_vision(HIM"小莹带着少女们走出大门。\n"NOR,this_player());
                remove_call_out("qu");
                call_out("qu",3,me);
                return 1;
           }
}
void qu(object me)

{
                message_vision(HIW"小莹走了进来，向$N说道：主人，已经办好了!\n"NOR,this_player());
}
void dance(object me)
{
                object a,b,c;
                a=new("/u/jill/qing");
                b=new("/u/jill/huang");
                c=new("/u/jill/bai");
                a->move(environment(me));
                b->move(environment(me));
                c->move(environment(me));
                message_vision(HIW"小莹带了几位少女进来！\n"NOR,me);
                message_vision(HIC"青衣少女向大家道了个万福!\n"NOR,me);
                message_vision(HIW"白衣少女向大家道了个万福!\n"NOR,me);
                message_vision(HIY"黄衣少女向大家道了个万福!\n"NOR,me);
}
void duanc(object me)
{
                object oba,obb,obc,obd;
                oba=new("/u/jill/frsp");
                obb=new("/u/jill/qcxr");
                obc=new("/u/jill/yxrs");
                obd=new("/u/jill/glyc");
                oba->move(environment(me));
                obb->move(environment(me));
                obc->move(environment(me));
                obd->move(environment(me));
                message_vision(HIW"小莹走到厅中说道：主人，菜以备齐，可以上菜了吗？\n"NOR,me);
                message_vision(HIC"$N向小莹点了点头!\n"NOR,me);
                message_vision(HIY"小莹来到门前，小手一挥：可以上菜了\n"NOR,me);
                message_vision(HIW"佣人们一个接一个地，将菜送了进来，\n"NOR,me);
                message_vision(HIG"小莹将菜名一一报来："HIM"芙蓉鳝片"NOR"、"HIW"清炒虾仁"NOR"、"HIR"鱼香肉丝"NOR"、"HIG"橄榄鱼翅"NOR"。。。。。。\n",me);
}

