//  guodalubook 人物传记
//  created by zine 28 Aug 2010
//  edited by zine 28 Aug 2010
inherit ITEM;
#include <ansi.h>

void init()
	{
		add_action("do_study", "kan");
	}

void create()
	{
        set_name(CYN"人物传记"NOR, ({ "guodalu's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIC"郭大路"NOR"生平的故事，你可以看看(kan)。\n");
				set("value", 42500);
            }
        setup();
	}

int do_study(string arg)
	{
        object me,ob;
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
        me = this_player();
        ob = this_object();
        if (me->query_temp("personalbook/read"))
        {
            tell_object(me,WHT"你已经开始读这本传记了，好好读完它吧。\n"NOR);
            return 1;
        }
        else
        {
            tell_object(me,color[random(sizeof(color))]+"你翻开了人物传记，并大声朗读。\n"NOR);
            tell_object(me,color[random(sizeof(color))]+"大路者，嵩山镜文湖蹦郭县人，癸未年六月十二日申时三刻生。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"性邋遢不羁，喜酒好文，不学无术，曾为乡里所患。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"少从师西岳君子剑，得三招半式，横行邻里，江湖诨号“猫少一足”。\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"廿岁偶遇剑神，习九剑名独孤，自以为世上鲜遇对手，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"后与三岁稚童鏖战数夜，未尝一胜，遂弃剑废武，\n"NOR);
		call_out("study4", 4, me);
		return 1;
	}

int study4(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"与哈希、老蹦之流终日混迹于酒肆青楼，放浪形骸，强扰妇人女子为乐。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"后有令狐虫虫、拓跋野、卓尔不群、小小雪等诸多后进或他投，或出师，\n"NOR);
		call_out("study5", 4, me);
		return 1;
	}
			
int study5(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"唯大路以末学微技独赖华山门墙，斗鸡走狗，贪花好色，纵酒欢淫，为西岳之羞。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"时言“少妇闻其绕路，深闺听之闭户。”\n"NOR);
		call_out("study6", 4, me);
		return 1;
	}

int study6(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"某日，于扬州街头见一少女，明眸皓齿不可方物，银心大动，诱之以诸般奇巧，终获一笑，容颜天籁，消冰融雪。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"路大惊，浑然坐忘，反顾生平种种，萎顿于街心三年不起。\n"NOR);
		call_out("study7", 4, me);
		return 1;
	}

int study7(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"时顽劣少年有玻璃、天命、紫菱等，无不以殴之为戏，待长成，更教其少子愈殴之，成扬州一景。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"秋草数黄，路惊而醒，垂垂老矣，\n"NOR);
        call_out("study8", 4, me);
		return 1;
	}

int study8(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"自言梦中过百又五十一载，品得生死往复，手刃八千八百八十六人，亦曾为他人所屠八十二次，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"所历种种奇诡、荒谬之能事，无法尽述，扬州人或以为癫，引作笑谈。\n"NOR);
		call_out("study9", 4, me);
		return 1;
	}		

int study9(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"讲得九九八十一日，忽言：“神马验证将来兮！吾当归去。”\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"言讫不见。\n"NOR);
		me->delete_temp("personalbook/read");
		return 1;
	}	