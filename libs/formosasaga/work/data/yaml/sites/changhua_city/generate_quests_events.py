#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Quests (5 needed) ────────────────────────────────────────────────────────
quests = [
    {
        "id": "quest_bagua_mountain_line",
        "title": "八卦山的悲歌",
        "era": "japanese",
        "difficulty": 3,
        "description": "歷史社社長小林正在比對乙未戰爭八卦山決戰的防線，\n解說員老陳也守在抗日烈士紀念碑旁，談起當年黑旗軍吳彭年將軍的悲壯犧牲。\n你將協助小林完成戰線調查，並在孔廟大成殿梁柱上找到那顆穿透歷史的子彈彈孔。",
        "objectives": [
            {"id": "talk_guide_mountain", "description": "在 八卦山 向 老陳 詢問吳彭年將軍與防線配置", "type": "npc", "target": "NPC_changhua_mountain_guide", "topic": "乙未戰爭"},
            {"id": "talk_keeper_bullet", "description": "在 孔廟 向 管理員阿福 詢問流彈彈孔的具體位置", "type": "npc", "target": "NPC_changhua_temple_keeper", "topic": "彈孔"},
            {"id": "look_temple_hall", "description": "在 彰化孔廟 仔細觀察大成殿中彈梁柱", "type": "site", "target": "changhua_confucian_temple", "action": "look"},
            {"id": "get_battle_memory", "description": "解鎖記憶碎片『八卦山頂的落日軍號』", "type": "memory", "target": "changhua_battle_001"}
        ],
        "reward": {"exp": 1200, "faction": "taiwan_historical_truth", "reputation": 80, "unlock": "changhua_bagua_mountain_incident"}
    },
    {
        "id": "quest_lai_ho_clinic_secret",
        "title": "媽祖醫生的處方箋",
        "era": "japanese",
        "difficulty": 3,
        "description": "賴和紀念館小敏展示了一張他在大正年間開立的感冒處方箋。\n處方箋背面用鉛筆寫著文學手稿的草稿，但有些字被摺痕磨損。\n你將在老城區尋訪曾受他恩惠的老人，拼湊完整的手稿內容。",
        "objectives": [
            {"id": "talk_curator_script", "description": "在 賴和紀念館 向 小敏 詢問處方箋草稿的摺痕缺字", "type": "npc", "target": "NPC_lai_ho_curator", "topic": "處方箋"},
            {"id": "talk_nanyao_secret", "description": "在 南瑤宮 向 老乩童阿喜叔 詢問賴和與匠師的往來", "type": "npc", "target": "NPC_changhua_nanyao_keeper", "topic": "歷史"},
            {"id": "look_clinic_manuscript", "description": "在 賴和醫院舊址 仔細翻閱賴和的新文學手稿", "type": "site", "target": "changhua_lai_ho_clinic", "action": "look"},
            {"id": "get_laiho_memory", "description": "解鎖記憶碎片『撕毀欠條的除夕夜』", "type": "memory", "target": "changhua_laiho_001"}
        ],
        "reward": {"exp": 1300, "faction": "taiwan_cultural_memory", "reputation": 90, "unlock": "changhua_lai_ho_literature_incident"}
    },
    {
        "id": "quest_shuangwen_well_seal",
        "title": "古井下的起義軍金印",
        "era": "qing",
        "difficulty": 3,
        "description": "古井老住戶阿公提到，清代林爽文之役城破前夕，守將將天地會金印丟入了無影井中。\n茶莊老闆阿德也收藏了拆除東門時暗中搶救出的『民胞物與』城門匾額。\n你將協助釐清這段彰化古城起義與防衛的歷史秘密。",
        "objectives": [
            {"id": "talk_well_seal", "description": "向 古井阿公 詢問金印的傳說與井底暗渠的流向", "type": "npc", "target": "NPC_changhua_past_elder", "topic": "林爽文"},
            {"id": "talk_east_gate_plate", "description": "向 東門茶莊老闆阿德 詢問城門匾額的藏匿位置", "type": "npc", "target": "NPC_changhua_rebel_descendant", "topic": "城門匾額"},
            {"id": "look_well_shadow", "description": "在 無影井 觀察水面與井壁石欄", "type": "site", "target": "changhua_bagua_well", "action": "look"},
            {"id": "get_well_memory", "description": "解鎖記憶碎片『無影井底的黃金印信』", "type": "memory", "target": "changhua_seal_001"}
        ],
        "reward": {"exp": 1150, "faction": "taiwan_folk_memory", "reputation": 75, "unlock": "changhua_爽文_siege_incident"}
    },
    {
        "id": "quest_nanyao_insult_carving",
        "title": "南瑤宮的柱頭大罵",
        "era": "japanese",
        "difficulty": 2,
        "description": "老乩童阿喜叔透露，南瑤宮觀音殿歐式立柱背面，\n隱藏著當年匠師留下的三個日文漢字『馬鹿野郎』暗罵監工官員。\n木雕學徒小施也聽說過孔廟夾層裡藏有清代匠師為了躲避沒收而藏匿的雕刻刀。\n你決定去實地調查，解開這段匠師的無聲反抗。",
        "objectives": [
            {"id": "talk_nanyao_carving", "description": "向 老乩童阿喜叔 詢問觀音殿立柱背面的日文漢字位置", "type": "npc", "target": "NPC_changhua_nanyao_keeper", "topic": "匠師刻字"},
            {"id": "look_nanyao_hall", "description": "在 南瑤宮 仔細尋找立柱背面的刻字痕跡", "type": "site", "target": "changhua_nanyao_temple", "action": "look"},
            {"id": "talk_apprentice_knife", "description": "向 木雕學徒小施 詢問孔廟夾層雕刻刀的傳說", "type": "npc", "target": "NPC_changhua_woodcarver_apprentice", "topic": "老街屋"},
            {"id": "get_nanyao_memory", "description": "解鎖記憶碎片『觀音殿的西洋馬鹿』", "type": "memory", "target": "changhua_nanyao_001"}
        ],
        "reward": {"exp": 1100, "faction": "taiwan_cultural_memory", "reputation": 75}
    },
    {
        "id": "quest_meatball_secret_alley",
        "title": "肉圓攤旁的秘密聯絡點",
        "era": "japanese",
        "difficulty": 2,
        "description": "肉圓店老闆阿成說，他祖父在日治初期擺攤時，\n老街屋的肉圓店曾被抗日義軍用作秘密聯絡點，並在竹籤筒裡傳遞傷藥與字條。\n你決定去老巷子深處進行深度探尋，還原這段街市底層的抗日互助故事。",
        "objectives": [
            {"id": "talk_meatball_secret", "description": "向 老闆阿成 詢問竹籤筒與老屋聯絡點的口述歷史", "type": "npc", "target": "NPC_changhua_meatball_owner", "topic": "傳言"},
            {"id": "look_meatball_alley", "description": "在 肉圓老巷 仔細尋找舊店鋪後方的老隔間與通道", "type": "site", "target": "changhua_meatball_alley", "action": "look"},
            {"id": "talk_west_gate_elder", "description": "向 西門古厝阿吉伯 詢問當年的械鬥後巷防禦", "type": "npc", "target": "NPC_changhua_west_gate_elder", "topic": "械鬥"},
            {"id": "get_meatball_memory", "description": "解鎖記憶碎片『孔廟前的扁擔肉圓』", "type": "memory", "target": "changhua_meatball_001"}
        ],
        "reward": {"exp": 1050, "faction": "taiwan_folk_memory", "reputation": 70}
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
settlement: changhua_city
scope:
  - changhua_city
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

# ─── World Events (2 needed) ──────────────────────────────────────────────────
world_events = [
    {
        "id": "changhua_lai_ho_memorial",
        "name": "賴和文學音樂祭（媽祖醫生紀念日）",
        "type": "scheduled",
        "era_active": "modern",
        "affected_sites": ["changhua_lai_ho_clinic", "changhua_city_site", "changhua_confucian_temple"],
        "duration_days": 2,
        "description": "每年舉辦的賴和文學音樂祭。彰化市區舉辦讀書會與音樂會，市民齊聚賴和紀念館，重讀他的經典新文學作品。",
        "overrides": {
            "changhua_lai_ho_clinic": "紀念館門前擺滿了市民自發前來敬獻的野百合，館內迴盪著青年樂手彈唱的賴和詩句民謠。",
            "changhua_city_site": "市區老街掛起了文學布條，街道上傳出讀書會朗讀賴和散文的台語聲音，極具文化氣息。"
        }
    },
    {
        "id": "changhua_nanyao_procession",
        "name": "南瑤宮彰化媽笨港進香",
        "type": "scheduled",
        "era_active": None,
        "affected_sites": ["changhua_nanyao_temple", "changhua_city_site", "changhua_south_gate"],
        "duration_days": 3,
        "description": "彰化南瑤宮著名的『笨港進香』。進香隊伍從彰化城出發，鑼鼓喧天，鞭炮齊鳴，大批信眾隨行，是中台灣最重要的宗教盛事之一。",
        "overrides": {
            "changhua_nanyao_temple": "正殿前庭擠滿了來自各地的鑾轎與陣頭，進香的大旗在空中揮舞，宮前廣場人聲鼎沸。",
            "changhua_south_gate": "南門口十字路口被進香的人潮與長長的隨香隊伍完全佔滿，交通一度管制，鞭炮屑鋪滿了整條官道地磚。"
        }
    }
]

# Write World Events
print("=== World Events ===")
for ev in world_events:
    affected = '\n'.join(f'  - {s}' for s in ev['affected_sites'])
    overrides = '\n'.join(f'    {site}: |\n      {desc}' for site, desc in ev['overrides'].items())
    era = ev.get('era_active') or 'null'
    
    content = f'''id: {ev['id']}
name: {ev['name']}
type: {ev['type']}
era_active: {era}
duration_days: {ev['duration_days']}
affected_sites:
{affected}
description: |
  {ev['description']}
effects:
  site_desc_override:
{overrides}
'''
    filepath = f"{BASE}/world_events/{ev['id']}.yaml"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"  CREATED: {ev['id']}.yaml")

print("All quests and world events for Changhua City created.")
