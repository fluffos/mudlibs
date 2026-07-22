

#include "ansi.h"

#define M_RAND 100
#define P_RAND 100

void add_food(object ob,int i);
void add_water(object ob,int i);
void heal_sen(object ob,int i);
void heal_gin(object ob,int i);
void heal_kee(object ob,int i);
void add_food_water_heal_sen(object ob,int i);
void add_force(object ob,int i);

void reduce_food(object ob,int i);
void reduce_water(object ob,int i);
void damage_sen(object ob,int i);
void damage_gin(object ob,int i);
void damage_kee(object ob,int i);
void busy(object ob,int i);
void damage_sen_kee_busy(object ob,int i);
void reduce_force(object ob,int i);

void add_parry(object ob,int i);
void add_dodge(object ob,int i);
void temp_add_force(object ob,int i);
void temp_add_maxforce(object ob,int i);
void temp_add_str(object ob,int i);
void temp_add_con(object ob,int i);
void temp_add_dex(object ob,int i);
void temp_add_int(object ob,int i);
void add_max_force(object ob,int i);
void add_str(object ob,int i);
void add_con(object ob,int i);
void add_dex(object ob,int i);
void add_int(object ob,int i);
void add_exp(object ob,int i);
void add_pot(object ob,int i);

//明药师
mapping medicine_type=([
"补充食物":(:add_food:),//75%
"增加饮水":(:add_water:),//65%
"恢复精神":(:heal_sen:),//60%
"恢复精血":(:heal_gin:),//50%
"恢复气血":(:heal_kee:),//40%
"补品":(:add_food_water_heal_sen:),//20%
"增加内力":(:add_force:),//5%

]);// 效果从左到右，出现的几率依次降低。
//补品 效果是 +水 +食物 +精神

//暗药师
mapping poison_type=([
"降低食物":(:reduce_food:),//90%
"减少饮水":(:reduce_water:),//80%
"损害精神":(:damage_sen:),//70%
"损害精血":(:damage_gin:),//60%
"损害气血":(:damage_kee:),//40%
"麻痹":(:busy:),//20%
"剧毒":(:damage_sen_kee_busy:),//15%
"损害内力":(:reduce_force:),//5%
]);// 效果从左到右，出现的几率依次降低。
//剧毒效果是 -精神 -气血 麻痹


string get_medicine_type(int dtype,string *types)
{
  if(dtype>=95)
   return types[sizeof(types)-1];
  if(dtype>=80)
   return types[sizeof(types)-2];
  if(dtype>=60)
   return types[sizeof(types)-3];
  if(dtype>=50)
   return types[sizeof(types)-4];
  if(dtype>=40)
   return types[sizeof(types)-5];
  if(dtype>=35)
   return types[sizeof(types)-6];
  
   return types[sizeof(types)-7];

}

string get_poison_type(int dtype,string *types)
{
  if(dtype>=95)
   return types[sizeof(types)-1];
  if(dtype>=85)
   return types[sizeof(types)-2];
  if(dtype>=80)
   return types[sizeof(types)-3];
  if(dtype>=60)
   return types[sizeof(types)-4];
  if(dtype>=40)
   return types[sizeof(types)-5];
  if(dtype>=30)
   return types[sizeof(types)-6];
  if(dtype>=20)
   return types[sizeof(types)-7];
  
  return types[sizeof(types)-8];

}

mapping medicine_add_type=([

"暂时增加防御":(:add_parry:),
"暂时增加命中":(:add_dodge:),
"暂时增加内力":(:temp_add_force:),
"暂时增加内力上限":(:temp_add_maxforce:),
"暂时增加臂力":(:temp_add_str:),
"暂时增加根骨":(:temp_add_con:),
"暂时增加身法":(:temp_add_dex:),
"暂时增加悟性":(:temp_add_int:),
"增加内力上限":(:add_max_force:),
"增加臂力":(:add_str:),
"增加根骨":(:add_con:),
"增加敏捷":(:add_dex:),
"增加悟性":(:add_int:),
"增加经验":(:add_exp:),
"增加潜能":(:add_pot:),

]);



