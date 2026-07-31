 inherit __DIR__"no_killing_place";
void create()
{
        set("short", "慕容庄园");
        set("long", @LONG
这里不知何时建立了一个小小的庄园，庄园的门前是一片绿色的草坪
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"road3",
        ]) ); 
        set("item_desc", ([
                "door" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
                "柴门" : "不甚坚固的柴门只是轻掩着，似乎轻轻一推就开了。\n",
        ]) ); 
        set("no_magic", 1);     
        set("outdoors","taoyuan");
    set("coor/x",210);
        set("coor/y",-30);
        set("coor/z",0);
        setup(); 
} 
void init() {
        ::init();
        add_action("do_push", "push");
}  
void close_path()
{
        if( query("exits/north") ) {
    message("vision","柴门来回荡了几荡，最后终于静止了。\n",this_object() );
    delete("exits/north");
    }
} 
int do_push(string arg)
{
        object me;
    me = this_player();
    if( arg=="door" || arg =="柴门") {
        message_vision("$N往柴门上轻轻地一推，吱。。。的一声柴门开了。\n", me);
                set("exits/north", __DIR__"cyard");
           call_out("close_path", 5);
        }
        else {
                write("你要推什么呢？\n");
        }
        return 1;       
 }   
