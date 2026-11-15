// ==================== 界面显示模块功能函数声明 ====================
// 主界面和属性查看功能 (实现在 interface.h 中)
int show_main_interface(object me);
int view_bonus(object me);

// ==================== 装备管理模块功能函数声明 ====================
// 装备和卸下真意功能 (实现在 equip.h 中)
int equip_zhenyi_action(object me, int slot, string zhenyi_id);
int unequip_zhenyi_action(object me, int slot);
int show_equip_slots(object me);
int show_unequip_slots(object me);
varargs int show_bag_for_equip(object me, int slot, int page);

// ==================== 背包模块功能函数声明 ====================
// 背包管理和真意操作功能 (实现在 bag.h 中)
varargs int manage_bag(object me, int page);
int view_zhenyi_detail(object me, string zhenyi_id);
int discard_confirm_action(object me, string zhenyi_id);
int discard_execute_action(object me, string zhenyi_id);
int show_effect_desc(object me, string effect_name);
int compare_zhenyi_action(object me, string zhenyi_id);
int show_equip_slots_for_item(object me, string zhenyi_id);
int zhenyi_quality_cmp(string id1, string id2, mapping bag, mapping qrank);

// ==================== 合成模块功能函数声明 ====================
// 真意合成功能 (实现在 synthesis.h 中)
int synthesis_zhenyi_cmp(string id1, string id2, mapping filtered_bag);
int level_range_cmp(string key1, string key2, mapping quality_level_stats);
int show_synthesis_interface(object me);
varargs int show_zhenyi_selection_for_synthesis(object me, string quality, int page, string selected_ids);
int show_synthesis_preview(object me, string selected_ids);
int show_synthesis_confirmation(object me, string selected_ids);
int execute_synthesis_action(object me, string selected_ids);

// ==================== 分解模块功能函数声明 ====================
// 真意分解功能 (实现在 decompose.h 中)
int show_decompose_interface(object me);
varargs int show_decompose_selection(object me, int page);
varargs int show_decompose_by_quality(object me, string quality, int page);
int show_decompose_preview(object me, string selected_ids);
int show_decompose_confirmation(object me, string selected_ids);
int execute_decompose_action(object me, string selected_ids);
int show_batch_decompose_interface(object me);
int show_wuyun_status(object me);
int decompose_zhenyi_cmp(string id1, string id2, mapping bag, mapping quality_config);

// ==================== 武蕴兑换模块功能函数声明 ====================
// 武蕴兑换功能 (实现在 exchange.h 中)
int show_wuyun_exchange_interface(object me);
int exchange_material_action(object me);
int exchange_material_confirm(object me);
int exchange_potential_input(object me);
int exchange_potential_action(object me, string amount);
int exchange_potential_confirm(object me, string amount);
string *get_material_pool();
string get_material_display_name(string material_path);

// ==================== 方案管理模块功能函数声明 ====================
// 方案管理功能 (实现在 scheme.h 中)
int show_scheme_management(object me);
varargs int show_scheme_list(object me, int page);
int show_scheme_detail(object me, string scheme_name);
int save_scheme_input(object me);
int save_scheme_execute(object me, string scheme_name);
int load_scheme_action(object me, string scheme_name);
int rename_scheme_input(object me, string old_name);
int rename_scheme_execute(object me, string old_name, string new_name);
int delete_scheme_confirm(object me, string scheme_name);
int delete_scheme_execute(object me, string scheme_name);