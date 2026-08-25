// emperor add makelove question, 2000.2.20
// written by  fire
// m_charanswer.c
/* for common for chars */
#include <mudlib.h>
#include <daemons.h>
void add_question(string p,string p2);
void char_answer_setup()
{
	string p_id;//emperor add
/*	string p_id,p_area;
	p_id=this_object()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	if(!p_area) return;

	if(AREA_D->get_area(p_area,"leader")==p_id) // local leader
	{ */
		add_question("settle","settle" );
		add_question("position","position");		
		add_question("localmeeting","localmeeting");
		add_question("job","job");
//	}

/* emperor add */
	p_id=this_object()->query_primary_id();
	if(CHAR_D->get_char(p_id, "mar"))
		add_question("sleep","sleep");
/* emperor add over */

	add_question("zgxy","zgxy");
	add_question("wxxy","wxxy");
	add_question("bfxy","bfxy");
}
void char_special_answer(object who, string matt)
{
	switch(matt)
	{
		case "settle" :
			(EV_SETTLE)->ask_settle(who,this_object());
			return;
		case "position":
			(EV_POSITION)->ask_position(who,this_object());
			return;
		case "localmeeting":
			(EV_LOCALMEETING)->ask_localmeeting(who,this_object());
			return;
		case "job":
			(EV_JOB)->ask_job(who,this_object());
			return;

/* emperor add */
		case "sleep":
			(EV_SLEEP)->ask_sleep(who,this_object());
			return;
/* emperor add over */

		case "wxxy" :
		case "bfxy" :
		case "zgxy" :
			(EV_LEARNSKILLS)->ask_skills(who,this_object(),matt);
			return;
	}
}
void special_answer(object who,string matt)
{
    if(!(CHAR_D->char_exist(this_object()->query_id()[0]))) {
	this_object()->targetted_action("$N对$T说道，对不起，我不知道。\n",who);
	return;
    }
    char_special_answer( who, matt);
}
