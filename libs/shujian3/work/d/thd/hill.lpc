inherit ROOM;
void create()
{
        set("short", "小山");
        set("long", @LONG
一翻上山头，你就发现眼前豁然开朗，北面山脚下是一大片的桃花丛，而
在花丛中隐约露出了几座庭院的飞檐，似乎有着一片典雅的建筑在那边。向靠
海的一边望去，用来爬山时垫脚的岩石已经被蹬掉了，你再也回不到海边了。
而东北边更有一座小山峰，
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"taohua1",
                "eastup" : __DIR__"hill1",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","桃花岛");

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob;
        int i;
        if (dir == "northdown" || dir == "eastup") {
           ob = all_inventory(me);
           for(i = 0; i < sizeof(ob); i++) {
               if (userp(ob[i])) {
                  message_vision("$N把$n放在地上，走进阵中。\n",me,ob[i]);
                  ob[i]->move(this_object());
               }
           }
        }
        return ::valid_leave(me, dir);
}

