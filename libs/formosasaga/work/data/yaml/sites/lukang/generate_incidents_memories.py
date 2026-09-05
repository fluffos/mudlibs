#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Incidents (3 needed) ──────────────────────────────────────────────────────
incidents = [
    {
        "id": "lukang_jiaobang_trade_incident",
        "name": "一府二鹿：行郊與貿易的黃金年代",
        "description": "乾隆至道光年間，鹿港作為對渡港口，商業極度繁盛，由各大商號組成的『八郊』（如泉郊、廈郊）主導了地方貿易與社會秩序。\n你將深入老街與天后宮，重溫那段萬船雲集的黃金歲月。",
        "truth": "鹿港的行郊不僅是商業同盟，更是早期的市民自治組織。他們集資建廟、開井（半邊井）、修築防禦隘門，在清代官府控制力薄弱的台灣平原上，建立了一套基於信義與神明見證的社會秩序與繁榮結構。",
        "era": "qing",
        "clues": [
            {"id": "jiao_temple_meeting", "name": "天后宮行郊議事總部", "type": "npc_ask", "source": "npc:NPC_lukang_temple_keeper", "topic": "行郊"},
            {"id": "banyue_well_humanity", "name": "半邊井的分享精神與老街舊路基", "type": "npc_ask", "source": "npc:NPC_lukang_banyue_well_elder", "topic": "半邊井"},
            {"id": "old_port_stone", "name": "舊渡頭風化的花崗岩繫船石", "type": "site_look", "source": "site:lukang_guichao_port"}
        ],
        "reward": {"exp": 1200, "faction": "taiwan_folk_memory", "reputation": 90}
    },
    {
        "id": "lukang_royal_artisan_incident",
        "name": "匠藝傳承：大木作與小木作的巔峰",
        "description": "鹿港以精湛的傳統工藝聞名，龍山寺的八卦藻井與神像雕刻是閩南匠藝的極致體現。\n你將走訪木雕工坊與古寺，理解匠人如何用刀鑿將信仰實體化，並面對近代傳承的斷層。",
        "truth": "鹿港木雕的巔峰得益於清代對渡貿易帶來的資金與福建大師的交流。龍山寺無釘藻井展現了小木作卡榫工藝的極致。日治時期的皇民化運動曾試圖沒收神像，靠著當地匠師與信眾聯手掉包才保住了核心的信仰標本。",
        "era": "japanese",
        "clues": [
            {"id": "temple_no_nail_well", "name": "龍山寺無釘卡榫藻井結構", "type": "npc_ask", "source": "npc:NPC_lukang_master_woodcarver", "topic": "龍山寺"},
            {"id": "swapped_mazu_statue", "name": "天后宮黑面二媽的皇民化掉包事件", "type": "npc_ask", "source": "npc:NPC_lukang_temple_keeper", "topic": "掉包"},
            {"id": "master_carver_workshop", "name": "木雕大師修復神轎的現場", "type": "site_look", "source": "site:lukang_woodcarving_workshop"}
        ],
        "reward": {"exp": 1500, "faction": "taiwan_cultural_memory", "reputation": 100}
    },
    {
        "id": "lukang_railway_bypass_incident",
        "name": "縱貫線鐵路繞道與鹿港的沒落",
        "description": "大正年間，日本政府修建縱貫線鐵路時，原本計畫經過鹿港，卻遭到當地行郊商人的強烈反對，鐵路最終繞道彰化。\n你將調查舊渡頭與隘門，探尋這段因拒絕鐵路而走向沒落的歷史轉折點。",
        "truth": "縱貫線鐵路繞道是鹿港發展史上最關鍵的轉折。行郊商人因擔心風水被破壞與商業主導權喪失而集體反對，導致鹿港在鐵路時代被邊緣化。隨後港口嚴重淤積，鹿港從商業樞紐退化為保存古老工藝與民俗的『歷史博物館』。",
        "era": "japanese",
        "clues": [
            {"id": "railway_pins_search", "name": "舊渡頭泥沙中的鐵路道釘", "type": "npc_ask", "source": "npc:NPC_lukang_dock_fisherman", "topic": "道釘"},
            {"id": "gate_defense_rebel", "name": "防禦隘門在日軍進城時的抵抗", "type": "npc_ask", "source": "npc:NPC_lukang_rebel_descendant", "topic": "歷史"},
            {"id": "大和洋樓_talk", "name": "民俗文物館洋樓二樓的歷史視野", "type": "npc_ask", "source": "npc:NPC_lukang_museum_guide", "topic": "洋樓"}
        ],
        "reward": {"exp": 1400, "faction": "taiwan_historical_truth", "reputation": 95}
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
  {chr(10).join('  ' + l if i > 0 else l for i, l in enumerate(inc['truth'].strip().splitlines()))}
era_active: {inc['era']}
settlement: lukang
scope:
  - lukang
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

# ─── Memories (8 needed) ───────────────────────────────────────────────────────
memories = [
    {"id": "lukang_trade_001", "title": "船頭街的萬船雲集", "era": "qing", "type": "日常記憶",
     "quality": 3, "site": "lukang_guichao_port", "desc": "乾隆五十年秋，鹿港溪口檣桅如林。\n來自泉州的舢舨載滿了棉布、陶瓷與杉木，在繫船石旁卸貨。\n水手們的閩南土腔與郊商掌櫃的算盤聲，在渡頭的夕陽下吵成一片，那是鹿港最繁華的交響樂。"},
    {"id": "lukang_well_001", "title": "半邊井前的溫情", "era": "qing", "type": "生活記憶",
     "quality": 2, "site": "lukang_banyue_well", "desc": "清代嘉慶年間，瑤林街的挑夫打水歇息。\n古厝主人交代僕人在牆外的半邊井旁放了一只粗瓷碗與一桶茶水，方便過路人自取。\n那半邊露在圍牆外的井欄，倒映著這座小鎮最純樸的善意。"},
    {"id": "lukang_wood_001", "title": "大木作的極致藻井", "era": "qing", "type": "工藝記憶",
     "quality": 3, "site": "lukang_longshan_temple", "desc": "清代建廟時，福建泉州的木雕大師施木生站在戲台頂端。\n他沒有拿任何圖紙，僅憑一把古老折尺和手感，將最後一塊斗拱卡入藻井中心。\n當榫卯完全契合的那一刻，整個八卦形的天空完美地懸掛在半空。"},
    {"id": "lukang_gate_001", "title": "車路口隘門夜鎖", "era": "qing", "type": "日常防衛",
     "quality": 2, "site": "lukang_yi_crossing", "desc": "咸豐三年的一場大械鬥前夜，更夫敲過三更。\n隘門守衛合力將厚重的杉木門栓推入石槽卡死，防禦的石鎖孔在月光下反射著冷光。\n牆內是熟睡的街坊，牆外是漫漫長夜與隨時可能爆發的衝突。"},
    {"id": "lukang_swapped_001", "title": "棉花捆裡的黑面二媽", "era": "japanese", "type": "歷史事件",
     "quality": 3, "site": "lukang_tianhou_temple", "desc": "昭和十五年的深夜，天后宮偏殿極度安靜。\n廟公與施師傅的曾祖父將黑面二媽的真身用油紙包好，塞進老街商號準備運往彰化的棉花捆最深處。\n第二天，日本人帶走了一尊剛刷好黑漆的假神像。"},
    {"id": "lukang_shi_feng_001", "title": "十宜樓的狂草斷章", "era": "qing", "type": "文人記憶",
     "quality": 2, "site": "lukang_shi_feng", "desc": "光緒二十一年夏，台灣割讓的噩耗傳來。\n詩人林會堂在十宜樓上喝乾了最後一壺酒，悲憤之下，用防身小刀在窗櫺木欄上刻下了『山河已改，此心難移』的狂草。\n刀尖入木三分，木屑混合著他的眼淚落在地板上。"},
    {"id": "lukang_pastry_001", "title": "鳳眼糕的日本皇室貢禮", "era": "japanese", "type": "生活記憶",
     "quality": 2, "site": "lukang_pastry_shop", "desc": "大正十二年，裕仁皇太子巡視台灣。\n鹿港製菓所的餅師用特製的鳳眼木模，敲出了一盤雪白精緻、入口即化的鳳眼糕。\n那只木模的弧度，自此成了這家餅鋪延續百年的最高榮譽。"},
    {"id": "lukang_museum_001", "title": "大和洋樓的二樓陽台", "era": "japanese", "type": "空間記憶",
     "quality": 2, "site": "lukang_mazu_folk_arts_museum", "desc": "一九一九年落成的洋樓二樓，辜顯榮站在精美的白色浮雕圓拱廊下。\n他看著老街蜿蜒的紅磚屋頂，與遠方已經開始淤積的渡口，深知這個小鎮的命運即將因為縱貫線鐵路的繞道而發生改變。"}
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
settlement: "lukang"
trigger_site: "{mem['site']}"
conditions: []
"""
    filepath = f"{BASE}/memories/{mem['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {mem['id']}.yaml")

print("All incidents and memories for Lukang created.")
