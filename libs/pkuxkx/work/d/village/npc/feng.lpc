// smith.c

inherit NPC;
inherit F_DEALER;
#include "/d/wizard/npc/equip_manage.h"
#include <ansi.h>

void create()
{
	set_name("冯铁匠", ({ "feng", "smith" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", 
"冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，\n"
"左腿残废，肩窝下撑著一根拐杖。\n");
	set("combat_exp", 50000);

        set("str", 24);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "小人姓冯，村里人都叫我冯铁匠。",
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 抱歉，锄头已经卖光了...",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"剑"  : 
"哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。\n"
"嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。",
		"取剑": "小人一定要见了岳掌门的手信才能给剑。",
		"冯默风" : "唉～，这个名字小人已经好久没有听到过了...",
		"奇门遁甲" : "那都是小时候学的，平时没事解解闷罢了。",
	]) );
	setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
		add_action("do_fix", "fix");  

}

int accept_object(object who, object ob)
{
if ((string)ob->query("name")=="手信" && (string)ob->query("id")=="letter") {
              if(!query("yl_trigger")) {
		object sword;
		sword = new(__DIR__"obj/youlong");
		say(
		"冯铁匠说道：这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。\n"
		"冯铁匠把" + sword->query("name") + "交给了" + who->query("name") + "。\n");
		sword->move(who);
                set("yl_trigger", 1);
              }
           else say("冯铁匠眼也不抬，说道：要剑自己进去拿。\n");
	return 1;
	}
	
if ((string)ob->query("name")=="xuan tie") {
	say("冯铁匠说道：你要修理什么套装?\n");
	who->set_temp("fix_taozhuang",1);
	return 1;
	}
	
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }

int do_fix(string arg)
{
        object ob,who, uitem;
        int cost = 0;  
        who = this_player();

        if(!arg)
                return notify_fail("你要修复什么装备？\n");
        if(!ob=present(arg,who))
                return notify_fail("你要修复什么装备？\n");
        if(!ob->is_gems())
                return notify_fail("这个东西我可修复不了！\n");
        if(!ob->query("weapon_prop"))
                return notify_fail("目前只能修复武器！\n");  
                
        if(ob->query("max_rigidity") < 2)
                return notify_fail("这件装备已经彻底损坏无法修理了。\n"); 

		if(!me->query("fix_taozhuang") && ob->query("taozhuang"))
				return notify_fail("修理套装需要千年玄铁，你去找一块给我。\n"); 
			
        uitem=new(UITEM_OB);
        uitem->set("id", who->query("id"));
//        if ( uitem->check_save() )
          uitem->restore();

        if(ob->query("max_rigidity") < ob->query("rigidity"))
        {
          //bug weapon
          ob->set("max_rigidity", ob->query("rigidity"));
          if(ob->query("gem_ob_autoloaded") == 1)
          {
            if ( ob->query("autoload_serial") )
              uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
          }                  
        }                      
        
        if(ob->query("rigidity") == ob->query("max_rigidity"))
        {
          uitem->save();
          destruct(uitem);
          return notify_fail("你的东西根本没坏。\n"); 
        }
                
    
    if(ob->query("forge/material1_level") > 3)
    {
      cost += 1 * ob->query("forge/material1_level") * ob->query("forge/material1_level") * ob->query("forge/material1_level");
    }
    
    if(ob->query("forge/material2_level") > 3)
    {
      cost += 1 * ob->query("forge/material2_level") * ob->query("forge/material2_level")* ob->query("forge/material1_level");
    }
    
    if(ob->query("forge/material3_level") > 3)
    {
      cost += 1 * ob->query("forge/material3_level") * ob->query("forge/material3_level")* ob->query("forge/material1_level");
    }  
    
    if(ob->query("forge/material4_level") > 3)
    {
      cost += 1 * ob->query("forge/material4_level") * ob->query("forge/material4_level")* ob->query("forge/material1_level");
    }        
    
    cost = cost * (ob->query("max_rigidity") - ob->query("rigidity")) / ob->query("max_rigidity");
    
    cost += (ob->query("max_rigidity") - ob->query("rigidity")) / 50;
    
    cost = cost / 4;
    
    if(cost < 1) cost = 1;
      
    if(who->query("balance") < cost * 10000)
    {
      uitem->save();
      destruct(uitem);
      return notify_fail(sprintf("修理这件装备需要%d两黄金，你没有这么多钱。\n",cost));
    }    
    
    who->add("balance",-cost*10000);
    if(random(1000) < (ob->query("max_rigidity") - ob->query("rigidity")))
    {
      write("由于常年使用，你的武器耐久永久性的下降了1点。\n");
      ob->add("max_rigidity",-1);
    }
    ob->set("rigidity",ob->query("max_rigidity"));
    
    if(ob->query("gem_ob_autoloaded") == 1)
    {
      if ( ob->query("autoload_serial") )
        uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
    }    
    
    write(sprintf("你花费了%d两黄金,修好%s！\n",cost,ob->query("name")));               
    uitem->save();
    destruct(uitem);
    return 1;
}
