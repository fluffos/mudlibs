// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;

string ask_met();
int do_weapon();
object creat_weapon();

void create()
{
        set_name("欧冶子", ({ "ouye zi", "zi" }) );
        set("nickname", RED "赤心剑胆" NOR );
	set("gender", "男性" );
        set("age", 60);
        set("long", 	
            "他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，\n"
            "二目炯炯有神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围\n"
	    "在一股剑气之中。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

	create_family("玄天派",1,"弟子");

        set("combat_exp", 250000);
	set("score",0);
	
        map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");

	
	set("attitude", "peaceful");
        
	set("inquiry", ([
            "铸剑"  : "铸剑可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？\n",
	    "原料"  : "铸剑可用千年玄铁。。。你找到了我才能帮你铸剑。\n",
	    "修理"  :  (: ask_met() :),
       ]) );

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
             "欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！\n",
	     "欧冶子低头沉吟，似乎在思考什么。\n"
	     "欧冶子叹了一口气：神兵配英雄，可英雄。。。。。。\n"
       }) );
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}




string ask_met() 
{ 
	object weapon;
	object gold;
	object *inv;
	int i;
        object me = this_player(); 
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
        return "你身上不是有武器吗？"; 


        if(me->is_busy())
        return "你上一个动作还没有完成。";

//        gold = present("gold_money", this_player());
//        if( !gold) return "你身上没有金子。";

//        if((int) gold->query_amount() < 101)
//        return "你身上没带够一百两金子。";

	if (me->query("weapon/type")) {
		switch((string)me->query("weapon/type"))
		{
			case "剑":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
                        return "修好了,请quit,再重新登陆一次!"; 
			case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "修好了,请quit,再重新登陆一次!"; 
			case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "修好了,请quit,再重新登陆一次!"; 
			case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "修好了,请quit,再重新登陆一次!"; 
			case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(me);
//        gold->add_amount(-100);
        me->start_busy(5);
			return "修好了,请quit,再重新登陆一次!"; 
		}
          }
else return "你造过武器吗？"; 
}

}