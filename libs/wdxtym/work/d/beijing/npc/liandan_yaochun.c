#include <ansi.h>
inherit NPC;

int do_stop();
int do_liandan();
string ask_me();
string ask_yinzhen();

void create()
{
	set_name("姚春", ({"yao chun", "yao", "chun"}));
	set("gender", "男性");
	set("age", 56);
	set("title", HIG "回春堂" NOR);
	set("nickname",HIR "跌打名医" NOR);
	set("long",
		"这便是京城回春堂药铺的跌打名医姚春，身材干"
		"瘦，其貌不扬。当年天地会徐天川受了伤，便由"
		"他医治，此人既是名医，擒拿短打也是一绝。\n");
	set("attitude", "heroism");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 20000);
	set("max_qi", 20000);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 20000);
	set("max_neili", 20000);

	set("combat_exp", 10000000);
	set("score", 300000);
	 set("skill_yaochun", 1);
	set_skill("medical", 150);
	set_skill("zhenjiu-shu", 150);
	set_skill("liandan-shu", 150);
	set_skill("literate", 150);

	map_skill("medical", "bencao-shuli");

	set("inquiry", ([
		"徐天川"  :  "那老猴儿便是我给医治的，怎么你也知道。\n",
		"炼丹"    : (:do_liandan:),
		"药材"    :  "去找我的小童，他会帮你处理。\n",
		"医术"    : (: ask_me :),
		"针灸"    : (: ask_yinzhen :),
		"停止炼丹"    : (: do_stop :),
	]) );

	setup();

}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

int do_stop()
{
	object me = this_player();

	if (me->query("combat_exp") < 2000000) {
                command("say 你还没有开始，就来问我结束吗？");
                return 1;
        }
      me->delete_temp("liandan");
      me->delete_temp("caiyao");
      command("sigh "+me->query("id"));
      command("say "+me->name()+"再也不是曾经的"+me->name()+"了，既然如此，那就先退下吧。");
      return 1;

}

int do_liandan()
{
	int exp, pot;
	object me = this_player();

	if (me->query("combat_exp") < 2000000) {
                command("say 你的实战修为太低,恐难以练出什么好丹吧！");
                return 1;
        }

	if (me->query_temp("liandan"))
	{
		if (me->query_temp("liandan") < 4)
		{
			command("say 不是要去炼丹吗，怎么还在这呆着？\n");
	            call_out("do_lian2", 5, me);
			return 1;
		}
		message_vision(CYN "姚春对$N" CYN "微笑道：炼丹是个修身养性的过程，你能成功，很不错！"NOR"\n", me);

		exp = 40 + random(20);
		pot = exp - random(20);

		me->add("combat_exp", exp);
		pot=me->improve_potential(pot);
		tell_object(me, HIC "你完成了第" + chinese_number(me->query("over_quest/liandan_quest", 1)+1) + "次炼丹。"NOR"\n" );
		tell_object(me, HIC "你获得了" + chinese_number(exp) +	"点修为和" + chinese_number(pot) + "点潜能。"NOR"\n" );

		me->delete_temp("liandan");
		me->add("over_quest/liandan_quest", 1);

	      call_out("do_lian1", 5, me);
		return 1;
	} else
	{
		message_vision(CYN "姚春对$N" CYN "点了点头，说道：炼丹是考验人的定力修为，心不静则事不成，你去向童子询问「" HIG "药材" NOR + CYN "」吧。"NOR"\n", me);
		me->set_temp("liandan", 1);

	      call_out("do_lian2", 5, me);
		return 1;
	}
}


void do_lian1(object me)
{
	if (! objectp(me))
		return;

      tell_object(me,ZJFORCECMD("ask yao chun about 炼丹"));

}

void do_lian2(object me)
{
	if (! objectp(me))
		return;

      tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("ask xiao tong about 采药"));

}


string ask_me() 
{
	object me;

	me = this_player();

	if (me->query("can_learn_medical/yaochun") == 1)
		return "我不是答应教你了吗，你这人怎么那么罗嗦？";

	if (me->query("shen") < -10000)
		return "你这种魔头，不去杀人都算是武林大幸了。";

	if (me->query("over_quest/liandan_quest") < 100 )
		return "这样吧，你先帮我炼丹百次，心诚之时我自然会传授给你。";

	if (me->query("shen") < 0)
		return "你侠义正事做得不够，多多行善之后我自然会传授给你。";

	me->set("can_learn_medical/yaochun", 1);
	       return "既然你欲诚心钻研学医之道，我就成全成全你吧。"; 
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("shen") < -10000)
	{
		command("say 给我滚开！我不会传授任何技能给你这种魔头！");
		return -1;
	}

	if ( ! me->query("can_learn_medical/yaochun") )
	{
		command("say 我的医术向来是不轻易传授的。");
		return -1;
	}

	if (skill == "literate")
	{
		command("say 读书写字自己去找教书先生学去。");
		return -1;
	}

	if (skill != "medical" &&
	    skill != "zhenjiu-shu")
	{
		command("say 我只能传授基本医术和针灸术。");
		return -1;
	}

	return 1;
}

string ask_yinzhen()
{
	mapping fam; 
	object ob;
	object me = this_player();

	if (me->query("shen") < -0)
		return "你走吧，我的神针可不会给你这样的人。";

	if ((int)me->query_skill("zhenjiu-shu", 1) < 60)
		return "你针灸术还不娴熟，随便用针会弄出人命来的。";

	if (present("yin zhen", this_player()))
		return "你身上不是还有一根吗？";

	ob = new("/d/beijing/obj/yinzhen");
	ob->move(me);

	message_vision(HIW "\n姚春从针盒里轻轻拈出一根银针，递给了$N" HIW "。"NOR"\n", me);
		return "这针可是用来救命的，好好的利用它为人治病吧。";
}

