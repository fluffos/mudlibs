#pragma save_binary
// luo.c

inherit BHNPC;


void create()
{
    set_name("小头目", ({ "toumu","tou" }) );
	set("title", "野羊山匪众");
	set("gender", "男性" );
	set("age",23);
	set("long",
	"野羊山的喽罗来自四面八方，他们落草为寇的原因也千奇百怪。\n"
	"有的喽罗本身就是地方上的游手好闲之徒，有的则是给官府逼的走\n"
	"头无路。所以他们对百姓的态度也各自不同n");
    set("shen_type",-1);
	set("combat_exp",1000);
	set("attitude", "friendly");
	set("inquiry", ([
		"野羊山" : "是啊... 这里就是野羊山，你要干什么？",
	]) );
	set_skill("literate", 10);
	set_skill("dodge", 60);
	set_skill("unarmed", 100);
	setup();
	add_money("coin", 50);
}

void init()
{
object ob;
ob = this_player();
::init();
    if( interactive( ob ) ) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
      }
void greeting(object ob)
{
object *list,aim;
int i,k,s;
list = all_inventory(ob);
i=sizeof(list);
if((string)ob->query("family/family_name") == "朝廷")
{
k=(8-ob->query("rank"))*2+4;
s=(8-ob->query("rank"))*1+7;
while(i--)
   {if (list[i]->query("id")=="junling" 
        && list[i]->query("owner")== ob->query("id")
    && (int)list[i]->query("sha_3")==1 ) 
 {command("say 兄弟们，官兵来攻打山寨了，快来杀啊！");
                   list[i]->set("sha_3",0);
        while(k--)  {                       aim=new(__DIR__"luo");
           aim->set("time",list[i]->query("time"));
               aim->move(environment(this_object()));
                                    }
                         }
            }
   }
 }
