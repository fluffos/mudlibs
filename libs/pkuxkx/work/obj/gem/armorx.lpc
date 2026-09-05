// by Vast@pkuxkx
// Modified by whuan@pkuxkx 
// all comments added by Vast

#include <ansi.h>
#include <armor.h>

inherit F_GEMS;
inherit EQUIP;

void setup_armor(); 
int get_grade(int min, int max); //计算盔甲类型的函数
varargs void gen_armor(int type, int min, int max);
void forge_capacity();

nosave string *all_colors = ({NOR, RED, BLU, GRN, YEL, CYN, MAG, HIW});
nosave string *all_grades = ({"机杼","苍野","青幽","百战","鬼烈","巨灵","深罡","九日"});
nosave string *all_types =({"铠甲", "靴", "袍", "手套", "盔", "盾", "披风", "腰带", "护腕"});
nosave string *all_ids=({"armor","boots","cloth","hands","head","shield","surcoat","waist","wrists"});

void create()
{
        int type;
        //只能在专门的地方进行买卖
        set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        //随机共9种盔甲
        type=random(9)+1;
        gen_armor(type,10000,10000);
        seteuid(ROOT_UID);
        setup();
}

int get_grade(int min, int max)
{
        int i, grade;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 2500)      grade = 1;    //(25%)
        else if (i < 4500) grade = 2;    //(20%)
        else if (i < 6100) grade = 3;    //(16%)
        else if (i < 7300) grade = 4;    //(12%)
        else if (i < 8500) grade = 5;    //(12%)
        else if (i < 9300) grade = 6;    //(8%)
        else if (i < 9700) grade = 7;    //(4%)
        else               grade = 8;    //(3%)
        return grade;	
}

varargs void gen_armor(int type, int min, int max) //type为盔甲类型
{
        int grade, min_def, max_def, def, weight = 1100 + random(700);
        string id;
        string name;
        if(!min) min = 0;         
        if(!max) max = 10000;     
                                  
        if (min > max)   return;  
        if (min < 0)     return;    
        if (max > 10000) return;
        
        set("type",type);
        grade=get_grade(min,max);
        if (grade<1 || grade > 8) grade=1;
        set("level",grade);
        
        name=all_colors[grade-1]+all_grades[grade-1]+"之"+all_types[type-1]+NOR;
        id=all_ids[type-1];
        set_name(name, ({id}) );
        set("base_weight", weight);
        set_weight(weight);
//        set("armor/long", "华丽的全身铠甲，极高的防御，完美之极。\n");
        set("material", "gold");
//        set("rigidity", 250+random(grade*15));
        set("value",10000+random(20000)+grade*10000);
        if(type>1)
        {
             min_def = 10+random(5*grade);
             max_def = 50+random(10*grade);
             def = min_def + random(max_def - min_def + 1);
             if (type==6)
             	def += 400;
             set("armor/min_def", min_def);
             set("armor/max_def", max_def);
             set("armor/armor",def);
             set("armor_prop/armor",def);
        }
        else
        {
        	   min_def = 200+random(5*grade);
             max_def = 250+random(40*grade);
             def = min_def + random(max_def - min_def + 1);
             set("armor/min_def", min_def);
             set("armor/max_def", max_def);
             set("armor/armor",def);
             set("armor_prop/armor",def);       	 
        }
        set("forge/times_max",1);//可锻造次数靠后天任务增加
        set("generation",2);
        forge_capacity();
}

void forge_capacity()
{
        int i, max;
        //1，2，3, 4孔出现的几率为8888:1100:11:1
        if(!query("forge/max"))
        {
                i = random(10000);

                if (i < 8888)
                max = 1;
                else if (i < 9988)
                max = 2;
                else if (i<9999)
                max = 3;
                else
                max = 4;
                set("forge/max", max);
        }
        //暂时不做复杂的分类，armor_type只设定盔甲(armor)一种
        //以后根据情况可增加 鞋(boots),帽子(head),衣物(cloth),手套(hands),外套(surcoat),腰带(waist),护腕(wrist)

        if (query("type")==1)        set("armor_type", "armor");
        else if (query("type")==2)   set("armor_type", "boots");
        else if (query("type")==3)   set("armor_type", "cloth");
        else if (query("type")==4)   set("armor_type", "hands");
        else if (query("type")==5)   set("armor_type", "head");
        else if (query("type")==6)   set("armor_type", "shield");
        else if (query("type")==7)   set("armor_type", "surcoat");
        else if (query("type")==8)   set("armor_type", "waist");
        else                         set("armor_type", "wrists");
        //set_armor_desc();
        
        setup_armor();
}

void setup_armor()
{
        int hole, i;
        string longdes;
        object ob = this_object();

        //基本信息
        if(stringp(ob->query("armor/name")))
        set_name(ob->query("armor/name"), ob->parse_command_id_list());

        ob->set("unit", "件");

        //set long_desc
        if (!stringp(ob->query("armor/long")))
        longdes = "随机装备\n"+"★★★★★★"+ob->query("name")+"★★★★★★\n";
        else
        longdes = ob->query("armor/long");

        longdes += set_armor_desc(ob);

        set("long", longdes);

        //材料
        if (!ob->query("material")) ob->set("material", "iron");
        	
        ob->set_weight(ob->query("base_weight"));

        //耐久度（armor暂未设置此值）
        //if (!ob->query("rigidity")) ob->set("rigidity", 300);
        //if (!ob->query("max_rigidity")) ob->set("max_rigidity", ob->query("rigidity"));

        //wear,unequip msg
        if (!stringp(ob->query("wear_msg")))
        set("wear_msg", "$N穿上一件$n。\n");
        else
        set("wear_msg", ob->query("wear_msg"));

        if (!stringp(ob->query("unequip_msg")))
        set("unequip_msg", "$N将$n脱下。\n");
        else
        set("unequip_msg", ob->query("unequip_msg"));

}

string spec_effect(object ob, object me, int damage, string act)
{
        int i, magic, kar, ratio, def = 0;
        string msg = "";

        //成功率(可能设定简单了一点)
        magic = me->query_temp("apply/magic");
        kar = me->query_kar();
        if (kar > 40) kar = 40;
        if (random(100) + kar / 5 + kar * magic / 1000 < 90) return msg;

        switch (act) {
        case "poison":
                msg = HIG"$n的盔甲上淬有剧毒！只见一道绿气迅速延伸到$N的手臂！\n"NOR;
				F_POISON->poison_attack(me,ob,"chuanxin", "emerald_poison", ob->query_condition("emerald_poison") + query("armor_effect/poison"));
                if (!ob->is_killing(me->query("id"))) ob->kill_ob(me);
                break;
        case "rebound":
                ratio = query("armor_effect/rebound");
                if(ratio > 100) ratio = 100;
                damage = damage * ratio / 100;
                msg = RED"$N这一击就像撞在了一堵墙上，攻击竟尽数反弹了回来！\n"NOR;
                ob->receive_damage("qi", damage, me);
                ob->receive_wound("qi", random(damage), me);
                if (wizardp(me))
                        tell_object(me, sprintf("反震伤害力： %d\n", damage));
                break;
        }
        return msg;
}

mixed ob_hit(object ob, object me, int damage)
{
        int i;
        mapping effect;
        string act, msg = "";

        //随机出现一种效果
        //weapon_effect/jing,poison,suck
        effect = query("armor_effect");
        if (mapp(effect))
        {
                i = sizeof(effect);
                act = keys(effect)[random(i)];
                msg += spec_effect(ob, me, damage, act);
        }

        return msg;
}

