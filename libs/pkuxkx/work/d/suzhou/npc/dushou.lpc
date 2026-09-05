// ping.c 平一指
// edit by whuan to add change sex
// 加入疗伤的功能 by whuan
// 做一个江南的copy
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int checkme();
string ask_cure();
mapping *poisons = ({
        ([  "name": "s_poison",    "cname":"断肠散之毒  ",     "base_amount":1 ]),    //断肠散之毒
        ([  "name": "bt_poison",   "cname":"白驼蛇毒    ",     "base_amount":1 ]),    //白驼蛇毒
        ([  "name": "rose_poison", "cname":"火玫瑰之毒  ",     "base_amount":2 ]),    //火玫瑰之毒
        ([  "name": "san_poison",  "cname":"断肠散之毒  ",     "base_amount":2 ]),    //断肠散之毒 
        ([  "name": "snake_poison","cname":"蛇毒        ",     "base_amount":1 ]),    //蛇毒 
        ([  "name": "sanxiao_poison","cname":"三笑逍遥散",     "base_amount":3 ]),    //三笑逍遥散
        ([  "name": "slumber_drug","cname":"蒙汗药      ",     "base_amount":1 ]),	  //蒙汗药
        ([  "name": "fs_poison",   "cname":"腐尸之毒    ",     "base_amount":3 ]),    //腐尸之毒
        ([  "name": "bing_poison", "cname":"冰魄银针    ",     "base_amount":1 ]),    //冰魄银针
        ([  "name": "ss_poison",   "cname":"生死符      ",     "base_amount":2 ]),    //生死符
        ([  "name": "xxx_poison",  "cname":"冰魄寒毒    ",     "base_amount":2 ]),    //冰魄寒毒
        ([  "name": "xx_poison",   "cname":"星宿毒掌之毒",     "base_amount":2 ]),    //星宿毒掌
        ([  "name": "yf_condition","cname":"玉蜂针之毒  ",     "base_amount":2 ]),    //玉蜂针
        ([  "name": "anran_poison","cname":"情毒        ",     "base_amount":3 ]),    //情毒 
        ([  "name": "qishang",     "cname":"七伤拳伤心脉",     "base_amount":30]),    //情毒                                                                                            
        ([  "name": "nx_zhua",     "cname":"凝血神爪之毒",     "base_amount":3 ]),    //凝血神爪之毒
         });
void create()
{
        set_name("无嗔大师", ({ "wuchen dashi", "wuchen", "dashi" }));
        set("title", BLU"毒手药王"NOR);
        set("gender", "男性");
        set("start_room","/d/suzhou/yaopu");
        set("long", "他就是大名鼎鼎的毒手药王。\n");
        set("age", 65);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("str", 30);
        set("per", 20);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("shen_type", 1);
        set("combat_exp", 500000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 700);
        set_temp("apply/defense", 700);
        set_temp("apply/damage", 500);

        set("vendor_goods", ({
        }));
        set("inquiry",([
                "治疗":(:ask_cure:),
                "cure":(:ask_cure:),
                ]));
        setup();
		call_out("checkme",1);
}

int checkme()
{
	object ob=this_object();
	if (!ob||!living(ob))
	{
		call_out("checkme",600);
		return 1;
	}
	if (!environment(ob))
	{
		call_out("checkme",600);
		return 1;
	}
	if (base_name(environment(ob))!="/d/suzhou/yaopu")
	{
		random_move();
		call_out("checkme",600);
		return 1;
	}
	call_out("checkme",600);
	return 1;
}


string ask_cure()
{     
            object me=this_player();
            object ob=this_object();
            int i,amount,total,duration;
            mapping poison;

      total=0;
      message_vision(CYN "$n伸出右手，搭在$N手腕上。\n"NOR, me, ob);
      message_vision(CYN "过了片刻，$n缓缓对$N说道：各项明细如下，\n" NOR, me, ob);        
      for(i=0;i<sizeof(poisons);i++) 
      {
                poison=poisons[i];
                duration=me->query_condition(poison["name"]);
                if(duration>0) 
                {
                              amount=poison["base_amount"];
                        message_vision(HIY ""+poison["cname"]+"："+chinese_number(amount)+"两黄金。\n" NOR, me, ob);
                        total+=amount;
                }       
      }
      if (total>0)
      {
      me->set_temp("cure_payment", total); 
      message_vision(CYN "$n说道：共需诊金"+total+"两黄金。\n"NOR, me, ob);
      message_vision(CYN "$n皱了皱眉又说道：如果不急早医治，恐病入膏肓。\n"NOR, me, ob);
      return "赶紧交药费吧。";
      }
        
      message_vision(CYN "$n皱眉道："+RANK_D->query_respect(me)+"又没病，怎么治？\n" NOR, me, ob);
      return "一边玩去！";
}

int accept_object(object who, object ob)
{
      object me = this_object();
      mapping poison;
      int total = who->query_temp("cure_payment");
      int value=ob->value();
      int duration,i;

      if(total==0) 
      {
              command("say "+RANK_D->query_respect(who)+"这是干什么？");
              return 0;
      }
      if(total*10000>value) 
      {
              command("say 医药费一共需要"+chinese_number(total)+"两黄金。");
              return 0;
      }
      message_vision(HIW "$N掏出几支金针，刺入$n人中，印堂，左手劳宫，右膝足三里等穴道。\n" NOR, me, who);
      message_vision(HIW "片刻之后，$N将金针一一拔下，\n$n只觉得嗓子眼发咸，张嘴吐出一口五彩斑斓的鲜血。\n" NOR, me, who);
      command("pat "+who->query("id"));
      command("say 差不多了，再发作一次就会好了。");
      for(i=0;i<sizeof(poisons);i++) 
      {
              poison=poisons[i];
              duration=who->query_condition(poison["name"]);
              if(duration>0) 
              {
                      who->apply_condition(poison["name"], 0);
              }
      }
      who->delete_temp("cure_payment");
      return 1;
}
