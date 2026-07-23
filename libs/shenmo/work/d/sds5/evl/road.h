void init()
{
object me = this_player();

if ( !userp(me) ) return;

add_action("do_none","ji");
add_action("do_none","tou");
add_action("do_none","steal");
add_action("do_none","fight");
add_action("do_none","burn");
add_action("do_none","move");
add_action("do_none","accept");
add_action("do_none","touxiang");
add_action("do_none","surrender");
add_action("do_none","fang");
add_action("do_none","apply");
add_action("do_cast","cast");
add_action("do_perform","perform");
remove_call_out("evl");
call_out("evl",1,me);
}

int do_none()
{
message_vision(BLU"四下来传来隐隐的泣哭之声，叫人心神不宁....\n"NOR,this_player());
return 1;
}
        
int do_cast(string arg)
{
string dir;
object me = this_player();
if( sscanf(arg, "shou on %s", dir)==1 
  ||sscanf(arg, "huimeng on %s", dir)==1 
  ||sscanf(arg, "qiankun on %s", dir)==1  
  ||sscanf(arg, "heijie on %s", dir)==1  
  ||arg=="huimeng"
  ||arg=="qiankun"
  ||arg=="heijie"
  ||arg=="chuqiao"
  ||arg=="shiyue" 
  ||arg=="yinshen" )  //容易引起bug的法术限制使用，欢迎补遗...
        {
        tell_object(me,"你结结巴巴的念动了几句咒语......还是算了......\n");
        return 1;
        }
}

int do_perform()
{
int damage;
object me = this_player();
damage = me->query("kee")/20;
if ( random(10)==1 )
        {
        message_vision("四下来传来隐隐的泣哭之声，叫人心神不宁....\n",this_player());
        if ( damage>0 )
                {
                me->receive_damage("sen",damage);
                COMBAT_D->report_sen_status(me);
                }
        return 1;
        }
}

void evl(object me)
{
int damage;
string msg = "四下来传来隐隐的泣哭之声，叫人心神不宁...."NOR;

remove_call_out("evl");

if ( !userp(me) || !me || !present(me,this_object()) )
        return;

if ( (int)me->query_temp("yinshentime") )
        {
        me->delete_temp("yinshentime");
        me->delete("env/invisibility");      
        me->save();
        me->delete_temp("no_heal_up/yinshen");
        msg = "\n\n$N现出了身形。\n\n";
        }

if ( me->query_temp("apply/name") )
        {
        msg = "$N只觉胆裂欲碎，不由现了原形。\n"NOR;
        me->delete_temp("apply/name");
        me->delete_temp("apply/id");
        me->delete_temp("apply/short");
        me->delete_temp("apply/long");
        me->delete_temp("family");
        me->delete_temp("no_heal_up/bian");
        me->save();
        }

if ( !me->query("sds5/gift1") )
        {
        msg+= "一股浓雾卷起$N，随之消失不见了！\n";
        message_vision(msg,me);
        tell_object(me,"你还是解开了黄金圣斗士复活之谜再来吧！\n");
        me->move("/d/city/kezhan");
        message_vision(HIB"眼前蓝光一闪，$N"HIB"一回到了客栈！\n"NOR,me);
        return;
        }
else if ( !present("nvshen shengyi",me) )
        {
        msg+= "一股浓雾卷起$N，随之消失不见了！\n";
        message_vision(msg,me);
        tell_object(me,HIB"你还是将雅典娜圣衣带着再来吧！\n"NOR);
        me->move("/d/city/kezhan");
        message_vision(HIB"眼前蓝光一闪，$N"HIB"一回到了客栈！\n"NOR,me);
        return;
        }

damage = me->query("kee")/20;
damage = random(damage/2);

switch (random(10))
        {
        case 1   : msg+="$N朝周围看了看，有些疑神疑鬼....\n";damage*=3;break;
        case 2   : msg+="$N朝身后看了看，只觉背脊一阵发凉....\n";damage*=2;break;
        case 9   : msg+="$N擦擦额头的冷汗，只觉得身后凉飕飕的....\n";damage*=2;break;
        case 10 : msg+="$N头角发麻，暗自骂了声：活见鬼了！\n";damage*=3;break;
        default : msg+="\n"NOR;damage=0;break;
       }
message_vision(msg,me);
if ( damage>0 )
        {
        me->receive_damage("sen",damage);
        COMBAT_D->report_sen_status(me);
        }
call_out("evl",5+random(5),me);
}


