// qiaofu.c

inherit NPC;
int ask_me();

void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这个樵夫好象打扮土里土气，但目光中透着一丝悲悯之情，让人好生奇怪。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("inquiry",([
		"绝义谷" : (:ask_me:),
		]));
	set("shen_type",1);set("score",200);setup();
}

void init()
{	
	object me;

	::init();
	if( interactive(me = this_player()) && !is_fighting() ) 
	message_vision("樵夫听到脚步声，抬起眼把$N打量了一番，他的目光令人不由的感到一丝寒意。\n",me);

}

int ask_me()
{	object me=this_player();
	me->set_temp("down1",1);
	tell_object(me,"樵夫摇摇头叹道：唉，又一个。。。\n"
			"樵夫头也不抬，指指树林中的小道，算是回答了你。\n");
	return 1;
}
