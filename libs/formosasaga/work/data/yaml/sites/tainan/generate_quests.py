#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Quests (15 needed) ────────────────────────────────────────────────────────
quests = [
    {
        "id": "quest_dutch_relic_tainan",
        "title": "大員的失落檔案",
        "era": "dutch",
        "difficulty": 3,
        "description": "學者Jan一直在尋找荷蘭國家檔案館殘缺的熱蘭遮城地下室圖紙。\n阿義志工透露，安平古堡老磚牆的厚度似乎藏有端倪。\n你將解開這個大航海時代的空間秘密。",
        "objectives": [
            {"id": "talk_jan", "description": "與 Jan 討論荷蘭大員文書", "type": "npc", "target": "NPC_dutch_researcher", "topic": "文書"},
            {"id": "look_wall", "description": "在 安平古堡 仔細觀察舊城牆", "type": "site", "target": "tainan_anping_fort", "action": "look"},
            {"id": "talk_guide", "description": "詢問 志工阿義 關於城牆的秘密", "type": "npc", "target": "NPC_anping_fort_guide", "topic": "密道"},
            {"id": "get_dutch_memory", "description": "解鎖記憶碎片『熱蘭遮城的早晨』", "type": "memory", "target": "tainan_dutch_001"}
        ],
        "reward": {"exp": 1200, "faction": "siraya_memory", "reputation": 80, "unlock": "tainan_dutch_landing"}
    },
    {
        "id": "quest_koxinga_tide_tainan",
        "title": "鹿耳門的奇蹟漲潮",
        "era": "koxinga",
        "difficulty": 3,
        "description": "鄭成功歷史表演者阿名對當時的登陸戰役極感興趣。\n傳說媽祖在關鍵時刻讓潮水暴漲，大軍才得以進入。\n你決定從歷史記載和地理遺留中，查明奇蹟的真相。",
        "objectives": [
            {"id": "talk_reenactor", "description": "與 阿名 討論登陸戰役的經過", "type": "npc", "target": "NPC_koxinga_reenactor", "topic": "鄭成功"},
            {"id": "look_landing", "description": "在 鹿耳門登陸處 仔細查看歷史碑文", "type": "site", "target": "tainan_koxinga_landing", "action": "look"},
            {"id": "talk_mazu_elder", "description": "在大天后宮向 阿珠嬤 詢問媽祖助戰的傳說", "type": "npc", "target": "NPC_mazu_worshipper_tainan", "topic": "媽祖"},
            {"id": "get_koxinga_memory", "description": "解鎖記憶碎片『明鄭大軍登陸鹿耳門』", "type": "memory", "target": "tainan_koxinga_001"}
        ],
        "reward": {"exp": 1500, "faction": "taiwan_historical_truth", "reputation": 100, "unlock": "tainan_koxinga_landing_incident"}
    },
    {
        "id": "quest_five_concubines_flower",
        "title": "五妃廟的無名花",
        "era": "koxinga",
        "difficulty": 2,
        "description": "五妃廟神龕前每年特定日子都會出現一束無名花。\n廟公阿文不知道是誰放的，但這與寧靖王姬妾殉節的歷史記憶深深交織。\n你需要找到這個默默致敬的人。",
        "objectives": [
            {"id": "talk_keeper", "description": "向 廟公阿文 詢問無名花的日期", "type": "npc", "target": "NPC_five_concubines_keeper", "topic": "花"},
            {"id": "look_urn", "description": "在 五妃廟 仔細尋找祭祀的痕跡", "type": "site", "target": "five_concubines_temple", "action": "look"},
            {"id": "talk_novelist", "description": "向 小說家彥廷 詢問他對五妃歷史的研究", "type": "npc", "target": "NPC_historical_novelist", "topic": "五妃"},
            {"id": "get_concubines_memory", "description": "解鎖記憶碎片『寧靖王姬妾殉節』", "type": "memory", "target": "tainan_koxinga_003"}
        ],
        "reward": {"exp": 1000, "faction": "taiwan_cultural_memory", "reputation": 70, "unlock": "tainan_koxinga_landing_incident"}
    },
    {
        "id": "quest_shennong_river_sound",
        "title": "五條港的地下回聲",
        "era": "qing",
        "difficulty": 2,
        "description": "神農街底下曾經是繁華的五條港水道，如今已填平為街面。\n咖啡店主阿勇說在大雨後的特定地點能聽到地下流水聲。\n你決定去實地調查，並找出水道舊輪廓。",
        "objectives": [
            {"id": "talk_barista", "description": "向 阿勇 詢問地下流水聲的具體位置", "type": "npc", "target": "NPC_shennong_barista", "topic": "神農街"},
            {"id": "search_waterway", "description": "在 神農街 仔細搜尋舊水道痕跡", "type": "site", "target": "tainan_shennong_street", "action": "search"},
            {"id": "talk_artist", "description": "與 藝術家阿珍 討論她創作的『五條港的回聲』", "type": "npc", "target": "NPC_shennong_street_artist", "topic": "水道"},
            {"id": "get_qing_memory", "description": "解鎖記憶碎片『五條港的水道喧囂』", "type": "memory", "target": "tainan_qing_001"}
        ],
        "reward": {"exp": 1100, "faction": "taiwan_folk_memory", "reputation": 75, "unlock": "tainan_bengang_harbor_incident"}
    },
    {
        "id": "quest_water_iron_pipe",
        "title": "明治水道的百年承諾",
        "era": "japanese",
        "difficulty": 3,
        "description": "台南水道的一截明治時期舊鑄鐵管道至今仍在使用，運作極其穩定。\n老工程師對此充滿敬意，但似乎有一台老水泵被封鎖在庫房角落。\n你將協助他重新了解台南淨水場的百年記憶。",
        "objectives": [
            {"id": "talk_engineer", "description": "向 老工程師 詢問明治舊管線的情形", "type": "npc", "target": "NPC_water_engineer", "topic": "老管道"},
            {"id": "look_pump", "description": "在 台南水道 觀察運轉的百年水泵", "type": "site", "target": "tainan_water_facility_old", "action": "look"},
            {"id": "get_water_memory", "description": "解鎖記憶碎片『山上淨水場的第一滴水』", "type": "memory", "target": "tainan_japanese_002"}
        ],
        "reward": {"exp": 1300, "faction": "taiwan_cultural_memory", "reputation": 90, "unlock": "tainan_shokusan_industry_incident"}
    },
    {
        "id": "quest_postwar_letter_wait",
        "title": "看守所寄出的信",
        "era": "postwar",
        "difficulty": 3,
        "description": "二二八紀念館展示著一封手寫遺書，收件人是『春梅』，但寄送地址早已變更。\n館員阿敏對此信件的背景感到無奈。\n你將重走這個地址，為這段長達數十年的沉默帶回一絲溫暖的解讀。",
        "objectives": [
            {"id": "talk_staff", "description": "向 館員阿敏 詢問信件的來源與細節", "type": "npc", "target": "NPC_228_museum_staff", "topic": "信件"},
            {"id": "look_memorial", "description": "在 紀念館 仔細閱讀該信件原文", "type": "site", "target": "tainan_228_memorial", "action": "look"},
            {"id": "talk_elder_witness", "description": "向 東門城邊老攤販阿德仔 詢問當年台南大捕殺的見聞", "type": "npc", "target": "NPC_dongmen_gate_elder", "topic": "東門城"},
            {"id": "get_postwar_memory", "description": "解鎖記憶碎片『二二八的最後家書』", "type": "memory", "target": "tainan_postwar_001"}
        ],
        "reward": {"exp": 1600, "faction": "taiwan_historical_truth", "reputation": 110, "unlock": "tainan_228_intellectual_incident"}
    },
    {
        "id": "quest_siraya_urn_secret",
        "title": "神龕旁的紅陶甕",
        "era": "modern",
        "difficulty": 2,
        "description": "新市仔社遺址的土地公廟裡，神像旁放著一個插著澤蘭的紅陶甕。\n考古系學生小明對此進行了初步田野調查。\n你將協助他釐清西拉雅族阿立祖信仰是如何在漢人神殿中生存下來的。",
        "objectives": [
            {"id": "talk_student", "description": "向 學生小明 詢問他發現的神龕細節", "type": "npc", "target": "NPC_tainan_archaeology_student", "topic": "阿立祖"},
            {"id": "look_urn", "description": "在 西拉雅遺址 觀察神龕旁的配置", "type": "site", "target": "tainan_xilaya", "action": "look"},
            {"id": "get_urn_memory", "description": "解鎖記憶碎片『土地公廟的阿立祖』", "type": "memory", "target": "tainan_siraya_urn_001"}
        ],
        "reward": {"exp": 1000, "faction": "siraya_memory", "reputation": 70, "unlock": "tainan_siraya_identity_incident"}
    },
    {
        "id": "quest_yongle_old_cloth_secret",
        "title": "此布留予來者認",
        "era": "postwar",
        "difficulty": 3,
        "description": "永樂市場的老布商阿順仔珍藏著一疋清代留下來的靛藍色老布頭。\n布的褶縫裡塞著一張寫著『此布留予來者認』的紙片。\n你需要解開這個長達百年的遺留之謎。",
        "objectives": [
            {"id": "talk_cloth_merchant", "description": "向 布商阿順仔 詢問老布頭的來歷", "type": "npc", "target": "NPC_old_tailor_tainan", "topic": "老布頭"},
            {"id": "search_market", "description": "在 永樂市場 尋找有關該訂單的舊記錄", "type": "site", "target": "tainan_yongle_market", "action": "search"},
            {"id": "get_cloth_memory", "description": "解鎖記憶碎片『永樂市場布市的算盤聲』", "type": "memory", "target": "tainan_postwar_002"}
        ],
        "reward": {"exp": 1200, "faction": "taiwan_folk_memory", "reputation": 80}
    },
    {
        "id": "quest_anping_unsigned_koxinga",
        "title": "老街的小廟神明",
        "era": "qing",
        "difficulty": 3,
        "description": "安平老街尾端的小廟供奉著一位沒有寫明來歷的『延平王』。\n蝦餅店老闆娘阿鳳暗示，這個廟可能與鄭成功後裔在清初的避難歷史有關。\n你決定前往小廟進行深度歷史考證。",
        "objectives": [
            {"id": "talk_prawn_lady", "description": "向 老闆娘阿鳳 詢問小廟的來歷", "type": "npc", "target": "NPC_anping_prawn_cracker_lady", "topic": "榕樹屋"},
            {"id": "look_old_street", "description": "在 安平老街 尋找小廟的碑文或刻字", "type": "site", "target": "tainan_anping", "action": "look"},
            {"id": "get_anping_memory", "description": "解鎖記憶碎片『大員港的荷蘭船隊』", "type": "memory", "target": "tainan_anping_001"}
        ],
        "reward": {"exp": 1100, "faction": "taiwan_cultural_memory", "reputation": 75}
    },
    {
        "id": "quest_chihkan_nine_horses",
        "title": "赤崁樓的轉頭石馬",
        "era": "qing",
        "difficulty": 2,
        "description": "赤崁樓院子裡的九隻石馬中，有一隻的頭是稍微朝左偏的。\n研究員小玲指出這隻石馬的石質和底座與其他不同。\n你將探尋這隻特殊石馬的修補背後隱藏的清代故事。",
        "objectives": [
            {"id": "talk_archivist", "description": "向 研究員小玲 詢問九隻石馬的調查細節", "type": "npc", "target": "NPC_chihkan_archivist", "topic": "石馬"},
            {"id": "look_horses", "description": "在 赤崁樓 觀察九隻石馬的姿態與石材", "type": "site", "target": "tainan_chihkan_tower", "action": "look"},
            {"id": "get_chihkan_memory", "description": "解鎖記憶碎片『大成殿的老榕樹』", "type": "memory", "target": "tainan_qing_002"}
        ],
        "reward": {"exp": 1000, "faction": "taiwan_cultural_memory", "reputation": 70}
    },
    {
        "id": "quest_decipher_voc_brick",
        "title": "VOC磚上的義字",
        "era": "dutch",
        "difficulty": 4,
        "description": "安平古堡的老城牆某塊磚上，同時刻有荷蘭東印度公司的VOC標誌與漢字『義』。\n導覽志工阿義與荷蘭學者Jan對此有不同的學術解讀。\n你將協助他們找到這塊磚的真正歷史含義。",
        "objectives": [
            {"id": "talk_dutch_scholar", "description": "向 Jan 詢問熱蘭遮城文書中關於本地工匠的記載", "type": "npc", "target": "NPC_dutch_researcher", "topic": "文書"},
            {"id": "talk_rector_guide", "description": "向 志工阿義 詢問這塊磚在古堡牆體上的具體位置", "type": "npc", "target": "NPC_anping_fort_guide", "topic": "傳言"},
            {"id": "look_fort_wall", "description": "在 安平古堡 仔細觀察那塊帶有漢字的荷蘭磚", "type": "site", "target": "tainan_anping_fort", "action": "look"}
        ],
        "reward": {"exp": 1700, "faction": "siraya_memory", "reputation": 120}
    },
    {
        "id": "quest_koxinga_three_faces",
        "title": "延平王的三副面孔",
        "era": "modern",
        "difficulty": 3,
        "description": "博物館裡展出了歐洲人、日本人與漢人分別繪製的三幅風格迥異的鄭成功畫像。\n策展人小芬正試圖規劃一個打破單一視角的歷史展覽。\n你將尋訪台南各處，為她收集關於鄭成功歷史角色的民間多樣記憶。",
        "objectives": [
            {"id": "talk_curator", "description": "與 策展人小芬 討論三幅畫像背後的文化視角", "type": "npc", "target": "NPC_koxinga_museum_curator", "topic": "畫像"},
            {"id": "look_museum_painting", "description": "在 延平王博物館 仔細觀看這三幅畫像", "type": "site", "target": "tainan_koxinga_museum", "action": "look"},
            {"id": "talk_reenactor_views", "description": "詢問 表演者阿名 關於扮演鄭成功的個人感觸", "type": "npc", "target": "NPC_koxinga_reenactor", "topic": "日本神社"},
            {"id": "get_school_first_class", "description": "解鎖記憶碎片『明倫堂的漢學第一課』", "type": "memory", "target": "tainan_koxinga_004"}
        ],
        "reward": {"exp": 1400, "faction": "taiwan_historical_truth", "reputation": 95}
    },
    {
        "id": "quest_hayashi_locked_basement",
        "title": "林百貨的地下牆面",
        "era": "japanese",
        "difficulty": 3,
        "description": "老台南人傳說林百貨地下室在二戰結束前夕封死了一面牆，藏有當時的貨物。\n解說員阿珊說地下室重新裝修後並未發現地窖，但確實有一面磚牆看起來非常新。\n你決定去實地調查，並設法查明原因。",
        "objectives": [
            {"id": "talk_clerk_basement", "description": "向 阿珊 詢問地下室翻修時的細節", "type": "npc", "target": "NPC_hayashi_store_clerk", "topic": "傳言"},
            {"id": "look_dept_store", "description": "在 林百貨 尋找那面看起來年份不對的磚牆", "type": "site", "target": "tainan_hayashi_dept", "action": "look"},
            {"id": "get_hayashi_memory", "description": "解鎖記憶碎片『林百貨的電梯轟鳴』", "type": "memory", "target": "tainan_japanese_001"}
        ],
        "reward": {"exp": 1300, "faction": "taiwan_cultural_memory", "reputation": 90}
    },
    {
        "id": "quest_zhongyi_temple_debt",
        "title": "武廟的祖傳借據",
        "era": "modern",
        "difficulty": 2,
        "description": "武廟保存著一本幾十年前由老商人立下的古怪『承諾借據』。\n廟公阿勝透露，目前是其第三代孫子每年來武廟還一個小承諾。\n你將協助釐清這份長達三代的神秘契約內容。",
        "objectives": [
            {"id": "talk_temple_勝", "description": "向 廟公阿勝 詢問那本借據與商人的名字", "type": "npc", "target": "NPC_zhongyi_temple_keeper", "topic": "借據"},
            {"id": "look_altar_secret", "description": "在 忠義路武廟 仔細觀察月老祠神龕周圍", "type": "site", "target": "tainan_zhongyi_temple", "action": "look"},
            {"id": "talk_foodie_helper", "description": "在西市場向 美食導覽員小玉 詢問那名老商人的背景", "type": "npc", "target": "NPC_tainan_foodie_guide", "topic": "傳言"}
        ],
        "reward": {"exp": 1100, "faction": "taiwan_folk_memory", "reputation": 75}
    },
    {
        "id": "quest_beimen_transparent_salt",
        "title": "結晶的甘甜",
        "era": "modern",
        "difficulty": 2,
        "description": "老鹽工阿海透露，七股鹽田的第三格西南角偶爾會結出如水晶般透明且帶有特殊甘甜的鹽。\n美食導覽小玉對此非常好奇，懷疑與當地的水質和地質結構有關。\n你決定去實地調查採樣，並找出原因。",
        "objectives": [
            {"id": "talk_salt_master", "description": "向 老鹽工阿海 詢問透明鹽結晶的採集時機", "type": "npc", "target": "NPC_salt_worker_tainan", "topic": "透明鹽"},
            {"id": "search_salt_field", "description": "在 七股鹽田 進行深度搜尋與水土採樣", "type": "site", "target": "tainan_beimen_salt_field", "action": "search"},
            {"id": "get_salt_memory", "description": "解鎖記憶碎片『鹽田底部的結晶』", "type": "memory", "target": "tainan_anping_salt_001"}
        ],
        "reward": {"exp": 1000, "faction": "taiwan_folk_memory", "reputation": 70}
    }
]

