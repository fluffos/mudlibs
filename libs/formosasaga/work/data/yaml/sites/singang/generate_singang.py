#!/usr/bin/env python3
"""Batch generate all singang content."""
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"
SITES_DIR = f"{BASE}/sites/singang"
os.makedirs(SITES_DIR, exist_ok=True)

def write(path, content):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if os.path.exists(path):
        print(f"  SKIP: {os.path.basename(path)}")
        return
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  OK: {os.path.basename(path)}")

# ─── SITES (10 new, total 12) ──────────────────────────────────────────────────
print("=== SITES ===")

# Update singang.yaml with 4 eras
write(f"{SITES_DIR}/singang.yaml", """\
id: singang
settlement: singang
canonical_name: 新港鄉（奉天宮前廣場）
is_heritage: true
base_description: |
  奉天宮的正殿金碧輝煌，廟頂的剪黏在陽光下閃著色彩。
  廟前廣場鋪著紅色磁磚，信眾從四面八方湧來，手捧金香，
  排成長龍等候擲筊問聖。廣場四周是香藝店和糕餅鋪，
  空氣混合著線香、烤米糕和稻田來的微風。
  這裡曾是西拉雅族新港社的聚落中心，幾百年後成了媽祖的聖域。
travel_arrive_text: "你沿著縣道行進，穿過綠意盎然的稻田，來到了媽祖信仰重鎮——新港鄉。"
footprint: geo:singang

names:
  - era: dutch
    name: 新港社（Sinkang）
  - era: qing
    name: 笨港新南港
  - era: japanese
    name: 新港庄
  - era: modern
    name: 新港鄉

rumors:
  - "廟裡有一塊石碑，背面刻著西拉雅文字，說是荷蘭時代留下來的，廟方說那是鎮廟之寶，不對外展示。"
  - "奉天宮媽祖的衣服每年要換，老廟公說換下來的舊衣從來不燒，說是要讓媽祖的靈氣留著。"

connections:
  - singang_market
  - fengtian_temple_inner
  - xilaya_stone_site
  - incense_workshop
""")

# Update singang_market.yaml with 3 eras
write(f"{SITES_DIR}/singang_market.yaml", """\
id: singang_market
settlement: singang
canonical_name: 新港市場
is_heritage: false
base_description: |
  廟前廣場旁延伸出的市集，早上五點就開攤了。
  鴨肉羹的大鍋咕嘟咕嘟地滾著，糯米糕堆在竹盤上，
  粉圓冰用扁擔挑著繞場叫賣。農民把剛採的花生和地瓜
  倒在布上，坐著等客人自己蹲下來挑。
travel_arrive_text: "你走進了熱鬧的新港市場，瞬間被美食的香氣與攤販的吆喝聲包圍。"
footprint: market_singang

names:
  - era: qing
    name: 笨港市集
  - era: japanese
    name: 新港市場
  - era: modern
    name: 新港市場

rumors:
  - "市場最老的鴨肉羹攤說，他們家的湯底配方是清代笨港時期傳下來的，但問細節，老闆說是家族秘密。"

connections:
  - singang
  - duck_soup_alley
""")

