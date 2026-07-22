// chuzi.c 厨子

inherit NPC;

int give_food();
int give_water();

void create()
{
	set_name("厨子", ({ "chu zi", "chuzi" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"这是一位神龙教厨房里的大师傅，正在忙碌着煮饭烧菜，你可以问他要food和water。\n");
	set("combat_exp", 0);
	set("attitude", "peaceful");
	set("inquiry", ([
		"food" : (: give_food :),
            	"water" : (: give_water :),
	]) );
        setup();
}

int give_food()
{
	object ob=this_player();
	object me=this_object();
	object obj;

	obj=new(FOOD_D("baozi"));
	obj->move(ob);
	tell_object(ob,me->name()+"给你一个包子。\n");
	return 1;
}

int give_water()
{
	object ob=this_player();
	object me=this_object();
	object obj;

	obj=new(FOOD_D("jiudai"));
	obj->move(ob);
	tell_object(ob,me->name()+"给你一个酒袋。\n");
	return 1;
}