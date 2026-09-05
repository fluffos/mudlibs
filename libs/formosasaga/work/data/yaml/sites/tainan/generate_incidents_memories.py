#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Incidents (6 needed) ──────────────────────────────────────────────────────
incidents = [
    {
        "id": "tainan_dutch_landing",
        "name": "荷蘭東印度公司大員築城",
        "description": "1624年，荷蘭東印度公司在今天安平的位置建造熱蘭遮城，開啟台灣的殖民時代與大航海歷史貿易。\n你將深入探尋當時台江內海與大員市鎮的開發原貌。",
        "truth": "熱蘭遮城的建立確立了台灣作為東亞轉口港的戰略位置。荷蘭人利用其軍事優勢強迫周遭原住民族臣服，但同時引進了文字教育（新港文書）與水利、製鹽技術，奠定台江地區初期的空間結構。",
        "era": "dutch",
        "clues": [
            {"id": "fort_wall_observation", "name": "安平古堡老磚城牆", "type": "site_look", "source": "site:tainan_anping_fort"},
            {"id": "dutch_research_data", "name": "Jan學者的海牙檔案筆記", "type": "npc_ask", "source": "npc:NPC_dutch_researcher", "topic": "文書"},
            {"id": "tayouan_street_memory", "name": "大員老街的底層石階", "type": "site_look", "source": "site:tainan_anping"}
        ],
        "reward": {"exp": 1800, "faction": "siraya_memory", "reputation": 120}
    },
    {
        "id": "tainan_koxinga_landing_incident",
        "name": "永曆十五年：明鄭大軍登陸鹿耳門",
        "description": "1661年，鄭成功率領兩萬五千大兵跨越鹿耳門淺灘，奇襲普羅民遮城，圍攻熱蘭遮城，迫使荷蘭人投降撤離。\n這場戰役改寫了台灣的主權歸屬，使台灣正式進入漢人政權統治時期。",
        "truth": "鄭成功的奇襲得益於對潮汐的精準預判與在地居民的情報支援。明鄭時期的建立雖然引入了儒學與官僚體制，但其本質仍是為了解決反清復明軍費問題的軍屯政權，對西拉雅族人的生存空間造成極大擠壓。",
        "era": "koxinga",
        "clues": [
            {"id": "koxinga_landing_mark", "name": "鹿耳門登陸紀念碑", "type": "site_look", "source": "site:tainan_koxinga_landing"},
            {"id": "koxinga_reenactor_ask", "name": "表演者阿名關於登陸潮汐的看法", "type": "npc_ask", "source": "npc:NPC_koxinga_reenactor", "topic": "鄭成功"},
            {"id": "koxinga_palace_relic", "name": "寧靖王府轉為天后宮的歷史過程", "type": "site_look", "source": "site:tainan_grand_mazu_temple"}
        ],
        "reward": {"exp": 2000, "faction": "taiwan_historical_truth", "reputation": 150}
    },
    {
        "id": "tainan_bengang_harbor_incident",
        "name": "台江內海淤積與五條港的誕生",
        "description": "清代中葉，台江內海因泥沙淤積逐漸陸化，原本的大港口安平失去了直接靠岸的優勢。\n府城商家為了解決運輸問題，開鑿了五條平行水道引水入城，稱為「五條港」。\n你將調查神農街與老街區，重現這段港城變遷的歷史。",
        "truth": "五條港的興起是府城商人為了克服地理限制而進行的都市再造工程。五條港不僅是商業通道，也形成了以各水道為核心的聯境與廟宇自治網，形成了台南獨特的市街紋理與市民自治傳統。",
        "era": "qing",
        "clues": [
            {"id": "shennong_street_underground", "name": "神農街填平水道的流水聲", "type": "npc_ask", "source": "npc:NPC_shennong_barista", "topic": "神農街"},
            {"id": "silian_yan_records", "name": "聯境廟宇的清代舊帳冊", "type": "site_look", "source": "site:tainan_silian_yan"},
            {"id": "anping_harbor_relic", "name": "台江淤積痕跡調查", "type": "site_look", "source": "site:anping_harbor"}
        ],
        "reward": {"exp": 1600, "faction": "taiwan_folk_memory", "reputation": 110}
    },
    {
        "id": "tainan_shokusan_industry_incident",
        "name": "日治時期的近代化基礎設施：台南水道與林百貨",
        "description": "大正至昭和年間，日本殖民政府在台南展開大規模的基礎建設，包括現代自來水系統（台南水道）與現代化商業大樓（林百貨）。\n你將重溫這段將現代化文明引入古城的過程與代價。",
        "truth": "台南水道與林百貨象徵著日治時期的「近代化」進程。在改善公共衛生與引進現代消費生活的同時，這些設施也服務於殖民政府的統治效率，並加深了階級與族群（日本人 vs. 本島人）在資源分配上的不平等。",
        "era": "japanese",
        "clues": [
            {"id": "water_facility_engine", "name": "山上淨水場的百年大泵", "type": "npc_ask", "source": "npc:NPC_water_engineer", "topic": "老管道"},
            {"id": "hayashi_roof_shrine", "name": "林百貨頂樓的神社遺址", "type": "npc_ask", "source": "npc:NPC_hayashi_store_clerk", "topic": "神社"},
            {"id": "guofeng_sugar_train", "name": "歸仁糖廠的窄軌五分車", "type": "npc_ask", "source": "npc:NPC_sugar_train_driver", "topic": "糖廠"}
        ],
        "reward": {"exp": 1500, "faction": "taiwan_cultural_memory", "reputation": 100}
    },
    {
        "id": "tainan_228_intellectual_incident",
        "name": "台南二二八：府城知識份子的沉默",
        "description": "1647年二二八事件波及台南，府城部分知識份子與仕紳試圖進行和平談判，但隨之而來的是逮捕與長期的戒嚴肅殺。\n你將收集歷史資料，拼湊這段台南記憶中最深沉的空白。",
        "thought": "台南二二八的悲劇主要體現在事件後長期的白色恐怖與自我審查。府城各界在長達數十年的時間裡對此保持絕對的沉默，許多歷史記憶只以家書、日記等極其私密的形式存於民間角落。",
        "era": "postwar",
        "clues": [
            {"id": "museum_last_letters", "name": "二二八紀念館藏被捕者遺書", "type": "npc_ask", "source": "npc:NPC_228_museum_staff", "topic": "信件"},
            {"id": "silian_yan_old_witness", "name": "老街街區的目擊口述", "type": "npc_ask", "source": "npc:NPC_dongmen_gate_elder", "topic": "東門城"}
        ],
        "reward": {"exp": 1700, "faction": "taiwan_historical_truth", "reputation": 120}
    },
    {
        "id": "tainan_siraya_identity_incident",
        "name": "新港社後裔的阿立祖崇拜",
        "description": "雖然表面上西拉雅族人在漢化過程中消失了，但在台南新市一帶的土地公廟裡，仍然可以發現與漢人神明並列的「阿立祖」祖靈甕。\n你將探尋這段在夾縫中求存的信仰混合歷史。",
        "truth": "阿立祖與土地公的共存，是西拉雅族人在面對強大漢文化時所採取的文化適應策略。他們藉由將祖靈隱藏於漢人神殿的角落，成功地將其核心信仰脈絡延續到了現代，成為台灣多重族群史的活標本。",
        "era": "modern",
        "clues": [
            {"id": "temple_siraya_urn", "name": "土地公廟側邊的祖靈甕", "type": "npc_ask", "source": "npc:NPC_tainan_archaeology_student", "topic": "阿立祖"},
            {"id": "siraya_elder_tradition", "name": "老婦人關於阿立祖祭祀的口述", "type": "npc_ask", "source": "npc:NPC_siraya_elder_singang", "topic": "祖靈"}
        ],
        "reward": {"exp": 1400, "faction": "siraya_memory", "reputation": 95}
    }
]

