// xiaoji.c

inherit NPC;

void talk();


string* longs = ({"一只可爱的小鸡，长着黄色的绒毛，可爱极了。\n",
"这是一只半大的小鸡，已经看出这是一只小母鸡了。\n",
"这是一只小母鸡，虽然还没长成。\n",	
"这是一只芦花大母鸡，咯咯咯咯咯\n",
"这是一只老母鸡了。\n",
	});

string* shorts = ({
	"小鸡",
	"半大小鸡",
	"小母鸡",
	"母鸡",
	"老母鸡",
});

string* talks = ({
	"叽叽叽叽叽叽.....\n",
	"咯咯叽叽唧唧\n",
	"咯咯咯唧唧唧\n",
	"咯哒咯哒咯哒...咯哒咯哒咯哒\n",
	"咯咯咯咯咯咯咯咯咯咯咯咯\n",
});

void create()
{
	set_name("小鸡", ({ "chick",}) );
	set("age", 1);
	set("race", "野兽");
	set("step",0);
	set("long", longs[0]);
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);
	set("gender","雌性");
	set("limbs", ({ "头部", "翅膀", "尾巴", "爪子"}) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
		
	set_heart_beat(1);
	setup();
	set("keep_heart_beat",1);
}

void heart_beat()
{
	object egg;
	if(random(500) == 0)
	{
		add("step",1);
		if(query("step") >= 5)
		{
			message_vision("$N真的老了，它再也不能下蛋了。它悲哀的缩了缩脖子，死了。\n",this_object());
			destruct(this_object());	
			return;
		}
		else
		{
			message_vision("$N又长大了。"+longs[query("step")],this_object());
			set("long",longs[query("step")]);
			set("name",shorts[query("step")]);

			if(query("step") == 4 || query("step") == 3)
			{
				message_vision("$N看四周没有人，偷偷的下了一个蛋！\n",this_object());
				egg = new(__DIR__"egg");
				egg->move(environment(this_object()));
			}
		}
	}

	if(random(100) < 10)
	{
		if(random(10) == 0)
		{
			random_move();
		}
		else
		{
			talk();
		}
	}
}

void die()
{
	object ob,corpse;
	message_vision("$N哀鸣一声，死了，好惨！\n", this_object());
	destruct(this_object());	
}


void talk()
{
	message_vision(talks[query("step")],this_object());
}