#include <ansi.h>
#include <globals.h>

inherit "/d/japan/npc/offense_wokou";
void smart_fight();
int lev = random(500);
int laa = random(150);
void create()
{       
	
				string *name= ({"蒙面忍者", "黑衣忍者","白衣忍者"});
        set_name(name[random(3)], ({ "renzhe"}) );
        set("title", HIY"倭寇"NOR); 
        set("long","
来自东瀛的强盗，他们烧杀抢掠，无恶不作。在日出城东边的小岛上有他们
的营地，是进攻日出城的基地。\n");
        set("attitude", "aggressive");
        set("no_return",1);
        //set("bellicosity", 1);
        set("no_arrest",1);
      set("str",10000);
set("con",10000);
set("cps",10000);
set("cor",10000);
  set("lunhui_zhuanshi",random(20));
       set("max_kee", 500000+3000*laa);
       set("max_sen", 500000+3000*laa);
       set("combat_exp", 825000000+random(800000000));
         set("daoxing", 825000000+random(800000000));

              set("faith", 102200);

   set_skill("unarmed", 3200+lev);
   set_skill("mindsword", 2200+lev);
   set_skill("dodge", 2200+lev);
   set_skill("parry", 2200+lev);
   set_skill("literate", 2200+lev);
   set_skill("spells", 2200+lev);
 set_skill("mingyu-gong", 2200+lev);
 set_skill("iron-cloth", 2200+lev);
 set_skill("yiqiguanforce", 2200+lev);
 set_skill("huntian-qigong", 2200+lev);
 set_skill("qixiu-jian", 2200+lev);
 set_skill("kugu-blade", 2200+lev);
 set_skill("yinfeng-zhua", 2200+lev);
 set_skill("blade", 2200+lev);
 set_skill("ittouryu", 2200+lev);
 set_skill("kongshoudao", 2200+lev);
   set_skill("force", 2200+lev);
   set_skill("zixia-shengong", 2200+lev);
   set_skill("sevensteps", 2200+lev);
   set_skill("taoism", 2200+lev);
   set_skill("hunyuan-zhang", 2200+lev);
   set_skill("yujianshu", 2200+lev);
   set_skill("canxin-jian", 2200+lev);
   set_skill("sword", 2200+lev);
  set_skill("moyun-shou", 2200+lev);
  set_skill("huomoforce", 2200+lev);
  set_skill("lengquan-force", 2200+lev);
  set_skill("changquan", 2200+lev);
  set_skill("cuixin-zhang", 2200+lev);
  set_skill("ningxie-force", 2200+lev);
  set_skill("cloudforce", 2200+lev);
  set_skill("lianhuan-zhang", 2200+lev);

  map_skill("force", "zixia-shengong");
  map_skill("unarmed", "hunyuan-zhang");
  map_skill("dodge", "sevensteps");
  map_skill("spells", "taoism");
  map_skill("parry", "mingyu-gong");
  map_skill("sword", "mindsword");
 map_skill("iron-cloth", "yiqiguanforce");
set("env/combatd",random(1));
 set("max_force",10300000+1500*laa);
  set("force",23000000+500*laa);
  set("max_mana",10300000+1500*laa);
  set("mana",23000000+50000*laa);
set("env/combatd",random(1));
        set("resistance/kee",90);
        set("resistance/gin",90);
        set("resistance/sen",90);
        set("lunhui_zhuanshi",random(30));
  set("skill_level/sword","grandmaster");
            set("skill_level/dodge","grandmaster");
 set("skill_level/parry","grandmaster");
 set("skill_level/force","grandmaster");
 set("skill_level/spells","grandmaster");
 set("skill_level/unarmed","grandmaster");
 set("skill_level/whip","grandmaster");
 set("skill_level/spear","grandmaster");
 set("skill_level/blade","grandmaster");
 set("skill_level/axe","grandmaster");
 set("skill_level/fork","grandmaster");
 set("skill_level/mace","grandmaster");
 set("skill_level/throwing","grandmaster");
 set("skill_level/literate","grandmaster");
 set("skill_level/iron-cloth","grandmaster");
 set("skill_level/staff","grandmaster");
 set("skill_level/stick","grandmaster");
 set("skill_level/dagger","grandmaster");
 set("skill_level/music","grandmaster");
 set("skill_level/hammer","grandmaster");
 set("zs1/family","南海普陀山");
  set("zs2/family","盘丝洞");
set("zs3/family","月宫");
set("zs4/family","方寸山三星洞");
set("zs5/family","阎罗地府");
set("zs6/family","峨眉派");
set("zs7/family","神剑山庄");
set("zs8/family","东海龙宫");
set("zs9/family","火云洞");
set("zs10/family","陷空山无底洞");
set("zs11/family","五庄观");
set("zs12/family","大雪山");
set("zs13/family","将军府");
set("zs14/family","蜀山剑派");
set("zs15/family","幻世魔导");
set("zs16/family","幻世勇者");
set("zs17/family","日月神教");
set("zs18/family","武圣门");
set("zs19/family","轩辕古墓");
set("zs20/family","三界散仙");
set("zs21/family","昆仑山玉虚洞");

set_temp("apply/armor", 56720+300*laa); 
                add_temp("apply/damage", 1455+20*laa);
add_temp("apply/armor_vs_force", 15725+random(5500)+100*laa);  	
                    set_temp("combat/bless",14*laa);
                 set_temp("combat/lucky",14*laa);
                  set_temp("apply/sub_max_armor",17600+100*laa); 
                 set_temp("apply/sub_max_defense",17900+100*laa); 
if(!random(2)) set_temp("apply/immune_jin",1);
if(!random(2)) set_temp("apply/immune_mu",1);
if(!random(2)) set_temp("apply/immune_shui",1);
if(!random(2)) set_temp("apply/immune_huo",1);
     add_temp("apply/sub_max_phy",22200+100*laa);
     add_temp("apply/sub_phy",12360+10*laa);
set_temp("boostcurse",1);
set_temp("dual-attack",1);
set("no_busy",20);
set_temp("npc_yyyy",1);

create_family("陷空山无底洞", 1, "弟子");

  
  set("chat_chance_combat",999);
        set("chat_msg_combat", ({
      //  (: exert_function, "qiankun" :),
                (: smart_fight() :),
                    }) );
  
        setup(); 
     carry_object("/d/japan/npc/obj/armor")->wear();
carry_object("/d/japan/npc/obj/sword")->wield();
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");
carry_object("/d/japan/npc/obj/sword");

carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
carry_object("/d/japan/npc/obj/blade4");
} 


void init()
{
 
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() 
	  && living(me) ) {
    call_out("greeting", 1, me);
  }

}

