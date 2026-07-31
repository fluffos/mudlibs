#include <ansi.h>
#include <combat.h>
string gettof(object me, object obj);
string tough_level(int power);
string *tough_level_desc = ({
"不堪一击","毫不足虑","不知所以","新学乍练","勉勉强强",
"初窥门径","初出茅庐","略知一二","普普通通","平平淡淡",
"平淡无奇","粗通皮毛","半生不熟","马马虎虎","略有小成",
"已有小成","渐入佳境","登堂入室","挥洒自如","融会贯通", 
"心领神会","炉火纯青","了然於胸","略有大成","已有大成",
"豁然贯通","出类拔萃","无可匹敌","技冠群雄","神乎其技",
"出神入化","非同凡响","傲视群雄","登峰造极","无与伦比",
"所向披靡","一代宗师","精深奥妙","神功盖世","举世无双",
"惊世骇俗","撼天动地","震古铄今","超凡入圣","威镇寰宇",
"空前绝后","天人合一","深藏不露","横扫江湖","深不可测",
"威不可挡","技惊四座","强绝天下","威镇武林","前无古人",
"返璞归真","独步天下","旷古绝伦","天下无敌","天下第一",
});
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	mapping prepare;
	int attack_points;
    if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];   
	    }
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    	return tough_level((int)(attack_points/300));
}
int main(object me,string arg)
{	string lev;
	string msg="\n\n"+
BLU"\t  不堪一击  "NOR+BLU"  毫不足虑  "NOR+BLU"  不知所以  "NOR+BLU"  新学乍练  "NOR+BLU"  勉勉强强  \n"NOR+
BLU"\t  初窥门径  "NOR+BLU"  初出茅庐  "NOR+BLU"  略知一二  "NOR+BLU"  普普通通  "NOR+BLU"  平平淡淡  \n"NOR+
HIB"\t  平淡无奇  "NOR+HIB"  粗通皮毛  "NOR+HIB"  半生不熟  "NOR+HIB"  马马虎虎  "NOR+HIB"  略有小成  \n"NOR+
HIB"\t  已有小成  "NOR+HIB"  渐入佳境  "NOR+HIB"  登堂入室  "NOR+HIB"  挥洒自如  "NOR+HIB"  融会贯通  \n"NOR+ 
CYN"\t  心领神会  "NOR+CYN"  炉火纯青  "NOR+CYN"  了然於胸  "NOR+CYN"  略有大成  "NOR+CYN"  已有大成  \n"NOR+
CYN"\t  豁然贯通  "NOR+CYN"  出类拔萃  "NOR+CYN"  无可匹敌  "NOR+CYN"  技冠群雄  "NOR+CYN"  神乎其技  \n"NOR+
HIC"\t  出神入化  "NOR+HIC"  非同凡响  "NOR+HIC"  傲视群雄  "NOR+HIC"  登峰造极  "NOR+HIC"  无与伦比  \n"NOR+
HIC"\t  所向披靡  "NOR+HIC"  一代宗师  "NOR+HIC"  精深奥妙  "NOR+HIC"  神功盖世  "NOR+HIC"  举世无双  \n"NOR+
HIR"\t  惊世骇俗  "NOR+HIR"  撼天动地  "NOR+HIR"  震古铄今  "NOR+HIR"  超凡入圣  "NOR+HIR"  威镇寰宇  \n"NOR+
HIR"\t  空前绝后  "NOR+HIR"  天人合一  "NOR+HIR"  深藏不露  "NOR+HIR"  横扫江湖  "NOR+HIR"  深不可测  \n"NOR+
HIY"\t  威不可挡  "NOR+HIY"  技惊四座  "NOR+HIY"  强绝天下  "NOR+HIY"  威镇武林  "NOR+HIY"  前无古人  \n"NOR+
HIY"\t  返璞归真  "NOR+HIY"  独步天下  "NOR+HIY"  旷古绝伦  "NOR+HIY"  天下无敌  "NOR+HIY"  天下第一  "NOR+"\n\n";
    

	if(!arg)
	{write(msg);
     return 1;
	}
	if (arg=="me")
	{lev=gettof(me,me);
     msg=replace_string(msg,lev,WHT+lev+NOR);
	 write(msg);
	 return 1;
	}
     return 0;


}













/*write(
BLU"\t\t不堪一击 毫不足虑 不知所以 新学乍练 勉勉强强\n"NOR+
BLU"\t\t初窥门径 初出茅庐 略知一二 普普通通 平平淡淡\n"NOR+
HIB"\t\t平淡无奇 粗通皮毛 半生不熟 马马虎虎 略有小成\n"NOR+
HIB"\t\t已有小成 渐入佳境 登堂入室 挥洒自如 融会贯通\n"NOR+ 
CYN"\t\t心领神会 炉火纯青 了然於胸 略有大成 已有大成\n"NOR+
CYN"\t\t豁然贯通 出类拔萃 无可匹敌 技冠群雄 神乎其技\n"NOR+
HIC"\t\t出神入化 非同凡响 傲视群雄 登峰造极 无与伦比\n"NOR+
HIC"\t\t所向披靡 一代宗师 精深奥妙 神功盖世 举世无双\n"NOR+
HIR"\t\t惊世骇俗 撼天动地 震古铄今 超凡入圣 威镇寰宇\n"NOR+
HIR"\t\t空前绝后 天人合一 深藏不露 横扫江湖 深不可测\n"NOR+
HIR"\t\t威不可挡 技惊四座 强绝天下 威镇武林 前无古人\n"NOR+          
HIY"\t\t返璞归真 独步天下 旷古绝伦 天下无敌 天下第一\n\n\n"NOR
);
	


	return 1;
}
*/