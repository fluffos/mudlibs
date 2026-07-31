// this npc will duplicate anyone who he/she lost his fight to....
#include <ansi.h>
#define CHAMPION_FILE "/data/npc/champion.o"
inherit NPC;
void loadall(object me);
string id1;
void find(string id);
void changeshape(object winner);
void create()
{
	string info,name,id,file;
        set_name( "盟主" , ({ "numberone" }) );
	setup();
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
                this_object()->set_max_encumbrance(100000000);
        this_object()->clear_condition();
        set("title", HIC "正派盟主" NOR);
	carry_object("clone/weapon/gangjian")->wield();
	carry_object("clone/misc/cloth")->wear();
	
}
	
		
}
void lose_enemy(object winner)
{
	remove_call_out("changeshape");
	if (userp(winner))
	call_out("changeshape",2,winner);
	return;
}
void changeshape( object winner)
{
	string winner_file;
	object zheng;
	string name,id,nick;
	int i;
	  if (!userp(winner))
        return notify_fail("你不是玩家，是机器人.\n");
	winner_file = winner->query_save_file();
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s从现在开始是我们新的正派盟主了！！ \n",
        winner->name(1)));
	write_file(CHAMPION_FILE,sprintf("%s %s %s",
	winner_file,winner->query("id"),winner->query("name")),1);
	restore_object(winner_file);
	name = winner->query("name");
	id = winner->query("id");
	set_name( name , ({ id }) );
	nick = winner->query("nickname");
	delete("env");
	set("attitude", "aggressive");
	reset_action();
	delete_temp("already_loaded");
	loadall(this_object());	
	set("title", HIC "正派盟主" NOR);	
	set("nickname",nick);
//	delete("party");
	zheng = new(__DIR__"zheng");
	find(id);
	zheng->move(winner);
	message_vision("正派盟主给了$N一根神杖。\n",winner);
if (winner->query("jinyong/all",1)==1)
{
message("channel:chat", HIC"【江湖传闻】"GRN + winner->query("name")+"完成了所有主线任务成为正派盟主 得到了奖励。！\n"NOR,users() );
	message_vision("$N得到替身娃娃十个。\n",winner);
	message_vision("$N得到锻炼石一套共四个。\n",winner);
winner->set("jinyong/all",2);	
                        for (i = 0; i < 10; i++)
                        {
                                zheng = new("/clone/buy/tishenwawa");
                                zheng->move(winner, 1);
                        }
                                zheng = new("/clone/buy/dzshi");
                                zheng->move(winner, 1);                        
                                zheng = new("/clone/buy/dzshi2");
                                zheng->move(winner, 1);                                  
                                zheng = new("/clone/buy/dzshi3");
                                zheng->move(winner, 1);                                                                  
                                zheng = new("/clone/buy/pzshi");
                                zheng->move(winner, 1);      

}
	winner->set("marks/mengzhu",1);
	   
return;
}

void loadall(object me)
{
        int MAX = 3;
        string name,id, *created;
        int i,j;
        object thing, *inv;
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        destruct(inv[i]);
                }

        id = me->query("id");
        created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
        for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
        if( sscanf(created[j], "%s.c", name) == 1 )
                {
	thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id +
 	"/" + name + ".c");
                        if(thing->move(me)) 
			{
			thing->wield();
			thing->wear();
			} 
                }
	me->reset_action();
        me->set_temp("already_loaded",1);
	return;
}
void init()
{	add_action("do_yao","yaozhang");
	if(!query_temp("already_loaded"))
		loadall(this_object());
	return;
}
int accept_fight(object me)
{
	return 1;
}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;
        if (!userp(ob)) return;
	changeshape(ob);
	return;
}
int do_yao()
{
	object zhang,me,ob;
	me = this_player();
	ob = this_object();
	zhang = new(__DIR__"zheng");
	if(ob->query("id")==me->query("id") && (!present("shenstaff",me)))
	{find(id1);
	zhang->move(me);
	message_vision("$N给了$n一根神杖。\n",ob,me);
	me->set("party/party_name",HIC+"正派"+NOR);
	me->set("party/rank",HIC+"盟主"+NOR);
	return 1;
	}
tell_object(me,"你瞎要什么？\n");
return 1;
}
void find(string id)
{
object *ulist,*ilist;
object ob;
int i,j;
ulist  =  users();
	i  =  sizeof(ulist);
while (i--) {
	//if(ulist[i]->query("id")== id ) {
	if  (present  ("shenstaff",ulist[i]))
	{
	ilist  =  all_inventory(ulist[i]);
	j=sizeof(ilist);
	while (j--) {
	ob = ilist[j];
	if(ob->query("id")=="shenstaff" && !userp(ob))
	{
	destruct(ob);
			}
	}
message_vision(HIY"$N身上的神杖化作一道金芒飞向了远方。\n"NOR,ulist[i]);
//ulist[i]->set("party",0);
	}
}
}
