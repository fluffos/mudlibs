#include <globals.h>
#include <ansi.h> 

inherit NPC;

//inherit "/d/japan/npc/offense_wokou";
void smart_fight();
int laa = random(600);
void create()
{       
        
                                string *name= ({"黑面罗刹", "红发罗刹"});
        set_name(name[random(2)], ({ "jap badguy", "badguy"}) );
        set("title", HIM"倭寇"NOR); 
        set("long","
来自东瀛的强盗，他们烧杀抢掠，无恶不作。在日出城东边的小岛上有他们
的营地，是进攻日出城的基地。\n");
              set("attitude", "aggressive");
        set("no_return",1);
        set("no_arrest",1);
        //set("bellicosity", 1);
        set("wokou",1);
set("env/combatd",random(11));
        set("str", 10000);
        set("combat_exp", 500000000+1000000*laa);
 set("daoxing", 500000000+1000000*laa);

       // set("class","ninja");
     set("max_kee",730000+6000*laa);
        set("max_sen",730000+6000*laa);
      //  set("max_gin",20000);
        set("force_factor",10*laa);
        set("chat_chance_combat", 999);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
set("lunhui_zhuanshi",20+random(10));
set("dropint",40);
set("level",100+random(100));
   set_skill("force",1900+10*random(laa));
        set_skill("lengquan-force",1900+10*random(laa));
        set_skill("unarmed", 3050+10*random(laa));
        set_skill("blade", 3250+10*random(laa));
        set_skill("parry", 3250+10*random(laa));
set_skill("spells", 3250+10*random(laa));
set_skill("baguazhou", 3250+10*random(laa));
set_skill("buddhism", 2250+10*random(laa));
        set_skill("dodge", 3250+10*random(laa));
        set_skill("kugu-blade",1860+10*random(laa));
  set_skill("ittouryu",1860+10*random(laa));
  set_skill("kongshoudao",1860+10*random(laa));
 set_skill("huntian-qigong",1260+10*random(laa));
 set_skill("cloudforce",1260+10*random(laa));
 set_skill("shenji-blade",1860+10*random(laa));
 set_skill("shadowsteps",1260+10*random(laa));
 set_skill("butian-force",1260+10*random(laa));
 set_skill("tianxin-blade",1260+10*random(laa));
 set_skill("lengquan-force",1260+10*random(laa));
 set_skill("wuhu-blade",1260+10*random(laa));
        set_skill("mingyu-gong",1500+10*random(laa));
        set_skill("yueying-wubu",1750+10*random(laa));
        set_skill("lianhuan-zhang",1200+10*random(laa));
  set_skill("xiantian",1200+10*random(laa));
  set_skill("xuanhu-blade",1200+10*random(laa));
  set_skill("moonforce",1200+10*random(laa));
  set_skill("moonshentong",1200+10*random(laa));
set_skill("ningxie-force",1200+10*random(laa));
set_skill("dengxian-dafa",1200+10*random(laa));
set_skill("bingpo-blade",1200+10*random(laa));
set_skill("wanxi-spells",1200+10*random(laa));
set_skill("wanxi-force",1200+10*random(laa));
set_skill("dragonforce",1200+10*random(laa));
set_skill("seashentong",1200+10*random(laa));
set_skill("kongshoudao",1200+10*random(laa));
set_skill("dragonfight",1200+10*random(laa));
set_skill("cuixin-zhang",1200+10*random(laa));
set_skill("moyun-shou",1200+10*random(laa));
set_skill("huomoforce",1200+10*random(laa));
set_skill("lotusforce",3200+10*random(laa));
set_skill("stick",1260+10*random(laa));
 set_skill("xingyi-stick",1260+10*random(laa));
 map_skill("stick","xingyi-stick");
        map_skill("blade","ittouryu");
        map_skill("parry","mingyu-gong");
        map_skill("dodge","yueying-wubu");
       //map_skill("dodge","fall-steps"); 
        map_skill("force","lotusforce"); 
map_skill("spells","baguazhou"); 
	map_skill("unarmed","lianhuan-zhang"); 
 set("max_force",10300000+1500*laa);
  set("force",23000000+500*laa);
  set("max_mana",10300000+1500*laa);
  set("mana",23000000+50000*laa);

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

set_temp("apply/armor", 36720+100*laa); 
                add_temp("apply/damage", 455+20*laa);
add_temp("apply/armor_vs_force", 4725+random(3500)+50*laa);  	
                    set_temp("combat/bless",14*laa);
                 set_temp("combat/lucky",14*laa);
                  set_temp("apply/sub_max_armor",4600+50*laa); 
                 set_temp("apply/sub_max_defense",5900+50*laa); 
if(!random(2)) set_temp("apply/immune_jin",1);
if(!random(2)) set_temp("apply/immune_mu",1);
if(!random(2)) set_temp("apply/immune_shui",1);
if(!random(2)) set_temp("apply/immune_huo",1);

set_temp("apply/max_huo",1000+random(1200));
set_temp("apply/huo",1000+random(1200));
set_temp("apply/max_jin",1000+random(1200));
set_temp("apply/jin",1000+random(1200));
set_temp("apply/max_shui",1000+random(1200));
set_temp("apply/shui",1000+random(1200));

set_temp("apply/max_mu",1000+random(1200));
set_temp("apply/mu",1000+random(1200));
set_temp("apply/max_tu",1000+random(1200));
set_temp("apply/tu",1000+random(1200));

set_temp("apply/sub_shui",1000+random(1200));
set_temp("apply/sub_max_shui",1000+random(1200));
set_temp("apply/sub_mu",1000+random(1200));
set_temp("apply/sub_max_mu",1000+random(1200));
set_temp("apply/sub_jin",1000+random(1200));
set_temp("apply/sub_max_jin",1000+random(1200));
set_temp("apply/sub_huo",1000+random(1200));
set_temp("apply/sub_max_huo",1000+random(1200));
set_temp("apply/sub_tu",1000+random(1200));
set_temp("apply/sub_max_tu",1000+random(1200));


     add_temp("apply/sub_max_phy",9200+100*laa);
     add_temp("apply/sub_phy",8360+30*laa);
set_temp("boostcurse",1);
set_temp("dual-attack",1);
set("no_busy",20);
set_temp("npc_yyyy",1);
set("env/combatd",1);
        setup(); 

        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/blade3")->wield();
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");
 carry_object(__DIR__"obj/blade3");

carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
carry_object(__DIR__"obj/qiankun");
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
*/

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
 command("enable blade ittouryu");
command("wield blade");
  command("perform gobankiri");
command("perform tianlangshixue");
 command("unwield all");
 command("wield stick");
 command("enable stick xingyi-stick");
 command("perform yinyangling");
 command("perform menghuantianluo");
 command("unwield all");
command("exert roar");
command("wield blade");
	       	 }


}
                else
                       

 {
	         command("enforce 500");
command("wield blade");
 command("enable blade ittouryu");
  command("perform gobankiri");
command("perform tianlangshixue");
 command("unwield all");
 command("wield stick");
 command("enable stick xingyi-stick");
 command("perform yinyangling");
 command("perform menghuantianluo");
 command("unwield all");
command("exert roar");
command("wield blade");
	       	 }


                }
 else { 
                       command("enforce 560");
 command("enable unarmed moyun-shou");
  command("perform pofuchenzhou");
 command("enable unarmed dragonfight");
command("perform pini");
 command("enable unarmed cuixin-zhang");
  command("perform cuixin");
command("enable unarmed lianhuan-zhang");
command("perform nianhua");
 command("unwield all");
 command("wield stick");
 command("enable stick xingyi-stick");
 command("perform yinyangling");
 command("perform menghuantianluo");
 command("unwield all");
command("wield blade");
command("exert roar");

 }
}


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

