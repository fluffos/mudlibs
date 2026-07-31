#include <ansi.h>
inherit ROOM;

void create ()
{
set ("short", "战斗区");
set("no_quit",1);
//set("broadcast",1);
set("no_flee",1);
set("alternative_die",1);
set("objects",([
   "/u/snowtu/npc/zzpfm_npc"  : 1,
]));
set("exits",([
        "out"  : (({"/d/city/kezhan","/d/city/center",})[random(2)]),
]));
setup();
}

void alternative_die (object me)
{
object ob;
me->powerup();
me->clear_condition();
me->remove_all_killer();
all_inventory(environment(me))->remove_killer(me);
message_vision ("\n$N「啪」的一声倒在地上，挣扎着抽动了几下就死了。\n\n",me);
message_vision ("地下传来崔判官的声音：切磋之争，不伤阳寿！\n",me);
message_vision ("\n$N慢慢从地上爬将起来。\n",me);
}

int do_full(string arg)
{
object who,me=this_player();
if ( !wizardp(me) ) return 0;
if ( !arg )  arg = me->query("id");
who = present(arg,this_object());
if ( !who )   return 0;
who->powerup(1,1);
write("ok\n");
return 1;
}

void init()
{
add_action("do_halt","quit");
}

void broadcast(string str)
{
string prefix = "";
string s1 = str, s2 = "";
while (strsrch(s1,"\n\n") != -1)
        s1 = replace_string(s1,"\n\n","\n");
if (s1[strlen(s1)-1]=='\n')
        {
        s1 = s1[0..strlen(s1)-2];
        s2 = "\n";
        }
if (strlen(s1) == 0)
        return;
s1 = replace_string(s1,"\n","\n"+prefix)+"";
reset_eval_cost();
tell_room( "/d/city/entrance",NOR HIR"\n【战斗区】"NOR CYN+prefix+s1+"\n"NOR );
}

int do_halt()
{
object me = this_player();
message_vision("$N眼见前途未卜，顿生退意。。。。",me);
if ( me->move("/d/city/kezhan",1) )
        message_vision("$N立即退出了战斗区。\n",me);
message_vision("\n",me);        
return 1;
}               
