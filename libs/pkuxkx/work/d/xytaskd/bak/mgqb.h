
int die()
{
object me,xytaskd;
if(query("victory"))
{
message_vision(this_object()->query("name")+"死了\n",this_object());
destruct(this_object());
return 1;
}
me=this_object()->get_damage_origin_object();
//if(!me) me=offensive_target(this_object());
if(!me) me=this_player();
xytaskd=load_object("/adm/daemons/xytaskd.lpc");
if(query("taskid")!=me->query_temp("xytaskd/taskid"))
me->delete_temp("xytaskd");
me->add_temp("xytaskd/number",1);
me->set_temp("xytaskd/taskid",xytaskd->query("taskid"));
//::die();
message_vision(this_object()->query("name")+"死了\n",this_object());
if(random(10)==0&&me) 	
{
	if(me->query("qi")>=me->query("max_qi"))
	{
		switch(random(6)){
		case 0:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌让敌人闻风丧胆!\n"NOR,users());
			break;
		case 1:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳取敌首级如探囊取物!\n"NOR,users());
			break;
		case 2:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳中战功赫赫!\n"NOR,users());
			break;
		case 3:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳中独当一面!\n"NOR,users());
			break;
		case 4:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌锐不可当!\n"NOR,users());
			break;
		case 5:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌数以万计!\n"NOR,users());
			break;
		default :
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳有万夫不当之勇!\n"NOR,users());
		}
	}
	else if(me->query("qi")>=me->query("max_qi")/4*3)
	{
		switch(random(3)){
		case 0:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌勇猛无比!\n"NOR,users());
			break;
		case 1:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳以一敌十!\n"NOR,users());
			break;
		default :
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳打败敌军!\n"NOR,users());
		}
	}
	else if(me->query("qi")>=me->query("max_qi")/2)
	{
		switch(random(3)){
		case 0:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌战袍都染红了!\n"NOR,users());
			break;
		case 1:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳杀敌无数!\n"NOR,users());
			break;
		default:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳誓死卫国，力拒敌兵!\n"NOR,users());
		}
	}
	else
	{
		switch(random(3)){
		case 0:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳带伤杀敌，令人敬佩!\n"NOR,users());
			break;
		case 1:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说"+me->query("name")+HIM"在襄阳置生死于度外，杀敌无数!\n"NOR,users());
			break;
		default:
                        message( "channel:" + "baowei",HIM + "【襄阳传闻】" + "据说已经分不清楚"+me->query("name")+HIM"脸上那些血是自己的，那些血是敌人的了!\n"NOR,users());
		}
	}
}
destruct(this_object());
return 1;
}
/*
int unconcious()
{
die();
return 1;
}
*/
int des()
{
destruct(this_object());
return 1;
}
