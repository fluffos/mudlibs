
inherit F_CLEAN_UP;
int main(object me)
{
        mapping info;
        float x, fraction,fraction2;
        info = rusage();
		call_out("get_cpu_usage",1,info["utime"],info["stime"],uptime());
        return 1;
}

int get_cpu_usage(int utime1,int stime1,int uptime1)
{
        mapping info;
        float x, utime_usage,stime_usage;
        string str;

		info = rusage();

		utime_usage = (info["utime"] -  utime1)/10/(uptime()-uptime1);
		stime_usage = (info["stime"] -  stime1)/10/(uptime()-uptime1);

        str = sprintf("CPU usage -- Sys: %2.2f -- User: %2.2f\n", stime_usage,utime_usage);
        write( str );

		return 1;
}

int help()
{
	write("cpu2，查看mudos的cpu占用率。\n");
	return 1;
}
