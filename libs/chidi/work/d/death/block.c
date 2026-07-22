inherit ROOM;
void create()
{
	set("short","空房间");
	set("long","你完了...\n");
	set("valid_startroom",1);
	setup();
}
int block_cmd()
{
        string verb = query_verb();
        if (verb=="say") return 0; 
        if (verb=="chat") return 0; 
        if (verb=="es") return 0; 
        if (verb=="rumor") return 0; 
        tell_object( this_player(),"人都死了还想干什么呀，别着急等会吧!!!\n\n" NOR);
        return 1;
}
void init()
{
object me;
    me=this_player();
	if (!wizardp(this_player()))
	add_action("block_cmd","",1);
if(me->is_ghost()){         
                write(BLU"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
                write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
        
                me->move("/d/death/gate");
                      }    

}