sites = [
    ("fengtian_temple_inner", "奉天宮正殿內殿", True,
     """\
這裡是奉天宮的心臟。媽祖神像高坐在神龕中央，
龍袍的刺繡在燭光下熠熠發光，神龕前的供桌上
堆疊著信眾帶來的花果和金紙。
內殿後方的牆壁上掛著幾塊有年份的匾額，
其中一塊是雍正年間的，邊緣已經發黑。""",
     "你通過重重香煙走進正殿，空氣變得更沉、更暖，充滿了幾百年信仰積累的重量。",
     [("dutch", "新港社祭祀場所"), ("qing", "笨港天后宮分宮"), ("japanese", "新港奉天宮"), ("modern", "奉天宮正殿")],
     ["fengtian_shrine_garden"],
     ["殿內有一個神龕是空的，廟公說那是給「還沒有來的神明」留的位置，但問是哪位神明，廟公笑而不答。"],
     True),
    ("xilaya_stone_site", "新港社遺址（西拉雅石板墓）", True,
     """\
奉天宮廟埕側邊的草叢裡立著幾塊風化的石板，
是荷蘭時代西拉雅族新港社的墓葬遺址。
石板表面的刻紋已模糊，但幾何圖形的輪廓還依稀可辨。
解說牌是新的，但石板是幾百年前埋下的。""",
     "你找到那幾塊石板，半掩在草叢中，用手撥開草，石板的重量讓你意識到它在這裡站了很久。",
     [("dutch", "新港社石板墓群"), ("qing", "西拉雅舊址"), ("modern", "新港社遺址")],
     ["singang", "beimen_creek_old"],
     ["有學者說新港社的石板墓群不只廟埕這幾塊，還有更多埋在附近農田的地下，農耕時偶爾會犁出石板。"],
     True),
    ("incense_workshop", "香藝工坊", False,
     """\
新港以製香聞名，這間工坊是幾代傳下來的老字號。
師傅把香粉和水混合，壓成細長的香條，
再送上竹架晾曬。晴天的午後，整個院子都是線香的甜香。
師傅說每種香的粗細、長短都有固定的用途，
廟用的、家用的、大型祭典用的，都不一樣。""",
     "你走進香藝工坊，香粉的塵香撲面而來，院子裡的竹架上掛滿了一排排還在晾乾的線香。",
     [("dutch", "西拉雅薰香儀式場所"), ("qing", "笨港製香所"), ("japanese", "新港香業工場"), ("modern", "香藝工坊")],
     ["singang", "singang_market"],
     ["工坊師傅說有一種香叫「西拉雅香」，是仿照荷蘭時代傳教士記錄的原住民薰香儀式製作的，已停產，但配方還在。"]),
    ("beimen_creek_old", "笨港溪舊河道", True,
     """\
一條河道痕跡穿過農田，現在是一條幾乎乾涸的排水溝，
兩岸的土堤上長著雜草。但如果你蹲下來看，
溝底的泥土裡偶爾會露出黑色的碎磚，是清代笨港的遺跡。
乾隆年間的大洪水就是沿著這條河道改道，
把繁華的笨港分成兩個聚落，一個在北、一個在南。""",
     "你站在舊河道旁，看著這條幾乎不像河的溝，想像當年洪水的力量。",
     [("dutch", "新港溪（Soulang River）"), ("qing", "笨港溪"), ("japanese", "笨港溪（廢河道）"), ("modern", "笨港溪舊河道")],
     ["xilaya_stone_site", "singang"],
     ["附近農民說每次深耕，都會從土裡翻出幾塊清代的磚頭或陶片，攢了幾十年，現在放在家裡當門擋。"]),
    ("fengtian_shrine_garden", "奉天宮後花園（舊社遺跡）", False,
     """\
廟的後方有一片不開放給一般信眾的花園，
老榕樹的氣根垂到草地上，角落裡有幾根石柱，
是荷蘭時代基督教堂的殘跡。
傳教士就是在這片土地上，用新港語（羅馬字）
教西拉雅族人讀書寫字，留下了「新港文書」。""",
     "你繞到廟的後方，找到那片不太顯眼的花園，幾根舊石柱靜靜地站在老榕樹旁。",
     [("dutch", "新港教堂遺址"), ("qing", "天后宮後院"), ("modern", "奉天宮後花園")],
     ["singang", "singang_school_old"],
     ["老廟公說，後花園的石柱下面有荷蘭人的地基，雨後泥土鬆了，有時候可以看到更深的石頭從地裡冒出來。"],
     True),
    ("singang_school_old", "新港公學校舊址", True,
     """\
日治時代建的公學校，木造校舍的屋頂保留著，
但教室已改成農會的倉庫。長廊的木柱被蟲蛀了一部分，
柱腳有用水泥修補的痕跡。
操場邊的牆壁上還可以看到模糊的石灰字跡，
是日文的標語，字太模糊，只認得出最後兩個字：「奉仕」。""",
     "你走進舊校舍的長廊，木地板發出一聲長長的吱呀，提醒你這棟建築的年紀。",
     [("japanese", "新港公學校"), ("postwar", "新港國民學校"), ("modern", "農會倉庫（舊公學校）")],
     ["singang", "bamboo_craft_studio"],
     ["牆上那個「奉仕」的字，有老師說後面其實還有兩個字，只是被石灰蓋掉了，那兩個字是「奉公」。"]),
    ("bamboo_craft_studio", "竹藝工作坊", False,
     """\
新港的竹藝是卑南、西拉雅混合本土技藝發展出來的工藝。
工作坊裡堆著各種粗細的竹管，師傅用彎刀把竹子劈成薄片，
眼睛不看手，靠的是幾十年的手感。
完成的竹編品——籃子、帽子、燈籠骨架——
掛在牆上排成一片，像一個竹子的圖書館。""",
     "你走進工作坊，竹子的清香和削竹的聲音讓這個地方充滿了安靜的生氣。",
     [("dutch", "西拉雅竹編工藝場"), ("qing", "笨港竹藝所"), ("japanese", "新港竹細工作所"), ("modern", "竹藝工作坊")],
     ["singang_school_old", "singang_market"],
     ["竹藝師傅說有一種竹編圖案叫「新港紋」，是西拉雅族的傳統紋樣，他在一本荷蘭時代的手稿上看過，試圖復原了十年，還差一點。"]),
    ("duck_soup_alley", "鴨肉羹巷", False,
     """\
這條巷弄只有三家店，但全部賣鴨肉羹，三家都說自己是正宗。
湯頭是雞鴨混熬的，勾了薄芡，鴨肉絲鋪在上面，
淋幾滴烏醋，撒一把芹菜末。
這是新港人的早餐和下午茶，也是廟會之後必吃的東西。""",
     "你走進鴨肉羹巷，三家店的鍋子都在滾，你得做個選擇。",
     [("qing", "笨港鴨肉店街"), ("japanese", "新港鴨肉料理通"), ("modern", "鴨肉羹巷")],
     ["singang_market", "singang"],
     ["最老的那家說，鴨肉羹的湯底是連續熬了三十年沒有換過的，每天補新的材料進去，老湯從來沒有清空。"]),
    ("singang_rice_paddy", "笨港平原稻田", False,
     """\
從奉天宮往外走五分鐘，城鎮邊界突然消失，
眼前是一片平坦的稻田，延伸到遠處的嘉南平原。
水田反著天光，白鷺鷥在田間踱步。
農夫開著耕耘機的聲音從遠處傳來，是這個時代的農事節奏。""",
     "你走出村子，站在田埂上，嘉南平原在眼前展開，一望無際。",
     [("dutch", "西拉雅農耕地"), ("qing", "笨港農田"), ("japanese", "新港庄水田"), ("modern", "笨港平原稻田")],
     ["singang", "beimen_creek_old"],
     ["稻田深處有個廢棄的小土地公廟，廟身只有兩塊磚那麼高，農民說那是西拉雅時代留下來的，改不了，就保留著。"]),
]

