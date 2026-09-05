// yexingren.c 夜行人
// created by Zine 26 Aug 2010

inherit NPC;

string* obj = ({

       "/biwu/xy/obj/dan",
	   "/biwu/xy/obj/saoba",
	   "/biwu/xy/obj/paper",
	   "/biwu/xy/obj/jiandao",
	   
});

int ask_secret();

void consider();

void create()
{
	set_name("夜行人", ({ "yexing ren","yexing","ren"}) );
	set("title", "飞檐走壁");
	set("gender", "男性" );
	set("long", "一个一身黑色的家伙，一看就不是什么好人。\n");
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", -100);
    set("env/wimpy", 110);
	set("thief", 0);
	set("combat_exp", 1000000);
    set_skill("force", 800);
	set_skill("cuff", 800);
	set_skill("taiji-quan", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("stealing", 500);
	set_skill("taiji-shengong", 800);
	set_skill("tiyunzong", 800);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-quan");
	map_skill("cuff", "taiji-quan");
	create_family("武当派", 4, "弃徒");
       	set("inquiry", ([
        	"秘密" : (: ask_secret :),
         	"传闻" : (: ask_secret :),
         	

	]));
	set("chat_chance", 20);
	set("chat_msg", ({
		"夜行人嘟囔说道: 找这里找了半天了，什么值钱的东西都没找到。\n",
		"夜行人很生气的撅了撅嘴。\n",
		"夜行人狠狠向空气劈了一拳，骂道: 月色那家伙真不可靠，骗我说这里有宝物，连个屁都没有。 \n",
		(: random_move :)
	}) );
	setup();
	carry_object("/biwu/xy/obj/bcloth")->wear();
    carry_object("/biwu/xy/obj/buxue")->wear();
}

void init()
{
	object ob;
	::init();
	if( (ob = this_player()) ) 
		{
			remove_call_out("stealing");
			call_out("stealing", 1, ob);
		}
}

void stealing(object ob)
{
	if( !ob || environment(ob) != environment()) 
		return;
		switch( random(5) ) 
			{
				case 0:
					command("hehe " + ob->query("id"));
                    command("kick " + ob->query("id"));
					break;
				case 1:
                    command("grin " + ob->query("id"));
                    command("consider " + ob->query("id"));
					break;
				case 2:
					command("wa " + ob->query("id"));
                    command("steal jia from " + ob->query("id"));
                    command("wear jia");
					break;
				case 3:
                    command("hate " + ob->query("id"));
                    command("slash " + ob->query("id"));
					break;
				case 4:
                    command("walkby " + ob->query("id"));
                    command("sigh " + ob->query("id"));
                    break;
			}
}

int ask_secret()
{
	object ob=this_player();
	object dan = new( obj[random(sizeof(obj))] );
	command("hehe");
	command("say 你问我为什么要来啊?月色告诉我，这里有很多宝物，瓮城里还藏有许多神兵利器。\n");
	command("say 你怎么会知道这个秘密的？\n");
	command("consider " + ob->query("id"));
	if (!(this_object()->query("asked")))
	{
  	dan->move(this_object());
	this_object()->set("asked",1);
	}
	return 1;
}

