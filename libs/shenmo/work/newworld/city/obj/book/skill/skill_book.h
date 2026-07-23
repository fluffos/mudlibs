void init()
{
add_action("do_xue","read");
}

int do_xue(string arg)
{
int lvl;
object me=this_player();
object book=this_object();
string skill=(string)book->query("skill/type");
lvl=me->query("level");

if ( !present(book,me) || !arg  || arg!="book" )
	return notify_fail(CYN"\n你想学习什么技能？\n"NOR);

if ( lvl< book->query("level") )
	return notify_fail(CYN"\n你的等级不够，不能学习这上面的技能！\n"NOR);

if ( (int)me->query_skill(skill) )
	return notify_fail(CYN"\n你已经学了这种技能了！\n"NOR);
me->set_skill(skill,1);
tell_object(me,HIY"\n你学得了"+book->query("skill/name")+"！\n"NOR);
destruct(book);
return 1;
}


