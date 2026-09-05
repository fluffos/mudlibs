// shuanger.c
#include <ansi.h>

inherit NPC;
string ask_combine();
string ask_map();

void create()
{
	set_name("双儿", ({ "shuang er", "shuang","er"}));
	set("title", HIW "天下无双" NOR);
	set("nickname", HIM "大功告成" NOR);
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
        set("per", 20 + random(15));

	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 100000+random(100000));
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 120);
	set_skill("taiji-quan", 120);
	set_skill("tiyunzong",50);
        set_skill("taiji-shengong", 120);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
        map_skill("force", "taiji-shengong");
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 25);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
           (: perform_action, "sword.lian" :),
           (: perform_action, "sword.chanup" :),
           (: perform_action, "sword.sui" :),
        }) );

	 set("inquiry", ([
	     "合并" : (: ask_combine :),
	     "combine" : (: ask_combine :),
	     "地图" : (: ask_map :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();

}


int init()
{
//	add_action("do_attack","attack");

}

string ask_combine()
{
	object me = this_player();

	if(me->query("ludingshan"))
	return RANK_D->query_respect(me) + "不是已经拿到地图了么？";

	if(me->query("luding/map"))
	return RANK_D->query_respect(me) + "上次叫双儿办的事情还没办完呢。";

	if(me->query("repute") < 100000)
	return RANK_D->query_respect(me) + "江湖声望太低啦。";

	if(!me->query_temp("luding/ao"))
	return RANK_D->query_respect(me) + "若能杀死鳌拜狗贼，双儿什么都听你的。";
	if(!me->query_temp("luding/wu"))
	return RANK_D->query_respect(me) + "若能抓来告密的狗官吴之荣，双儿什么都听你的。";
	if(!me->query_temp("luding/zhuang"))
	return RANK_D->query_respect(me) + "若能救回我家老爷，双儿什么都听你的。";

	//三件事情都完成了
	me->set_temp("luding/map", 1);
	return RANK_D->query_respect(me) + "对双儿和夫人恩重如山，你说什么我都听你的。";
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return 0;

	if (!me->query_temp("luding/map"))
	{
		tell_object(me, "你无缘无故给我这个干什么啊？\n");
		return 0;
	}
        if(ob->query("id") != "yang pi")
        {
                tell_object(me, "恩公给双儿这个，双儿可消受不起。\n");
                return 0;
        }

	if ( (string)ob->query("name") == YEL"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p1"))
		me->set_temp("yangpi/p1", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIY"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p2"))
		me->set_temp("yangpi/p2", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == BLU"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p3"))
		me->set_temp("yangpi/p3", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIB"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p4"))
		me->set_temp("yangpi/p4", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == RED"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p5"))
		me->set_temp("yangpi/p5", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIR"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p6"))
		me->set_temp("yangpi/p6", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == WHT"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p7"))
		me->set_temp("yangpi/p7", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIW"羊皮碎片"NOR && ob->query("id") == "yang pi")
	{
		if (!me->query_temp("yangpi/p8"))
		me->set_temp("yangpi/p8", 1);
		else
		{
			tell_object(me, "这包碎片你已经给过我了啊？\n");
			return 0;
		}
	}
	call_out("destroy", 1, ob);
	if (	   me->query_temp("yangpi/p1")
		&& me->query_temp("yangpi/p2")
		&& me->query_temp("yangpi/p3")
		&& me->query_temp("yangpi/p4")
		&& me->query_temp("yangpi/p5")
		&& me->query_temp("yangpi/p6")
		&& me->query_temp("yangpi/p7")
		&& me->query_temp("yangpi/p8") )
	{
		me->delete_temp("yangpi");
		me->delete_temp("luding");
		me->set("luding/map", me->query("mud_age") + 3000 + random(1500));
		tell_object(me, "这些碎片我可能要花一些时间才能拼好，你过几天再来找我吧。\n");
	}
	else
		tell_object(me, RANK_D->query_respect(me) + "快把剩下的碎片找齐给我吧。\n");

        return 1;
}
void destroy(object ob)
{
	destruct(ob);
}

string ask_map()
{
	object map;
	object me = this_player();
	int age = me->query("mud_age");

	if(!me->query("luding/map"))
	return RANK_D->query_respect(me) + "与我素无来往，此话从何提起？";

	if( age - me->query("luding/map") < 0)
	return "羊皮碎片实在是太多了，" + RANK_D->query_respect(me) + "请过几天再来吧。";

	message_vision(HIG"\n双儿把$N领到桌前，只见桌上大白布上钉满了几千枚绣花针。
几千块碎片已经拼成一幅完整无缺的大地图，难得的是几千片
碎片拼在一起，既没多出一片，也没少了一片。\n\n"NOR, me);

	message_vision(HIW"全幅地图都是墨笔画成，只见地图上一条大河转弯处聚在一起。
有八个颜色的小圈，八个小圈之间写着两个黄色满洲字，译成
汉字，乃是“鹿鼎山”三字。\n\n"NOR, me);

	message_vision(HIR"$N大叫一声，反手将$n一把抱住，叫道：“大功告成，亲个嘴儿。”说着向$n嘴上吻去。
$n羞得满脸通红，头一侧，$N的嘴吻到了$n的耳垂上。$n只觉全身酸软，惊叫：“不，不要！”\n\n"NOR, me, this_object());

	tell_object(me, "你将图形和地名牢记在心，然后将羊皮地图投入火炉，一把火烧掉。\n\n");
	me->delete("luding/map");
	me->add("combat_exp", 10000);
	me->set("ludingshan", 1);
	tell_object(me, "你的经验增加了。\n");
	return "恭喜" + RANK_D->query_respect(me) + "发现鹿鼎山的秘密！！！" ;
}
