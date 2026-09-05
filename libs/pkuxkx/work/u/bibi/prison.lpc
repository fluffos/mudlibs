inherit ROOM;
void create()
{
set("short","梦乡");
set("long","白蒙蒙的一片，这里到底是什么地方呢？\n该不会是监狱吧？！\n");
set("valid_startroom",1);
}
void init()
{
this_player()->set("startroom", "u/bibi/prison");
this_player()->set("food",0);
this_player()->set("water",0);
this_player()->set("jing",0);
this_player()->save();
add_action("do_punish","chat");
add_action("do_punish","chat*");
add_action("do_punish","rumor");
add_action("do_punish","rumor*");
add_action("do_punish","tell");
add_action("do_punish","say");
add_action("do_punish","lian");
add_action("do_punish","practice");
add_action("do_punish","study");
add_action("do_punish","du");
add_action("do_punish","dazuo");
add_action("do_punish","exercise");
add_action("do_punish","suicide");
add_action("do_punish","respirate");
add_action("do_punish","'");
add_action("do_punish","mp");
add_action("do_punish","ct");
add_action("do_punish","vote");
add_action("do_punish","reply");
add_action("do_punish","quit");
}
int do_punish()
{
   if( wizardp(this_player())) return 0;
 tell_object(this_player(), "省省吧，谁叫你不听话呢！\n");
 return 1;
}
