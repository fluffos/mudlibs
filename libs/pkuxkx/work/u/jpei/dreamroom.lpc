inherit ROOM;

void create ()
{
       set("short","那拉提");
        set("long", @LONG
这里是那拉提的发呆空间，一张大大的书桌全是灰尘，也没见打扫一下。
只有墙角放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG);
        set("exits",([
          "north" : "/d/wizard/wizard_room_advent",
          "south" : "/d/wizard/wizard_room_whuan", 
          "down" : "/d/city/guangchang", 
          "up" : "/d/wizard/wizard_room",  
          "southeast" : "/d/wizard/biwuchang", 
          "northeast" : "/d/wizard/guest_room",
        ]));
        set("objects", ([  
//                __DIR__"npc/piaoran" : 1,  
//                __DIR__"npc/shihou" : 1,                  
//                __DIR__"obj/shiguan" : 1,  
//                __DIR__"obj/muding" : 1,
        ]) );
        set("no_kill", 1);
        set("valid_startroom", 1);
        set("alternative_die",1);
        set("sleep_room", 1);
        set("no_steal", 1);
        setup();
}

void alternative_die(object me)
{
        if(userp(me)){
                message_vision("天空突然升出一只大脚，一脚将$N踢飞了。\n",me);
                me->move("/d/city/guangchang");
                me->unconcious();                
                tell_room(environment(me),"半空中，"+me->query("name")+"倒栽葱的直坠下来。\n");
                return;
        }else{
                if(me->query("id") =="shouhuzhe"){
                        me->die();
                }else{
                        me->move("/obj/void");
                        destruct(me);
                }
        }
}