void greeting(object me)
{
  
  object ob = this_object(); 
  if( !me || environment(me) != environment() ) return;
      kill_ob(me);
      me->kill_ob(ob);
      return;
 
}



varargs void invocation(int exp,int life_bonus,object who)
{
        exp = exp/3*3;
//        ::invocation(exp,life_bonus,who);
        }
        
void smart_fight() {
 object me;
 me = this_object();
 
 if (query_temp("weapon")) { 
                if (random(5))
{
                    {
	       command("enforce 500");
 command("unwield all");
command("wield sword");
command("enable sword qixiu-jian");
  command("perform zxzx");
  command("perform jianxi");
command("perform qijian");
command("enable sword canxin-jian");
command("perform xiangsi");
command("perform xiaoyao");
command("unwield sword");
command("wield blade");
command("enable blade kugu-blade");
command("perform pozhan");
command("perform du");
 command("enable blade ittouryu");
  command("perform gobankiri");
  command("perform hyakki");
command("perform duomingqisha");
command("perform tianlangshixue");


	       	 }


}
                else
                       

 {

command("enforce 500");
 command("unwield all");
command("wield sword");
command("enable sword qixiu-jian");
  command("perform zxzx");
  command("perform sishen");
command("perform kuangsha");
command("enable sword mindsword");
command("perform jianqi");
command("perform tonggui");
command("perform yujian");
command("unwield sword");
command("enable unarmed yinfeng-zhua");
command("perform yinfeng");
 command("enable unarmed kongshoudao");
  command("perform shimon");
command("perform yaozhan");
command("wield blade");
command("enable blade ittouryu");
  command("perform hyakki");
command("perform duomingqisha");
command("perform tianlangshixue");



	       	 }


                }
 else { 
                       command("unwield all");
                        command("enforce 560");
 command("enable unarmed moyun-shou");
  command("perform pofuchenzhou");
  command("perform zhangxinlei");
 command("enable unarmed cuixin-zhang");
  command("perform cuixin");
command("enable unarmed yinfeng-zhua");
command("perform yinfeng");
command("enable unarmed kongshoudao");
command("perform yaozhan");
command("perform shimon");
command("enable unarmed lianhuan-zhang");
command("perform nianhua");



 }
}







