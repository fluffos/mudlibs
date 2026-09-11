// nick.c 
// by fire on Sep 4, 1998
// used for player char to risign a position
inherit M_ANSI;

void start(string arg)
{
	int ret;
	if (colour_strlen(arg) > 20) {
            write("头衔太长了，想一个简单响亮点的吧。\n");
	    return;
	}
	if (arg == 0 || arg == "") {
	    this_body()->set_title(0);
            write("头衔取消成功。\n");
	}  
        else {
            this_body()->set_title(arg);
            write("称号设置成功。\n");
        }
}
