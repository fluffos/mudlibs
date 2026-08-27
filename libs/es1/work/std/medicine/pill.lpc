//#pragma save_binary

#include <mudlib.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set("can_eat", 1);
	set("unit", "粒");
}

void set_healing(int heal)
{
	if( heal < 1 ) return;
	set("healing", heal);
}

void init()
{
	medicine::init();
}

void eat(object me)
{
	int i, heal, med, med_res, percent, times, max, tmp;
	
	heal = query("healing");
	if( !med = (int)query("medication") ) med = heal;
	med_res = (int)me->query("medication_resistance");
	max = (int)me->query("critical_med_res");
	if( (tmp=(int)query("effect_critical")) > 0 )
		max = max * tmp / 100;

	// is my body resist the medication? heal points down?
	if( med_res > max ) {
		percent = 2;
		times = ( med_res - max ) / med;
		if (times> 7) times=7;
		for( i=0; i<times; i++ ) percent *= 2;
		heal /= percent;
	}
	me->receive_healing( heal );
}