/*
void init() 
{                               
  object target;
     ::init();
     if( !query_heart_beat(this_object())) set_heart_beat(1);        
  
  if(environment() && !environment()->query("no_fight")) 
  {
     target =  this_player();
     if(!target->query("no_see")&&!target->query("wokou"))
     {
         kill_ob(target);
         target->kill_ob(this_object());
     }
   }
} 
varargs void invocation(int exp,int life_bonus,object who)
{
        exp = exp/3*3;
//        ::invocation(exp,life_bonus,who);
        }
        
void smart_fight() {
 object me;
 object ob;
object *inv;
object target;
int i,j;
 me = this_object();
  if (environment()) {
    inv = all_inventory(environment());
    for (i=0;i<sizeof(inv);i++) {
     target =  inv[i];
     if(living(target) && !target->query("no_see") && !target->query("wokou"))
     {
         kill_ob(target);
         target->kill_ob(this_object());
     }
   }
  }
 
      command("wield all");
 if (query_temp("weapon")) { 
                if (random(2))
{
                    {
	        command("enforce 500");
 command("unwield all");
command("wield sword");
command("enable sword qixiu-jian");
  command("perform zxzx");
  command("perform jianxi");
command("perform qijian");
command("enable sword canxin-jian");
command("perform xiangsi");
command("perform xiaoyao");
command("unwield sword");
command("wield blade");
command("enable blade kugu-blade");
command("perform pozhan");
command("perform du");
 command("enable blade ittouryu");
  command("perform gobankiri");
  command("perform hyakki");
command("perform duomingqisha");
command("perform tianlangshixue");
	       	 }


}
                else                        

 {
	        command("enforce 500");
 command("unwield all");
command("wield sword");
command("enable sword qixiu-jian");
  command("perform zxzx");
  command("perform sishen");
command("perform kuangsha");
command("enable sword mindsword");
command("perform jianqi");
command("perform tonggui");
command("perform yujian");
command("unwield sword");
command("enable unarmed yinfeng-zhua");
command("perform yinfeng");
 command("enable unarmed kongshoudao");
  command("perform shimon");
command("perform yaozhan");
command("wield blade");
command("enable blade ittouryu");
  command("perform hyakki");
command("perform duomingqisha");
command("perform tianlangshixue");

	       	 }


                }
 else { 
command("unwield all");
                        command("enforce 560");
 command("enable unarmed moyun-shou");
  command("perform pofuchenzhou");
  command("perform zhangxinlei");
 command("enable unarmed cuixin-zhang");
  command("perform cuixin");
command("enable unarmed yinfeng-zhua");
command("perform yinfeng");
command("enable unarmed kongshoudao");
command("perform yaozhan");
command("perform shimon");
command("enable unarmed lianhuan-zhang");
command("perform nianhua");
 }
}
*/
void unconcious()
{
        die();
}
void die()
{
        int gin,kee,sen,i,j;
        int expg,potg,scoreg,moneyg;
        object room;
        object *inv;
        string reward_msg;
object killer;
int jiangli;
	if(killer = query_temp("last_damage_from"))
   //     if (objectp(killer))
        {
          //   if(killer->query("possessed")) killer =killer->query("possessed");
                killer->add_temp("jap_badguy/jiang2", 1);
        }
        this_object()->remove_all_killer();


         message_vision(HIW"$N叫道：八格！八格呀噜！\n"NOR,this_object());


 	 this_object()->set("is_diablo_npc",1);
		this_object()->add("magic_find",13000+random(15000));
 DIABLO_D->diablo_drop(this_object(),killer);
 DIABLO_D->diablo_drop(this_object(),killer);


jiangli = 100000+random(100000);

killer->add("combat_exp",jiangli);
killer->add("daoxing",jiangli);
killer->add("potential",jiangli/5);
message_vision(HIW"$N英勇杀敌，获得经验"+HIR+jiangli+HIW"点，潜能"+HIR+jiangli/3+HIW+"点！！\n"NOR,killer);

        destruct(this_object());
        return ; 
}   

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        mixed pob;
        string str;
        int i,n;
        if(random(50)<query("wokou"))
        {
            pob=previous_object(-1);
            for(i=0;i<sizeof(pob);i++)
                if (objectp(pob[i]) && living(pob[i]))
                {
                    message_vision( HIW"\n结果$n被$N的反击攻了个手忙脚乱。\n"NOR,this_object(),pob[i]);
                    pob[i]->start_busy(1);
                    break;
                }
        }
        else
        if(new_busy>0) 
        {
        	if(random(query("wokou"))<4)
        	        ::start_busy(1);
	        else
                        message_vision(CYN"$N真气流转，身形飘忽灵动，变幻无方。\n"NOR,this_object());
	}
} 

