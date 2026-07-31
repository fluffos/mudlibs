// fu_jiang 
// Made by ysg (1997.10.22)

#include <ansi.h>
inherit NPC;

#include "namedata.h"

void create()
{
        string name,nick;

	name = comm_man_name();
	nick = comm_man_nick();
	
        set_name(name, ({ "fu jiang" , "fu" , "jiang" }) );
	set("gender", "男性");
        set("title",RED"禁卫军"NOR+BLU"副将"NOR);
        set("nickname", nick);
	set("age", 35+random(20));
	set("long",
	"他跟着当今皇上出生入死，靠着战功一步步升到了今天这个位置，如今天下太平，也没什么示可\n"
	"做了，就练练兵，以防边疆有变，别看他这把年纪，功夫可没拉下。\n");
	set("combat_exp", 65000+random(65000));
        set("shen_type", 1);
	set("attitude", "heroism");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(HIY "副将大声喝道：好啊，你想造反了吗？\n" NOR),
		(HIG "副将“嗤”的一声冷笑道：哼，不想活了吧！\n" NOR),
        }) );

	set_skill("unarmed", 90);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	
	create_family("将军府", 3, "副将");

	setup();
        
	if(strsrch(nick,"剑")!=-1)
	 {
          carry_object(__DIR__"obj/gangjian")->wield();
	  set_skill("sword",90);
	 }	
        else if(strsrch(nick,"刀")!=-1)
	 {
          carry_object(__DIR__"obj/blade")->wield();
	  set_skill("blade",90);
	 }
        else if(strsrch(nick,"戟")!=-1)
	 {
	  carry_object(__DIR__"obj/ji")->wield();
          set_skill("halberd",90);
         }
        else if(strsrch(nick,"锤")!=-1)
	 {
	 carry_object(__DIR__"obj/hammer")->wield();
	 set_skill("hammer",90);
         }
        else if(strsrch(nick,"斧")!=-1)
	 {
	  carry_object(__DIR__"obj/axe")->wield();
          set_skill("axe",90);
         }
        else if(strsrch(nick,"枪")!=-1)
	 {
          carry_object(__DIR__"obj/qiang")->wield();
          set_skill("qian",90);
         }
        else if(strsrch(nick,"鞭")!=-1)
	 {
          carry_object(__DIR__"obj/whip")->wield();
	  set_skill("whip",90);
         }
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver", 20);
}

int accept_fight(object me)
{
        command("say "+RANK_D->query_rude(me)+"居然敢同官兵作对, 看招!");
        command("grin");
        kill_ob(me);
        return 1;
}

int accept_kill(object killer)
{
 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="将军府") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		write(ob[i]->query("name")+ "吼道:"+RANK_D->query_rude(killer)+"你去死吧！ \n" );
        }
        return 1;
}