# Write Incidents
print("=== Incidents ===")
for inc in incidents:
    clue_lines = []
    for c in inc["clues"]:
        clue_lines.append(f"  - clue_id: {c['id']}")
        clue_lines.append(f"    name: {c['name']}")
        clue_lines.append(f"    source_type: {c['type']}")
        clue_lines.append(f"    source_id: \"{c['source']}\"")
        if "topic" in c:
            clue_lines.append(f"    ask_topic: {c['topic']}")
    
    content = f"""incident_id: {inc['id']}
name: {inc['name']}
description: |
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(inc['description'].strip().splitlines()))}
truth: |
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(inc.get('truth', inc.get('thought', '')).strip().splitlines()))}
era_active: {inc['era']}
settlement: tainan
scope:
  - tainan
clues:
{chr(10).join(clue_lines)}
completion_reward:
  exp: {inc['reward']['exp']}
  faction: {inc['reward']['faction']}
  reputation: {inc['reward']['reputation']}
"""
    filepath = f"{BASE}/incidents/{inc['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {inc['id']}.yaml")

# ─── Memories (20 needed) ─────────────────────────────────────────────────────
memories = [
    {"id": "tainan_dutch_001", "title": "熱蘭遮城的早晨", "era": "dutch", "type": "歷史目擊",
     "quality": 3, "site": "tainan_anping_fort", "desc": "1630年代的熱蘭遮城，清晨的瞭望哨可以看到台江內海鋪滿了大小商船。\n荷蘭士兵用沾水筆在日誌上寫下：今天風向西北，三艘裝載生絲與瓷器的船隻進港。"},
    {"id": "tainan_dutch_002", "title": "新港社傳教士日誌", "era": "dutch", "type": "文書記錄",
     "quality": 3, "site": "tainan_xilaya", "desc": "尤羅伯傳教士寫道：今天我教導了新港社的十名青年使用羅馬字拼寫他們自己的母語。\n他們指著泥土寫下了這幾個字母，這或許是這片土地上最早的自主文字痕跡。"},
    {"id": "tainan_koxinga_001", "title": "明鄭大軍登陸鹿耳門", "era": "koxinga", "type": "軍事記錄",
     "quality": 3, "site": "tainan_koxinga_landing", "desc": "永曆十五年四月初一，潮水暴漲，鄭成功手持佩劍站在主艦甲板上。\n將士們看著原本是淺灘的沙洲在一夜之間被海水覆蓋，船隊得以順利長驅直入。"},
    {"id": "tainan_koxinga_002", "title": "王府的寧靜夜", "era": "koxinga", "type": "歷史回憶",
     "quality": 2, "site": "tainan_grand_mazu_temple", "desc": "寧靖王朱術桂在王府大堂內，點燃了最後的清香。\n他看著身旁的五位姬妾，每個人神情坦然，沒有淚水，只有明朝將亡之際的決絕。"},
    {"id": "tainan_qing_001", "title": "五條港的水道喧囂", "era": "qing", "type": "日常記憶",
     "quality": 2, "site": "tainan_shennong_street", "desc": "清代道光年間的神農街，後門就是水道，搬運工赤裸上身，將整箱的樟腦和茶葉從舢舨上抬進倉庫。\n空氣中滿是汗水與桐油的特殊氣味。"},
    {"id": "tainan_qing_002", "title": "大成殿的老榕樹", "era": "qing", "type": "物件記憶",
     "quality": 2, "site": "tainan_confucian_temple", "desc": "清代乾隆年間的一場午後暴雨後，孔廟大成殿庭院的石板被水洗刷得發亮。\n秀才們聚在茂密的老榕樹下討論著經義，樹葉上的水滴不時落在他們的考卷上。"},
    {"id": "tainan_japanese_001", "title": "林百貨的電梯轟鳴", "era": "japanese", "type": "生活記憶",
     "quality": 2, "site": "tainan_hayashi_dept", "desc": "昭和七年，林百貨隆重開幕。\n市民們排在旋轉指針的電梯前，懷著既期待又害怕的心情踏入電梯。\n電梯上升時的低沉轟鳴，是那個摩登時代的心跳。"},
    {"id": "tainan_japanese_002", "title": "山上淨水場的第一滴水", "era": "japanese", "type": "工程記憶",
     "quality": 2, "site": "tainan_water_facility_old", "desc": "大正十一年，台南水道試運轉。\n當清澈的過濾水順著厚重的鑄鐵管道流向台南市區時，工程師們緊緊擁抱在一起。\n這滴水解決了府城肆虐百年的霍亂。"},
    {"id": "tainan_postwar_001", "title": "二二八的最後家書", "era": "postwar", "type": "信件記憶",
     "quality": 3, "site": "tainan_228_memorial", "desc": "1947年三月中旬，一封從看守所寄出的手寫信被藏在衣服縫隙裡帶出。\n信上寫著：『春梅，孩子就交給妳了。請轉告大家，我是為了這座古城的和平而談，我無愧於心。』"},
    {"id": "tainan_postwar_002", "title": "永樂市場布市的算盤聲", "era": "postwar", "type": "日常記憶",
     "quality": 1, "site": "tainan_yongle_market", "desc": "民國五十年代的永樂市場，布匹堆得比人還高。\n本省的呢絨與外省的緞面交錯，老布商的手指在算盤上快速飛舞，清脆的算盤聲是那代人維持生計的節奏。"},
    {"id": "tainan_modern_001", "title": "神農街老屋的地井", "era": "modern", "type": "空間記憶",
     "quality": 2, "site": "tainan_sakura_lane", "desc": "老街店面裝修時，掀開地磚，赫然發現一口早已乾涸的古井。\n探頭往下看，井底的乾泥上散落著幾片清代的青花瓷碗碎片，反射著手電筒的光。"},
    {"id": "tainan_modern_002", "title": "大菜市的碗粿老攤", "era": "modern", "type": "飲食記憶",
     "quality": 1, "site": "tainan_old_market", "desc": "每天清晨，木製蒸籠掀開的瞬間，白色水霧中飄散出濃郁的米香與滷肉香。\n老闆用竹籤將碗粿劃開，沿用百年的動作在指尖流暢重複。"},
    {"id": "tainan_siraya_urn_001", "title": "土地公廟的阿立祖", "era": "modern", "type": "信仰記憶",
     "quality": 2, "site": "tainan_xilaya", "desc": "在新市仔社遺址的土地公廟裡，神像旁放著一個樸素的紅陶甕，甕口插著澤蘭。\n這是西拉雅後裔與漢人神明和平共處的象徵，也是他們沒有遺忘祖靈的證明。"},
    {"id": "tainan_anping_salt_001", "title": "鹽田底部的結晶", "era": "japanese", "type": "日常記憶",
     "quality": 2, "site": "tainan_beimen_salt_field", "desc": "烈日下的七股鹽田，海水在高溫下逐漸濃縮。\n鹽工用木耙將底部的結晶推成一堆，那一層晶瑩的白在陽光下閃耀著刺眼的光芒，是幾代人汗水的沉積。"},
    {"id": "tainan_koxinga_003", "title": "寧靖王姬妾殉節", "era": "koxinga", "type": "悲情記憶",
     "quality": 3, "site": "five_concubines_temple", "desc": "王府後院，五位姬妾穿戴整齊，向著京城的方向跪拜後，懸樑自盡。\n她們留下的衣冠，後來被埋在府城南郊，成為五妃廟的由來。"},
    {"id": "tainan_qing_003", "title": "聯境防衛的誓言", "era": "qing", "type": "社會記憶",
     "quality": 2, "site": "tainan_silian_yan", "desc": "道光年間，面對林爽文餘黨的威脅，四聯境的長老齊聚城隍廟前，在神前立誓共同守衛街區，不准外人侵擾。"},
    {"id": "tainan_anping_001", "title": "大員港的荷蘭船隊", "era": "dutch", "type": "日常記憶",
     "quality": 2, "site": "anping_harbor", "desc": "大員港口的海水清澈，荷蘭東印度公司的三桅大船靠在碼頭，本島的工人將鹿皮搬運上船，海風中充滿了皮革與海水的氣味。"},
    {"id": "tainan_koxinga_004", "title": "明倫堂的漢學第一課", "era": "koxinga", "type": "教育記憶",
     "quality": 2, "site": "tainan_confucian_temple", "desc": "陳永華在大成殿旁的明倫堂內，教導台灣的第一批學子朗讀古文。\n漢文的聲調在剛建好的學堂內迴盪，開啟了全台首學的歷史。"},
    {"id": "tainan_japanese_003", "title": "五分車上的糖甜", "era": "japanese", "type": "生活記憶",
     "quality": 2, "site": "tainan_guofeng_market", "desc": "採收季的冬天，滿載甘蔗的五分車緩緩駛進歸仁糖廠。\n空氣中瀰漫著熬糖的甜膩氣味，車廂鐵軌的摩擦聲在平原上傳得很遠。"},
    {"id": "tainan_qing_004", "title": "迎春門外的春牛", "era": "qing", "type": "民俗記憶",
     "quality": 2, "site": "tainan_dongmen", "desc": "每年立春，府城官員在東門城外舉行迎春禮，用紙糊的春牛在鑼鼓聲中被敲碎，象徵新一年農耕的開始。"}
]

# Write Memories
print("=== Memories ===")
for mem in memories:
    content = f"""id: {mem['id']}
title: "{mem['title']}"
era: "{mem['era']}"
evidence_type: "{mem['type']}"
quality: {mem['quality']}
progress: 10
description: |
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(mem['desc'].strip().splitlines()))}
settlement: "tainan"
trigger_site: "{mem['site']}"
conditions: []
"""
    filepath = f"{BASE}/memories/{mem['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {mem['id']}.yaml")

print("All memories & incidents created.")