for (sid, cname, heritage, desc, travel, names_list, conns, rumors, *hidden) in sites:
    names_yaml = "\n".join(f"  - era: {e}\n    name: {n}" for e, n in names_list)
    conns_yaml = "\n".join(f"  - {c}" for c in conns)
    rumors_yaml = "\n".join(f'  - "{r}"' for r in rumors)
    hidden_line = "hidden: true\n" if hidden else ""
    desc_indented = "\n  ".join(desc.strip().splitlines())
    content = f"""id: {sid}
settlement: singang
canonical_name: {cname}
is_heritage: {str(heritage).lower()}
{hidden_line}base_description: |
  {desc_indented}
travel_arrive_text: "{travel}"

names:
{names_yaml}

rumors:
{rumors_yaml}

connections:
{conns_yaml}
"""
    write(f"{SITES_DIR}/{sid}.yaml", content)

# ─── NPCs (12) ────────────────────────────────────────────────────────────────
print("\n=== NPCs ===")
npcs = [
    ("NPC_temple_matron_singang", "奉天宮廟婆阿鳳", "temple_keeper", "singang",
     "頭髮花白、身穿素色唐裝的老婦人，在廟埕間輕快行走，偶爾停下來整理供桌的花果。",
     {"媽祖": "媽祖從湄洲渡海來台，最先落腳在笨港，那是幾百年前的事了。新港這尊是真正的古媽，神威顯赫，你有什麼事，就去問她，她知道的比我多。",
      "西拉雅": "你問西拉雅？這片土地原來是他們的，叫做新港社。媽祖來了以後，他們有些人也跟著拜媽祖，兩種信仰在同一片土地上共存，很奇妙。",
      "石碑": "（神情謹慎）那塊碑是廟的秘密，你要看，要先問過總幹事，我沒有資格讓你進去。但我告訴你，那塊碑的字不是中文，也不是日文。",
      "傳言": "空的神龕？那個位置留了很久了，老廟公說那是給一個還沒有找到身份的神明留的。什麼神明，他沒有說，我也沒有問。"}),
    ("NPC_incense_master_singang", "香藝師傅阿福", "craftsman", "incense_workshop",
     "五十多歲的男人，手指染著深棕色的香料色，說話緩慢，思考時習慣閉著眼睛。",
     {"香": "新港的香和嘉義的香不一樣。嘉義偏沉木系，新港用的是在地的藥材和花材，氣味比較清甜，適合廟用。我家做香做了四代了，現在是第五代。",
      "西拉雅香": "（睜開眼睛）你從哪裡聽說這個？那是我在嘗試復原的東西，荷蘭傳教士的紀錄裡有一段描述，說西拉雅人在祭典時燃燒某種香草，那個香草現在我知道是什麼，但量太少了，還沒辦法大量製作。",
      "竹藝": "竹藝師傅和我是朋友，我用他的竹管做香架，他有時候用我的香做氣息測試，看竹子的氣味和香會不會衝突。我們都在做跟記憶有關的事。",
      "傳言": "西拉雅香的配方？有一半我知道，另一半我懷疑寫在廟後花園那些石柱附近的地下。我沒有去挖，那是古蹟。"}),
    ("NPC_bamboo_artist_singang", "竹藝師傅阿珠", "craftsman", "bamboo_craft_studio",
     "三十多歲的年輕女性，短髮，手指有幾道乾裂的細紋，說話直接、自信，對工藝充滿自豪。",
     {"竹藝": "新港的竹藝傳統比你想像的古老，西拉雅族就有竹編，荷蘭人來了之後，傳教士把他們看到的圖案記錄下來。我從那些記錄復原了幾個圖案，但還有一個叫「新港紋」的，我還在研究。",
      "新港紋": "那個紋樣的複雜度超出我的預期，它不只是幾何圖形，裡面有方向性，像是地圖，或者某種儀式的空間描述。我不確定，但它不只是裝飾。",
      "歷史": "新港是西拉雅族最重要的聚落，荷蘭人選這裡設立第一個學校，教西拉雅族讀書寫字。那些字後來叫「新港文書」，是台灣最早的原住民文字記錄。",
      "傳言": "竹藝工坊的那個圖案？對，就是我說的那個。我把它掃描下來，放大，發現它的形狀和奉天宮廟埕的平面圖幾乎一樣。我不知道這代表什麼，但感覺很重要。"}),
    ("NPC_siraya_elder_singang", "西拉雅後裔阿甘伯", "elder", "xilaya_stone_site",
     "黝黑瘦削的老人，額頭有深刻的皺紋，坐在石板墓旁邊的大樹蔭下，像是守著什麼。",
     {"西拉雅": "我是西拉雅人，第幾代我不確定了，連我阿公也說不清楚。我們這裡在地圖上叫新港鄉，但我們的祖先叫這裡「新港社」。名字換了，但土地還是一樣的土地。",
      "石板": "這些石板是祖先的墓，我每天來看一看，確認還在。不是因為有人要偷，是因為如果沒有人看，它就只是石頭，不是記憶了。",
      "荷蘭": "荷蘭人來的時候，我們的祖先學了羅馬字，能夠寫契約、寫信。那些文字後來叫做「新港文書」，現在散在各個博物館裡。我希望有一天全部回來。",
      "傳言": "你說新港紋？那個竹藝師傅說的圖案，我阿嬤的阿嬤也會編，但她說那個圖案是一種祈禱，不是裝飾，你把它編出來就是在說一件事，但說什麼，她沒有告訴後代了。"}),
    ("NPC_duck_soup_grandma", "鴨肉羹阿嬤", "vendor", "duck_soup_alley",
     "矮小精壯的老婦人，手持大杓，站在滾著湯的大鍋旁，眼睛永遠盯著鍋裡的狀態。",
     {"鴨肉羹": "我家的湯是笨港時代傳下來的，那時候新港還叫笨港。我阿嬤說，湯從沒有清空過，只是每天補料進去。你說這是真的嗎？我相信，因為這個湯就是和別家不一樣。",
      "笨港": "笨港就是舊新港，清朝時候的大港口，船從大陸來，停在笨港溪口。後來溪流改道，港口淤積，人就分成兩邊走。這邊是新港，那邊是北港。",
      "廟": "媽祖是從笨港時代就有的，但是後來分家了，北港供奉一尊，新港供奉一尊，兩邊都說自己才是正宗的媽祖。這件事我問了一輩子，答案我不說。",
      "傳言": "三十年老湯？這是真的，不是傳言。但老湯裡還有什麼，那才是秘密。我阿嬤說裡面有一塊她媽媽的骨灰，說這樣祖先就一直在湯裡護佑。我不確定，但我不敢清湯底。"}),
    ("NPC_rice_farmer_singang", "笨港平原老農阿德", "farmer", "singang_rice_paddy",
     "六十歲出頭，皮膚暗沉，手背有老繭，蹲在田埂上看水位，和農田之間有一種無聲的默契。",
     {"稻田": "嘉南平原的土肥，種什麼都好。我種稻，我阿爸種稻，往前幾代也種稻。土地不變，人換，但和土地的對話每天都一樣：今天水夠不夠，今天風對不對，今天蟲多不多。",
      "西拉雅": "這裡以前是西拉雅的地，他們也種地，種不一樣的東西。我有次深耕挖出一塊石頭，上面有花紋，不像漢人的東西，我放在田邊讓它繼續待著。",
      "水利": "嘉南大圳是日本時代蓋的，我阿公說以前灌溉靠天，大圳來了才穩定。但蓋圳的工程，死了很多人，包括原住民工人，這件事沒什麼人提。",
      "傳言": "廢棄的小土地公廟？那是我爺爺說的，說那個廟是西拉雅人蓋的，拜的不是土地公，是他們的祖靈，但漢人來了之後改說是土地公，大家就接受了，這樣兩邊都說得通。"}),
    ("NPC_historian_singang", "新港文史工作者阿明", "scholar", "xilaya_stone_site",
     "戴著眼鏡、手持記事本的中年男人，說話條理清晰，對每一個歷史細節都有不尋常的熱情。",
     {"新港文書": "新港文書是台灣最珍貴的原住民歷史文件，用羅馬字寫的西拉雅語，記錄了清代漢人向西拉雅族購買土地的契約。那些契約現在散在國內外各個博物館，要完整看到全部，得跑好幾個城市。",
      "西拉雅": "西拉雅族在清代被認為是「熟番」，漢化程度較深，因此反而在歷史上更容易被忽視。他們的文化沒有完全消失，但在很多地方是以隱藏的方式存活著，比如廟裡的某些儀式，比如那個竹藝圖案。",
      "荷蘭": "荷蘭東印度公司在台灣建立了第一個系統性的行政管理，但更重要的是他們帶來了文字教育。西拉雅族因此是台灣歷史上第一個有自己書面文字的族群。這件事應該更廣為人知。",
      "傳言": "廟裡的石碑？我知道它的存在，但廟方不讓我拍照，只讓我看了幾分鐘。碑上的文字是荷蘭時代的羅馬字，我只看清楚了幾個字，但那幾個字已經讓我研究了三年。"}),
    ("NPC_temple_keeper_old_singang", "老廟公阿春", "elder", "fengtian_shrine_garden",
     "八十多歲，走路緩慢但穩健，在廟後花園一帶守護，見到訪客眼神警覺，見到有誠意的人才開口。",
     {"後花園": "廟後面的花園是不對外開放的，你怎麼進來的？算了，進來了就進來了。這個地方是荷蘭人蓋教堂的舊址，石柱留到現在，我每天來看，確認它還在。",
      "石柱": "那幾根石柱是荷蘭人留下的，是花崗岩，比廟的建材還好。我有時候靠著它坐，感覺比靠廟牆更穩，不知道為什麼。",
      "新港文書": "荷蘭人在這裡教西拉雅族讀書，就在這個地方。新港文書就是在這片土地上誕生的，想到這件事，這幾根石柱就不只是石柱了。",
      "傳言": "地下？（停頓很久）有一次雨後，石柱旁邊的土塌陷了一個坑，我去看，坑底有幾個磚頭，比廟的磚更舊，顏色更深，我把土填回去，沒有跟人說，但我知道那裡有什麼。"}),
    ("NPC_school_teacher_singang", "舊公學校老師水仙", "teacher", "singang_school_old",
     "六十多歲的退休老師，用農會倉庫當舊教室，偶爾在這裡整理記錄，說話帶著說故事的韻律。",
     {"學校": "公學校在這裡，我在這裡讀書，也在這裡教書，教了三十年。後來改成農會倉庫，我還是會來，坐在老位置上發呆一會兒。",
      "日本時代": "日本時代的學校教的是日語、算術、修身。修身課是最有趣的，因為那個課在教某種價值觀，我小時候讀，長大了才看出來它在教什麼，那個覺悟讓我對「教育」這兩個字有了不一樣的理解。",
      "奉仕": "牆上那兩個字，完整的是「奉公奉仕」，奉公就是服從政府，奉仕就是貢獻社會。日本政府把這兩件事放在一起教，意思是說，服從就是貢獻。我教書三十年，盡量不這樣教。",
      "傳言": "我在整理倉庫的時候發現一個日治時代的教師日誌，裡面有一頁寫到「昨天課後，有幾個孩子問我，西拉雅語怎麼說天空，我不知道，我感到羞愧」。那個老師的名字已經不清楚了，但那句話我記得。"}),
    ("NPC_photographer_singang", "廟會攝影師阿志", "artist", "singang",
     "四十歲左右，單眼相機掛在脖子上，在廟埕間穿梭，身手靈活，捕捉信眾最真實的表情。",
     {"廟會": "奉天宮的廟會是台灣最大的之一，信眾從全台灣來，有些人步行幾天就為了來進香。你拍廟會，拍的不是儀式，是人，拍的是那種非常純粹的相信。",
      "信仰": "我不是很有信仰的人，但我拍廟會拍了十五年，我見過的事情讓我說不清楚信仰到底是什麼。我只知道，那種表情是真的，那種眼淚是真的。",
      "西拉雅": "有一年廟會，我看到一個老太太做了一個動作，和廟裡其他信眾都不一樣，她把香舉過頭，往後仰，像一種很古老的儀式。我拍了下來，後來有學者告訴我那是西拉雅族的傳統祭拜動作。",
      "傳言": "那個老太太？我找了她好幾年，廟裡沒有人認識她，那張照片是我最有名的一張，但我不知道那個人是誰。"}),
    ("NPC_northern_harbor_elder", "笨港老人阿德仔", "elder", "beimen_creek_old",
     "坐在舊河道旁的大石上，手持菸斗，眼神遙遠，像是在等那條河回來。",
     {"笨港": "笨港就是這裡，你看這條溝，以前是大河，大船進出的。我阿公說那時候港口熱鬧，大陸來的船帶來絲綢茶葉，台灣的稻米糖出去。一場大水，全部沖掉了。",
      "洪水": "乾隆年間的洪水，把笨港分成兩邊。北邊的人說他們才是正宗笨港，南邊的人也這樣說。後來北邊叫北港，南邊叫新港，兩個媽祖廟，兩個故事，到現在還在吵。",
      "河道": "你問河道的磚頭？那是真的，每次大雨之後，溝底就有磚頭露出來，是紅磚，清代的。我撿過幾塊，放在家裡，有人說那是古物，不能帶走。我說，我的祖先在這裡建的，我帶回家算什麼古物。",
      "傳言": "漂來的木頭？不是在嘉義公園嗎？我怎麼知道這裡也有流傳？是不是同一塊木頭，我不知道，但這裡也流傳說溪底有個箱子，一百年前有人看到，後來就看不到了。"}),
    ("NPC_sinkang_descendent_lady", "西拉雅後裔阿春嬤", "elder", "singang",
     "穿著素色棉麻衣的老婦人，眼神清明，說話時常常夾著幾個外來語無法翻譯的詞，最後解釋說那是西拉雅語。",
     {"西拉雅": "我說我是西拉雅人，很多人說你哪有，你跟我們長得一樣。但我阿嬤告訴我，我們是Sinkang社的後代，新港這個名字就是Sinkang的漢字音譯。",
      "祖靈": "我們西拉雅有阿立祖，是女性的神靈，放在甕裡，放在家的某個角落。現在很多人不拜了，但我家還有一個甕，我每天早上放一杯水，那是阿立祖喜歡的。",
      "媽祖": "（微笑）你問我媽祖和阿立祖哪個好？兩個都好。我早上拜阿立祖，廟會去拜媽祖，她們都不介意，我覺得。",
      "傳言": "竹藝那個紋樣？那個我認識，我阿嬤說那個叫「靈圖」，是Sinkang社用來召喚祖靈的圖案，不是用來裝飾的。那個竹藝師傅把它織出來，我有點擔心，但我沒有去阻止，或許祖靈早就想回來了。"})
]

