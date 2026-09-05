
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_lost();

mapping budbook=
	([
	"般若经":"/d/shaolin/obj/fojing10",
	"维摩经":"/d/shaolin/obj/fojing10",
	"法华经":"/d/shaolin/obj/fojing10",
	"华严经":"/d/shaolin/obj/fojing10",
	"无量寿经":"/d/shaolin/obj/fojing20",
	"大般涅磐经":"/d/shaolin/obj/fojing20",
	"阿含经":"/d/shaolin/obj/fojing20",
	"金刚经":"/d/shaolin/obj/fojing20",
	"波罗蜜多心经":"/d/shaolin/obj/fojing20"]);

void create(){
	set_name("玄彦大师", ({"hcc npc"}));
	set("long","他就是当年侠客行里自称老衲的玄彦大师. \n""他神态祥和，面带微笑，是你如沐春风. \n""他端坐这那里，口中喃喃的诵读着佛经. \n");
	set("title",RED "少林" NOR + GRN "扫地僧" NOR);
	set("gender", "男性");
	set("age", 51);
  set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2500000);
 	set("score", 500000);
	set_skill("force", 300);
	set_skill("hunyuan-yiqi", 300);
	set_skill("blade", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("dodge", 250);
	set_skill("shaolin-shenfa", 250);
	set_skill("cuff", 300);
	set_skill("jingang-quan",300);
	set_skill("parry",300);
	set_skill("sword", 300);
	set_skill("damo-jian", 300);
	set_skill("buddhism", 250);
	set_skill("finger", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("literate", 100);
	map_skill("force","hunyuan-yiqi");
	map_skill("dodge","shaolin-shenfa");
	map_skill("cuff","jingang-quan");
	map_skill("parry","jingang-quan");
	map_skill("blade","xiuluo-dao");
	map_skill("sword","damo-jian");
	map_skill("finger","nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");
	set("inquiry",
 	([
  	"鸿鸿" : (: ask_me :),
  	"借书" : "目前对少林弟子开放佛经外借手续，本处藏经皆可外借(jie)，每人限定一本。",
  	"遗失" : (: ask_lost :)
  	]));
  create_family("少林派",1,"祖师");
  set("class", "bonze");
  setup();
}

string ask_me()
{
         mapping fam;
               object ob;
          if(!(fam=this_player()->query("family"))
              ||fam["family_name"]!="少林派")
return RANK_D->query_respect(this_player())+"与本派素无往来，不知此话从何说起?";
command("say 鸿鸿是我老婆呀!");
command("say 千万别告诉她我出家了啊！？她会把我purge掉的。");
command("fear");
command("这本书是我从藏经阁里偷出来的，给你吧。别告诉别人啊！");
command("grin "+ this_player()->query("id"));
write("hcc偷偷塞给你一本射雕英雄传\n");
command("laugh")
;
command("say 其实我是骗你的，我怎么能随便给玩家东西呢，爱爱她不让！\n");
  return ("hcc嘿嘿嘿地奸笑了几声。\n");
}

//佛经遗失以后将降低门派评价，损失一定程度钱财
string ask_lost()
{
	mapping fam;
	object me;
	
	me=this_player();
	if (!(fam = me->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";
	else if(!me->query("family/book"))
		return "你没有从我这里外借图书，也无需进行遗失登记。";
	else if(member_array(me->query("family/book"), keys(budbook))==-1)
		return "我这里只提供佛经的遗失登记！";
	else if(me->query("score")<10)
		return "你先对门派做出更多贡献才能给予你图书的遗失登记。";
	else if(me->query("balance")<10000)
		return "遗失登记需要1两黄金的金钱补偿，你的存款不足以完成遗失登记。";
	
	me->add("score",-10);
	me->add("balance",-10000);
	me->delete("family/book");
	return "已经注销了你的图书租借记录，你可以继续外借佛经了！";
}

void init()
{
  object ob;
  mapping fam;
  ::init();
  add_action("do_jie", "jie");
}

//借佛经，少林弟子都可以借佛经
int do_jie(string arg)
{
	object me,book;
	mapping fam;
	
	me=this_player();
	if(!arg)
		return notify_fail("必须给出想借的佛经名字！\n");
	else if(me->query("family/book"))
		return notify_fail("你先还上图书才能再往外借！\n");
	else if (!(fam = me->query("family")) || fam["family_name"] != "少林派")
		return notify_fail(RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？");
	else if(member_array(arg, keys(budbook))==-1)
		return notify_fail("目前仅提供佛经：般若经、维摩经、法华经、华严经、无量寿经、大般涅磐经、阿含经、金刚经、波罗蜜多心经！\n");
	else if(me->query("combat_exp")<2000)
		return notify_fail("经验过2000点以后才能开通借书服务！\n");
	
	book=new(budbook[arg]);
	book->set("name",arg);
	me->set("family/book",arg);
	book->move(me);
	tell_room(environment(),query("name")+"递给你一本"+book->query("name")+"，并对你说：请注意保管，用完佛经及时归还，如有遗失请过来登记！\n");
	return 1;
}

int accept_object(object me, object ob)
{
	object tob=this_object();
	mapping fam;
	
	if (!(fam = me->query("family")) || fam["family_name"] != "少林派") {
		command("say "+RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？");
		return 0;
	}
	else if(!me->query("family/book")||member_array(me->query("family/book"), keys(budbook))==-1) {
		command("say 你没有从我这里外借过图书！");
		return 0;
	}
	else if(me->query("family/book")!=ob->query("name")) {
		command("say 你从我这里借走佛经："+me->query("family/book")+"和你给我的"+ob->query("name")+"似乎不符！");
		return 0;
	}
	else {
		message_vision("$N归还了借走的佛经「"+me->query("family/book")+"」。\n", me);
		me->delete("family/book");
		remove_call_out("destroying");
		call_out("destroying",1,ob);
		return 1;
	}
}

void destroying(object ob)
{
	destruct(ob);
	return;
}