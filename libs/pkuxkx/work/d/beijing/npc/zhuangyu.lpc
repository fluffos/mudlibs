inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("庄允城", ({ "zhuang yuncheng", "zhuang","yuncheng" }) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("no_get", 1);
	set("long",
		"这是个饱读诗书，却手无搏鸡之力的书生。\n"
             +"因编辑「明书辑略」，被吴之荣告发，全家逮入京中。\n" );
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("no_get", "庄允城叹道：我不行了，你走吧。唉，我担心我家里人啊。\n");
	set("chat_chance", 5);
	set("chat_msg", ({
	"\n庄允城说道：只怪我当初好心，在书中夹了金叶送与他，\n"
	"谁想这狼心狗肺的家伙竟然就去告发了我。唉...\n",
	"\n庄允城说道：谁要把吴之荣抓到庄府就好了。\n",
	"庄允城说道：谁要救了我，我一定会报答他。\n",
	}));
        set("inquiry", ([
                "救命"     : (: ask_me :),
		"鳌拜" : "鳌拜的暗室里有宝贝。",
		"吴之荣" :  "把他送到庄府去有好处。",
	]) );
	set("shen_type",1);set("score",2000);setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me, ob, player;
        me = this_object();
        player = me->query_leader();
        if (!player) return;

        ::init();
        if( objectp(ob = present("san furen", environment())) )
        {
         command("missu " + ob->query("id"));
         command("touch " + ob->query("id"));
         command("say 多谢"+ RANK_D->query_respect(player) + "救我性命，大恩大德永世难忘。");
         message_vision("$N和$n携手走入了内堂。\n", me, ob);
         command("follow none");
         //player增加一个mark，以供合并地图使用
         player->set_temp("luding/zhuang", 1);
         destruct(ob);
         destruct(me);
        }

}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("name") == "「明书辑略」")
	{
	 write(HIC "\n庄允城笑到：书里有金叶子，难道你不知道吗？\n" NOR);
	 write(HIC "庄允城说：替我把吴之荣这厮抓到庄府去吧，我不行了。\n" NOR);
	 write("庄允城喘了口气，又说：庄府在京城东北边。\n");
	}
        else
        {
         write("你给我这个东西做什么？\n");
         return 0;
        }
        return 1;
}
string ask_me()
{
        object me, ob;
        me = this_object();
        if (objectp(me->query_leader())) return "一个一个来，不要急。";
        ob = this_player();
        command("say "+ RANK_D->query_respect(ob) + "请带我回庄府。\n");
        command("follow " + ob->query("id"));
        ob->apply_condition("bjkiller", 100);
        tell_object(ob,HIR"你被官府通缉了。\n"NOR);
        return "我们走罢！";
}



