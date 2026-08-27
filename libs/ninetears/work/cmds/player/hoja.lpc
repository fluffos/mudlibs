// Vilat 01.09.2002
// Ficha (innovando modo reducido y extendido)
// 2 meses despues ficha remodelada e incomprensible el codigo

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup() {
   	position = 0;
	}

string query_usage() {
   	return "hoja [verbose|brief]";
	}

string query_short_help() {
   	return "Muestra las caracteristicas del jugador.";
	}

int cmd (string str, object me) {
        int n,ajuste,a,age;
        string info,buf;
   	object guild;
   	string *st;

   	if (str) st = explode(str, " ");
	else st = ({ });
	guild = me->query_guild_ob();


        if (me->query_dead()) return notify_fail("Eres un espiritu, no necesitas saber esto.\n");

   	if ((!me->query_verbose() && member_array("verbose", st) == -1)||member_array("brief", st )!= -1) {
      		buf=me->query_cap_name()+(me->query_apellido()!=""?" "+TP->query_apellido():"");
		ajuste=me->query_cols()-longitud(buf)-6;
		buf="{ %^RESET%^"+buf+" %^CYAN%^}";
                for(n=0;n<ajuste;n+=2) buf="="+buf+"=";
		buf="%^CYAN%^O"+buf+"O%^RESET%^\n\n";
   		tell_object(me,buf);
		ajuste=me->query_cols()-16;
		buf="%^BOLD%^Raza:%^RESET%^ "+CAP(me->query_race());
		info="%^BOLD%^Nivel:%^RESET%^ "+(string)me->query_level();
		ajuste=ajuste-7-strlen((string)me->query_level());
                for(n=longitud(buf);n<ajuste;n++) buf+=" ";
		buf+=info+"\n";
		tell_object(me,"\t"+buf);
		ajuste=me->query_cols()-16;
		buf="%^BOLD%^Sexo:%^RESET%^ "+CAP(me->query_gender_string());
		info="%^BOLD%^Deidad:%^RESET%^ "+CAP(me->query_deity());
		ajuste=ajuste-7-strlen(me->query_deity());
                for(n=longitud(buf);n<ajuste;n++) buf+=" ";
		buf+=info+"\n";
		tell_object(me,"\t"+buf);
		ajuste=me->query_cols()-16;
		buf="%^BOLD%^Alineamiento:%^RESET%^ "+CAP(me->query_alineamiento_name());
		info="%^BOLD%^Gremio:%^RESET%^ "+(guild?guild->query_short():"Sin Gremio");
		ajuste=ajuste-6-(guild?strlen(guild->query_short()):11);
                for(n=longitud(buf);n<ajuste;n++) buf+=" ";
		buf+=info+"\n";
		tell_object(me,"\t"+buf+"\n");
		ajuste=me->query_cols()-24;
		ajuste/=7;
		buf="";
		for(n=0;n<(me->query_cols()-ajuste*5-24)/2;n++) buf+=" ";
		buf+="%^BOLD%^Fue:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Des:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Con:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Int:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Sab:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Car:%^RESET%^\n";
		tell_object(me,buf);
		buf="";
		for(n=0;n<(me->query_cols()-ajuste*5-24)/2;n++) buf+=" ";
		buf+=" "+(me->query_str()<10?" ":"")+(string)me->query_str()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_dex()<10?" ":"")+(string)me->query_dex()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_con()<10?" ":"")+(string)me->query_con()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_int()<10?" ":"")+(string)me->query_int()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_wis()<10?" ":"")+(string)me->query_wis()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_cha()<10?" ":"")+(string)me->query_cha()+"\n";
		tell_object(me,buf+"\n");
      		buf="%^BLUE%^BOLD%^ NineTears %^RESET%^";
		ajuste=me->query_cols()-longitud(buf)-6;
		buf="{ %^RESET%^"+buf+" %^CYAN%^}";
   		for(n=0;n<ajuste;n+=2) buf="="+buf+"=";
		buf="%^CYAN%^O"+buf+"O%^RESET%^\n\n";
   		tell_object(me,buf);
		return 1;
		}
	else if ((me->query_verbose() && member_array("brief", st) == -1)||member_array("verbose", st )!= -1) {
      		buf=me->query_cap_name()+(me->query_apellido()!=""?" "+TP->query_apellido():"");
		ajuste=me->query_cols()-longitud(buf)-6;
		buf="{ %^RESET%^"+buf+" %^CYAN%^}";
   		for(n=0;n<ajuste;n+=2) buf="="+buf+"=";
		buf="%^CYAN%^O"+buf+"O%^RESET%^\n\n";
   		tell_object(me,buf);
		ajuste=me->query_cols()-16;
		buf="%^BOLD%^Raza:%^RESET%^ "+CAP(me->query_race());
		info="%^BOLD%^Nivel:%^RESET%^ "+(string)me->query_level();
		ajuste=ajuste-7-strlen((string)me->query_level());
		for(n=longitud(buf);n<ajuste;n++) buf+=" ";
		buf+=info+"\n";
		tell_object(me,"\t"+buf);
		buf="%^RED%^-%^BOLD%^=%^BLUE%^ NineTears %^RED%^=%^RESET%^RED%^-%^RESET%^\n";
		ajuste=me->query_cols()-15;
		ajuste/=2;
		for(n=0;n<ajuste;n++) buf=" "+buf;
		tell_object(me,buf);
		ajuste=me->query_cols()-16;
		buf="%^BOLD%^Sexo:%^RESET%^ "+CAP(me->query_gender_string());
		info="%^BOLD%^Gremio:%^RESET%^ "+(guild?guild->query_short():"Sin Gremio");
		ajuste=ajuste-6-(guild?strlen(guild->query_short()):11);
		for(n=longitud(buf);n<ajuste;n++) buf+=" ";
		buf+=info+"\n";
		tell_object(me,"\t"+buf+"\n");
		ajuste=me->query_cols()-24;
		ajuste/=7;
		buf="";
		for(n=0;n<(me->query_cols()-ajuste*5-24)/2;n++) buf+=" ";
		buf+="%^BOLD%^Fue:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Des:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Con:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Int:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Sab:";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Car:%^RESET%^\n";
		tell_object(me,buf);
		buf="";
		for(n=0;n<(me->query_cols()-ajuste*5-24)/2;n++) buf+=" ";
		buf+=" "+(me->query_str()<10?" ":"")+(string)me->query_str()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_dex()<10?" ":"")+(string)me->query_dex()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_con()<10?" ":"")+(string)me->query_con()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_int()<10?" ":"")+(string)me->query_int()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_wis()<10?" ":"")+(string)me->query_wis()+" ";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+=" "+(me->query_cha()<10?" ":"")+(string)me->query_cha()+"\n";
		tell_object(me,buf+"\n");
		ajuste=me->query_cols()-42;
		ajuste/=6;
		buf="";
		for(n=0;n<(me->query_cols()-ajuste*4-42)/2;n++) buf+=" ";
		buf+="%^BOLD%^Deidad";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Alineamiento";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Ciudadania";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Fama";
		for(n=0;n<ajuste;n++) buf+=" ";
		buf+="Reputacion%^RESET%^\n";
		tell_object(me,buf);

		ajuste=me->query_cols()-42;
		ajuste/=6;
		buf="";
		a=(me->query_cols()-ajuste*4-42)/2;
		age=6-strlen(me->query_deity());
		a+=age/2;
		for(n=0;n<a;n++) buf+=" ";
		buf+=CAP(me->query_deity())+" ";
		age=strlen(buf); // Lo que ya hemos avanzado
		a=(me->query_cols()-ajuste*4-42)/2+6+ajuste; //Lo que deberiamos haber avanzado
		a-=age; // Avance neto
		age=12-strlen(me->query_alineamiento_name()); // Para cuadrar el alineamiento
		a+=age/2;
		for(n=0;n<a;n++) buf+=" ";
		buf+=me->query_alineamiento_name()+" ";
		age=strlen(buf); // Lo que ya hemos avanzado
		a=(me->query_cols()-ajuste*4-42)/2+18+ajuste*2; //Lo que deberiamos haber avanzado
		a-=age; // Avance neto
		age=10-strlen(me->query_ciudadania()); // Para cuadrar la ciudadania
		a+=age/2;
		for(n=0;n<a;n++) buf+=" ";
		buf+=me->query_ciudadania()+" ";
		age=strlen(buf); // Lo que ya hemos avanzado
		a=(me->query_cols()-ajuste*4-42)/2+28+ajuste*3; //Lo que deberiamos haber avanzado
		a-=age; // Avance neto
		age=4-strlen(me->query_fp_name()); // Para cuadrar la fama
		a+=age/2;
		for(n=0;n<a;n++) buf+=" ";
		buf+=me->query_fp_name()+" ";
		age=strlen(buf); // Lo que ya hemos avanzado
		a=(me->query_cols()-ajuste*4-42)/2+32+ajuste*4; //Lo que deberiamos haber avanzado
		a-=age; // Avance neto
		age=10-strlen(me->query_rp_name()); // Para cuadrar la reputacion
		a+=age/2;
		for(n=0;n<a;n++) buf+=" ";
		buf+=me->query_rp_name()+"\n\n";
		tell_object(me,buf);
		buf="%^CYAN%^";
		for(n=0;n<me->query_cols();n++) buf+="=";
		if(longitud(me->query_cap_name()+(me->query_apellido()!=""?" "+TP->query_apellido():""))%2&&!me->query_cols()%2) buf+="=";
		tell_object(me,buf+"%^RESET%^\n");
		buf="%^BOLD%^Dinero: %^RESET%^"+(string)(me->query_value()/500)+" Plat.$%^BOLD%^Carga: %^RESET%^"+(string)me->query_loc_weight()+" %^BOLD%^(%^RESET%^"+(string)me->query_max_weight()+"%^BOLD%^)%^RESET%^$%^BOLD%^Cobardia: %^RESET%^"+(string)me->query_wimpy()+" %^BOLD%^%%^RESET%^$%^BOLD%^Thac0: %^RESET%^"+(string)me->query_thac0()+"$%^BOLD%^AC: %^RESET%^"+(string)me->query_total_ac();
		ajuste=me->query_cols()-64-strlen((string)(me->query_value()/500))-strlen((string)me->query_loc_weight())-strlen((string)me->query_max_weight())-strlen((string)me->query_wimpy())-strlen((string)me->query_thac0())-strlen((string)me->query_total_ac());
		info="";
		for(n=0;n<ajuste/4;n++) info+=" ";
		buf=replace_string(buf,"$",info);
		tell_object(me,buf+"\n");
		buf="%^CYAN%^";
		for(n=0;n<me->query_cols();n++) buf+="=";
		if(longitud(me->query_cap_name()+(me->query_apellido()!=""?" "+TP->query_apellido():""))%2&&!me->query_cols()%2) buf+="=";
		tell_object(me,buf+"%^RESET%^\n");
		if (me->query_group_ob()) tell_object(me,"Eres miembro del Clan "+me->query_group_name()+"\n");
		if (me->query_race_group_ob()) tell_object(me,"Eres miembro de "+me->query_race_group_name()+"\n");
		tell_object(me,"\n");
		tell_object(me,"Estas "+me->volume_string()+".\n");
		tell_object(me,"\n");
		tell_object(me,"Tienes ");
		age = me->query_time_on();
		age = -age;
		if (age > 86400) printf("%d dias, ", age/86400);
		if (age > 3600) printf("%d horas, ", (age/3600)%24);
		if (age > 60) printf("%d minutos y ", (age/60)%60);
		printf("%d segundos.\n", age % 60);
		buf="%^CYAN%^O";
		for(n=0;n<me->query_cols()-2;n++) buf+="=";
		if(longitud(me->query_cap_name()+(me
		->query_apellido()!=""?" "+TP->query_apellido():""))%2&&!me->query_cols()%2) buf+="=";
		tell_object(me,buf+"O%^RESET%^\n");
		return 1;
		}
	return notify_fail("Algo malo ha ocurrido, notificaselo a un inmortal o usa el comando 'bug' explicando las circunstancias en que ha aparecido este mensaje.\n");
	}
