// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// Yaynu @ red dragon Nov. 1995
#include <mudlib.h>
inherit CMD;
string obj_static() {
	string ret;
	ret="物品总数："+sizeof(objects())+"\n";
	ret+="生命总数："+sizeof(objects((:$1->is_living():)))+"\n";
	ret+="室内房间总数："+sizeof(objects((:$1->is_indoors():)))+"\n";
	ret+="户外房间总数："+sizeof(objects((:$1->is_outdoors():)))+"\n";
	ret+="daemon 物品总数："+sizeof(objects((:$1->direct_check_obj():)))+"\n";
	return ret;
}
void main() {
    mapping info;
    float x, fraction;
    string ret;
    info = rusage();
    x = info["utime"] + info["stime"];
    // time is in msec, convert to sec
    x = (info["utime"] + info["stime"])/1000;
    fraction = x / uptime();    
    outf("CPU usage: %2.2f%%\n", fraction * 100);
    outf("Mud status is\n");
    ret=mud_status();
    outf(ret);
    outf("load average:\n");
    outf("%s\n",query_load_average());
    outf(obj_static());
}