object bb;
int m;
	if(killer = query_temp("last_damage_from"))
   //     if (objectp(killer))
        {
          //   if(killer->query("possessed")) killer =killer->query("possessed");
                killer->add_temp("jap_badguy/bing3", 1);
        }
        this_object()->remove_all_killer();


         message_vision(HIW"$N叫道：八格！八格呀噜！\n"NOR,this_object());


 	 this_object()->set("is_diablo_npc",1);
		this_object()->add("magic_find",13000+random(15000));
 DIABLO_D->diablo_drop(this_object(),killer);
 DIABLO_D->diablo_drop(this_object(),killer);



jiangli = 40000+random(40000);

killer->add("combat_exp",jiangli);
killer->add("daoxing",jiangli);
killer->add("potential",jiangli/3);
message_vision(HIW"$N英勇杀敌，获得经验"+HIR+jiangli+HIW"点，潜能"+HIR+jiangli/3+HIW+"点！！\n"NOR,killer);


if(random(220)<=1+this_object()->query_temp("mmmmmmmmmm"))
{
m=random(16);
if(m==0)
  bb=new("/d/sunrise/obj/book");
else if(m==1)
  bb=new("/d/sunrise/obj/book2");
else if(m==2)
  bb=new("/d/sunrise/obj/book3");
else if(m==3)
  bb=new("/d/sunrise/obj/book4");
else if(m==4)
  bb=new("/d/sunrise/obj/book5");
else if(m==5)
  bb=new("/d/sunrise/obj/book6");
else if(m==6)
  bb=new("/d/sunrise/obj/book7");
else if(m==7)
  bb=new("/d/sunrise/obj/book8");
else if(m==8)
  bb=new("/d/sunrise/obj/book9");
else if(m==9)
  bb=new("/d/sunrise/obj/book10");
else if(m==10)
  bb=new("/d/sunrise/obj/book11");
else if(m==11)
  bb=new("/d/sunrise/obj/book12");
else if(m==12)
  bb=new("/d/sunrise/obj/book13");
else if(m==13)
  bb=new("/d/sunrise/obj/book14");
else   bb=new("/d/sunrise/obj/book15");


killer->command("mp* haha");
killer->command("chat* gongxi");
killer->command("xyj 倭岛几翻生死,百转血战,得觅神修宝典,幸哉幸哉!!");
 bb->set("owner",killer);

bb->move(killer);
}




        destruct(this_object());
        return ; 
}   

