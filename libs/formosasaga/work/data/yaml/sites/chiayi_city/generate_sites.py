#!/usr/bin/env python3
"""Batch generate chiayi_city site YAML files."""
import os

SITES_DIR = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml/sites/chiayi_city"

sites = [
    {
        "id": "alishan_railway_depot",
        "canonical_name": "阿里山鐵路調度場",
        "is_heritage": True,
        "base_description": "木造的調度廠房飄散著機油與松木的氣味。幾輛森林鐵路的蒸汽機車停在側線，\n車身塗著暗紅，是從阿里山原始森林裡運材而生的機器。\n技師們蹲在車輪旁敲打、測量，每一道維修記錄都是一頁林業史。",
        "travel": "你走進阿里山鐵路調度場，蒸汽的嘶嘶聲和金屬敲擊聲交織成這個地方特有的節奏。",
        "names": [("japanese", "嘉義製材所鐵道部"), ("postwar", "阿里山鐵道修理廠"), ("modern", "阿里山鐵路調度場")],
        "connections": ["chiayi_train_station", "lumber_yard_chiayi"],
        "rumors": ["老技師說調度場最裡面有一節車廂從來沒有打開過，鑰匙在日本人手裡，現在不知道去哪了。"],
    },
    {
        "id": "central_market",
        "canonical_name": "嘉義東市場",
        "is_heritage": True,
        "base_description": "東市場的磁磚屋頂在清晨五點就已燈火通明。\n豬肉攤、魚攤、蔬菜行依著老規矩排列，走廊裡的小吃攤賣著火雞肉飯和米糕。\n每個攤位都是一個家族的命脈，從日治傳到現在，位置固定，客人固定。",
        "travel": "你走進東市場，鮮魚和滷肉的氣味同時撲來，人聲在鐵皮屋頂下迴盪。",
        "names": [("japanese", "嘉義公設市場"), ("postwar", "嘉義東門市場"), ("modern", "嘉義東市場")],
        "connections": ["chiayi_city", "chicken_rice_alley"],
        "rumors": ["市場最深處有一家布行從來不賣布，老闆整天坐在裡面喝茶，但從來沒人看過他出入過。"],
    },
    {
        "id": "chicken_rice_alley",
        "canonical_name": "雞肉飯街",
        "is_heritage": False,
        "base_description": "這條短短的巷弄裡有七家雞肉飯，每家都說自己是正宗。\n火雞肉的油香從大鍋裡蒸騰而出，澆上雞油飯，\n搭一碗苦瓜湯。嘉義人的早餐不談歷史，只談這碗飯夠不夠香。",
        "travel": "你轉進雞肉飯街，濃郁的雞油香氣立刻讓你的胃開始期待。",
        "names": [("japanese", "鶏肉料理屋台"), ("postwar", "火雞肉飯巷"), ("modern", "雞肉飯街")],
        "connections": ["central_market", "chiayi_city"],
        "rumors": ["第一家火雞肉飯老闆的阿嬤說，雞肉飯的秘訣是日本時代從軍隊廚師那邊學來的，才有火雞這個食材。"],
    },
    {
        "id": "old_city_wall",
        "canonical_name": "諸羅舊城牆遺址",
        "is_heritage": True,
        "base_description": "幾段殘存的土城牆夾在現代樓房之間，像是時代縫隙裡的殘骸。\n磚色是暗紅的，是清代的手工燒磚，每塊都有輕微的手壓紋。\n解說牌立在旁邊，說這裡曾是林爽文攻城的決戰地點。",
        "travel": "你走到舊城牆遺址，殘存的磚牆比你想像中矮，但站在它前面，有種說不清楚的重量感。",
        "names": [("qing", "諸羅縣城土牆"), ("japanese", "嘉義舊城址"), ("postwar", "嘉義古城牆"), ("modern", "諸羅舊城牆遺址")],
        "connections": ["chiayi_city", "chiayi_city_temple", "north_gate_area"],
        "hidden": True,
        "rumors": ["有人在城牆磚縫裡發現了一個小布包，裡面是幾枚清代銅錢和一張無字的紙，包包被帶走了，磚縫還在。"],
    },
    {
        "id": "north_gate_area",
        "canonical_name": "北門圓林仔街",
        "is_heritage": True,
        "base_description": "北門一帶保留了日治時代的棋盤式街道，老屋的亭仔腳連成一排廊道。\n賣蔗糖、賣糕餅、賣香的老鋪子夾在新式的透天厝之間，\n老一輩的居民說，這條街的形狀從日本時代就沒有變過。",
        "travel": "你走進北門舊街區，亭仔腳的廊道讓你暫時躲開了午後的烈日。",
        "names": [("qing", "諸羅北門街"), ("japanese", "圓林仔通"), ("postwar", "北門路商圈"), ("modern", "北門圓林仔街")],
        "connections": ["chiayi_train_station", "old_city_wall", "city_park"],
        "rumors": ["北門街的某棟老屋二樓住著一個從來沒被人見過臉的老人，房東說他租了三十年，房租從來不遲到。"],
    },
    {
        "id": "city_park",
        "canonical_name": "嘉義公園",
        "is_heritage": True,
        "base_description": "公園裡的老榕樹樹齡超過百年，幾棵大樹的根系已經把石板路拱起來。\n日治時代這裡建過一座神社，戰後神社拆了，留下了石燈籠和一段石階。\n現在有老人在樹蔭下下棋，有孩子在草地上奔跑，石燈籠就這樣靜靜待在一旁。",
        "travel": "你走進嘉義公園，老榕樹的氣根垂下來，樹蔭把午後的燥熱擋在外面。",
        "names": [("japanese", "嘉義神社"), ("postwar", "嘉義公園（舊神社址）"), ("modern", "嘉義公園")],
        "hidden": True,
        "connections": ["north_gate_area", "chiayi_city"],
        "rumors": ["公園石階下面據說有一座封閉的地窖，是當年奉安庫，神社拆了但地窖沒有，被土蓋住了。"],
    },
    {
        "id": "lumber_yard_chiayi",
        "canonical_name": "嘉義製材所遺址",
        "is_heritage": True,
        "base_description": "製材所的大型廠房骨架還在，鋼骨生著紅鏽，地面上留著鋸台的固定孔。\n這裡曾是全台最大的木材加工廠，阿里山的檜木從山上下來，\n就在這裡被剖成板材，再運往全島各地。\n木香已經散盡，只剩鐵鏽與野草。",
        "travel": "你走進製材所遺址，腳踩著碎磚，腦海裡試著想像當年機器轟鳴的景象。",
        "names": [("japanese", "嘉義製材所"), ("postwar", "台灣林產管理局嘉義廠"), ("modern", "嘉義製材所遺址")],
        "connections": ["alishan_railway_depot", "art_museum"],
        "rumors": ["製材所深處有一棟小辦公室，窗戶用磚頭封死了，有人說戰後封掉的時候裡面還有人的東西沒有帶走。"],
    },
    {
        "id": "art_museum",
        "canonical_name": "嘉義市立美術館（畫都）",
        "is_heritage": True,
        "base_description": "嘉義被稱為「畫都」，因為日治時代出了陳澄波等一批台灣西洋畫家。\n美術館的白牆上掛著油畫，窗口透進的自然光讓畫面的色彩靈動。\n有一幅畫的角落簽了日文，但畫的是諸羅山的夕陽——那個時代的矛盾就夾在這兩件事之間。",
        "travel": "你走進美術館，陽光透過高窗落在地板上，四周出奇地安靜。",
        "names": [("japanese", "嘉義美術展覽所"), ("postwar", "嘉義社教館"), ("modern", "嘉義市立美術館")],
        "connections": ["lumber_yard_chiayi", "chiayi_city"],
        "rumors": ["館藏裡有一幅沒有標示作者的畫，策展人說那幅畫在二二八後就一直掛在這裡，從來沒有人來認領。"],
    },
    {
        "id": "lantern_street",
        "canonical_name": "燈籠街",
        "is_heritage": False,
        "base_description": "這條窄巷的兩側掛滿了大大小小的紅燈籠，有廟宇訂製的、有婚慶用的、有祭典用的。\n燈籠師傅坐在店裡用竹篾彎出骨架，外面糊上薄薄的紅紙，\n再用毛筆寫上字。一個燈籠從頭到尾大概三十分鐘，師傅手從不停。",
        "travel": "你走進燈籠街，紅色的光把整條巷子染成暖橘色，微風吹來，燈籠在頭頂輕輕搖晃。",
        "names": [("japanese", "提燈製造所通"), ("postwar", "燈籠巷"), ("modern", "燈籠街")],
        "connections": ["chiayi_city_temple", "chiayi_city"],
        "rumors": ["燈籠師傅說他爺爺做過一批燈籠，送去掛二二八那天義勇軍的指揮部，後來那批燈籠沒有回來，人也沒有。"],
    },
    {
        "id": "performance_stage",
        "canonical_name": "嘉義公會堂",
        "is_heritage": True,
        "base_description": "日式風格的公會堂外牆已修復，正面的山牆保留著昭和年間的洗石子工藝。\n門廊的木柱打磨得光滑，廳內可容納數百人。\n這裡曾舉辦過皇民奉公演講，也曾在某個夜晚擠滿了不知道明天會如何的人。",
        "travel": "你走進公會堂，腳步在木地板上發出迴響，空曠的大廳讓聲音顯得格外清晰。",
        "names": [("japanese", "嘉義公會堂"), ("postwar", "嘉義市民會堂"), ("modern", "嘉義公會堂（修復）")],
        "connections": ["chiayi_city", "lantern_street"],
        "rumors": ["有個老人說公會堂地板下有一個密室，是日本時代防空用的，入口在舞台右側的一塊活動地板。"],
    },
    {
        "id": "police_station_old",
        "canonical_name": "嘉義警察署舊址",
        "is_heritage": True,
        "base_description": "磚紅色的建築正面有著規整的拱廊，屋頂的馬薩式屋頂是日治官廳的標準配備。\n玄關的石柱被磨得光滑，是幾十年的腳步踩出來的。\n二二八期間，這裡是衝突的核心地點之一。",
        "travel": "你站在舊警察署前，建築本身說不了話，但牆上的彈孔痕跡還在。",
        "names": [("japanese", "嘉義警察署"), ("postwar", "嘉義市警察局"), ("modern", "嘉義警察署舊址（文化資產）")],
        "hidden": True,
        "connections": ["chiayi_city", "old_city_wall"],
        "rumors": ["警察署地下室的檔案室在二二八後被清理過，有人說清理前有人把部分檔案帶走，至今不知去向。"],
    },
    {
        "id": "chiayi_old_hospital",
        "canonical_name": "嘉義公立醫院舊址",
        "is_heritage": True,
        "base_description": "這棟白色木造建築現在是醫療史文物館。長廊兩側的診間還保留著舊式的木製藥櫃，\n抽屜上貼著日文藥名的標籤。\n日治時代的護士制服掛在展示架上，白得像一個遙遠而乾淨的年代。",
        "travel": "你走進舊醫院的長廊，消毒水的氣味早已不在，只有木材與時間的氣味。",
        "names": [("japanese", "嘉義公立醫院"), ("postwar", "嘉義市立醫院"), ("modern", "嘉義公立醫院文物館")],
        "connections": ["chiayi_city", "city_park"],
        "rumors": ["醫院舊手術室的牆壁上有幾個字，說是二二八那幾天有傷患被藏在手術室裡，字是他們用血寫的，後來被漆掉了。"],
    },
    {
        "id": "chenghuang_well",
        "canonical_name": "城隍廟旁古井",
        "is_heritage": False,
        "base_description": "城隍廟東側的巷弄裡藏著一口古井，井欄的石頭已被水桶繩索磨出深深的溝痕。\n現在加了鐵蓋，但每逢清明，廟方仍會開井祭拜。\n附近居民說，這口井的水在颱風過後特別甘甜。",
        "travel": "你找到那口古井，俯身往下看，水面反出一個小小的天空。",
        "names": [("qing", "諸羅城隍廟義井"), ("japanese", "城隍廟境內井"), ("modern", "城隍廟旁古井")],
        "hidden": True,
        "connections": ["chiayi_city_temple"],
        "rumors": ["老廟公說這口井在日本人來以前就有了，清代有人在井底發現過一個銅製的符令，後來供在廟裡，現在不知道在哪個神龕。"],
    },
    {
        "id": "sugar_refinery_north",
        "canonical_name": "嘉義製糖所（北廠）",
        "is_heritage": False,
        "base_description": "北廠的煙囪在嘉義市北邊的天際線上清晰可見。\n採收季時，甘蔗車一輛接一輛，整個街區瀰漫著熱糖的甜膩氣味。\n工人三班制，廠燈從未熄滅，是嘉義平原工業化最直白的象徵。",
        "travel": "你走近糖廠，熱氣從磚牆縫隙滲出來，空氣裡有甜膩的蔗糖香。",
        "names": [("japanese", "嘉義製糖株式會社北廠"), ("postwar", "台糖嘉義廠"), ("modern", "嘉義製糖所北廠（廢棄）")],
        "connections": ["north_gate_area", "alishan_railway_depot"],
        "rumors": ["糖廠倉管說有一個特定的磚頭格，裡面從日本時代起就從來沒有被清空過，格子上貼著封條，但封條是舊的。"],
    },
    {
        "id": "chiayi_confucian_temple",
        "canonical_name": "嘉義孔廟",
        "is_heritage": True,
        "base_description": "孔廟的大成殿紅牆黃瓦，前庭的旗桿底座刻著「禮義廉恥」四字。\n教諭祭孔的時節，各校師生排排站，用台語唸祭文，\n聲音在古老的院落裡迴盪，帶著一種複雜的官方莊嚴。",
        "travel": "你踏進孔廟的前庭，腳步放輕了，也說不清楚為什麼。",
        "names": [("qing", "諸羅縣文廟"), ("japanese", "嘉義孔廟"), ("postwar", "嘉義市孔子廟"), ("modern", "嘉義孔廟")],
        "connections": ["chiayi_city", "old_city_wall"],
        "rumors": ["孔廟的大門最後一道檻曾在日本時代被迫降低高度，說是要讓人不用低頭就能進入，老人說那是對聖人的不敬。"],
    },
    {
        "id": "riverside_settlement",
        "canonical_name": "八掌溪河岸聚落",
        "is_heritage": False,
        "base_description": "八掌溪的堤防外是一片河岸低地，住著幾戶靠打漁與種菜維生的家庭。\n竹造的屋子搭得低矮，颱風來前全家要往城裡跑。\n溪邊的日落最美，但美景只有這幾戶人家有空看。",
        "travel": "你走到八掌溪堤防外，河風把城市的聲音隔絕在遠處，眼前只有水聲和蘆葦。",
        "names": [("qing", "打貓溪河埔地"), ("japanese", "八掌溪河岸"), ("modern", "八掌溪河岸聚落")],
        "connections": ["north_gate_area"],
        "rumors": ["颱風過後溪邊有人發現一具木頭漂來，上面刻了地圖，但地圖指向的位置在現在的嘉義公園，挖不得。"],
    },
    {
        "id": "chiayi_broadcasting",
        "canonical_name": "嘉義放送局",
        "is_heritage": True,
        "base_description": "矮矮的磚造廠房裡有一個播音間，麥克風和轉盤機現在已是展示品。\n二二八那天，有人試圖佔領這裡向全嘉義廣播，\n廣播出去了，但廣播的人後來消失了。",
        "travel": "你走進放送局，看著展示的廣播設備，麥克風的質感讓你有一種想說話又說不出口的感覺。",
        "names": [("japanese", "嘉義放送局"), ("postwar", "嘉義廣播電台"), ("modern", "嘉義放送局文化資產館")],
        "hidden": True,
        "connections": ["chiayi_city", "performance_stage"],
        "rumors": ["館方人員說，展示的那個麥克風曾在二二八那天對著嘉義說話，但說了什麼，沒有錄音留下來。"],
    },
    {
        "id": "qipao_tailor_chiayi",
        "canonical_name": "旗袍裁縫鋪",
        "is_heritage": False,
        "base_description": "這間縫紉鋪子從日本時代就在這條巷子裡，師傅的手法是本省與外省風格的混合體。\n牆上貼著幾張款式圖，一半是旗袍，一半是台式大襟衫。\n縫紉機的聲音從早到晚沒有停過。",
        "travel": "你走進裁縫鋪，師傅抬頭看你一眼，點點頭，繼續縫他的布料。",
        "names": [("japanese", "洋裁仕立屋"), ("postwar", "旗袍縫製行"), ("modern", "旗袍裁縫鋪")],
        "connections": ["central_market", "chiayi_city"],
        "rumors": ["裁縫師傅說有個老客人每年來取一件旗袍，但從來不量身，每次拿走的都剛好合身，師傅說那客人五十年沒有變過。"],
    },
    {
        "id": "chiayi_county_hall_old",
        "canonical_name": "嘉義縣廳舊址",
        "is_heritage": True,
        "base_description": "縣廳的石階寬闊，正面的石柱一字排開，有一種讓人仰視的官廳氣勢。\n現在建築已改作他用，但石柱留著，柱頭的龍形雕飾在風化後模糊了線條，\n卻更顯古拙。",
        "travel": "你站在縣廳舊址前，石柱的高度讓你不由自主地抬起頭。",
        "names": [("qing", "諸羅縣署"), ("japanese", "嘉義廳廳舍"), ("postwar", "嘉義縣政府"), ("modern", "嘉義縣廳舊址（保存建築）")],
        "connections": ["old_city_wall", "chiayi_city"],
        "rumors": ["舊縣廳的某個房間，地板比周圍低了幾公分，有人說那是清代官員秘密藏公文的坑道入口，後來被填起來了。"],
    },
    {
        "id": "incense_shop_chiayi",
        "canonical_name": "百年香舖",
        "is_heritage": False,
        "base_description": "紅磚店面的牆腳堆著成捆的線香，空氣裡的沉香木香和萬壽菊粉的氣味層層疊疊。\n老闆說他家的配方傳了四代，日治時代差點因為「奢靡之物」的命令被取締，\n靠著說成「衛生防疫用品」才撐下來。",
        "travel": "你走進香舖，大量的香氣同時湧入，片刻後你的嗅覺才漸漸分辨出不同的氣味。",
        "names": [("qing", "諸羅香燭鋪"), ("japanese", "線香製造所"), ("postwar", "百年香行"), ("modern", "百年香舖")],
        "connections": ["chiayi_city_temple", "lantern_street"],
        "rumors": ["香舖老闆說有一種香已經停產了，因為配方的某樣原料在戰後進不來，但廟裡有幾個老委員還在問有沒有存貨。"],
    },
    {
        "id": "noodle_stall_chiayi",
        "canonical_name": "火雞肉飯老攤",
        "is_heritage": False,
        "base_description": "攤子就是一個兩輪推車，老闆娘把飯盛進小碗，澆一匙雞油、鋪幾條手撕火雞肉，\n再挖一小匙蔥酥，動作像刻在手裡的反射。\n每天早上六點開攤，兩個小時賣完，年年如此，沒有例外。",
        "travel": "你來到老攤，隊伍已經排了十幾個人，隊伍移動得很快，每個人都知道要點什麼。",
        "names": [("japanese", "鶏肉料理屋台"), ("postwar", "火雞肉飯推車"), ("modern", "火雞肉飯老攤")],
        "connections": ["chicken_rice_alley"],
        "rumors": ["老攤旁邊的大樹有個樹洞，老闆娘說每天收攤前她都會把一碗飯放在樹洞旁，五十年了，從來沒有忘記過，說是給「老主顧」的。"],
    },
    {
        "id": "chiayi_prison_old",
        "canonical_name": "嘉義監獄舊址",
        "is_heritage": True,
        "base_description": "扇形輻射狀的獄房格局是日本殖民者從西方移植來的監控設計，\n一個守衛站在圓心可以看到所有廊道。\n現在是文化園區，但走廊的長度和鐵門的重量感還在，\n讓每一個走過去的人都不由得放慢腳步。",
        "travel": "你走進監獄舊址，腳步聲在長廊裡迴盪，和當年是同樣的聲音。",
        "names": [("japanese", "嘉義刑務所"), ("postwar", "嘉義監獄"), ("modern", "嘉義監獄文化園區")],
        "hidden": True,
        "connections": ["old_city_wall", "police_station_old"],
        "rumors": ["某個牢房的牆壁上有用指甲刻的字，刻的是日文和台語交替的一首詩，沒有名字，日期是昭和二十二年三月。"],
    },
]

os.makedirs(SITES_DIR, exist_ok=True)
created = 0

for site in sites:
    filepath = os.path.join(SITES_DIR, f"{site['id']}.yaml")
    if os.path.exists(filepath):
        print(f"SKIP (exists): {site['id']}")
        continue

    names_yaml = "\n".join(
        f"  - era: {era}\n    name: {name}" for era, name in site["names"]
    )
    connections_yaml = "\n".join(f"  - {c}" for c in site["connections"])
    rumors_yaml = "\n".join(f'  - "{r}"' for r in site.get("rumors", []))

    hidden_line = "hidden: true\n" if site.get("hidden") else ""

    content = f"""id: {site['id']}
settlement: chiayi_city
canonical_name: {site['canonical_name']}
is_heritage: {str(site['is_heritage']).lower()}
{hidden_line}base_description: |
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(site['base_description'].strip().splitlines()))}
travel_arrive_text: "{site['travel']}"

names:
{names_yaml}

{"rumors:" + chr(10) + rumors_yaml if rumors_yaml else ""}

connections:
{connections_yaml}
"""
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"CREATED: {site['id']}")
    created += 1

print(f"\nDone. Created {created} site files.")
