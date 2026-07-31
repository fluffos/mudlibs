inherit ROOM;
void create ()
{
  set ("short", "民居");
 set ("long", "不大不小的一间房子，正对你是一块发黄的门板，门是虚掩着的，\n三块台阶已经上青绿了。门前只有一位老者，好象这家主人出门远行\n了。");
  set ("exits", ([]));
  set("outdoors", "xy1");
  set ("no_clean_up", 1);
  set ("sleep_room",1);
  set ("if_bed",1);
  set("exits", (["east"         : __DIR__"dingan-2",]));
  set ("objects", ([ __DIR__"npc/oldman"  : 1,]) );
  setup();
}
/*
void init()
{
object who=this_player();
if( (string)who->query("gender")=="男性" || (string)who->query("gender")=="女性" )
{
call_out("heal_up", 1, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
"你觉得浑身说不出的舒畅。\n",
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_jing", (int)who->query("max_jing"));
who->set("eff_qi", (int)who->query("max_qi"));
who->set("eff_jing", (int)who->query("max_jing"));
message_vision("一股力量涌向$N，$N深深吸了几口气。\n", who);
write("你觉得自己的精神气血一下子都恢复了。\n");
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
*/
