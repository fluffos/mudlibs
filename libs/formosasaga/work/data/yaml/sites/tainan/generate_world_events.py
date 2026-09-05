#!/usr/bin/env python3
import os

BASE = "/home/wade/src/github/FormosaSaga/mudlib/data/yaml"

# ─── World Events (4 needed) ──────────────────────────────────────────────────
world_events = [
    {
        "id": "tainan_koxinga_festival",
        "name": "延平郡王祭",
        "type": "scheduled",
        "era_active": None,
        "affected_sites": ["wu_fei_temple", "tainan_confucian_temple", "tainan_koxinga_museum"],
        "duration_days": 3,
        "description": "每年舉辦的延平郡王祭典，祭祀開台聖王鄭成功，忠義路一帶彩旗飄揚，廟埕民俗表演與儀式吸引大量人潮。",
        "overrides": {
            "wu_fei_temple": "延平郡王祠外高掛著明鄭軍旗，廣場上進行著八家將與宋江陣的演出，鼓樂喧天。",
            "tainan_confucian_temple": "大成殿前今天特別安靜，為了祭孔與郡王祭的銜接，長老與樂生正在緊鑼密鼓地彩排大成樂舞。"
        }
    },
    {
        "id": "tainan_ghost_festival",
        "name": "府城中元大普渡",
        "type": "scheduled",
        "era_active": None,
        "affected_sites": ["tainan_grand_mazu_temple", "tainan_silian_yan", "tainan_old_market"],
        "duration_days": 3,
        "description": "農曆七月，台南府城各大聯境與天后宮共同舉行的大普渡。沿街擺設供桌，香煙繚繞，氣氛既莊嚴又熱鬧。",
        "overrides": {
            "tainan_grand_mazu_temple": "廟門前的金爐火光熊熊，無數信眾將一疊疊金紙投入，煙霧幾乎籠罩了整座正殿。",
            "tainan_silian_yan": "四聯境各大廟宇聯手在街區中架起普渡棚，排開的供品一直延伸到老街的巷子裡。"
        }
    },
    {
        "id": "tainan_salt_festival",
        "name": "七股鹽田送夕陽",
        "type": "scheduled",
        "era_active": "modern",
        "affected_sites": ["tainan_beimen_salt_field", "anping_harbor"],
        "duration_days": 1,
        "description": "七股鹽田在歲末舉辦的送夕陽慶典，市民與遊客齊聚鹽山與舊鹽田，在琴聲中目送最後一道餘暉沒入海峽。",
        "overrides": {
            "tainan_beimen_salt_field": "白色鹽田在落日餘暉下被染成一片絢麗的粉紅與金黃，老鹽工阿海默默看著落日，像是送別一個時代的戰友。"
        }
    },
    {
        "id": "tainan_hayashi_anniversary",
        "name": "林百貨摩登大遊行",
        "type": "scheduled",
        "era_active": "modern",
        "affected_sites": ["tainan_hayashi_dept", "tainan_old_street", "tainan_old_market"],
        "duration_days": 1,
        "description": "林百貨週年慶的復古摩登大遊行。街上隨處可見穿著旗袍、和服與昭和風西裝的遊行隊伍，重現1930年代的府城風華。",
        "overrides": {
            "tainan_hayashi_dept": "百貨外牆掛起了復古的彩燈，電梯門口排起了長龍，解說員阿珊也換上了最精緻的蕾絲滾邊旗袍迎接來客。"
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

print("All world events created.")
