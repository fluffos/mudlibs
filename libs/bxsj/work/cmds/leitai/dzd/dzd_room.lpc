#include <ansi.h>

#define BACK_ROOM "/d/foshan/dukou"

inherit ROOM;

void backhome(object ob);

void init()
{
	object me = this_player();
	if(!mapp(me->query_temp("job_xkd"))) backhome(me);
}

void remove(string euid)
{
	object* obs = all_inventory(this_object());
	//obs = filter_array(obs,(:userp($1):));
	if(!sizeof(obs)) return;
	for(int i=0;i<sizeof(obs);i++) 	backhome(obs[i]);
}

void get_item(object me)
{
	object* items = deep_inventory(me);
        for(int i=0;i<sizeof(items);i++)
        	if( items[i]->query("dzd_obj") ) destruct(items[i]);
}

void backhome(object ob)
{
	if(!userp(ob)) return;
	ob->delete_temp("job_xkd");
	if(query("short")=="小船") tell_object(ob,RED"你只觉得天昏地暗，整座小船都在往下沉。\n\n"NOR);
	else tell_object(ob,RED"你只觉得天昏地暗，整座小岛都在往下沉。\n\n"NOR);
	tell_object(ob,HIB"冥冥之中，好象有人在对你招手……………………\n\n"NOR);
	//about no_pk
	if(ob->query("dzd_no_pk")){
		ob->set("no_pk",ob->query("dzd_no_pk"));
		ob->delete("dzd_no_pk");
	}
	get_item(ob);	
	ob->move(BACK_ROOM);
	tell_object(ob,"\n突然之间，你发现自己已经回到了"+environment(ob)->query("short")+NOR"，难道今天睡过头了？\n");
}
