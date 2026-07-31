 inherit ROOM;
void create()
{
        set("short", "山道口"); 
        set("long", @LONG
此处再往上走，便是当初可谓名震一时的“富贵山庄”了，但自从富贵山庄传
到现任庄主王动手里，便开始一败涂地了，后来听说山庄里又住进了几个古古怪怪
的人，很大路的郭大路，自称死过七次的燕七和文秀如处子，酒量却赛过常人百倍
的林太平。路口有三个捕头模样的人拦住去路，一旁有块告示（ｇａｏｓｈｉ）。
往北路口被拦住了。
LONG);
        set("outdoors", "fugui");
        set("type","road");
        set("exits",([
                "west":__DIR__"shanlu1",
                "south":__DIR__"xiaojie1",
        "northup":__DIR__"shandao8",
        ]) );
        
        set("item_desc", ([
                "gaoshi": @TEXT
近日吉祥镇附近盗匪猖獗，传言中大盗凤栖梧出入无常，夜盗百家，
北面山路禁止通行，如有愿协助官府缉拿者可揭此告示，协力缉拿。
（ｊｉｅ　ｇａｏｓｈｉ）
TEXT
        ]) );  
        set("objects", ([
                __DIR__"npc/jinshizi" : 1,
                __DIR__"npc/jiagun" : 1,
                __DIR__"npc/meirujia" : 1,
        ]) );
        set("gaoshi",1);
        set("coor/x",-580);
        set("coor/y",130);
        set("coor/z",0);
        setup();
        
} 
void init(){
        add_action("do_jie", "jie");
} 
int do_jie(string arg){
        object jin;
        if (arg == "gaoshi" && query("gaoshi")) {
                if(present("jin shizi", this_object())) {
                        jin = present("jin shizi", this_object());
                        jin->do_jie(arg);
                } else {
                        message_vision("看守告示的人不在，等会儿再来揭吧。\n", this_player());
                }
        } 
        return 1;
}  
int valid_leave(object me, string dir)
{
        object ob, yayi;    
            
        if (!yayi=present("jin shizi",this_object()))
        if (!yayi=present("jia gun",this_object()))
                return 1;
        
        if ( userp(me) && dir=="northup" ) {
                if (!ob=present("yao pai",me))
                        return notify_fail(yayi->name()+"拦住了你的去路，看看告示吧。\n");
                if (!me->query_temp("yaopai"))
                        return notify_fail(yayi->name()+"说：“这腰牌你是从哪里偷来的？”\n");
                return 1;
        }
        
        return 1;
}    
