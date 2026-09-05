//讲笑话的npc
//whuan
#include <ansi.h>
inherit NPC;
int do_jiang();

void create()
{
    set_name(HIR"笑话使者"NOR, ({"joke npc","joke"}) );
    set("long", "她是一个漂亮的小姑娘，特别会讲笑话。\n");
    set("per",40);
    set("gender", "女性");
    set("age", 1);
    set("attitude", "friendly");
    set("long","乖宝宝。\n");
    set("combat_exp", 1);
    set("str",3);

    setup();
}

int init()
{
    add_action("do_start","start");
    return 1;
}

int do_start()
{
    object me=this_player();
    if( !wizardp(me) ) return notify_fail("你是谁呀？\n");
    if(  find_call_out("do_jiang") != -1 ) return notify_fail("已经开始讲了呀。\n");
    do_jiang();
    return 1;
}

int do_jiang()
{
        string str, no, file="/d/wizard/npc/joke.txt";
        int i, j=0, k=1, flag=0;
        
        if( file_size(file) < 0 ) return notify_fail("这个文件不存在。\n");
        
        i=random(15000);
        str=read_file(file,i,1);
        while( str && flag != 2 && j < 100 ){
                if( sscanf(str,"####%s", no) == 1 ) {
                        flag += 1;
                } else {
                        if( flag == 1 && k < 20 ) {
                          if(k==1) shout(HIR"〖笑话精灵〗开始工作，请大家注意收听。\n"NOR);
                        //  if(k==1) write(HIR"〖笑话精灵〗开始工作，请大家注意收听。\n"NOR);
                          if(k==1) str =HIR"〖笑话精灵〗题目："HIY+str+NOR;
                          else str =HIR"〖笑话精灵〗:"HIY+str+NOR;
                          call_out("jiang",2*k,str);
                           k++;
                        }
                }
                i++;
                j++;
                str=read_file(file,i,1);
        }
        call_out("do_jiang",1200);
        return 1;
}

void jiang(string str)
{
//        command("say "+str);
        message("channel:chat",str,users());
        //write(str);
}
