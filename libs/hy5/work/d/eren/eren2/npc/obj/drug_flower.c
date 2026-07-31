 inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"七心海棠叶"NOR,({ "haitang" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",1000);
                set("unit","片");
                set("long", HIG
"说起毒物，世人只知鹤顶红、孔雀胆、墨蛛汁、腐肉膏、彩虹菌、
碧蚕卵、蝮蛇涎、番木鳖、白薯芽等等，其实最可怕却是这七心海棠。
这毒物无色无臭，无影无踪。若是求生无望，求死无门，还不如就
此。。。。。（ｄｉｅ）\n"NOR);
                }
} 
void init()
{
  if(this_player()==environment())
        add_action("do_cure","die");
} 
int do_cure()
{
        object me,room, death_room,corpse;
        me = this_player();
        message_vision("$N把七心海棠叶一口吞了下去！\n",me);
        room = environment(me);
        if(objectp(corpse = CHAR_D->make_corpse(me, me)))
                corpse->move(room);
        death_room = find_object("/d/eren/chunliuju1");
        if(!objectp(death_room))
                death_room = load_object("/d/eren/chunliuju1");
        if (me->query("combat_exp")>2000)
                me->add("combat_exp",-2000);
                else me->set("combat_exp",0);
        tell_object(me,"你觉得自己的肌肉僵硬，脑子也不听使唤了。\n");
        message_vision("$N死了。\n",me);
        me -> unconcious(); 
        me->move(death_room);
   destruct(this_object());     
        return 1;
}   
