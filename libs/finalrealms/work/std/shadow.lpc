/* Standard shadow thingies */

nosave object owner;

void start()
{
 shadow(owner, 1);
 call_out("wear_off", 50);
}

void wear_off(object me)
{
 tell_object(owner, "Your spell wears off.\n");
 destruct(this_object());
}

int dispell()
{
 tell_object(owner, "A Dispell Magic dispelled your spell.\n");
 tell_object(environment(owner), owner->query_cap_name()+"'s spell is dispelled.\n");

 wear_off(owner);
 return 1;
}
