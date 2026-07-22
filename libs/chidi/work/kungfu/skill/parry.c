// parry.c
inherit SKILL;
string *parry_msg = ({
        "只听见「锵」一声，被$p用手中$i格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$i架开。\n",
        "但是$n身子一侧，用手中$i格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string *no_weapon_msg = ({
        "但是被$p轻轻一推，$w失了准头，和$p的$l偏了几寸。\n",
        "$p往$N的手腕轻轻一按，结果$w偏向一边。\n",
});
string query_parry_msg(object me,object weapon)
{
    string msg;
    object my_weapon;
    
    if (!objectp(my_weapon=me->query_temp("weapon")) ){
        if (!objectp(my_weapon=me->query_temp("secondary_weapon")) ){
            if (weapon)
                return no_weapon_msg[random(sizeof(no_weapon_msg))];
            else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
        }
    }
    if (my_weapon->query("skill_type")=="throwing")
        if (weapon)
            return no_weapon_msg[random(sizeof(no_weapon_msg))];
        else
            return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
    msg=parry_msg[random(sizeof(parry_msg))];
    msg=replace_string( msg, "$i", my_weapon->name() );
    return msg;
}

