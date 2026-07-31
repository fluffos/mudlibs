//7/14/2001 by Xuanyuan

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_zhen();
string ask_yang();
int auto_perform();
string ask_yufengjiang();

void create()
{
        set_name("小龙女", ({ "xiao longnu", "long", "longnu" }));
	set("long", "她清丽异常，但也许是长居古墓之故，面色略白。\n");
        set("gender", "女性");
        set("age", 18);
        set("attitude", "friendly");
        set("str", 20);
        set("dex", 28);
        set("con", 20);
        set("int", 28);
        set("shen", 20000);

        set("combat_exp", 1600000);
        set("max_qi", 2500);
        set("max_jing", 5600);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali",50);
        set_skill("literate", 150);
        set_skill("parry", 240);
        set_skill("force", 240);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("whip", 240);
        set_skill("throwing",240);
        set_skill("cuff", 240);
        set_skill("strike", 240);
        set_skill("meinu-quan", 240);
        set_skill("gumu-shenfa", 240);
        set_skill("tianluo-diwang", 240);
        set_skill("yinsuo-jinling", 240);
        set_skill("yunu-jue", 300);
        set_skill("yunu-jianfa", 240);
        set_skill("quanzhen-jian", 240);
        set_skill("yunu-xinjing", 240);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "gumu-shenfa");
        map_skill("cuff", "meinu-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("whip", "yinsuo-jinling");
        map_skill("sword", "yunu-jianfa");
        map_skill("parry", "yunu-jianfa");

        prepare_skill("cuff", "meinu-quanfa");
        prepare_skill("strike", "tianluo-diwang");

        create_family("古墓派",3,"弟子");
        set("inquiry", ([
		"杨过" : "过儿是我夫君，我知道他很爱我，可一直呆在这真怕他会闷。",
		"过儿" : (: ask_yang :),
		"job" : "你到外面树林去采一些蜂蜜回来,再到药房去炼成玉蜂浆",
		"工作" : "你到外面树林去采一些蜂蜜回来,再到药房去炼成玉蜂浆",
		"work" : "你到外面树林去采一些蜂蜜回来,再到药房去炼成玉蜂浆",
		"秘籍" : (: ask_me :),
		"玉蜂浆" : (: ask_yufengjiang :),
		"玉蜂针" : (: ask_zhen :),  
		    ]) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("book_count", 1);
	set("jiang_count", 4);

        setup();
        carry_object("/d/zhongnan/obj/baipao")->wear();
        carry_object("/d/zhongnan/obj/jinsi-shoutao")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/zhongnan/obj/jinling-suo");
}

void attempt_apprentice(object ob)
{

	mapping fam = ob->query("family");

/*	if(fam["master_name"] == "李莫愁") {
		command("say 你是我师姐"+fam["master_name"]+"的徒弟，我不能收你。");
		return;
		}       
  */        if((int)ob->query_skill("force", 1) < 20) {
                command("say 我古墓武功内功是基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }  
          if((int)ob->query_skill("dodge", 1) < 20) {
                command("say 你轻功这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在轻功上多下点功夫？");
                return;
                }
          if((int)ob->query_skill("sword", 1) < 20) {
                command("say 你剑法这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                return;
                }
            if((int)ob->query_skill("cuff", 1) < 20) {
                  command("say 你的基本拳法修为尚浅，领悟不了我的功夫。"); 
                 command("say "+RANK_D->query_respect(ob)+"是否还应该在你基本拳法上多下点功夫？");
                return;
                }
           // if((int)ob->query_skill("strike", 1) < 20) {
            //      command("say 你的基本掌法修为尚浅，领悟不了我的功夫。"); 
             //     command("say "+RANK_D->query_respect(ob)+"还是多练练掌法再来找我吧。");
            //    return;
             //   }
	if(ob->query_int() < 23) {
                command("say 我的武功都要极高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say 这位"+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";

	obs = filter_array(children("/d/zhongnan/obj/yunu_book1.c"), (: clonep :));
        if (sizeof(obs) > 2)
		return "你来晚了，本派的内功心法不在此处。";

	ob=new("/d/zhongnan/obj/yunu_book1");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"弄到了一册玉女二十四诀上卷。");
	return "本派的内功心法玉女心经并不在我这里，不过这本「玉女二十四诀上卷」你可以拿回去好好钻研。";
}

string ask_yufengjiang()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if(fam["master_name"] == "李莫愁") 
		return "怎么师姐的徒弟也对这古墓里的东西有兴趣？";

	if (query("jiang_count") < 1)
		return "你来晚了，玉蜂浆已经都给了你的师姐师妹们了。";

	if ( (int)this_player()->query("eff_qi")==(int)this_player()->query("max_qi") ) {
                message_vision("$N向$n脸上仔细地打量了一阵，摇了摇头。\n", this_object(), this_player());
                return "玉蜂浆酿制不易，你并未受伤，我不能给你。\n";
        }

	ob=new("/clone/drug/yufeng-jiang");
	ob->move(this_player());
	add("jiang_count", -1);
	return "这是我们古墓派的疗伤灵药，你拿去好好服用。";
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.suxin");
		  }
		  else return perform_action("cuff.luowang");
}

string ask_zhen()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "古墓派")
                                         return RANK_D->query_respect(this_player()) +
                                         "与本派素无来往，不知此话从何谈起？";
                  if (query("zhen_count") < 1)
                                         return "我已经将玉蜂针已给了派去清理门户的人，你好好练功，以后有机会再去吧。";
                  add("zhen_count", -1);
                  ob = new("/d/gumu/obj/yfzhen.c");
                  ob->move(this_player());
                  return "你如此自愿为师门清理门户，不枉我平时一番栽培，这枚玉蜂针你就拿去吧。";
}

string ask_yang()
{
	mapping fam; 
	object ob, *obs;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (query("shunvjian_count") > 1)
	return "你来晚了，君子剑我已找人带给过儿了。";

	obs = filter_array(children("/kungfu/class/gumu/obj/junzijian.c"), (: clonep :));
        if (sizeof(obs) > 0)
	return "你来晚了耶，君子剑我已找人带给过儿了。";

	ob=new("/kungfu/class/gumu/obj/junzijian");
	ob->move(this_player());
	add("shunvjian_count", -1);
	command ("rumor "+this_player()->query("name")+"得到一把君子剑。");
	return "你把这把君子剑带给过儿。";
}

