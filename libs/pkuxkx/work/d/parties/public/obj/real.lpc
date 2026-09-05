//price 是地产价格，单位gold 

inherit F_SAVE;
#define NO 1
#define REAL_ESTATE_TRADE "/data/business/real_estate_no"+NO
string query_save_file()
{
        return REAL_ESTATE_TRADE;
}
mapping *entry = ({
            ([  "area":"luoyang","desc":"洛阳函谷关附近","file":"/d/luoyang/hanguguan","user_dir":"","price":15200,"room_limit": 8,"owner":"N/A","entry":"/d/parties/Real_1/biguanchu","entry_code":"N/A",]),
            ([  "area":"xiangyang","desc":"襄阳近武当山附近","file":"/d/xiangyang/westr5","user_dir":"","price":15500,"room_limit": 9,"owner":"N/A","entry":"/d/parties/Real_2/biguanchu","entry_code":"N/A",]),
            ([  "area":"changan","desc":"长安曲江池附近","file":"/d/changan/qujiangchi","user_dir":"","price":15000,"room_limit": 8,"owner":"N/A","entry":"/d/parties/Real_3/biguanchu","entry_code":"N/A",]),
            ([  "area":"suzhou","desc":"苏州狮子林附近","file":"/d/suzhou/shizilin","user_dir":"","price":12000,"room_limit": 12,"owner":"N/A","entry":"/d/parties/Real_4/biguanchu","entry_code":"N/A",]),
            ([  "area":"hangzhou","desc":"临安府西湖附近","file":"/d/hangzhou/xihu/pinghu","user_dir":"","price":13000,"room_limit": 10,"owner":"N/A","entry":"/d/parties/Real_5/biguanchu","entry_code":"N/A",]),
            ([  "area":"chengdu","desc":"成都百花潭附近","file":"/d/chengdu/baihuatan","user_dir":"","price":9000,"room_limit": 15,"owner":"N/A","entry":"/d/parties/Real_6/biguanchu","entry_code":"N/A",]),
            ([  "area":"beijing","desc":"濮阳铜雀台附近","file":"/d/beijing/tongque","user_dir":"","price":10000,"room_limit": 12,"owner":"N/A","entry":"/d/parties/Real_7/biguanchu","entry_code":"N/A",]),
            ([  "area":"jinyang","desc":"晋阳西门外","file":"/d/jinyang/guandaow1","user_dir":"","price":9800,"room_limit": 12,"owner":"N/A","entry":"/d/parties/Real_8/biguanchu","entry_code":"N/A",]),
            ([  "area":"taishan","desc":"泰山岱宗坊南","file":"/d/taishan/yidao3","user_dir":"","price":14000,"room_limit": 8,"owner":"N/A","entry":"/d/parties/Real_9/biguanchu","entry_code":"N/A",]),
            ([  "area":"xingxiu","desc":"北疆小镇附近","file":"/d/xingxiu/beijiang","user_dir":"","price":6000,"room_limit": 18,"owner":"N/A","entry":"/d/parties/Real_10/biguanchu","entry_code":"N/A",]),
            });

mapping *real_estate()
{
	restore();
    return entry;
}

int save_entry(mapping *source_entry)
{
    entry=source_entry;
    return 1;
}
