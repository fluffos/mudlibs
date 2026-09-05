// by Vast@pkuxkx
// Modified by whuan@pkuxkx 
// all comments added by Vast

#include <ansi.h>
#include <armor.h>

inherit EQUIP;

void setup_armor(); 
int get_grade(int min, int max); //计算盔甲类型的函数
varargs void gen_armor(int type, int min, int max);
void init_sockets();

nosave string *all_colors = ({NOR, RED, BLU, GRN, YEL, CYN, MAG, HIW});
nosave string *all_grades = ({"恶来","玄狐","洛神","盘瓠","儵忽","帝江","烛阴","盘古"});
nosave string *all_types =({"戒指", "项链"});
nosave string *all_ids=({"ring","necklace"});

void create()
{
        int type;
                set("no_get", 1);
                set("no_drop", "这东西不能扔。\n");
                set("no_steal", 1);
                set("value",1000000);
                set("owner", "skywolf");
                set("auto_load", 1);
        //随机共2种饰品
        type=random(2)+1;
        set("type",type);
        gen_armor(type);
        setup();
}

int get_grade(int min, int max)
{
        int i, grade;

        grade = 8;  //(3%)
        return grade;   
}

varargs void gen_armor(int type, int min, int max) //type为盔甲类型
{
        int grade;
        string id;
        string name;
        if(!min) min = 0;         
        if(!max) max = 10000;     
                                  
        if (min > max)   return;  
        if (min < 0)     return;    
        if (max > 10000) return;
        
        grade=get_grade(min,max);
        if (grade<1 || grade > 8) grade=1;
        
        name=HIW+BNK+"渡月的结婚戒指"+NOR;
        id="skywolf's marriage ring";
        set_name(name, ({id,"ring"}) );
        
        set("base_weight", 500 + random(100));
//        set("armor/long", "华丽的全身铠甲，极高的防御，完美之极。\n");
        set("material", "gold");
        set("rigidity", 250+random(grade*15));
        set("value",10000+random(20000+grade*10000));
        set("armor/min_def", 10+random(10*grade));
        set("armor/max_def", 30+random(30*grade));

        delete("armor_prop/armor");
        init_sockets();
}

void init_sockets()
{
        int i, max;
        //1，2，3孔出现的几率为888:111:1
        if(!query("sockets/max"))
        {
                max = 2;
                set("sockets/max", max);
        }
        //暂时不做复杂的分类，armor_type只设定盔甲(armor)一种
        //以后根据情况可增加 鞋(boots),帽子(head),衣物(cloth),手套(hands),外套(surcoat),腰带(waist),护腕(wrist)

        if (query("type")==1)        set("armor_type", "finger");
        else                         set("armor_type", "finger");
        //set_armor_desc();
        
        setup_armor();
        set("owner","skywolf");
                set("armor_prop/armor", 200);
        
}

void setup_armor()
{
        int hole, i;
        string longdes;
        object ob = this_object();

        //基本信息
        if(stringp(ob->query("armor/name")))
        set_name(ob->query("armor/name"), ob->parse_command_id_list());

        ob->set("unit", "枚");

        //set long_desc
        if (!stringp(ob->query("armor/long")))
        longdes = HIW"这是一枚做工精美的白金钻戒，美丽的花纹环绕着闪耀着炫目光泽的钻石，华贵之极。
钻戒内圈镌刻着一行小字：钻石恒久远，爱情永保鲜。祝渡月新婚快乐！ ---icer敬赠\n"NOR;
        else
        longdes = ob->query("armor/long");


        set("long", longdes);

        //材料
        if (!ob->query("material")) ob->set("material", "gold");

        //耐久度（armor暂未设置此值）
        //if (!ob->query("rigidity")) ob->set("rigidity", 300);
        //if (!ob->query("max_rigidity")) ob->set("max_rigidity", ob->query("rigidity"));

        //wear,unequip msg
        if (!stringp(ob->query("wear_msg")))
        set("wear_msg", "$N喜气洋洋地戴上一枚$n。\n");
        else
        set("wear_msg", ob->query("wear_msg"));

        set("unequip_msg", "$N将$n摘下，小心翼翼地收藏起来。\n");

}

void init()
{
        if (this_player()->query("id")!=query("owner"))
        {
                message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
                message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
                destruct(this_object());
                return;
        }
}

