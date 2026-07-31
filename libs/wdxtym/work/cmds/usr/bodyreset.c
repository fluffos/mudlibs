// derive.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

mapping roushen = ([
	"零" : HIW "凡体俗身  ",
	"一" : HIY "筋骨强劲",
	"二" : HIY "刀枪不入",
	"三" : HIR "铜皮铁骨",
	"四" : HIR "金刚不坏",
	"五" : HIC "不死不灭",
	"六" : HIC "肉身成圣",
]);

varargs int deriving(object me);
int halt_deriving(object me);
int dest_room(object me,object room);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
int zon,reset;
string* sk,map_skill;
int i;
int j;

reset=me->query("bodyreset")*100+500;

if (arg=="explain")
{

string msg;

msg= ZJOBLONG+HIR "◎"HIY "重修系统" HIR "◎"NOR+ZJBR;

msg+=HIG"——————————————————————"NOR+ZJBR;

msg+="肉身重修可以使你改头换面，并且清除个人全部武功和吃丹记录以及内力、潜能、精力、灵慧、阅历和威望，保留30w修为和全部属性，经过此过程，你便可以重新拜师学艺和提升自己的先天属性。"ZJBR;
msg+=HIG"——————————————————————"NOR+ZJBR;
msg+="目前重修次数：("HIM+me->query("bodyreset")+NOR")"ZJBR;
msg+="当前重修条件：师门贡献一万（不消耗）、钻石一千、基本轻功、基本内功、基本招架以及对应的已激发的特殊武功达到"+chinese_number(reset)+"级"ZJBR;
msg+="需要最低支撑肉身等级："+roushen[chinese_number(me->query("bodyreset")+1)]+NOR"\n";

msg += ZJOBACTS2+ZJMENUF(2,2,9,30);

	msg += "确定重修:bodyreset"ZJSEP;		
	msg += "肉身修炼:tupo explain\n";	
	
	message("vision", msg, me);	
	return 1;
}

zon = 200;

if (me->query("bodyreset")>=5)
return notify_fail("你已经不死不灭了！。\n");	  

if (me->query("blevel")<=me->query("bodyreset"))
return notify_fail("人体密藏还没开发到那个层次，何来肉身重修？\n");	       

sk = keys(me->query_skills());		  // 所学武功的名称集合

		if (me->query("gongxian") < 10000)
	    return notify_fail("贡献不足10000，强求亦是枉然。\n");
		if (me->query("dajif") < 1000)
	    return notify_fail("钻石不足1000，强求亦是枉然。\n");
	

 if (me->query("max_neili") < 10000)
	    return notify_fail("内力不足10000，强求亦是枉然。\n");	       
	    
	       if (me->query_skill("dodge",1)  < reset)
	       return notify_fail("基本轻功不足，强求亦是枉然。\n");
	       
	          if (me->query_skill("parry",1)  < reset)
	       return notify_fail("基本招架不足，强求亦是枉然。\n");
	       
	    if (me->query_skill("force",1)  < reset)
	       return notify_fail("基本内功不足，强求亦是枉然。\n");	
	  //     reset-=500;	      
	       	 if (me->query_skill("martial-cognize",1)  < zon+reset-500)
	       return notify_fail("武学修养不足，强求亦是枉然。\n");	    
	       
	       map_skill = me->query_skill_mapped("force");
        if (me->query_skill("force", 1) < reset ||me->query_skill(map_skill, 1) < reset)        
               return notify_fail("特殊内功不足，强求亦是枉然。\n");        
               
        map_skill = me->query_skill_mapped("dodge");
        if (me->query_skill("dodge", 1) < reset ||
            me->query_skill(map_skill, 1) < reset)
                        return notify_fail("特殊轻功不足，强求亦是枉然。\n");         
                                       
        map_skill = me->query_skill_mapped("parry");
        if (me->query_skill("parry", 1) < reset || me->query_skill(map_skill, 1) < reset)  
                              return notify_fail("特殊轻功不足，强求亦是枉然。\n");                           	       	 	       	       
foreach (map_skill in sk)
	me->delete_skill(map_skill);

me->delete("family");
me->set("combat_exp",300000);
me->delete("gift/xisuidan");
me->delete("gift/unknowdan");
me->delete("gift/shenliwan");
me->delete("gift/xiandan");
me->delete("potential");
me->delete("learned_points");
me->delete("max_neili");
me->delete("magic_learned");
me->delete("story");
me->delete("score");
me->delete("weiwang");
me->delete("magic_points");
me->add("dajif",-1000);
me->add("bodyreset",1);
me->set("max_qi",2000);
me->set("title", "转修之身");
	
/* 	new("/clone/bodyreset/xidian")->move(me);
	new("/clone/bodyreset/xinggedan")->move(me); */
	
message("channel:chat",HIW"肉身重修"HIR"："+me->query("name")+"肉身重修，肉身天赋变得更加高了\n"NOR,users());
write(HIR"你仿佛感到身体一阵轻松，肉身天赋变得更高，由于你需要契合新的肉身，你震散了全身修为，修武资质变得更高一层，身体杂质也在不断排出。\n");
  
	return 1;
}


int dest_room(object me,object room)
{
if (environment(me)==room)
me->move("/d/city/kedian");
destruct(room);
}