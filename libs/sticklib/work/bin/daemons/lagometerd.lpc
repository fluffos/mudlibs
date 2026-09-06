/* Lag-o-Meter by Frobozz 13.6.1995 */

// inherit "/basic/id";
// No need as this is daemon. -+ Doomdark +-

#include "/sys/configuration.h"

#define HB_CYCLE      2
//How many minutes backwards do we show?
#define LAG_MINUTES   5
//For how long do we keep counting lag?
#define COUNTER_CYCLE 60

int last_hb_time;
int *lagometer;
int lag_counter;
int start_time; //When did we start counting lag?

void
create()
{
    lagometer=allocate(LAG_MINUTES);
    configure_object(this_object(), OC_HEART_BEAT, 1);
}

void
heart_beat()
{
    int this_hb_time,lag_time,i,size;
    this_hb_time=time();
    //Are we checking lag?
    if(last_hb_time)
	//Is it lagging? And how much?
	if((lag_time=this_hb_time-last_hb_time)>HB_CYCLE)
	    lag_counter+=(lag_time-HB_CYCLE);
    //Do we have to update the lagometer?
    if(this_hb_time-start_time>=COUNTER_CYCLE) {
	for(i=sizeof(lagometer)-1;i>0;i--)
	    lagometer[i]=lagometer[i-1];
	lagometer[0]=lag_counter;
	lag_counter=0;
	start_time=this_hb_time;
    }
    last_hb_time=this_hb_time;
}

/* This function makes a number to format "a.bc" (123 -> "1.23") */

string
divide(int n)
{
    string result;
    result="";
    if(n<100)
	result+="0";
    else {
	result+=n/100;
	n-=(n/100)*100;
    }
    result+=".";
    if(n<10)
	result+="0";
    result+=n;
    return result;
}

void
show_lagometer(object player)
{
    int i,current_time,sec;
    string header,info;
    current_time=time();
    header="Lagometer statistics from the last "+LAG_MINUTES+" minutes:\n";
    info="";
    if((sec=current_time-start_time)>0) {
	header+="Current minute ("+sec+" s)\t";
	info+=("\t"+divide((lag_counter*100)/(current_time-start_time))+"\t\t");
    }
    for(i=0;i<LAG_MINUTES;i++) {
	header+=("\t"+(i+1));
	info+=("\t"+divide((lagometer[i]*100)/COUNTER_CYCLE));
    }
    player->tell_me(header+" min ago\n"+info);
}
