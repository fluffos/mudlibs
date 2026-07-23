// UPLOAD BY SCATTER.C
// THIS FILE IS ONLY FOR TESTING!
// Please Do Not Modify This File!  Thank you!

//#include <ansi.h>
inherit ROOM;

void init()
{	object ob;
	if( interactive( ob = this_player()))
	remove_call_out("arrowing");
        ob->start_busy(10);
	call_out("arrowing", 3, ob,0);
}

int arrowing(object ob, int stage)
{
   string *story_msg;
   object env;
        env=environment(ob);
        story_msg=env->query("story_msg");

        if( environment(ob) == this_object())
	{
	   tell_object(ob, story_msg[stage]);
	   if( ++stage < sizeof(story_msg) ) {
		call_out("arrowing",3, ob, stage);
           }
           else {
              if (env->query("next_room"))
                 {
                   if(env->query("save_room"))
                    ob->set("startroom",env->query("save_room"));
                    ob->move(env->query("next_room"));
                 }
              else return 1;
           }
	}
	else return 1;
}