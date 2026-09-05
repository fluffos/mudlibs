// File         : bodyguard.c 美女保镖
// Created By   : whuan@pkuxkx, 2008-12-25
#include <ansi.h>
inherit FAMILY_NPC;
#include <random_name.h>

void create()
{
        set_name(get_rndname(), ({get_rndid(), "bao biao","baobiao"}));
        set("nickname",HIW"保镖"NOR);
        set("long","听说最近治安不好，他可是被人用重金从京城请来的，据说以前是大内高手呢！\n");
        set("gender", "男性" );
        set("age", 22+random(40));
        set("combat_exp", 10000000);
        set("attitude", "heroism");
        add("inquiry", ([
                "name" : "大爷我有要事在身，别烦我！",
                "here" : "大爷我有要事在身，别烦我！",
        ]));
        set("uni_target", 1);               
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        call_out("do_leave", 1800);
}
void delete_init_num(object me)
{
        me->delete("init_num");
        return;
}

void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N匆匆忙忙离开了。\n", this_object());
        destruct(this_object());
}

varargs void wield_weapon(string weapon)
{
        if(!weapon && query("use_weapon1"))
                wield_weapon(query("use_weapon1"));
        if(!weapon && query("use_weapon2"))
                wield_weapon(query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                carry_object("/clone/weapon/changbian")->wield();
                break;
        case "zhen":
                set("gender", "无性");
                carry_object("/d/city/obj/flower_shoe")->wear();
                carry_object("/d/city/obj/pink_cloth")->wear();
                carry_object("/d/city/obj/goldring")->wear();
                carry_object("/d/city/obj/necklace")->wear();
                carry_object("/d/quanzhou/obj/xiuhua")->wield();
                carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
                break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "hammer":
                carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
        }
        return;
}
void unconcious()
{        
        object ob = this_object();
        if(ob->query("qi")>=100 && random(2)==1)
                return;
        die();
}
int checking(object me, object ob)
{
        if(!ob)
              	return 1;
        if (me->is_fighting()) 
        {
                call_out("checking",1, me, ob);
                return 1;
        }
        if (!me->is_fighting() && living(ob) && objectp(present(ob->query("id"), environment())) )
        {
                me->kill_ob(ob);
                call_out("checking",1, me, ob);
                return 1;
        }
        if ( (!present(ob->query("id"), environment()) || !living(ob)) && present("beauty girl",environment()) )
           {  
                command("heng");
                message_vision("$N护送着主人匆匆离开。\n", me);
                call_out("destroying",1,me);
                return 1;
        }
        if (!present(ob->query("id"), environment()))
          {
              message_vision("$N悻悻的说：“算你跑的快！”\n",me);
              command("heng");
              message_vision("$N护送着主人匆匆离开。\n",me);
              call_out("destroying",1,me);
              return 1;
          }
        if ( present(ob->query("id"), environment()) && !living(ob) && present("beauty girl",environment()) )
           {  
                command("heng");
                message_vision("$N护送着主人匆匆离开。\n", me);
                call_out("destroying",1,me);
                return 1;
        }              
}
void destroying(object me)
{
				object meinv=present("beauty girl",environment());
				if(meinv) meinv->dest();
				call_out("destroying2",1,me);	
        return;
}
void destroying2(object me)
{
        destruct(me);
        return;
}
int do_copy(object me)  
{                       
        int exp;
        int skill;
        if(!objectp(me)) return 0;
        	
        exp=me->query("combat_exp");     
  		exp=exp*4/5;
  		exp=exp*(me->query("jiaofei/tmz/lianxu")/3+1);
   		set("chat_chance_combat", 40);
        skill=pow(exp/100.0,1.0/3)*10;
		if(me->query("combat_exp") < 1000000)
		{
			skill=skill*9/10;
			exp = exp*9/10;
			set("chat_chance_combat", 20);
		}
        family_skill(this_object(), "random", skill, 1);
        set("combat_exp",exp);    
        set("level",me->query("level")+random(5));
        set("max_qi", me->query("max_qi") * 2);
        set("eff_qi", me->query("max_qi") * 2);
        set("qi", me->query("max_qi") * 2);
        set("max_jing", me->query("max_jing") * 2);
        set("eff_jing", me->query("max_jing") * 2);
        set("jing", me->query("max_jing") * 2);
        set("max_neili", me->query("max_neili") * 3/2);
        set("neili", me->query("max_neili") * 3/2);
        set("max_jingli", me->query("max_jingli") * 3/2);
        set("jingli", me->query("max_jingli") * 3/2);
        set("jiali",0);
        set("uni_target", me);
        set("killer",me->query("id"));
        if(me->query("combat_exp") < 1000000)
        {
            set("no_pfm",1);
        }
        wield_weapon();
}
