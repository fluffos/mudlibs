inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>

string *skill = ({ 
	"longzhua-gong", "ruying-suixingtui", "yizhi-chan", "jingang-quan",
	"qianye-shou", "nianhua-zhi", "zhenshan-mianzhang", "jieshou-jiushi",
	"yiyang-zhi", "qishang-quan", "lanhua-shou", "poyu-quan",
	"xianglong-zhang", "huagu-mianzhang", "jiuyin-baiguzhua", "anran-zhang",
	}); 

string *force = ({
	"yijin-jing", "yijin-jing", "yijin-jing", "yijin-jing",
	"yijin-jing", "yijin-jing", "yinyun-ziqi", "linji-zhuang",
	"qiantian-yiyang", "shenghuo-shengong", "bihai-chaosheng","zixia-gong",
	"huntian-qigong", "dulong-dafa", "linji-zhuang", "yunu-xinjing",
	});

string *perform = ({
	"canyun", "ruying", "wofo", "fumo",
	"qianshou", "fuxue", "bingdi", "foguang",
	"sandie", "qishang", "fuxue", "leidong",
	"paiyun", "bujue", "jiuyin", "anran",
	});

string *base = ({
	"claw", "leg", "finger", "cuff",
	"hand", "finger", "strike", "hand",
	"finger", "cuff", "hand", "cuff",
	"strike", "strike", "claw", "strike",
	}); 

void create()
{
    set_name("一品堂 武士", ({ "wu shi", "wushi", "shi"}));

	set("init",0);
	
    set("gender", "男性");
    set("age", 20 + random(60));
    set("long", "这是西夏一品堂从江湖上重金招聘的一名武林高手。\n" );
	if( random(10) < 1 )
		set("double_attack",1);
}       

void init()
{
    object me=this_player(),ob=this_object();
	int lvl;
	string s_skill,s_force,s_perform,s_base;
	int index;
	object *lineup;
        
    ::init();

	if( query("init") == 0 )
	{
		if( userp(me) && me->query_temp("gb_job4") )
		{
			if(!me->query_lineup())
				lvl = me->query("max_pot");
			else
			{
				lineup = me->query_lineup();
				lvl = 0;
				for(index=0;index<sizeof(lineup);index++)
				{
					if( lineup[index]->query("max_pot") > lvl )
						lvl = lineup[index]->query("max_pot");
				}
				
			}
			
		}
		else
		{
			return;
		}
		
		lvl = lvl - 100;
		set("init", 1);

		index = random( sizeof( skill ) );

		s_skill = skill[ index ];
		s_force = force[ index ];
		s_perform = perform[ index ];
		s_base = base[ index ];
     
	    set("gender", "男性");
	    set("age", 20 + random(60));

	    set("combat_exp", lvl*lvl*lvl/10);
	    set("meitude", "peaceful");
	    set("str", 20 + random( 10 ) );
	    set("int", 20 + random( 10 ) );
	    set("con", 20 + random( 10 ) );
	    set("dex", 20 + random( 10 ) );
	    set("shen",0);
	    set("max_qi", 6000);
	    set("max_jing", 3000);
	    set("max_neili", 4000 + lvl * 20 );
	    set("eff_jingli",3000);
	    set("neili", 4000 + lvl * 20 );
	    set_skill(s_skill, lvl );
	    set_skill(s_force, lvl );
	    set_skill(s_base, lvl);
	    set_skill("dodge", lvl);
	    set_skill("force", lvl);
	    set_skill("parry", lvl);
	    set_skill("tiyunzong", lvl);

	    map_skill("force", s_force);
	    map_skill("dodge", "tiyunzong");
	    map_skill("parry", s_skill);
	    map_skill(s_base, s_skill);
	    prepare_skill(s_base, s_skill);
	
		set("chat_chance_combat", 20);
		set("chat_msg_combat", ({
			(: perform_action, s_base + "." + s_perform :)
		}) );

	    setup();
	    carry_object(ARMOR_D("cloth"))->wear();
    }
    
        
    if( me->query_temp("gb_job4") || me->query_lineup() )
    {
    	ob->kill_ob(me);
    }
}
