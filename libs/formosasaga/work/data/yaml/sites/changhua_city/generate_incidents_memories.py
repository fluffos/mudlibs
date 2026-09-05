#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Incidents (3 needed) ──────────────────────────────────────────────────────
incidents = [
    {
        "id": "changhua_bagua_mountain_incident",
        "name": "1895八卦山戰役：乙未喋血",
        "description": "1895年8月，日本近衛師團大軍壓境，台灣義軍與黑旗軍在八卦山展開激烈的防守決戰。\n吳彭年將軍率領義軍全軍覆沒，戰火甚至波及下方的彰化城與孔廟。\n你將重回這段乙未最悲壯的歷史防線。",
        "truth": "八卦山決戰是乙未抗日中規模最大的山頭會戰。義軍雖然在裝備與訓練上居於絕對劣勢，但憑藉地勢頑強抵抗，造成日軍重大傷亡，包括日本北白川宮能久親王受傷的傳說。此役結束後，中台灣的組織性抵抗宣告瓦解，也留下了孔廟梁柱上的流彈彈孔等歷史標本。",
        "era": "japanese",
        "clues": [
            {"id": "battlefield_monument", "name": "八卦山頂的抗日烈士紀念碑", "type": "site_look", "source": "site:changhua_bagua_mountain"},
            {"id": "temple_bullet_hole", "name": "孔廟大成殿梁柱的彈孔", "type": "npc_ask", "source": "npc:NPC_changhua_temple_keeper", "topic": "彈孔"},
            {"id": "battlefield_student_diary", "name": "歷史社社長整理的戰役日記手稿", "type": "npc_ask", "source": "npc:NPC_changhua_historical_student", "topic": "乙未戰爭"}
        ],
        "reward": {"exp": 1500, "faction": "taiwan_historical_truth", "reputation": 100}
    },
    {
        "id": "changhua_lai_ho_literature_incident",
        "name": "賴和行醫與新文學的誕生",
        "description": "大正至昭和年間，彰化名醫賴和在診所行醫的同時，用漢字創作出大量關懷社會底層、反抗日人剝削的新文學作品，被譽為『台灣新文學之父』。\n你將走訪賴和醫院舊址，還原這段以筆為刀的文學反抗歷史。",
        "truth": "賴和的診所是日治時期彰化知識份子與底層庶民的交會所。他藉由行醫體會底層痛苦，並將其轉化為『一桿秤仔』等經典文學。他與天后宮、孔廟等地方組織關係緊密，被市民尊稱為『媽祖醫生』，其文學創作形成了台灣主體意識的初次萌芽。",
        "era": "japanese",
        "clues": [
            {"id": "lai_ho_handscript", "name": "賴和診所留下的手寫詩句處方箋", "type": "npc_ask", "source": "npc:NPC_lai_ho_curator", "topic": "處方箋"},
            {"id": "lai_ho_clinic_observation", "name": "賴和醫院舊址的聽診器與手稿", "type": "site_look", "source": "site:changhua_lai_ho_clinic"},
            {"id": "nanyao_temple_carving", "name": "南瑤宮重建時的匠師秘密刻字", "type": "npc_ask", "source": "npc:NPC_changhua_nanyao_keeper", "topic": "匠師刻字"}
        ],
        "reward": {"exp": 1200, "faction": "taiwan_cultural_memory", "reputation": 80}
    },
    {
        "id": "changhua_爽文_siege_incident",
        "name": "林爽文起義：半線古城的攻防戰",
        "description": "乾隆五十一（1786）年，林爽文率領天地會起義，攻佔彰化縣城，並以八卦山為大本營與清軍對峙。\n這場起義震動大清帝國，也徹底改變了彰化平原的社會防衛結構（隘門與城牆興建）。\n你將調查東門與無影井，還原這場歷史風暴。",
        "truth": "林爽文事件直接導致清廷在戰後同意將原本的刺竹城牆改建為磚石縣城。城內居民為了自衛，在各大街區普遍建立防禦隘門與分類聯境，形成了清代彰化古城如同迷宮一般的防衛格局，影響了後續百年的都市結構。",
        "era": "qing",
        "clues": [
            {"id": "well_gold_seal_legend", "name": "無影井底深埋起義軍金印的傳說", "type": "npc_ask", "source": "npc:NPC_changhua_past_elder", "topic": "林爽文"},
            {"id": "east_gate_hidden_sign", "name": "被藏匿的東門『民胞物與』門額", "type": "npc_ask", "source": "npc:NPC_changhua_rebel_descendant", "topic": "城門匾額"},
            {"id": "west_gate_sword_relic", "name": "西門城基縫隙裡發現的斷鐵劍", "type": "npc_ask", "source": "npc:NPC_changhua_west_gate_elder", "topic": "西門"}
        ],
        "reward": {"exp": 1300, "faction": "taiwan_folk_memory", "reputation": 85}
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
settlement: changhua_city
scope:
  - changhua_city
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
    {"id": "changhua_battle_001", "title": "八卦山頂的落日軍號", "era": "japanese", "type": "歷史事件",
     "quality": 3, "site": "changhua_bagua_mountain", "desc": "1895年8月28日黃昏，日軍的刺刀衝上八卦山頂砲台。\n黑旗軍吳彭年將軍身中數彈，在斷裂的砲架旁吹響了最後的撤退軍號。\n那一聲軍號在彰化平原上空被風撕碎，宣示了這片高地最悲壯的防守結局。"},
    {"id": "changhua_bullet_001", "title": "穿透櫺星門的流彈", "era": "japanese", "type": "日常記憶",
     "quality": 2, "site": "changhua_confucian_temple", "desc": "八卦山決戰那天，城內硝煙瀰漫，避難的學子躲在大成殿的供桌下。\n突然一聲巨響，一發日軍的流彈穿透木製櫺星門，擊中了殿內正梁，木屑如雨般落在聖人牌位上。"},
    {"id": "changhua_laiho_001", "title": "撕毀欠條的除夕夜", "era": "japanese", "type": "生活記憶",
     "quality": 3, "site": "changhua_lai_ho_clinic", "desc": "昭和五年的除夕深夜，賴和醫生坐在診所的煤油燈下，\n將一疊貧窮患者寫下的醫藥費欠條扔進火盆。\n看著欠條在火光中化為灰燼，他在日記中寫道：『讓他們安心過個好年吧，神明見證，債已清。』"},
    {"id": "changhua_seal_001", "title": "無影井底的黃金印信", "era": "qing", "type": "傳奇物件",
     "quality": 2, "site": "changhua_bagua_well", "desc": "乾隆五十二年清軍破城前夕，起義軍守將將天地會的金質大印用布包裹，\n趁夜丟入了無影井深處的水泥潭底。\n那一聲悶響，伴著激起的井水，將這段起義的榮耀與秘密永遠封存在冷泥中。"},
    {"id": "changhua_plate_001", "title": "被藏匿的東門匾額", "era": "qing", "type": "物件記憶",
     "quality": 2, "site": "changhua_east_gate", "desc": "日治初期城牆拆除前夕，彰化的幾位老紳商趁夜雇了挑夫，\n用粗麻繩將東門城樓上寫有『民胞物與』的花崗岩匾額取下，\n抬進老街米行天花板的夾層裡，用紙蓋住，不讓日本人看見。"},
    {"id": "changhua_nanyao_001", "title": "觀音殿的西洋馬鹿", "era": "japanese", "type": "工藝事件",
     "quality": 3, "site": "changhua_nanyao_temple", "desc": "大正十一年，南瑤宮觀音殿重建完工。\n施大師在西洋柱頭的背面，悄悄用刻刀留下了日文漢字『馬鹿』字樣。\n日本官員在柱下指手畫腳，卻不知道自己頭頂正頂著匠師最直白的無聲嘲諷。"},
    {"id": "changhua_babuza_001", "title": "半線社的梅花鹿群", "era": "qing", "type": "生態記憶",
     "quality": 2, "site": "changhua_old_well_babu", "desc": "在清代漢人開墾之前，半線平原長滿了沒膝的荒草與茂密的刺竹林。\n巴布薩族的獵人手持木弓，蹲在水潭邊，\n看著上百隻梅花鹿在朝陽下的草澤間奔跑，那是這片土地最原始的模樣。"},
    {"id": "changhua_meatball_001", "title": "孔廟前的扁擔肉圓", "era": "japanese", "type": "飲食記憶",
     "quality": 1, "site": "changhua_meatball_alley", "desc": "大正年間的清晨，阿公挑著沉重的扁擔來到孔廟前街。\n油鍋的火在風中搖曳，溫油慢炸的肉圓散發出番薯粉與豬油的純香，\n挑夫與學生圍坐在板凳上，用幾枚銅錢換得一天的飽足。"}
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
settlement: "changhua_city"
trigger_site: "{mem['site']}"
conditions: []
"""
    filepath = f"{BASE}/memories/{mem['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {mem['id']}.yaml")

print("All incidents and memories for Changhua City created.")