for npc_id, name_zh, role, site, hint, responses in npcs:
    lines = [
        f"id: {npc_id}",
        f"name:",
        f'  zh-TW: "{name_zh}"',
        f"settlement: singang",
        f"home_site: {site}",
        f"role: {role}",
        f'hint:',
        f'  zh-TW: "{hint}"',
        "responses:",
    ]
    for topic, reply in responses.items():
        lines.append(f'  "{topic}":')
        lines.append(f'    zh-TW: "{reply}"')
    write(f"{BASE}/npcs/{npc_id}.yaml", "\n".join(lines) + "\n")

# ─── INCIDENTS (3) ─────────────────────────────────────────────────────────────
print("\n=== INCIDENTS ===")

def write_incident(inc_id, name, desc, truth, era, scope_list, clues, exp, faction, rep):
    scope = "\n".join(f"  - {s}" for s in scope_list)
    clue_yaml = ""
    for c in clues:
        clue_yaml += f"  - clue_id: {c['id']}\n    name: {c['name']}\n    source_type: {c['type']}\n    source_id: \"{c['src']}\"\n"
        if "topic" in c:
            clue_yaml += f"    ask_topic: {c['topic']}\n"
    content = f"""incident_id: {inc_id}
name: {name}
description: |
  {chr(10).join('  ' + l if i > 0 else l for i,l in enumerate(desc.strip().splitlines()))}
truth: |
  {chr(10).join('  ' + l if i > 0 else l for i,l in enumerate(truth.strip().splitlines()))}
era_active: {era}
settlement: singang
scope:
{scope}
clues:
{clue_yaml}completion_reward:
  exp: {exp}
  faction: {faction}
  reputation: {rep}
"""
    write(f"{BASE}/incidents/{inc_id}.yaml", content)

