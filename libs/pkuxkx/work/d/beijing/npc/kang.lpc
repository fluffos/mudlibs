// kang.c 康亲王

#include <ansi.h>

inherit NPC;
string ask_job();
string ask_fail();
string ask_finish();
void create()

{

	set_name("康亲王", ({ "kang qinwang", "kang", "qinwang"}));

	set("gender", "男性");

	set("age", 42);

	set("str", 25);

	set("dex", 20);

	set("long", "只见他一身锦衣，笑容满面，任谁见了他都生不起气来。\n"+

		"此人深谙为官之道，极善察言观色、溜须拍马，颇得皇帝欢心。\n");

	set("combat_exp", 50000);

	set("score", 5000);

	set("shen_type", -1);

	set("attitude", "peaceful");


	set_skill("unarmed", 60);

	set_skill("dodge", 60);

	set_skill("parry", 60);
        set_skill("force",60);



	set_temp("apply/attack", 50);

	set_temp("apply/defense", 50);

	set_temp("apply/armor", 10);

	set_temp("apply/damage", 25);

	set("qi", 500);

	set("max_qi", 500);

	set("jing", 300);

	set("max_jing", 300);

	set("neili", 500);

	set("max_neili", 500);

	set("jiali", 50);

        set("inquiry", ([

		"鳌拜" :  "\n鳌拜这厮横行霸道，我早就想除了他。\n",

		"玉骢马" :  "\n你想要我就送与你吧，不过它可不一定会服你。\n",

		/*"洗马": (:ask_job:),
		"失败":(:ask_fail:),
		"完成":(:ask_finish:),*/
       ]) );



	setup();

	carry_object(__DIR__"obj/guanfu")->wear();

        //add_money("gold", 1);
        add_money("silver", 10);

}


void init()

{

object ob;

ob=this_player();

::init();

remove_call_out("greeting");

call_out("greeting", 1, ob);

}



void greeting(object ob)

{

        object man;
        if( !ob || environment(ob) != environment() || environment()->query("short") != HIC"康亲王书房"NOR) return;
        if(userp(ob) && ob->query("class") != "officer")
	{

        if(userp(ob))
        message_vision("\n康亲王一见$N, 顿时勃然大怒，叫道：“来人啊！将这厮给我拿下！”\n",ob);
        ob->apply_condition("bjkiller", 100 + ob->query_condition("bjkiller"));
        if(!present("shiwei", environment(ob)))
	 {
         message_vision("登时门外冲进几个侍卫，挥刀向$N直扑过来。\n",ob);

	 man=new("/d/beijing/npc/shiwei1");

	 man->move(environment(ob));

	 man->kill_ob(ob);

	 man=new("/d/beijing/npc/shiwei2");

	 man->move(environment(ob));

	 man->kill_ob(ob);

	 man=new("/d/beijing/npc/shiwei2");

	 man->move(environment(ob));

	 man->kill_ob(ob);
	 }

        return ;

	}

	switch( random(5) ) {

		case 0:

        message_vision("\n$N刚一进门, 康亲王便抢着迎了出来，笑道：“这位" + RANK_D->query_respect(ob)+

	"，请进请进。\n",ob);

	break;

	default:

	say( "康亲王笑道：不知这位" + RANK_D->query_respect(ob)

		+ "，光临寒舍有何贵干？\n");

	break;

	}

}

/*string ask_job()
{
	object ppl=this_player();
	 if(ppl->query("combat_exp") > 3000)
        {
            return "在我这里洗马太埋没您拉，您还是去干点别的吧。\n";
        }

	if (ppl->query_temp("xima/in_job"))
		return "你上次的工作还没有完成！";
	else
	{
		ppl->set_temp("xima/in_job",1);
		ppl->set_temp("xima/ok",0);
		return "你到马厩去洗一下马吧。\n";
	}
}

string ask_fail()
{
	object ppl=this_player();
	if (!ppl->query_temp("xima/in_job"))
			return "我没有让你洗马呀？";
	if (ppl->query_temp("xima/ok"))
		return "你不是已经洗完马了吗？";
	ppl->set_temp("xima/in_job",0);
    write("康亲王叹了口气，说道：这点小事都干不好，还想在江湖上混？\n");
	return "你走吧，我看见你就来气";
}
string ask_finish()
{
	object ppl = this_player();
        int ereward,breward;
	 if(!ppl->query_temp("xima/in_job"))
			return "我没有让你洗马呀？";
	 if(!ppl->query_temp("xima/ok"))
            return "你还没洗完马吧？ 嗯......\n";

	ppl->delete_temp("xima/in_job");
	ppl->delete_temp("xima/ok");

            ereward=(5 + random(45));
            breward= 100 * (1 + random(8));
            ppl->add("combat_exp",ereward);
            ppl->add("balance",breward);
            ppl->add("chaoting/xima", 1);
            ppl->add("score", 1);
            tell_object(ppl,"你对朝廷的贡献度上升了。\n");
            tell_object(ppl ,HIY"你得到了"+chinese_number(ereward)+"点经验的奖励。\n"
              "你得到了"+chinese_number(breward/100)+"两银子的奖励。\n"NOR);
                return "干得好，赏银已经存入你的钱庄户头了。\n";
}
*/