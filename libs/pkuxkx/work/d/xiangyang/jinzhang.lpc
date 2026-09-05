#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"蒙古金帐"NOR);
	set("long", 
YEL"这里是蒙古大汗居住的金帐，屋内陈设极其奢华。墙上还挂着一把镶满宝石的宝刀。\n"NOR
YEL"正中一张矮几，后面坐着个青年，拿着本书正向旁边站着的一个僧人和一个天竺人请教着什么。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"mgying2",
	]));

	set("objects", ([
                __DIR__"npc/qbing" : 4,
                "/d/dalunsi/npc/nimoxing" : 1,
                "/d/dalunsi/npc/daerba" : 1,
                "/kungfu/class/dalunsi/fa-wang" : 1,
                __DIR__"npc/meng" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{        
int i;
mapping armor;
string *pname;
armor=me->query_temp("armor");
if (!userp(me)) return ::valid_leave(me, dir);
if (me->query_temp("songtasks/honglusi/1/finish")&&!me->query_temp("songtasks/honglusi/leave_target_palace"))
{
	me->set_temp("songtasks/honglusi/leave_target_palace",1);
	return ::valid_leave(me,dir);
}
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
if ((armor[pname[i]])->query("id")=="menggu cloth"&&me->query_temp("citan"))  return ::valid_leave(me, dir);
}
         if (present("qing bing", environment(me))&& 
                                 (dir == "south") ||
             present("meng ge", environment(me)) && 
                                 (dir == "south") 

           )
        return notify_fail(RED"我大蒙古皇帝的金帐岂是由你说来就来说走就走的？\n"NOR);
	return ::valid_leave(me, dir);
}
void init()
{ 
int i;
mapping armor;
string *pname;
  object me = this_object();
  object mee = this_player();
        armor = mee->query_temp("armor");
        if(armor)
        {
                pname = keys(armor);
                for(i=0; i<sizeof(armor); i++)
                        if((armor[pname[i]])->query("id")=="menggu cloth" && mee->query_temp("citan"))
                                return;
        }
        mee->set_temp("杀",1);
        me->set_temp("杀",1);
        mee->set_temp("刺客",1);
        me->set_temp("刺客",1);
        return;
      

}

