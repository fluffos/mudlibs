inherit NPC;
//大内高手
#include <ansi.h>


void create()  
{       set_name(HIC"大内高手"NOR, ({ "danei gaoshou","gaoshou" }));
	set("gender", "男性");
        set("age", random(10) + 30);
        set("shen", -50000);
        set("str", 105);
        set("dex", 96);
     set("long",HIW"这就是朝廷的鹰犬。为人及其心狠手辣\n他们负责看守风波亭,对擅闯风波亭的人格杀勿论,这种人还是少惹为妙!\n"NOR);
        set("combat_exp", 200000000);
        set("shen_type", -1);
        set("attitude", "heroism");

        set_skill("unarmed", 500);
        set_skill("force", 900);
        set_skill("strike", 500);
        set_skill("xiake-quanjiao", 500);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("xiake-strike", 500);

        map_skill("unarmed", "xiake-quanjiao");
        map_skill("strike", "xiake-trike");

        set_temp("apply/attack", 5000);
        set_temp("apply/defense", 5000);
        set_temp("apply/armor", 5000);
        set_temp("apply/damage", 5000);

   prepare_skill("unarmed","xiake-quanjiao");
   prepare_skill("strike","xiake-strike");
        set("neili", 8000); 
        set("max_neili", 20000);
      set("max_qi",20000);
      set("max_jing",10000);
      set("max_jingli",10000);
        set("jiali", 1000);
        
        set("inquiry",([
                "风波亭"  : ("问这个干什么?快滚!"),
                "岳飞"  : ("再废话,小心我宰了你!!"),
        ]));


        set("chat_chance", 8);
        set("chat_msg", ({
"秦臣相有命令,擅入风波亭者,死!.\n",
"滚开滚开!不要命了?\n",
"你再不滚,小心我对你不客气!\n"
        }) );

        setup();
        carry_object("/d/yuewangmu/obj/tiejia")->wear();
        carry_object("/d/yuewangmu/obj/tieqiao");

}

void init()
{
	object ob=this_player();
	::init();
if(present("wumu yishu",ob))
{
 message_vision (HIW"大内高手见喝道:啊,武穆遗书?大胆!竟敢私藏反书!赶快拿下!\n"NOR,ob);
//   call_out("kill_ob",1,ob);
this_object()->kill_ob(ob);
}

}


/*
string kill_you()
{
        object me,ob;
	me=this_player();
	ob=this_object();
	ob->kill_ob(me);
	me->kill_ob(ob);
return (HIR"盗墓高手大骇:你是官府来的么?那咱们就来个你死我活吧!"NOR);
}
*/
 


