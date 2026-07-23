#include <ansi.h>
#include <room.h>
inherit ROOM;
string *banned_cast=({"escape","chuqiao","jieti","tudun","shuidun","yinshen","sheqi"});
void init()
{
  add_action("do_cast",({"cast","perform","exert"}));
        add_action("do_quit", "quit");   
        add_action("do_ji", "ji");     
        add_action("do_fly", "fly");    
}
int do_quit(string arg)
{
        if(this_player()->query_temp("husong_rob")){
                write(HIR"\n你不能在这里退出。\n"NOR);
       return 1;
        }
        else return 0;
}
int do_ji(string arg)
{
        if(this_player()->query_temp("husong_rob")){
                write(HIR"\n你不能在这里使用法宝。\n"NOR);
       return 1;
        }
        else return 0;
}
int do_fly(string arg)
{
        if(this_player()->query_temp("husong_rob")){
                write(HIR"\n你不能在这里自由飞翔。\n"NOR);
       return 1;
        }
        else return 0;
}

int do_cast(string arg) {
    if(!arg) return 0;
    if(member_array(arg,banned_cast)==-1 ||
        !this_player()->query_temp("husong_rob") )
        return 0;
    write(HIR"你无法这里使用"NOR+HIG+arg+NOR+HIR"。\n"NOR);
    return 1;
}
int valid_leave(object me, string dir)
{
  object ob;
  if(me->query_temp("husong_rob") )
    { 
      tell_object(me,HIR"强盗在逃亡,我们得快快寻找.\n"NOR);
      if(objectp(present("hubiao biaoshi",this_object())) 
           ||objectp(present("qiang dao",this_object())) 
           ||objectp(present("gongsun xiansheng",this_object())) ){
               return notify_fail(HIR"不好,这里还有事情未了！\n"NOR);  
        }
      if(me->query_temp("husong_where")) 
    if(random(3)==1)  tell_object(me,HIR"似乎商队已经逃往"+me->query_temp("husong_where")+"。\n"NOR);
        }
      return ::valid_leave(me, dir);
}