# Write Quests
print("=== Quests ===")
for q in quests:
    obj_lines = []
    for obj in q["objectives"]:
        obj_lines.append(f"  - id: {obj['id']}")
        obj_lines.append(f"    description: \"{obj['description']}\"")
        if obj["type"] == "npc":
            obj_lines.append(f"    npc: {obj['target']}")
            obj_lines.append(f"    ask_topic: {obj['topic']}")
        elif obj["type"] == "site":
            obj_lines.append(f"    site: {obj['target']}")
            obj_lines.append(f"    action: {obj['action']}")
        elif obj["type"] == "memory":
            obj_lines.append(f"    memory: {obj['target']}")
            
    unlock_line = f"  unlock_incident: {q['unlock']}\n" if q.get("unlock") else ""
    
    content = f"""id: {q['id']}
title: "{q['title']}"
settlement: tainan
scope:
  - tainan
era: {q['era']}
difficulty: {q['difficulty']}
description: |
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(q['description'].strip().splitlines()))}
objectives:
{chr(10).join(obj_lines)}
completion_reward:
  exp: {q['reward']['exp']}
  faction: {q['reward']['faction']}
  reputation: {q['reward']['reputation']}
{unlock_line}"""
    filepath = f"{BASE}/quests/{q['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {q['id']}.yaml")

print("All quests created.")
