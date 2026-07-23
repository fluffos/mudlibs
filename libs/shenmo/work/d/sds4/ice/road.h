int block_cmd(string args);

void ice(object me)
{
if (random(4) == 0)
	{
	object ob;
	object *inv = all_inventory(me);
	if (sizeof(inv) == 0)
		return;
	ob = inv[random(sizeof(inv))];
	if ( !present("aoding baoshi",me) )  //身上没奥丁宝石
		{
		if (ob->move(this_object()) )
			{
			message_vision(HIW"\n四周寒意愈来愈浓,只听啪的一声，$N"HIW"的$n"HIW"顿时冻裂成冰珠！\n"NOR,me,ob);
			destruct(ob);
			}
		}
	}
else   {
	switch (random(4))
           {
		case 0:
		{ message_vision(HIW"\n$N"HIW"的脸上结了一层厚厚的霜冰！\n"NOR,me); break; }
		case 1:
		{ message_vision(HIW"\n$N"HIW"在被飕飕寒风激起了个冷战！\n"NOR,me); break; }
		case 2:
		{ message_vision(HIW"\n$N"HIW"“阿嚏”一声，鼻涕横流！\n"NOR,me); break; }
		case 3:
		{ message_vision(HIW"\n$N"HIW"给冻得在风雪中不住的跺脚！\n"NOR,me); break; }
           }
	if(me->query("kee") > 55)
	    me->add("kee",-35-random(20));
	if(me->query("sen") > 55)
	    me->add("sen",-35-random(20));
	}
}

void init()
{
object me = this_player();
add_action("block_cmd", "", 1);
if (!me || me->query("ice/number")>=10 || environment(me) != this_object() || ( !userp(me)&&me->query("id")=="freya" ) )  //过了的，不会起作用
	return;
if ( !userp(me) && me->query("id")!="freya" ) 
	{
	message_vision(HIW"\n一阵狂风卷起,$N"HIW"身不由己的随咆哮的风雪扶摇直上! \n"NOR,me);
	me->die();
	}
if ( !(int)me->query("sds3/all") )    //12gong没过
	{
	message_vision(HIW"\n一阵狂风卷起,"HIW"$N身不由己的随咆哮的风雪扶摇直上! \n"NOR,me);
	me->move("/d/city/kezhan");
        message_vision(HIW"\n一阵冰冷的风夹带着冰凌呼啸而过,一个人影踉跄着走了过来,正是$N!"NOR,me);
	me->unconcious();
	}
if ( (int)me->query("bellicosity")>(int)me->query("force")/2 )
        {
        message_vision(HIR"\n$N"HIR"杀气太高,不适宜待在奥丁领域！\n"NOR,me);
        me->move("/d/city/kezhan");
message_vision(HIW"\n一阵冰冷的风夹带着冰凌呼啸而过,一个人影踉跄着走了过来,正是$N!"NOR,me); 
        }
call_out ("ice",random(2)+3,me);
}

int block_cmd(string args)
{
string verb;
 verb = query_verb();
if ( verb == "cast" || verb == "get" || verb == "drop" || verb == "recall") 
	return 1;
return 0;
}