void set_medicine_add_type(object ob,mapping type)
{
    int lev;
    
    lev=ob->query_skill("bencao-shuli",1);
    
    if(lev<200)
     return;
    
    if(random(100)>90)
     type+=([ "暂时增加防御":random(lev/10) ]);
    
    if(random(100)>90)
     type+=([ "暂时增加命中":random(lev/10) ]);
    
    if(random(100)>96)
     type+=([ "暂时增加内力":lev*(1+random(4)) ]);
    
    if(random(100)>96)
     type+=([ "暂时增加内力上限":lev*(1+random(4)) ]);
    
    if(random(200)==ob->query_kar())
     type+=([ "暂时增加臂力":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "暂时增加根骨":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "暂时增加身法":random(lev/200) ]);
    if(random(200)==ob->query_kar())
     type+=([ "暂时增加悟性":random(lev/200) ]);
    
    if(random(500)==ob->query_kar())
     type+=([ "增加内力上限":random(lev/100) ]);
    
    if(random(3000)==ob->query_kar())
     type+=([ "增加臂力":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "增加根骨":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "增加悟性":random(lev/200) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "增加敏捷":random(lev/200) ]);
    
    if(random(3000)==ob->query_kar())
     type+=([ "增加经验":random(lev/10) ]);
    if(random(3000)==ob->query_kar())
     type+=([ "增加潜能":random(lev/10) ]);
    
    
	
}

