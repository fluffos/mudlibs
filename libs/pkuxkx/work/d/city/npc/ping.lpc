// ping.c 平一指
// edit by whuan to add change sex
// modified by Zine,增加第二次以上变性的惩罚
// 加入疗伤的功能 by whuan
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

string ask_job();
string ask_fail();
int change_title();
int ask_changesex();
int change_sex();
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
        set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
        set("title", "药铺老板");
        set("gender", "男性");
        set("start_room","/d/city/yaopu");
        set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
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
                "工作":(:ask_job:),
                "失败":(:ask_fail:),
                "变性":(:ask_changesex:),  
                "changetitle":(:change_title:),  
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
	if (base_name(environment(ob))!="/d/city/yaopu")
	{
		random_move();
		call_out("checkme",600);
		return 1;
	}
	call_out("checkme",600);
	return 1;
}

void init()
{
        add_action("change_sex", "confirm");
}

string ask_job()
{
        object ppl=this_player(),yaofang;
         if(ppl->query("combat_exp")>2000)
        {
            return "在我这里配药太埋没您拉，您还是去干点别的吧。\n";
        }
 
        if (ppl->query_temp("peiyao/in_job"))
                return "你上次的工作还没有完成！";
        else
        {
                yaofang=new(__DIR__"obj/yaofang");
                yaofang->move(ppl);
                ppl->set_temp("peiyao/in_job",1);
                ppl->set_temp("peiyao/ok",0);
                return "我们现在正好缺少一种药，这是药方，你去配吧";
        }
}

string ask_fail()
{
        object ppl=this_player();
        if (!ppl->query_temp("peiyao/in_job"))
                        return "我没有让你配药呀？";
        if (ppl->query_temp("peiyao/ok"))
                return "你不是已经把药配好了吗？";
        ppl->set_temp("peiyao/in_job",0);
        write("平一指叹了口气，说道：这点小事都干不好，还想在江湖上混？\n");
        return "你走吧，我看见你就来气";
}

int ask_changesex()
{
        object me=this_player();
        if (me->query("age")<18) 
        {
         command("say 你的年龄太小，这么大的手术可能承担不起。");
         return 1;
        }
        if (me->query("balance")<88880000)
        {
         command("say 一次手术的费用是8888黄金，我看你的存款还不够。");
         return 1;  
        }
        if(me->query("marry"))
        {
         command("ks");
         command("say 你已经结婚了，就要对另一半的幸福负责。");
         return 1;  
        }
		if (me->query("mingpin"))
		{
			command("say 大明官员也来变性？");
			command("say 我可得先提醒你，变了性很可能会被赶出大明官场的。");
		}
        if ((int)me->query("changed_gender")>4) // by Zine 防止扣钱溢出
        {
            command("say 你的下面已经被彻底破坏了，神仙也没救了！");
            return 1; 
        }
        if (time()>1306108799&&me->query("gender")=="无性")// by Zine Pixie-jian等太监技在有性别情况下使用会造成很多不合理情况。
        {
            command("laugh");
            command("say 割掉容易，接回去可难了，我又不是神仙！");
            return 1;  
        }
        write("平一指说：“你确认要变性么？请用confirm命令来确认。”\n");
        me->set_temp("ask_changesex",1);
        return 1;
}
int change_sex()
{
       object me=this_player();
       int requirebalance=88880000+88880000*(int)me->query("changed_gender")*(int)me->query("changed_gender");
       int cutexp=(int)me->query("combat_exp")/20*(int)me->query("changed_gender"); //第一次不消耗经验，以后每次消耗次数×5%经验，比如第二次消耗5%，第三次消耗10%
       if (!me->query_temp("ask_changesex")) return 0;
       if (!me->query_temp("ask_changesex_again")&&me->query("changed_gender")>=1)
       {
            tell_object(me,BLINK+HIR+"第二次以上变性将扣除经验和巨额存款，如果你一定要这样，请使用confirm命令来确认。\n"+NOR);
            me->set_temp("ask_changesex_again",1);
            return 1; 
       }
       if (me->query("changed_gender")&&me->query("balance")<requirebalance)
       {
            command("say 由于频繁变性，导致手术难度大增，这次变性需要"+chinese_number(requirebalance/10000)+"两黄金，我看你的存款还不够。");
            return 1; 
       }
       if (me->query("balance")<88880000)
       {
        command("say 一次手术的费用是"+chinese_number(requirebalance/10000)+"两黄金，我看你的存款还不够。");
        return 1;  
       }
       write(HIR"平一指一声奸笑，招呼药铺伙计给你推到了一个小黑屋中。\n"NOR);
       write(HIR"你没来得及反应,只见平一指手起刀落,"+HIW"嚓.... "+HIR"你忍不住剧痛惊叫了一声晕了过去......\n\n"NOR);
       if(me->query("gender")!="女性")
         me->set("gender","女性");
       else
         me->set("gender","男性");
       message("shout", HIM "【江湖传言】某人：据说"HIW+me->query("name")+HIM" 花费巨资，成功变性！\n" NOR,users());
       me->add("changed_gender",1);
       me->delete_temp("ask_changesex");
       me->add("balance",-requirebalance);
       if (me->query("changed_gender"))
       {
           me->add("combat_exp",-cutexp);
           me->add("exp/change_sex",-cutexp);
       }
       me->save();
       if (!wizardp(me))
       {
           me->unconcious();
       }
       
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
int change_title()
{
       object me=this_player();
       if (!me->query("xiezi") || !me->query("old_title"))
       {
          command("say 对不起，你这个我可以帮不上什么忙。");
          return 1;
       }
       if (me->query("balance")<50000)
       {
          command("say 药膏的费用为5两黄金，你的账户余额不足。");
          return 1;  
       }
       write(HIW"平一指不知道从哪里掏出来几张狗皮膏药，“啪”的几声把你脸上贴得到处都是膏药。\n"NOR);
       write(HIW"你只觉得脸上火辣辣的疼痛不已。\n\n"NOR);
       write(HIG"过了一会儿，平一指说道：“好了！”"NOR);
       me->delete("xiezi");
       me->set("title",me->query("old_title"));
       me->delete("old_title");
       me->add("balance",-50000);
       me->save();
       return 1;
}
