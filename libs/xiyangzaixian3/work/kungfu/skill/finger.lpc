// staff.c

inherit SKILL;
int valid_selflearn(object me) {
        return 1;
}

int selflearn_skill(object me) { 
        if ((int)me->query("jing")<10) return 0;
	me->add("jing",-10);
        me->add("eff_jing",-10);
        return 1;
}
