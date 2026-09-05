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
varargs void gen_dagger(int min, int max);
varargs void gen_spear(int min, int max);
varargs void gen_halberd(int min, int max);
varargs void gen_hammer(int min, int max);
varargs void gen_whip(int min, int max);
varargs void gen_throwing(int min, int max);

void create()
{
        int i;
        //只能在专门的地方进行买卖
              set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        i=random(160);
        if (i<20)       gen_weapon(1); //sword
        else if (i<40)  gen_weapon(2); //blade
        else if (i<60)  gen_weapon(3); //staff
        else if (i<80)  gen_weapon(4); //whip
        else if (i<90)  gen_weapon(5); //axe
        else if (i<100) gen_weapon(6); //spear
        else if (i<110) gen_weapon(7); //hammer
        else if (i<120) gen_weapon(8); //halberd        
        else if (i<140) gen_weapon(9); //throwing       
        else            gen_weapon(10);//dagger
        setup();
}
void gen_weapon(int seed)//axe,blade,sword,halberd,spear,staff,whip,dagger,hammer,....throwing
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
                set("skill_type", "staff");
                gen_staff();
                break;
                case 4:
                set("skill_type", "whip");
                gen_whip();
                break;
                case 5:
                set("skill_type", "axe");
                gen_axe();
                break;
                case 6:
                set("skill_type", "spear");
                gen_spear();
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
                set("skill_type", "throwing");
                gen_throwing();
                break;
                case 10:
                set("skill_type", "dagger");
                gen_dagger();
                break;
        }
        set("seed",i); //icer added to clone the same weapon when player using this random weapon
        				// used in /task/npc/target
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
        else type = 8;                  //玄铁剑(4%)

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
                set_name(HIY"青钢剑"NOR, ({ "qinggang sword", "sword", "jian" }) );
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
                set_name(HIC"龙泉剑"NOR, ({ "longquan sword", "sword", "jian" }) );
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
                set_name(WHT"紫薇软剑"NOR, ({ "ziwei sword", "sword", "jian" }) );
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
                set_name(RED"赤焰剑"NOR, ({ "chiyan sword", "sword", "jian", "xiao" }) );
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
                set_name(HIW"松纹古剑"NOR, ({ "songwen sword", "sword", "jian" }) );
                set("base_weight", 1200 + random(1800));
                set("weapon/long", "剑中王者，剑柄神兽盘踞，剑身隐现松纹，样式古拙。\n");
                set("material", "steel");
                set("rigidity", 250 + random(100));
                set("two-hand", 1);
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 80);
                set("weapon/max_dam", 130);
                break;
                case 7:
                set_name(HIC"龙象巨剑"NOR, ({ "longxiang sword", "sword", "jian" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "剑身宽阔，两面分别精雕龙纹象纹，剑脊加厚，约比一般宝剑长六成。因过于沉重需双手持用，虽不太灵便,但威力比单手剑高很多。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                set("wield_msg", "$N从身后抽出一把$n，双手紧紧握住。\n");
                set("unwield_msg", "$N慢慢把$n插入背后的剑鞘。\n");
                set("weapon/min_dam", 150);
                set("weapon/max_dam", 280);
                set("two_hand",1);
                break;
                default:
                set_name(HIG"胜邪剑"NOR, ({ "shengxie sword", "sword", "jian" }) );
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
        }
        delete("weapon_prop/damage");
        init_sockets();
}
varargs void gen_blade(int min, int max)
{
        //刀的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 1900) type = 1;         //(19%)朴刀
        else if (i < 3600) type = 2;    //(17%)八卦刀
        else if (i < 5100) type = 3;    //(15%)绿波香露刀
        else if (i < 6500) type = 4;    //(14%)银弧刀
        else if (i < 7700) type = 5;    //(12%)缅刀
        else if (i < 8700) type = 6;    //(10%)冷月宝刀
        else if (i < 9500) type = 7;    //(8%)紫金八卦刀
        else type = 8;                  //(4%)七星宝刀

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
                set_name(HIY"八卦刀"NOR, ({ "bagua blade", "blade", "dao" }) );
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
                set_name(HIB"绿波香露刀"NOR, ({ "xianglu blade", "blade", "dao" }) );
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
                set_name(WHT"银弧刀"NOR, ({ "yinhu blade", "blade", "dao" }) );
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
                set_name(GRN"缅刀"NOR, ({ "mian dao", "blade", "jian", "dao" }) );
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
                set_name(HIW"冷月宝刀"NOR, ({ "lengyue blade", "blade", "dao" }) );
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
                set_name(MAG"紫金八卦刀"NOR, ({ "zijinbagua blade", "blade", "dao" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "以深色金属锻造而成的八卦刀，较一般的八卦刀为之沉重，且锋利。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 150);
                set("weapon/max_dam", 280);
                set("two_hand",1);
                break;
                default:
                set_name(HIG"七星宝刀"NOR, ({ "qixing blade", "blade", "dao" }) );
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
        }
        delete("weapon_prop/damage");
        init_sockets();
}
varargs void gen_whip(int min, int max)
{
        //鞭的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 1900) type = 1;         //(19%)朴刀
        else if (i < 3600) type = 2;    //(17%)八卦刀
        else if (i < 5100) type = 3;    //(15%)绿波香露刀
        else if (i < 6500) type = 4;    //(14%)银弧刀
        else if (i < 7700) type = 5;    //(12%)缅刀
        else if (i < 8700) type = 6;    //(10%)冷月宝刀
        else if (i < 9500) type = 7;    //(8%)紫金八卦刀
        else type = 8;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR"钢鞭"NOR, ({ "gang bian", "bian", "whip" }) );
                set("base_weight", 1000 + random(1500));
                set("weapon/long", "以精钢锻成一节节的鞭身，再以钢线、熟皮、锁子连接。\n");
                set("material", "iron");
                set("rigidity", 50 + random(100));
                set("value", 30000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 75);
                break;
                case 2:
                set_name(HIC"钢铸软鞭"NOR, ({ "gangzhu ruanbian", "bian", "whip" }) );
                set("base_weight", 2500 + random(1500));
                set("weapon/long", "精钢制成的软鞭,长二丈,末端附有握把,首端有垂重物以便于施用。\n");
                set("material", "copper");
                set("rigidity", 80 + random(100));
                set("value", 45000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 45);
                set("weapon/max_dam", 65);
                break;
                case 3:
                set_name(CYN"九节鞭"NOR, ({ "jiujian bian", "bian", "whip" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "以金属锻造的鞭节串以镔铁丝线制成的软鞭。远较一般的软鞭来得沉重，但较不灵活。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 50000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 50);
                set("weapon/max_dam", 85);
                break;
                case 4:
                set_name(BLU"蝎尾鞭"NOR, ({ "xiewei bian", "bian", "whip" }) );
                set("base_weight", 500 + random(1500));
                set("weapon/long", "赤铁打成的短鞭，质亦软硬鞭之间，鞭尾生锐刺，刺为倒生。\n");
                set("material", "steel");
                set("rigidity", 20 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 40);
                set("weapon/max_dam", 120);
                break;
                case 5:
                set_name(YEL"鳄尾鞭"NOR, ({ "ewei bian", "bian", "whip"}) );
                set("base_weight", 500 + random(1000));
                set("weapon/long", "以青铜、熟铁及皮革组合而成，制成鳄尾形状。除鳄类的打击方式外，更可以进行类似锯的攻击。\n");
                set("material", "jade");
                set("rigidity", 50 + random(200));
                set("value", 70000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 70);
                set("weapon/max_dam", 110);
                break;
                case 6:
                set_name(HIY"金丝软鞭"NOR, ({ "jinsi ruanbian", "bian", "whip" }) );
                set("base_weight", 1200 + random(1800));
                set("weapon/long", "以金属丝编成的软鞭，相当的沉重，没有一定的技巧便无法使得顺手，非常强韧，可用来格挡兵刃。\n");
                set("material", "steel");
                set("rigidity", 250 + random(100));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 80);
                set("weapon/max_dam", 130);
                break;
                case 7:
                set_name(HIY"金龙鞭"NOR, ({ "jinlong bian", "bian", "whip" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "以金属制成的软鞭,长二丈二,平时可缠于腰间,便于携带,表层以黄铜混金而成。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 130);
                break;
                default:
                set_name(HIB"毒龙鞭"NOR, ({ "dulong bian", "bian", "whip" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "以钢片编制而成的四丈长鞭,外层包以银皮,状若龙鳞,鞭首呈幼龙龙首之形,除增加打击力度外,更可喂毒。\n");
                set("material", "heavysteel");
                set("rigidity", 10000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_staff(int min, int max)
{
        //杖的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 3000) type = 1;         //(19%)朴刀
        else if (i < 6500) type = 2;    //(14%)银弧刀
        else if (i < 7700) type = 3;    //(12%)缅刀
        else if (i < 8700) type = 4;    //(10%)冷月宝刀
        else if (i < 9500) type = 5;    //(8%)紫金八卦刀
        else type = 6;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR"木杖"NOR, ({ "mu zhang", "zhang", "staff" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "这是用柞木做成的长杖。它发出奇怪的黑色光线，摸起来暖暖的。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 50000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 50);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(BLU"铁拐"NOR, ({ "tie guai", "guai", "staff" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "以生铁铸成的拐杖，极重，使来非常不顺手。\n");
                set("material", "steel");
                set("rigidity", 20 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 40);
                set("weapon/max_dam", 120);
                break;
                case 3:
                set_name(YEL"哭丧棒"NOR, ({ "kuangsang bang", "bang", "staff"}) );
                set("base_weight", 500 + random(1000));
                set("weapon/long", "以金属铸成的短杖，杖头结有以金属薄片打造的引灵绳。\n");
                set("material", "jade");
                set("rigidity", 50 + random(200));
                set("value", 70000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 70);
                set("weapon/max_dam", 110);
                break;
                case 4:
                set_name(HIY"龙头拐"NOR, ({ "longtou guai", "guai", "staff" }) );
                set("base_weight", 1200 + random(1800));
                set("weapon/long", "钢制长杖，相当的沉重，杖头雕有盘型飞龙，龙型灵动，仿如活物。\n");
                set("material", "steel");
                set("rigidity", 250 + random(100));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 80);
                set("weapon/max_dam", 130);
                break;
                case 5:
                set_name(HIY"金蛇杖"NOR, ({ "jinshe zhang", "zhang", "staff" }) );
                set("base_weight", 2000 + random(4000));
                set("weapon/long", "精钢打造的长杖，杖头雕若蛇状，结有八个金铃。\n");
                set("material", "steel");
                set("rigidity", 500 + random(500));
                set("value", 150000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 130);
                break;
                default:
                set_name(HIB"寒冰宝杖"NOR, ({ "hanbing baozhang", "zhang", "staff" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "这把宝杖的杖头是以坚不可摧的冰蓝水晶所锻造。它的握柄触手生寒，持有者会被平静的寒气圣光环绕。\n");
                set("material", "heavysteel");
                set("rigidity", 10000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_axe(int min, int max)
{
        //axe的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 6000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR"钢斧"NOR, ({ "gang fu", "fu", "axe" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "这是一柄普通的铁斧，不过磨的闪亮闪亮的，看起来还象把利器。\n");
                set("material", "steel");
                set("rigidity", 500 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(HIW"宣花斧"NOR, ({ "xuanhua fu", "fu", "axe" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "这是把沉重的大斧，有八尺多长，锋利无比\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 120);
                break;
                default:
                set_name(HIB"盘古斧"NOR, ({ "pangu fu", "fu", "axe" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "传说天地混沌之初，盘古由睡梦醒来，见天地晦暗，于是拿一把巨大的斧子劈开天地，自此才有我们的世界。 \n此斧拥有分天地、穿梭太虚之力。\n");
                set("material", "heavysteel");
                set("rigidity", 10000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_spear(int min, int max)
{
        //spear的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 7000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR"钢枪"NOR, ({ "gang qiang", "qiang", "spear" }) );
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "这是一柄普通的钢枪，不过磨的闪亮闪亮的，看起来还象把利器。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(WHT"飞龙枪"NOR, ({ "feilong qiang", "qiang", "spear" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "枪身笔挺，光泽照人，隐见螺旋纹样，枪尖处锋利之极，钢质特佳。\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 120);
                break;
                default:
                set_name(HIR"惊夜枪"NOR, ({ "jingye qiang", "qiang", "spear" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "此枪乃是取自天外陨星之精华所铸而成。\n第十二代始祖有感于慧星坠落当晚的奇异天象，是以，他为此枪命名为惊夜神枪。\n后来，此枪为陶唐氏所得，一直存于陶唐氏之中。一百余年后，帝尧更凭借此枪威服南方三苗，成其不朽帝业。\n");
                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_halberd(int min, int max)
{
        //halberd的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 7000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(GRN "方天画戟" NOR, ({ "fangtian ji", "ji", "halberd"}));
                set("base_weight", 1500 + random(2000));
                set("weapon/long", "这是一杆方天画戟。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(HIM "金凤紫电戟" NOR, ({"jifengzidian ji", "ji", "halberd" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "此戟长约一丈二寸，重六十六斤。\n戟端造型优美，形如飞凤，外镀金粉，端庄华丽，戟身闪烁紫电星芒，挥舞之时有风鸣雷烁、紫电闪灼之威。\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 120);
                break;
                default:
                set_name(HIY "明月寒星戟" NOR, ({ "mingyuehanxing ji", "ji", "halberd" }) );
                set("base_weight", 5000 + random(5000));
                set("weapon/long", "此戟为三角形长援，戟刺反卷成钩状，援两面的中部均带有宽血槽。\n内中有一圆穿，犹如明月，戟身修长，寒铁所铸，尖端缀以宝石，折射日光月光，犹如寒星闪烁，惊人心魂。\n");
                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_hammer(int min, int max)
{
        //hammer的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 7000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR "钢锤" NOR, ({ "gang chui", "chui", "hammer"}));
                set("base_weight", 800 + random(2000));
                set("weapon/long", "这是一把钢锤。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(HIY "金瓜" NOR, ({"jin gua", "gua", "hammer" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "这是一把沉重的金瓜。\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 120);
                break;
                default:
                set_name(HIM"五行神锤" NOR, ({ "wuxing shenchui", "chui", "hammer" }) );
                set("base_weight", 1200 + random(5000));
                set("weapon/long", "此锤分为金、木、水、火、土五行。锤大如瓜，各有其形，上缚钢链，可御锤贯顶。\n");
                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_throwing(int min, int max)
{
        //throwing的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 7000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR "钢镖" NOR, ({ "gang biao", "biao", "dart"}));
                set("base_weight", 800 + random(2000));
                set("weapon/long", "这是一把钢锤。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(HIY "柳叶镖" NOR, ({"liuye biao", "biao", "dart" }) );
                set("base_weight", 800 + random(1500));
                set("weapon/long", "这是一把柳叶飞镖，从形态上看是专为女子设计的。\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 80);
                break;
                default:
                set_name(HIM"凤凰烈焰针" NOR, ({ "fenghuanglieyan zhen", "zhen" }) );
                set("base_weight", 1200 + random(5000));
                set("weapon/long", "针如凤焰,灿烂辉煌,故而得名,针细如毛,有剧毒,一发而不可收拾。\n");

                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}
varargs void gen_dagger(int min, int max)
{
        //dagger的基本类型 相当于diablo中的灰色物品
        int i, type;
        if(!min) min = 0;
        if(!max) max = 10000;

        if (min > max) return;
        if (min < 0) return;
        if (max > 10000) return;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 7000) type = 1;         //(19%)朴刀
        else if (i < 9500) type = 2;    //(8%)紫金八卦刀
        else type = 3;                  //(4%)七星宝刀

        switch(type)
        {
                case 1:
                set_name(NOR"铜匕首" NOR, ({ "tong bishou", "bishou", "bi"}));
                set("base_weight", 100 + random(1000));
                set("weapon/long", "这是一把钢匕首，看起来很陈旧。\n");
                set("material", "steel");
                set("rigidity", 150 + random(50));
                set("value", 20000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 30);
                set("weapon/max_dam", 85);
                break;
                case 2:
                set_name(HIC"精钢短剑" NOR, ({"duan jian", "duanjian", "jian" }) );
                set("base_weight", 200 + random(1000));
                set("weapon/long", "这是一柄剑身短小的精钢剑，一般的剑客都配带此剑。\n");
                set("material", "steel");
                set("rigidity", 220 + random(50));
                set("value", 80000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 60);
                set("weapon/max_dam", 80);
                break;
                default:
                set_name(HIM"徐夫人宝匕" NOR, ({ "xushi bi", "bi" }) );
                set("base_weight", 200 + random(1000));
                set("weapon/long", "此匕首乃赵国名匠徐夫人所铸，长八寸许，刃长五寸余，柄约四寸，刃窄长且轻，上有铬文：徐氏。\n");
                set("material", "heavysteel");
                set("rigidity", 1000);
                set("value", 120000);
                //set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                //set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon/min_dam", 100);
                set("weapon/max_dam", 150);
                break;
        }
        delete("weapon_prop/damage");
        init_sockets(); 
}

