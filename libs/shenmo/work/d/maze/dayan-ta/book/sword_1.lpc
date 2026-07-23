#include <ansi.h> 
inherit COMBINED_ITEM;

int is_book(){return 1;}

void setup(){}

varargs string name(int v)
{
	mapping skill;
	string arg,str = ::name(v);
	if( !mapp(skill=query("skill"))
	 || sizeof(skill)<1 )
	 	return str;
	if( skill["max_skill"]<=150 )
		arg = YEL"入门"NOR;
	else if( skill["max_skill"]<=399 )
		arg = NOR"基础";
	else if( skill["max_skill"]<=500 )
		arg = HIB"下阶"NOR;
	else if( skill["max_skill"]<=799 )
		arg = HIY"中阶"NOR;
	else	arg = HIW"上阶"NOR;
	str = HIR"秘籍"HIY"【"HIC+str+NOR+arg+NOR HIY"】"NOR;
	return str;
}

void create()
{
        set_name("烈阳剑法", ({"jian book", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long","域外拜火教徒所学的西域剑法精要。\n");
                set("unit", "叠");
                set("base_unit","张");
        	set("material", "paper");
        	set("skill", ([
                        "name": "lieyang-jian",
                        "exp_required": 100,
                        "sen_cost": 50,
                        "difficulty": 50,
                        "max_skill": 50,
		]) );
        }
        setup();
        set_amount(1);
}

