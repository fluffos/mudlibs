int block_cmd(string args);

void water(object me)
{
string msg;
if (!me)
{
    return;
}
msg=HIG"一阵急流涌过,"NOR;
if ( !userp(me) )
	{
	msg += HIG"$N"HIG"惨叫一声,被水流冲走了!\n"NOR;
	destruct(me);
	}
if ( me->query("sds4/yi")!="done" )
	{
	msg += HIG"$N"HIG"没有提防,被水流冲走了!\n"NOR;
	me->move("/d/sds4/ice/ice_sea");
	msg += HIY"天空传来一声怒吼,“想搞破坏！”说罢将$N丢将下来!\n"NOR;
	me->unconcious();
	}
switch (random(4))
	{
	case 0:
		{ msg+=HIG"$N"HIG"被冲得打了个趔趄！\n"NOR; break; }
	case 1:
		{ msg+=HIG"$N"HIG"勉强在水流中站稳脚步！\n"NOR; break; }
	case 2:
		{ msg+=HIG"$N"HIG"给冲得直皱眉头......\n"NOR; break; }
	case 3:
		{ msg+=HIG"$N"HIG"在急流中狼狈不堪！\n"NOR; break; }
       }
if( me->query("kee") > 55)
    me->add("kee",-35-random(20));
if(me->query("sen") > 55)
    me->add("sen",-35-random(20));
message_vision(msg,me);
if ( present(me,this_object()) && !wizardp(me) )
   call_out("water",2+random(2),me);
}

void init()
{
object me = this_player();
add_action("block_cmd", "", 1);
call_out ("water",random(2)+1,me);
}

int block_cmd(string args)
{
string verb;
 verb = query_verb();
if ( verb == "cast" || verb == "get" || verb == "drop" || verb == "recall") 
	return 1;
return 0;
}


