int do_cast(string arg)
{
string dir;
object me = this_player();

if( sscanf(arg, "shou on %s", dir)==1 
  ||sscanf(arg, "huimeng on %s", dir)==1 
  ||sscanf(arg, "shiyue on %s", dir)==1  
  ||arg=="huimeng"
  ||arg=="chuqiao"
  ||arg=="shiyue" 
  ||!arg        
  ||arg=="yinshen" )  //容易引起bug的法术限制使用，欢迎补遗...
        {
        tell_object(me,"你结结巴巴的念动了几句咒语......还是算了......\n");
        return 1;
        }
return 0;
}

int do_none()
{
message_vision("赶紧去保护雅典娜！\n",this_player());
return 1;
}

int do_pfm( )
{
int i;  // pfm所发成功率
object where,me;

where=this_object();
me=this_player();
i=where->query("num");

if ( !i ) i=random(10);

if ( random(i)<5 )
        {
        message_vision("$N想用外功制敌，可惜修为不够，失败了。\n",me);
        return 1;
        }
else    return 0;
}

void init()
{
object me = this_player();
add_action("do_cast", "cast");
add_action("do_pfm", "perform");
add_action("do_none", "recall");
add_action("do_none", "whisper");
add_action("do_none", "surrender");
add_action("do_none", "bian");
add_action("do_none", "get");
add_action("do_none", "give");
add_action("do_none", "move");
add_action("do_none", "burn");

if ( (int)me->query_temp("yinshentime") )
        {
        me->delete_temp("yinshentime");
        me->delete("env/invisibility");      
        me->save();
        me->delete_temp("no_heal_up/yinshen");
        message_vision(HIW"\n白光闪过之后，$N又现出了身形。\n\n"NOR, me);
        }
if ( me->query("sds4/king")!="done" & userp(me) )
        {
        message_vision(HIY"“圣域现在有事发生，你还是回吧！”\n"NOR,me);
        me->move("/d/city/kezhan");
        message_vision(HIY"白光有一闪，$N出现在大家的面前，世界真奇妙！\n"NOR);
        me->unconcious();       
        }
return;
}


