// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// arearoom.c

#pragma save_binary

#include <ansi.h>

inherit ROOM;
inherit F_OBSAVE;

string query_save_file();

int is_area_room() { return 1; }

int restore()
{
        // this object (/inherit/room/arearoom) doesn't need to save
        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

        return ::restore();
}

int save()
{
	int res;

        // this object (/inherit/room/arearoom) doesn't need to save
        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

	return ::save();
}

void setup()
{
        ::setup();
        restore();

        return 0;
}

void remove()
{
        save();
}

mixed save_dbase_data()
{
        mapping data;
        
        data = ([ "bunch" : query("bunch") ]);                  

        return data;
}

int receive_dbase_data(mixed data)
{
        int i;

        if (! mapp(data))
                return 0;

        if (mapp(data["bunch"]))
                set("bunch", data["bunch"]);

        return 1;
}

string long()
{
        string bunch;
        string desc;
        string ziyuan;

        desc = query("long");
        ziyuan = query("area/ziyuan");
        bunch = query("bunch/bunch_name");
        
        if (! ziyuan) return desc;
        
        if (! bunch || ! stringp(bunch))
                desc += "    这里" + ziyuan + "资源丰富可利用之做出一番事业！\n";
        else
                desc += "    这里是属于" + bunch + "的地盘，" + ziyuan + "资源正在开发中！\n";

        return desc;
}

string query_save_file()
{
        string file;
        string arg;

        file = base_name(this_object());

        if (! file || ! sscanf(file, "/d/%s", arg)) return 0;
        return DATA_DIR + file;
}

