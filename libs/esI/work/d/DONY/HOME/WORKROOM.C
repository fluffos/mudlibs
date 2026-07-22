#include <mudlib.h>
inherit ROOM;
int have=0;
void create()
{
	::create();
        set_short( "workroom", "工作室" );
	set_long(
                "this is a workroom\n",
                "这是宁丹的工作室\n"
                "    往北则是三大陆的传送室，往南则是宁丹的最爱\n\n"
	);
	set("light",1);
        set("trap_set",1);
	set( "exits", ([
                      "north":"/u/d/dony/home/hall.c",
                      "south":"/u/d/dony/home/idle.c",
	]) );
        set( "objects", ([
                      "uki" : "/d/eastland/beggar/monster/uki",
                  "phoenix" : "/d/eastland/story/palace/monster/phoenix",          
                  "dragon" : "/d/eastland/story/palace/monster/dragon1"
        ]) );
        set_reset(this_object(),30);
}
void init()
{
   this_player()->delete_temp("hidding");
   add_action("do_search","search");
}
int clean_up() { return 0; }
int do_search(string arg)
{
   if ( !have ) {
      write("ya\n");
      have=1;
      return 1;
   }
   return 0;
}
void reset()
{
   have=0;
   set_reset(this_object(),30);
   ::reset();
}
