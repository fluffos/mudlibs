// Job daemon, which handle informations of all kinds of jobs
// By flee@sgz, 21 Dec 1998
#include <mudlib.h>
#include <security.h>

#define SAVE_FILE "/data/daemons/job_d"

inherit M_ACCESS;

private mapping jobs;
nosave protected int save_time;
void save_data()
{
	unguarded(1, (: save_object, SAVE_FILE, 1 :));
	return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        if( !jobs || !mapp(jobs) )jobs = ([ ]);
        return;
}
string *list_jobs()
{
	return keys( jobs );
}
mixed query_job(string str, string para)
{
	string *job_ids;
	mapping job_want;

	if((!str)||(str=="")) return jobs;
	job_ids = keys( jobs );

	if( member_array( str, job_ids ) == -1 ){
		return 0;
	};
	if( !para )return jobs[str]; 
/*	job_want = jobs[str];
	job_ids = keys( job_want );
	if( member_array( para, job_ids ) == -1 ){
		if((para!="assign_job") || (para!="finish_job")) {
			printf("no such %s parameter in this job %s\n", para, str);
			return;
		}
	} else return job_want[para]; */
	return jobs[str][para];
}
string set_job(string str, string para, mixed value)
{
	string *job_ids;
	mapping temp_job;

	job_ids = keys( jobs );
	temp_job = ([ ]);
	
	if( !para )para = "";
	if( !value )value = 0;
	if( member_array( str, job_ids ) == -1 )printf("new job added !\n");
	else temp_job = jobs[str];
	temp_job[para] = value;
	jobs[str] = temp_job;
	save_data();
	return "ok, modify over !\n";
}
string delete_job(string str)
{
	string *job_ids;
	
	job_ids = keys( jobs );
	if( member_array( str, job_ids ) == -1 )
		return "sorry, but no such job name.\n";
	map_delete( jobs, str );
	save_data();
	return "ok, job delete!";
}
string* check_job(string para_name,mixed para_value)
{       string* ret;
        string* list;
        list=keys(jobs);
        ret=filter_array(list, (:jobs[$1][$(para_name)]==$(para_value):));
        return ret;
}
void time_save_data() {
	int t=time();
	if((t-save_time)>60) {
		save_time=t;
		save_data();
	}
}
mixed assign_job(string job) {
	if(!mapp(jobs[job])) return "no such job";
	jobs[job]["assign_job"]++;
	time_save_data();
	return jobs[job]["assign_job"];
}

string finish_job(string job) {
	if(!mapp(jobs[job])) return "no such job";
	jobs[job]["finish_job"]++;
	time_save_data();
	return jobs[job]["finish_job"];

}
void remove() {
	save_data();
}