// standard bed for players.
// by mon. 3/7/97

#include <ansi.h>

inherit ITEM;

int do_bed();

void create()
{
     set_name("木床",({"home_bed"}));     
     set("short","木床");
     set("long", @LONG
一张大木床。 
LONG
     );
     set("out","/d/changan/ph");
     set("exits", ([
  		"out": this_object()->query("out"),
         ]));
     set_max_encumbrance(300000);
     set_weight(100000);
     seteuid(getuid());
     set("sleep_room",1);
     set("if_bed",1);
     set("no_fight", 1);
     set("no_magic", 1);
     set("no_get",1);
     setup();

}

void init()
{
	object me=this_player(), env=this_object();

        if(env==environment(me)) {
	  add_action("go_out", "out");
        }
}

int go_out()
{   object me=this_player();
    object out=this_object()->query("out");
    message_vision("$N掀开纱帐，从床里钻了出去。\n",me);
    me->move(out);
    tell_room(out,me->query("name")+
      "掀开纱帐，从床里钻了出来。\n",({me}));
    return 1;
}


string long()
{
string str;
object *inv,obj=this_object();
int i;
inv = all_inventory();
str = sprintf( "%s  %s\n    %s",
                obj->query("short")?(HIR"「"HIG+(string)obj->query("short")+HIR"」"NOR): "新婚木床",
                wizardp(this_player())?HIW+" - "+file_name(obj)+NOR: "",
                obj->query("long")? obj->query("long"): "\n",
        );
str += "    这里唯一的出口是 " + BOLD + "out" + NOR + "。\n";

for(i=0;i<sizeof(inv);i++)
        {
        if( !this_player()->visible(inv[i]) ) continue;
        if( inv[i]==this_player() ) continue;
        str+= "  " + inv[i]->short() + "\n";
        }
return str;
}