write_incident(
    "singang_sinkang_social_incident",
    "新港社的記憶：西拉雅族的消失與存續",
    """荷蘭時代，新港社（Sinkang）是西拉雅族最大聚落，擁有文字（新港文書）、學校和教堂。
清代漢人移民大量湧入後，西拉雅族逐漸被「漢化」，族名消失，語言消失，
但某些文化習俗以隱蔽的形式延續至今——在廟裡的儀式裡，在竹藝的圖案裡，
在老人口中偶爾說出的幾個無法翻譯的詞裡。
你試圖還原這段隱藏的存續史。""",
    """西拉雅族並非消失，而是以「隱形」的方式存活在漢人社會中。他們接受漢名、說漢語、拜漢人的神，
但同時保留著阿立祖信仰、特定的祭祀動作、竹編圖案中的祖靈召喚紋樣。
新港文書是這段歷史最直接的文字證據，散佚在各博物館中等待被重新認識。""",
    "dutch", ["singang"],
    [
        {"id": "xilaya_stone", "name": "西拉雅石板墓觀察", "type": "site_look", "src": "site:xilaya_stone_site"},
        {"id": "elder_testimony", "name": "西拉雅後裔阿甘伯的記憶", "type": "npc_ask", "src": "npc:NPC_siraya_elder_singang", "topic": "西拉雅"},
        {"id": "bamboo_pattern", "name": "竹藝師傅發現的祖靈圖案", "type": "npc_ask", "src": "npc:NPC_bamboo_artist_singang", "topic": "新港紋"},
        {"id": "old_lady_ritual", "name": "攝影師拍到的古老儀式動作", "type": "npc_ask", "src": "npc:NPC_photographer_singang", "topic": "西拉雅"},
    ],
    1800, "siraya_memory", 130
)

