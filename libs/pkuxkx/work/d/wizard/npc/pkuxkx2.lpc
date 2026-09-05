//inherit F_DBASE;
//加入family score 清0 by yhzzyahoo
inherit F_CLEAN_UP;
inherit F_SAVE;

inherit NPC;

#include <ansi.h>
#include <localtime.h>
nosave int inclear=0;

void destme();
void himsg();
void himsg();
void start_clear();
void checkstarttime1();
void create()
{
        set_name(HIW"北侠报时机器人"NOR, ({"pkuxkx TIMER","timer"}));
        set("gender", "男性" );
        set("age", 13);
        set("env/invisibility",1);
        set("long", "一个可爱的小童，每天负责在这里给玩家报时。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_qi", 1500000);
        set("qi",1500000);
        set("jing",1500000);
        set("max_jing", 1500000);
        set("shen_type",1);set("score",0);setup();
		call_out("checkstarttime1",60);
        himsg();
}
void himsg()
{
       remove_call_out("himsg1");
       call_out("himsg1",1);
       return; 
}
void himsg1()
{
	if (environment(this_object()))
	{
       CHANNEL_D->do_channel(this_object(), "jh", HBBLU+HIY+"江湖又暂时恢复了表面的宁静..."+NOR, -1);
       remove_call_out("destme");
       call_out("destme",779);
    }
       return; 
}

void destme()
{
  if (!objectp(this_object()))
  	return;
	if (environment(this_object()))
	{
		CHANNEL_D->do_channel(this_object(), "jh", HBBLU+HIY+"还有不到一炷香的功夫，血雨腥风的日子就要告一段落了..."+NOR, -1);
		destruct(this_object());
	}
	return;
}

void start_clear()
{
	string* fams;
	int i;
	if (inclear)
	{
		return;
	}
	inclear=1;
	fams = FAMILY_D->get_repute_top(20);
    CHANNEL_D->do_channel(this_object(), "rw", HIY + "门派推广重新开始，正在重新分配门派威望值。\n"NOR, -1);
	for(i=0;i<sizeof(fams);i++)
	{
	//	CHANNEL_D->do_channel(this_object(), "rw","第"+chinese_number(i+1)+"名:"+fams[i]+":"+FAMILY_D->get_repute(fams[i])+"\n"NOR,-1);
		if (i<3 || i>16)
		{
			FAMILY_D->set_repute(fams[i],1+random(5));
		}
		else
		{
			FAMILY_D->set_repute(fams[i],0);
		}

	}
	save();
    CHANNEL_D->do_channel(this_object(), "rw", HIY + "门派威望值分配完毕。\n"NOR, -1);

	return;
}

void checkstarttime1()
{
	mixed* timeinfos;
	int hour;
	int minute;
	int mday;

	timeinfos = localtime(time());

	hour = timeinfos[LT_HOUR];
	minute = timeinfos[LT_MIN];
	mday = timeinfos[LT_MDAY];
//	CHANNEL_D->do_channel(this_object(), "rw", HIY + "测试family score1。\n"NOR, -1);
	if(mday==1 && hour==5 && minute >= 1 && minute <= 3)
		{
			remove_call_out("checkstarttime1");
			start_clear();
			return;
		}
	else
		{
		/*test使用
		FAMILY_D->set_repute("quanzhen",1+random(35));
		FAMILY_D->set_repute("wudang",1+random(35));
		FAMILY_D->set_repute("shaolin",1+random(25));
		FAMILY_D->set_repute("mingjiao",1+random(25));
		FAMILY_D->set_repute("gaibang",1+random(25));
		FAMILY_D->set_repute("murong",1+random(25));
		FAMILY_D->set_repute("chaoting",1+random(25));		
		FAMILY_D->set_repute("baituo",1+random(25));
		FAMILY_D->set_repute("dalunsi",1+random(25));
		FAMILY_D->set_repute("tianlong",1+random(25));
		FAMILY_D->set_repute("shenlongjiao",1+random(25));
		FAMILY_D->set_repute("emei",1+random(25));
		FAMILY_D->set_repute("xingxiu",1+random(25));
		FAMILY_D->set_repute("lingjiu",1+random(25));
		FAMILY_D->set_repute("riyueshenjiao",1+random(25));
		FAMILY_D->set_repute("huashan",1+random(35));
		FAMILY_D->set_repute("gumu",1+random(35));
		FAMILY_D->set_repute("taohua",1+random(35));
		FAMILY_D->set_repute("tiandihui",1+random(35));
		FAMILY_D->set_repute("lingxiao",1+random(35));
		*/
		inclear=0;
		remove_call_out("checkstarttime1");
		call_out("checkstarttime1",60);
		}

}
