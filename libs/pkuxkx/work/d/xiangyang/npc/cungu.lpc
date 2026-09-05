#include <ansi.h>
string ask_diao();  
inherit NPC;
void create()
{
	set_name(GRN"村姑"NOR, ({
		"cun gu",      
		"cungu",
		"gu",
	}));
	set("long",
		"她是一个十八九岁的姑娘,贫苦的生活并没有减弱她动人的姿色.
由于刚才的一阵挣扎,她的衣服已经凌乱不堪,脸上绯红,娇喘吁吁,额上渗出滴滴汗珠.
.\n"
	);
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 18);
	set("shen_type",1);
	set("str", 13);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 300);
	set("max_jing", 100);
	set("combat_exp", 800);
	set_skill("dodge", 20);
	set_skill("parry", 20); 
        set_skill("cuff", 40);
         set("inquiry",([  
                  "白雕"  : (: ask_diao :),
                  "雕儿"  : (: ask_diao :),
          ]));

	setup();

}
string ask_diao()
{       object me;
        me=this_player();
        me->set_temp("上峰", 1);  
        return "从这一直往西有座" +GRN"雪峰"NOR +",你只要按我说方法,就能上去,\n大雕很利害的,你要小心.";
}

       



