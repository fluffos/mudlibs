 //modified by wind
// Room: /city/jianyu.c
inherit ROOM;
void init();
void create()
{
    set("short", "大理监狱");
    set("long", @LONG
这里是一间黑黝黝的监狱，空气中充斥着一股腐臭，高高的铁窗
透进一丝阳光，几只大老鼠若无其事地在你身边穿来穿去。
LONG
    );
    set("valid_startroom", 1);
  set("no_fly",1);
    set("no_fight", 1);
    set("objects", ([
//        __DIR__"obj/jitui" : 3,
//        __DIR__"obj/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
    ob->set("startroom","/d/dali/dljianyu");
        remove_call_out("kick_ob");
    call_out("kick_ob",30);
}
void kick_ob()
{
    object room,*obj;
        int i;
        
        obj=deep_inventory(this_object());
        if (!sizeof(obj))   return;
        for (i=0;i<sizeof(obj);i++){
                if (interactive(obj[i]) && (time()-obj[i]->query_temp("summon_time"))>300){
                        message_vision(HIY+"哐当一声，一个狱卒打开牢门，一脚把$N踢了出去：想在这里白吃白喝？没门！\n"+NOR,obj[i]);
                if (!room=find_object("/d/dali/sheguta") )
                                room=load_object("/d/dali/sheguta");
                        obj[i]->move(room);
                        message("vision",HIY+"一个家伙从衙门的后门给踢了出来!\n"+NOR,room,({obj[i]}));
                obj[i]->set("qi",-1);
                        tell_object(obj[i],"你疼的差点昏了过去。\n...干脆还是昏了好受些，昏了就不疼了！\n");
            obj[i]->set("startroom","/d/dali/sheguta");
                    call_out("kick_ob",30);
                        return;
                }
        }
    call_out("kick_ob",100);
}

object do_check(string arg)
{
    object *obj;
    int i;
    if (!arg)   return 0;
    obj=deep_inventory(this_object());
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++)
        if (obj[i]->id(arg) && obj[i]->is_character() && !obj[i]->is_corpse())    return obj[i];
    return 0;
}
