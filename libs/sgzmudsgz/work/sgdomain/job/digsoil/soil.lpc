// soil by fire :)
// this is used for the job of 锄地
#include <mudlib.h>
inherit OBJ;
inherit M_DIGGABLE;
inherit M_INPUT;
string *desc = ({"一片土地，应该可以耕作。\n"+
"看来地需要锄锄草。(dig soil with chu tou)\n",
"土地已经旱透了，看来需要浇些水。(turn mu tong)\n",
"土地看上去很肥沃的样子，种上庄稼明年一定有好的收成。\n",});
int status; // 0-20 weed 21-40 need water 41- good
int touch;
void setup()
{
        set_id("soil", "一片土地");
	add_id("tu di");
        set_in_room_desc("一片土地(soil)");
        status = 0;
        touch=0;
        call_out("decay", 10);
      set_clean_up(1);
}
int query_status()
{
  return status;
}
string long()
{
   if(status<21)
     return desc[0];
   if(status<41)
     return desc[1];
   return desc[2];
}
void decay()
{
     call_out("decay",30);
     touch=touch-1;
     if(touch<0)
        touch=0;
     if(touch)
        return;
     status=status-2;
     if(status<0)
       status=0;
     tell_environment(this_object(),"长时间无人打理，土地开始荒芜了。\n");
}
void dig(object o)
{
   if(touch==14)
   {
      write("地刚打理过，要稍微等一下。\n");
      return;
   }
   touch=14;
   if (status<21)
   {
        int m_hp;
        m_hp=this_body()->query_cur_hp();
        if (m_hp<10)
        {  write("你太累了，休息一会儿吧。\n");
           return;
        }
        m_hp-=5;
        this_body()->set_chr_hp(m_hp);
        status=status+random(10)+2;
        this_body()->simple_action( ({"$N拿起锄头锄了锄草，这片地看上去好多了。",
"$N一锄头锄了下去，正砸中一块石头，震得双手发麻。",
"$N一锄头锄了下去，不小心砸到脚上，疼的$n嗷嗷怪叫。"}) );
   }
   else
      write("现在已经不需要锄地了。\n");
}
int is_digable()
{
	return 1;
}
int water()
{
   if(touch==14)
   {
      write("地刚打理过，要稍微等一下。\n");
      return 0;
   }
   touch=14;
   status=status+random(10)+2;
        this_body()->simple_action( ({"$N浇了一桶水，土地看起来润泽了许多。",
"$N一桶水泼出去，没想到溅了自己一身泥。"}) );
    if(status>40) {
        if(this_body()->query_job("digsoil","beg_time"))
        {
           this_body()->set_job("digsoil","status","done");
                write("地已经搞好了，快去领钱吧。\n");
        }
    }   
   return 1;
}
void set_status(int i)
{
   status=i;
}
int query_clean_up() {
   return 1;
}