mapping names=([
HIG"兰草"NOR:"lancao", YEL"山茱萸"NOR:"shanzhuyu",WHT"白 术"NOR:"baizhu",
WHT"白 芷"NOR:"baizhi",HIW"白 薇"NOR:"baiwei",WHT"白附子"NOR:"baifuzi",
WHT"白 蔹"NOR:"bailian",WHT"白首乌"NOR:"baishouwu",WHT"百合"NOR:"baihe",
YEL"北豆根"NOR:"beidougen",YEL"北沙参"NOR:"beishashen",WHT"苍 术"NOR:"cangshu",
HIG"柴 胡"NOR:"chaihu",YEL"石菖蒲"NOR:"shiChangpu",HIY"常 山"NOR:"changshan",
HIG"赤勺"NOR:"chishao",YEL"川 芎"NOR:"chuanxiong",MAG"川木香"NOR:"chuanmuxiang",
MAG"川贝母"NOR:"chuanbeimu",YEL"川牛膝"NOR:"chuanniuxi",YEL"刺五加"NOR:"ciwujia",
YEL"大 黄"NOR:"dahuang",HIR"丹 参"NOR:"danshen",MAG"当 归"NOR:"danggui",
HIG"党 参"NOR:"dangshen",MAG"地 黄"NOR:"dihuang",MAG"地 榆"NOR:"diyu",
MAG"独 活"NOR:"duhuo",HIM"郁 金"NOR:"yujin",HIY"萆薢"NOR:"bixie",

MAG"紫苏子"NOR:"zisuzi",YEL"枳 实"NOR:"zhishi",WHT"枳 壳"NOR:"zhiqiao",
WHT"预知子"NOR:"yuzhizi",HIG"郁李仁"NOR:"yuliren",HIB"罂粟壳"NOR:"yingsuqiao",
WHT"薏苡仁"NOR:"yiyiren",HIG"益 智"NOR:"yizhi",MAG"芫荽子"NOR:"yuanxuzi",
BLU"亚麻子"NOR:"yamazi",YEL"鸦胆子"NOR:"yadanzi",YEL"小茴香"NOR:"xiahuixiang",
WHT"香 橼"NOR:"xiangyuan",HIG"西瓜翠"NOR:"xiguacui",HIG"五味子"NOR:"wuwezi",
HIG"梧桐子"NOR:"wutongzi",YEL"吴茱萸"NOR:"wuzhuyu",HIG"乌 梅"NOR:"wumei",
HIG"栀 子"NOR:"zhizi",HIG"王不留行"NOR:"wangbuliuxing",YEL"菟丝子"NOR:"tusizi",
YEL"葶苈子"NOR:"tinglizi",YEL"甜瓜子"NOR:"tianguazi",MAG"天仙子"NOR:"tianxianzi",
HIM"桃 仁"NOR:"taoren",YEL"酸枣仁"NOR:"suanzaoren",HIG"丝瓜络"NOR:"sigualuo",
YEL"柿 蒂"NOR:"shidi",YEL"使君子"NOR:"shijunzi",HIG"石榴皮"NOR:"shiliupi",

WHT"艾 叶"NOR:"aiye",HIR"侧柏叶"NOR:"cebaiye",YEL"臭梧桐"NOR:"chouwutong",
YEL"大青叶"NOR:"daqingye",MAG"丁 香"NOR:"dingxiang",HIY"番泻叶"NOR:"fanxieye",
HIY"芫 花"NOR:"yuanhua",RED"罗布麻叶"NOR:"luobumaye",YEL"桑 叶"NOR:"sangye",
HIY"菊 花"NOR:"juhua",YEL"枇杷叶"NOR:"pipaye",YEL"蒲 黄"NOR:"puhuang",
RED"西红花"NOR:"fanhonghua",HIR"红 花"NOR:"honghua",HIG"槐 花"NOR:"huaihua",
YEL"谷精草"NOR:"gujingcao",RED"合欢花"NOR:"hehuanhua",MAG"金银花"NOR:"jinyinhua",
MAG"密蒙花"NOR:"mimenghua",MAG"款冬花"NOR:"kuandonghua",WHT"旋覆花"NOR:"xuanfuhua",
WHT"辛夷花"NOR:"xinyihua",YEL"洋金花"NOR:"yangjinghua",YEL"玉米须"NOR:"yumixu",
HIY"闹羊花"NOR:"naoyanghua",YEL"木槿花"NOR:"mujinghua",MAG"玫瑰花"NOR:"meiguihua",
MAG"夏枯草"NOR:"xiakucao",YEL"樟 脑"NOR:"zhangnao",MAG"紫花地丁"NOR:"zihuadiding",

MAG"紫 苏"NOR:"zisu",MAG"泽 兰"NOR:"zelan",MAG"鱼腥草"NOR:"yuxingcao",
YEL"淫羊藿"NOR:"yinyanghuo",HIG"茵 陈"NOR:"yinchen",MAG"益母草"NOR:"yimucao",
WHT"鸭跖草"NOR:"yazhicao",YEL"寻骨风"NOR:"xungufeng",HIG"小 蓟"NOR:"xiaoji",
WHT"香 薷"NOR:"xiangru",	

]);

void set_new_name(object obj)
{
  string *newnames,name;
  
  newnames=keys(names);
  name=newnames[random(sizeof(newnames))];
  
  obj->set_name(name,({ names[name] }) );
	
	
}

void add_food(object ob,int i)
{
  ob->add("food",i);
  
}

void add_water(object ob,int i)
{
  ob->add("water",i);
  
}

void heal_sen(object ob,int i)
{
  ob->receive_curing("sen",i);
  
}

void heal_gin(object ob,int i)
{
  ob->receive_curing("gin",i);
  
}

void heal_kee(object ob,int i)
{
  ob->receive_curing("kee",i);
 
}

void add_food_water_heal_sen(object ob,int i)
{
  ob->add("food",i);
  ob->add("water",i);
  ob->receive_curing("sen",i);

}

void add_force(object ob,int i)
{
  ob->add("force",i);
 
}

void reduce_food(object ob,int i)
{
  ob->add("food",-i);
  if(ob->query("food")<0)
  ob->set("food",0);

}