write_incident(
    "singang_bengang_split_incident",
    "笨港分裂：一場洪水、兩個媽祖、兩個城市",
    """乾隆年間，笨港溪發生重大改道，繁華的笨港港口被洪水沖毀，
人口分流，一批往北定居形成北港，一批往南定居形成新港。
兩地都保留了媽祖信仰，各自宣稱自己才是正宗的笨港媽祖。
這場分裂的影響延續至今，成為台灣廟宇文化中著名的「南北媽祖之爭」。
你試圖在舊河道、老人口述和廟史文件中還原這場分裂的始末。""",
    """笨港的分裂是一個結構性事件：洪水改變地理，地理改變人群分布，人群分布改變信仰的歸屬。
兩個城市都沒有說謊，他們都是笨港的後代。但正因為都是後代，
「誰才是正宗」這個問題就沒有答案，也不需要答案。
真正重要的是，這場洪水讓台灣多了一個關於遷徙、認同和信仰的精彩故事。""",
    "qing", ["singang"],
    [
        {"id": "creek_ruins", "name": "笨港溪舊河道的清代磚頭", "type": "site_look", "src": "site:beimen_creek_old"},
        {"id": "old_man_bengang", "name": "笨港老人阿德仔的記憶", "type": "npc_ask", "src": "npc:NPC_northern_harbor_elder", "topic": "洪水"},
        {"id": "duck_soup_bengang", "name": "鴨肉羹阿嬤的笨港故事", "type": "npc_ask", "src": "npc:NPC_duck_soup_grandma", "topic": "笨港"},
    ],
    1400, "taiwan_folk_memory", 100
)

write_incident(
    "singang_dutch_church_incident",
    "荷蘭教堂的遺跡：新港社的文字誕生地",
    """十七世紀，荷蘭東印度公司在新港社建立了第一所原住民學校，
傳教士用羅馬字拼寫西拉雅語，教導新港社族人讀書識字。
那些文字後來被稱為「新港文書」，是台灣最早的原住民書寫記錄。
教堂的實體早已消失，但石柱殘跡藏在奉天宮後花園。
你試圖透過老廟公、竹藝圖案和廟裡的石碑，還原這段文字誕生的故事。""",
    """新港文書的存在說明，在漢字和日文之前，台灣曾有另一種書寫系統在這片土地上運作。
那些文字是土地交易的契約，是族群接觸史的直接證據。
荷蘭人帶來了文字作為傳教工具，但西拉雅族把它變成了自己的記錄工具。
這種文化翻轉，是殖民地歷史中罕見的主動性展現。""",
    "dutch", ["singang"],
    [
        {"id": "stone_pillar", "name": "後花園的荷蘭石柱", "type": "site_look", "src": "site:fengtian_shrine_garden"},
        {"id": "old_keeper_underground", "name": "老廟公發現的地下空間", "type": "npc_ask", "src": "npc:NPC_temple_keeper_old_singang", "topic": "傳言"},
        {"id": "historian_stone", "name": "文史工作者看到的石碑文字", "type": "npc_ask", "src": "npc:NPC_historian_singang", "topic": "新港文書"},
    ],
    1600, "siraya_memory", 120
)

