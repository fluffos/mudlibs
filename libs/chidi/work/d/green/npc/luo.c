#pragma save_binary
// luo.c

inherit BHNPC;


void create()
{
  set_name("喽罗", ({ "lou luo", "luo" }) );
	set("title", "野羊山匪众");
	set("gender", "男性" );
	set("age",23);
	set("long",
	"野羊山的喽罗来自四面八方，他们落草为寇的原因也千奇百怪。\n"
	"有的喽罗本身就是地方上的游手好闲之徒，有的则是给官府逼的走\n"
	"头无路。所以他们对百姓的态度也各自不同n");
       set("shen_type",-1);
     set("max_kee",250);
     set("kee",250);
     set("cor",30);
     set("con",30);
     set("str",15);
	set("combat_exp",2000);
	set("attitude", "friendly");
	set("inquiry", ([
		"野羊山" : "是啊... 这里就是野羊山，你要干什么？",
	]) );
	set_skill("literate", 10);
	set_skill("dodge", 50);
	set_skill("unarmed", 80);
	setup();
}

void init()
{
object ob;
ob = this_player();
::init();
remove_call_out("greeting");
call_out("greeting", 1, ob);
      }

void greeting(object ob)
{
if (ob->query("name")==(" 辽东大营士兵"))
command ("kill "+ob->query("id"));
}
void killed_enemy(object who)
{        call_out("dissolve", 1);
} 
void dissolve()
{
        command("kill bing");
}

int heal_up()
{
::heal_up();
if (this_object()->query("time")<(int)time())
     {call_out("dodest",1);
      }
}
void dodest()
{
destruct(this_object());
}

