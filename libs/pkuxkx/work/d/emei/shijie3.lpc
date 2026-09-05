// Room: /u/cuer/emei/shijie3.c
                           
#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", RED"解剑石"NOR);
set("outdoors","emei");
	set("long",
"这里是峨眉山脚下著名的"RED"解剑石"NOR"。在石阶的旁边立\n"
"着一块巨大的石块，上面锩刻着"RED"“解剑石”"NOR"三个大字。\n"
RED"解剑石"NOR"的旁边站着几个峨嵋女弟子在检查过往行人。\n"
         );
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie1",
  "northup" : __DIR__"gchang",
           ]));

        set("objects",([
            __DIR__"npc/shoushan" : 2,
               ])); 	

	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability"))
        return ::valid_leave(me, dir);  
    if( dir != "northup" || (string)me->query("family/family_name") == "峨嵋派" 
        || !(me->query_temp("weapon") || me->query_temp("secondary_weapon")))
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shoushan dizi" )
            return notify_fail("守山弟子说: 峨嵋非行凶之地，施主想要上山请解兵器。\n");
    }            
    return ::valid_leave(me, dir);
}