void reduce_water(object ob,int i)
{
  ob->add("water",-i);
  if(ob->query("water")<0)
  ob->set("water",0);

}

void damage_sen(object ob,int i)
{
  ob->receive_damage("sen",i*2);
  ob->receive_wound("sen",i);
  
}

void damage_gin(object ob,int i)
{
  ob->receive_damage("gin",i*2);
  ob->receive_wound("gin",i);
 
}

void damage_kee(object ob,int i)
{
  ob->receive_damage("kee",i*2);
  ob->receive_wound("kee",i);
 
}

void busy(object ob,int i)
{
  ob->start_busy(random(i/100));
  
}

void damage_sen_kee_busy(object ob,int i)
{
   ob->receive_damage("sen",i*2);
   ob->receive_damage("kee",i*2);
   ob->receive_wound("sen",i);
   ob->receive_wound("kee",i);
   ob->start_busy(random(i/100));
}

void reduce_force(object ob,int i)
{
   ob->add("force",-i*3);
  if(ob->query("force")<0)
  ob->set("force",0);
}

void add_parry(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_parry"))
    return;  
   info["number"]=i;
   info["times"]=i*2/5;
   
   ob->add_temp("apply/parry",i);
   ob->set_temp("medicine_add_temp_parry",1);
   
   ob->apply_condition("add_temp_parry",info);
   
}

void add_dodge(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_dodge"))
    return;  
   info["number"]=i;
   info["times"]=i*2/5;
   
   ob->add_temp("apply/dodge",i);
   ob->set_temp("medicine_add_temp_dodge",1);
   
   ob->apply_condition("add_temp_dodge",info);
   
}

void temp_add_str(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_str"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/strength",i);
   ob->set_temp("medicine_add_temp_str",1);
   
   ob->apply_condition("add_temp_str",info);
   
}

void temp_add_dex(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_dex"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/dodgeaction",i);
   ob->set_temp("medicine_add_temp_dex",1);
   
   ob->apply_condition("add_temp_dex",info);
   
}

void temp_add_int(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_int"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/intelligence",i);
   ob->set_temp("medicine_add_temp_int",1);
   
   ob->apply_condition("add_temp_int",info);
   
}

void temp_add_con(object ob,int i)
{
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_con"))
    return;  
   info["number"]=i;
   info["times"]=i*10;
   
   ob->add_temp("apply/constitution",i);
   ob->set_temp("medicine_add_temp_con",1);
   
   ob->apply_condition("add_temp_con",info);
   
}

void temp_add_force(object ob,int i)
{
   int time;
   
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_force"))
    return;  
   info["number"]=i;
   time=i/100;
   if(time<2) time=2;
   if(time>20) time=20;
   info["times"]=time;
   
   ob->add("force",i);
   ob->set_temp("medicine_add_temp_force",i);
   
   ob->apply_condition("add_temp_force",info);
   
}

void temp_add_maxforce(object ob,int i)
{
   int time;
   
   mapping info=([ "number":0,
                   "times":0,
                ]);
      
   if(ob->query_condition("add_temp_maxforce"))
    return;  
   info["number"]=i;
   time=i/100;
   if(time<2) time=2;
   if(time>20) time=20;
   info["times"]=time;
   
   ob->add("max_force",i);
   ob->set_temp("medicine_add_temp_maxforce",i);
   
   ob->apply_condition("add_temp_maxforce",info);
   
}

void add_max_force(object ob,int i)
{
  ob->add("max_force",i);
}

void add_str(object ob,int i)
{
   ob->add("str",i);
}
void add_con(object ob,int i)
{
   ob->add("con",i);
}   
void add_dex(object ob,int i)
{
   ob->add("dex",i);
}
void add_int(object ob,int i)
{
   ob->add("int",i);
}
void add_exp(object ob,int i)
{
   ob->add("combat_exp",i);
}
void add_pot(object ob,int i)
{
   ob->add("potential",i);
}