inherit NPC;
inherit F_DEALER;
#include "/d/wizard/npc/equip_manage.h"
#include <ansi.h>
void create()
{
        set_name("铁匠", ({ "tie jiang"}));
        set("gender", "男性");
        set("age", 35);
        set("long", "一个浑身黝黑的铁匠，看起来再普通不过了。他可以帮你修理兵器。fix 兵器名\n");

        set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        set("inquiry", ([
            "name" : "其实我是一个神秘的铁匠。",
            "here" : "这里临安府。",
         ]) );
    set("vendor_goods", ({
                "/d/city/obj/gangdao",
                "/d/city/obj/tiejia",
                "/d/city/obj/changjian",
                "/d/city/obj/duanjian",
                "/clone/weapon/dart",
                "/clone/weapon/changbian",
                "/clone/weapon/bishou",
                "/clone/weapon/tiefu",
                "/clone/weapon/wuyingzhen",
                "/d/xingxiu/npc/obj/tiegun",
                "/d/village/npc/obj/hammer",    
        }));
        setup();
        carry_object("clone/cloth/male4-cloth")->wear();
}

void init()
{
  add_action("do_fix","fix");  
  add_action("do_autoload","autoload"); 
  add_action("do_disload","disload");
  add_action("do_rename","rename");
  add_action("do_reload","reload");
  add_action("do_list", "list");
  add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
object me=this_player();
if ((string)ob->query("id")=="xuan tie") {
	say("铁匠说道：你要修理什么套装?\n");
	me->set_temp("fix_taozhuang",1);
	return 1;
	}
	
	return 0;
}

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

	if(ob->query("taozhuang")) {
		if(who->query_temp("fix_taozhuang")!=1)
			return notify_fail("修理套装需要千年玄铁，你去找一块给我。\n"); 
	}

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
