// 称号demo by 潇湘夜雨(baiyi666/lude)
#pragma optimize
#pragma save_binary

#include <ansi.h>
//可加成基本属性值
mapping titles = ([
"无上剑仙":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_poison":5,"obtain":"无上剑经达到600级！"]),
"六道剑仙":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_magic":5,"obtain":"六道仙经达到600级！"]),
"无垠剑仙":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_metal":5,"obtain":"无垠剑经达到600级！"]),
"太元帝尊":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"reduce_wood":5,"obtain":"太元帝经达到600级！"]),
"太始帝尊":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"reduce_water":5,"obtain":"太始帝经达到600级！"]),
"太衍帝尊":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_fire":5,"obtain":"太衍帝经达到600级！"]),
"斗战胜佛":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"add_earth":5,"obtain":"斗战圣经达到600级！"]),
"上古圣君":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"jing_recover":5,"obtain":"上古秘法达到600级！"]),
"阴阳道君":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"qi_recover":5,"obtain":"阴阳道经达到600级！"]),
"归真道君":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"neili_recover":5,"obtain":"归真道经达到600级！"]),
"开天仙王":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"through_armor":5,"obtain":"开天仙经达到600级！"]),
"炼狱魔君":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"qi_abs_neili":5,"obtain":"炼狱魔经达到600级！"]),
"圣斗龙王":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"double_damage":5,"obtain":"龙王圣经达到600级！"]),
"寒冰法王":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"leech_neili":5,"obtain":"冰之圣典达到600级！"]),
"火焰法王":(["str":25,"int":25,"con":25,"dex":25,"max_jing":1000,"max_jingli":1000,"max_qi":1000,"max_neili":1000,"yanjiux":5,"baoji":5,"baojixg":5,"leech_qi":5,"obtain":"火之圣典达到600级！"]),
]);
//转换为中文名称
mapping chinesename=([
"str":"后天臂力",
"int":"后天悟性",
"con":"后天根骨",
"age":"年龄",
"dex":"后天身法",
"max_jing":"精神上限",
"max_jingli":"精力上限",
"max_qi":"气血上限",
"max_neili":"内力上限",
"yanjiux":"研究效率",
"yanjiuc":"研究次数",
"baoji":"暴击概率",
"baojixg":"暴击效果",
"xixue":"吸血概率",
"leech_qi":"生命偷取",
"leech_neili":"内力偷取",
"leech_jing":"精神偷取",
"double_damage":"双倍伤害",
"qi_abs_neili":"伤转内力",
"through_armor":"穿透破甲",
"neili_recover":"内力恢复",
"qi_recover":"生命恢复",
"jing_recover":"精气恢复",
"add_poison":"毒之伤害",
"add_magic":"魔之伤害",
"add_metal":"金之伤害",
"add_wood":"木之伤害",
"add_water":"水之伤害",
"add_fire":"火之伤害",
"add_earth":"土之伤害",
"reduce_poison":"毒伤抗性",
"reduce_magic":"魔伤抗性",
"reduce_metal":"金伤抗性",
"reduce_wood":"木伤抗性",
"reduce_water":"水伤抗性",
"reduce_fire":"火伤抗性",
"reduce_earth":"土伤抗性",
"avoid_poison":"忽视中毒",
"reputation":"声望",
"sm":"称号说明",
"bodyreset":"重修次数",
"blevel":"肉身等级",
"per":"容貌",
"zjvip/level":"vip等级",
"yuanbao":"灵石",
"combat_exp":"修为",
"potential":"潜能",
"qiangdaotask":"衙门贡献",
"gender":"性别",
"combat/MKS":"杀人数",
"combat/dietimes":"死亡次数",
"obtain":"获取方式"NOR,
]);

//需要达标的属性值
mapping need_attribute=([
"侠行天下":(["bodyreset":5]),
"盖世齐天":(["str":100,"con":100,"int":100,"dex":100]),
"琉璃金身":(["blevel":5]),
"杀神":(["combat/MKS":1000000]),
"倾城倾国":(["per":50,"gender":"女性"]),
"陌上君子":(["per":50,"gender":"男性"]),
"奢华贵族":(["zjvip/level":5]),
"富可敌国":(["yuanbao":66666]),
"百岁老人":(["age":100]),
"地狱之客":(["combat/dietimes":100,"bodyreset":1]),
"为民除害":(["qiangdaotask":1000]),
]);

