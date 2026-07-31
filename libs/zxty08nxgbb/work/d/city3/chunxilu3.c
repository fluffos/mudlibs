
inherit ROOM;

void create()
{
        set("short", "春熙路口");
        set("long", @LONG
这里是成都府最繁华的地带——春熙路，并不宽的街道
两旁，店铺林立汉白玉砌的路面几乎能照出人影。路上的行
人摩肩接踵，都在为各自的生计奔波着。一派繁荣，富庶的
景象。不远处的公告栏(sign)站着两名衣甲鲜明的卫兵。不
时警惕的看着你。东南方就是成都的母亲河---府南河。
LONG);

        set("outdoors", "/d/chengdu");
        set("objects", ([
                __DIR__"npc/weibing" : 2,
            ]));

        set("exits", ([
                "southeast" : __DIR__"funanhe1",
                "north" : __DIR__"chunxilu2",
            ]));
        set("item_desc", ([ 
            "sign" : "成都大府，严禁乱来，否则弄凶！\n",
           ]));

        setup();
       
}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( dir == "north" 
        && ob=present("wei bing", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
                        return notify_fail(ob->name()+"向你喝道：你这贱民想造反唆，搞快放下手持兵器才能进去！\n"); 
                        
                }
        }
        

        return 1;
        }
        else
                return 1;
}

