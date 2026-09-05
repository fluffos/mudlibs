/*  <SecCrypt CPL V3R05>  */
 
//  by  snowcat  on  7/5/1997  
inherit  NPC;

int  random2  (int  i)
{
    //return  (random(i)+uptime())  %  i;
	return i;
}

void  create()
{
    set_name("斗鸡",  ({  "dou ji",  "ji"  })  );
    set("race",  "野兽");
    set("gender",  "雄性");
    set("age",  10);
    set("long",  "一只雄赳赳的斗鸡。\n");
    set("attitude",  "friendly");
    set("eff_qi",200);
    set("str",  10);
    set("spi",  10);
    set("cor",  10);
    set("con",  10);
    set("cor",  10);
    set("cps",  10);
    set("dex",  10);
    set_skill("unarmed",  10);
    set_skill("dodge",  10);
    set_skill("parry",  10);
    set("limbs",  ({  "头部",  "身体",  "尾巴"  })  );
    set("verbs",  ({  "bite"})  );

    setup();

	set("keep_heart_beat",1);
}

void heart_beat()
{
	if(query("qi") < 50 || query("eff_qi") < 50)
	{
		die();
	}
	else
	{
		::heart_beat();
	}
}