//需要达标的技能
mapping need_skill=([
"无上剑仙":(["wushang-jianjing":600]),
"六道剑仙":(["lunhui-sword":600]),
"无垠剑仙":(["wuyin-jianjing":600]),
"太元帝尊":(["wanmo-futi":600]),
"太始帝尊":(["yinyangjiuzhuanshierchongtian":600]),
"太衍帝尊":(["taiyan-dijing":600]),
"斗战胜佛":(["douzhan-shengjing":600]),
"上古圣君":(["shanggu-mijing":600]),
"阴阳道君":(["liangyi-yinyangjue":600]),
"归真道君":(["tianrenheyi":600]),
"开天仙王":(["badao":600]),
"炼狱魔经":(["lianyu-mojing":600]),
"圣斗龙王":(["longwang-shengjing":600]),
"寒冰法王":(["bingzhi-shengdian":600]),
"火焰法王":(["huozhi-shengdian":600]),
]);
void create() { seteuid(getuid()); }

int use_title(object me,string title)
{
mixed xg=titles[title];
string *att,at;
att=keys(xg);
me->delete("titlea");
   foreach (at in att)
   {
     if (intp(xg[at]))
     me->set("titlea/"+at,xg[at]);
  }
me->set("chenghao",title);
tell_object(me,"你佩戴了称号："HIC+title+NOR+"\n");
	return 1;
}


string query_title(object me,string title)
{
string msg,msgg;
mixed xg=titles[title];
    if (xg)
{
msg=chinesename["obtain"]+":"+xg["obtain"]+"\n";
msg+=HIC+NOR+ZJBR"================称号加成=================\n";

if (xg["sm"])
msg+=chinesename["sm"]+":\n"+xg["sm"]+"\n";
foreach (msgg in keys(xg))
if (intp(xg[msgg]))
msg+=HIY"("+chinesename[msgg]+")"NOR+HIW":"+xg[msgg]+NOR"\n";
if (xg=need_attribute[title])
{
msg+=HIC+NOR+ZJBR"——————————称号需求——————————————"+ZJBR;
foreach (msgg in keys(xg))
if (xg[msgg])
msg+=HIY"("+chinesename[msgg]+")"NOR+HIW":"+xg[msgg]+NOR"\n";
}
       }
else
msg="该称号无任何加成\n";
	return msg;
}

mapping alltitles()
{
return titles;
}
//购买称号处理
int buy_title(object me,string title)
{
string att,*allatt;
mapping attribute;
//先计算属性是否达标
         if (me->query("titles/"+title))
        {
         tell_object(me,"你已获得该称号。\n");
         return 1;
         }
         
    if (need_attribute[title])
   {
   		allatt=keys(need_attribute[title]);
		attribute=need_attribute[title];
        foreach (att in allatt)
         if (me->query(att) < attribute[att])
         {
         tell_object(me,"你的"+chinesename[att]+"未达标。\n");
         return 1;
         }
  
   }
//再计算技能是否达标
   if (need_skill[title])
   {
   allatt=keys(need_skill[title]);
attribute=need_skill[title];
       foreach (att in allatt)
         if (me->query_skill(att,1) < attribute[att])
         {
         tell_object(me,"你的"+to_chinese(att)+"低于"+chinese_number(attribute[att])+"级，未达标。\n");
         return 1;
         }
       
   }
 //最后计算声望是否足够
 attribute=titles[title];
           if (me->query("reputation")<attribute["reputation"])
        {
         tell_object(me,"你的声望不够。\n");
         return 1;
         }
 me->add("potential",attribute["reputation"]/10);
 if (attribute["reputation"])
 me->add("yuanbao",1000);
 me->add("reputation",-attribute["reputation"]);
 me->set("titles/"+title,1);
 if (titles[title]["sm"])
 message("channel:chat",HBYEL+"［"+title+"］"NOR"："+me->query("name")+"："+replace_string(titles[title]["sm"],"\n"," ")+"\n"NOR,users());
 tell_object(me,"恭喜你获得称号"+HIR+title+"\n"NOR);
 return 1;
}