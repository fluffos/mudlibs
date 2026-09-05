// standard s_weapon object
// by Vast@pkuxkx
// all comments added by Vast

inherit S_WEAPON;

#include <ansi.h>
void gen_weapon(int seed);
varargs void gen_sword(int min, int max);
varargs void gen_blade(int min, int max);
varargs void gen_axe(int min, int max);
varargs void gen_staff(int min, int max);
varargs void gen_club(int min, int max);
varargs void gen_spear(int min, int max);
varargs void gen_halberd(int min, int max);
varargs void gen_hammer(int min, int max);
varargs void gen_whip(int min, int max);
varargs void gen_throwing(int min, int max);

void create()
{
	//只能在专门的地方进行买卖
	set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        gen_weapon(1+random(2));
        setup();
}
void gen_weapon(int seed)//axe,blade,sword,halberd,spear,staff,whip,club,hammer,....throwing
{
	int i;
	if(!seed) i = 1 + random(10);
	else
	{
		if(seed < 1 || seed > 10) return;
		i = seed;
	}
	switch(i)
	{
		case 1:
		set("skill_type", "sword");
		gen_sword();
		break;
		case 2:
		set("skill_type", "blade");
		gen_blade();
		break;
		case 3:
		set("skill_type", "axe");
		gen_axe();
		break;
		case 4:
		set("skill_type", "spear");
		gen_spear();
		break;
		case 5:
		set("skill_type", "staff");
		gen_staff();
		break;
		case 6:
		set("skill_type", "whip");
		gen_whip();
		break;
		case 7:
		set("skill_type", "hammer");
		gen_hammer();
		break;
		case 8:
		set("skill_type", "halberd");
		gen_halberd();
		break;
		case 9:
		set("skill_type", "club");
		gen_club();
		break;
		case 10:
		set("skill_type", "throwing");
		gen_throwing();
		break;
	}
//先确定武器基本种类、属性，再生成武器的gem类公有属性
}
varargs void gen_sword(int min, int max)
{
        //剑的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 1900) type = 1;         //(19%)
        else if (i < 3600) type = 2;    //(17%)
        else if (i < 5100) type = 3;    //(15%)
        else if (i < 6500) type = 4;    //(14%)
        else if (i < 7700) type = 5;    //(12%)
        else if (i < 8700) type = 6;    //(10%)
        else if (i < 9500) type = 7;    //双手剑(8%)
        else if (i < 9900) type = 8;    //玄铁剑(4%)
        else type = 9;  //冰剑(1%)

        switch(type)
        {
                case 1:
                set_name(YEL"铁剑"NOR, ({ "tie jian", "sword", "jian" }) );
                set("base_weight", 1000 + random(1500));
                set("weapon/long", "铁铸长剑，无刃无锋，为习武之人练习之用。鲜有人作为兵刃使用。\n");
                set("material", "iron");
                set("rigidity", 50 + random(100));
                set("value", 30000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 75);
                break;
                case 2:
                set_name(HIY"青钢剑"NOR, ({ "qinggang jian", "sword", "jian" }) );
                set("base_weight", 2500 + random(1500));
                set("weapon/long", "很普通的剑，是一般武人行走江湖的防身之物。\n");
                set("material", "copper");
                set("rigidity", 80 + random(100));
                set("value", 45000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 45);
                set("weapon/max_dam", 65);
                break;
                case 3:
                set_name(HIC"龙泉剑"NOR, ({ "longquan jian", "sword", "jian" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "以过碳生钢精炼的长剑，剑身有一龙形，龙首指向剑柄。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 50000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 50);
                set("weapon/max_dam", 85);
                break;
                case 4:
                set_name(WHT"紫薇软剑"NOR, ({ "ziwei ruanjian", "sword", "jian" }) );
                set("base_weight", 500 + random(1500));
                set("weapon/long", "百炼成精，剑身柔软，可卷缠，非高手不宜使用。\n");
                set("material", "steel");
                set("rigidity", 20 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 40);
                set("weapon/max_dam", 120);
                break;
                case 5:
                set_name(RED"赤焰剑"NOR, ({ "chiyan jian", "sword", "jian", "xiao" }) );
                set("base_weight", 500 + random(1000));
                set("weapon/long", "剑身赤红如血，满布精细密叠之火焰状锻纹，仿佛正散发出热浪阵阵。\n");
                set("material", "jade");
                set("rigidity", 50 + random(200));
                set("value", 70000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 70);
                set("weapon/max_dam", 110);
                break;
                case 6:
                set_name(HIW"松纹古剑"NOR, ({ "songwen gujian", "sword", "jian" }) );
                set("base_weight", 1200 + random(1800));
                set("weapon/long", "剑中王者，剑柄神兽盘踞，剑身隐现松纹，样式古拙。\n");
                set("material", "steel");
                set("rigidity", 250 + random(100));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 80);
                set("weapon/max_dam", 130);
                break;
                case 7:
                set_name(HIC"龙象巨剑"NOR, ({ "longxiang jujian", "sword", "jian" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "剑身宽阔，两面分别精雕龙纹象纹，剑脊加厚，约比一般宝剑长六成。因过于沉重需双手持用，虽不太灵便,但威力比单手剑高很多。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                set("wield_msg", "$N从身后抽出一把$n，双手紧紧握住。\n");
                set("unwield_msg", "$N慢慢把$n插入背后的剑鞘。\n");
                set("weapon/min_dam", 150);
                set("weapon/max_dam", 280);
                break;
                case 8:
                set_name(MAG"胜邪剑"NOR, ({ "shengxie jian", "sword", "jian" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "昔名铸造师欧冶子打造的五剑之首，华而不耀，实而不浮。无坚不摧，堪称神兵。\n");
                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
                case 9:
                //冰剑
                break;
        }
        delete("weapon_prop/damage");
        init_sockets();
}
varargs void gen_blade(int min, int max)
{
        //剑的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 1900) type = 1;         //(19%)
        else if (i < 3600) type = 2;    //(17%)
        else if (i < 5100) type = 3;    //(15%)
        else if (i < 6500) type = 4;    //(14%)
        else if (i < 7700) type = 5;    //(12%)
        else if (i < 8700) type = 6;    //(10%)
        else if (i < 9500) type = 7;    //双手剑(8%)
//        else if (i < 9900) type = 8;    //玄铁剑(4%)
        else type = 8;  //冰剑(1%)

        switch(type)
        {
                case 1:
                set_name(YEL"朴刀"NOR, ({ "pu dao", "blade", "dao" }) );
                set("base_weight", 1000 + random(1500));
                set("weapon/long", "一种木柄上安有长而宽的钢刃的兵器，刀身部分占的比例比较大。\n");
                set("material", "iron");
                set("rigidity", 50 + random(100));
                set("value", 30000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 75);
                break;
                case 2:
                set_name(HIY"八卦刀"NOR, ({ "bagua dao", "blade", "dao" }) );
                set("base_weight", 2500 + random(1500));
                set("weapon/long", "刀柄刻有八卦图案,且柄为圆柱状角形单刀。在各种翻刀、转刃的动作上非常的方便。\n");
                set("material", "copper");
                set("rigidity", 80 + random(100));
                set("value", 45000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 45);
                set("weapon/max_dam", 65);
                break;
                case 3:
                set_name(HIB"绿波香露刀"NOR, ({ "lvboxianglu dao", "blade", "dao" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "刀上喂毒的臭刀，偏以香为名。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 50000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 50);
                set("weapon/max_dam", 85);
                break;
                case 4:
                set_name(HIW"银弧刀"NOR, ({ "yinhu dao", "blade", "dao" }) );
                set("base_weight", 500 + random(1500));
                set("weapon/long", "以银材制成的弯刀,刀身呈弧月壮,刀体轻灵,使用方便。\n");
                set("material", "steel");
                set("rigidity", 20 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 40);
                set("weapon/max_dam", 120);
                break;
                case 5:
                set_name(WHT"缅刀"NOR, ({ "mian dao", "blade", "dao" }) );
                set("base_weight", 500 + random(1000));
                set("weapon/long", "刀身软，可曲藏于外衣之下，刀身吸血无数，隐隐生出红光。\n");
                set("material", "jade");
                set("rigidity", 50 + random(200));
                set("value", 70000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 70);
                set("weapon/max_dam", 110);
                break;
                case 6:
                set_name(HIC"冷月宝刀"NOR, ({ "lengyue baodao", "blade", "dao" }) );
                set("base_weight", 1200 + random(1800));
                set("weapon/long", "精钢锻造的单刀，刀柄上用金丝银丝镶著一个眉毛月之形。\n");
                set("material", "steel");
                set("rigidity", 250 + random(100));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 80);
                set("weapon/max_dam", 130);
                break;
                case 7:
                set_name(MAG"紫金八卦刀"NOR, ({ "zijinbagua dao", "blade", "dao" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "以深色金属锻造而成的八卦刀，较一般的八卦刀为之沉重，且锋利。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 150);
                set("weapon/max_dam", 280);
                break;
                case 8:
                set_name(HIY"七星宝刀"NOR, ({ "qixing baodao", "blade", "dao" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "锐利无匹的宝刃，鞘上镶嵌了七颗价值连城的宝石。\n");
                set("material", "heavysteel");
                set("rigidity", 10000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
                case 9:
                //冰剑
                break;
        }
        delete("weapon_prop/damage");
        init_sockets();
}
varargs void gen_spear(int min, int max){}
varargs void gen_halberd(int min, int max){}
varargs void gen_hammer(int min, int max){}
varargs void gen_whip(int min, int max){}
varargs void gen_throwing(int min, int max){}
