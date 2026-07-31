// xikou.c 溪口
// Modify By River@SJ 99.06
#include <ansi.h>
#include <wanted.h>

inherit ROOM;
void create()
{
        set("short", "溪口");
        set("long", @LONG
你迎着阵阵海风来到了溪口，这里是自古代以来兵家必争之地，这里连接
着与海外的贸易，岸边停泊着的几艘大帆船在夕阳的照射下，船帆显得分外美
丽。岸边有几个老艄公正等着拉客人，也许你上前询问一下就能雇船出海。
LONG);
	set("outdoors", "宁波");
	set("exits",([
		"west" : __DIR__"aywsi",
		"south" : __DIR__"dongqianhu",
	]));
	set("objects",([
		"/d/mingjiao/npc/shao"  :   1,
	]));       
	setup();
}

void init()
{
	if (is_wanted(this_player())) return;
	add_action("do_yell", "yell");
	add_action("do_enter", "enter");
}

int do_yell(string arg)
{
        object ob,me, obj;
        me = this_player();

        if (!arg) return 0;
        if (arg == "chuan"){
             message_vision("$N对着海船叫了一声：“船家，出海！”\n", me);
             if(!me->query_temp("haichuan_paid")){
                 message_vision("海船上的艄公对$N理都不理。\n", me);
                 return 1;
             }
             if(query("boat_on_sea")) return notify_fail("海船上的艄公说道：正等着你呢，上来吧。\n");
             if(!objectp(obj = present("shao gong", environment(me))) || !living(obj))
                       return notify_fail("你在这里空着急，却没人给你召唤一只海船过来。\n");
             message_vision("艄公点点头，招来一只海船，说对$N道：船已经来了，上去(enter)吧。\n\n", me);
             ob=new("/clone/misc/boat1");
             ob->set("boat_of", "/d/ningbo/xikou");
             ob->set_temp("stepw", 14);
             ob->set_temp("steps", 14);
             ob->move("/clone/misc/sea");
             set("boat_on_sea", 1);
             return 1;
        }
        else message_vision("$N对着大海大叫一声：“" + arg + "～～～”\n", me);      
        return 1;
}

int do_enter()
{
        object me, sea, *inv;
        int i;
        me = this_player();
        
        if(!query("boat_on_sea")) return 0;
        if(!(sea = find_object("/clone/misc/sea")))
             sea = load_object("/clone/misc/sea");
        if(sea = find_object("/clone/misc/sea")){
             inv = all_inventory(sea);
             for(i= 0;i< sizeof(inv);i++){
                   if(inv[i]->query("boat_of") == base_name(this_object())){
                          message_vision("$N象猴子一样蹦得老高，两下就窜上了帆船。\n\n", me);
                          me->move(inv[i]);
                          message("vision",me->name()+"象猴子一样蹦了上来。\n",environment(me), ({me}) );
                          return 1;
                   }
             }
        }
        else write("sea boat error, please call wizard. \n");
        return 1;
}