inherit ITEM;

void create()
{
	set_name("易筋石" , ({ "powerstone" }) );
        set_weight(600);
        set("unit", "块");
        set("long", "这是一块载有绝世神功，达摩易筋术，的易筋石．\n");
        set("value", 0);
}

void init()
{
        add_action("setskillss", "setski");
        add_action("setattss", "setatt");
	add_action("setdefaultss", "setdef");
}
int setskillss ( string arg)
{
	object me;
	string skilltype, skilllevel;
	int ski;
	me = this_player();		
        if(!arg) return notify_fail("Usage: setski skilltype skilllevel\n");
        if( sscanf(arg, "%s to %s", skilltype, skilllevel)==2
        || sscanf(arg, "%s %s", skilltype, skilllevel)==2 );
        else return notify_fail("Usage: setski skilltype skilllevel\n");
	ski = atoi(skilllevel);
	me->set_skill(skilltype , ski);
	tell_object(me, "Set your " + skilltype + " to " + skilllevel + "\n");
	return 1;
}
 
int setattss ( string arg)
{
        object me;
        string atttype, attlevel;
        int ski;
        me = this_player();
        if(!arg) return notify_fail("Usage: setatt atttype attlevel\n");
        if( sscanf(arg, "%s to %s", atttype, attlevel)==2
        || sscanf(arg, "%s %s", atttype, attlevel)==2 );
        else return notify_fail("Usage: setatt atttype attllevel\n");
        ski = atoi(attlevel);
        me->set(atttype , ski);
        tell_object(me, "Set your " + atttype + " to " + attlevel + "\n");
        return 1;
}
int setdefaultss( )
{
	object me;
	me = this_player();
	me->set("max_gin", 3000);
        me->set("max_kee", 99999);
        me->set("max_sen", 3000);
        me->set("eff_gin", 3000);
        me->set("eff_kee", 99999);
        me->set("eff_sen", 3000);
        me->set("gin", 3000);
        me->set("kee", 99999);
        me->set("sen", 3000);
        me->set("max_atman", 300);
        me->set("atman", 300);
        me->set("max_force", 300);
        me->set("force", 300);
        me->set("max_mana", 300);
        me->set("mana", 300);
	me->set("water", me->max_water_capacity());
        me->set("food", me->max_food_capacity());
	me->set("combat_exp", 1000);
	me->set_skill("unarmed", 30);
        me->set_skill("dodge", 30);
        me->set_skill("force", 30);
        me->set_skill("literate", 30);
        me->set_skill("parry", 30);
        me->set_skill("sword", 30);
        me->set_skill("blade", 30);
        me->set_skill("hammer", 30);
        tell_object(me, "DONE! \n");
	return 1;
}

