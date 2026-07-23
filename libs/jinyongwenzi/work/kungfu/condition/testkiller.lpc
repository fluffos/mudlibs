// killer.c

#include <ansi.h>
#define JAIL_ROOM  "/d/wizard/wizard_jail"

int update_condition(object me, int duration)
{
        object where;
        where = environment(me);
        if ((duration > 220) && (file_name(where) != JAIL_ROOM))
        {
                message_vision(HIW"\n$N杀人无数，血债难偿，官府通缉你很长时间了，这回跑\n不了了，老老实实跟我走吧。\n\n"NOR, me);
                me->move(JAIL_ROOM);
                me->set("jail_timeout_room",(string)file_name(where));
                me->set("startroom", JAIL_ROOM);
                message("channel:chat", HIC "\n【官府消息】："+(string)me->query("name")+"因为杀人如麻、罪大恶极，被捕快抓到监狱关押。\n\n" NOR, users());
                return 1;
        }
        if (duration < 1) {
                tell_object(me, "官府不再通缉你了！\n");
                return 0;
        }
        if ((duration < 100) && (file_name(where) == JAIL_ROOM))
        {
                message_vision(HIW"\n本府看$N尚有悔过之意，先准$N出去，切记不可再为非作歹，否则定不轻饶！\n\n"NOR, me);
                me->move((string)me->query("jail_timeout_room"));
                return 1;
        }
        me->apply_condition("killer", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "killer";
}
