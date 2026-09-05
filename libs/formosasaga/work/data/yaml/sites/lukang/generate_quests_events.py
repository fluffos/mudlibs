#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── Quests (5 needed) ────────────────────────────────────────────────────────
quests = [
    {
        "id": "quest_jiaobang_order_lukang",
        "title": "行郊的信義印記",
        "era": "qing",
        "difficulty": 2,
        "description": "天后宮廟公阿全提到，清代行郊在媽祖前立誓交易，違約者會被收回商運。\n半邊井的老太太春花也保留著關於當年行郊施水的溫情故事。\n你將協助釐清這段基於宗教與信義的社會管理史。",
        "objectives": [
            {"id": "talk_keeper_jiao", "description": "向 廟公阿全 詢問行郊議事與公斷的舊規矩", "type": "npc", "target": "NPC_lukang_temple_keeper", "topic": "行郊"},
            {"id": "look_port_relic", "description": "在 舊渡頭 觀察花崗岩繫船石", "type": "site", "target": "lukang_guichao_port", "action": "look"},
            {"id": "talk_well_elder", "description": "向 半邊井老太太春花 詢問建井主人的故事", "type": "npc", "target": "NPC_lukang_banyue_well_elder", "topic": "半邊井"},
            {"id": "get_well_memory", "description": "解鎖記憶碎片『半邊井前的溫情』", "type": "memory", "target": "lukang_well_001"}
        ],
        "reward": {"exp": 1000, "faction": "taiwan_folk_memory", "reputation": 70, "unlock": "lukang_jiaobang_trade_incident"}
    },
    {
        "id": "quest_shaojing_no_nail",
        "title": "無釘藻井的奧秘",
        "era": "japanese",
        "difficulty": 3,
        "description": "木雕施師傅表示，龍山寺的八卦藻井是全台木結構的巔峰，中心藏有鎮火符。\n天后宮廟公阿全也透露皇民化時期曾有用木雕佛像掉包真身的驚險事件。\n你決定探尋這兩項將工藝與信仰完美融合的匠人秘密。",
        "objectives": [
            {"id": "talk_master_wood", "description": "與 木雕大師施師傅 討論龍山寺藻井榫卯結構", "type": "npc", "target": "NPC_lukang_master_woodcarver", "topic": "龍山寺"},
            {"id": "look_workshop_site", "description": "在 木雕工坊 仔細尋找舊設計圖或修復工具", "type": "site", "target": "lukang_woodcarving_workshop", "action": "look"},
            {"id": "talk_keeper_swap", "description": "向 廟公阿全 詢問當年黑面二媽掉包真身的藏匿地點", "type": "npc", "target": "NPC_lukang_temple_keeper", "topic": "掉包"},
            {"id": "get_wood_memory", "description": "解鎖記憶碎片『大木作的極致藻井』", "type": "memory", "target": "lukang_wood_001"}
        ],
        "reward": {"exp": 1300, "faction": "taiwan_cultural_memory", "reputation": 90, "unlock": "lukang_royal_artisan_incident"}
    },
    {
        "id": "quest_railway_bypass_relic",
        "title": "拒絕鐵路的代價",
        "era": "japanese",
        "difficulty": 3,
        "description": "老漁夫阿木在舊渡頭泥沙中挖到過大正時期的鐵道道釘，引出當年鐵路繞道歷史。\n隘門老守衛阿德也談到，縱貫線繞道後，日軍進城時隘門曾關閉防禦的家族口述。\n你將解鎖這段改變鹿港歷史走向的重要轉折。",
        "objectives": [
            {"id": "talk_fisherman_pin", "description": "向 漁夫阿木 詢問鐵路道釘與老街商人的反對原因", "type": "npc", "target": "NPC_lukang_dock_fisherman", "topic": "道釘"},
            {"id": "talk_guard_gate", "description": "向 隘門守衛阿德 詢問隘門在日治初期的防禦狀況", "type": "npc", "target": "NPC_lukang_rebel_descendant", "topic": "歷史"},
            {"id": "look_museum_view", "description": "在 民俗文物館 仔細觀察大和洋樓的二樓結構", "type": "site", "target": "lukang_mazu_folk_arts_museum", "action": "look"},
            {"id": "get_museum_memory", "description": "解鎖記憶碎片『大和洋樓的二樓陽台』", "type": "memory", "target": "lukang_museum_001"}
        ],
        "reward": {"exp": 1250, "faction": "taiwan_historical_truth", "reputation": 85, "unlock": "lukang_railway_bypass_incident"}
    },
    {
        "id": "quest_shi_feng_carving",
        "title": "十宜樓的狂草小刀字",
        "era": "qing",
        "difficulty": 3,
        "description": "文史研究員林先生提到十宜樓的木櫺上，有一處被油漆蓋住的狂草小刀刻字。\n這是清代舉人林會堂在割台噩耗傳來時留下的絕筆。\n你決定去十宜樓實地考察，將這段悲憤的文人記憶還原出來。",
        "objectives": [
            {"id": "talk_scholar_poem", "description": "向 研究員林先生 詢問舉人林會堂的名字與刻字位置", "type": "npc", "target": "NPC_lukang_scholar_elder", "topic": "小刀刻字"},
            {"id": "search_shi_feng", "description": "在 十宜樓 仔細尋找木欄杆上的刀刻痕跡", "type": "site", "target": "lukang_shi_feng", "action": "search"},
            {"id": "get_shifeng_memory", "description": "解鎖記憶碎片『十宜樓的狂草斷章』", "type": "memory", "target": "lukang_shi_feng_001"}
        ],
        "reward": {"exp": 1100, "faction": "taiwan_cultural_memory", "reputation": 75}
    },
    {
        "id": "quest_incense_pastry_secret",
        "title": "避邪神香與鳳眼木模",
        "era": "modern",
        "difficulty": 2,
        "description": "香藝阿義師傅表示，大天后宮木盒裡保存著清代瘟疫時期的『避邪神香』配方，但缺少關鍵植物。\n餅鋪阿修也擁有一只大正時期為皇室準備的鳳眼木模。\n你將協助他們將這些精緻的手工民俗記憶拼湊完整。",
        "objectives": [
            {"id": "talk_incense_recipe", "description": "向 香藝師傅阿義 詢問避邪神香的配方秘密", "type": "npc", "target": "NPC_lukang_incense_master", "topic": "避邪神香"},
            {"id": "talk_pastry_mold", "description": "向 餅鋪繼承人阿修 詢問鳳眼木模的歷史與皇太子的故事", "type": "npc", "target": "NPC_lukang_pastry_boss", "topic": "鳳眼木模"},
            {"id": "search_tianhou_box", "description": "在 天后宮 尋找保存舊配方的舊木盒", "type": "site", "target": "lukang_tianhou_temple", "action": "search"},
            {"id": "get_pastry_memory", "description": "解鎖記憶碎片『鳳眼糕的日本皇室貢禮』", "type": "memory", "target": "lukang_pastry_001"}
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
settlement: lukang
scope:
  - lukang
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
        "id": "lukang_mazu_birthday",
        "name": "鹿港迎媽祖（天后宮誕辰慶典）",
        "type": "scheduled",
        "era_active": None,
        "affected_sites": ["lukang_tianhou_temple", "lukang_old_street", "lukang_pastry_shop"],
        "duration_days": 3,
        "description": "每年農曆三月二十三日媽祖誕辰，鹿港天后宮舉行盛大的迎媽祖遶境，各大街區與老街塞滿了各地進香人潮，民俗陣頭與鞭炮齊鳴。",
        "overrides": {
            "lukang_tianhou_temple": "天后宮前殿被信眾與香煙完全籠罩，大門口排滿了各地的神轎，鞭炮聲連綿不絕。",
            "lukang_pastry_shop": "餅鋪阿修今天忙得不可開交，鳳眼糕與綠豆椪在開爐幾分鐘內就被進香的香客搶購一空。"
        }
    },
    {
        "id": "lukang_dragon_boat_festival",
        "name": "鹿港慶端陽（龍王祭與點燈）",
        "type": "scheduled",
        "era_active": None,
        "affected_sites": ["lukang_longshan_temple", "lukang_guichao_port", "lukang_old_street"],
        "duration_days": 3,
        "description": "端午節期間的鹿港慶端陽活動。以龍山寺的『龍王祭』拉開序幕，恭迎龍王尊神至舊渡頭為龍舟開光點睛，老街沿路高掛古色古香的燈籠。",
        "overrides": {
            "lukang_longshan_temple": "龍山寺山門前聚集了迎龍王的陣頭，老木雕施師傅正神情肅穆地確認龍王頭雕刻的最後裝飾。",
            "lukang_guichao_port": "淤積的舊渡頭水道兩側掛滿了五彩的裝飾燈籠，市民齊聚岸邊，觀看傳統的龍舟點睛開光儀式。"
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

print("All quests and world events for Lukang created.")
