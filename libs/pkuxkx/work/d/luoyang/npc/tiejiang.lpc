inherit NPC;


#include <ansi.h>
int ask_tool();
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
            "here" : "这里古都洛阳。",
			"修船工具" : (: ask_tool :),
			"tool" : (: ask_tool :),
            
       	]) );
        set("startjob",1);
        setup();
        
}
int ask_transfer(string arg)
{
	object me=this_player(),ob;
	string sword;
	if (me->query("family/family_name")!="明教")
	{
		command("shake");
		return 1;
	}
	if (me->query("mingjiao/new_skill/transfered")>=2)
	{
		command("say 你已经转换过2把sword为dagger了。");
		return 1;
	}
	if (!arg||sscanf(arg,"%s",sword)!=1)
	{
		command("say 你要把什么武器转换？");
		return 1;
	}
	if (!ob=present(sword,me))
	{
		command("say 你要把什么武器转换？");
		return 1;
	}
	if(!ob->is_gems())
	{
		command("say "+ob->query("name")+"不是随机武器不能被转换。");
		return 1;
	}
	if(!ob->query("weapon_prop"))
	{
		command("say "+ob->query("name")+"不是随机武器不能被转换。");
		return 1;
	}
	if(ob->query("gem_ob_autoloaded"))
	{
		command("say "+ob->query("name")+"必须去除自动加载后才能被转换。");
		return 1;
	}
	if (ob->query("skill_type")!="sword")
	{
		command("say 新明教的转换只涉及sword类随机武器。");
		return 1;
	}
	ob->set("skill_type","dagger");
	ob->set("verbs",({ "pierce", "thrust" }));
	ob->set_name(replace_string(ob->query("name"),"剑","匕"),({"dagger"}));
	me->add("mingjiao/new_skill/transfered",1);
	command("say 你的新武器"+ob->query("name")+"转换好了，你共用去了"+chinese_number(me->query("mingjiao/new_skill/transfered"))+"次机会，共有2次机会。");
	me->save();
	return 1;
}
int ask_tool()
{
	object me=this_player(),tool,tool2,ob=this_object();
	if (base_name(environment())!=ob->query("startroom"))
	{
		command("say 这里又不是我的打铁铺，工具不齐，我帮不了你啊。");
		return 1;
	}
	if (!tool=present("gongju",me))
	{
		command("say 打听修船工具？你至少该拿个修船的工具过来吧？");
		return 1;
	}
	if (!tool->query("is_boat_tool"))
	{
		command("say 打听修船工具？你至少该拿个修船的工具过来吧？");
		return 1;
	}
	if (tool->query("is_boat_tool")>1)
	{
		command("say 你的"+tool->query("name")+"做工很精致啊，我是没法改进了。");
		return 1;
	}
	if (!tool2=present("tong kuai",me))
	{
		tool->set("owner",me);
		tool->set("value", 0);
		command("say 这件修船工具，其实很简单，你拿着上了鄱阳湖的小船自然知道它的妙用了。");
		command("say 如果你能找到一件铜块我还可以帮你改进它，铜块嘛，注意留心洛阳城传闻了。");
		return 1;
	}
	if (!tool2->query("is_copperBlock"))
	{
		tool->set("owner",me);
		tool->set("value", 0);
		command("say 这件修船工具，其实很简单，你拿着上了鄱阳湖的小船自然知道它的妙用了。");
		command("say 如果你能找到一件铜块我还可以帮你改进它，铜块嘛，注意留心洛阳城传闻了。");
		return 1;
	}
	command("say 既然你东西都备齐了，我就帮帮你吧。");
	tool->move(ob);
	tool2->move(ob);
	message_vision("$N没说二话，把"+tool2->query("name")+"精心附着在"+tool->query("name")+"上，以增加其的韧性。\n",ob);
	destruct(tool);
	destruct(tool2);
	tool=new("/d/yingtianfu/neicheng/obj/boat_tool2");
	tool->move(ob);
	tool->set("owner",me);
	command("give "+me->query("id")+" "+tool->query("id"));
	command("gaoding");
	return 1;
}

void init()
{
    add_action("do_fix","fix");
	add_action("ask_transfer","transfer");
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
			
	if(ob->query("taozhuang"))  //加入套装维修费用
	{
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