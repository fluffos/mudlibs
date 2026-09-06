/*
** People command.
** Aramis - Nov. 29, 1998
** added n option. - Dec. 6, 1998
*/

#include "/sys/driver_info.h"
#include "/sys/interactive_info.h"

#include <cmd.h>
#include <driver.h>
#include <config.h>
#include <mud_name.h>
#include <invis_levels.h>

#define BAR "=++=-=++=-=++=-=++=-=++=-=++=-=++=-=++=-=+\
+=-=++=-=++=-=++=-=++=-=++=-=++=-=++="

string format_time(int num);
string format_text(string str, string bah);
string *make_output(string *input, int num, string bah);
string get_level(object ob);
mixed *sort_people(mixed *people);

nomask int people_cmd(string str) {
    mixed *people;
    string age,name,ip_num,level,idle,where,*output;
    int x,num;

    people = users();
    people = sort_people(people);
    num=sizeof(people);
    output = ({""});

    for(x=0;x<num;x++) {
	name=people[x]->query_real_name();
	if(name) name = capitalize(name);
	else     name = "Login";
	age   =format_time((people[x]->query_age())/30);
	if(str=="n") ip_num = format_text(interactive_info(people[x], II_IP_NAME),"bah");
	else ip_num=interactive_info(people[x], II_IP_NUMBER);
	level =get_level(people[x]);
	idle  =format_time(interactive_info(people[x], II_IDLE)/60);
	if(environment(people[x]))
	    if(str=="n") where = environment(people[x])->query_short();
	    else where = object_name(environment(people[x]));
	else where = "Login area.";
	if(where[0..5] == "areas/") where = "^"+capitalize(where[6..sizeof(where)]);
	if(where[0..1] == "u/") where = "~"+capitalize(where[2..sizeof(where)]);
	where = format_text(where,str);

	switch(str) {
	case "n": output += ({sprintf("%-11s %-35s %-31s",
		name,ip_num,where)});break;
	default:output += ({ sprintf("%4s %-11s %-15s %5s %4s %-35s",age,name,ip_num,level,idle,where)});break;
	}
    }
    this_player()->more(make_output(output, num, str));
    return 1;
}

string format_time(int j) {
    string str;

    if (j >= 60*24) str = j/(60 * 24) + "d"; else
    if (j >= 60) str = j/60 + "h"; else
    if (j > 0) str = j + "m"; else str="  ";
    return str;
}

string get_level(object ob) {
    string str;
    int num;

    if(num=ob->query_coder_level()) {
	str="C"+num;
    }else{
	str=" "+ob->query_level();
    }
    return str;
}

string format_text(string str, string bah) {
    int num;

    if(bah=="n") num=31;
    else num=35;
    if(sizeof(str) > num) str = str[0..(num-20)]+"..."+str[<16..<1];
    return str;
}

string *make_output(string *input, int num, string bah) {
    string TITLE;

    if(bah == "n") TITLE= " Name            Current IP                        Location";
    else TITLE = " Age Name        Current IP      Level Idle Location";
    input=({ BAR, (num > 1)
      ? sprintf("%|75s", "There are "+num+" people on "+MUD_NAME+".  "+driver_info(DI_LOAD_AVERAGE_COMMANDS)+".")
      : sprintf("%|75s", "There is one person on "+MUD_NAME+".  "+driver_info(DI_LOAD_AVERAGE_COMMANDS)+"."),
      BAR, TITLE})+input+({BAR});
    return input;
}
mixed *sort_people(mixed *output) {
    mixed dummy;
    int x,flag,num1,num2;

    flag = 1;
    while(flag) {
	flag = 0;
	for(x=1;x<sizeof(output);x++) {
	    if(num1=output[x]->query_coder_level()) num1+=1000;
	    else num1=output[x]->query_level();
	    if(num2=output[x-1]->query_coder_level()) num2+=1000;
	    else num2=output[x-1]->query_level();
	    if(num1>num2) {
		dummy = output[x];
		output[x]=output[x-1];
		output[x-1]=dummy;
		flag=1;
	    }
	}
    }
    return output;
}
