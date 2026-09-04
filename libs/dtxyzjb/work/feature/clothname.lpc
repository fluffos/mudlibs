// clothname.c  

#include <ansi.h>

string *com_type = ({
"衲袄"NOR, "宽衫"NOR, "窄衫"NOR, "汗衫"NOR, "罗衫"NOR, "罗袄"NOR, "短衫"NOR, 
"衣衫"NOR, "小褂"NOR,
});
string *man_color = ({
CYN"青", BLU"蓝", WHT"白", HIB"藏青", GRN"胡绿", HIR"绯红", 
BLK"皂", WHT"素白", HIM"紫", MAG"浅紫", 
});
string *com_material = ({
"布", "旧", "印花", "绸", "麻布", "粗布", 
});        
string *high_type = ({
"罗袍"NOR, "袍"NOR, "宽袍"NOR, "长衫"NOR, "衲袄"NOR, "宽衫"NOR, "罗衫"NOR, 
"大氅"NOR, "长袍"NOR,
});
string *high_material = ({
"缎子", "锦", "绸", "薄绸", "直缝", 
});                
string *wo_type = ({
"裙"NOR, "罗裙"NOR, "衫"NOR, "锦袄"NOR, "小袄"NOR, "长裙"NOR, "罗衣"NOR,
});
string *wo_color = ({
RED"大红", RED"银红", HIY"杏黄", GRN"葱绿", BLU"蓝", MAG"藕合色"
, MAG"粉", YEL"泥金", WHT"素白", WHT"白", GRN"胡绿", 
});
string *wo_material = ({
"绸", "细纱", "团花", "绣花", "罗", "六幅", "百绉", "薄绸", "对襟", "纹锦", 
});   
string *wos_type = ({
"鞋"NOR, "靴"NOR, "长靴"NOR, "皮靴"NOR,
});
string *mans_type = ({
"靴"NOR, "长靴"NOR, "宽靴"NOR,"快靴"NOR,
});
string *wos_color = ({
RED"大红", RED"银红", HIY"杏黄", GRN"葱绿", BLU"蓝", MAG"藕合色"
, MAG"粉", YEL"泥金", WHT"素白", WHT"白", GRN"胡绿", 
});
string *wos_material = ({
"绸", "细纱", "团花", "绣花", "罗", "六幅", "百绉", "薄绸", "丝", "纹锦", 
}); 
string *mans_color = ({
CYN"青", BLU"蓝", WHT"白", HIB"藏青", GRN"胡绿", HIR"绯红", 
BLK"皂", WHT"素白", HIM"紫", MAG"浅紫", 
});
string *mans_material = ({
"薄底", "锦", "干黄", "四缝", "直缝", 
});                                     
string comm_man_cloth()
{
    return man_color[ random ( sizeof ( man_color ) ) ] + com_material[ 
        random ( sizeof ( com_material ) ) ] + com_type[ random ( sizeof ( com_type ) ) ];
}
string high_man_cloth()
{
    return man_color[ random ( sizeof ( man_color ) ) ] + high_material[ random ( 
        sizeof ( high_material ) ) ] + high_type[ random ( sizeof ( high_type ) ) ];
}
string woman_cloth()
{
    return wo_color[ random ( sizeof ( wo_color ) ) ] + wo_material[ random ( sizeof ( 
        wo_material ) ) ] + wo_type[ random ( sizeof ( wo_type ) ) ];
}
string woman_shoes()
{
    return wos_color[ random ( sizeof ( wos_color ) ) ] + wos_material[ random ( sizeof ( 
        wos_material ) ) ] + wos_type[ random ( sizeof ( wos_type ) ) ];
}
string man_shoes()
{
    return mans_color[ random ( sizeof ( mans_color ) ) ] + mans_material[ random ( sizeof ( 
        mans_material ) ) ] + mans_type[ random ( sizeof ( mans_type ) ) ];
}



