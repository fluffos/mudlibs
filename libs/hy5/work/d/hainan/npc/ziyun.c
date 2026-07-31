// worker.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("紫云", ({"zi yun"}));
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个漂亮的小姑娘．");
	set("title", "白云庵传人");
	set("class", "taoist");
        set("combat_exp", 45000);
        set("attitude", "peaceful");
        create_family("海南白云庵", 4, "弟子");
        set_skill("unarmed", 50);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("force", 230);   

        set_skill("sword",250);


        set("per", 30);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

        set("force_factor", 5);
        setup();
        carry_object("/d/hainan/obj/girlcloth")->wear();
        carry_object("/d/hainan/obj/roujing_sword")->wield();
              carry_object("/obj/money/gold");
}
void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
			call_out("greeting",1,ob);
}
}
void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
tell_object(ob,HIC"你听到一阵泼水的声音,伴随着年轻女子的嘻笑声!\n"+NOR);
  if (ob->query("gender")=="男性")
   {
tell_object(ob,HIC+"随着几声惊叫,你眼前一黑,脑后挨了一棒!\n
眼前的一切变得模模糊糊,然后就什么都不知道了!\n
..........    ..........\n"+NOR);
ob->unconcious();
message_vision(HIR"-------啊------,紫云尖叫一声,$N偷看女孩子洗澡------ ------!\n
$N脑后随即挨了一棍子,桃花林中冲出几个衣衫不整的女子,把$N拖死狗般拖走了!\n"+NOR,ob);
tell_room("/d/hainan/dilao.c",RED"地牢门突然打开,"+ob->query("name")+"被扔了进来!\n"+NOR);
ob->move("/d/hainan/dilao.c");
    }
else 
  message_vision(HIC"紫云笑嘻嘻地对$N说道:这位"+RANK_D->query_respect(ob)+"也是来洗澡的么?\n"+NOR,ob);
}


