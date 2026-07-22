#include <ansi.h>
inherit ROOM;
inherit F_SAVE;

mapping *rumors=allocate(10);
int index=0;

string query_save_file() 
{
return "/c/data/item/"+query("short");
}

void reset()
{
restore();
::reset();
}       

void setup()
{
restore();
::setup();
}
                
void create ()
{
set ("short", "谣言控制中心");
set ("long",@LONG

一间不大的房间，无门无窗，笼罩在一束柔和的灯光下，
你却找不到光源在哪里。四周靠墙摆满了各色各样的仪器，
上面红红绿绿的指示灯不停的跳动着。正中墙上贴着副对
联----若要人不知，除非己莫为，横批是：天网恢恢。

LONG);
CHANNEL_D->register_relay_channel("rumor");
setup();
}

void relay_channel(object ob, string channel, string msg) 
{
mapping rumor=allocate_mapping(4);
if (channel!="rumor") return;
rumor["disclose"]=0;
if(userp(ob)) 
        {
        rumor["name"]=ob->query("name");
        rumor["id"]=ob->query("id");
        } 
else      {
             rumor["name"]= "系统";
             rumor["id"]= "底层文件或智能NPC";
             rumor["disclose"]=1;
           }
rumor["body"]=msg;
if ( !ob || wizardp(ob) )
        rumor["disclose"]=0;
else    rumor["disclose"]=1;    
if ( !random(4) )
        rumor["disclose"]=1;
rumors[index]=rumor;
index=(index+1)%10;   
set("rumor",rumor);
save();
}

void init() 
{
if (!wizardp(this_player()))
        this_player()->move("/d/city/center");
else    {
        add_action("do_list","list");
        }
}

int do_list() 
{
int i;
mapping r;  
for (i=1;i<=10;i++) 
        {
        r=rumors[(index-i+10)%10];
        if (r) 
                {
                write(r["name"]+"("+r["id"]+") says "+r["body"]);
                if (r["disclose"]) write(" [DISCLOSED]\n");
                else write("\n");
                }
        }
return 1;
}

mapping reveal(int i) 
{
return rumors[(index-i+10)%10];
}            


