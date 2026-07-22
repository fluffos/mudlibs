#include <globals.h>
#include <ansi.h> 

inherit NPC;

//inherit "/d/japan/npc/offense_wokou";
void smart_fight();
int big_blowing();
int lev = random(5000);
int laa = random(150);
void create()
{       
        
        string *name= ({"月牍", "天照"});
  object me= this_object();
        int i;
        i= random(sizeof(name));
        set_name(name[i], ({ "jap badguy","badguy"}) );
        set("title", HIC"倭寇"NOR); 
        set("long","
来自东瀛的强盗，他们烧杀抢掠，无恶不作。在日出城东边的小岛上有他们
的营地，是进攻日出城的基地。\n");
        set("attitude", "aggressive");
        set("no_return",1);
        //set("bellicosity", 1);
        set("wokou",6);
        set("big_boss",9);
        set("boss",9);
        set("big_boss",6);
        set("boss",6);
        set("no_arrest",1);
set("str",10000);
set("con",10000);
set("cps",10000);
set("cor",10000);
  set("lunhui_zhuanshi",random(20));
       set("max_kee", 1800000+3000*laa);
       set("max_sen", 1800000+3000*laa);
       set("combat_exp", 825000000+random(800000000));
         set("daoxing", 825000000+random(800000000));

              set("faith", 102200);
set("lunhui_zhuanshi",20+random(10));
set("dropint",40);
set("level",100+random(100));
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

 set_skill("stick",2260+10*random(laa));
 set_skill("xingyi-stick",2260+10*random(laa));
 map_skill("stick","xingyi-stick");

  set_skill("lianhuan-zhang", 2200+lev);
  set_skill("lotusforce", 2200+lev);
  map_skill("force", "lotusforce");
  map_skill("unarmed", "hunyuan-zhang");
  map_skill("dodge", "sevensteps");
  map_skill("spells", "taoism");
  map_skill("parry", "mingyu-gong");
  map_skill("sword", "mindsword");
 map_skill("iron-cloth", "yiqiguanforce");
set("env/combatd",random(12));
 set("max_force",10300000+1500*laa);
  set("force",23000000+500*laa);
  set("max_mana",10300000+1500*laa);
  set("mana",23000000+50000*laa);
set("env/combatd",random(21));
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

set_temp("apply/armor", 56720+100*laa); 
                add_temp("apply/damage", 1055+20*laa);
add_temp("apply/armor_vs_force", 7725+random(5500)+100*laa);  	
                    set_temp("combat/bless",14*laa);
                 set_temp("combat/lucky",14*laa);
                  set_temp("apply/sub_max_armor",8600+100*laa); 
                 set_temp("apply/sub_max_defense",8900+100*laa); 
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


     add_temp("apply/sub_max_phy",15200+100*laa);
     add_temp("apply/sub_phy",13360+50*laa);
set_temp("boostcurse",1);
set_temp("dual-attack",1);
set("no_busy",20);
set_temp("npc_yyyy",1);

create_family("陷空山无底洞", 1, "弟子");

  
  set("chat_chance_combat",999);
        set("chat_msg_combat", ({
      //  (: exert_function, "qiankun" :),
                (: smart_fight() :),
   (: big_blowing :)
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




int big_blowing()
{
if(!this_object()) return 0;
if(random(10)>8 && !this_object()->query_temp("banzai"))
{
this_object()->set_temp("banzai",1);
remove_call_out("hurting");
message_vision( HIR "\n\n$N"HIR"连连挥刀,大呼"HIY"版载,版载"HIR"!!\n\n" NOR,
this_object());
call_out("hurting",random(3)+3);
}

        return 1;
}

int hurting()
{
        int i;
        int dam;
        object ob;
        object *inv;
if(!this_object()) return 0;
ob =this_object();
     ob->delete_temp("banzai");
        message_vision( HIR "\n\n$N"HIR"得到八歧大蛇赐予神力！\n\n对手突然感觉压力剧增。\n"NOR,this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        if(inv[i]->is_fighting(this_object()))
        {
        dam = inv[i]->query("sen")/(6+random(10));
        if(dam <0) dam = 0;
        inv[i]->receive_wound("kee",dam);
inv[i]->receive_damage("kee",dam);
if(random(10)>5)
 ob->add("kee",dam/10);
ob->add("eff_kee",dam/10);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
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
 command("unwield sword");
command("wield blade");
 command("enable blade ittouryu");
  command("perform gobankiri");
command("perform tianlangshixue");
   command("perform duomingqisha");
command("perform hyakki");
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
                else                        

 {
	        command("enforce 500");
 command("unwield all");
command("wield sword");
command("enable sword qixiu-jian");
  command("perform zxzx");
 command("unwield sword");
command("wield blade");
 command("enable blade ittouryu");
  command("perform gobankiri");
command("perform tianlangshixue");
   command("perform duomingqisha");
command("perform hyakki");
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
 else { 
 command("enforce 560");
  command("enable unarmed dragonfight");
command("perform pini");
 command("enable unarmed cuixin-zhang");
  command("perform cuixin");
command("enable unarmed lianhuan-zhang");
command("perform nianhua");
command("enable unarmed kongshoudao");
command("perform yaozhan");
command("perform shimon");
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
                killer->add_temp("jap_badguy/jiang2", 1);
        }
        this_object()->remove_all_killer();


         message_vision(HIW"$N叫道：八格！八格呀噜！\n"NOR,this_object());


 	 this_object()->set("is_diablo_npc",1);
		this_object()->add("magic_find",13000+random(15000));
 DIABLO_D->diablo_drop(this_object(),killer);
 DIABLO_D->diablo_drop(this_object(),killer);
 DIABLO_D->diablo_drop(this_object(),killer);
 DIABLO_D->diablo_drop(this_object(),killer);



jiangli = 60000+random(60000);

killer->add("combat_exp",jiangli);
killer->add("daoxing",jiangli);
killer->add("potential",jiangli/3);
message_vision(HIW"$N英勇杀敌，获得经验"+HIR+jiangli+HIW"点，潜能"+HIR+jiangli/3+HIW+"点！！\n"NOR,killer);



if(random(120)<=1+this_object()->query_temp("mmmmmmmmmm"))
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
/*
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
*/
