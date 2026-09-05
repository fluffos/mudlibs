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
                set_name(YEL"朴刀"NOR, ({ "zhutie jian", "blade", "jian" }) );
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
                set_name(HIY"八卦刀"NOR, ({ "qingtong blade", "blade", "jian" }) );
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
                set_name(HIB"绿波香露刀"NOR, ({ "jinggang blade", "blade", "jian" }) );
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
                set_name(WHT"银弧刀"NOR, ({ "baoren blade", "blade", "jian" }) );
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
                set_name(GRN"缅刀"NOR, ({ "yu xiao", "blade", "jian", "xiao" }) );
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
                set_name(HIW"冷月宝刀"NOR, ({ "kuanren blade", "blade", "jian" }) );
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
                set_name(MAG"紫金八卦刀"NOR, ({ "two-handed blade", "blade", "jian" }) );
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
                set_name(HIG"七星宝刀"NOR, ({ "xuantie blade", "blade", "jian" }) );
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
