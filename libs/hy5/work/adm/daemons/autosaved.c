// autosaved.c
// file:                Autosave daemon
// creator:     ken
// date:                98-2-23

// for autosave players data file.
#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "内存精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "\n自动存盘系统已经启动。\n");
        call_out("auto_save", 40);
}

void auto_save()
{
        int i,mem;
        object *ob, link_ob;
        string id;
/*
        seteuid(getuid());
        ob=users();
        i=sizeof(ob);
        reclaim_objects();
        for( i=0;i<sizeof(ob);i++) {
                id = (string) ob[i]->query("id");
                if (!id) continue;
                if(!environment(ob[i]) )        continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                if( (int)link_ob->save() && (int)ob[i]->save() )
message("channel:chat", HIG"【存盘】您的档案已经自动存盘。\n"NOR,ob[i]);
                else
message("channel:chat", HIG"【存盘】您的档案已经自动存盘失败，请与巫师联系。\n"NOR,ob[i]);
        }
*/
//	CHANNEL_D->do_channel( this_object(), "sys",
//		sprintf("系统自动清除 " + reclaim_objects() + " 个变数。\n"));
        remove_call_out("auto_save");
        call_out("auto_save", 480+random(120));
}
