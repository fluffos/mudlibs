// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼门关" NOR);
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
            "黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
        set("deathroom",1);
	set("no_fight",1);
        set("no_dazuo", "1");
        set("valid_startroom", "1");
//	set("no_clean_up", 0);
	setup();
}


void init()
{
        object me;
        me = this_player();
        if( !wizardp(me) ) {
        if (me->query_condition("poison_sandu")>1)
        {          me->apply_condition("poison_sandu",0);}
        if (me->query_condition("snake_poison")>1)
        {          me->apply_condition("snake_poison",0);}
        if (me->query_condition("wugong_poison")>1)
        {          me->apply_condition("wugong_poison",0);}
        if (me->query_condition("zhizhu_poison")>1)
        {          me->apply_condition("zhizhu_poison",0);}
        if (me->query_condition("xiezi_poison")>1)
        {          me->apply_condition("xiezi_poison",0);}
        if (me->query_condition("chanchu_poison")>1)
        {          me->apply_condition("chanchu_poison",0);}
        if (me->query_condition("poison_sandu")>1)
        {          me->apply_condition("poison_sandu",0);}
        me->set_temp("isdeads",0);
        me->delete_temp("isdeads");
        
	me->set("startroom",base_name(environment(me)));
        me->save();
	add_action("block_cmd","",1);
	}
}


int block_cmd()
{
	string verb = query_verb();
	if (verb=="who") return 0;
	if (verb=="look") return 0;
	if (verb=="skills") return 0;
	if (verb=="score") return 0;
	if (verb=="quit") return 0;
	if (verb=="hp") return 0;
	return 1;
}
