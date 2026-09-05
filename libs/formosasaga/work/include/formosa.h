// /include/formosa.h
//
// 《源流福爾摩沙》全域常數、Daemon 路徑、Macro 定義。
// 所有 LPC 物件 #include 此檔。
//
// Canon 參照：docs/mudlib/02_domain_model.md

#ifndef FORMOSA_H
#define FORMOSA_H

// ── Daemon 路徑 ────────────────────────────────────────
#define EVENT_D       load_object("/secure/event_d.lpc")
#define SETTLEMENT_D  load_object("/daemon/settlement_d.lpc")
#define REVEAL_D      load_object("/daemon/reveal_d.lpc")
#define FOOTPRINT_D   load_object("/daemon/footprint_d.lpc")
#define MEMORY_D      load_object("/daemon/memory_d.lpc")
#define TIMELINE_D    load_object("/daemon/timeline_d.lpc")
#define CAREER_D      load_object("/daemon/career_d.lpc")
#define FACTION_D     load_object("/daemon/faction_d.lpc")
#define OBLIVION_D    load_object("/daemon/oblivion_d.lpc")
#define RESONANCE_D   load_object("/daemon/resonance_d.lpc")
#define CHRONICLE_D   load_object("/daemon/chronicle_d.lpc")
#define INCIDENT_D    load_object("/daemon/incident_d.lpc")
#define SCHEDULE_D    load_object("/daemon/schedule_d.lpc")
#define NPC_D         load_object("/daemon/npc_d.lpc")
#define ERA_D         load_object("/daemon/era_d.lpc")
#define SITE_D        load_object("/daemon/site_d.lpc")
#define ROUTE_D       load_object("/daemon/route_d.lpc")
#define EVENT_VIEWER_D load_object("/daemon/event_viewer_d.lpc")
#define WORLD_EVENT_D  load_object("/daemon/world_event_d.lpc")
#define COMPLETION_D   load_object("/daemon/completion_d.lpc")
#define CODEX_D        load_object("/daemon/codex_d.lpc")
#define RELATION_D     load_object("/daemon/relation_d.lpc")
#define WORLD_STATE_D  load_object("/daemon/world_state_d.lpc")

// ── 踏印類型 ───────────────────────────────────────────
#define FP_GEO        "geo"         // 地理踏印
#define FP_RELATION   "relation"    // 人情踏印
#define FP_CRAFT      "craft"       // 技藝踏印
#define FP_SETTLEMENT "settlement"  // 聚落踏印
#define FP_ERA        "era"         // 時代踏印
#define FP_SOURCE     "source"      // 源流踏印

// ── 踏印品質 ───────────────────────────────────────────
#define FQ_GLIMPSE    1   // 初識
#define FQ_FAMILIAR   2   // 熟悉
#define FQ_DEEP       3   // 深入
#define FQ_SOURCE     4   // 源流

// ── 聚落六維 key ───────────────────────────────────────
#define DIM_POPULATION "population"
#define DIM_INDUSTRY   "industry"
#define DIM_CULTURE    "culture"
#define DIM_MEMORY     "memory"
#define DIM_TRADE      "trade"
#define DIM_COHESION   "cohesion"

// ── 聚落等級 ───────────────────────────────────────────
#define TIER_VILLAGE  4
#define TIER_CITY3    3
#define TIER_CITY2    2
#define TIER_CITY1    1

// ── 記憶品質 ───────────────────────────────────────────
#define MQ_FRAGMENT   1   // 殘片
#define MQ_RECORD     2   // 記錄
#define MQ_HERITAGE   3   // 傳承
#define MQ_EPIC       4   // 史詩
#define MQ_SOURCE     5   // 源流

// ── 失源者型態 ─────────────────────────────────────────
#define SP_LOST_NAME    "lost_name"     // 失名者
#define SP_LOST_PLACE   "lost_place"    // 失鄉者
#define SP_LOST_TONGUE  "lost_tongue"   // 失語者
#define SP_LOST_HISTORY "lost_history"  // 失史者

// ── 遺忘閾值 ───────────────────────────────────────────
#define OBLIVION_WARN     30    // 記憶值低於此，預警
#define OBLIVION_SPECTER  20    // 記憶值低於此，生成失源者
#define OBLIVION_CRISIS   10    // 記憶值低於此，危機狀態

// ── Reveal 條件類型 ────────────────────────────────────
#define RC_FOOTPRINT      "has_footprint"
#define RC_FOOTPRINT_MIN  "footprint_min_quality"
#define RC_ERA_DONE       "era_completed"
#define RC_MEMORY_DONE    "memory_completed"
#define RC_CAREER_RANK    "career_rank"
#define RC_SETTLEMENT_MEM "settlement_memory_gte"
#define RC_TALENT         "has_talent"
#define RC_GLOBAL_EVENT   "global_event_triggered"
#define RC_HAS_QUEST      "has_quest"
#define RC_IN_PARTY       "in_party"
#define RC_ANY            "any"   // 任一條件成立即顯示
#define RC_ALL            "all"   // 所有條件成立才顯示

// ── 天賦 ───────────────────────────────────────────────
#define TALENT_ISLAND_MEMORY "island_memory"  // 主角唯一天賦

// ── ANSI 顏色快捷 ──────────────────────────────────────
#define C_RESET   "$NOR$"
#define NOR       "$NOR$"
#define C_TITLE   "$HIW$"
#define C_DIM     "$CYN$"
#define C_WARN    "$HIR$"
#define C_GOOD    "$HIG$"
#define C_MEMORY  "$YEL$"
#define C_HISTORY "$MAG$"
#define C_REVEAL  "$HIB$"
#define C_CODEX   "$HIB$"

// ── 資料路徑 ───────────────────────────────────────────
#define YAML_SETTLEMENTS  "/data/yaml/settlements/"
#define YAML_SITES        "/data/yaml/sites/"
#define YAML_MEMORIES     "/data/yaml/memories/"
#define YAML_ERAS         "/data/yaml/eras/"
#define YAML_CAREERS      "/data/yaml/careers/"
#define YAML_FACTIONS     "/data/yaml/factions/"
#define STATE_SETTLEMENTS "/data/state/settlements/"
#define STATE_SYSTEM      "/data/state/system/"

#endif
