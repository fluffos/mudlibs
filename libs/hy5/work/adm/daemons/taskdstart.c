// autosaved.c
// file:                Autosave daemon
// creator:     ken
// date:                98-2-23

// for autosave players data file.
#include <ansi.h>

inherit F_DBASE;

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "任务精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "随机任务系统已经启动。\n");
        call_out("auto_save", 28);
}

void auto_save()
{
 "/adm/daemons/taskd"->create();
}