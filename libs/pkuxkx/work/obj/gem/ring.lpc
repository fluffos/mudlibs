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
nosave string *all_grades = ({"恶来","玄狐","洛神","盘瓠","儵忽","帝江","烛阴","盘古"});
nosave string *all_types =({"戒指", "项链"});
nosave string *all_ids=({"ring","necklace"});

void create()
{
        int type;
        //只能在专门的地方进行买卖
        set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);
        //随机共2种饰品
        type=random(2)+1;
        set("type",type);
        gen_armor(type);
        setup();
}

int get_grade(int min, int max)
{
        int i, grade;

        i = min + random(max - min);

        //此处还可做相应调整
        if (i < 2500)      grade = 1;         //(25%)
        else if (i < 4500) grade = 2;    //(20%)
        else if (i < 6100) grade = 3;    //(16%)
        else if (i < 7300) grade = 4;    //(12%)
        else if (i < 8500) grade = 5;    //(12%)
        else if (i < 9300) grade = 6;    //(8%)
        else if (i < 9700) grade = 7;    //(4%)
        else               grade = 8;  //(3%)
        return grade;	
}

varargs void gen_armor(int type, int min, int max) //type为盔甲类型
{
        int grade, min_def, max_def, def, weight = 600 + random(150);
        string id;
        string name;
        if(!min) min = 0;         
        if(!max) max = 10000;     
                                  
        if (min > max)   return;  
        if (min < 0)     return;    
        if (max > 10000) return;
        
        grade=get_grade(min,max);
        if (grade<1 || grade > 8) grade=1;
        set("level",grade);
        
        name=all_colors[grade-1]+all_grades[grade-1]+"之"+all_types[type-1]+NOR;
        id=all_ids[type-1];
        set_name(name, ({id}) );
        min_def = 10+random(2*grade);
        max_def = 30+random(3*grade);
        def = min_def + random(max_def - min_def + 1);
        set("base_weight", weight);
        set_weight(weight);
        set("material", "gold");
        set("rigidity", 250+random(grade*15));
        set("value",10000+random(20000+grade*10000));
        set("armor/min_def", min_def);
        set("armor/max_def", max_def);
        set("armor/armor",def);
        set("armor_prop/armor",def);
        set("forge/times_max",1);//可锻造次数靠后天任务增加
        set("generation",2);
        forge_capacity();
}

void forge_capacity()
{
        int i, max;
        //1，2孔出现的几率为999:1
        if(!query("forge/max"))
        {
                i = random(1000);

                if (i < 999)
                max = 1;
                else
                max = 2;
                set("forge/max", max);
        }
        //暂时不做复杂的分类，armor_type只设定盔甲(armor)一种
        //以后根据情况可增加 鞋(boots),帽子(head),衣物(cloth),手套(hands),外套(surcoat),腰带(waist),护腕(wrist)

        if (query("type")==1)        set("armor_type", "finger");
        else                         set("armor_type", "neck");
        
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

        longdes += set_ring_desc(ob);

        set("long", longdes);

        //材料
        if (!ob->query("material")) ob->set("material", "iron");

        //耐久度（armor暂未设置此值）
        //if (!ob->query("rigidity")) ob->set("rigidity", 300);
        //if (!ob->query("max_rigidity")) ob->set("max_rigidity", ob->query("rigidity"));

        //wear,unequip msg
        if (!stringp(ob->query("wear_msg")))
        set("wear_msg", "$N戴上一件$n。\n");
        else
        set("wear_msg", ob->query("wear_msg"));

        if (!stringp(ob->query("unequip_msg")))
        set("unequip_msg", "$N将$n脱下。\n");
        else
        set("unequip_msg", ob->query("unequip_msg"));

}
