// story:huanyin 玄阴指法



nosave string char_id;
nosave string char_name;
nosave string family_name;

int give_gift();
object select_character();

nosave mixed *story = ({
	"谢巽：成坤！休走，今天我就和你做一了断",
	"成坤：他奶奶的，今天遇到这瞎子，算我倒霉到家了。",
	"杨霄：成坤，你作恶多端，害死阳教主，今天还想跑么？",
	"韦笑川：当年光明顶的事情还没有了阿，你就这么走了？",
	"张无极哼了一声，暗道：义父和这人是血海深仇，不能不报，我倒不必插手。",
	"成坤呵呵大笑：老夫岂能怕了你们，只不过你们倚多取胜，老夫就不能奉陪了。",
	"韦笑川笑道：成坤，你就呆着这里，若能打赢狮王，就让你走路，我们决不插手。",
	"成坤冷笑一声，道：老夫活了几十年，居然还在我面前玩这种小儿科？",
	"韦笑川阴阴道：那就别怪我...",
	"只见韦笑川身形倏的变快，直令人匪夷所思，双脚踢得尘土飞扬，犹如一道利箭赶了上来...",
	"成坤暗道：吾命休矣！韦笑川倒也罢了，只是他缠上身来，我却怎么落得脱身？",
	"忽然路边一人飘然而至，“嗯？这是为何？”",
	"韦笑川一掌探出，拍向那人，喝道：“让开！”",
	"$N讶道：“怎的如此狠毒？想必也不是什么善类。”随即一掌轻轻挥出。",
	"两掌相交，只震得韦笑川眼花缭乱，气血翻涌，人平平的飞了出去，一跤摔倒在地。",
	"张无极见状大惊，连忙欺身近来，护住韦笑川。",
	"成坤哈哈大笑，道：张教主、杨左使、韦蝠王还有我得好徒儿，今天我可要失陪了。",
	"张无极喝道：阁下何人？为何要插手此事？",
	"$N淡淡道：久闻明教无恶不作，今日一见，果不其然，我便是$N，如若不服，他日找上$F就是。",
	"张无极：@@@@@@@",
	"......",
	"成坤：今天承蒙相救，老夫感激不尽，无以为赠，这路玄阴指法乃在下精研，阁下如果有意，也可参详一番。",
	(: give_gift :),
});

void create()
{
	seteuid(getuid());

	if (! objectp(select_character()))
	{
		destruct(this_object());
		return;
	}
}

string prompt() { return HIG "【武林传闻】" NOR; }

object select_character()
{
	object *obs;
	object ob;

	obs = filter_array(all_interactive(),
			   (: ultrap($1) &&
			      living($1) &&
			      $1->query_skill("huanyin-zhi", 1) < 1 &&
			      $1->query("family/family_name") &&
			      ! wizardp($1) &&
			      ! $1->query("story/huanyin") :));
	if (! sizeof(obs))
		return 0;

	ob = obs[random(sizeof(obs))];
	char_id = ob->query("id");
	char_name = ob->name(1);
	family_name = ob->query("family/family_name");
	return ob;
}

mixed query_story_message(int step)
{
	mixed msg;

	if (step >= sizeof(story))
		return 0;

	msg = story[step];
	if (stringp(msg))
	{
		msg = replace_string(msg, "$N", char_name);
		msg = replace_string(msg, "$F", family_name);
		msg = replace_string(msg, "$ID", char_id);
	}
	return msg;
}

int give_gift()
{
	object ob;

	ob = find_player(char_id);
	if (! ob) return 1;

	if (ob->query_skill("huanyin-zhi", 1) < 10)
		ob->set_skill("huanyin-zhi", 10);

	ob->set("story/huanyin", 1);
	tell_object(ob, HIC "你从成坤那里学习到了玄阴指法。"NOR"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
			      "从成坤那里学习到了玄阴指法。");
	STORY_D->remove_story("huanyin");
	return 1;
}
