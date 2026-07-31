// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "÷–—Îπ„≥°");
    set("long", @LONG
    ’‚¿Ô «≥« –µƒ’˝÷––ƒ£¨“ª∏ˆ∫‹øÌ¿´µƒπ„≥°£¨∆Ã◊≈«‡ Øµÿ√Ê°£“ª–©”Œ ÷∫√œ–
µƒ»À‘⁄’‚¿Ô¡Ô¡Ô¥Ô¥Ô£¨æ≠≥£”–“’»À‘⁄’‚¿Ô±Ì—›°£÷–—Î”–“ªø√¥ÛÈ≈ ˜£¨≈Ã∏˘¥ÌΩ⁄£¨æ›
¥´“—”–«ßƒÍµƒ ˜¡‰£¨ «’‚◊˘≥« –µƒ¿˙ ∑º˚÷§°£ ˜∏…µ◊≤ø”–“ª∏ˆ∫‹¥Ûµƒ∂¥(shudong)°£
ƒ„ø…“‘ø¥µΩ±±±ﬂ”–¿¥◊‘∏˜µÿµƒ––»À¿¥¿¥Õ˘Õ˘£¨ƒœ√Ê»À…˘∂¶∑–£¨“ª≈…∑±ª™æ∞œÛ£¨∂´±ﬂ
≤ª ±µÿ¥´¿¥¿ ¿ µƒ∂¡ È…˘£¨Œ˜±ﬂ‘Úº˚≤ªµΩº∏∏ˆ––»À£¨“ª∆¨À‡æ≤°£¥Û ˜…œπ““ªøÈ¥Û≈∆

                        °°[1;33m£Œ£œ£‘£…£√£≈[2;37;0m

LONG
    );
        set("no_sleep_room",1);
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "’‚ «“ª∏ˆ∫⁄≤ª¡Ô‰–µƒ¥Û∂¥£¨¿Ô√Ê≤ª÷™µ¿”––© ≤√¥π≈π÷°£\n",
        "È≈ ˜"  :   "“ªø√÷¶“∂√Ø ¢µƒ¥ÛÈ≈ ˜£¨ø¥¿¥À∆∫ıø…“‘≈¿(climb)…œ»•°£\n",
        "¥ÛÈ≈ ˜":   "“ªø√÷¶“∂√Ø ¢µƒ¥ÛÈ≈ ˜£¨ø¥¿¥À∆∫ıø…“‘≈¿(climb)…œ»•°£\n",
        " ˜"    :   "“ªø√÷¶“∂√Ø ¢µƒ¥ÛÈ≈ ˜£¨ø¥¿¥À∆∫ıø…“‘≈¿(climb)…œ»•°£\n",
        "tree"  :   "“ªø√÷¶“∂√Ø ¢µƒ¥ÛÈ≈ ˜£¨ø¥¿¥À∆∫ıø…“‘≈¿(climb)…œ»•°£\n",

                "notice" : (: look_notice :),

    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
         "northwest" : __DIR__"happyjie",
     "down" : __DIR__"drop",
     "enter" : "/u/zjb/room/yingxiong",
    ]));
    set("objects", ([
        __DIR__"npc/liumang" : 2,
"/d/npc/jinglei" : 1,
        __DIR__"npc/liumangtou" : 1,
       __DIR__"npc/gcqingjie" : 1,
        "/clone/npc/halfgod":1,
        "/d/npc/xunbu":1,
    ]));
    setup();
}
void do_rumor(object me)
{
    if (!me)    return;
   if (!userp(me)) return;
//    CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"‘⁄Ω÷…œ¬„±º—Ω£°");
}
void init()
{
    object me;
    me=this_player();
    if (!me->query_temp("armor/cloth") && me->query("race")=="»À¿‡" ){
            if (time()-me->query_temp("rumor/nocloth")>10){
                me->set_temp("rumor/nocloth",time());
                call_out("do_rumor",random(5),me);
            }
        }
    if(me->is_ghost()){		
		write(BLU"Õª»ªº‰“ı∑Á’Û’Û£¨ƒ„∂˙±ﬂœÏ∆“ª’Ûø’∂¥∂¯”÷“ı…≠µƒ…˘“Ù:°Æªÿ¿¥”¥£¨ªÿ¿¥”¥!°Ø\n"NOR);
		write(HIW"“ª’Û∞◊ŒÌΩ´ƒ„π¸¡À∆¿¥£¨ƒ„”÷ªÿµΩ¡ÀπÌ√≈πÿ\n"NOR);
	
		me->move("/d/death/gate");
		      }    
        if ((int)me->query("neili") > (int)me->query("max_neili") * 8)
               me->set("neili", (int)me->query("max_neili") * 8);

        
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}
int do_enter(string arg)
{
    object me;
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="shudong" ) 
    {
        write("ƒ„“ªÕ‰—¸Õ˘∂¥¿Ô◊ﬂ¡ÀΩ¯»•°£\n");
                me->move("/d/gaibang/inhole");
                message("vision",
            me->name() + "¥”∂¥¿Ô◊ﬂ¡ÀΩ¯¿¥°£\n",
                    environment(me), ({me}) );
        return 1;
    }
}   
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if( !arg || arg!="up") return notify_fail("ƒ„“™Õ˘ƒƒ∏ˆ∑ΩœÚ≈¿£ø\n");
    if(me->query_condition("killer"))
    {
       message("vision",
        me->name() + "’Ω’Ωæ§æ§µÿ¿≠◊≈¥ÛÈ≈ ˜µƒ≈Ã∏˘£¨∆®π…“ª≈§“ª≈§µÿÕ˘…œ≈¿£¨Õª»ª“ª…˘≤“Ω–£¨”÷µÙ¡Àœ¬¿¥°£\n",
        environment(me), ({me}) );
        write("ƒ„’Ω’Ωæ§æ§µÿ¿≠◊≈¥ÛÈ≈ ˜µƒ≈Ã∏˘Õ˘…œ≈¿£¨“ª≤ª–°–ƒÀ§¡À∏ˆπ∑≥‘ ∫°£\n");
        return 1;
     }
    if (me->query("gender")!="≈Æ–‘")
    message("vision",
        me->name() + "’Ω’Ωæ§æ§µÿ¿≠◊≈¥ÛÈ≈ ˜µƒ≈Ã∏˘£¨∆®π…“ª≈§“ª≈§µÿÕ˘…œ≈¿°£\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "«·«·“ªÃ¯£¨“¬»π∆Æ∆Æ£¨œÛœ…◊”∞„∑……œ¥ÛÈ≈ ˜°£\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "’Ω’Ωæ§æ§µƒ◊•◊° ˜∏…Õ˘…œ≈¿»•°£\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="≈Æ–‘")
        message("vision",
        me->name() + "∆¯¥≠–Í–Íµÿ≈¿¡À…œ¿¥°£\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","“ª’Û«Âœ„∑…¿¥£¨ƒ„∂®—€“ªø¥£¨"+
        me->name() + "“—æ≠Ê√Ê√”Ò¡¢‘⁄ƒ„—€«∞°£\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "’Ω’Ωæ§æ§µÿ¥”œ¬√Ê≈¿¡À…œ¿¥°£\n", environment(me), ({me}) );   
    return 1;
}   
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j=0, k;
        who=this_player();
 file=read_file("/log/fight/lunjian1");
 file+=read_file("/log/fight/lunjian2");
 file+=read_file("/log/fight/lunjian3");
 file+=read_file("/log/fight/lunjian4");
        if(!file)
                return "ƒø«∞√ª”–»Œ∫Œ±»Œ‰º«¬º°£\n";
        name_list = explode(file,"\n");
        for(i=0;i<sizeof(name_list);i++) {
                if(name_list[i] == "seperator" ) {
                        j++;
                        k=0;
                        printf("\nµ⁄"+chinese_number(j)+"ΩÏª™…Ω¬€Ω£Ω·π˚£∫\n");
                        continue;
                }
                k++;
                printf(GRN "µ⁄"+chinese_number(k)+"√˚£∫%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}

