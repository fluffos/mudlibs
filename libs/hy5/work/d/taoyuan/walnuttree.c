#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
    set("short", "核桃树下");
    set("long", @LONG
靠近草地的边缘长着一棵枝叶繁茂的小树，树下是碧绿的草地，一块平整的大
石头压在草地上，几朵黄色的小花开在石头的旁边。夏日时一阵阵的小凉风吹来让
人暑意全消，是一个纳凉的好地方。
LONG
        );
        set("long_night", @LONG
脚下的绿草地细密柔软，在昏暗的夜光下你隐约可以看见一棵小树，每当晴朗
无云的夜晚，你站在树下透过茂密的枝叶，便可看见天上星光浮动。树下有一块平
坦的大石头。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"lawn",
        ])); 
        set("item_desc", ([
                "stone" : "平坦的大石头，就象一个天然的大床，你可以躺下。（ｌａｙｄｏｗｎ）\n",
                "大石" : "平坦的大石头，就象一个天然的大床，你可以躺下。（ｌａｙｄｏｗｎ）\n",
        ]) );
    set ("no_magic", 1);
    set("outdoors","taoyuan");
    set("coor/x",240);
    set("coor/y",-50);
    set("coor/z",0);
    setup();
} 
void init(){
        ::init();
        add_action("do_laydown", "laydown");
        add_action("do_getup","getup");
} 
int do_laydown(){ 
        object me, walnut,who;
        int i, j; 
        me = this_player();
   i = NATURE_D->get_season();
        j = random(20); 
        who=query("laydown_person"); 
        if(me==who) return  notify_fail("你已经躺下了呀！？\n");
        if(who&&present(who,this_object()))
                return notify_fail("已经有人躺在大石上了。。。\n"); 
        if(i == 1){
                message("vision", "春风吹在你的脸上让你睡意悠然，石头虽然有些凉却还可以忍受。\n"
                                , me);
                message("vision", me->name() + "惬意地躺到了大石上。\n", this_object(), me);
                set("laydown_person",me);
        } else if(i == 2  ){
                if(NATURE_D->is_day_time()){
                        message("vision", "小树的枝叶替你遮挡着阳光，你舒适的躺到大石上。\n", me);
                        message("vision", me->name() + "惬意地躺到了大石上，舒服地叹了一口长气。\n",
                                        this_object(), me);
                set("laydown_person",me);
                        if(random(30)<2){
                            remove_call_out("walnut_fall");
                        call_out("walnut_fall", j, me);
                        }
                } else {
                        message("vision", "灿烂的星空是那么的迷人，你不禁悠然神往。\n", me);
                        if(random(10)<1){
                                remove_call_out("falling_star");
                                call_out("falling_star", j, me);
                        }
                        message("vision", me->name() + "惬意地躺到了大石上。\n", this_object(), me);
                        set("laydown_person",me);
                }
        } else if(i == 3){
                message("vision", "秋高气爽，落叶凋零，躺在这里的你心中充满了感伤。\n", me);
                message("vision", me->name() + "躺下深深地叹了一口气，声音中充满了无奈。\n",
                                this_object(), me);
                set("laydown_person",me);
        }
        else if(i == 4){
                message("vision", "冰凉的石头让你倏然一惊，马上站了起来。\n", me);
                message("vision", "刚躺到石头上的" + me->name() + "打了个冷战马上爬了起来。\n"
                                , this_object(), me);
   } 
        return 1;
} 
int do_getup()
{
        object me; 
        me=this_player();
        if(me!=query("laydown_person")) return 0;
    remove_call_out("walnut_fall");
        message_vision("$N从大石上爬了起来。\n",me);
        delete("laydown_person");
        return 1;
} 
int valid_leave(object who,string dir)
{
        if(who==query("laydown_person"))
                return notify_fail("你正躺着呢，不能离开！！\n");
        return ::valid_leave(who,dir);
} 
void walnut_fall(object me)
{
        object walnut; 
        message_vision(RED"风吹树动，一个青核桃落下正好砸到$N的头上。\n"NOR, me);
        message_vision(RED"$N倏然一惊，一骨碌爬了起来。\n"NOR, me);
        me->set("宿命B/桃源_核桃", 1+random(10));
        walnut = new(__DIR__"obj/walnut");
        walnut->move(this_object());
        delete("laydown_person");
} 
void falling_star(object me)
{
        int age; 
        age = me->query("age");
        message("vision", HIW"突然之间一道闪亮的银光划过夜空，消失在南边的天际。\n"NOR, me);
        if (age >= 10 && age <= 12 && !me->query("宿命A/桃源_流星")) {
                message("vision", HIG"你在流星落前的刹那间许下了一个愿望！！\n"NOR, me);
                message_vision("$N默默地站了起来！\n", me);
                me->set("宿命A/桃源_流星", 1+random(10));
        } else {
        message_vision("$N惊喜地跳了起来！！！\n", me);
   }
        delete("laydown_person");
}  