# ─── MEMORIES (8) ──────────────────────────────────────────────────────────────
print("\n=== MEMORIES ===")
memories = [
    ("singang_siraya_001", "新港社的祭典之夜", "dutch", "儀式記憶", 3, "xilaya_stone_site",
     "荷蘭傳教士第一次目睹新港社的祭典，是一個月圓的夜晚。\n族人圍成一圈，燃燒著他不認識的香草，吟唱他聽不懂的歌。\n他在日記裡寫：「他們呼喚的是祖先，或是山，或是什麼更古老的東西。\n我無法轉換成任何我學過的語言。」"),
    ("singang_siraya_002", "最後一份新港文書", "qing", "文字記憶", 3, "xilaya_stone_site",
     "嘉慶年間，最後一份用新港語（羅馬字）書寫的土地契約在這片土地上交換。\n買方是漢人移民，賣方是西拉雅族的一個家族。\n賣方在契約末尾用羅馬字寫了一行族語，\n翻譯出來的意思是：「這片土地屬於天，我們只是借住的。」"),
    ("singang_temple_001", "笨港媽祖渡海", "qing", "信仰記憶", 2, "singang",
     "傳說中，媽祖的神像從湄洲渡海，在笨港港口上岸的那天，\n海面異常平靜，而且天空出現了一道紅光。\n港口的漁民說，那道光從海面延伸到天上，像一條路，\n指引著神像的方向。無論是否真實，從那天起，笨港有了媽祖。"),
    ("singang_bengang_001", "洪水分家的那天", "qing", "災難記憶", 2, "beimen_creek_old",
     "乾隆五十一年的秋天，笨港溪決堤了。\n水從河堤湧入市區，木造的店屋漂浮在泥水中，\n有人往北跑，有人往南跑，有人站在原地看著自己的家消失在水裡。\n三天後水退了，笨港還在，但已經是兩個笨港了。"),
    ("singang_church_001", "傳教士的羅馬字課", "dutch", "教育記憶", 3, "fengtian_shrine_garden",
     "荷蘭傳教士在教堂旁的大樹下架起一塊木板，用樹枝沾著墨汁，\n教新港社的孩子認識羅馬字母。\n那些孩子學得很快，比傳教士預期的快。\n三個月後，有個孩子用羅馬字寫下了他第一句族語：「我的土地在日出的方向。」"),
    ("singang_incense_001", "製香的清晨", "modern", "日常記憶", 1, "incense_workshop",
     "清晨四點，香藝師傅起床，第一件事是確認昨天壓好的香條有沒有受潮。\n把乾燥的香條一根根放上竹架，讓它們在朝陽中慢慢乾燥。\n這個動作他做了三十年，他的師父做了四十年，師父的師父做了更多年。\n香的氣味是時間積累出來的，不是調配出來的。"),
    ("singang_bamboo_001", "竹編裡的地圖", "dutch", "謎團記憶", 2, "bamboo_craft_studio",
     "竹藝師傅把那個圖案掃描放大，比對了奉天宮的平面圖，\n發現兩者之間有一種不可思議的相似性。\n如果這個圖案真的是新港社廟埕的空間圖，\n那麼奉天宮現在的建築，站的就是西拉雅祭典的正中心。"),
    ("singang_festival_001", "進香的隊伍", "modern", "信仰記憶", 1, "singang",
     "每年農曆三月，從全台各地來的進香隊伍在奉天宮前集合。\n有人走了三天，腳上起了水泡，還是繼續走。\n攝影師問一個進香的老太太，為什麼要走這麼遠來拜媽祖？\n她說：「因為她一直在等我，我不能讓她等太久。」"),
]
for mid, title, era, etype, quality, site, desc in memories:
    desc_indented = "\n  ".join(desc.strip().splitlines())
    content = f"""id: {mid}
title: "{title}"
era: "{era}"
evidence_type: "{etype}"
quality: {quality}
progress: 10
description: |
  {desc_indented}
settlement: "singang"
trigger_site: "{site}"
conditions: []
"""
    write(f"{BASE}/memories/{mid}.yaml", content)

# ─── WORLD EVENTS (2) ─────────────────────────────────────────────────────────
print("\n=== WORLD EVENTS ===")
events = [
    ("singang_mazu_procession", "新港奉天宮媽祖遶境", "scheduled",
     """每年農曆三月，新港奉天宮舉行盛大的媽祖遶境活動，
信眾從全台各地湧入，廟前廣場和周邊街道擠滿人群，
鑼鼓聲和鞭炮聲從清晨持續到深夜。""",
     {"singang": "廟前廣場完全被信眾佔滿，香煙瀰漫，鑼鼓聲震耳欲聾，你必須側身才能在人群中移動。",
      "duck_soup_alley": "三家鴨肉羹今天供不應求，隊伍排到巷口外，老闆說這一天的量等於平日一個月。"},
     ["singang", "duck_soup_alley", "singang_market"],
     3),
    ("singang_ghost_festival", "笨港中元普渡", "scheduled",
     """農曆七月，新港依照古笨港的傳統舉行中元普渡，
沿著舊笨港溪河道一帶設立普渡桌，祭拜當年洪水中逝去的先民亡魂。
這個習俗已延續兩百多年，是笨港歷史記憶最直接的現存儀式。""",
     {"beimen_creek_old": "舊河道旁擺著長桌，普渡的供品從一端延伸到另一端，老人說每個桌位對應的是當年洪水時逝去的一個家族。",
      "singang": "廟埕上的普渡儀式同步進行，廟公說今年的普渡特別重要，因為有幾個亡魂等了很久，今年才終於有後代來祭拜。"},
     ["beimen_creek_old", "singang", "singang_market"],
     2),
]
for eid, ename, etype, desc, overrides, affected, duration in events:
    affected_yaml = "\n".join(f"  - {s}" for s in affected)
    override_yaml = "\n".join(f"    {s}: |\n      {d}" for s, d in overrides.items())
    desc_indented = "\n  ".join(desc.strip().splitlines())
    content = f"""id: {eid}
name: {ename}
type: {etype}
era_active: null
duration_days: {duration}
affected_sites:
{affected_yaml}
description: |
  {desc_indented}
effects:
  site_desc_override:
{override_yaml}
"""
    write(f"{BASE}/world_events/{eid}.yaml", content)

