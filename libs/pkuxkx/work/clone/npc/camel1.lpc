// camel.c
#include <ansi.h>
inherit NPC;

int destroyme();
int destroy();
void destroyme1();
void getall();
int random_move1();

void create()
{
	seteuid(getuid());
	set_name("毫毛", ({ "hao mao","mao mao","mao","camel" }) );
	set("container",1);
        set("dustman",1);
        set("special_skill/sociability",1);
	set("title", MAG "江湖破烂王" NOR);
	set("gender", "男性" );
	set("age", 28);
	set("long", "一个慈眉善目、道貌岸然的家伙，身上穿得破烂不堪，到处捡别人扔掉的垃圾。\n");
	set("attitude", "peaceful");
        set("class", "officer");
        set("pin", 8);
        set("rank_info/respect", "老爷子");
        set("rank_info/rude", "臭捡破烂的");
	set("str", 50);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
        set("neili", 5000);
        set("max_neili", 5000);
	set("shen_type", 0);
	set("startroom","/d/city/guangchang");
	set("thief", 0);
	set("no_steal",1);
	set("no_fight",1);
	set_max_encumbrance(100000000);
	set("combat_exp", 100000000);
	set("chat_chance",30);
	set("inquiry", ([
	    "name" : "我就是大名鼎鼎的毫毛呀，连我都不知道，你别在江湖混了。",
	    "姓名" : "我就是大名鼎鼎的毫毛呀，连我都不知道，你别在江湖混了。",
	]) );
	set("chat_msg", ({
		(: random_move1 :),
	}) );
	set("shen_type",1);set("score",2000);set("shen_type",1);set("score",5000);setup();
	carry_object("/clone/armor/cloth")->wear();
	call_out("destroyme",3600);
	call_out("destroy",360);
}
/*
void delete_init_num(object me)
{
        me->delete("init_num");
        return;
}

void init()
{
	::init();
	if(!query_heart_beat())
	set_heart_beat(1);
	if (!this_player())	//非玩家不触发
		return;
	//以下有关random_move的修改为防止出现类似init(opendoor(init(opendoor(....类型的递归调用 (/d/baituo/storeroom会有这样的情景)
	//1秒钟内最多触发1次init
	if (this_object()->query("init_num"))
     	call_out("delete_init_num",1,this_object());
	this_object()->add("init_num",1);
	if (this_object()->query("init_num") < 2)
	{
			command("get all");
			command("open door");
			command("open men");
			this_object()->remove_all_killer();
	}
}*/

int destroy()
{
	object *inv=all_inventory(this_object());
	for(int i=sizeof(inv)-1;i>=0;i--)
	{
		reset_eval_cost();
		if (inv[i]->query("id") != "cloth")
		destruct(inv[i]);
	}
	remove_call_out("destroy");
	call_out("destory",360);
	return 1;       
}

int destroyme()
{
	if(environment(this_object()))
		message("vision","毫毛忽然跑到路边对着墙上的野广告大喊『我的病有治啦！！！』，接着小心翼翼地揭下广告，匆匆走开。\n",environment(this_object()));
	destroy();
	call_out("destroyme1",2);
	return 1;
}

int random_move1()
{
	random_move();
	command("get all");
        getall();
	return 1;
}

void destroyme1()
{
	destruct(this_object());
}

void unconcious()
{
	die();
}

/*
void die()
{
	message("vision","毫毛吹了吹胡子，天空中出现一阵烟雾，几声怪响之后，毫毛又\n"+
	"活了过来....\n",environment(this_object()));
	this_object()->set("eff_qi",this_object()->query("max_qi"));
	this_object()->set("qi",this_object()->query("max_qi"));
	this_object()->set("eff_jing",this_object()->query("max_jing"));
	this_object()->set("jing",this_object()->query("max_jing"));
	this_object()->remove_all_killer();
	return;
}

*/
int heal_up()
{
	return ::heal_up() + 1;
}
void getall()                                             
{                                                       
        object ob=this_player();                        
        object env=environment(ob);
        object *inv;
        inv=all_inventory(env);
        for(int i=0;i<sizeof(inv);i++)
        {
           if( inv[i]->is_character()) continue;
          if( inv[i]->query("no_get") && inv[i]->query("weapon_prop"))
              {
              message_vision( "$N吐了一口口水，使劲一脚将$n踩到了地里，得意的笑了一声。\n", ob, inv[i]);
              destruct(inv[i]);
              }
        }
        return;                                     
}
