//bandwidth control

//in M
int total_traffic;
int total_traffic_bytes;
int start_time;

void create() 
{
	seteuid(getuid());
    total_traffic_bytes = 0;
    total_traffic = 0;
    start_time = time();
}

//int traffic, in bytes
int add_traffic(int traffic)
{
    total_traffic_bytes += traffic;
    if(total_traffic_bytes > 100 * 1024 * 1024)
    {
        total_traffic += (total_traffic_bytes/1024/1024);
        total_traffic_bytes = 0;
    }
    return total_traffic;
}

int get_total_traffic()
{
    return total_traffic;
}

int get_total_time()
{
    return time() - start_time;
}

string get_stat()
{
    int el = get_total_time();
    return sprintf("From %s, in %d days,%d hours,%d minutes,%d seconds, %d MBytes are sent out\n",ctime(start_time), el / 86400, 
        (el - (el/86400)*86400)/3600,(el - (el/3600)*3600)/60,el - (el/60)*60,total_traffic);
}