# ─── QUESTS (5) ───────────────────────────────────────────────────────────────
print("\n=== QUESTS ===")
quests = [
    ("quest_sinkang_pattern_singang", "新港紋的秘密", "dutch", 3,
     """竹藝師傅阿珠發現，她嘗試復原的「新港紋」
竟然和奉天宮廟埕的平面圖高度相似。
西拉雅後裔阿春嬤說，那個圖案是祖靈的召喚符，
不是用來裝飾的。你試圖找到這個圖案背後的真相。""",
     [("npc", "NPC_bamboo_artist_singang", "新港紋"),
      ("npc", "NPC_siraya_elder_singang", "傳言"),
      ("site", "fengtian_shrine_garden", "look"),
      ("npc", "NPC_sinkang_descendent_lady", "傳言"),
      ("memory", "singang_bamboo_001", None)],
     1500, "siraya_memory", 110, "singang_dutch_church_incident"),
    ("quest_bengang_split_singang", "笨港分裂的記憶", "qing", 2,
     """笨港老人阿德仔說，笨港溪舊河道底下還有清代的磚頭。
鴨肉羹阿嬤說，她家的老湯從笨港時代就沒換過。
你試圖從這些殘存的記憶中，還原乾隆年間那場洪水的影響。""",
     [("npc", "NPC_northern_harbor_elder", "洪水"),
      ("npc", "NPC_duck_soup_grandma", "笨港"),
      ("site", "beimen_creek_old", "search"),
      ("memory", "singang_bengang_001", None)],
     1200, "taiwan_folk_memory", 80, "singang_bengang_split_incident"),
    ("quest_mazu_secret_singang", "廟裡的石碑", "qing", 3,
     """廟婆阿鳳說，廟裡有一塊刻著非中文非日文字的石碑，是廟的秘密。
文史工作者阿明說，他看了幾分鐘，只認出幾個字，研究了三年。
你想看到那塊石碑，並嘗試讀出它上面的內容。""",
     [("npc", "NPC_temple_matron_singang", "石碑"),
      ("npc", "NPC_historian_singang", "新港文書"),
      ("site", "fengtian_temple_inner", "look"),
      ("npc", "NPC_temple_keeper_old_singang", "後花園"),
      ("memory", "singang_church_001", None)],
     1600, "siraya_memory", 120, "singang_dutch_church_incident"),
    ("quest_incense_siraya_singang", "西拉雅香的配方", "modern", 2,
     """香藝師傅阿福說，「西拉雅香」的配方有一半他知道，
另一半他懷疑在後花園的地下。
西拉雅後裔阿春嬤說，那種香是祭典用的，召喚祖靈用的。
你試圖找齊完整的配方，並決定它的用途。""",
     [("npc", "NPC_incense_master_singang", "西拉雅香"),
      ("npc", "NPC_sinkang_descendent_lady", "祖靈"),
      ("site", "fengtian_shrine_garden", "search"),
      ("memory", "singang_incense_001", None)],
     1100, "siraya_memory", 85, None),
    ("quest_photographer_lady_singang", "攝影師找不到的老太太", "modern", 3,
     """廟會攝影師阿志說，他拍到一個做了古老西拉雅祭拜動作的老太太，
找了好幾年，沒有人認識她。
西拉雅後裔阿春嬤說，那種動作是她阿嬤教她的，
只有西拉雅家族才知道。
那個老太太是誰？""",
     [("npc", "NPC_photographer_singang", "西拉雅"),
      ("npc", "NPC_sinkang_descendent_lady", "西拉雅"),
      ("npc", "NPC_siraya_elder_singang", "西拉雅"),
      ("site", "singang", "look"),
      ("memory", "singang_festival_001", None)],
     1300, "siraya_memory", 95, None),
]
for qid, title, era, diff, desc, objectives, exp, faction, rep, unlock in quests:
    obj_yaml = ""
    for i, obj in enumerate(objectives):
        obj_id = f"step_{i+1}"
        if obj[0] == "npc":
            obj_yaml += f"  - id: {obj_id}\n    description: \"與 {obj[1]} 對話\"\n    npc: {obj[1]}\n    ask_topic: {obj[2]}\n"
        elif obj[0] == "site":
            obj_yaml += f"  - id: {obj_id}\n    description: \"在 {obj[1]} 進行 {obj[2]}\"\n    site: {obj[1]}\n    action: {obj[2]}\n"
        elif obj[0] == "memory":
            obj_yaml += f"  - id: {obj_id}\n    description: \"解鎖記憶碎片 {obj[1]}\"\n    memory: {obj[1]}\n"
    unlock_line = f"  unlock_incident: {unlock}\n" if unlock else ""
    desc_indented = "\n  ".join(desc.strip().splitlines())
    content = f"""id: {qid}
title: "{title}"
settlement: singang
scope:
  - singang
era: {era}
difficulty: {diff}
description: |
  {desc_indented}
objectives:
{obj_yaml}completion_reward:
  exp: {exp}
  faction: {faction}
  reputation: {rep}
{unlock_line}"""
    write(f"{BASE}/quests/{qid}.yaml", content)

print("\nAll singang content done!")
