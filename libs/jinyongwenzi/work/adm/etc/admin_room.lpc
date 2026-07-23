#include <ansi.h>
inherit ROOM;

string *ids = ({  }); 
int get_setup(object me);
void checking(object me);
void create()
{
        set("short", "天神的议会厅");
        set("long", "这里是"+MUD_NAME+"的天神会议室。
要给予其他人进入的权限，请使用 setup 命令，删除请用 move 命令。\n");
        set("exits", ([
               "out" : "/d/wizard/wizard_room"
        ]));
        set("no_death", 1);
        set("no_save", 1);
	set("no_fight", 1);
        setup();
}

void init()
{
       string wiz_status;
       object me;

       me = this_player();
       wiz_status = SECURITY_D->get_status(me);
       
       if( wiz_status != "(admin)" && !get_setup(me)){
       	              message_vision("\n$N偷偷溜了过来，忽然一股神力将$P传送到了时空的另一处。\n\n",me);
                      me->move("/d/city/chmiao");
                      }
       else checking(me);
       if( wiz_status == "(admin)"){
       	     add_action("do_setup", "setup");
       	     add_action("move_setup", "move");
       	     }
}

void checking(object me)
{
	object snooper;
	string wiz_status = SECURITY_D->get_status(me);
	
	if (!me || environment(me) != this_object()) return;
	else if (wiz_status != "(admin)" && !get_setup(me)){
       	              message_vision("\n忽然一股神力将$N传送到了时空的另一处。\n\n",me);
                      me->move("/d/city/chmiao");
                      }
        else if (objectp(snooper = query_snoop(me))){
                  message_vision(HIW"\n$N突然大叫了一声：我被"+snooper->short(1)+"监听了，然后就解除了监听。！\n\n"NOR, me);
                snoop(snooper);
                      }
    call_out("checking", 1, me);
}

int move_setup(string arg)
{
	object me,ob;
	int i;
	me = this_player();
	if (previous_object() && getuid(previous_object()) != ROOT_UID) return 0;
	if (!arg) return notify_fail ("嘿嘿，你准备删除谁进入这里的权限？\n");
        if (!objectp(ob = LOGIN_D->find_body(arg)))
                  return notify_fail("你准备删除谁进入这里的权限？\n");
        if (ob == me)
                  return notify_fail("你是在开玩笑吧？\n");
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==ob->query("id"))
                 	 ids = ids - ({ ob->query("id") });      	 

        write("你删除了"+ob->name()+"进入这里的权限。\n");
       
	return 1;
}

int do_setup(string arg)
{
	object me,ob;
	int i;
	me = this_player();
	if (previous_object() && getuid(previous_object()) != ROOT_UID) return 0;
	if (!arg) return notify_fail ("嘿嘿，你准备给谁进入这里的权限？\n");
        if (!objectp(ob = LOGIN_D->find_body(arg)))
                  return notify_fail("你准备给谁进入这里的权限？\n");
        if (ob == me)
                  return notify_fail("你是在开玩笑吧？\n");
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==ob->query("id"))
                 	 return notify_fail("此人已经有了进入这里的权限。\n");       	 
        
        ids = ids + ({ ob->query("id") });
        write("你给予了"+ob->name()+"进入这里的权限。\n");
       
	return 1;
}

int get_setup(object me)
{
        int i;
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==me->query("id"))
                 	 return 1;       	 
        
        return 0;
}
