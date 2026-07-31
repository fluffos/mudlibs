 inherit ROOM;
void create()
{
        set("short", "风云驿站");
        set("long", @LONG
每天快马三匹，早午晚各传递书信三次。无论官员衙役还是普通百姓都可以在
这儿免费邮寄书信。不管你的书信要寄到那里，只要交给驿站，三天之内绝对可以
送到。近来朝廷节缩开支，王风也挂起了牌子(Sign)，和关外的吕恭合伙，做起了
出租马车到关外的生意。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"wcloud2",
        ]));
        set("objects", ([
                __DIR__"npc/officer": 1
        ]) );
        set("item_desc", ([
                "sign": @TEXT
招牌写著：出租马车(rent mache): 纹银8两
TEXT
        ]) ); 
        set("coor/x",-20);
        set("coor/y",10);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string dir)
{
        object mbox; 
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回驿站。\n");
                destruct(mbox);
        }
        return 1;
}  
