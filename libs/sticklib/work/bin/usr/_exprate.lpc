#include <cmd.h>

nomask int
exprate_cmd(string name)
{
    string *arr,log,who,gn;
    int exp,time,ctr,ep,tt;
    status guild;
    if(!name) 
    {
	notify_fail("Usage: exprate <who/guild>\n");
	return 0;
    }

    exp=time=0;
    log = read_file("/log/EXPRATE");

    arr = explode(log,"\n");

    if(member(({"ninja","priest","fighter","thief", "necromancer",
	  "healer", "mage"}), name) > -1) guild = 1;

    for(ctr =0; ctr < sizeof(arr);ctr ++)
    {
	sscanf(arr[ctr],"%s,%d,%d,%s",who,ep,tt,gn);
	if(guild)
	{
	    if(gn == name)
	    {
		if(ep > 0)
		{
		    exp += ep;
		    time += tt;
		}
	    }
	}
	else
	{
	    if(name == who)
	    {
		if(ep > 0)
		{
		    exp += ep;
		    time += tt;
		}
	    }
	}
    }
    if(time <=0)
    {
	write(name+" not found\n");
	return 1;
    }
    write("Showing summary for "+name+":\n");
    write("Total exp: "+exp+"\n");
    write("Done in "+time/3600+" hours "+((time%3600)/60)+" minutes and "+(time%60)+
      " seconds.\n");
    if(time/3600 > 0)
	write("Making the exprate: "+(exp/time)*3600+" exp / hour (approx).\n");
    else
	write("Making the exprate: "+(exp/time)*60+" exp / minute (approx).\n");
    return 1;
}
