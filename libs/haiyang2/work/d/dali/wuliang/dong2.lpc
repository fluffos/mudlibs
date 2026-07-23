// dong2.c
// bbb 1997/07/16
// COOL@SJ,9808

inherit ROOM;

string look_yuxiang();
string look_zi();
string look_shoe();
string look_left();
string look_right();

void create()
{
    set("short", "内室");
        set("long", @LONG
眼前突然一亮，一个宫装美女，手持长剑，剑尖对准了你的胸膛。细看
之下，原来是一座玉像（yuxiang)。东壁写了许多字（zi），笔法飘逸，似
以极强腕力以利器写成，西壁镶了六块大水晶，水晶外绿水隐隐，映得石室
中比第一间石室亮了数倍。
LONG
        );

        set("exits", ([
                "out" : __DIR__"dong1",
        ]));

        set("valid_startroom",1);
        
        set("item_desc",([
                "left"          :       (: look_left :),
                "right" :               (: look_right :),
                "zi"            :       (: look_zi :),
                "yuxiang"       :       (: look_yuxiang :),
        ]));

        setup();
}


void init()
{
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
       object me;
       me=this_player();

       if (!me->query_temp("lbwb1/yuxiang")) return 0;
       if ( me->query("dali/fail") > 3) return 0;

       if( !arg || arg != "yuxiang" ) return 0;
        
       if( arg=="yuxiang" ) {
           message_vision("$N口中数着，恭恭敬敬的向玉像磕起头来。\n", this_player());
           if(!me->query_temp("lbwb1/left") || !me->query_temp("lbwb1/right")) {
                write("你对着玉像一个头磕下去，似乎发现玉像的左脚（left)、右脚（right)绣得有字。 \n");
                return 1; 
           }
           if( me->query_temp("ketou_trigger") > 15 
            && me->query_temp("ketou_trigger") < 17 ) {
               message_vision("$N看见蒲团上的薄草早已破裂，不由伸手进去，里面什么也没有，好象已经被取走了。\n",me);
               me->delete_temp("lbwb1");
               me->delete("ketou_trigger");
               return 1;
           }
           if (!me->query("dali/meet_dy1") 
            || !me->query("dali/pass")) {       
               me->set_temp("duanyu/find1",1);
               me->add_temp("ketou_trigger", 1);
               return 1;
           }       
           return 1;
       }
}


string look_left()
{ 
       object me;  
       me=this_player();
       me->set_temp("lbwb1/left",1);
          return "磕首百遍，供我驱策。\n";
}

string look_right()
{ 
       object me;  
       me=this_player();
       me->set_temp("lbwb1/right",1);
          return "遵行我命，百死无悔。 \n";
}

string look_zi()
{
       return "洞中无日月，人间至乐也 -- 逍遥子为秋水妹书。\n";
}

string look_yuxiang()
{    
       object me;  
       me=this_player();
       me->set_temp("lbwb1/yuxiang",1); 
          return "那是一座白玉雕成的玉像，与真人一般大小，身上淡黄绸衫微微颤动，更奇的是一对眸子莹然有光，神采飞扬。  \n";
}
