// camel.c
#include <ansi.h>
inherit NPC;

int destroyme();
int destroy();
void destroyme1();

void create()
{
        seteuid(getuid());
        set_name("毫毛", ({ "hao mao","mao mao","mao","camel" }) );
        set("container",1);
        set("title", MAG "江湖破烂王" NOR);
        set("gender", "男性" );
        set("age", 28);
        set("long", "一个慈眉善目、道貌岸然的家伙，身上穿得破烂不堪，到处捡别人扔掉的垃圾。\n");
        set("attitude", "peaceful");
        set("str", 50);
        set("con", 25);
        set("int", 25);
        set("dex", 25);
         set("max_qi", 1000);
         set("max_jing", 1000);
        set("neili", 0);
        set("max_neili", 0);
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
        	(: random_move :),
        }) );
        setup();
        carry_object("/clone/armor/cloth")->wear();
        call_out("destroyme",3600);
}

void init()
{
        ::init();
        if(!query_heart_beat())
        	set_heart_beat(1);
	command("get all");
	command("open door");
 	command("open men");
}

int destroy()
{
	object *inv=all_inventory(this_object());
         for(int i=sizeof(inv)-1;i>=0;i--)
	{
		reset_eval_cost();
                if (inv[i]->query("id") != "cloth")
		destruct(inv[i]);
	}
	return 1;	
}

int destroyme()
{
   if (!environment(this_object())) 
    {
    destruct(this_object());
    return 1;
    }
        message("vision","毫毛忽然跑到路边对着墙上的野广告大喊『我的病有治啦！！！』，接着小心翼翼地揭下广告，匆匆走开。\n",environment(this_object()));
		destroy();
        call_out("destroyme1",2);
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

void die()
{
	message("vision","毫毛吹了吹胡子，天空中出现一阵烟雾，几声怪响之后，毫毛又\n"+
	"活了过来....\n",environment(this_object()));
	this_object()->set("eff_qi",this_object()->query("max_qi"));
	this_object()->set("qi",this_object()->query("max_qi"));
	this_object()->set("eff_jing",this_object()->query("max_jing"));
	this_object()->set("jing",this_object()->query("max_jing"));
	return;
}

int heal_up()
{
        return ::heal_up() + 1;
}
