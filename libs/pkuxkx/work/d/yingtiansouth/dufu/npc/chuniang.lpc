inherit NPC;


void create()
{
	set_name("厨娘", ({ "chu niang", "chu","niang" }));
	set("gender", "女性");
	set("age", 21);
	set("str", 10);
	set("dex", 10);
	set("long", "她是一名都府里的厨娘，长得清秀可人。\n");
	set("combat_exp", 8000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 10);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("chat_chance", 3);
	set("is_chuniang",1);
	set("chat_msg", ({
				(: random_move :),
                this_object()->name()+"轻轻地揉了揉自己的脸蛋。\n",
				this_object()->name()+"伸了一下懒腰。\n",
				this_object()->name()+"挽了一下鬓角的头发。\n",
                //(:askforhelp:),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth_chuniang")->wear();
}
int OfferFood(object me)
{
	object food=new(__DIR__"obj/food"+random(3));
	if (food->move(me))
	message_vision("$N把"+food->query("name")+"轻轻递给$n。\n",this_object(),me);
	else
	{
		tell_object(me,"你身上东西实在太多了，都摊不出手来接厨娘递过的"+food->query("name")+"。\n");
		destruct(food);
	}
	return 1;
}