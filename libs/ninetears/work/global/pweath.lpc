/* your very own personal weather... */
#include <tiempo.h>
int wetness;

int query_wetness() { return wetness; }
void adjust_wetness(int arg) { wetness += arg; }
void set_wetness(int i) { wetness = i; }

void create() {
    this_object()->add_alias("tiempo");
    this_object()->add_alias("luna");
    this_object()->add_alias("sol");
    }

string weather_extra_look() {
    string me, oa;

	oa = (TO->query_gender() == 1) ? "o" : "a";
    /* Ghosts shouldn't be wet, nor getting wet, Baldrick, june '96 */
    if (this_object()->query_dead())
    {
	wetness = 0;
	return "";
    } 

    me = capitalize(this_object()->query_pronoun());
    if (wetness>200)
	return "Esta totalmente empapad"+oa+".\n";
    if (wetness>100)
	return me+" esta chorreando agua.\n";
    if (wetness>50)
	return me+" esta muy mojad"+oa+".\n";
    if (wetness>10)
	return me+" esta mojad"+oa+".\n";
    if (wetness>0)
	return me+" esta algo mojad"+oa+".\n";
    return "";
}

string weather_long(string str) {
    object env;

    env = environment();
    if (!env||!env->query_outside()) return "No estas en el exterior.\n";

    if (str=="sol") {
	if (!CICLO_HANDLER->query_noche()) {
	    if (CICLO_HANDLER->query_eclipse()) return "Es de dia pero el sol esta oculto tras la luna... Arrepientete de tus pecados, pues se acerca el fin del mundo!\n";
	    else return "Tienes que retirar rapidamente la mirada para no quemarte la retina.\n";
	    }
	else
	    return "El sol no suele dejarse ver de noche...\n";
	}

    if (str == "luna") {
	if (CICLO_HANDLER->query_eclipse()) return "La luna parece haber engullido al sol... Es el Apocalipsis!\n";
	if (CICLO_HANDLER->query_noche()) return "Ves "+CICLO_HANDLER->query_luna_name()+" en el cielo.\n";
	else return "La luz del sol te impide ver la luna, aunque seguramente este ahi arriba.\n";
	}
    if (str != "tiempo") return "";
    return CLIMA->query_clima_name(env->query_ajuste_clima());
}

void event_weather() {
    call_out("check_it",0);
}

void check_it() {
    object env=environment();

    if (!env||TO->query_dead()) return ;
    if (CLIMA->query_lluvia() && CLIMA->query_lluvia()!=2 && !env->query_property("no_llover")) {
		if (env->query_outside()) {
			int ll;
			ll=CLIMA->query_humedad()+env->query_property("ajuste_humedad");
			if (ll<1) ll=1;
	    		wetness+=ll;
			if(wetness>300) wetness=300;
	    		tell_object(TO,"Te estas mojando.\n");
	    		}
		}
    if (wetness>0 && (!CLIMA->query_lluvia()||!env->query_outside()||env->query_no_llover()) ) {
	int hu;
	hu=CLIMA->query_humedad()+env->query_property("ajuste_humedad");
	if (hu<1) hu=1;
	wetness-=hu;
	if (wetness<=0) {
		tell_object(TO,"Te secas.\n");
		wetness=0;
		}
	}
    return;
}
