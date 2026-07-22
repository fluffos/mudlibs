

varargs int can_use(object me, object victim, object weapon)
{
	return 1;
}

string *defense_msg = ({
 "%s ",      
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
tell_object(me,"hit=");
tell_object(me,hit);
   	return 0;
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
tell_object(me," pen=");
tell_object(me,pen);
   	return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
tell_object(me," dam=");
tell_object(me,damage);
   	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
	return defense_msg[random(sizeof(defense_msg))];
}
