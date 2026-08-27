// 玩家出生点 START_ROOM
inherit STD_ROOM;

protected void create()
{
    setArea(0,0,0,0);
    ::create();
    set("short", "茅草屋");
    set("long", @LONG
破旧的茅草屋，简单的一桌一床。桌上摆着一个灵位，散落着几只野果。灵牌上的字迹模糊不清，隐约可见“二...大...月”的字样。床上铺着草席，胡乱地堆着几只枕头。床边地上还摆着一只破损的蒲团，门边的倒着一只木桶，桶里还有些许清水。屋子主人早已离去多年，但不时会有不知哪里来的人在此临时落脚。
LONG);
    //setArea(0,0,0,0); //设置所属地区和X,Y,Z坐标
    set("exits", ([
        "south" : WORLD_DIR"tutorial/courtyard",
        "north" : WORLD_DIR"tutorial/backyard",
    ])); //设置出口
}